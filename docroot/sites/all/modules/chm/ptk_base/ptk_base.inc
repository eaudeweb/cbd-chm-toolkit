<?php

class PTK {

  const ROLE_ADMINISTRATOR = 'administrator';

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
        $items[strtoupper($term->iso2l)] = $term;
        $items[strtoupper($term->iso3l)] = $term;
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

  /**
   * Lookup country by name
   * @param string $name Country name
   * @return integer
   *   Country tid or NULL
   */
  static function getCountryByName($name) {
    $name = trim($name);
    /** @var SelectQuery $query */
    $query = db_select('taxonomy_term_data', 'a')->fields('a', array('tid'));
    $query->leftJoin('field_data_name_field', 'b', "a.tid = b.entity_id AND b.bundle = 'countries'");
    $query->leftJoin('field_data_field_un_official_short_name', 'c', "a.tid = c.entity_id AND c.bundle = 'countries'");
    $query->leftJoin('field_data_field_official_name', 'd', "a.tid = d.entity_id AND d.bundle = 'countries'");

    $where = db_or();
    $where->condition('a.name', $name);
    $where->condition('b.name_field_value', $name);
    $where->condition('c.field_un_official_short_name_value', $name);
    $where->condition('d.field_official_name_value', $name);
    $query->condition($where);
    $query->groupBy('a.tid');

    if ($tid = $query->execute()->fetchField()) {
      return $tid;
    }
    return NULL;
  }

  public static function getCountryFlag($country, $relative = FALSE) {
    try {
      $w = entity_metadata_wrapper('taxonomy_term', $country);
      if ($iso = $w->field_iso_code->value() && $image = $w->field_image->value()) {
        return $image['uri'];
      }
    } catch (Exception $e) {
      watchdog_exception('ptk', $e);
    }
    return NULL;
  }

  public static function getCountryFlagURL($country) {
    try {
      $w = entity_metadata_wrapper('taxonomy_term', $country);
      if ($iso = $w->field_iso_code->value() && $image = $w->field_image->value()) {
        return url(
          file_create_url($image['uri']),
          array('absolute' => 0, 'language' => (object)array('language' => LANGUAGE_NONE))
        );
      }
    } catch (Exception $e) {
      watchdog_exception('ptk', $e);
    }
    return NULL;
  }

  /**
   * Configure the given block to be displayed on a specific URL pattern.
   * It alters the default 'pages' configuration parameter to add new pattern
   * @param $blocks
   * @param $nid
   * @param string $theme
   */
  public static function showBlockOnPage($block_delta, $url, $theme = 'chm_theme_kit') {
    $q = db_select('block', 'b')
      ->condition('b.delta', $block_delta)
      ->condition('b.theme', $theme)
      ->fields('b', ['pages']);
    $pages = $q->execute()->fetchField();
    $pages .= PHP_EOL . $url;
    db_update('block')
      ->condition('delta', $block_delta)
      ->condition('theme', $theme)
      ->fields(['pages' => $pages])
      ->execute();
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
        else {
          return array(date($cfg['from_full'], $from), NULL);
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

  /**
   * Check if the given user has been granted administrator role.
   *
   * @param stdClass $account
   *   Account to check
   *
   * @return bool
   *   TRUE if the user is administrator
   */
  static function userIsAdministrator($account = NULL) {
    if (empty($account)) {
      global $user;
      $account = $user;
    }
    if ($account->uid == 1) {
      return true;
    }
    return in_array(self::ROLE_ADMINISTRATOR, $account->roles);
  }


  static function stringEndsWith($string, $test) {
    $strlen = strlen($string);
    $testlen = strlen($test);
    if ($testlen > $strlen) return false;
    return substr_compare($string, $test, $strlen - $testlen, $testlen) === 0;
  }


  static function entityQueueAccess($op, $entity = NULL, $account = NULL, $entity_type = NULL) {
    if (PTK::userIsAdministrator()) {
      return entityqueue_access($op, $entity, $account, $entity_type);
    }
    else {
      if ($op == 'update') {
        global $user;
        domain_user_load(array($user));
        $queue_name = $entity->queue;
        foreach ($user->domain_user as $domain_id) {
          $domain = domain_load($domain_id);
          if (PTK::stringEndsWith($queue_name, '_' . $domain['machine_name'])) {
            return TRUE;
          }
        }
      }
      return FALSE;
    }
  }


  static function getOrCreateTermIdByName($name, $machine_name, $create = TRUE) {
    $voc = taxonomy_vocabulary_machine_name_load($machine_name);
    /** @var SelectQuery $query */
    $query = db_select('taxonomy_term_data', 'a')
      ->fields('a', array('tid'))
      ->condition('vid', $voc->vid)
      ->condition('name', $name);
    if ($tid = $query->execute()->fetchField()) {
      return $tid;
    }
    else {
      if (!$create) {
        return NULL;
      }
      // Create the term
      $term = new stdClass();
      $term->language = 'en';
      $term->vid = $voc->vid;
      $term->name = $name;
      $term->name_field['en'][0]['value'] = $name;
      taxonomy_term_save($term);
      if (!empty($term->tid)) {
        return $term->tid;
      }
      return NULL;
    }
  }

  /**
   * Find organization node by name.
   *
   * @param string $name Organization name
   * @return integer
   *   Node ID or NULL if not found
   */
  static function getOrganizationByName($name) {
    // SELECT * FROM node a
    // LEFT JOIN field_data_title_field b ON (a.nid = b.entity_id AND b.bundle = 'organization')
    // LEFT JOIN field_data_field_organization_acronym c ON (a.nid = c.entity_id AND c.bundle = 'organization')
    // WHERE a.title = 'GEF' OR b.title_field_value = 'GEF';
    $name = trim($name);
    /** @var SelectQuery $query */
    $query = db_select('node', 'a')->fields('a', array('nid'));
    $query->leftJoin('field_data_title_field', 'b', "a.nid = b.entity_id AND b.bundle = 'organization'");
    $query->leftJoin('field_data_field_organization_acronym', 'c', "a.nid = c.entity_id AND c.bundle = 'organization'");

    $where = db_or();
    $where->condition('a.title', $name);
    $where->condition('b.title_field_value', $name);
    $where->condition('c.field_organization_acronym_value', $name);
    $query->condition($where);
    $query->groupBy('a.nid');

    if ($tid = $query->execute()->fetchField()) {
      return $tid;
    }
    return NULL;

  }
}
