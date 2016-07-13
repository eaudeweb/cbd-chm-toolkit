<?php



/**
 * Implements hook_form_alter().
 * @inheritdoc
 */
function ptk_base_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'views_exposed_form' && $form['#id'] == 'views-exposed-form-administrative-content-page') {
    PTKForm::adminContentFormAlter($form, $form_state);
  }
  PTKFormDocumentTypeField::alter($form);
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