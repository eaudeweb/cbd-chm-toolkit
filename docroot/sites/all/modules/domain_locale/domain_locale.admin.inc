<?php

/**
 * @file
 * Provides admin functionality for domain specific language settings
 */

/**
 * The domain language page callback router.
 *
 * @param $domain
 *  The $domain object created by domain_lookup().
 */
function domain_locale($domain) {
  if (!is_array($domain)) {
    return t('Invalid page requested.');
  }
  return drupal_get_form('domain_locale_form', $domain);
}

/**
 * A modified version of locale_languages_overview_form to manage domain language settings.
 *
 * @param string $type
 * @param int $domain_id
 */
function domain_locale_form($form, &$form_state, $domain, $arguments = array()) {
  $form = array();
  drupal_set_title(t('Edit domain languages for !domain', array('!domain' => $domain['subdomain'])));
  $form['domain_id'] = array('#type' => 'value', '#value' => $domain['domain_id']);
  $record_edit_url = 'admin/structure/domain/' . ($domain['domain_id'] == 0 ? '' : 'view/' . $domain['domain_id']);

  $link = l($domain['subdomain'], $record_edit_url);
  $form['domain'] = array(
    '#type' => 'markup',
    '#markup' => t('Enabled languages for !link', array('!link' => filter_xss($link))),
  );

  $languages = language_list('language', TRUE);
  $domain_languages = domain_locale_lookup($domain['domain_id']);
  $default_domain_language = domain_conf_variable_get($domain['domain_id'], 'language_default');
  $default_install_language = language_default('language');
  $domain_default = isset($default_domain_language) ? $default_domain_language : $default_install_language;

  $form['domain_language'] = array(
    '#tree' => TRUE,
  );

  foreach ($languages as $langcode => $language) {

    $form['domain_language'][$langcode] = array(
      '#tree' => TRUE,
    );
    $form['domain_language'][$langcode]['title'] = array(
      '#type' => 'value',
      '#value' => filter_xss_admin($language->name),
    );
    $form['domain_language'][$langcode]['langcode'] = array(
      '#type' => 'value',
      '#value' => filter_xss_admin($langcode),
    );
    $form['domain_language'][$langcode]['enabled'] = array(
      '#type' => 'checkbox',
      '#default_value' => (isset($domain_languages[$langcode]) && $language->enabled == 1),
    );
    $form['domain_language'][$langcode]['weight'] = array(
      '#type' => 'weight',
      '#default_value' => isset($domain_languages[$langcode]) ? $domain_languages[$langcode]['weight'] : 0,
    );
    $form['domain_language'][$langcode]['site_default'] = array(
      '#type' => 'radio',
      '#return_value' => $langcode,
      '#attributes' => ($domain_default == $langcode)
        ? array('checked' => 'checked', 'name' => 'domain_languages[site_default]')
        : array('name' => 'domain_languages[site_default]'),
    );
  }

  $form['submit'] = array('#type' => 'submit', '#value' => t('Save languages'));
  return $form;
}

/**
 * Form theming.
 */
function theme_domain_locale_form($variables) {
  $form = $variables['form'];
  $output = '';

  $redirect = t('Check the enabled box to make the language enabled for the registered domain.');
  $output .= drupal_render($form['domain_help']);
  $output .= '<br /><h3>' . drupal_render($form['domain']) . '</h3>';
  // Edit existing records.
  $elements = element_children($form['domain_language']);
  if (!empty($elements)) {
    $header = array(t('Language'), t('Langcode'), t('Enabled'), t('Weight'), t('Default'));
    $rows = array();
    foreach ($elements as $element) {
      $rows[] = array(
        $form['domain_language'][$element]['title']['#value'],
        $form['domain_language'][$element]['langcode']['#value'],
        drupal_render($form['domain_language'][$element]['enabled']),
        drupal_render($form['domain_language'][$element]['weight']),
        drupal_render($form['domain_language'][$element]['site_default']),
      );
    }
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
    $output .= '<p><em>' . $redirect . '</em></p>';
  }
  else {
    $output .= '<p>' . t('There are no languages available for this domain.') . '</p>';
  }

  $output .= drupal_render_children($form);
  return $output;
}

/**
 * FormsAPI submit handler for domain language settings
 */
function domain_locale_form_submit($form, &$form_state) {
  $domain_id = $form_state['values']['domain_id'];
  $check = domain_locale_lookup($domain_id);
  if (is_array($check) && count($check) >=1) {
    domain_locale_delete_domain($domain_id);
  }
  $default = $form_state['input']['domain_languages']['site_default'];

  //Construct the array for inserts and updates. Looping over existing languages list.
  $params = array();

  foreach ($form_state['input']['domain_language'] as $langcode => $values) {
    if (!$values['enabled'] && $default != $langcode)
      continue;

    $params[$langcode] = array(
      'language' => $langcode,
      'weight' => $values['weight']
    );
  }

  domain_locale_insert_domain($domain_id, $params);

  //Update domain_conf language_default variable
  domain_conf_variable_set($domain_id, 'language_default', $default);

  // Changing the language settings impacts the interface.
  cache_clear_all('*', 'cache_page', TRUE);
  drupal_set_message(t('Updated domain specific language settings.'));
  // Return to the correct page.
  $form_state['redirect'] = 'admin/structure/domain/view/' . $domain_id . '/language';
}


/**
 * Resets locale settings by setting them to default domain settings in {domain_locale}.
 *
 * @param $domain
 * The $domain object created by domain_lookup().
 * @return
 * A confirmation form.
 */
function domain_locale_reset($domain) {
  if ($domain == -1) {
    return t('An invalid request has been made.');
  }
  return drupal_get_form('domain_locale_reset_form', $domain);
}

/**
 * FormsAPI for resetting domain languages.
 *
 * @param $domain
 * The $domain object for the selected domain.
 * @return
 * Themed HTML form.
 */
function domain_locale_reset_form($form, $form_state, $domain) {
  $extra['domain_id'] = array(
    '#type' => 'value',
    '#value' => isset($domain['domain_id']) ? $domain['domain_id'] : NULL,
  );
  $form = confirm_form($extra,
    t('Are you sure you wish to reset languages for %name?', array('%name' => $domain['sitename'])),
    'admin/build/domain/language/' . $domain['domain_id'],
    t('Submitting this form will apply default domain languages for this domain.'));
  return $form;
}

/**
 * FormsAPI for domain_locale_reset_form.
 */
function domain_locale_reset_form_submit($form, &$form_state) {
  domain_locale_delete_domain($form_state['values']['domain_id']);
  domain_locale_restore_default($form_state['values']['domain_id']);
  drupal_set_message(t('Domain language settings have been reset to default domain settings.'));
  $form_state['redirect'] = 'admin/build/domain/view/' . $form_state['values']['domain_id'] . '/language';
}

/**
 * Theme a message at the top of domain locale pages.
 *
 * @param $domain
 * The $domain object for the selected domain.
 * @return
 * Themed HTML messages.
 */
function theme_domain_locale_reset($domain) {
  $output = '';
  $output .= '<p>' . t('These settings will replace your default site language settings when %name is the active domain.', array('%name' => $domain['sitename'])) . '</p>';
  $data = db_query("SELECT language FROM {domain_locale} WHERE domain_id = :did", array(':did' => $domain['domain_id']));

  if (!empty($data)) {
    $output .= '<p>' . t('You may <a href="!url">erase these settings</a> to restore the default behavior.', array('!url' => url('admin/build/domain/language-reset/' . $domain['domain_id']))) . '</p>';
  }
  return $output;
}
