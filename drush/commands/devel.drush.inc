<?php

/**
 * Implements hook_drush_command().
 */
function devel_drush_command() {
  $items = array();
  $items['prepare-test'] = array(
    'description' => 'Configures the database for testing environment after copying from production.',
    'callback' => '_drush_prepare_test',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'examples' => array(
      'drush prepare-test' => 'Prepare the test instance after cloning the production database.',
    ),
  );
  $items['prepare-dev'] = array(
    'description' => 'Configures the current instance for local development.',
    'callback' => '_drush_prepare_dev',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'examples' => array(
      'drush prepare-dev' => 'Change the domains, permissions, variables for local development',
    ),
  );

  return $items;
}

function _drush_prepare_dev() {
  $env = variable_get('environment');
  if ($env != 'dev') {
    drush_set_error("Refusing to destroy the current environment ($env). Please set environment to 'dev' (drush vset environment dev)");
    return;
  }
  if (!drush_confirm('Are you sure you want to alter the current instance?')) {
    return;
  }
  if (module_exists('overlay')) {
    module_disable(['overlay']);
  }
  module_disable(['memcache_storage']);
  module_enable(['devel', 'path_breadcrumbs_ui']);
  foreach (domain_domains() as $id => $domain) {
    $domain = domain_load($id);
    _drush_prepare_development_domains($domain);
    drush_log('Configuring ' . $domain['scheme'] . '://' . $domain['subdomain'], 'ok');
    domain_save($domain);
  }
  if (module_exists('devel')) {
    drush_log('Assign devel access to everyone');
    user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access devel information'));
    user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access devel information'));
  }
  variable_set('eu_cookie_compliance_domain', 'local.ro');
  variable_set('page_compression', 0);
  variable_set('preprocess_css', 0);
  variable_set('preprocess_js', 0);
  drush_invoke_process('@self', 'sql-sanitize');
}


function _drush_prepare_development_domains(&$domain) {
  $domain['scheme'] = 'http';
  switch($domain['subdomain']) {
    case 'biodiversity-albania.chm-cbd.net':
    case 'new-al.chm-cbd.net':
      $domain['subdomain'] = 'chm7-al.local.ro';
      $domain['path'] = 'http://chm7-al.local.ro';
      break;
    case 'biodiversity-kazakhstan.chm-cbd.net':
    case 'new-kz.chm-cbd.net':
      $domain['subdomain'] = 'chm7-kz.local.ro';
      $domain['path'] = 'http://chm7-kz.local.ro';
      break;
    default:
      $subjects = array('www.' , 'demo.',      'new-' , 'old-' , '.chm-cbd.net');
      $replaces = array('chm7.', 'chm7-demo.', 'chm7-', 'chm7-', '.local.ro');
      $domain['subdomain'] = str_replace($subjects, $replaces, $domain['subdomain']);
      $domain['path'] = str_replace($subjects, $replaces, $domain['path']);
  }
}


function _drush_prepare_test() {
  $env = variable_get('environment');
  if ($env != 'test') {
    drush_set_error("Refusing to destroy the current environment ($env). Please set environment to 'test' (drush vset environment test)");
    return;
  }
  if (!drush_confirm('Are you sure you want to alter the current instance?')) {
    return;
  }
  foreach (domain_domains() as $id => $domain) {
    $domain = domain_load($id);
    _drush_prepare_test_existing_domains($domain);
    drush_log('Configuring ' . $domain['scheme'] . '://' . $domain['subdomain'], 'ok');
    domain_save($domain);
  }
  /** @var SearchApiServer $server */
  if ($server = search_api_server_load('apache_solr_search_server')) {
    if ($server->options['path'] != '/solr/chm-test') {
      drush_log('Updating Solr server path to /solr/chm-test', 'ok');
      $server->options['path'] = '/solr/chm-test';
      $server->save();
    }
  }

  _drush_chm_create_test_domains();
}


function _drush_prepare_test_existing_domains(&$domain) {
  $domain['scheme'] = 'http';
  switch($domain['subdomain']) {
    case 'biodiversity-albania.chm-cbd.net':
      $domain['subdomain'] = 'new-al.chm-cbd.net';
      $domain['path'] = 'http://new-al.chm-cbd.net';
      break;
    case 'biodiversity-kazakhstan.chm-cbd.net':
      $domain['subdomain'] = 'new-kz.local.ro';
      $domain['path'] = 'http://new-kz.local.ro';
      break;
    default:
      $subjects = array('www.' , 'demo.');
      $replaces = array('new-www.', 'new-demo.');
      $domain['subdomain'] = str_replace($subjects, $replaces, $domain['subdomain']);
      $domain['path'] = str_replace($subjects, $replaces, $domain['path']);
  }
}

/**
 * Create the domains on the test server together with their links etc.
 */
function _drush_chm_create_test_domains() {
  // Enable custom languages
  $existing = language_list();
  $languages = array(
    'hy' => 'Armenian',
    'az' => 'Azerbaijian',
    'bs' => 'Bosnian',
    'bg' => 'Bulgarian',
    'ky' => 'Kyrgyz',
    'sr' => 'Serbian',
    'tg' => 'Tajik',
    'tk' => 'Turkmen',
    'uk' => 'Ukrain',
    'fj' => 'Fiji',
    'hi' => 'Hindi',
    'bi' => 'Bislama',
  );
  foreach ($languages as $code => $name) {
    if (!array_key_exists($code, $existing)) {
      drush_log("Adding new language: $name ($code)" , 'ok');
      locale_add_language($code);
    }
  }
  if (!array_key_exists('pis', $existing)) {
    drush_log("Adding new language: Pijin (pis)" , 'ok');
    locale_add_language('pis', 'Pijin', 'Pijin', LANGUAGE_LTR, '', 'pis', TRUE);
  }

  $defaults = array(
    // 'subdomain' => NULL,
    // 'sitename' => NULL,
    'scheme' => 'http',
    'valid' => 1,
    'domain_id' => NULL,
    // 'machine_name' => NULL,
    'populate_main_menu' => 1,
    'op' => 'Create domain record',
    // 'language_list' => array('en' => 'en'),
  );
  $domains = array();
  $domains['biodiversity_armenia'] = $defaults + array(
      'subdomain' => 'new-am.chm-cbd.net',
      'sitename' => 'Biodiversity Armenia',
      'country' => 'am',
      'language_list' => array('en' => 'en', 'hy' => 'hy'),
  );
  $domains['biodiversity_azerbaijan'] = $defaults + array(
      'subdomain' => 'new-az.chm-cbd.net',
      'sitename' => 'Biodiversity Azerbaijan',
      'machine_name' => 'biodiversity_azerbaijan',
      'country' => 'az',
      'language_list' => array('en' => 'en', 'az' => 'az'),
  );
  $domains['biodiversity_bosnia_herzegovina'] = $defaults + array(
      'subdomain' => 'new-ba.chm-cbd.net',
      'sitename' => 'Biodiversity Bosnia & Herzegovina',
      'machine_name' => 'biodiversity_bosnia_herzegovina',
      'country' => 'ba',
      'language_list' => array('en' => 'en', 'bs' => 'bs'),
  );
  $domains['biodiversity_bulgaria'] = $defaults + array(
      'subdomain' => 'new-bg.chm-cbd.net',
      'sitename' => 'Biodiversity Bulgaria',
      'machine_name' => 'biodiversity_bulgaria',
      'country' => 'bg',
      'language_list' => array('en' => 'en', 'bg' => 'bg'),
  );
  $domains['biodiversity_kyrgyzstan'] = $defaults + array(
      'subdomain' => 'new-kg.chm-cbd.net',
      'sitename' => 'Biodiversity Kyrgyzstan',
      'machine_name' => 'biodiversity_kyrgyzstan',
      'country' => 'kg',
      'language_list' => array('en' => 'en', 'ru' => 'ru', 'ky' => 'ky'),
  );
  $domains['biodiversity_serbia'] = $defaults + array(
      'subdomain' => 'new-rs.chm-cbd.net',
      'sitename' => 'Biodiversity Serbia',
      'machine_name' => 'biodiversity_serbia',
      'country' => 'rs',
      'language_list' => array('en' => 'en', 'sr' => 'sr'),
  );
  $domains['biodiversity_tajikistan'] = $defaults + array(
      'subdomain' => 'new-tj.chm-cbd.net',
      'sitename' => 'Biodiversity Tajikistan',
      'machine_name' => 'biodiversity_tajikistan',
      'country' => 'tj',
      'language_list' => array('en' => 'en', 'ru' => 'ru', 'tg' => 'tg'),
  );
  $domains['biodiversity_turkmenistan'] = $defaults + array(
      'subdomain' => 'new-tm.chm-cbd.net',
      'sitename' => 'Biodiversity Turkmenistan',
      'machine_name' => 'biodiversity_turkmenistan',
      'country' => 'tm',
      'language_list' => array('en' => 'en', 'ru' => 'ru', 'tk' => 'tk'),
  );
  $domains['biodiversity_ukraine'] = $defaults + array(
      'subdomain' => 'new-ua.chm-cbd.net',
      'sitename' => 'Biodiversity Ukraine',
      'machine_name' => 'biodiversity_ukraine',
      'country' => 'ua',
      'language_list' => array('en' => 'en', 'uk' => 'uk'),
  );
  $domains['biodiversity_fiji'] = $defaults + array(
      'subdomain' => 'new-fj.chm-cbd.net',
      'sitename' => 'Biodiversity Fiji',
      'machine_name' => 'biodiversity_fiji',
      'country' => 'fj',
      'language_list' => array('en' => 'en', 'fj' => 'fj', 'hi' => 'hi'),
  );
  $domains['biodiversity_kiribati'] = $defaults + array(
      'subdomain' => 'new-ki.chm-cbd.net',
      'sitename' => 'Biodiversity Kiribati',
      'machine_name' => 'biodiversity_kiribati',
      'country' => 'ki',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_marshall_islands'] = $defaults + array(
      'subdomain' => 'new-mh.chm-cbd.net',
      'sitename' => 'Biodiversity Marshall Islands',
      'machine_name' => 'biodiversity_marshall_islands',
      'country' => 'mh',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_micronesia'] = $defaults + array(
      'subdomain' => 'new-fm.chm-cbd.net',
      'sitename' => 'Biodiversity Micronesia',
      'machine_name' => 'biodiversity_micronesia',
      'country' => 'fm',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_niue'] = $defaults + array(
      'subdomain' => 'new-nu.chm-cbd.net',
      'sitename' => 'Biodiversity Niue',
      'machine_name' => 'biodiversity_niue',
      'country' => 'nu',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_palau'] = $defaults + array(
      'subdomain' => 'new-pw.chm-cbd.net',
      'sitename' => 'Biodiversity Palau',
      'machine_name' => 'biodiversity_palau',
      'country' => 'pw',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_solomon_islands'] = $defaults + array(
      'subdomain' => 'new-sb.chm-cbd.net',
      'sitename' => 'Biodiversity Solomon Islands',
      'machine_name' => 'biodiversity_solomon_islands',
      'country' => 'sb',
      'language_list' => array('en' => 'en', 'pis' => 'pis'),
  );
  $domains['biodiversity_tonga'] = $defaults + array(
      'subdomain' => 'new-to.chm-cbd.net',
      'sitename' => 'Biodiversity Tonga',
      'machine_name' => 'biodiversity_tonga',
      'country' => 'to',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_tuvalu'] = $defaults + array(
      'subdomain' => 'new-tv.chm-cbd.net',
      'sitename' => 'Biodiversity Tuvalu',
      'machine_name' => 'biodiversity_tuvalu',
      'country' => 'tv',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_vanuatu'] = $defaults + array(
      'subdomain' => 'new-vu.chm-cbd.net',
      'sitename' => 'Biodiversity Vanuatu',
      'machine_name' => 'biodiversity_vanuatu',
      'country' => 'vu',
      'language_list' => array('en' => 'en', 'fr' => 'fr', 'bi' => 'bi'),
  );
  $domains['biodiversity_samoa'] = $defaults + array(
      'subdomain' => 'new-ws.chm-cbd.net',
      'sitename' => 'Biodiversity Samoa',
      'machine_name' => 'biodiversity_samoa',
      'country' => 'ws',
      'language_list' => array('en' => 'en'),
  );

  // 'balkan-biodiversity.chm-cbd.net' => 'Balkan Biodiversity'
  $weight = 5;
  module_load_include('inc', 'domain', 'domain.admin');
  foreach ($domains as $machine_name => $domain) {
    if (!empty($domain['valid'])) {
      if (!domain_load_domain_id($machine_name)) {
        drush_log(sprintf('Creating new domain: %s (%s)', $domain['sitename'], $machine_name), 'ok');
        $form_state = array('values' => $domain);
        $form_state['values']['machine_name'] = $machine_name;
        $form_state['values']['weight'] = $weight++;

        drupal_form_submit('domain_form', $form_state);
        $form_errors = form_get_errors();
        if (!empty($form_errors)) {
          var_dump($form_errors);
        }
        // Attach a new 'CHM Site' to each domain
        $node_attributes = array(
          'type' => 'chm_site',
          'title' => $domain['sitename'],
          'status' => 1,
          'uid' => 1,
          'name' => 'chm',
          'language' => 'en',
          'domains' => array(PTKDomain::$CHM_DOMAIN_ID),
          'domain_site' => PTKDomain::$CHM_DOMAIN_ID,
          'field_url' => ['en' => [0 => ['url' => 'https://' . $domain['subdomain']]]],
        );
        $country = PTK::getCountryByCode($domain['country']);
        if (!empty($country)) {
          $node_attributes['field_countries'] = [LANGUAGE_NONE => [0 => ['tid' => $country->tid]]];
        }
        else {
          drush_log('Missing country:' . $domain['country'], 'warn');
        }
        $node = (object)$node_attributes;
        node_object_prepare($node);
        node_save($node);
      }
    }
  }
}
