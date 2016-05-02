<?php

/**
 * Class for the nfp_type migration populating taxonomy_nfp_type taxonomy.
 */
class CHMServerConsumerNFPTypeMigration extends CHMServerConsumerMigration {


  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        '_id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Entity original ID',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $this->source = new CHMServerConsumerNFPTypeMigrateSource($arguments['urlPattern']);
    $this->destination = new MigrateDestinationTerm('taxonomy_nfp_type');

    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('field_original_id', 'code');

    $this->addUnmigratedDestinations([
      'path', 'pathauto', 'weight', 'format', 'parent_name', 'parent', 'description',

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
}


/**
 * Migration source class for the nfp_type migration.
 */
class CHMServerConsumerNFPTypeMigrateSource extends CHMServerConsumerMigrateSource {

  /**
   * @inheritdoc
   */
  public function fields() {
    return [
      '_id'     => 'Remote record ID',
      'code'    => '@fake field to keep computed title',
      'treaty'  => 'Website',
      'name'    => 'Remote record ID',
      'acronym' => 'Alternative e-mails',
    ];
  }
}


/**
 * Class for the nfp migration populating cbd_nfp node type.
 */
class CHMServerConsumerNFPMigration extends CHMServerConsumerMigration {

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        '_id' => array(
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

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_url', 'website');
    $this->addFieldMapping('field_email', 'email');
    $this->addFieldMapping('field_alternative_emails', 'emailAlts');
    $this->addFieldMapping('field_fax_numbers', 'faxes');
    $this->addFieldMapping('field_phone_numbers', 'phones');
    $this->addFieldMapping('field_country', 'government');
    $this->addFieldMapping('field_country:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_postal_code', 'postalCode');
    $this->addFieldMapping('field_state', 'state');
    $this->addFieldMapping('field_city', 'city');
    $this->addFieldMapping('field_address', 'address');
    $this->addFieldMapping('field_organization_name', 'organization');
    $this->addFieldMapping('field_organization_acronym', 'organizationAcronym');
    $this->addFieldMapping('field_department', 'department');
    $this->addFieldMapping('field_nfp_designation', 'designation');
    $this->addFieldMapping('field_first_name', 'firstName');
    $this->addFieldMapping('field_last_name', 'lastName');
    $this->addFieldMapping('field_salutation', 'salutation');
    $this->addFieldMapping('field_nfp_type', 'types');
    $this->addFieldMapping('field_nfp_type:source_type')->defaultValue('tid');
    $this->addFieldMapping('language')->defaultValue('en');

    /*@TODO
      domain_site	Domain: all affiliates
      domains	Domain: assigned domains
      domain_source	Domain: Domain Source
    */


    $this->addUnmigratedDestinations([
      'uid', 'created', 'changed', 'status', 'promote', 'sticky', 'revision',
      'log', 'tnid', 'translate', 'revision_uid', 'is_new', 'path', 'pathauto',
      'comment',
      'body', 'body:summary', 'body:format',
      'field_url:title', 'field_url:attributes', 'field_url:language',
      'field_nfp_type:create_term', 'field_nfp_type:ignore_case',
      'field_country:create_term', 'field_country:ignore_case',

      'metatag_title', 'metatag_description', 'metatag_abstract', 'metatag_keywords',
      'metatag_robots', 'metatag_news_keywords', 'metatag_standout', 'metatag_rating',
      'metatag_referrer', 'metatag_generator', 'metatag_rights', 'metatag_image_src',
      'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author',
      'metatag_original-source', 'metatag_prev', 'metatag_next', 'metatag_content-language',
      'metatag_geo.position', 'metatag_geo.placename', 'metatag_geo.region',
      'metatag_icbm', 'metatag_refresh', 'metatag_revisit-after', 'metatag_pragma',
      'metatag_cache-control', 'metatag_expires',
    ]);

    $this->addUnmigratedSources([
      '__v',
    ]);
  }


  public function prepareRow($row) {
    $row->title = NULL;
    if (!empty($row->firstName)) {
      $row->title = $row->firstName;
    }
    if (!empty($row->lastName)) {
      if (!empty($row->firstName)) {
        $row->title .= ' ';
      }
      $row->title .= $row->lastName;
    }

    if (empty($row->title) && !empty($row->organization)) {
      $row->title = $row->organization;
    }

    if (empty($row->title)) {
      $f = '_id';
      $this->log(sprintf("Contact %s does not have a title", $row->{$f}));
      return FALSE;
    }

    // Country
    if (!empty($row->government)) {
      /** @var stdClass $country */
      if ($country = PTK::getCountryByCode($row->government)) {
        $row->government = $country->tid;
      }
      else {
        $row->government = NULL;
      }
    }

    // Type
    $types = array();
    if (!empty($row->types)) {
      foreach ($row->types as $type) {
        /** @var stdClass $type */
        if ($type = PTK::getNFPTypeByAcronym($type)) {
          $types[] = $type->tid;
        }
      }
    }
    $row->types = $types;

    return TRUE;
  }
}


/**
 * Migration source class for the nfp migration.
 */
class CHMServerConsumerNFPMigrateSource extends CHMServerConsumerMigrateSource {

  /**
   * @inheritdoc
   */
  public function fields() {
    return [
      '_id'                 => 'Remote record ID',
      'title'               => '@fake field to keep computed title',
      'website'             => 'Website',
      'emailAlts'           => 'Alternative e-mails',
      "email"               => 'Email',
      "faxes"               => 'One or more fax numbers',
      "phones"              => 'One or more phone numbers',
      "country"             => 'Country',
      "postalCode"          => 'Postal code',
      "state"               => 'State',
      "city"                => 'City',
      "address"             => 'Address',
      "organizationAcronym" => 'Organisation acronym',
      "organization"        => 'Organisation name',
      "department"          => 'Department',
      "designation"         => 'Designation',
      "lastName"            => 'Last name',
      "firstName"           => 'First name',
      "salutation"          => 'Salutation',
      "types"               => 'Focal point roles',
      "government"          => 'Government ISO code',
      "__v"                 => 'Version',
    ];
  }
}
