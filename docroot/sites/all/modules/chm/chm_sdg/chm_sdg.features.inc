<?php
/**
 * @file
 * chm_sdg.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function chm_sdg_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
