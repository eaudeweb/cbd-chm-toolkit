<?php

class ChmServiceConsumerLog {

  static $messages = array();

  public static function log($message, $severity = MigrationBase::MESSAGE_INFORMATIONAL) {
    $ob = new stdClass();
    $ob->timestamp = time();
    $ob->message = $message;
    $ob->severity = $severity;
    self::$messages[] = $ob;

    if (function_exists('drush_log')) {
      $status = 'status';
      switch($severity) {
        case MigrationBase::MESSAGE_ERROR:
          $status = 'error';
          break;
        case MigrationBase::MESSAGE_WARNING:
          $status = 'warning';
          break;
        case MigrationBase::MESSAGE_NOTICE:
          $status = 'notice';
          break;
      }
      drush_log($message, $status);
      return;
    }
  }

  public static function findMessages($pattern) {
    $ret = array();
    foreach(self::$messages as $message) {
      if(preg_match($pattern, $message->message) === 1) {
        $ret[] = $message;
      }
    }
    return $ret;
  }

  public static function messages() {
    return self::$messages;
  }
}

/**
 * Log system for the chm_service_consumer migrations.
 *
 * @param string $message
 *   Log message
 * @param int $severity
 *    See MigrationBase::MESSAGE_* constants
 */
function chm_service_consumer_log($message, $severity = MigrationBase::MESSAGE_INFORMATIONAL) {
  ChmServiceConsumerLog::log($message, $severity);
}

function chm_service_consumer_drush_command() {
  return array(
    'nfp-purge-orphans' => array(
      'description' => 'Check remote service for orphaned nfp records (removed) and remove them locally',
      'required-arguments' => 0,
      'options' => array(
        'dry-run' => 'Do not delete, just report the records',
      ),
    )
  );
}

function drush_chm_service_consumer_nfp_purge_orphans() {
  $dry_run = drush_get_option('dry-run');
  $migration_name = 'nfp';
  /** @var CHMServerConsumerNFPMigration $migration */
  $migration = Migration::getInstance($migration_name);
  if (!$migration) {
    drush_set_error('No migration found:' . $migration_name);
    return;
  }

  if ($migration->getStatus() != MigrationBase::STATUS_IDLE) {
    drush_set_error('Migration not idle, waiting to finish. Status is: ' . $migration->getStatus());
    return;
  }

  $rows = db_select('migrate_map_' . $migration_name, 'm')
    ->fields('m', array('sourceid1', 'destid1'))
    ->isNotNull('destid1')
    ->execute()
    ->fetchAllKeyed(0, 1);
  $total_destination = count($rows);
  chm_service_consumer_log(__METHOD__ . "(): Checking {$total_destination} records for orphans", MigrationBase::MESSAGE_INFORMATIONAL);

  /** @var CHMServerConsumerNFPMigrateSource $source  */
  $source = $migration->getSource();
  $total = $source->count();
  chm_service_consumer_log(__METHOD__ . "(): Total {$total} source records", MigrationBase::MESSAGE_INFORMATIONAL);

  $source_ids = [];
  while ($row = $source->getNextRow()) {
    $source_ids[$row->id] = $row->id;
  }
  if (!$source_ids) { // Error no rows. avoid remove all
    return;
  }
  if ($total != count($source_ids)) {
    drush_set_error("Error getting total = " . $total . ", found = " . count($source_ids) . ". Try again later" );
    return;
  }

  $orphaned = 0;
  $i = 0;
  $deleted = 0;
  foreach($rows as $source_id => $nid) {
    if (!@$source_ids[$source_id]) {
//      echo "Orphaned source_id = " . $source_id . ", dest_id = " . $nid . "\n";
//      $orphaned++;
      if (!$dry_run) {
        chm_service_consumer_log(__METHOD__ . "(): Deleting orphan record: $source_id ($nid)", MigrationBase::MESSAGE_INFORMATIONAL);
//        node_delete($nid);
        $deleted++;
//        $migration->getMap()->delete(array($source_id));
      } else {
        chm_service_consumer_log(__METHOD__ . "(): Found orphan record: $source_id ($nid)", MigrationBase::MESSAGE_INFORMATIONAL);
        $orphaned++;
      }
    }
    if (++$i % 50 === 0) {
      chm_service_consumer_log(__METHOD__ . "(): Checked {$i}/{$total_destination}", MigrationBase::MESSAGE_INFORMATIONAL);
    }
  }
  if (!$dry_run) {
    chm_service_consumer_log(__METHOD__ . "(): Removed {$deleted} orphan records", MigrationBase::MESSAGE_INFORMATIONAL);
  }
  else {
    chm_service_consumer_log(__METHOD__ . "(): Found {$orphaned} orphan records", MigrationBase::MESSAGE_INFORMATIONAL);
  }
//  echo "Orphaned = $orphaned \n";
}
