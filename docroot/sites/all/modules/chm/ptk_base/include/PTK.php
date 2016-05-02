<?php


class PTK {

  /**
   * Retrieve a country by its code.
   *
   * @param string $iso
   *   ISO 2L code.
   * @return stdClass|NULL
   *   Country object
   */
  static function getCountryByCode($iso) {
    $items = drupal_static(__METHOD__);
    if (!isset($items)) {
      $q = db_select('field_data_field_country_code');
      $q->fields(NULL, array('entity_id', 'field_country_code_value'));
      $q->condition('entity_type', 'taxonomy_term');
      $q->condition('bundle', 'items');
      $rows = $q->execute()->fetchAllKeyed();
      foreach ($rows as $k => $code) {
        $items[$code] = taxonomy_term_load($k);
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
  static function getNFPTypeByAcronym($acronym) {
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
}
