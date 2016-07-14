<?php

class ChmSocialMediaForm {

  static function form($form, $domain) {
    $ret['ptk']['social'] = [
      '#type' => 'fieldset',
      '#title' => t('Social media'),
    ];
    $ret['ptk']['social']['ptk_social_facebook'] = [
      '#type' => 'textfield',
      '#title' => t('Facebook link'),
      '#default_value' => PTKDomain::variable_get('ptk_social_facebook', $domain),
    ];
    $ret['ptk']['social']['ptk_social_linkedin'] = [
      '#type' => 'textfield',
      '#title' => t('LinkedIn link'),
      '#default_value' => PTKDomain::variable_get('ptk_social_linkedin', $domain),
    ];
    $ret['ptk']['social']['ptk_social_twitter'] = [
      '#type' => 'textfield',
      '#title' => t('Twitter link'),
      '#default_value' => PTKDomain::variable_get('ptk_social_twitter', $domain),
    ];
    $ret['ptk']['social']['ptk_social_youtube'] = [
      '#type' => 'textfield',
      '#title' => t('Youtube link'),
      '#default_value' => PTKDomain::variable_get('ptk_social_youtube', $domain),
    ];
    return $ret;
  }

  static function submit($form, $form_state, $domain) {
    $values = $form_state['values'];
    $keys = array(
      'ptk_social_facebook',
      'ptk_social_linkedin',
      'ptk_social_twitter',
      'ptk_social_youtube'
    );
    foreach ($keys as $key) {
      $v = isset($values[$key]) ? $values[$key] : NULL;
      PTKDomain::variable_set($key, $v, $domain);
    }
  }
}
