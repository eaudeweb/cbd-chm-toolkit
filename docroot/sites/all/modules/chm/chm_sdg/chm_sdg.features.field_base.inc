<?php
/**
 * @file
 * chm_sdg.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function chm_sdg_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_index'.
  $field_bases['field_index'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_index',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
