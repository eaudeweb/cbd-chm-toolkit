<?php


class PTK {

  public static function getCountryListAsOptions() {
    $ret = [];
    $countries = self::getCountryList();
    foreach ($countries as $country) {
      $w = entity_metadata_wrapper('taxonomy_term', $country);
      $code = $w->field_iso_code->value();
      $ret[strtolower($code)] = $w->label();
    }
    return $ret;
  }

  /**
   * Return the list of countries.
   *
   * @return array|mixed
   *   List of taxonomy term objects
   */
  public static function getCountryList() {
    $items = drupal_static(__METHOD__);
    if (!isset($items)) {
      $v = taxonomy_vocabulary_machine_name_load('countries');
      $items = taxonomy_term_load_multiple(NULL, array('vid' => $v->vid));
    }
    return $items;
  }

  /**
   * Retrieve a country by its code.
   *
   * @param string $iso
   *   ISO 2L code.
   * @return stdClass|NULL
   *   Country object
   */
  public static function getCountryByCode($iso) {
    $items = drupal_static(__METHOD__);
    if (!isset($items)) {
      $q = db_select('field_data_field_iso_code');
      $q->fields(NULL, array('entity_id', 'field_iso_code_value'));
      $q->condition('entity_type', 'taxonomy_term');
      $q->condition('bundle', 'countries');
      $rows = $q->execute()->fetchAllKeyed();
      foreach ($rows as $k => $code) {
        $term = taxonomy_term_load($k);
        $w = entity_metadata_wrapper('taxonomy_term', $term);
        $term->iso2l = $w->field_iso_code->value();
        $term->iso3l = $w->field_iso3l_code->value();
        $items[strtoupper($code)] = $term;
      }
    }
    $k = strtoupper(trim($iso));
    if (!empty($items[$k])) {
      return $items[$k];
    }
    return NULL;
  }


  /**
   * Retrieve a NFP Type term by its code.
   *
   * @param string $acronym
   *   Acronym for the term
   * @return stdClass|NULL
   *   The corrersponding taxonomy term
   */
  public static function getNFPTypeByAcronym($acronym) {
    $items = drupal_static(__METHOD__);
    if (!isset($items)) {
      $q = db_select('field_data_field_original_id');
      $q->fields(NULL, array('entity_id', 'field_original_id_value'));
      $q->condition('entity_type', 'taxonomy_term');
      $q->condition('bundle', 'taxonomy_nfp_type');
      $rows = $q->execute()->fetchAllKeyed();
      foreach ($rows as $k => $code) {
        $items[$code] = taxonomy_term_load($k);
      }
    }
    $k = strtoupper(trim($acronym));
    if (!empty($items[$k])) {
      return $items[$k];
    }
    return NULL;
  }

  public static function getCountryFlagURL($country) {
    try {
      $w = entity_metadata_wrapper('taxonomy_term', $country);
      if ($iso = $w->field_iso_code->value() && $image = $w->field_image->value()) {
        return url(file_create_url($image['uri']),
          array('absolute' => 1, 'language' => (object)array('language' => LANGUAGE_NONE))
        );
      }
    } catch (Exception $e) {
      watchdog_exception('ptk', $e);
    }
    return NULL;
  }


  public static function addBlocksToNode($blocks, $nid, $theme = 'chm_theme_kit') {
    if (!is_array($blocks)) {
      $blocks = [$blocks];
    }
    foreach ($blocks as $block) {
      $q = db_select('block', 'b')
        ->condition('b.delta', $block)
        ->condition('b.theme', $theme)
        ->fields('b', ['pages']);
      $pages = $q->execute()->fetchField();
      $pages .= "\nnode/{$nid}";
      db_update('block')
        ->condition('delta', $block)
        ->condition('theme', $theme)
        ->fields([
          'pages' => $pages,
        ])
        ->execute();
    }
  }

  /**
   * @param integer $from
   *   Start timestamp
   * @param integer $to
   *   End timestamp
   *
   * @return array
   *   Array with two elements, first is the start date, second is the end
   *   date representation or NULL. If input is invalid yields (NULL, NULL)
   */
  static function dateInterval($from, $to, $config = array()) {
    if (empty($from)) {
      return array(NULL, NULL);
    }
    $cfg = array_merge(array(
      'to_format' => 'j F Y',
      'from_day' => 'j',
      'from_day_month' => 'j F',
      'from_full' => 'j F Y'
    ), $config);
    $f_year = date('Y', $from);
    $t_year = !empty($to) ? date('Y', $to) : NULL;
    $f_month = date('F', $from);
    $t_month = !empty($to) ? date('F', $to) : NULL;
    $f_day = date('j', $from);
    $t_day = !empty($to) ? date('j', $to) : NULL;
    $to_str = !empty($to) ? date($cfg['to_format'], $to) : NULL;

    if ($f_year != $t_year) {
      // Go full date
      return array(date($cfg['from_full'], $from), $to_str);
    }
    else {
      if ($f_month != $t_month) {
        return array(date($cfg['from_day_month'], $from), $to_str);
      }
      else {
        if ($f_day != $t_day) {
          return array(date($cfg['from_day'], $from), $to_str);
        }
      }
    }
    return array(NULL, NULL);
  }

  static function dateIntervalString($from, $to) {
    list($start, $end) = self::dateInterval($from, $to);
    if (empty($end)) {
      return $start;
    }
    else {
      return t('!start_date to !end_date', array('!start_date' => $start, '!end_date' => $end));
    }
  }

  /**
   * Log a message.
   *
   * @param string $message
   */
  static function log_debug($message) {
    if (function_exists('drush_log')) {
      drush_log($message, \Drush\Log\LogLevel::NOTICE);
    }
  }

  /**
   * Log a message.
   *
   * @param string $message
   */
  static function log_warning($message) {
    if (function_exists('drush_log')) {
      drush_log($message, \Drush\Log\LogLevel::WARNING);
    }
  }

  /**
   * Log a message.
   *
   * @param string $message
   */
  static function log_error($message) {
    if (function_exists('drush_log')) {
      drush_log($message, \Drush\Log\LogLevel::ERROR);
    }
  }
}
