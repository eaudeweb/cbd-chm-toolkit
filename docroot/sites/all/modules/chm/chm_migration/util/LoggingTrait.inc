<?php

trait CHMLoggingTrait {

  public function debug($message) {
    $this->log($message, 'debug');
  }

  public function info($message) {
    $this->log($message);
  }

  public function warning($message) {
    $this->log($message, 'warning');
  }

  public function error($message) {
    $this->log($message, 'error');
  }

  public function log($message, $level = 'info') {
    if (function_exists('drush_log')) {
      switch($level) {
        case 'debug':
          drush_log($message, \Drush\Log\LogLevel::INFO);
          break;

        case 'info':
          drush_log($message, \Drush\Log\LogLevel::OK);
          break;

        case 'warning':
          drush_log($message, \Drush\Log\LogLevel::WARNING);
          break;

        case 'error':
          drush_log($message, \Drush\Log\LogLevel::ERROR);
          break;
      }
    }
    else {

    }
  }
}
