<?php

/**
 * Class CHMPortalBaseMigration is the base class for Naaya CHM portals migration.
 */
abstract class CHMPortalBaseMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);
  }

  /**
   * Additional preparation for the row, specific to the content-type.
   *
   * @param stdClass $row
   *   Row object to prepare
   */
  abstract function prepareRowObject($row);

  /**
   * @param object $row
   *   Row object to validate
   *
   * @return boolean
   *   TRUE if the row is valid, FALSE otherwise
   */
  abstract function validateRowObject($row);

  public function prepareRow($row) {
    $this->prepareRowObject($row);
    return $this->validateRowObject($row);
  }
}
