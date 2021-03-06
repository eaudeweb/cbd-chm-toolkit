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

function _drush_devel_update_solr_path() {
  if (module_exists('search_api')) {
    $entity_type = 'search_api_server';
    $servers = entity_load($entity_type, false);
    foreach($servers as $server) {
      if ($server->class == 'search_api_solr_service') {
        $options_path = trim($server->options['path']);
        if (substr($options_path, -5) == '-prod') {
          $server->options['path'] = str_replace('-prod', '-test', $options_path);
          entity_save($entity_type, $server);
          $msg = t('Updating Solr server path from !from to !to', array('!from' => $options_path, '!to' => $server->options['path']));
          drupal_set_message($msg);
          drush_log($msg, 'ok');
        }
      }
    }
  }
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
  _drush_prepare_development_domains($domain);
  if (module_exists('devel')) {
    drush_log('Assign devel access to everyone');
    user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access devel information'));
    user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access devel information'));
  }
  variable_set('eu_cookie_compliance_domain', 'local.ro');
  variable_set('error_level', '2');
  _drush_devel_update_solr_path();
  variable_set('page_compression', 0);
  variable_set('preprocess_css', 0);
  variable_set('preprocess_js', 0);
  drush_invoke_process('@self', 'sql-sanitize');
}


function _drush_prepare_development_domains(&$domain) {
  foreach (domain_domains() as $id => $domain) {
    $domain = domain_load($id);
    $domain['scheme'] = 'http';
    if ($id == 1) { // www
      $domain['subdomain'] = 'chm7.local.ro';
      $domain['path'] = 'http://chm7.local.ro/';
    }
    else if ($id == 3) { // demo
      $domain['subdomain'] = 'chm7-demo.local.ro';
      $domain['path'] = 'http://chm7-demo.local.ro/';
    }
    else {
      $domain['subdomain'] = str_replace('.chm-cbd.net', '.local.ro', $domain['subdomain']);
      $domain['path'] = str_replace('.chm-cbd.net', '.local.ro', $domain['path']);
      if (strpos($domain['subdomain'], 'test-') !== FALSE) {
        $domain['subdomain'] = str_replace('test-', '', $domain['subdomain']);
        $domain['path'] = str_replace('test-', '', $domain['path']);
      }
      if ($country = PTKDomain::getPortalCountry($domain)) {
        $code = entity_metadata_wrapper('taxonomy_term', $country)->field_iso_code->value();
        $code = strtolower($code);
        $domain['subdomain'] = "chm7-{$code}.local.ro";
        $domain['path'] = "http://chm7-{$code}.local.ro";
      }
      else {
        $domain['subdomain'] = 'chm7-' . $domain['subdomain'];
        $domain['path'] = str_replace('https://', 'http://chm7-', $domain['path']);
      }
    }
    drush_log('Configuring ' . $domain['path'] . ' (' . $domain['subdomain'] . ')', 'ok');
    domain_save($domain);
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
  _drush_devel_update_solr_path();
  // Fix existing domains
  foreach (domain_domains() as $id => $domain) {
    $domain = domain_load($id);
    $domain['scheme'] = 'http';
    if ($id == 1) { // www
      $domain['subdomain'] = 'test-www.chm-cbd.net';
      $domain['path'] = 'http://test-www.chm-cbd.net/';
    }
    else if ($id == 3) { // demo
      $domain['subdomain'] = 'test-demo.chm-cbd.net';
      $domain['path'] = 'http://test-demo.chm-cbd.net/';
    }
    else {
      $domain['subdomain'] = str_replace('new-', 'test-', $domain['subdomain']);
      $domain['path'] = str_replace('new-', 'test-', $domain['path']);

      // Force country assigned domain to predictible DNS name
      if ($country = PTKDomain::getPortalCountry($domain)) {
        $code = entity_metadata_wrapper('taxonomy_term', $country)->field_iso_code->value();
        $code = strtolower($code);
        $domain['subdomain'] = "test-{$code}.chm-cbd.net";
        $domain['path'] = "http://test-{$code}.chm-cbd.net";
      }
    }
    drush_log('Configuring ' . $domain['path'] . ' (' . $domain['subdomain'] . ')', 'ok');
    domain_save($domain);
  }
  // Create new domains
  _drush_chm_create_test_domains();
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
      'subdomain' => 'test-am.chm-cbd.net',
      'sitename' => 'Biodiversity Armenia',
      'country' => 'am',
      'language_list' => array('en' => 'en', 'hy' => 'hy'),
  );
  $domains['biodiversity_azerbaijan'] = $defaults + array(
      'subdomain' => 'test-az.chm-cbd.net',
      'sitename' => 'Biodiversity Azerbaijan',
      'machine_name' => 'biodiversity_azerbaijan',
      'country' => 'az',
      'language_list' => array('en' => 'en', 'az' => 'az'),
  );
  $domains['biodiversity_bosnia_herzegovina'] = $defaults + array(
      'subdomain' => 'test-ba.chm-cbd.net',
      'sitename' => 'Biodiversity Bosnia & Herzegovina',
      'machine_name' => 'biodiversity_bosnia_herzegovina',
      'country' => 'ba',
      'language_list' => array('en' => 'en', 'bs' => 'bs'),
  );
  $domains['biodiversity_bulgaria'] = $defaults + array(
      'subdomain' => 'test-bg.chm-cbd.net',
      'sitename' => 'Biodiversity Bulgaria',
      'machine_name' => 'biodiversity_bulgaria',
      'country' => 'bg',
      'language_list' => array('en' => 'en', 'bg' => 'bg'),
  );
  $domains['biodiversity_kyrgyzstan'] = $defaults + array(
      'subdomain' => 'test-kg.chm-cbd.net',
      'sitename' => 'Biodiversity Kyrgyzstan',
      'machine_name' => 'biodiversity_kyrgyzstan',
      'country' => 'kg',
      'language_list' => array('en' => 'en', 'ru' => 'ru', 'ky' => 'ky'),
  );
  $domains['biodiversity_serbia'] = $defaults + array(
      'subdomain' => 'test-rs.chm-cbd.net',
      'sitename' => 'Biodiversity Serbia',
      'machine_name' => 'biodiversity_serbia',
      'country' => 'rs',
      'language_list' => array('en' => 'en', 'sr' => 'sr'),
  );
  $domains['biodiversity_tajikistan'] = $defaults + array(
      'subdomain' => 'test-tj.chm-cbd.net',
      'sitename' => 'Biodiversity Tajikistan',
      'machine_name' => 'biodiversity_tajikistan',
      'country' => 'tj',
      'language_list' => array('en' => 'en', 'ru' => 'ru', 'tg' => 'tg'),
  );
  $domains['biodiversity_turkmenistan'] = $defaults + array(
      'subdomain' => 'test-tm.chm-cbd.net',
      'sitename' => 'Biodiversity Turkmenistan',
      'machine_name' => 'biodiversity_turkmenistan',
      'country' => 'tm',
      'language_list' => array('en' => 'en', 'ru' => 'ru', 'tk' => 'tk'),
  );
  $domains['biodiversity_ukraine'] = $defaults + array(
      'subdomain' => 'test-ua.chm-cbd.net',
      'sitename' => 'Biodiversity Ukraine',
      'machine_name' => 'biodiversity_ukraine',
      'country' => 'ua',
      'language_list' => array('en' => 'en', 'uk' => 'uk'),
  );
  $domains['biodiversity_fiji'] = $defaults + array(
      'subdomain' => 'test-fj.chm-cbd.net',
      'sitename' => 'Biodiversity Fiji',
      'machine_name' => 'biodiversity_fiji',
      'country' => 'fj',
      'language_list' => array('en' => 'en', 'fj' => 'fj', 'hi' => 'hi'),
  );
  $domains['biodiversity_marshall_islands'] = $defaults + array(
      'subdomain' => 'test-mh.chm-cbd.net',
      'sitename' => 'Biodiversity Marshall Islands',
      'machine_name' => 'biodiversity_marshall_islands',
      'country' => 'mh',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_micronesia'] = $defaults + array(
      'subdomain' => 'test-fm.chm-cbd.net',
      'sitename' => 'Biodiversity Micronesia',
      'machine_name' => 'biodiversity_micronesia',
      'country' => 'fm',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_niue'] = $defaults + array(
      'subdomain' => 'test-nu.chm-cbd.net',
      'sitename' => 'Biodiversity Niue',
      'machine_name' => 'biodiversity_niue',
      'country' => 'nu',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_palau'] = $defaults + array(
      'subdomain' => 'test-pw.chm-cbd.net',
      'sitename' => 'Biodiversity Palau',
      'machine_name' => 'biodiversity_palau',
      'country' => 'pw',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_solomon_islands'] = $defaults + array(
      'subdomain' => 'test-sb.chm-cbd.net',
      'sitename' => 'Biodiversity Solomon Islands',
      'machine_name' => 'biodiversity_solomon_islands',
      'country' => 'sb',
      'language_list' => array('en' => 'en', 'pis' => 'pis'),
  );
  $domains['biodiversity_tonga'] = $defaults + array(
      'subdomain' => 'test-to.chm-cbd.net',
      'sitename' => 'Biodiversity Tonga',
      'machine_name' => 'biodiversity_tonga',
      'country' => 'to',
      'language_list' => array('en' => 'en'),
  );
  $domains['biodiversity_vanuatu'] = $defaults + array(
      'subdomain' => 'test-vu.chm-cbd.net',
      'sitename' => 'Biodiversity Vanuatu',
      'machine_name' => 'biodiversity_vanuatu',
      'country' => 'vu',
      'language_list' => array('en' => 'en', 'fr' => 'fr', 'bi' => 'bi'),
  );
  $domains['biodiversity_samoa'] = $defaults + array(
      'subdomain' => 'test-ws.chm-cbd.net',
      'sitename' => 'Biodiversity Samoa',
      'machine_name' => 'biodiversity_samoa',
      'country' => 'ws',
      'language_list' => array('en' => 'en'),
  );
  // 'balkan-biodiversity.chm-cbd.net' => 'Balkan Biodiversity'
  $weight = 5;
  module_load_include('inc', 'domain', 'domain.admin');
  foreach ($domains as $machine_name => $domain) {
    // @warning Make sure machine name is limited to 27 characters
    if (strlen($machine_name) > 27) {
      $original = $machine_name;
      $machine_name = substr($machine_name, 0, 27);
      drush_log(sprintf('Adjusting machine name from %s to %s', $original, $machine_name, 'warning'));
    }
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
