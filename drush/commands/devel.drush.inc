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
  if (!drush_confirm('Are you sure you want to devify the current instance?')) {
    return;
  }
  if (module_exists('overlay')) {
    module_disable(['overlay']);
  }
  foreach (domain_domains() as $id => $domain) {
    switch ($id) {
      case 18:
        // Configure the domains
        $domain = domain_load($id);
        $domain['subdomain'] = 'chm7.local.ro';
        $domain['path'] = 'http://chm7.local.ro/';
        $domain['scheme'] = 'http';
        drush_log('Configuring `www` domain: ' . $domain['subdomain'], 'ok');
        domain_save($domain);
        break;
      case 1:
        $domain = domain_load($id);
        $domain['subdomain'] = 'chm7-demo.local.ro';
        $domain['path'] = 'http://demo.chm7.local.ro/';
        $domain['scheme'] = 'http';
        drush_log('Configuring `bioland` domain: ' . $domain['subdomain'], 'ok');
        domain_save($domain);
        break;
      case 2:
        $domain = domain_load($id);
        $domain['subdomain'] = 'chm7-al.local.ro';
        $domain['path'] = 'https://chm7-al.local.ro/';
        $domain['scheme'] = 'http';
        drush_log('Configuring `Albania` domain: ' . $domain['subdomain'], 'ok');
        domain_save($domain);
        break;
      default:
        drush_log('Disabling: ' . $domain['subdomain'], 'ok');
        $domain = domain_load($id);
        $domain['valid'] = 0;
        domain_save($domain);
    }
  }
  //
  if (module_exists('devel')) {
    drush_log('Assign devel access to everyone');
    user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access devel information'));
    user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access devel information'));
  }
  drush_invoke_process('@self', 'sql-sanitize');
}

function _drush_prepare_test() {
  if (module_exists('overlay')) {
    module_disable(['overlay']);
  }

  foreach (domain_domains() as $id => $domain) {
    switch ($id) {
      case 18:
        // Configure the domains
        $domain = domain_load($id);
        $domain['subdomain'] = 'test7.chm-cbd.net';
        $domain['path'] = 'https://test7.chm-cbd.net';
        $domain['scheme'] = 'http';
        drush_log('Configuring `www` domain: ' . $domain['subdomain'], 'ok');
        domain_save($domain);
        break;
      case 1:
        $domain = domain_load($id);
        $domain['subdomain'] = 'test7-demo.chm-cbd.net';
        $domain['path'] = 'https://test7-demo.chm-cbd.net/';
        $domain['scheme'] = 'http';
        drush_log('Configuring `bioland` domain: ' . $domain['subdomain'], 'ok');
        domain_save($domain);
        break;
      case 2:
        $domain = domain_load($id);
        $domain['subdomain'] = 'test7-al.chm-cbd.net';
        $domain['path'] = 'https://test7-al.chm-cbd.net/';
        $domain['scheme'] = 'http';
        drush_log('Configuring `Albania` domain: ' . $domain['subdomain'], 'ok');
        domain_save($domain);
        break;
      default:
        drush_log('Disabling: ' . $domain['subdomain'], 'ok');
        $domain = domain_load($id);
        $domain['valid'] = 0;
        domain_save($domain);
    }
  }
}
