<?php

class ChmMiscellaneousForm {

  static function form($form, $domain) {
    if (empty($form['#domain'])) {
      $form['#domain'] = $domain;
    }
    $form['ptk']['miscellaneous'] = [
      '#type' => 'fieldset',
      '#title' => t('Miscellaneous'),
    ];
    $form['ptk']['miscellaneous']['ptk_arkive_key'] = [
      '#type' => 'textfield',
      '#title' => t('Arkive key'),
      '#default_value' => PTKDomain::variable_get('ptk_arkive_key', $domain),
    ];
    $form['#submit'][] = array('ChmMiscellaneousForm', 'submit');
    return $form;
  }

  static function submit($form, $form_state) {
    $domain = $form['#domain'];
    // New domains
    if (empty($domain['domain_id'])) {
      $domain = $form_state['values'];
    }
    if (empty($domain['domain_id'])) {
      drupal_set_message('Cannot miscellaneous settings, please contact technical support and describe your action', 'error');
      return;
    }
    $values = $form_state['values'];
    $keys = array(
      'ptk_arkive_key',
    );
    foreach ($keys as $key) {
      $v = isset($values[$key]) ? $values[$key] : NULL;
      PTKDomain::variable_set($key, $v, $domain);
    }
  }
}
