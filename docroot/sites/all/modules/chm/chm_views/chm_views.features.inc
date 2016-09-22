<?php
/**
 * @file
 * chm_views.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function chm_views_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_ctools_plugin_api().
 */
function chm_views_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "slick" && $api == "slick_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function chm_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function chm_views_image_default_styles() {
  $styles = array();

  // Exported image style: portrait_image_listing.
  $styles['portrait_image_listing'] = array(
    'label' => 'Portrait image listing',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 595,
          'height' => 842,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: slider_image.
  $styles['slider_image'] = array(
    'label' => 'Slider image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 1200,
          'height' => 400,
          'anchor' => 'center-top',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
