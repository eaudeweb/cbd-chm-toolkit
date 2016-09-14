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
  module_enable(['devel']);
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
    _drush_prepare_test_domains($domain);
    drush_log('Configuring ' . $domain['scheme'] . '://' . $domain['subdomain'], 'ok');
    domain_save($domain);
  }

  //@todo: Create other new-* test domains
}


function _drush_prepare_test_domains(&$domain) {
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
