<?php


/**
 * Configuration form.
 */
function iucn_redlist_config_form($form, $form_state) {
  $form = array(
    'iucnredlist_url' => array(
      '#type' => 'textfield',
      '#title' => t('IUCN Redlist WS base URL'),
      '#default_value' => variable_get('cms_iucnredlist_url', 'http://apiv3.iucnredlist.org/api/v3'),
    ),
    'iucnredlist_apikey' => array(
      '#type' => 'textfield',
      '#title' => t('IUCN Redlist v3 API key'),
      '#description' => t('Please visit <a href="http://apiv3.iucnredlist.org/api/v3/token" target="_blank">this page</a> to generate a valid token for API access'),
      '#default_value' => variable_get('iucnredlist_apikey', '9bb4facb6d23f48efbf424bb05c0c1ef1cf6f468393bc745d42179ac4aca5fee'),
    ),
    'iucnredlist_calldelay' => array(
      '#type' => 'textfield',
      '#title' => t('Delay between repetitive API calls (milliseconds)'),
      '#size' => 10,
      '#description' => t('If the delay is too small, the service migh temporarily or permanently block API calls'),
      '#default_value' => variable_get('iucnredlist_calldelay', '500'),
    )
  );
  return system_settings_form($form);
}
