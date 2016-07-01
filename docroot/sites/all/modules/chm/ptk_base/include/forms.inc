<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ptk_base_form_domain_form_alter(&$form, &$form_state, $form_id) {
  PTKForm::domainFormAlter($form, $form_state);
}

/**
 * Implements hook_form_alter().
 * @inheritdoc
 */
function ptk_base_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'views_exposed_form' && $form['#id'] == 'views-exposed-form-admin-views-node-system-1') {
    PTKForm::adminContentFormAlter($form, $form_state);
  }
  PTKFormDocumentTypeField::alter($form);
}


/**
 * Class PTKFormDocumentTypeField for alters the field_document_type to show
 * only the active terms
 */
class PTKFormDocumentTypeField {

  static function alter(&$form) {
    if (isset($form['field_document_type'])) {
      $allowed = db_select('field_data_field_in_use', 'a')
        ->fields('a', array('entity_id'))
        ->condition('entity_type', 'taxonomy_term')
        ->condition('bundle', 'document_type')
        ->condition('deleted', 0)->execute()->fetchCol();
      $options = array();
      foreach ($form['field_document_type'][LANGUAGE_NONE]['#options'] as $k => $v) {
        if (in_array($k, $allowed) || $k == '_none') {
          $options[$k] = $v;
        }
      }
      $form['field_document_type'][LANGUAGE_NONE]['#options'] = $options;
    }
  }

}

class PTKForm {

  public static function adminContentFormAlter(&$form, $form_state) {
    if (!empty($form['sitename'])) {
      $domains = domain_domains();
      $options = array('' => t('-- All sites --'));
      foreach ($domains as $domain) {
        $options[$domain['sitename']] = $domain['sitename'];
      }
      $form['sitename']['#type'] = 'select';
      $form['sitename']['#options'] = $options;
      $form['sitename']['#default_value'] = '';
      unset($form['sitename']['#size']);
    }
  }

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
      $form['submit']['#value'] = t('Create domain record');
    }
    $form['#is_new'] = $is_new;
    $form['#submit'][] = array('PTKForm', 'domainFormSubmit');
    $form['#validate'][] = array('PTKForm', 'domainFormValidate');
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
    if (!empty($form['#is_new'])) {
      $machine_name = $form_state['values']['machine_name'];
      $domain_id = domain_load_domain_id($machine_name);
      $domain = domain_load($domain_id);
      PTK::initializeCountryDomain($domain, $form_state['values']);
      PTKForm::socialMediaFormSubmit($form, $form_state, $domain);
      cache_clear_all();
    }
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