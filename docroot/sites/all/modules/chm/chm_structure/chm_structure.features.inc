<?php
/**
 * @file
 * chm_structure.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function chm_structure_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "slick" && $api == "slick_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function chm_structure_image_default_styles() {
  $styles = array();

  // Exported image style: extra_large.
  $styles['extra_large'] = array(
    'label' => 'Extra Large (1280X720)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1280,
          'height' => 720,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: header_flag.
  $styles['header_flag'] = array(
    'label' => 'Header flag',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 65,
          'height' => 45,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image_listing.
  $styles['image_listing'] = array(
    'label' => 'Image listing',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 360,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function chm_structure_node_info() {
  $items = array(
    'cbd_national_target' => array(
      'name' => t('CBD National Target'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'cbd_nfp' => array(
      'name' => t('CBD National Focal Point'),
      'base' => 'node_content',
      'description' => t('CBD National Focal Point automatically imported from the CBD REST API'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'chm_site' => array(
      'name' => t('CHM site'),
      'base' => 'node_content',
      'description' => t('Use this content type to add references of current or future national or regional CHM websites'),
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
    'gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('Group multiple images into a nice gallery'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Create a gallery with description and after saving, use drag and drop to upload files from your computer. Images can be ordered, cropped etc.'),
    ),
    'link' => array(
      'name' => t('Link'),
      'base' => 'node_content',
      'description' => t('Provide a link to a website or another online reference presenting relevant information about biodiversity in your country.'),
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
    'organization' => array(
      'name' => t('Organization'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
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
    'person' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Full name'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Use a project to describe a biodiversity project or initiative in your country.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'protected_area' => array(
      'name' => t('Protected area'),
      'base' => 'node_content',
      'description' => t('Use this type to describe a protected area in your country'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'species' => array(
      'name' => t('Species'),
      'base' => 'node_content',
      'description' => t('Contains species data'),
      'has_title' => '1',
      'title_label' => t('Scientific name'),
      'help' => '',
    ),
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Upload a video on Youtube and show it in your website!'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
