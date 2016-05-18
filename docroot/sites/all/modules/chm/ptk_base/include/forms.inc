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
  if ($current !== $value) {
    PTK::variable_realm_set('country', $value, $domain);
  }
}

function ptk_base_domain_content_config_form($form, &$form_state, $domain) {
  $realm_key = _domain_variable_realm_key($domain);
  $countries = PTK::getCountryListAsOptions();
  return [
    'domain' => [
      '#type' => 'value',
      '#value' => $domain,
    ],
    'country' => [
      '#title' => t('Country'),
      '#type' => 'select',
      '#options' => $countries,
      '#default_value' => PTK::variable_realm_get('country', $domain),
      '#required' => TRUE,
    ],
    'create_main_menu' => [
      '#type' => 'checkbox',
      '#title' => t('Create main menu & basic pages'),
    ],
    'create_sample_content' => [
      '#type' => 'checkbox',
      '#title' => t('Create sample content'),
    ],
    'submit' => [
      '#type' => 'submit',
      '#value' => t('Submit'),
      '#submit' => ['ptk_base_domain_content_config_form_submit'],
    ],
  ];
}

function ptk_base_domain_content_config_form_submit($form, &$form_state) {
  $success = PTK::initializeCountryDomain($form_state['values']);
  if (!$success) {
    drupal_set_message('An error occurred.', 'error');
  }
  else {
    drupal_set_message('Succesfully populated domain.');
  }
}