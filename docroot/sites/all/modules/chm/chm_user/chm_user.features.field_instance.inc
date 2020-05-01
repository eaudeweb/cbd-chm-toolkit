<?php
/**
 * @file
 * chm_user.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function chm_user_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_register_domain'.
  $field_instances['user-user-field_register_domain'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Domain used during registration
',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_register_domain',
    'label' => 'Register domain',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Domain used during registration
');
  t('Register domain');

  return $field_instances;
}
