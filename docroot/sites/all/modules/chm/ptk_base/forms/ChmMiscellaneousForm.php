<?php

class ChmMiscellaneousForm{

  static function form($form, $domain) {
    $ret['ptk']['miscellaneous'] = [
      '#type' => 'fieldset',
      '#title' => t('Miscellaneous'),
    ];
    $ret['ptk']['miscellaneous']['ptk_arkive_key'] = [
      '#type' => 'textfield',
      '#title' => t('Arkive key'),
      '#default_value' => PTKDomain::variable_get('ptk_arkive_key', $domain),
    ];

    return $ret;
  }

  static function submit($form, $form_state, $domain) {
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
