<?php


/**
 * Log messages from the API.
 *
 * @param string $message
 *   Message to log
 * @param int $severity
 *   Same as WATCHDOG_* constants
 *
 * @see watchdog()
 */
function iucn_redlist_log($message, $variables, $severity) {
  if ($severity == WATCHDOG_ERROR) {
    watchdog('mymodule', $message, $variables, $severity);
  }
}
