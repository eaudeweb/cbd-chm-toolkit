<?php
/**
 * @file
 * country_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function country_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'cbd_country_group' => array(
      'name' => 'CBD country group',
      'machine_name' => 'cbd_country_group',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'countries' => array(
      'name' => 'Countries',
      'machine_name' => 'countries',
      'description' => 'List of countries',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'un_region' => array(
      'name' => 'UN region',
      'machine_name' => 'un_region',
      'description' => 'The list of UN official regions',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
