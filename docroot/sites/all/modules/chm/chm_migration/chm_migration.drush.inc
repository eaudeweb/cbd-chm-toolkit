<?php

function chm_migration_drush_command() {
  $items = array();

  $items['chm-source-overview'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => 'Status of a CHM site migration',
    'aliases' => array('chm-mo'),
  );

  $items['chm-migrate-status'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => 'Status of a CHM site migration',
    'required-arguments' => 1,
    'arguments' => array(
      'domain_machine_name' => 'Drupal domain machine name of the website to import (see /admin/structure/domains for the list)',
    ),
    'aliases' => array('chm-ms'),
  );

  $items['chm-migrate-import'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => 'Run a CHM site migration task',
    'aliases' => array('chm-mi'),
  );

  $items['chm-migrate-test'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => 'Test migrations',
    'aliases' => array('chm-mi-test'),
  );

  return $items;
}

function drush_chm_migration_chm_source_overview() {
  if ($source_dir = variable_get(CHM_NAAYA_EXPORT_DIR)) {
    drush_log("Source data directory: $source_dir", 'ok');
    drush_log("Reading source file  : " . realpath($source_dir . '/migrate-config.json'));
    $config = chm_migration_get_source_config();
    foreach($config->sites as $id => $source) {
      drush_log("\nFound site: $id", 'ok');
      if (!empty($source->source_dir_events)) {
        $source = new CHMEventsNestedDirJSONSource(array('source_dir' => realpath($source_dir . '/' . $source->source_dir_events)));
        drush_log(sprintf("    * Events: %d items", $source->computeCount()), 'ok');
      }
    }
  }
  else {
    $var = CHM_NAAYA_EXPORT_DIR;
    drush_log("Source data directory not set, aborting! Use 'drush vset {$var}  /path/to/export/data/dir' to configure the correct data source!", 'error');
  }
}

function drush_chm_migration_chm_migrate_status() {

}

function drush_chm_migration_chm_migrate_test() {
  $events = new CHMPortalEventsMigrationTest();
  try {
    $events->test();
    echo "Success! (({$events->getAssertionsCount()} assertion(s), {$events->getFailuresCount()} failure(s))\n";
  } catch (Exception $e) {
    drush_set_error($e->getMessage());
    echo "Failure! ({$events->getAssertionsCount()} assertion(s), {$events->getFailuresCount()} failure(s))\n";
  }
}
