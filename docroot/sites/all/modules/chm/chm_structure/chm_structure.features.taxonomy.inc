<?php
/**
 * @file
 * chm_structure.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function chm_structure_taxonomy_default_vocabularies() {
  return array(
    'event_status' => array(
      'name' => 'Event status',
      'machine_name' => 'event_status',
      'description' => 'Status of an event (postponed, cancelled etc.)',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'taxonomy_nfp_type' => array(
      'name' => 'National Focal Point Type',
      'machine_name' => 'taxonomy_nfp_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
