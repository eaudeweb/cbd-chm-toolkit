<?php
/**
 * @file
 * chm_structure.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function chm_structure_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_date_month_year';
  $strongarm->value = 'd M Y';
  $export['date_format_date_month_year'] = $strongarm;

  return $export;
}
