<?php

class PTKDomain {

  /**
   * Get the ID of default domain
   *
   * @return integer
   *   ID of the default domain
   */
  public static function getDefaultDomainId() {
    if ($domain = self::getDefaultDomain()) {
      return $domain['domain_id'];
    }
    return NULL;
  }

  public static function isDefaultDomain($domain) {
    $self = domain_get_domain();
    if (!empty($self['domain_id']) && !empty($domain['domain_id'])) {
      return $self['domain_id'] == $domain['domain_id'];
    }
    return FALSE;
  }

  /**
   * Get the ID of default domain
   *
   * @return integer
   *   ID of the default domain
   */
  public static function getDefaultDomain() {
    $all = domain_domains();
    foreach ($all as $domain) {
      if (!empty($domain['is_default']) && $domain['is_default'] == 1) {
        return $domain;
      }
    }
    return NULL;
  }


  /**
   * Retrieve the domain object corresponding to a country ISO code.
   */
  public static function getDomainByCountryISO($iso) {
    $all = domain_domains();
    foreach ($all as $domain_id => $domain) {
      if ($value = PTKDomain::variable_get('country', $domain)) {
        if (strtoupper($iso) == strtoupper($value)) {
          return $domain;
        }
      }
    }
    return NULL;
  }

  public static function getIMCEUploadPath() {
    $domain = domain_get_domain();
    return 'uploads/' . $domain['machine_name'];
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
    if ($iso = self::variable_get('country', $domain)) {
      return PTK::getCountryByCode($iso);
    }
    return NULL;
  }


  public static function createCountryMainMenu($country, $domain) {
    $code = strtolower($country);
    $countries = PTK::getCountryListAsOptions();
    if (isset($countries[$code])) {
      $name = $countries[$code];
    }
    else {
      $name = $domain['subdomain'];
    }
    $menu = array(
      'menu_name' => "menu-main-menu-{$code}",
      'title' => "Main menu ({$code})",
      'description' => "Main menu for $name portal",
      'i18n_mode' => I18N_MODE_MULTIPLE,
    );
    $exists = menu_load($menu['menu_name']);
    if (!$exists) {
      menu_save($menu);
    }
    return $menu;
  }


  public static function initializeCountryDomain($domain, $values) {
    global $user;
    if (empty($domain)) {
      return FALSE;
    }
    $theme = 'chm_theme_kit';
    $country = PTK::getCountryByCode($values['country']);
    $create_main_menu = !empty($values['create_main_menu']);
    $create_sample_content = !empty($values['create_sample_content']);

    if ($country) {
      self::variable_set('site_name', "Biodiversity {$country->name}", $domain);
      /** @var stdClass $wrapper */
      $wrapper = entity_metadata_wrapper('taxonomy_term', $country);
      try {
        if ($ppid = $wrapper->field_protected_planet_id->value()) {
          PTKDomain::variable_set('ptk_protected_planet_id', $ppid, $domain);
        }
      } catch (Exception $e) {
        drupal_set_message('Could not set ProtectedPlanet ID automatically');
        watchdog_exception('ptk', $e);
      }
    }
    else {
      self::variable_set('site_name', "Biodiversity website", $domain);
    }
    self::variable_set('site_slogan', 'National Clearing-House Mechanism Training Website', $domain);
    drupal_static_reset('language_list');
    $languages = $values['language_list'];
    self::variable_set('language_list', $languages, $domain);

    $flagname = strtolower($values['country']);
    $settings = [
      'logo_path' => "sites/all/themes/chm_theme_kit/flags/{$flagname}.png",
    ];

    if (module_exists('domain_theme') && function_exists('domain_theme_lookup')) {
      $check = domain_theme_lookup($domain['domain_id'], $theme);
      if ($check != -1) {
        $existing = db_select('domain_theme', 't')
          ->fields('t', ['settings'])
          ->condition('t.domain_id', $domain['domain_id'])
          ->condition('t.theme', $theme)
          ->execute()->fetchField();
      }
      else {
        $existing = db_select('domain_theme', 't')
          ->fields('t', ['settings'])
          ->condition('t.theme', $theme)
          ->execute()->fetchField();
      }
      $existing = unserialize($existing);
      $settings = array_merge($existing, $settings);
      $settings = serialize($settings);

      if ($check != -1) {
        db_update('domain_theme')
          ->fields(array(
            'settings' => $settings,
          ))
          ->condition('domain_id', $domain['domain_id'])
          ->condition('theme', $theme)
          ->execute();
      }
      else {
        db_insert('domain_theme')
          ->fields(array(
            'domain_id' => $domain['domain_id'],
            'theme' => $theme,
            'settings' => $settings,
            'status' => 1,
          ))
          ->execute();
      }
    }

    if ($create_main_menu) {
      $menu = self::createCountryMainMenu($values['country'], $domain);
      $page_default_attributes = array(
        'type' => 'page',
        'status' => '1',
        'uid' => $user->uid,
        'name' => $user->name,
        'language' => 'en',
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
        $slug = str_replace(" ", "-", strtolower($page));
        db_insert('domain_path')
          ->fields(array(
            'domain_id' => $domain['domain_id'],
            'source' => 'node/' . $node->nid,
            'alias' => $slug,
            'language' => 'en',
            'entity_type' => 'node',
            'entity_id' => $node->nid,
          ))
          ->execute();
        switch ($page) {
          case 'Home':
            self::variable_set('site_frontpage', "node/{$node->nid}", $domain);
            PTK::addBlocksToNode(['home_page_slider-block', 'latest_updates-block', 'statistics-block_1'], $node->nid);
            break;
          case 'Biodiversity':
            PTK::addBlocksToNode(['ecosystems-block'], $node->nid);
            break;
          case 'Strategy':
            PTK::addBlocksToNode(['nbsap-block', 'national_targets-block'], $node->nid);
            break;
          case 'Implementation':
            PTK::addBlocksToNode(['projects-block'], $node->nid);
            break;
          case 'Information':
            $default_node = node_load(4);
            $node->body = $default_node->body;
            node_save($node);
            break;
          case 'Participate':
            $default_node = node_load(5);
            $node->body = $default_node->body;
            node_save($node);
            break;
          case 'About us':
            $default_node = node_load(6);
            $node->body = $default_node->body;
            node_save($node);
            break;
        }
      }
      self::variable_set('menu_main_links_source', $menu['menu_name'], $domain);
      self::variable_set('create_main_menu', TRUE, $domain);
    }

    if ($create_sample_content) {
      $content_types = [
        'document',
        'ecosystem',
        'event',
        'fact',
        'news',
      ];
      $number_of_nodes = 2;
      foreach ($content_types as $ct) {
        for ($i = 1 ; $i <= $number_of_nodes ; $i++) {
          $node_attributes = array(
            'type' => $ct,
            'title' => "{$ct} node {$i}",
            'status' => '1',
            'uid' => $user->uid,
            'name' => $user->name,
            'language' => 'en',
            'domains' => array($domain['domain_id'] => $domain['domain_id']),
            'domain_site' => 0,
          );
          $node = (object)$node_attributes;
          node_object_prepare($node);
          node_save($node);
        }
      }
      self::variable_set('create_sample_content', TRUE, $domain);
    }

    // Create entityqueue for slideshow.
    $default_queue = entityqueue_queue_load('slideshow_www');
    if (!empty($default_queue)) {
      $new_queue = (array) $default_queue;
      unset($new_queue['export_type']);
      $new_queue['name'] = $new_queue['label'] = 'slideshow_' . $domain['machine_name'];
      $new_queue['is_new'] = TRUE;
      $new_queue = new EntityQueue($new_queue);
      entityqueue_queue_save($new_queue);
    }
    return TRUE;
  }

  public static function variable_get($name, $domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    if (!empty($domain['domain_id'])) {
      return domain_variable_get($domain['domain_id'], $name);
    }
    return NULL;
  }

  public static function variable_set($name, $value, $domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    $realm_key = $domain['machine_name'];
    variable_realm_set('domain', $realm_key, $name, $value);
  }
}
