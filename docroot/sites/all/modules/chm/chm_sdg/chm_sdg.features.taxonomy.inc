<?php
/**
 * @file
 * chm_sdg.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function chm_sdg_taxonomy_default_vocabularies() {
  return array(
    'sdg' => array(
      'name' => 'Sustainable Development Goals',
      'machine_name' => 'sdg',
      'description' => 'The list of 17 sustainable development goals',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
