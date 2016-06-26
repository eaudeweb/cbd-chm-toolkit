<?php
/**
 * @file
 * chm_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function chm_structure_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function chm_structure_node_info() {
  $items = array(
    'cbd_nfp' => array(
      'name' => t('CBD National Focal Point'),
      'base' => 'node_content',
      'description' => t('CBD National Focal Point automatically imported from the CBD REST API'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('Simple content page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
