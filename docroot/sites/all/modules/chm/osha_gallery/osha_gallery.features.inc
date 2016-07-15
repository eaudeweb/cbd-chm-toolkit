<?php
/**
 * @file
 * osha_gallery.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function osha_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: gallery_cover_image.
  $styles['gallery_cover_image'] = array(
    'label' => 'Gallery cover image',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1170,
          'height' => 555,
          'upscale' => 0,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'gallery_cover_image',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: gallery_thumbnail.
  $styles['gallery_thumbnail'] = array(
    'label' => 'Gallery Thumbnail',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
