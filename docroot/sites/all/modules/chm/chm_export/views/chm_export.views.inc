<?php
/**
 * @file
 * Views style plugin to render nodes in the JSON data format.
 *
 * @see views_plugin_style_json.inc
 * @ingroup views_plugins
 */

/**
 * Implements hook_views_plugins().
 */
function chm_export_views_plugins() {
  $formats = chm_export_views_formats();
  $additional_themes = array();
  foreach ($formats as $format => $description) {
    $additional_themes['views_chm_export_style_' . $format] = 'style';
  }

  $path = drupal_get_path('module', 'chm_export') . '/views';
  return array(
    'module' => 'chm_export',
    'style' => array(
      'chm_export' => array(
        'title' => t('CHM export'),
        'path' => $path . '/plugins',
        'help' => t('Displays entities in the JSON data format.'),
        'handler' => 'views_plugin_style_chm_export',
        'theme' => 'views_chm_export_style',
        'theme file' => 'views_chm_export_style.theme.inc',
        'theme path' => $path . '/theme',
        'additional themes' => $additional_themes,
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'help_topic' => 'style-json',
        'even empty' => TRUE,
      ),
    ),
  );
}

/*
 * All recognised JSON output formats
 */
function chm_export_views_formats() {
  return module_invoke_all('chm_export_formats');
}

function chm_export_chm_export_formats() {
  $formats = array(
    'simple' => t('Simple'),
  );
  return $formats;
}
