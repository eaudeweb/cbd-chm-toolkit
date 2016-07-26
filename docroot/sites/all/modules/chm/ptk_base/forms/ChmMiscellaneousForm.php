<?php

class ChmMiscellaneousForm {

  static function form($domain, &$form = NULL) {
    $ret = array();
    $ret['ptk']['miscellaneous'] = [
      '#type' => 'fieldset',
      '#title' => t('Miscellaneous'),
    ];
    $ret['ptk']['miscellaneous']['ptk_arkive_key'] = [
      '#tree' => FALSE,
      '#type' => 'textfield',
      '#title' => t('Arkive key'),
      '#default_value' => PTKDomain::variable_get('ptk_arkive_key', $domain),
      '#description' => t('Visit the <a href="!url" target="_blank">Arkive.org</a> website to get your API access key', array('!url' => 'https://www.arkive.org/api/docs'))
    ];
    if ($form) {
      $form['#submit'][] = array('ChmMiscellaneousForm', 'submit');
    }
    $ret['#submit'][] = array('ChmMiscellaneousForm', 'submit');
    return $ret;
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
