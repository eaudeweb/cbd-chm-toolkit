<?php


/**
 * Class for the NBSAPs document migration into the document node type.
 */
class CHMServiceDocumentNBSAPMigration extends CHMServerConsumerMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Entity original ID',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $this->source = new CHMServiceDocumentNBSAPMigrateSource($arguments['urlPattern']);
    $this->destination = new MigrateDestinationNode('document');

    $this->addFieldMapping('title', 'title_s');
    $this->addFieldMapping('title_field', 'title_s');
    $this->addFieldMapping('field_countries', 'government_s');
    $this->addFieldMapping('field_countries:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_document_type', 'document_type');
    $this->addFieldMapping('field_document_type:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_files', 'documentLinks_s');
    $this->addFieldMapping('field_files:destination_dir', 'files_destination_dir');
    $this->addFieldMapping('field_files:file_replace')->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    $this->addFieldMapping('field_publication_date', 'startDate_s');

    $this->addFieldMapping('field_url', 'url_ss');
    $this->addUnmigratedDestinations(array('field_url:title', 'field_url:attributes', 'field_url:language'));

    $this->addFieldMapping('language')->defaultValue('en');

    $this->addFieldMapping('domain_site')->defaultValue(FALSE);
    $this->addFieldMapping('domain_source', 'domain_source');
    $this->addFieldMapping('domains', 'domains');
    $this->addFieldMapping('uid')->defaultValue(USER_WALLE);

    $this->addUnmigratedDestinations([
      'created', 'changed', 'status', 'promote', 'sticky', 'revision',
      'log', 'tnid', 'translate', 'revision_uid', 'is_new', 'path', 'pathauto',
      'comment',
      'body', 'body:summary', 'body:format',
      'metatag_title', 'metatag_description', 'metatag_abstract', 'metatag_keywords',
      'metatag_robots', 'metatag_news_keywords', 'metatag_standout', 'metatag_rating',
      'metatag_referrer', 'metatag_generator', 'metatag_rights', 'metatag_image_src',
      'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author',
      'metatag_original-source', 'metatag_prev', 'metatag_next', 'metatag_content-language',
      'metatag_geo.position', 'metatag_geo.placename', 'metatag_geo.region',
      'metatag_icbm', 'metatag_refresh', 'metatag_revisit-after', 'metatag_pragma',
      'metatag_cache-control', 'metatag_expires',
    ]);
  }


  public function prepareRow($row) {

    $row->files_destination_dir = 'public://websites/www/documents'; // default path

    if ($nbsap = taxonomy_get_term_by_name('NBSAP', 'document_type')) {
      $nbsap = current($nbsap);
    }
    $row->document_type = $nbsap->tid;

    $row->startDate_s = strtotime($row->startDate_s) +  3600 * 12;// small hack (2hours timezone diffenrence

    if ($row->documentLinks_s) {
      $row->documentLinks_s = json_decode($row->documentLinks_s);
      foreach($row->documentLinks_s as $key => $link) {
        $row->documentLinks_s[$key] = $link->url;
      }
    }

    if (!empty($row->government_s)) {
      if ($country = PTK::getCountryByCode($row->government_s)) {
        $iso = $row->government_s;
        $row->government_s = $country->tid;

        $row->domain_source = PTKDomain::$CHM_DOMAIN_ID;
        $row->domains = array(PTKDomain::$CHM_DOMAIN_ID);
        // Publish to any existing country portals
        if ($domains = PTKDomain::getDomainsByCountryISO($iso)) {
          $row->domains = array_merge($row->domains, array_map(function($d) { return $d['domain_id']; }, $domains));
        }
        $row->files_destination_dir = 'public://websites/www/documents';
      }
      else {
        $row->government_s = NULL;
      }
    }

    return TRUE;
  }
}


/**
 * Migration source class for the NBSAP document migration.
 */
class CHMServiceDocumentNBSAPMigrateSource extends CHMServerConsumerMigrateSource {

  public function fields() {
    return [
      'id' => 'Remote record ID',
      'title' => 'title',
      'government_s' => 'Country ISO code',
      'title_s' => '',
      'document_type' => '',
      'documentLinks_s' => '',
      'startDate_s' => '',
    ];
  }

  public function count($refresh = FALSE) {
    if (empty($this->count) || $refresh) {
      $url = $this->urlPattern . '&rows=0';
      if ($response = self::http_request($url)) {
        $response = json_decode($response);
        $this->count = $response->response->numFound;
      }
    }
    return $this->count;
  }

  /**
   * Fetch the next row of data, returning it as an object.
   *
   * @return object
   *   FALSE data as stdClass, FALSE when there is no more data available.
   */
  public function getNextRow() {
    $next_call_count = $this->currentPage * $this->pageSize;
    if ($this->currentCount == $this->count()) {
      return NULL;
    }
    if ($this->currentCount == $next_call_count && $next_call_count < $this->count()) {
      $start = $this->currentPage * $this->pageSize;
      if ($str = self::http_request($this->urlPattern . '&rows=' . $this->pageSize . '&start=' . $start, array('Accept: application/json'))) {
        $result = json_decode($str, FALSE);
        if (!empty($result->response->docs)) {
          $this->data = $result->response->docs;
          $this->currentPage++;
        }
      }
    }
    $item = NULL;
    if (count($this->data)) {
      $item = current($this->data);
      next($this->data);
      $this->currentCount++;
    }
    return $item;
  }
}
