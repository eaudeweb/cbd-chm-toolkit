<?php
/**
 * @file
 *   Policy commandfile.
 *
 *   Validates commands as they are issued and returns an error
 *   or changes options when policy is violated.
 */

/**
 * Implements drush_hook_COMMAND_validate().
 *
 * Prevent catastrophic braino when syncing databases.
 */
function drush_policy_sql_sync_validate($source = NULL, $destination = NULL) {
  if (preg_match('/@prod/', $destination)) {
    return drush_set_error(dt('You may never overwrite the production database.'));
  }
  return TRUE;
}

/**
 * Implements drush_hook_COMMAND_validate().
 *
 * Prevent catastrophic braino when rsyncing files.
 */
function drush_policy_core_rsync_validate($source = NULL, $destination = NULL) {
  if (preg_match("/^@prod/", $destination)) {
    return drush_set_error(dt('You may never overwrite the production files.'));
  }
  return TRUE;
}

function drush_policy_prepare_dev_validate() {
  if (empty(variable_get('environment')) || variable_get('environment') == 'prod') {
    return drush_set_error(dt('DANGER: Use explicit `drush vset environment dev` to confirm this environment is for development'));
  }
  return TRUE;
}

function drush_policy_prepare_test_validate() {
  if (empty(variable_get('environment')) || variable_get('environment') == 'prod') {
    return drush_set_error(dt('DANGER: Use explicit `drush vset environment test` to confirm this environment is for testing'));
  }
  return TRUE;
}