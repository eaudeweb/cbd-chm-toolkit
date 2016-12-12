<?php
/**
 * @file
 * country_taxonomy.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function country_taxonomy_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-cbd_country_group-description_field'.
  $field_instances['taxonomy_term-cbd_country_group-description_field'] = array(
    'bundle' => 'cbd_country_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'description_field',
    'label' => 'Description',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'taxonomy_term-cbd_country_group-field_cbd_code'.
  $field_instances['taxonomy_term-cbd_country_group-field_cbd_code'] = array(
    'bundle' => 'cbd_country_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cbd_code',
    'label' => 'CBD code',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 10,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-cbd_country_group-name_field'.
  $field_instances['taxonomy_term-cbd_country_group-name_field'] = array(
    'bundle' => 'cbd_country_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-description_field'.
  $field_instances['taxonomy_term-countries-description_field'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'description_field',
    'label' => 'Description',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_cbd_country_group'.
  $field_instances['taxonomy_term-countries-field_cbd_country_group'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cbd_country_group',
    'label' => 'CBD country group',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_cbd_id'.
  $field_instances['taxonomy_term-countries-field_cbd_id'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cbd_id',
    'label' => 'CBD ID',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 10,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_country_cbd_guid'.
  $field_instances['taxonomy_term-countries-field_country_cbd_guid'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_country_cbd_guid',
    'label' => 'CBD GUID',
    'required' => 0,
    'settings' => array(
      'context' => 'title',
      'context_default' => 'sdl_editor_representation',
      'dnd_enabled' => 0,
      'entity_translation_sync' => FALSE,
      'mee_enabled' => 0,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_gef_id'.
  $field_instances['taxonomy_term-countries-field_gef_id'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_gef_id',
    'label' => 'GEF ID',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 10,
      ),
      'type' => 'text_textfield',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_image'.
  $field_instances['taxonomy_term-countries-field_image'] = array(
    'bundle' => 'countries',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'small_flag_icon',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_image',
    'label' => 'Flag',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'entity_translation_sync' => 0,
      'file_directory' => 'images/flags',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'manualcrop_crop_info' => TRUE,
        'manualcrop_default_crop_area' => TRUE,
        'manualcrop_enable' => FALSE,
        'manualcrop_inline_crop' => FALSE,
        'manualcrop_instant_crop' => FALSE,
        'manualcrop_instant_preview' => TRUE,
        'manualcrop_keyboard' => TRUE,
        'manualcrop_maximize_default_crop_area' => FALSE,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => FALSE,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_is_un_country'.
  $field_instances['taxonomy_term-countries-field_is_un_country'] = array(
    'bundle' => 'countries',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'This country is on the list of UN official countries',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_is_un_country',
    'label' => 'Is UN country',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_iso3l_code'.
  $field_instances['taxonomy_term-countries-field_iso3l_code'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_iso3l_code',
    'label' => 'Country ISO 3-letter Code',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 3,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_iso_code'.
  $field_instances['taxonomy_term-countries-field_iso_code'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_iso_code',
    'label' => 'Country ISO 2-letter Code',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 3,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_official_name'.
  $field_instances['taxonomy_term-countries-field_official_name'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_official_name',
    'label' => 'Official name',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_parent_country'.
  $field_instances['taxonomy_term-countries-field_parent_country'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_parent_country',
    'label' => 'Parent country',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-countries-field_protected_planet_id'.
  $field_instances['taxonomy_term-countries-field_protected_planet_id'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'To find this country\'s protected areas on the Protected Planet website (www.protectedplanet.net)',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_protected_planet_id',
    'label' => 'Protected Planet ID',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 10,
      ),
      'type' => 'text_textfield',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_un_number'.
  $field_instances['taxonomy_term-countries-field_un_number'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_un_number',
    'label' => 'UN number',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 10,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-countries-field_un_official_short_name'.
  $field_instances['taxonomy_term-countries-field_un_official_short_name'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_un_official_short_name',
    'label' => 'UN official short name',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-field_un_region'.
  $field_instances['taxonomy_term-countries-field_un_region'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_un_region',
    'label' => 'UN region',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 1,
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'taxonomy_term-countries-name_field'.
  $field_instances['taxonomy_term-countries-name_field'] = array(
    'bundle' => 'countries',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'chm_country' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 1,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'taxonomy_term-un_region-description_field'.
  $field_instances['taxonomy_term-un_region-description_field'] = array(
    'bundle' => 'un_region',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'description_field',
    'label' => 'Description',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-un_region-name_field'.
  $field_instances['taxonomy_term-un_region-name_field'] = array(
    'bundle' => 'un_region',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'name_field',
    'label' => 'Name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => FALSE,
        'page' => FALSE,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('CBD GUID');
  t('CBD ID');
  t('CBD code');
  t('CBD country group');
  t('Country ISO 2-letter Code');
  t('Country ISO 3-letter Code');
  t('Description');
  t('Flag');
  t('GEF ID');
  t('Is UN country');
  t('Name');
  t('Official name');
  t('Parent country');
  t('Protected Planet ID');
  t('This country is on the list of UN official countries');
  t('To find this country\'s protected areas on the Protected Planet website (www.protectedplanet.net)');
  t('UN number');
  t('UN official short name');
  t('UN region');

  return $field_instances;
}
