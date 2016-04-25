<?php

/**
 * @file
 * Drush commands for Domain Locale.
 */

/**
 * Implements hook_drush_command().
 */
function domain_locale_drush_command() {
  $items = array();
  $items['domain-locale-set'] = array(
    'description' => 'Add specific language settings to a site.',
    'examples' => array(
      'drush domain-locale-set example.com \'de\'',
      'drush domain-locale-set example.com \'de fr\' --weight=-1 --default=fr',
    ),
    'arguments' => array(
      'domain' => 'The domain to register (e.g. example.com).',
      'languages' => 'The prefixes of the languages to enable for this site (e.g. \'en\', \'en de\', ...).',
    ),
    'options' => array(
      'default' => 'The prefix of the default language for this domain.',
    ),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function domain_locale_drush_help($section) {
  $items = domain_locale_drush_command();
  $name = $sectionpscp;
  if (isset($items[$name])) {
    return dt($items[$name]['description']);
  }
}

/**
 * Add a language to a site.
 *
 * @param $subdomain
 *   The domain name to register.
 * @param $lang_prefixes
 *   The prefixes of the languages to enable
 *
 * @return
 *   Void if OK, or an error message.
 */
function drush_domain_locale_set($subdomain = NULL, $lang_prefixes = NULL) {
  if (is_null($subdomain)) {
    return drush_set_error('domain_locale', dt('You must specify a domain machine name.'));
  }
  if (is_null($lang_prefixes)) {
    return drush_set_error('domain_locale', dt('You must specify at least one language.'));
  }
  // Validate subdomain, get domain_id.
  $machine_name = domain_machine_name($subdomain);
  $domain = domain_machine_name_load($machine_name);
  if (!$domain) {
    return drush_set_error('domain_locale', dt("Domain @subdomain not found.", array(
      '@subdomain' => $subdomain,
    )));
  }
  $domain_id = $domain['domain_id'];

  // Get and validate languages for the domain.
  $langs = explode(" ", $lang_prefixes);
  $available_languages = language_list();
  foreach ($langs as $lang) {
    if (! isset($available_languages[$lang])) {
      return drush_set_error('domain_locale', dt("Language @language not available.", array(
        '@language' => $lang,
      )));
    }
  }

  // Get and validate default language.
  $default = (drush_get_option('default')) ? drush_get_option('default') : NULL;
  if ($default && !in_array($default, $langs)) {
    return drush_set_error('domain_locale', dt("Default language '@language' must be present in 'languages' parameter.", array(
      '@language' => $default,
    )));
  }
  if (!$default && count($langs) == 1) {
    $default = $lang;
    drush_log(dt("Default language for @subdomain automatically set as '@lang'.", array(
      '@subdomain' => $subdomain,
      '@lang'      => $lang,
    )), 'ok');
  }

  // Update db
  $params = array();
  foreach ($langs as $lang) {
    $params[] = array('language' => $lang);
  }
  domain_locale_delete_domain($domain_id);
  domain_locale_insert_domain($domain_id, $params);

  if ($default) {
    domain_conf_variable_set($domain_id, 'language_default', $default);
  }

  // Clear cache.
  cache_clear_all('*', 'cache_page', TRUE);

  drush_log(dt("Locale settings updated for @subdomain", array(
    '@subdomain' => $subdomain,
  )), 'ok');
}
