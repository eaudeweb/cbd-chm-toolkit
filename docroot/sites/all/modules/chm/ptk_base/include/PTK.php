<?php


class PTK {

  static function getCountryByCode($iso) {
    $countries = drupal_static(__METHOD__);
    if (!isset($countries)) {
      $q = db_select('field_data_field_country_code');
      $q->fields(NULL, array('entity_id', 'field_country_code_value'));
      $q->condition('entity_type', 'taxonomy_term');
      $q->condition('bundle', 'countries');
      $rows = $q->execute()->fetchAllKeyed();
      foreach ($rows as $k => $code) {
        $countries[$code] = taxonomy_term_load($k);
      }
    }
    $k = strtoupper(trim($iso));
    if (!empty($countries[$k])) {
      return $countries[$k];
    }
    return NULL;
  }
}
