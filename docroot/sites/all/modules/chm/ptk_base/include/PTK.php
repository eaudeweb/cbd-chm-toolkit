<?php


class PTK {

  public static $PTK_ROOT_DOMAIN_ID = 18;

  /**
   * Retrieve the domain object corresponding to a country ISO code.
   */
  public static function getDomainByCountryISO($iso) {
    $all = domain_domains();
    foreach ($all as $domain_id => $config) {
      $realm_key = _domain_variable_realm_key($config['machine_name']);
      if ($code = variable_realm_get('domain', $realm_key, 'country')) {
        if ($iso == $code) {
          return $config;
        }
      }
    }
    return NULL;
  }


  /**
   * Get the Country of the current portal.
   *
   * @param array $domain
   *   A domain, if NULL the current domain (or default domain) is returned
   *
   * @return null|\stdClass
   *   Taxonomy term from 'countries' taxonomy for the current country
   */
  public static function getPortalCountry($domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    $realm_key = _domain_variable_realm_key($domain['machine_name']);
    if ($iso = variable_realm_get('domain', $realm_key, 'country')) {
      return self::getCountryByCode($iso);
    }
    return NULL;
  }

  public static function getCountryListAsOptions() {
    $ret = [];
    $countries = self::getCountryList();
    foreach ($countries as $country) {
      $w = entity_metadata_wrapper('taxonomy_term', $country);
      $code = $w->field_country_code->value();
      $ret[$code] = $w->label();
    }
    return $ret;
  }


  public static function getCountryList() {
    $items = drupal_static(__METHOD__);
    if (!isset($items)) {
      $v = taxonomy_vocabulary_machine_name_load('countries');
      $items = taxonomy_term_load_multiple(NULL, array('vid' => $v->vid));
    }
    return $items;
  }


  /**
   * Retrieve a country by its code.
   *
   * @param string $iso
   *   ISO 2L code.
   * @return stdClass|NULL
   *   Country object
   */
  public static function getCountryByCode($iso) {
    $items = drupal_static(__METHOD__);
    if (!isset($items)) {
      $q = db_select('field_data_field_country_code');
      $q->fields(NULL, array('entity_id', 'field_country_code_value'));
      $q->condition('entity_type', 'taxonomy_term');
      $q->condition('bundle', 'countries');
      $rows = $q->execute()->fetchAllKeyed();
      foreach ($rows as $k => $code) {
        $term = taxonomy_term_load($k);
        $w = entity_metadata_wrapper('taxonomy_term', $term);
        $term->iso2l = $w->field_country_code->value();
        $items[$code] = $term;
      }
    }
    $k = strtoupper(trim($iso));
    if (!empty($items[$k])) {
      return $items[$k];
    }
    return NULL;
  }


  /**
   * Retrieve a NFP Type term by its code.
   *
   * @param string $acronym
   *   Acronym for the term
   * @return stdClass|NULL
   *   The corrersponding taxonomy term
   */
  public static function getNFPTypeByAcronym($acronym) {
    $items = drupal_static(__METHOD__);
    if (!isset($items)) {
      $q = db_select('field_data_field_original_id');
      $q->fields(NULL, array('entity_id', 'field_original_id_value'));
      $q->condition('entity_type', 'taxonomy_term');
      $q->condition('bundle', 'taxonomy_nfp_type');
      $rows = $q->execute()->fetchAllKeyed();
      foreach ($rows as $k => $code) {
        $items[$code] = taxonomy_term_load($k);
      }
    }
    $k = strtoupper(trim($acronym));
    if (!empty($items[$k])) {
      return $items[$k];
    }
    return NULL;
  }

  public static function getCountryFlagURL($country) {
    try {
      $w = entity_metadata_wrapper('taxonomy_term', $country);
      if ($iso = $w->field_country_code->value()) {
        return url(
          sprintf('/sites/all/files/flags/%s.png', strtolower($iso)),
          array('absolute' => 1, 'language' => (object)array('language' => LANGUAGE_NONE))
        );
      }
    } catch (Exception $e) {
      watchdog_exception('ptk', $e);
    }
    return NULL;
  }

  public static function variable_realm_get($name, $domain = NULL) {
    $realm_name = 'domain';
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    $realm_key = $domain['machine_name'];
    return variable_realm_get($realm_name, $realm_key, $name);
  }

  public static function variable_realm_set($name, $value, $domain = NULL) {
    $realm_name = 'domain';
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    $realm_key = $domain['machine_name'];
    variable_realm_set($realm_name, $realm_key, $name, $value);
  }

  public static function createCountryMainMenu($country) {
    $menu = array(
      'menu_name' => "menu-main-menu-{$country}",
      'title' => "Main menu ({$country})",
      'description' => "Main menu for {$country} country.",
    );
    $exists = menu_load($menu['menu_name']);
    if (!$exists) {
      menu_save($menu);
    }
    return $menu;
  }

  public static function initializeCountryDomain($values) {
    global $user;
    $domain = domain_load(domain_load_domain_id($values['machine_name']));
    $country = self::getCountryByCode($values['country']);
    $menu = self::createCountryMainMenu($values['country']);
    $page_default_attributes = array(
      'type' => 'page',
      'status' => '1',
      'uid' => $user->uid,
      'name' => $user->name,
      'language' => 'en',
      'field_country' => array(
        LANGUAGE_NONE => array(
          '0' => array(
            'tid' => $country->tid,
          ),
        )
      ),
      'menu' => array(
        'enabled' => 1,
        'mlid' => 0,
        'module' => 'menu',
        'hidden' => 0,
        'has_children' => 0,
        'customized' => 0,
        'options' => array(),
        'expanded' => 0,
        'parent_depth_limit' => 8,
        'description' => '',
        'parent' => "{$menu['menu_name']}:0",
        'weight' => 0,
        'plid' => 0,
        'menu_name' => $menu['menu_name'],
      ),
      'domains' => array($domain['domain_id'] => $domain['domain_id']),
      'domain_site' => 0,
    );
    $pages = array(
      'Home',
      'Biodiversity',
      'Strategy',
      'Implementation',
      'Information',
      'Participate',
      'About us',
    );
    $weight = 0;
    foreach ($pages as $page) {
      $node = $page_default_attributes;
      $node['title'] = $node['menu']['link_title'] = $page;
      $node['menu']['weight'] = $weight++;
      $node = (object) $node;
      node_save($node);
      if ($page == 'Home') {
        self::variable_realm_set('site_frontpage', "node/{$node->nid}", $domain);
      }
    }

    self::variable_realm_set('menu_main_links_source', $menu['menu_name'], $domain);
    self::variable_realm_set('site_name', $values['sitename'], $domain);
    self::variable_realm_set('site_slogan', '', $domain);
    self::variable_realm_set('language_list', ['en' => 'en'], $domain);

  }
}
