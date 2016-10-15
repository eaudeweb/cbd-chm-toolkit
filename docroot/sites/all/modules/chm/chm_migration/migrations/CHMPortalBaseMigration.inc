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

  public static function prepareDateField($date_string) {
    if (empty($date_string)) {
      return NULL;
    }
    if ($datetime = DateTime::createFromFormat(DateTime::ISO8601, $date_string . 'Z')) {
      $datetime->setTimezone(new DateTimeZone('Etc/Zulu'));
      return $datetime->getTimestamp();
    }
    return $date_string;
  }

  protected function ignoreMetatagFields() {
    $this->addUnmigratedDestinations([
      'metatag_title', 'metatag_description', 'metatag_abstract', 'metatag_keywords',
      'metatag_robots', 'metatag_news_keywords', 'metatag_standout', 'metatag_rating',
      'metatag_referrer', 'metatag_generator', 'metatag_rights', 'metatag_image_src',
      'metatag_canonical', 'metatag_shortlink', 'metatag_publisher', 'metatag_author',
      'metatag_original-source', 'metatag_prev', 'metatag_next', 'metatag_content-language',
      'metatag_geo.position', 'metatag_geo.placename', 'metatag_geo.region',
      'metatag_icbm', 'metatag_refresh', 'metatag_revisit-after', 'metatag_pragma',
      'metatag_cache-control', 'metatag_expires',
    ]);
  }
}
