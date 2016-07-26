<?php


/**
 * Implements hook_variable_group_info().
 */
function ptk_base_variable_group_info() {
  $groups = array();
  $groups['social_media'] = array(
    'title' => t('Social Media'),
    'description' => t('Social media information'),
    'access' => 'configure chm website settings',
  );
  $groups['advanced'] = array(
    'title' => t('System configuration'),
    'description' => t('Advanced site functional configuration'),
    'access' => 'configure chm website settings',
  );
  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function ptk_base_variable_info($options) {
  $variables = array();
  $variables['ptk_social_facebook'] = array(
    'title' => t('Facebook link'),
    'group' => 'social_media',
    'type' => 'string',
    'multidomain' => TRUE,
    'description' => t('Link to Facebook account')
  );
  $variables['ptk_social_linkedin'] = array(
    'title' => t('LinkedIn link'),
    'group' => 'social_media',
    'type' => 'string',
    'multidomain' => TRUE,
    'description' => t('Link to LinkedIn account')
  );
  $variables['ptk_social_twitter'] = array(
    'title' => t('Twitter link'),
    'group' => 'social_media',
    'type' => 'string',
    'multidomain' => TRUE,
    'description' => t('Link to Twitter account')
  );
  $variables['ptk_social_youtube'] = array(
    'title' => t('Youtube link'),
    'group' => 'social_media',
    'type' => 'string',
    'multidomain' => TRUE,
    'description' => t('Link to Youtube account')
  );
  $variables['ptk_arkive_key'] = array(
    'title' => t('Arkive API key'),
    'group' => 'advanced',
    'type' => 'string',
    'multidomain' => TRUE,
    'description' => t('Visit the <a href="!url" target="_blank">Arkive.org</a> website to get your API access key', array('!url' => 'https://www.arkive.org/api/docs'))
  );
  return $variables;
}