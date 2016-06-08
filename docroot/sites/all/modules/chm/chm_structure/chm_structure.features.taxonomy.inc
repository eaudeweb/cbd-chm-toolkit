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
