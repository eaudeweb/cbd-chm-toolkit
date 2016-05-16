<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ptk_base_form_domain_form_alter(&$form, &$form_state, $form_id) {
  $countries = PTK::getCountryListAsOptions();
  $form['country'] = [
    '#title' => t('Country'),
    '#description' => t('Designate the country for this CHM portal'),
    '#type' => 'select',
    '#options' => $countries,
    '#default_value' => PTK::variable_realm_get('country', $form['#domain']),
    '#required' => TRUE,
    '#weight' => -10,
  ];
  $form['#submit'][] = 'ptk_base_form_domain_form_submit';
}

function ptk_base_form_domain_form_submit($form, &$form_state) {
  $current = PTK::variable_realm_get('country', $form['#domain']);
  $value = $form_state['values']['country'];
  $domain = $form['#domain'];
  if (empty($domain['machine_name'])) {
    $domain['machine_name'] = $form_state['values']['machine_name'];
  }
  if ($current !== $value) {
    PTK::variable_realm_set('country', $value, $domain);
  }
}
