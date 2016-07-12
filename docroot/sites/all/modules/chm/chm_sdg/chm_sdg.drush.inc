<?php

function chm_sdg_drush_command() {
  $items = array();

  $items['chm-sdg-full-import'] = array(
    'drupal dependencies' => array('phpexcel'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => 'SDG Full Import',
    'aliases' => array('sdg-fi'),
  );

  return $items;
}

/**
 * Imports SDG goals, targets & indicators from SDGs.xlsx file.
 */
function drush_chm_sdg_full_import() {
  
}