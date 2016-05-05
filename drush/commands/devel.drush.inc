<?php


/**
 * Implements hook_drush_command().
 */
function devel_drush_command() {
  $items = array();

  $items['devify'] = array(
    'description' => 'Configures the current instance for development.',
    'callback' => '_drush_devify',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'options' => array(
      'enable-modules' => 'A comma separated list of modules to enable.',
      'disable-modules' => 'A comma separated list of modules to disable.',
      'delete-variables' => 'A comma separated list of variables to delete.',
      'reset-variables' => 'A comma separated list of variables to reset with ' .
        'the format foo=var,hey=ho.',
    ),
    'examples' => array(
      'drush devify' => 'Uses command default values to set up a database for development.',
      'drush devify --enable-modules=xhprof,devel' => 'Enables XHProf and Devel modules',
      'drush devify --reset-variables=site_mail=local@local.com,file_temporary_path=/tmp'
      => 'Resets site_mail and file_temporary_path variables.',
    ),
  );
  $items['prepare-test'] = array(
    'description' => 'Configures the current instance for testing environment.',
    'callback' => '_drush_prepare_test',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'examples' => array(
      'drush prepare-test' => 'Uses command default values to set up a database for development.',
    ),
  );

  return $items;
}

function _drush_devify() {
  if (module_exists('overlay')) {
    module_disable(['overlay']);
  }

  $domain = domain_load(18);
  $domain['subdomain'] = 'chm7.local.ro';
  $domain['path'] = 'http://chm7.local.ro/';
  $domain['scheme'] = 'http';
  drush_log('Configuring `www` domain: ' . $domain['subdomain'], 'ok');
  domain_save($domain);

  $domain = domain_load(1);
  $domain['subdomain'] = 'chm7-demo.local.ro';
  $domain['path'] = 'http://demo.chm7.local.ro/';
  $domain['scheme'] = 'http';
  drush_log('Configuring `bioland` domain: ' . $domain['subdomain'], 'ok');
  domain_save($domain);

  $domain = domain_load(2);
  $domain['subdomain'] = 'chm7-al.local.ro';
  $domain['path'] = 'https://chm7-al.local.ro/';
  $domain['scheme'] = 'http';
  drush_log('Configuring `Albania` domain: ' . $domain['subdomain'], 'ok');
  domain_save($domain);

  variable_set('environment', 'devel');

  if (module_exists('devel')) {
    drush_log('Assign devel access to everyone');
    user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access devel information'));
    user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access devel information'));
  }
}

function _drush_prepare_test() {
  $domain = domain_load(18);
  $domain['subdomain'] = 'test7.chm-cbd.net';
  $domain['path'] = 'https://test7.chm-cbd.net';
  drush_log('Configuring `www` domain: ' . $domain['subdomain'], 'ok');
  domain_save($domain);

  $domain = domain_load(1);
  $domain['subdomain'] = 'test7-demo.chm-cbd.net';
  $domain['path'] = 'https://test7-demo.chm-cbd.net/';
  drush_log('Configuring `bioland` domain: ' . $domain['subdomain'], 'ok');
  domain_save($domain);

  $domain = domain_load(2);
  $domain['subdomain'] = 'test7-al.chm-cbd.net';
  $domain['path'] = 'https://test7-al.chm-cbd.net/';
  drush_log('Configuring `Albania` domain: ' . $domain['subdomain'], 'ok');
  domain_save($domain);

  variable_set('environment', 'test');
}
