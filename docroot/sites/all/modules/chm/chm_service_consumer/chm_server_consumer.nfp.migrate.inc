<?php

/**
 * Class for the nfp_type migration populating taxonomy_nfp_type taxonomy.
 */
class CHMServerConsumerNFPTypeMigration extends CHMServerConsumerMigration {


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
      'id'     => 'Remote record ID',
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
        'id' => array(
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
//    $this->addFieldMapping('field_url', 'website');
    $this->addFieldMapping('field_email', 'email');
//    $this->addFieldMapping('field_alternative_emails', 'emailAlts');
    $this->addFieldMapping('field_fax_numbers', 'fax');
//    $this->addFieldMapping('field_phone_numbers', 'phones');
    $this->addFieldMapping('field_country', 'country');
    $this->addFieldMapping('field_country:source_type')->defaultValue('tid');
//    $this->addFieldMapping('field_postal_code', 'postalCode');
//    $this->addFieldMapping('field_state', 'state');
//    $this->addFieldMapping('field_city', 'city');
    $this->addFieldMapping('field_address', 'address');
    $this->addFieldMapping('field_organization_name', 'institution');
//    $this->addFieldMapping('field_organization_acronym', 'organizationAcronym');
    $this->addFieldMapping('field_department', 'department');
//    $this->addFieldMapping('field_nfp_designation', 'designation');
    $this->addFieldMapping('field_first_name', 'firstName');
    $this->addFieldMapping('field_last_name', 'lastName');
    $this->addFieldMapping('field_salutation', 'prefix');
//    $this->addFieldMapping('field_nfp_type', 'types');
//    $this->addFieldMapping('field_nfp_type:source_type')->defaultValue('tid');
    $this->addFieldMapping('language')->defaultValue('en');

    $this->addFieldMapping('domain_site')->defaultValue(FALSE);
    $this->addFieldMapping('domain_source', 'domain_source');
    $this->addFieldMapping('domains', 'domains');

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
    $row->title = trim($row->title);
    if (empty($row->title)) {
      $f = 'id';
      $this->log(sprintf("Contact %s does not have a title", $row->{$f}));
      return FALSE;
    }

    // Country.
    if (!empty($row->country)) {
      // @var stdClass $country
      if ($country = PTK::getCountryByCode($row->country)) {
        $iso = $row->country;
        $row->country = $country->tid;

        $domain = PTK::getDomainByCountryISO($iso);
        $row->domain_source = $domain['domain_id'];
        $row->domains = array($domain['domain_id']);
      }
      else {
        $row->country = NULL;
      }
    }

    return TRUE;
  }

  public function complete($entity, $row) {
    // Remove existing field collections roles.
    $fc_item_values = array();
    if (!empty($entity->field_nfp_roles)) {
      foreach ($entity->field_nfp_roles as $lang => $values) {
        foreach ($values as $idx => $value) {
          $fc_item_values[] = $value['value'];
          unset($entity->field_nfp_roles[$lang][$idx]);
        }
      }
    }
    entity_delete_multiple('field_collection_item', $fc_item_values);

    // Attach field collection roles.
    $voc_roles = taxonomy_vocabulary_machine_name_load('taxonomy_nfp_type');
    $voc_treaties = taxonomy_vocabulary_machine_name_load('treaties');
    if (is_array($row->roles)) {
      foreach ($row->roles as $role) {
        $item = array(
          'field_name' => 'field_nfp_roles',
        );
        if (!empty($role->treaty)) {
          $term = $this->termLoadFieldValue('treaties', 'field_informea_machine_name', $role->treaty);
          if (empty($term)) {
            $term = new stdClass();
            $term->vid = $voc_treaties->vid;
            $term->name = $role->treaty;
            $term->field_informea_machine_name[LANGUAGE_NONE][] = array('value' => $role->treaty);
            taxonomy_term_save($term);
          }
          else {
            $term = current($term);
          }
          $item['field_treaty'][LANGUAGE_NONE][] = array('tid' => $term->tid);
        }
        foreach ($role->roles as $role_name) {
          $term = taxonomy_get_term_by_name($role_name, 'taxonomy_nfp_type');
          if (empty($term)) {
            $term = new stdClass();
            $term->vid = $voc_roles->vid;
            $term->name = $role_name;
            taxonomy_term_save($term);
          }
          else {
            $term = current($term);
          }
          $item['field_nfp_type'][LANGUAGE_NONE][] = array(
            'tid' => $term->tid,
          );
        }
        $item = entity_create('field_collection_item', $item);
        $item->setHostEntity('node', $entity);
      }
    }
    node_save($entity);
  }
  
  public function termLoadFieldValue($vocabulary_name, $entity_field, $entity_value) {
    $tid = 0;
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', array($vocabulary_name))
      ->fieldCondition($entity_field, 'value', $entity_value, '=');
    $result = $query->execute();

    if ($result) {
      $terms = array_keys($result['taxonomy_term']);
      $tid = $terms[0];
    }

    return $tid;
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
      'id'                 => 'Remote record ID',
      'title'               => '@fake field to keep computed title',
//      'website'             => 'Website',
//      'emailAlts'           => 'Alternative e-mails',
      "email"               => 'Email',
      "fax"               => 'One or more fax numbers',
//      "phones"              => 'One or more phone numbers',
      "country"             => 'Country',
//      "postalCode"          => 'Postal code',
//      "state"               => 'State',
//      "city"                => 'City',
      "address"             => 'Address',
//      "organizationAcronym" => 'Organisation acronym',
      "institution"        => 'Organisation name',
      "department"          => 'Department',
//      "designation"         => 'Designation',
      "lastName"            => 'Last name',
      "firstName"           => 'First name',
      "prefix"          => 'Salutation',
//      "types"               => 'Focal point roles',
      "country"          => 'Government ISO code',
      "__v"                 => 'Version',
    ];
  }
}
