<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ptk_base_form_domain_form_alter(&$form, &$form_state, $form_id) {
  PTKForm::domainFormAlter($form, $form_state);
}


class PTKForm {

  public static function domainFormAlter(&$form, &$form_state) {
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
      $form['#submit'][] = array('PTKForm', 'domainFormSubmit');
      $form['#validate'][] = array('PTKForm', 'domainFormValidate');
      $form['submit']['#value'] = t('Create domain record');
    }
  }

  public static function domainFormValidate($form, $form_state) {
    $iso = $form_state['values']['country'];
    if ($iso && $country = PTK::getCountryByCode($form_state['values']['country'])) {
      // Do not allow to set a country without having Protected Planet ID set
      /** @var stdClass $wrapper */
      $wrapper = entity_metadata_wrapper('taxonomy_term', $country);
      $ppid = $wrapper->field_protected_planet_id->value();
      if (empty($ppid)) {
        form_set_error(
          'country',
          t('Cannot use this country because is missing the <b>Protected Planet</b> ID, configure it !here',
            array('!here' => l(t('here'), 'taxonomy/term/' . $country->tid . '/edit', array('attributes' => array('target' => '_blank')))))
          );
      }
    }
  }

  public static function domainFormSubmit($form, $form_state) {
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


  public static function socialMediaForm($form, $form_state) {
    $ret['ptk']['social'] = [
      '#type' => 'fieldset',
      '#title' => t('Social media'),
    ];
    $ret['ptk']['social']['facebook'] = [
      '#type' => 'textfield',
      '#title' => t('Facebook link'),
      '#default_value' => PTK::variable_realm_get('ptk_social_facebook'),
    ];
    $ret['ptk']['social']['linkedin'] = [
      '#type' => 'textfield',
      '#title' => t('LinkedIn link'),
      '#default_value' => PTK::variable_realm_get('ptk_social_linkedin'),
    ];
    $ret['ptk']['social']['twitter'] = [
      '#type' => 'textfield',
      '#title' => t('Twitter link'),
      '#default_value' => PTK::variable_realm_get('ptk_social_twitter'),
    ];
    $ret['ptk']['social']['youtube'] = [
      '#type' => 'textfield',
      '#title' => t('Youtube link'),
      '#default_value' => PTK::variable_realm_get('ptk_social_youtube'),
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