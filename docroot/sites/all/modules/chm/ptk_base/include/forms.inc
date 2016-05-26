<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ptk_base_form_domain_form_alter(&$form, &$form_state, $form_id) {
  $form['is_default']['#access'] = FALSE;
  $is_new = empty($form['#domain']['domain_id']);
  $countries = PTK::getCountryListAsOptions();
  $form['country'] = [
    '#title' => t('Country'),
    '#description' => t('Designate the country for this CHM portal'),
    '#type' => 'select',
    '#options' => $countries,
    '#empty_option' => t('- Select -'),
    '#default_value' => PTK::variable_realm_get('country', $form['#domain']),
    '#required' => FALSE,
    '#weight' => -10,
  ];
  module_load_include('inc', 'domain_variable_locale', 'domain_variable_locale.variable');
  $languages = PTK::variable_realm_get('language_list', $form['#domain']);
  $languages = !empty($languages) ? array_values($languages) : array();
  if ($is_new && empty($languages)) {
    $languages = array('en');
  }
  if ($is_new) {
    $form['languages'] = [
      '#type' => 'fieldset',
      '#title' => t('List of active languages'),
      '#weight' => 40,
    ];
    $form['languages']['language_list'] = [
      '#title' => t('Select the languages to be available on this website'),
      '#type' => 'checkboxes',
      '#options' => domain_variable_locale_language_list([], []),
      '#default_value' => $languages,
      '#required' => TRUE,
    ];
    $form['ptk'] = [
      '#type' => 'fieldset',
      '#title' => t('Initialize domain content'),
      '#weight' => 50,
    ];
    $form['ptk']['create_main_menu'] = [
      '#type' => 'checkbox',
      '#title' => t('Create main menu & static pages'),
    ];
    $form['ptk']['create_sample_content'] = [
      '#type' => 'checkbox',
      '#title' => t('Create sample content (i.e. project, species etc.)'),
    ];
    $social = PTKForm::socialMediaForm($form, $form_state);
    $form['ptk']['social'] = $social['ptk']['social'];

    $form['weight']['#access'] = FALSE;
    $form['submit']['#weight'] = 100;
    $form['#submit'][] = 'ptk_base_form_domain_form_submit';
    $form['submit']['#value'] = t('Create domain record');
  }
}

function ptk_base_form_domain_form_submit($form, &$form_state) {
  $current = PTK::variable_realm_get('country', $form['#domain']);
  $domain = $form['#domain'];
  if (empty($domain['machine_name'])) {
    $domain['machine_name'] = $form_state['values']['machine_name'];
  }
  $value = $form_state['values']['country'];
  if ($current !== $value) {
    PTK::variable_realm_set('country', $value, $domain);
  }
  cache_clear_all();
  $machine_name = $form_state['values']['machine_name'];
  $domain_id = domain_load_domain_id($machine_name);
  $domain = domain_load($domain_id);
  PTK::initializeCountryDomain($domain, $form_state['values']);
  PTKForm::socialMediaFormSubmit($form, $form_state, $domain);
  cache_clear_all();
}


class PTKForm {

  public static function socialMediaForm($form, $form_state) {
    $ret['ptk']['social'] = [
      '#type' => 'fieldset',
      '#title' => t('Social media'),
    ];
    $ret['ptk']['social']['facebook'] = [
      '#type' => 'textfield',
      '#title' => t('Facebook account'),
      '#default_value' => PTK::variable_realm_get('ptk_social_facebook'),
    ];
    $ret['ptk']['social']['linkedin'] = [
      '#type' => 'textfield',
      '#title' => t('LinkedIn account'),
      '#default_value' => PTK::variable_realm_get('ptk_social_linkedin'),
    ];
    $ret['ptk']['social']['twitter'] = [
      '#type' => 'textfield',
      '#title' => t('Twitter account'),
      '#default_value' => PTK::variable_realm_get('ptk_social_twitter'),
    ];
    $ret['ptk']['social']['youtube'] = [
      '#type' => 'textfield',
      '#title' => t('Youtube account'),
      '#default_value' => PTK::variable_realm_get('ptk_social_youtube'),
    ];
    $ret['ptk']['social']['connect_with_us'] = [
      '#type' => 'textfield',
      '#title' => t('Connect with us'),
      '#default_value' => PTK::variable_realm_get('ptk_social_connect_with_us'),
    ];
    return $ret;
  }

  public static function socialMediaFormSubmit($form, $form_state, $domain) {
    $values = $form_state['values'];
    $frm = self::socialMediaForm($form, $form_state);
    foreach (array_keys($frm['ptk']['social']) as $key) {
      // $form['#tree']
      if (!empty($values['ptk']['social'][$key])) {
        PTK::variable_realm_set('ptk_social_' . $key, $values['ptk']['social'][$key], $domain);
      }
      else if (!empty($values[$key])) {
        PTK::variable_realm_set('ptk_social_' . $key, $values[$key], $domain);
      }
    }
  }
}