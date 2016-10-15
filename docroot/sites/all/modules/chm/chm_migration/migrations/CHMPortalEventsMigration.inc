<?php

class CHMPortalEventsMigration extends CHMPortalBaseMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'url' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Entity original ID',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $this->source = new CHMEventsNestedDirJSONSource($arguments);
    $this->destination = new MigrateDestinationNode('event');

    $this->addFieldMapping('created', 'releasedate');
    $this->addFieldMapping('changed', 'last_modification');
    $this->addFieldMapping('status', 'approved');
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('sticky', 'topitem');
    $this->addFieldMapping('revision')->defaultValue(0);
    $this->addFieldMapping('translate')->defaultValue(0);
    $this->addFieldMapping('revision_uid')->defaultValue(0);
    $this->addFieldMapping('uid')->defaultValue(USER_WALLE);
    $this->addFieldMapping('language')->defaultValue('en');

    $this->addFieldMapping('pathauto')->defaultValue(1);
    $this->addFieldMapping('domain_path', 'domain_path');

    // @todo
    $this->addFieldMapping('domain_site')->defaultValue(FALSE);
    $this->addFieldMapping('domain_source', 'domain_source');
    $this->addFieldMapping('domains', 'domains');

    // title
    $this->addFieldMapping('title', 'title_en');
    $this->addFieldMapping('title_field', 'title');
    $this->addFieldMapping('title_field:language', 'title_languages');
    // body
    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:language', 'description_languages');
    $this->addFieldMapping('body:format')->defaultValue('html');
    $this->addUnmigratedDestinations(array('body:summary'));

    // field_dates
    $this->addFieldMapping('field_dates', 'start_date');
    $this->addFieldMapping('field_dates:to', 'end_date');

    // field_url
    $this->addFieldMapping('field_url', 'event_url');
    $this->addUnmigratedDestinations(array('field_url:title', 'field_url:attributes', 'field_url:language'));

    // field_event_address
    $this->addFieldMapping('field_event_address', 'location_address');
    // @todo
    $this->addUnmigratedDestinations(array(
      'field_event_address:administrative_area',
      'field_event_address:sub_administrative_area',
      'field_event_address:locality',
      'field_event_address:dependent_locality',
      'field_event_address:postal_code',
      'field_event_address:thoroughfare',
      'field_event_address:premise',
      'field_event_address:sub_premise',
      'field_event_address:organisation_name',
      'field_event_address:name_line',
      'field_event_address:first_name',
      'field_event_address:last_name',
      'field_event_address:data',
    ));

    // @todo
    $this->addUnmigratedDestinations(array(
      'field_geolocation',
      'field_geolocation:geo_type',
      'field_geolocation:lat',
      'field_geolocation:lon',
      'field_geolocation:left',
      'field_geolocation:top',
      'field_geolocation:right',
      'field_geolocation:bottom',
      'field_geolocation:geohash'
    ));

    // @todo contact_email
    // @todo field_image
    // @todo field_images
    // @todo: field_event_status
    $this->addUnmigratedDestinations([
      'nid', 'log', 'tnid', 'is_new',
      // Don't migrate path to avoid URL collisions with other portals
      // Instead the path is migrated to domain_path.
      'path',
      'field_reference',
      'field_event_status',
      'field_aichi_targets', 'field_aichi_targets:source_type', 'field_aichi_targets:create_term', 'field_aichi_targets:ignore_case',
    ]);
    $this->ignoreMetatagFields();
    $this->addUnmigratedSources([
      'id', 'discussion', 'approved_by', 'version', 'folder', 'sortorder',
      'checkout', 'checkout_user',
    ]);
  }

  /**
   * {@inheritdoc}
   */
  function prepareRowObject($row) {
    $domain_id = $this->arguments['domain']['domain_id'];
    $row->domain_source = $domain_id;
    $row->domains = array($domain_id);
    $row->domain_path[$domain_id] = $row->url;
    $row->event_url = strtolower($row->event_url);
    $row->releasedate = self::prepareDateField($row->releasedate);
    if (empty($row->last_modification)) {
      $row->last_modification = $row->releasedate;
    }
    else {
      $row->last_modification = self::prepareDateField($row->last_modification);
    }

    $row->start_date = self::prepareDateField($row->start_date);
    $row->end_date = self::prepareDateField($row->end_date);
  }

  /**
   * {@inheritdoc}
   */
  function validateRowObject($row) {
    // TODO: Implement validateRowObject() method.
  }
}
