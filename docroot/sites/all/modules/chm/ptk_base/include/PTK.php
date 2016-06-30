<?php


class PTK {

  /**
   * Get the ID of default domain
   *
   * @return integer
   *   ID of the default domain
   */
  public static function getDefaultDomainId() {
    $all = domain_domains();
    foreach ($all as $domain) {
      if (!empty($domain['is_default']) && $domain['is_default'] == 1) {
        return $domain['domain_id'];
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
      if ($value = PTK::variable_realm_get('country', $domain)) {
        if (strtoupper($iso) == strtoupper($value)) {
          return $domain;
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
      $code = $w->field_iso_code->value();
      $ret[strtolower($code)] = $w->label();
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
      $q = db_select('field_data_field_iso_code');
      $q->fields(NULL, array('entity_id', 'field_iso_code_value'));
      $q->condition('entity_type', 'taxonomy_term');
      $q->condition('bundle', 'countries');
      $rows = $q->execute()->fetchAllKeyed();
      foreach ($rows as $k => $code) {
        $term = taxonomy_term_load($k);
        $w = entity_metadata_wrapper('taxonomy_term', $term);
        $term->iso2l = $w->field_iso_code->value();
        $term->iso3l = $w->field_iso3l_code->value();
        $items[strtoupper($code)] = $term;
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
      if ($iso = $w->field_iso_code->value() && $image = $w->field_image->value()) {
        return url(file_create_url($image['uri']),
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
    $code = strtolower($country);
    $countries = self::getCountryListAsOptions();
    $name = $countries[$code];
    $menu = array(
      'menu_name' => "menu-main-menu-{$code}",
      'title' => "Main menu ({$code})",
      'description' => "Main menu for $name website",
      'i18n_mode' => I18N_MODE_MULTIPLE,
    );
    $exists = menu_load($menu['menu_name']);
    if (!$exists) {
      menu_save($menu);
    }
    return $menu;
  }

  protected static function addBlocksToNode($blocks, $nid, $theme = 'chm_theme_kit') {
    if (!is_array($blocks)) {
      $blocks = [$blocks];
    }
    foreach ($blocks as $block) {
      $q = db_select('block', 'b')
        ->condition('b.delta', $block)
        ->condition('b.theme', $theme)
        ->fields('b', ['pages']);
      $pages = $q->execute()->fetchField();
      $pages .= "\nnode/{$nid}";
      db_update('block')
        ->condition('delta', $block)
        ->condition('theme', $theme)
        ->fields([
          'pages' => $pages,
        ])
        ->execute();
    }
  }

  public static function initializeCountryDomain($domain, $values) {
    global $user;
    if (empty($domain)) {
      return FALSE;
    }
    $theme = 'chm_theme_kit';
    $country = self::getCountryByCode($values['country']);
    $create_main_menu = !empty($values['create_main_menu']);
    $create_sample_content = !empty($values['create_sample_content']);

    if ($country) {
      self::variable_realm_set('site_name', "Biodiversity {$country->name}", $domain);
      /** @var stdClass $wrapper */
      $wrapper = entity_metadata_wrapper('taxonomy_term', $country);
      try {
        if ($ppid = $wrapper->field_protected_planet_id->value()) {
          PTK::variable_realm_set('ptk_protected_planet_id', $ppid, $domain);
        }
      } catch (Exception $e) {
        drupal_set_message('Could not set ProtectedPlanet ID automatically');
        watchdog_exception('ptk', $e);
      }
    }
    else {
      self::variable_realm_set('site_name', "Biodiversity website", $domain);
    }
    self::variable_realm_set('site_slogan', 'National Clearing-House Mechanism Training Website', $domain);
    drupal_static_reset('language_list');
    $languages = $values['language_list'];
    self::variable_realm_set('language_list', $languages, $domain);

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
      $menu = self::createCountryMainMenu($values['country']);
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
            self::variable_realm_set('site_frontpage', "node/{$node->nid}", $domain);
            self::addBlocksToNode(['home_page_slider-block', 'latest_updates-block', 'statistics-block_1'], $node->nid);
            break;
          case 'Biodiversity':
            self::addBlocksToNode(['ecosystems-block'], $node->nid);
            break;
          case 'Strategy':
            self::addBlocksToNode(['nbsap-block', 'national_targets-block'], $node->nid);
            break;
          case 'Implementation':
            self::addBlocksToNode(['projects-block'], $node->nid);
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
      self::variable_realm_set('menu_main_links_source', $menu['menu_name'], $domain);
      self::variable_realm_set('create_main_menu', TRUE, $domain);
    }

    if ($create_sample_content) {
      $content_types = [
        'best_practice',
        'cbd_nfp',
        'carousel_slider',
        'document',
        'ecosystem',
        'event',
        'biodiversity_fact',
        'nbsap',
        'national_focal_point',
        'target',
        'need',
        'article',
        'organization',
        'person',
        'project',
        'protected_area',
        'resource',
        'species',
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
          $node = (object) $node_attributes;
          if ($ct == 'carousel_slider') {
            $node->field_slider_image = [
              LANGUAGE_NONE => [
                0 => (array) file_load(77),
              ],
            ];
            $node->field_slider_link = [
              LANGUAGE_NONE => [
                0 => [
                  'url' => 'http://example.com',
                  'title' => "{$ct} node {$i}",
                ],
              ],
            ];
            $node->field_slider_text = $node->field_slider_link_text = $node->field_weight = [
              LANGUAGE_NONE => [
                0 => [
                  'value' => $i,
                ],
              ],
            ];
          }
          node_save($node);
        }
      }
      self::variable_realm_set('create_sample_content', TRUE, $domain);
    }
    return TRUE;
  }


  /**
   * @param integer $from
   *   Start timestamp
   * @param integer $to
   *   End timestamp
   *
   * @return array
   *   Array with two elements, first is the start date, second is the end
   *   date representation or NULL. If input is invalid yields (NULL, NULL)
   */
  static function dateInterval($from, $to, $config = array()) {
    if (empty($from)) {
      return array(NULL, NULL);
    }
    $cfg = array_merge(array(
      'to_format' => 'j F Y',
      'from_day' => 'j',
      'from_day_month' => 'j F',
      'from_full' => 'j F Y'
    ), $config);
    $f_year = date('Y', $from);
    $t_year = !empty($to) ? date('Y', $to) : NULL;
    $f_month = date('F', $from);
    $t_month = !empty($to) ? date('F', $to) : NULL;
    $f_day = date('j', $from);
    $t_day = !empty($to) ? date('j', $to) : NULL;
    $to_str = !empty($to) ? date($cfg['to_format'], $to) : NULL;

    if ($f_year != $t_year) {
      // Go full date
      return array(date($cfg['from_full'], $from), $to_str);
    }
    else {
      if ($f_month != $t_month) {
        return array(date($cfg['from_day_month'], $from), $to_str);
      }
      else {
        if ($f_day != $t_day) {
          return array(date($cfg['from_day'], $from), $to_str);
        }
      }
    }
    return array(NULL, NULL);
  }

  static function dateIntervalString($from, $to) {
    list($start, $end) = self::dateInterval($from, $to);
    if (empty($end)) {
      return $start;
    }
    else {
      return t('!start_date to !end_date', array('!start_date' => $start, '!end_date' => $end));
    }
  }

  /**
   * Log a message.
   *
   * @param string $message
   */
  static function log_debug($message) {
    if (function_exists('drush_log')) {
      drush_log($message, \Drush\Log\LogLevel::NOTICE);
    }
  }

  /**
   * Log a message.
   *
   * @param string $message
   */
  static function log_warning($message) {
    if (function_exists('drush_log')) {
      drush_log($message, \Drush\Log\LogLevel::WARNING);
    }
  }

  /**
   * Log a message.
   *
   * @param string $message
   */
  static function log_error($message) {
    if (function_exists('drush_log')) {
      drush_log($message, \Drush\Log\LogLevel::ERROR);
    }
  }
}
