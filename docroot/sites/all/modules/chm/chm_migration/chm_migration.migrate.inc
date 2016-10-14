<?php

/**
 * Implements hook_migrate_api().
 */
function chm_migration_migrate_api() {
  $ret = array(
    'api' => 2,
    'groups' => array(
      CHM_NAAYA_MIGRATION_GROUP => array('title' => t('Migrate data exported from old CHM portals based on Naaya platform')),
    ),
    'migrations' => array(),
  );
  $config = chm_migration_get_source_config();
  $root_dir = variable_get(CHM_NAAYA_EXPORT_DIR);
  foreach($config->sites as $domain_machine_name => $source) {
    if (!$destination_domain_id = domain_load_domain_id($domain_machine_name)) {
      drupal_set_message(
        sprintf('[chm_migration] Cannot find domain with machine name: %s', $domain_machine_name, $domain_machine_name),
        'error'
      );
      continue;
    };
    $destination_domain = domain_load($destination_domain_id);
    if (!empty($source->source_dir_events)) {
      $data_dir = realpath($root_dir . '/' . $source->source_dir_events);
      if (!is_dir($data_dir) || !is_readable($data_dir)) {
        drupal_set_message(
          sprintf('[chm_migration][%s]Source data directory does not exist or unreadable: %s', $domain_machine_name, $data_dir),
          'error'
        );
        continue;
      }
      $migration_name = $domain_machine_name . '_events';
      $migration = array(
        'group_name' => CHM_NAAYA_MIGRATION_GROUP,
        'class_name' => 'CHMPortalEventsMigration',
        'dependencies' => array(),
        'source_dir' => $data_dir,
        'domain' => $destination_domain
      );
      $ret['migrations'][$migration_name] = $migration;
    }
  }

  return $ret;
}
