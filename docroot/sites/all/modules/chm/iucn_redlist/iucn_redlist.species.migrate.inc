<?php

class IUCNRedListSpeciesMigration extends Migration {

  private $service;

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'taxonid' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Entity original ID',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $this->service = IUCNRedListAPI::instance();
    $this->source = new IUCNRedListSpeciesSource($this->service);
    $this->destination = new MigrateDestinationNode('species', array('language' => 'en'));

    $this->addFieldMapping('field_original_id', 'taxonid');
    $this->addFieldMapping('title', 'scientific_name');
    $this->addFieldMapping('field_species_kingdom', 'kingdom');
    $this->addFieldMapping('field_species_kingdom:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_species_phylum', 'phylum');
    $this->addFieldMapping('field_species_phylum:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_species_class', 'class');
    $this->addFieldMapping('field_species_class:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_species_order', 'order');
    $this->addFieldMapping('field_species_order:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_species_family', 'family');
    $this->addFieldMapping('field_species_family:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_species_genus', 'genus');
    $this->addFieldMapping('field_species_main_common_name', 'main_common_name');
    $this->addFieldMapping('field_species_authority', 'authority');
    $this->addFieldMapping('field_species_authority:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_date', 'published_year');
    $this->addFieldMapping('field_redlist_status', 'category');
    $this->addFieldMapping('field_redlist_status:source_type')->defaultValue('tid');


    $this->addFieldMapping('domain_site')->defaultValue(FALSE);
    $this->addFieldMapping('domain_source', 'domain_source');
    $this->addFieldMapping('domains', 'domains');

    $this->addUnmigratedDestinations([

    ]);

    $this->addUnmigratedSources([
      'criteria', 'marine_system', 'freshwater_system', 'terrestrial_system',
      'assessor', 'reviewer'
    ]);
  }

  public function prepareRow($row) {
    if (empty($row->taxonid)) {
      return FALSE;
    }
    $row->kingdom = $this->getOrCreateTermByName($row->kingdom, 'species_kingdom');
    $row->phylum = $this->getOrCreateTermByName($row->phylum, 'species_phylum');
    $row->class = $this->getOrCreateTermByName($row->class, 'species_class');
    $row->order = $this->getOrCreateTermByName($row->order, 'species_order');
    $row->family = $this->getOrCreateTermByName($row->family, 'species_family');
    $row->authority = $this->getOrCreateTermByName($row->authority, 'species_authority');
    $row->category = $this->getOrCreateTermByMachineName($row->category, 'species_redlist_status');

    // Handle domain assignment
    $countries = $this->service->getLocalSpeciesCountries($row->taxonid);
    $domains = array();
    $row->domain_source = PTK::getDefaultDomainId();
    foreach($countries as $iso) {
      if ($domain = PTK::getDomainByCountryISO($iso)) {
        $domains[] = $domain['domain_id'];
      }
    }
    $row->domains = $domains;
    return TRUE;
  }

  public function getOrCreateTermByName($name, $vocabulary_machine_name) {
    if ($ret = taxonomy_get_term_by_name($name, $vocabulary_machine_name)) {
      $ret = current($ret);
    } else {
      $voc = taxonomy_vocabulary_machine_name_load($vocabulary_machine_name);
      $ret = new stdClass();
      $ret->vid = $voc->vid;
      $ret->language = LANGUAGE_NONE;
      $ret->name = $name;
      if ($voc->i18n_mode == 1) {
        $ret->language = 'en';
        $ret->name_field['en'][0]['value'] = $name;
      }
      taxonomy_term_save($ret);
    }
    return $ret->tid;
  }


  public function getOrCreateTermByMachineName($machine_name, $vocabulary_machine_name) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', array($vocabulary_machine_name))
      ->fieldCondition('field_machine_name', 'value', $machine_name, '=');
    if ($result = $query->execute()) {
      $terms = array_keys($result['taxonomy_term']);
      $tid = $terms[0];
    } else {
      $voc = taxonomy_vocabulary_machine_name_load($vocabulary_machine_name);
      $term = new stdClass();
      $term->language = LANGUAGE_NONE;
      $term->vid = $voc->vid;
      $term->name = $machine_name;
      $term->field_machine_name[LANGUAGE_NONE][] = array('value' => $machine_name);
      if ($voc->i18n_mode == 1) {
        $term->language = 'en';
        $term->name_field['en'][0]['value'] = $machine_name;
      }
      taxonomy_term_save($term);
      $tid = $term->tid;
    }
    return $tid;
  }
}

class IUCNRedListSpeciesSource extends MigrateSource {

  private $service;
  private $data = array();

  public function __construct(IUCNRedListAPI $service) {
    parent::__construct(array());
    $this->service = $service;
    $this->data = $this->service->getLocalSpeciesIDs();
  }

  /**
   * @inheritdoc
   */
  public function fields() {
    return [
      'taxonid' => 'Remote record ID',
      'scientific_name' => 'Species scientific name',
      'kingdom' => 'Kingdom',
      'phylum' => 'Phylum',
      'class' => 'Class',
      'order' => 'Order',
      'family' => 'Family',
      'genus' => 'Genus',
      'main_common_name' => 'Main vernacular name',
      'authority' => 'Authority person',
      'published_year' => 'Published year',
      'category' => 'Threat status',
      'criteria' => 'Criteria',
      'marine_system' => 'Is marine system? (boolean)',
      'freshwater_system' => 'Is freshwater system? (boolean)',
      'terrestrial_system' => 'Is terrestrial system? (boolean)',
      'assessor' => 'Assesor person',
      'reviewer' => 'Review person',
    ];
  }

  public function __toString() {
    return sprintf('Retrieve species data');
  }

  public function count($refresh = FALSE) {
    return count($this->data);
  }

  public function performRewind() {
    $this->data = $this->service->getLocalSpeciesIDs();
    reset($this->data);
  }

  /**
   * Fetch the next row of data, returning it as an object.
   *
   * @return object
   *   FALSE data as stdClass, FALSE when there is no more data available.
   */
  public function getNextRow() {
    if (count($this->data)) {
      $taxonid = current($this->data);
      next($this->data);
      if ($taxonid) {
        return $this->service->getRemoteSpeciesRecord($taxonid);
      }
    }
    return FALSE;
  }
}
