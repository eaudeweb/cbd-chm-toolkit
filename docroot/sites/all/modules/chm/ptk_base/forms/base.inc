<?php

require_once dirname(__FILE__) . '/ChmDomainForm.php';
require_once dirname(__FILE__) . '/ChmDomainDeleteFormForm.php';
require_once dirname(__FILE__) . '/ChmI18nStringLocaleTranslateEditFormForm.php';
require_once dirname(__FILE__) . '/ChmSocialMediaForm.php';
require_once dirname(__FILE__) . '/ChmMiscellaneousForm.php';
require_once dirname(__FILE__) . '/ChmNodeForm.php';
require_once dirname(__FILE__) . '/ChmProtectedPlanetSettingsForm.php';
require_once dirname(__FILE__) . '/ChmUserLoginForm.php';
require_once dirname(__FILE__) . '/ChmUserAdminAccountForm.php';


/**
 * Implements hook_form_alter().
 * @inheritdoc
 */
function ptk_base_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'entityqueue_subqueue_edit_form') {
    $form['eq_node']['und']['add']['entity']['#size'] = 140;
  }

  if ($form_id == 'views_exposed_form' && $form['#id'] == 'views-exposed-form-administrative-content-page') {
    PTKForm::adminContentFormAlter($form, $form_state);
  }
  $klass = 'Chm' . str_replace(' ', '', ucwords(str_replace('_', ' ', $form_id))) . 'Form';
  // if (module_exists('devel')) { dpm($klass); }
  if (class_exists($klass) && method_exists($klass, 'alter')) {
    $klass::alter($form, $form_state);
  }
  // Alter all forms where document type field appears
  PTKFormDocumentTypeField::alter($form);
  if (!empty($form['#node_edit_form'])) {
    ChmNodeForm::alter($form, $form_state);
  }
}


/**
 * Class PTKFormDocumentTypeField for alters the field_document_type to show
 * only the active terms
 */
class PTKFormDocumentTypeField {

  static function alter(&$form) {
    if (isset($form['field_document_type'])) {
      $allowed = db_select('field_data_field_in_use', 'a')
        ->fields('a', array('entity_id'))
        ->condition('entity_type', 'taxonomy_term')
        ->condition('bundle', 'document_type')
        ->condition('deleted', 0)->execute()->fetchCol();
      $options = array();
      foreach ($form['field_document_type'][LANGUAGE_NONE]['#options'] as $k => $v) {
        if (in_array($k, $allowed) || $k == '_none') {
          $options[$k] = $v;
        }
      }
      $form['field_document_type'][LANGUAGE_NONE]['#options'] = $options;
    }
  }

}

class PTKForm {
  public static function adminContentFormAlter(&$form, $form_state) {
    if (!PTK::userIsAdministrator()) {
      unset($form['#info']['filter-sitename']);
      $form['#info']['#access'] = FALSE;
      $form['sitename']['#access'] = FALSE;
      hide($form['sitename']);
      return;
    }
    if (!empty($form['sitename'])) {
      $domains = domain_domains();
      $options = array('' => t('-- All sites --'));
      foreach ($domains as $domain) {
        $options[$domain['sitename']] = $domain['sitename'];
      }
      $form['sitename']['#type'] = 'select';
      $form['sitename']['#options'] = $options;
      $form['sitename']['#default_value'] = '';
      unset($form['sitename']['#size']);
    }
  }
}