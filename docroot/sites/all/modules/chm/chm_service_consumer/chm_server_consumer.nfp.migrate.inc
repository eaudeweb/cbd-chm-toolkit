<?php

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
    $this->addFieldMapping('field_title', 'title');
    $this->addFieldMapping('field_email', 'email');
    $this->addFieldMapping('field_fax_numbers', 'fax');
    $this->addFieldMapping('field_countries', 'country');
    $this->addFieldMapping('field_countries:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_address', 'address');
    $this->addFieldMapping('field_organization_name', 'institution');
    $this->addFieldMapping('field_department', 'department');
    $this->addFieldMapping('field_first_name', 'firstName');
    $this->addFieldMapping('field_last_name', 'lastName');
    $this->addFieldMapping('field_salutation', 'prefix');
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
      'field_url:title', 'field_url:attributes', 'field_url:language',
      'field_nfp_type:create_term', 'field_nfp_type:ignore_case',

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

        $domain = PTKDomain::getDomainByCountryISO($iso);
        $row->domain_source = $domain['domain_id'];
        $row->domains = array($domain['domain_id']);
      }
      else {
        $row->country = NULL;
      }
    }

    return TRUE;
  }

  public function prepare($entity, $row) {
    if (!empty($entity->nid)) {
      $node = node_load($entity->nid);
      $entity->field_nfp_roles = $node->field_nfp_roles;
    }
    $existing = $this->getContactRoles($entity);
    // Attach new roles
    if (is_array($row->roles)) {
      foreach ($row->roles as $role) {
        if (empty($role->treaty)) {
          continue;
        }
        $treatyId = $this->getTreaty($role->treaty);
        $item = array(
          'field_name' => 'field_nfp_roles',
          'field_treaty' => array(LANGUAGE_NONE => array(0 => array('tid' => $treatyId))),
          'field_nfp_type' => array(LANGUAGE_NONE => array())
        );
        $roles = array();
        foreach ($role->roles as $role_name) {
          $rid = $this->getRoleId($role_name);
          $roles[] = $rid;
          $item['field_nfp_type'][LANGUAGE_NONE][] = array('tid' => $rid);
        }
        if (!$this->roleExists($treatyId, $roles, $existing)) {
          $item = entity_create('field_collection_item', $item);
          $item->setHostEntity('node', $entity);
        }
      }
    }
    // Remove revoked roles
    foreach ($entity->field_nfp_roles[LANGUAGE_NONE] as $i => $v) {
      $key = $v['value'];
      if (array_key_exists($key, $existing)) {
        unset($entity->field_nfp_roles[LANGUAGE_NONE][$i]);
      }
    }
    entity_delete_multiple('field_collection_item', array_keys($existing));
    node_save($entity);
  }


  public function roleExists($treatyId, $roles, &$existing) {
    foreach ($existing as $id => $v) {
      if ($v['treatyId'] == $treatyId && (!array_diff($v['roles'], $roles) && !array_diff($roles, $v['roles']))) {
        unset($existing[$id]);
        return $id;
      }
    }
    return FALSE;
  }

  public function getContactRoles($entity) {
    $fc_item_values = array();
    if (!empty($entity->field_nfp_roles[LANGUAGE_NONE])) {
      foreach ($entity->field_nfp_roles[LANGUAGE_NONE] as $idx => $value) {
        $fc_item_values[] = $value['value'];
      }
    }
    $existing = array();
    $rows = entity_load('field_collection_item', $fc_item_values);
    foreach ($rows as $row) {
      $roles = array();
      foreach ($row->field_nfp_type[LANGUAGE_NONE] as $r) {
        $roles[] = $r['tid'];
      }
      $existing[$row->item_id] = array('treatyId' => $row->field_treaty[LANGUAGE_NONE][0]['tid'], 'roles' => $roles);
    }
    return $existing;
  }
  
  public function getTreaty($entity_value) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', array('treaties'))
      ->fieldCondition('field_machine_name', 'value', $entity_value, '=');
    if ($result = $query->execute()) {
      $terms = array_keys($result['taxonomy_term']);
      $tid = $terms[0];
    } else {
      $voc_treaties = taxonomy_vocabulary_machine_name_load('treaties');
      $term = new stdClass();
      $term->vid = $voc_treaties->vid;
      $term->name =$entity_value;
      $term->language = 'en';
      $term->field_machine_name[LANGUAGE_NONE][] = array('value' => $entity_value);
      $term->name_field['en'][0]['value'] = $entity_value;
      taxonomy_term_save($term);
      $tid = $term->tid;
    }
    return $tid;
  }

  public function getRoleId($value) {
    if ($ret = taxonomy_get_term_by_name($value, 'taxonomy_nfp_type')) {
      $ret = current($ret);
    } else {
      $voc_roles = taxonomy_vocabulary_machine_name_load('taxonomy_nfp_type');
      $ret = new stdClass();
      $ret->vid = $voc_roles->vid;
      $ret->language = 'en';
      $ret->name = $value;
      $ret->name_field['en'][0]['value'] = $value;
      taxonomy_term_save($ret);
    }
    return $ret->tid;
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
      'id' => 'Remote record ID',
      'title' => '@fake field to keep computed title',
      'email' => 'Email',
      'fax' => 'One or more fax numbers',
      'country' => 'Country ISO code',
      'address' => 'Address',
      'institution' => 'Organisation name',
      'department' => 'Department',
      'lastName' => 'Last name',
      'firstName' => 'First name',
      'prefix' => 'Salutation',
    ];
  }
}
