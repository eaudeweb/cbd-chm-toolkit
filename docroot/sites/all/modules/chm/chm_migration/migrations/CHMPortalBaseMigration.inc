<?php

/**
 * Class CHMPortalBaseMigration is the base class for Naaya CHM portals migration.
 */
abstract class CHMPortalBaseMigration extends Migration {

  use CHMLoggingTrait;

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

  public function prepareKeywords($row) {
    $keywords = [];
    try {
      foreach ($row->keywords as $ob) {
        if ($tid = self::findTermIdByName($ob->term, 'keywords')) {
          $keywords[] = $tid;
        }
        else {
          $this->info('Creating new term: ' . $ob->term);
          $voc = taxonomy_vocabulary_machine_name_load('keywords');
          $term = (object)[
            'vid' => $voc->vid,
            'name' => $ob->term,
            'name_field' => [$ob->language => [0 => ['value' => $ob->term]]],
            'language' => $ob->language,
          ];
          taxonomy_term_save($term);
          $keywords[] = $term->tid;
        }
      }
    } catch(Exception $e) {
      // @todo:
    }
    $row->keywords = $keywords;
  }

  public static function findTermIdByName($term, $vocabulary) {
    // SELECT a.entity_id FROM field_data_name_field a
    // WHERE a.entity_type = 'taxonomy_term' AND a.bundle = 'keywords'
    // AND a.name_field_value = 'keyword';
    $q = db_select('field_data_name_field', 'a')->fields('a', ['entity_id']);
    $q->condition('entity_type', 'taxonomy_term');
    $q->condition('bundle', $vocabulary);
    $q->condition('name_field_value', $term);
    return $q->execute()->fetchField();
  }

}
