<?php

class ChmSocialMediaForm {

  static function form($form) {
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

  static function submit($form, $form_state, $domain) {
    $values = $form_state['values'];
    $frm = self::form($form);
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