<?php

/**
 * Class ChmNodeForm affects the behavior of all node forms.
 */
class ChmNodeForm {

  /**
   * This method is called for all node forms.
   *
   * @param $form
   * @param $form_state
   */
  static function alter(&$form, &$form_state) {
    /** Global configuration common to all forms */

    // Non-administrators does not have access to authoring information
    if (!user_access('configure chm settings')) {
      $form['author']['#access'] = FALSE;
    }

    // Pre-fill field_countries to all nodes with domain's configured country.
    if (isset($form['field_countries'])) {
      if ($country = PTKDomain::getPortalCountry()) {
        $form['field_countries'][LANGUAGE_NONE]['#default_value'] = array($country->tid);
      }
    }

    // Per node type customisations
    if ($form) {
      $bundle = $form['#bundle'];
      $method = 'alter_' . $bundle;
      if (method_exists('ChmNodeForm', $method)) {
        self::$method($form, $form_state);
      }
    }
  }

  static function alter_protected_area(&$form, &$form_state) {
    $is_new = empty($form['#node']->nid);
    // Allow full edit for new nodes.
    if ($is_new) {
      return;
    }
    $nid = $form['#node']->nid;
    $wdpaid = db_select('migrate_map_protected_areas')
      ->fields(NULL, array('sourceid1'))
      ->condition('destid1', $nid)
      ->execute()
      ->fetchField();
    // Allow full edit for non-migrated nodes.
    if (empty($wdpaid)) {
      return;
    }

    // Hide migrated fields
    $fields = array(
      'title_field',
      'field_pa_designation',
      'field_pa_designation_type',
      'field_pa_iucn_category',
      'field_pa_surface_area',
      'field_pa_status',
      'field_pa_status_year',
      'field_pa_governing_type',
      'field_pa_owner_type',
      'field_pa_management_authority',
      'field_pa_management_plan',
      'field_countries',
    );
    foreach ($fields as $field_name) {
      $form[$field_name]['#access'] = FALSE;
    }
  }
}
