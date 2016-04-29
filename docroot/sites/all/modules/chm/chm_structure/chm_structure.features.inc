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
