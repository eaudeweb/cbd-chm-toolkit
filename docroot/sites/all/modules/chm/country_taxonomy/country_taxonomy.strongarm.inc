<?php
/**
 * @file
 * country_taxonomy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function country_taxonomy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_countries_pattern';
  $strongarm->value = 'countries/[term:name]';
  $export['pathauto_taxonomy_term_countries_pattern'] = $strongarm;

  return $export;
}
