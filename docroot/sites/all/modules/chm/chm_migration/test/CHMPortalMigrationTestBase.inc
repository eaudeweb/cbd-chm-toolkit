<?php


class CHMPortalMigrationTestBase {

  protected $assertions = 0;
  protected $failures = 0;
  protected $continueOnFailure = 0;

  protected function assertEquals($a, $b) {
    $this->assertions++;
    if ($a !== $b) {
      $this->handleFailure("'$a' != '$b'");
    }
  }

  protected function assertTrue($a) {
    $this->assertions++;
    if ($a !== true) {
      $this->handleFailure("expression is not true");
    }
  }

  protected function assertNotNull($a) {
    $this->assertions++;
    if ($a === null) {
      $this->handleFailure("$a is not null");
    }
  }

  protected function assertNotEmpty($a) {
    $this->assertions++;
    if (empty($a)) {
      $this->handleFailure("$a is not empty");
    }
  }

  protected function handleFailure($message) {
    $trace = debug_backtrace();
    $failure = $trace[1];
    echo "Assestion failure $message on {$failure['file']}:{$failure['line']}\n";
    if (!$this->continueOnFailure) {
      $this->failures++;
      throw new Exception("Tests failed. Stopping ...");
    }
  }

  public function getAssertionsCount() {
    return $this->assertions;
  }

  public function getFailuresCount() {
    return $this->failures;
  }
}
