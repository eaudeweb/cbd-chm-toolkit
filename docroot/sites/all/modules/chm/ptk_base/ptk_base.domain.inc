<?php

class PTKDomain {

  public static $DEMO_DOMAIN_ID = 3;

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
   * Retrieve the enabled languages
   */
  public static function getLanguages($domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    $ret = array('en' => 'en');
    $enabled = self::variable_get('language_list', $domain);
    if (!empty($enabled) && is_array($enabled)) {
      $enabled = array_filter($enabled);
      $ret += $enabled;
      $ret = array_values($ret);
    }
    return $ret;
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

    self::variable_set('site_frontpage', "main-home-page", $domain);

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
      $home_link = [
        'link_title' => 'Home',
        'link_path' => '<front>',
        'menu_name' => $menu['menu_name'],
        'weight' => 0,
        'expanded' => 0,
        'depth' => 1,
      ];
      menu_link_save($home_link);

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
          'plid' => 0,
          'menu_name' => $menu['menu_name'],
        ),
        'domains' => array($domain['domain_id'] => $domain['domain_id']),
        'domain_site' => 0,
      );
      $pages = array(
        'Biodiversity' => 'biodiversity',
        'Strategy' => 'strategy',
        'Implementation' => 'implementation',
        'Information' => 'information',
        'Participate' => 'participate',
        'About us' => 'about',
      );
      $weight = 1;
      foreach ($pages as $page => $path) {
        $node = $page_default_attributes;
        $node['title'] = $node['menu']['link_title'] = $page;
        $node['menu']['weight'] = $weight++;
        $node = (object) $node;
        $node->path = array('pathauto' => 0, 'alias' => '');
        node_save($node);
        db_insert('domain_path')
          ->fields(array(
            'domain_id' => $domain['domain_id'],
            'source' => 'node/' . $node->nid,
            'alias' => $path,
            'language' => 'en',
            'entity_type' => 'node',
            'entity_id' => $node->nid,
          ))
          ->execute();
        switch ($page) {
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
            $node->title = $page;
            $node->type = 'page';
            node_object_prepare($node);
            $node->uid = 1;
            node_save($node);
            break;
          case 'Participate':
            node_save($node);
            break;
          case 'About us':
            $node->title = $page;
            $default_node = node_load(1);
            $node->body = $default_node->body;
            $node->title_field = $default_node->title_field;
            node_save($node);
            break;
        }
      }

      $links = menu_load_links($menu['menu_name']);
      foreach ($links as $link) {
        if ($link['link_title'] == 'Information') {
          $link['expanded'] = 1;
          $link['has_children'] = 1;
          menu_link_save($link);
          $new_link = [
            'link_title' => 'Species',
            'link_path' => 'species',
            'menu_name' => $menu['menu_name'],
            'weight' => 0,
            'expanded' => 0,
            'depth' => 2,
            'plid' => $link['mlid'],
            'p1' => $link['mlid'],
          ];
          menu_link_save($new_link);
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

    // Set treaty data
    self::set_country_treaty_data($country, $domain);

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

  public static function set_country_treaty_data($country = NULL, $domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    if (empty($country)) {
      $country =  PTK::getCountryByCode(self::variable_get('country', $domain));
    }
    $treaties = ['cbd', 'nagoya', 'cartagena'];
    foreach ($treaties as $treaty) {
      if (!empty($url = variable_get($treaty . '_ratification_xml_url'))) {
        $ratification = self::treaty_ratification_process_xml($url);
        if (!empty($ratification) && !empty($ratification->ratification)) {
          foreach ($ratification->ratification as $item) {
            if ($item->country == $country->name) {
              $value = serialize($item);
              self::variable_set($treaty . '_ratification', $value, $domain);
            }
          }
        }
      }
    }
  }

  /**
   * @param string $url URL to the XML
   * @return stdClass Object with data extracted from XML. Fields:
   * - source_url - Original URL
   * - ratification - array with ratification information (keys are country names in English)
   */
  public static function treaty_ratification_process_xml($url) {
    $ret = new stdClass();
    $ret->source_url = $url;
    $ret->ratification = array();
    $ret->entry_into_force = NULL;
    $response = drupal_http_request($url, array(
      'headers' =>  array('Accept' => 'text/xml'),
    ));
    if (!isset($response->error)) {
      $xml_str = $response->data;
      $xml = simplexml_load_string($xml_str, 'SimpleXMLElement', LIBXML_NOEMPTYTAG);
      if ($xml === FALSE) {

        return FALSE;
      }
      if ($eif = $xml->xpath('//EIF')) {
        if (!empty($eif[0])) {
          $eif = $eif[0];
          $entry_into_force = (string)$eif->Labeltext;
          if (!empty($entry_into_force)) {
            if ($pos = strpos($entry_into_force, ',')) {
              $entry_into_force = substr($entry_into_force, 0, $pos);
            }
            if ($date = DateTime::createFromFormat('d F Y', $entry_into_force)) {
              $ret->entry_into_force = $date->getTimestamp();
            }
          }
        }
      }

      $rows = $xml->xpath('//Participants/Table/TGroup/Tbody/Rows/Row');
      if (empty($rows)) {
        $rows = $xml->xpath('//Row');
      }
      if (!empty($rows)) {
        foreach($rows as $row) {
          $warnings = '';
          $row = $row->children();
          $new_row = array((string)$row[0], (string)$row[1], (string)$row[2]);
          if (!empty($row[3])) {
            $new_row[] = (string)$row[3];
          }
          $row = $new_row;
          $country = $row[0];
          if (!empty($country)) {
            // Remove additional data from country name such as footnote references
            $country = preg_replace('/\<superscript\>.*\<\/superscript\>/', '', $country);
          }
          else {
            $warnings .= 'Could not reliably determine the country name;';
          }

          $date1 = '';
          if (!empty($row[1]) && is_string($row[1])) {
            $parsed = date_parse($row[1]);
            if ($parsed !== FALSE) {
              //@todo: Inspect error_count, errors, warning_count and warnings inside $date1p
              $date1 = date('Y-m-d', mktime(0, 0, 0, $parsed['month'], $parsed['day'], $parsed['year']));
            } else {
              $warnings = sprintf('Canot parse date1: %s', $row[1]);
            }
          } else {
            if (!empty($row[1])) {
              $warnings = 'date1 is not a string. Removed';
            }
          }

          $date2 = '';
          if (!empty($row[2]) && is_string($row[2])) {
            $parsed = date_parse($row[2]);
            if ($parsed !== FALSE) {
              //@todo: Inspect error_count, errors, warning_count and warnings inside $date2p
              $date2 = date('Y-m-d', mktime(0, 0, 0, $parsed['month'], $parsed['day'], $parsed['year']));
            } else {
              $warnings = sprintf('Cannot parse date2: %s', $row[2]);
            }
          } else {
            if (!empty($row[2])) {
              $warnings = 'date2 is not a string. Setting to empty';
            }
          }
          $status = NULL;
          if (!empty($row[3])) {
            $status = strtolower($row[3]);
          } else if(preg_match('/\ a$/', $row[2])) { // a
            $status = 'accession';
          } elseif(preg_match('/\ AA$/', $row[2])) { // AA
            $status = 'approval';
          } elseif(preg_match('/\ A$/', $row[2])) { // A
            $status = 'acceptance';
          } elseif (!empty($date2)) {
            $status = 'ratification';
          } else {
            $status = 'signatory';
          }
          $ob = new stdClass();
          $ob->country = $country;
          $ob->country_verbatim = $row[0];
          $ob->date1 = $date1;
          $ob->date1_verbatim = $row[1];
          $ob->date2 = $date2;
          $ob->date2_verbatim = $row[2];
          $ob->status = $status;
          $ob->warnings = $warnings;
          $ob->errors = array();
          $ret->ratification[] = $ob;
        }
      }
    }
    return $ret;
  }

}
