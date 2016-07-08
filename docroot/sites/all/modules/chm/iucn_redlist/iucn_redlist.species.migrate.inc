<?php

class IUCNRedListSpeciesMigration extends Migration {

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
    $this->source = new CHMServerConsumerNFPMigrateSource($arguments['urlPattern']);
    $this->destination = new MigrateDestinationNode('cbd_nfp');

    $this->addFieldMapping('field_original_id', 'taxonid');
    $this->addFieldMapping('title', 'scientific_name');
    $this->addFieldMapping('field_species_kingdom', 'kingdom');
    $this->addFieldMapping('field_species_phylum', 'phylum');
    $this->addFieldMapping('field_species_class', 'class');
    $this->addFieldMapping('field_species_order', 'order');
    $this->addFieldMapping('field_species_family', 'family');
    $this->addFieldMapping('field_species_genus', 'genus');
    $this->addFieldMapping('field_species_main_common_name', 'main_common_name');
    $this->addFieldMapping('field_species_authority', 'authority');
    $this->addFieldMapping('field_date', 'published_year');
    $this->addFieldMapping('field_redlist_status', 'category');

    $this->addUnmigratedDestinations([

    ]);

    $this->addUnmigratedSources([
      'criteria', 'marine_system', 'freshwater_system', 'terrestrial_system',
      'assessor', 'reviewer'
    ]);
  }

  public function prepareRow($row) {
    return TRUE;
  }
}

class IUCNRedListSpeciesSource extends MigrateSource {

  private $serviceUrl;
  private $apiToken;

  public function __construct($serviceUrl, $apiToken) {
    parent::__construct(array());
    $this->serviceUrl = $serviceUrl;
    $this->serviceUrl = $apiToken;
  }

  public function __toString() {
    return sprintf('Retrieve species data');
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
}
