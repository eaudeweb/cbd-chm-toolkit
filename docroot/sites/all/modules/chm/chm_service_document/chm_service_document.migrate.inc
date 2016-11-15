<?php
/**
 * Base class for migrations.
 */
abstract class CHMServiceDocumentMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
  }

  function log($message) {
    $this->currentMigration()->saveMessage($message);
    $this->currentMigration()->displayMessage($message);
  }

}

/**
 * Class for the nfp migration populating cbd_nfp node type.
 */
class CHMServiceDocumentNBSAPMigration extends CHMServiceDocumentMigration {

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

  public function getDomainByCountryIso($iso) {
    $domain = PTKDomain::getDomainByCountryISO($iso);
    return $domain;
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

        $domain = PTKDomain::getDomainByCountryISO($iso);
        $row->domain_source = $domain['domain_id'];
        $row->domains = array($domain['domain_id']);
        if ($domain['machine_name']) {
          $row->files_destination_dir = 'public://websites/' . $domain['machine_name'] . '/documents';
        }
      }
      else {
        $row->government_s = NULL;
      }
    }

    return TRUE;
  }
}


/**
 * Migration source class for the document migration.
 */
class CHMServiceDocumentNBSAPMigrateSource extends MigrateSource {

  protected $urlPattern = NULL;
  protected $count = NULL;
  protected $data = array();
  protected $currentPage = 0;
  protected $currentCount = 0;
  protected $pageSize = 100;


  public function __construct($urlPattern) {
    parent::__construct(array());
    $this->urlPattern = $urlPattern;
  }

  public function fields() {
    return [
      'id' => 'Remote record ID',
      'title' => 'title',
      'government_s' => 'Country ISO code',
    ];
  }

  public function __toString() {
    return sprintf('Extract data from the API');
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


  /**
   * Do whatever needs to be done to start a fresh traversal of the source data.
   *
   * This is always called at the start of an import, so tasks such as opening
   * file handles, running queries, and so on should be performed here.
   */
  public function performRewind() {
    $this->data = array();
    $this->currentPage = 0;
    $this->currentCount = 0;
  }

  static function http_request($url, $headers = array()) {
    migrate_instrument_start(__CLASS__ . ' http_request');
    self::log(__METHOD__ . ": $url", MigrationBase::MESSAGE_INFORMATIONAL);
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 10);
    curl_setopt($ch, CURLOPT_TIMEOUT, 400);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($ch, CURLOPT_NOBODY, 0);
    $ret = curl_exec($ch);
    $info = curl_getinfo($ch);
    if ($info['http_code'] != 200) {
      $code = $info['http_code'];
      self::log(__METHOD__ . ": Failure ({$code}) for URL: $url", MigrationBase::MESSAGE_ERROR);
      $ret = NULL;
    }
    curl_close($ch);
    migrate_instrument_stop(__CLASS__ . ' http_request');
    return $ret;
  }

  /**
   * Log system for the ws_consumer_odata migrations.
   *
   * @param string $message
   *   Log message
   * @param int $severity
   *    See MigrationBase::MESSAGE_* constants
   */
  static function log($message, $severity = MigrationBase::MESSAGE_INFORMATIONAL) {
    if (function_exists('drush_log')) {
      $status = 'status';
      switch($severity) {
        case MigrationBase::MESSAGE_ERROR:
          $status = 'error';
          break;
        case MigrationBase::MESSAGE_WARNING:
          $status = 'warning';
          break;
        case MigrationBase::MESSAGE_NOTICE:
          $status = 'notice';
          break;
      }
      drush_log($message, $status);
    }
  }
}
