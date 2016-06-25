<?php

/**
 * Implements hook_drush_command().
 */
function country_taxonomy_drush_command() {
  $items = array();
  $items['delete-countries'] = array(
    'description' => 'Empty the country taxonomy',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

function drush_country_taxonomy_delete_countries() {
  if ($voc = taxonomy_vocabulary_machine_name_load('countries')) {
    $q = db_select('taxonomy_term_data', 'a')->fields('a', array('tid'));
    $q->condition('vid', $voc->vid);
    foreach ($q->execute()->fetchCol() as $tid) {
      $term = taxonomy_term_load($tid);
      drush_log("Removing {$term->name} ...", 'warning');
      taxonomy_term_delete($tid);
    }
  }
}
