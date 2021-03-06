<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ptk_base_form_domain_form_alter(&$form, &$form_state, $form_id) {
  ChmDomainForm::alter($form, $form_state);
}


function ptk_base_domain_form_ajax_country($form, $form_state) {
  $control = $form['sitename'];
  if (!empty($form_state['values']['country']) &&
    $country = PTK::getCountryByCode($form_state['values']['country'])
  ) {
    $control['#value'] = 'Biodiversity ' . $country->name;
  }
  $ret[] = ajax_command_replace('sitename-wrapper', $control);
  return $ret;
}

class ChmDomainForm {

  static function alter(&$form, &$form_state) {
    $form['is_default']['#access'] = FALSE;
    $is_new = empty($form['#domain']['domain_id']);
    $domain = $form['#domain'];

    $form['subdomain']['#description'] = '<span style="color:red">'
      . t('If you selected a country above, set the machine name to ISO 2-letter code (i.e. "be").')
      .  '</span> '
      . $form['subdomain']['#description'];

    $form['sitename']['#prefix'] = '<div id="sitename-wrapper">';
    $form['sitename']['#suffix'] = '</div>';
    if (!PTKDomain::isDefaultDomain($domain)) {
      $countries = PTK::getCountryListAsOptions();
      $form['country'] = [
        '#title' => t('Country'),
        '#description' => t('Designate the country for this CHM portal'),
        '#type' => 'select',
        '#options' => $countries,
        '#empty_option' => t('- Select -'),
        '#default_value' => PTKDomain::variable_get('country', $form['#domain']),
        '#required' => FALSE,
        '#weight' => -10,
        '#ajax' => array(
          'callback' => 'ptk_base_domain_form_ajax_country',
          'wrapper' => 'sitename-wrapper',
          'method' => 'replace',
          'effect' => 'fade',
        ),
      ];
    }
    module_load_include('inc', 'domain_variable_locale', 'domain_variable_locale.variable');
    $languages = PTKDomain::variable_get('language_list', $form['#domain']);
    $languages = !empty($languages) ? array_values($languages) : array();
    if ($is_new && empty($languages)) {
      $languages = array('en');
    }
    if ($is_new) {
      $form['languages'] = [
        '#type' => 'fieldset',
        '#title' => t('List of active languages'),
        '#weight' => 40,
      ];
      $form['languages']['language_list'] = [
        '#title' => t('Select the languages to be available on this website'),
        '#type' => 'checkboxes',
        '#options' => domain_variable_locale_language_list([], []),
        '#default_value' => $languages,
        '#required' => TRUE,
      ];
      $form['ptk'] = [
        '#type' => 'fieldset',
        '#title' => t('Initialize domain content'),
        '#weight' => 50,
      ];
      $form['ptk']['populate_main_menu'] = [
        '#type' => 'checkbox',
        '#title' => t('Create standard pages and link them to main menu'),
      ];
      $form['ptk']['populate_footer_menu'] = [
        '#type' => 'checkbox',
        '#title' => t('Create standard pages and link them to footer menu'),
      ];
      $form['ptk']['create_sample_content'] = [
        '#type' => 'checkbox',
        '#title' => t('Create sample content (i.e. project, species etc.)'),
      ];
      $form['weight']['#access'] = FALSE;
      $form['submit']['#value'] = t('Create domain record');
    }
    $social = ChmSocialMediaForm::form($domain, $form);
    $form['ptk']['social'] = $social['ptk']['social'];

    $miscellaneous = ChmMiscellaneousForm::form($domain, $form);
    $form['ptk']['miscellaneous'] = $miscellaneous['ptk']['miscellaneous'];

    $form['submit']['#weight'] = 100;
    $form['#is_new'] = $is_new;
    $form['#submit'][] = array('ChmDomainForm', 'submit');
    $form['#validate'][] = array('ChmDomainForm', 'validate');
  }

  static function validate($form, $form_state) {
    if (strlen($form_state['values']['machine_name']) > 27) {
      form_set_error('machine_name', t("Domain's <strong>Machine-readable name</strong> must be 27 characters or less, please edit then submit again"));
    }
  }

  static function submit($form, $form_state) {
    $domain = $form['#domain'];
    if (empty($domain['machine_name'])) {
      $domain['machine_name'] = $form_state['values']['machine_name'];
    }

    $countryIsoCode = NULL;
    if (!PTKDomain::isDefaultDomain($domain)) {
      if ($countryIsoCode = $form_state['values']['country']) {
        PTKDomain::variable_set('country', $countryIsoCode, $domain);
      }
    }

    cache_clear_all();
    if (!empty($form['#is_new'])) {
      $machine_name = $form_state['values']['machine_name'];
      $domain_id = domain_load_domain_id($machine_name);
      $domain = domain_load($domain_id);
      self::initializeDomain($domain, $form_state['values']);
      cache_clear_all();
    }

    // Add the species import batch
    if ($countryIsoCode) {
      PTKDomain::set_country_treaty_data(NULL, $domain);

      $batch = array(
        'title' => t('Invoking IUCN RedList API species data, please be patient ...'),
        'operations' => array(
          array(
            array('ChmDomainForm', 'importSpeciesForCountry'),
            array($countryIsoCode)
          ),
        ),
        'finished' => array('ChmDomainForm', 'importSpeciesForCountryFinished')
      );
      batch_set($batch);
    }
  }


  public static function importSpeciesForCountry($iso, &$context) {
    $iucn = IUCNRedListAPI::instance();
    $count = $iucn->populateCountrySpecies($iso);
    $context['results'] = $count;
  }

  public static function importSpeciesForCountryFinished($success, $results) {
    if ($success) {
      $message = "$results species processed from IUCN RedList API.";
    }
    else {
      $message = t('Species synchronisation finished with an error.');
    }
    drupal_set_message($message);
  }


  public static function initializeDomain($domain, $values) {
    global $user;
    if (empty($domain)) {
      drupal_set_message('Cannot finish domain structure creation due to internal error, please contact technical support', 'error');
      return FALSE;
    }
    $country = PTK::getCountryByCode($values['country']);

    // Configure front-page
    PTKDomain::variable_set('site_frontpage', "main-home-page", $domain);
    if ($country) {
      // Site name
      PTKDomain::variable_set('site_name', "Biodiversity {$country->name}", $domain);
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
      PTKDomain::variable_set('site_name', "Biodiversity website", $domain);
    }

    // Configure slogan
    PTKDomain::variable_set('site_slogan', 'National Clearing-House Mechanism Training Website', $domain);

    // Enable languages
    drupal_static_reset('language_list');
    $languages = $values['language_list'];
    PTKDomain::variable_set('language_list', $languages, $domain);

    $flagname = strtolower($values['country']);
    $settings = [
      'logo_path' => "sites/all/themes/chm_theme_kit/flags/{$flagname}.png",
    ];

    // Set active theme
    if (module_exists('domain_theme') && function_exists('domain_theme_lookup')) {
      $theme = 'chm_theme_kit';
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

    $populate_footer_menu = !empty($values['populate_footer_menu']);
    self::createWebsiteFooterMenu($values['country'], $domain, $populate_footer_menu);

    // Main menu
    $menu = self::createWebsiteMainMenu($values['country'], $domain);
    $populate_main_menu = !empty($values['populate_main_menu']);
    if ($populate_main_menu) {
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
        $node['menu']['customized'] = 1;
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
        switch ($path) {
          case 'biodiversity':
            PTK::showBlockOnPage('ecosystems-block', 'node/' . $node->nid);
            break;
          case 'strategy':
            PTK::showBlockOnPage('nbsap-block', 'node/' . $node->nid);
            PTK::showBlockOnPage('cbd_national_targets-targets', 'node/' . $node->nid);
            PTK::showBlockOnPage('documents-nbsaps', 'node/' . $node->nid);
            break;
          case 'implementation':
            PTK::showBlockOnPage('projects-block_listing', 'node/' . $node->nid);
            break;
          case 'information':
            $node->title = $page;
            $node->type = 'page';
            node_object_prepare($node);
            $node->uid = 1;
            node_save($node);
            if (!empty($node->nid)) {
              // Show the Information block on this page
              PTK::showBlockOnPage('chm_information_page', 'node/' . $node->nid);
              PTK::showBlockOnPage('chm_information_page', 'node/' . $node->nid, 'bootstrap' );
            }
            break;
          case 'participate':
            node_save($node);
            break;
          case 'about':
            $node->title = $page;
            $default_node = node_load(1);
            $node->body = $default_node->body;
            $node->title_field = $default_node->title_field;
            node_save($node);
            break;
        }
      }

      $level2_information_links = [
        'news' => 'News',
        'events' => 'Events',
        'national-targets' => 'National targets',
        'facts' => 'Facts',
        'faq' => 'FAQ',
        'ecosystems' => 'Ecosystems',
        'protected-areas' => 'Protected areas',
        'projects' => 'Projects',
        'species' => 'Species',
        'organizations' => 'Organizations',
        'network-directory' => 'Network directory',
        'library' => 'Library',
        'videos' => 'Videos',
        'photo-galleries' => 'Image gallery',
        'links' => 'Related websites',
      ];

      $links = menu_load_links($menu['menu_name']);
      foreach ($links as $link) {
        if ($link['link_title'] == 'Information') {
          // Expand to enable drop-down
          $link['expanded'] = 1;
          $link['has_children'] = 1;
          menu_link_save($link);
          $i = 0;
          $menu_link_default = array(
            'menu_name' => $menu['menu_name'],
            'expanded' => 0,
            'depth' => 2,
            'plid' => $link['mlid'],
            'p1' => $link['mlid'],
            'customized' => 1,
          );
          $info_settings = ptk_base_get_information_settings();
          foreach($level2_information_links as $link_path => $link_title) {
            $new_link = $menu_link_default + [
              'link_title' => $link_title,
              'link_path' => $link_path,
              'weight' => $i++,
            ];

            $new_link['options']['attributes']['class'] = $info_settings[$link_path]['class'];
            if (@$info_settings[$link_path]['accesskey']) {
              $new_link['options']['attributes']['accesskey'] = $info_settings[$link_path]['accesskey'];
            }

            menu_link_save($new_link);
          }
        }
      }

      PTKDomain::variable_set('menu_main_links_source', $menu['menu_name'], $domain);
      PTKDomain::variable_set('populate_main_menu', TRUE, $domain);
    }

    $create_sample_content = !empty($values['create_sample_content']);
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
      PTKDomain::variable_set('create_sample_content', TRUE, $domain);
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
    PTKDomain::set_country_treaty_data($country, $domain);

    return TRUE;
  }


  public static function createWebsiteMainMenu($country, $domain) {
    $url = l($domain['path'], $domain['path']);
    $sitename = $domain['sitename'];
    $code = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $domain['machine_name']));
    $menu = array(
      'menu_name' => "menu-{$code}",
      'title' => "Main menu for {$sitename}",
      'description' => "Website's main menu for the <strong>$url</strong> portal",
      'i18n_mode' => I18N_MODE_MULTIPLE,
    );
    $exists = menu_load($menu['menu_name']);
    if (!$exists) {
      menu_save($menu);
    }

    $home_link = [
      'link_title' => 'Home',
      'link_path' => '<front>',
      'menu_name' => $menu['menu_name'],
      'weight' => 0,
      'expanded' => 0,
      'depth' => 1,
      'customized' => 1,
    ];
    menu_link_save($home_link);
    return $menu;
  }

  public static function createWebsiteFooterMenu($country, $domain, $populate_footer_menu) {
    global $user;
    $url = l($domain['path'], $domain['path']);
    // todo because of sql menu_name filed max length 32 we will use $country + domain_id
    $menu = array(
      'menu_name' => "footer-menu-{$country}-{$domain['domain_id']}",
      'title' => "Footer menu {$domain['sitename']}",
      'description' => "Website's footer menu for the <strong>$url</strong> portal",
      'i18n_mode' => I18N_MODE_MULTIPLE,
    );
    $exists = menu_load($menu['menu_name']);
    if (!$exists) {
      menu_save($menu);
      _block_rehash('bootstrap');
      _block_rehash('chm_theme_kit');
      db_update('block')
        ->condition('delta', $menu['menu_name'])
        ->condition('theme', 'chm_theme_kit')
        ->fields(['region' => 'footer', 'status' => 1, 'title' => '<none>'])
        ->execute();
      db_insert('domain_blocks')
        ->fields(array(
          'module' => 'menu',
          'delta' => $menu['menu_name'],
          'realm' => 'domain_id',
          'domain_id' => $domain['domain_id'],
        ))
        ->execute();
    }
    if ($populate_footer_menu) {
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
        'Contact' => ['node/3177', 'none'],
        'Credits' => ['credits'],
        'FAQ' => ['faq', 'none'],
        'Terms of use' => ['terms-of-use'],
      );
      $weight = 1;
      foreach ($pages as $link_title => $page) {
        $path = $page[0];
        $type = @$page[1];
        if ($type != 'none') {
          $node = $page_default_attributes;
          if ($type) {
            $node['type'] = $type;
          }
          $node['title'] = $node['menu']['link_title'] = $link_title;
          $node['menu']['weight'] = $weight++;
          $node['menu']['customized'] = 1;
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
        } else {
          $custom_link = [
            'link_title' => $link_title,
            'link_path' => $path,
            'menu_name' => $menu['menu_name'],
            'weight' => $weight++,
            'expanded' => 0,
            'depth' => 1,
            'customized' => 1,
          ];
          menu_link_save($custom_link);
        }
      }
    }

    PTKDomain::variable_set('populate_footer_menu', TRUE, $domain);
    return $menu;
  }

}