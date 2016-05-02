<?php


/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function ptk_base_form_variable_realm_edit_variables_form_alter(&$form, &$form_state) {
  $countries = PTK::getCountryListAsOptions();
  $realm_name = $form_state['build_info']['args'][0];
  $realm_key = $form_state['build_info']['args'][1];
  $form['variables']['regional_settings']['country'] = [
    '#title' => t('Country'),
    '#description' => t('Designate the country for this CHM portal'),
    '#type' => 'select',
    '#options' => $countries,
    '#default_value' => variable_realm_get($realm_name, $realm_key, 'country'),
    '#weight' => -10,
  ];
}
