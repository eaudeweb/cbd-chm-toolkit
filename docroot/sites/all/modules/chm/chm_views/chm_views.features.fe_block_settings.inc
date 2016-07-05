<?php
/**
 * @file
 * chm_views.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function chm_views_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-home_page_image_slider-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'home_page_image_slider-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'chm_theme_kit' => array(
        'region' => 'main_top',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
