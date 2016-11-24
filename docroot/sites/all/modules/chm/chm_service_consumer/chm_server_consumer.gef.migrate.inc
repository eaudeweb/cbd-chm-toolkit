<?php

/**
 * Class for the GEF projects migration populating project node type.
 */
class CHMGEFProjectMigrate extends CHMServerConsumerMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'project_id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Primary key',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    if ($instance = file_stream_wrapper_get_instance_by_uri(variable_get(GEF_CSV_VAR))) {
      $this->source = new MigrateSourceCSV(
        $instance->realpath(),
        $this->csvcolumns(),
        array('header_rows' => 1,),
        $this->fields()
      );
    }
    else {
      throw new MigrateException('Cannot instantiate migration class because the CSV source data file does not exist. Visit /admin/config/system/chm_global_settings/gef-projects and upload a new file.');
    }
    $this->destination = new MigrateDestinationNode('project', array('language' => 'en'));

    // Project name
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('title_field', 'name');

    // GEF Project ID
    $this->addFieldMapping('field_gef_id', 'project_id');

    // Countries
    $this->addFieldMapping('field_countries', 'countries');
    $this->addFieldMapping('field_countries:source_type')->defaultValue('tid');

    // Focal areas
    $this->addFieldMapping('field_gef_focal_areas', 'focal_areas');
    $this->addFieldMapping('field_gef_focal_areas:source_type')->defaultValue('tid');

    // Implementing Agencies
    $this->addFieldMapping('field_project_organizations', 'implementing_agencies');

    // Project Type
    $this->addFieldMapping('field_gef_project_type', 'type');
    $this->addFieldMapping('field_gef_project_type:source_type')->defaultValue('tid');

    // GEF Project Grant
    $this->addFieldMapping('field_project_grant', 'grant');

    // Co-financing Total
    $this->addFieldMapping('field_co_financing_total', 'co_financing_total');

    // Latest Timeline Status
    $this->addFieldMapping('field_gef_project_status', 'status');
    $this->addFieldMapping('field_gef_project_status:source_type')->defaultValue('tid');

    // Approval FY
    $this->addFieldMapping('field_gef_approval_fiscal_year', 'approval_fy');

    // GEF Period
    $this->addFieldMapping('field_gef_period', 'period');
    $this->addFieldMapping('field_gef_period:source_type')->defaultValue('tid');

    // GEF project URL (computed)
    $this->addFieldMapping('field_url', 'url');

    $this->addFieldMapping('field_source', 'source');
    $this->addFieldMapping('field_source:source_type')->defaultValue('tid');

    $this->addFieldMapping('domains', 'domains');
    $this->addFieldMapping('uid')->defaultValue(USER_WALLE);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('language')->defaultValue('en');
    $this->addFieldMapping('domain_site')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);

    $this->addMetadataUnmigratedDestinations();
    $this->addUnmigratedDestinations([
      'nid', 'created', 'changed', 'revision', 'log', 'tnid', 'translate',
      'revision_uid', 'is_new', 'body',
      'body:summary', 'body:format', 'body:language',
      'field_image', 'field_image:file_class', 'field_image:language', 'field_image:preserve_files',
      'field_image:destination_dir', 'field_image:destination_file', 'field_image:file_replace',
      'field_image:source_dir', 'field_image:urlencode', 'field_image:alt', 'field_image:title',
      'title_field:language',
      'field_countries:create_term', 'field_countries:ignore_case',
      'field_gef_period:create_term', 'field_gef_period:ignore_case',
      'field_gef_project_type:create_term', 'field_gef_project_type:ignore_case',
      'field_source:create_term', 'field_source:ignore_case',
      'path', 'pathauto',
      'field_gef_focal_areas:create_term', 'field_gef_focal_areas:ignore_case',
      'field_gef_project_status:create_term', 'field_gef_project_status:ignore_case',
      'field_project_type', 'field_project_type:create_term', 'field_project_type:source_type', 'field_project_type:ignore_case',
      'field_url:title', 'field_url:attributes', 'field_url:language',
      'field_project_status', 'field_project_status:create_term', 'field_project_status:source_type', 'field_project_status:ignore_case',
      'field_dates', 'field_dates:timezone', 'field_dates:rrule', 'field_dates:to',
      'field_project_objectives', 'field_project_objectives:language',
      'field_project_activities', 'field_project_activities:language',
      'field_project_results', 'field_project_results:language',
      'field_aichi_targets', 'field_aichi_targets:create_term', 'field_aichi_targets:source_type', 'field_aichi_targets:ignore_case',
      'field_coverage_level', 'field_coverage_level:create_term', 'field_coverage_level:source_type', 'field_coverage_level:ignore_case',
      'field_government', 'field_government:create_term', 'field_government:source_type', 'field_government:ignore_case',
      'field_subjects', 'field_subjects:create_term', 'field_subjects:source_type', 'field_subjects:ignore_case',
      'field_reference',
      'field_gef_approval_fiscal_year:timezone', 'field_gef_approval_fiscal_year:rrule', 'field_gef_approval_fiscal_year:to',
      'field_project_organizations:revision_id',
    ]);
  }

  public function fields() {
    return array(
      'domains' => 'Assigned domains for this protected area. Computed field',
      'source' => 'Data source (in this case always GEF)',
      'url' => 'URL to GEF project (computed)'
    );
  }

  public function generateMachineName() {
    return 'gef_projects';
  }

  protected function csvcolumns() {
    $columns[0] = array('name', 'Project title');
    $columns[1] = array('project_id', 'GEF project ID');
    $columns[2] = array('countries', 'Project geographical area');
    $columns[3] = array('focal_areas', 'GEF project areas');
    $columns[4] = array('implementing_agencies', 'GEF implementing agencies');
    $columns[5] = array('type', 'GEF project type');
    $columns[6] = array('grant', 'GEF project grant');
    $columns[7] = array('co_financing_total', 'Co-financing total sum');
    $columns[8] = array('status', 'Latest timeline status');
    $columns[9] = array('approval_fy', 'Approval financing year');
    $columns[10] = array('period', 'GEF period');
    return $columns;
  }

  public function prepareRow($row) {
    if (empty($row->project_id)) {
      $this->log('Ignoring record without ID (' . $row->name . ')');
      return FALSE;
    }

    // name
    $name = $row->name;
    if (strpos($name, 'test') !== false) {
      $this->log('Ignoring test record (project ID:' . $row->project_id . ', ' . $row->name . ')');
      return FALSE;
    }
    $name = trim($name);
    $row->name = $name;

    // countries
    $row->countries = $this->prepareCountries($row);

    // focal_areas
    $row->focal_areas = $this->prepareFocalAreas($row);

    // implementing_agencies
    $row->implementing_agencies = array();
    // @todo implementing Agencies

    // type
    $row->type = self::getOrCreateTaxonomyTermByName($row->type, 'gef_project_type');

    // status
    $row->status = self::getOrCreateTaxonomyTermByName($row->status, 'gef_project_status');

    // period
    $row->period = self::getOrCreateTaxonomyTermByName($row->period, 'gef_period');

    // approval_fy - make a date compatible
    $row->approval_fy = $row->approval_fy . '-02-02';

    // source
    $row->source = self::getOrCreateTaxonomyTermByName('GEF', 'data_source');

    // Domain assignment
    $row->domain_source = PTKDomain::$CHM_DOMAIN_ID;
    $row->domains = array();
    if (!empty($row->countries)) {
      foreach ($row->countries as $tid) {
        if ($domains = PTKDomain::getDomainsByCountryTid($tid)) {
          $row->domains = array_merge($row->domains, array_keys($domains));
        }
      }
      $row->domains = array_unique($row->domains);
    }
    $row->domains[] = PTKDomain::$CHM_DOMAIN_ID;
    return TRUE;
  }


  function prepareFocalAreas($row) {
    if (empty(trim($row->focal_areas))) {
      return array();
    }
    $ret = array();
    $exploded = explode(', ', trim($row->focal_areas));
    foreach ($exploded as $name) {
      $name = trim($name);
      if ($term = self::getOrCreateTaxonomyTermByName($name, 'gef_focal_area')) {
        $ret[] = $term->tid;
      }
    }

    return $ret;
  }

  function prepareCountries($row) {
    if (empty(trim($row->countries))) {
      return array();
    }
    $ret = array();
    $exploded = explode(', ', trim($row->countries));
    $static_mappings = [
      'Vietnam' => 'Viet Nam',
      'St. Lucia' => 'Saint Lucia',
      'Timor Leste' => 'Timor-Leste',
      'St. Kitts And Nevis' => 'Saint Kitts and Nevis',
      'St. Vincent and Grenadines' => 'Saint Vincent and the Grenadines',
      'Lao DPR' => 'Laos',
      'Lao PDR' => 'Laos',
      'Korea DPR' => 'North Korea',
      'Congo DR' => 'Democratic Republic of the Congo',
      'Palestinian Authority' => 'Palestinian Territory, Occupied',
      'Bosnia-Herzegovina' => 'Bosnia and Herzegovina',
    ];
    foreach ($exploded as $name) {
      $name = trim($name);
      // Ignore global
      if (stripos($name, 'Global') !== FALSE
        || stripos($name, 'Regional') !== FALSE
        || stripos($name, 'Latin America and Caribbean') !== FALSE) {
        continue;
      }
      if (array_key_exists($name, $static_mappings)) {
        $name = $static_mappings[$name];
      }
      if (stripos($name, 'Serbia and Montenegro')) { // Dicks
        $serbia = PTK::getCountryByName('Serbia');
        $montenegro = PTK::getCountryByName('Montenegro');
        $ret[] = $serbia->tid;
        $ret[] = $montenegro->tid;
        continue;
      }

      // @todo Kosovo, Yugoslavia
      if ($tid = PTK::getCountryByName($name)) {
        $ret[] = $tid;
      }
      else {
        $this->log('Cannot find country (' . $name . ', project ID: ' . $row->project_id . ')');
      }
    }
    return $ret;
  }
}
