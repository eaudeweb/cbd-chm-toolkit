<?php

class CHMPortalEventsMigration extends CHMPortalBaseMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->source = new CHMEventsNestedDirJSONSource($arguments);
    $this->destination = new MigrateDestinationNode('event');

    $this->addFieldMapping('created', 'releasedate');
    $this->addFieldMapping('changed', 'last_modification');
    $this->addFieldMapping('status', 'approved');
    $this->addFieldMapping('sticky', 'topitem');
    // Computed
    $this->addFieldMapping('language', 'language');

    // @todo
    $this->addFieldMapping('domain_source', 'domain_source');
    $this->addFieldMapping('domains', 'domains');

    $this->addFieldMapping('field_keywords', 'keywords');
    $this->addFieldMapping('field_keywords:source_type')->defaultValue('tid');

    // field_countries
    $this->addFieldMapping('field_countries', 'country');
    $this->addFieldMapping('field_countries:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_countries:create_term')->defaultValue(FALSE);

    // title
    $this->addFieldMapping('title', 'title_en');
    $this->addFieldMapping('title_field', 'title');
    $this->addFieldMapping('title_field:language', 'title_languages');
    // body
    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('body:language', 'description_languages');

    // field_dates
    $this->addFieldMapping('field_dates', 'start_date');
    $this->addFieldMapping('field_dates:to', 'end_date');

    // field_url
    $this->addFieldMapping('field_url', 'event_url');
    $this->addUnmigratedDestinations(array('field_url:title', 'field_url:attributes', 'field_url:language'));

    // field_event_address
    $this->addFieldMapping('field_event_address:premise', 'location_address');
    // @todo
    $this->addUnmigratedDestinations(array(
      'field_event_address:administrative_area',
      'field_event_address:sub_administrative_area',
      'field_event_address:locality',
      'field_event_address:dependent_locality',
      'field_event_address:postal_code',
      'field_event_address:thoroughfare',
      'field_event_address:sub_premise',
      'field_event_address:organisation_name',
      'field_event_address:name_line',
      'field_event_address:first_name',
      'field_event_address:last_name',
      'field_dates:timezone', 'field_dates:rrule',
      'field_event_status:source_type', 'field_event_status:create_term',
      'field_event_status:ignore_case',
      'field_countries:ignore_case',
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
      // Don't migrate path to avoid URL collisions with other portals
      // Instead the path is migrated to domain_path.
      'field_reference',
      'field_event_status',
      'field_aichi_targets', 'field_aichi_targets:source_type', 'field_aichi_targets:create_term', 'field_aichi_targets:ignore_case',
      'field_keywords:create_term', 'field_keywords:ignore_case',
      'field_event_address',
      'field_images:title',
      'field_image:title',
    ]);
    $this->addUnmigratedSources([
      'contributor', 'submitted',
      'id', 'discussion', 'approved_by', 'version', 'folder', 'sortorder',
      'checkout', 'checkout_user',
      'geo_type',
    ]);
  }

  /**
   * {@inheritdoc}
   */
  function prepareRowObject($row) {
    $row->language = 'en';
    $this->prepareKeywords($row);
    $domain_id = $this->arguments['domain']['domain_id'];
    $row->domain_source = $domain_id;
    $row->domains = array($domain_id);
    $row->event_url = strtolower($row->event_url);
    $row->releasedate = self::prepareDateField($row->releasedate);
    if (empty($row->last_modification)) {
      $row->last_modification = $row->releasedate;
    }
    else {
      $row->last_modification = self::prepareDateField($row->last_modification);
    }
    if($country = PTKDomain::getPortalCountry($this->arguments['domain'])) {
      $row->country = $country->tid;
    }
    $row->start_date = self::prepareDateField($row->start_date);
    $row->end_date = self::prepareDateField($row->end_date);
  }

  /**
   * {@inheritdoc}
   */
  function validateRowObject($row) {
    if (empty($row->start_date)) {
      $this->warning("The event {$row->url} has no start date, skipping ...");
      return false;
    }
    return parent::validateRowObject($row);
  }

  function prepare($entity, $row) {
    $languages = $this->getLanguages($row);
    $this->setTranslation($entity, $languages);
  }

  function getLanguages($row) {
    $languages = array();
    if (!empty($row->title_languages)) {
      $languages = array_merge($languages, $row->title_languages);
    }
    if (!empty($row->description_languages)) {
      $languages = array_merge($languages, $row->description_languages);
    }
    return array_unique($languages);
  }

  function complete($entity, $row) {
    $domain_id = $this->arguments['domain']['domain_id'];
    $languages = $this->getLanguages($row);
    if (empty($languages['en'])) {
      $languages[] = 'en';
    }
    // Add aliases for all languages if not exist (i.e. drush mi --update)
    foreach($languages as $language) {
      if (!domain_path_path_load([
        'alias' => $row->url, 'domain_id' => $domain_id,
        'language' => $language, 'source' => 'node/' . $entity->nid
      ])) {
        $path = [
          'entity_type' => 'node',
          'domain_id' => $domain_id,
          'language' => $language,
          'alias' => $row->url,
          'source' => 'node/' . $entity->nid,
          'entity_id' => $entity->nid
        ];
        domain_path_path_save($path);
      }
    }
  }
}
