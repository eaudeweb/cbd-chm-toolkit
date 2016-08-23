<?php

/**
 * Class for the nfp migration populating cbd_nfp node type.
 */
class CHMServerConsumerPAMigrate extends CHMServerConsumerMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'wdpaid' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'WDPAID primary key',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $instance = file_stream_wrapper_get_instance_by_uri(variable_get(PROTECTED_PLANET_AREA_CSV_VAR));
    $this->source = new MigrateSourceCSV(
      $instance->realpath(),
      $this->csvcolumns(),
      array('header_rows' => 1,),
      $this->fields()
    );
    $this->destination = new MigrateDestinationNode('protected_area', array('language' => 'en'));

    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('title_field', 'name');
    $this->addFieldMapping('field_pa_designation', 'desig_en');

    $this->addFieldMapping('field_pa_designation_type', 'desig_type');
    $this->addFieldMapping('field_pa_designation_type:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_pa_iucn_category', 'iucn_cat');
    $this->addFieldMapping('field_pa_iucn_category:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_pa_surface_area', 'rep_area');

    $this->addFieldMapping('field_pa_status', 'status');
    $this->addFieldMapping('field_pa_status:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_pa_status_year', 'status_yr');

    $this->addFieldMapping('field_pa_governing_type', 'gov_type');
    $this->addFieldMapping('field_pa_governing_type:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_pa_owner_type', 'own_type');
    $this->addFieldMapping('field_pa_owner_type:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_pa_management_authority', 'mang_auth');
    $this->addFieldMapping('field_pa_management_plan', 'mang_plan');

    $this->addFieldMapping('field_countries', 'iso3');
    $this->addFieldMapping('field_countries:source_type')->defaultValue('tid');

    $this->addFieldMapping('domains', 'domains');

    $this->addFieldMapping('uid')->defaultValue(USER_WALLE);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('language')->defaultValue('en');
    $this->addFieldMapping('domain_site')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);

    $this->addUnmigratedDestinations([
      'created', 'changed', 'revision', 'log', 'tnid', 'translate',
      'revision_uid', 'is_new', 'body',
      'body:summary', 'body:format', 'body:language',
      'field_image', 'field_image:file_class', 'field_image:language', 'field_image:preserve_files',
      'field_image:destination_dir', 'field_image:destination_file', 'field_image:file_replace',
      'field_image:source_dir', 'field_image:urlencode', 'field_image:alt', 'field_image:title',
      'title_field:language',
      'field_countries:create_term', 'field_countries:ignore_case',
      'field_pa_designation_type:create_term', 'field_pa_designation_type:ignore_case',
      'field_pa_iucn_category:create_term', 'field_pa_iucn_category:ignore_case',
      'field_pa_status:create_term', 'field_pa_status:ignore_case',
      'field_pa_status_year:timezone', 'field_pa_status_year:rrule', 'field_pa_status_year:to',
      'field_pa_governing_type:create_term', 'field_pa_governing_type:ignore_case',
      'field_pa_owner_type:create_term', 'field_pa_owner_type:ignore_case',
      'path', 'pathauto',

    ]);
  }

  protected function csvcolumns() {
    $columns[1] = array('wdpaid', 'Protected area ID');
    $columns[4] = array('name', 'Protected area name');
    $columns[7] = array('desig_en', 'Designation name in English');
    $columns[8] = array('desig_type', 'Designation type');
    $columns[9] = array('iucn_cat', 'IUCN classification category');
    $columns[14] = array('rep_area', 'Surface area');
    $columns[18] = array('status', 'Status');
    $columns[19] = array('status_yr', 'Status year');
    $columns[20] = array('gov_type', 'Governing type');
    $columns[21] = array('own_type', 'Owner type');
    $columns[22] = array('mang_auth', 'Management authority');
    $columns[23] = array('mang_plan', 'Management plan');
    $columns[28] = array('iso3', 'Country code');
    return $columns;
  }


  public function fields() {
    return array(
      'domains' => 'Assigned domains for this protected area. Computed field',
    );
  }


  public function generateMachineName() {
    return 'protected_planet_areas';
  }

  public function prepareRow($row) {
    // Country.
    if (!empty($row->iso3)) {
      // @var stdClass $country
      if ($country = PTK::getCountryByCode($row->iso3)) {
        $iso = $row->iso3;
        $row->iso3 = $country->tid;
        if ($domains = PTKDomain::getDomainsByCountryISO($iso)) {
          $row->domain_source = PTKDomain::$CHM_DOMAIN_ID;
          $row->domains = array_keys($domains);
        }
      }
      else {
        $this->log('Skipping protected area without country (WDPAID:' . $row->wdpaid . ')');
        return FALSE;
      }
    }
    else {
      $this->log('Skipping protected area without country (WDPAID:' . $row->wdpaid . ')');
      return FALSE;
    }

    $row->desig_type = self::getOrCreateTaxonomyTermByName($row->desig_type, 'pa_designation_type');
    $row->iucn_cat = self::getOrCreateTaxonomyTermByName($row->iucn_cat, 'pa_iucn_category');
    $row->status = self::getOrCreateTaxonomyTermByName($row->status, 'pa_status');
    $row->gov_type = self::getOrCreateTaxonomyTermByName($row->gov_type, 'pa_governing_type');
    $row->own_type = self::getOrCreateTaxonomyTermByName($row->own_type, 'pa_owner_type');

    return TRUE;
  }
}
