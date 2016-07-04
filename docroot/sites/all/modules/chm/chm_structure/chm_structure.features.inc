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
    'document' => array(
      'name' => t('Document'),
      'base' => 'node_content',
      'description' => t('Use a Document to describe a publication or any other relevant document on biodiversity in your country.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'ecosystem' => array(
      'name' => t('Ecosystem'),
      'base' => 'node_content',
      'description' => t('Use an ecosystem to briefly describe a major ecosystem of your country.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use an <i>event</i> to describe a biodiversity-related event (meeting, workshop, conference, etc.) in your country.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'fact' => array(
      'name' => t('Biodiversity fact'),
      'base' => 'node_content',
      'description' => t('Use a biodiversity fact to describe a particular fact related to biodiversity in your country.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('Use <i>news</i> for time-sensitive content like news, press releases, alerts etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('Use <i>page</i> for the static content of your national CHM website, such as the <b>About Us</b> page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
