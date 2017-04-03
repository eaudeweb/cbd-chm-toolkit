<?php

require_once dirname(__FILE__) . '/ChmDomainForm.php';
require_once dirname(__FILE__) . '/ChmDomainDeleteFormForm.php';
require_once dirname(__FILE__) . '/ChmI18nStringLocaleTranslateEditFormForm.php';
require_once dirname(__FILE__) . '/ChmSocialMediaForm.php';
require_once dirname(__FILE__) . '/ChmMiscellaneousForm.php';
require_once dirname(__FILE__) . '/ChmNodeForm.php';
require_once dirname(__FILE__) . '/ChmProtectedPlanetSettingsForm.php';
require_once dirname(__FILE__) . '/ChmUserLoginForm.php';
require_once dirname(__FILE__) . '/ChmUserProfileFormForm.php';

function _ptk_base_menu_link_check_expanded($link) {
  for($i=1; $i <= $link['depth']; $i++) {
    $mlid = $link['p' . $i];
    if ($mlid ) {
      $menu_link = menu_link_load($mlid);
      if (!$menu_link['expanded']) {
        $menu_link['expanded'] = 1;
        menu_link_save($menu_link);
      }
    }
  }
}
function ptk_base_menu_link_insert($link) {
  _ptk_base_menu_link_check_expanded($link);
}

function ptk_base_menu_link_update($link) {
  _ptk_base_menu_link_check_expanded($link);
}

/**
 * This function is altering the node form. In the form tab at the bottom called
 * "Menu settings", when checked, it replaces the menu links provided by Drupal
 * with the menu links from the current domain.
 *
 * @param array $form
 *   Form to alter
 * @param array $form_state
 *   Unused
 */
function ptk_base_add_domain_menu(&$form, &$form_state) {
  $main_menu = variable_get('menu_main_links_source', 'main-menu');

  $link = $form['#node']->menu;
  $type = $form['#node']->type;

  $item = $link['mlid'] ? $link : $type;

  if (!is_array($item)) {
    // If $item is not an array then it is a node type.
    // Use it as $type and prepare a dummy menu item for _menu_get_options().
    $type = $item;
    $item = array('mlid' => 0);
  }
  $options = _menu_get_options(menu_get_menus(), [$main_menu => $main_menu], $item);
  // If no possible parent menu items were found, there is nothing to display.
  if (empty($options)) {
    return;
  }
  // Populate the element with the link data.
  foreach (array('mlid', 'module', 'hidden', 'has_children', 'customized', 'options', 'expanded', 'hidden', 'parent_depth_limit') as $key) {
    $form['menu']['link'][$key] = array('#type' => 'value', '#value' => $link[$key]);
  }

  $default = ($link['mlid'] ? $link['menu_name'] . ':' . $link['plid'] : variable_get('menu_parent_' . $type, 'main-menu:0'));
  if (!isset($options[$default])) {
    $array = array_keys($options);
    $default = reset($array);
  }
  $form['menu']['link']['parent'] = array(
    '#type' => 'select',
    '#title' => t('Parent item'),
    '#default_value' => $default,
    '#options' => $options,
    '#attributes' => array('class' => array('menu-parent-select')),
  );
}

/**
 * Implements hook_node_prepare().
 */
function ptk_base_node_prepare($node) {
  $main_menu = variable_get('menu_main_links_source', 'main-menu');

  $item = array();
  if (isset($node->nid)) {
    $mlid = db_query_range("SELECT mlid FROM {menu_links} WHERE link_path = :path AND menu_name = :menu_name AND module = 'menu' ORDER BY mlid ASC", 0, 1, array(
      ':path' => 'node/' . $node->nid,
      ':menu_name' => $main_menu,
    ))->fetchField();

    // Check all allowed menus if a link does not exist in the default menu.
    if (!$mlid) {
      $mlid = db_query_range("SELECT mlid FROM {menu_links} WHERE link_path = :path AND module = 'menu' AND menu_name IN (:type_menus) ORDER BY mlid ASC", 0, 1, array(
        ':path' => 'node/' . $node->nid,
        ':type_menus' => [$main_menu],
      ))->fetchField();
    }
    if ($mlid) {
      $item = menu_link_load($mlid);
    }
  }
  // Set default values.
  $node->menu = $item + array(
      'link_title' => '',
      'mlid' => 0,
      'plid' => 0,
      'menu_name' => $main_menu,
      'weight' => 0,
      'options' => array(),
      'module' => 'menu',
      'expanded' => 0,
      'hidden' => 0,
      'has_children' => 0,
      'customized' => 0,
    );

  // Find the depth limit for the parent select.
  if (!isset($node->menu['parent_depth_limit'])) {
    $node->menu['parent_depth_limit'] = _menu_parent_depth_limit($node->menu);
  }
}

/**
 * Implements hook_form_alter().
 * @inheritdoc
 */
function ptk_base_form_alter(&$form, &$form_state, $form_id) {
  if (strpos($form_id, '_node_form')) {
    ptk_base_add_domain_menu($form, $form_state);
  }

  if ($form_id == 'views_exposed_form') {
    if (@$form_state['view'] && $form_state['view']->name == 'documents') {
      $form['field_document_type_tid']['#options'] = PTK::getDocumentsOptionsInUse($form);
    }
    if (@$form_state['view'] && $form_state['view']->name == 'solr_documents') {
      $form['field_document_type_tid']['#options'] = PTK::getDocumentsOptionsInUse($form);
    }
  }

  if ($form_id == 'entityqueue_subqueue_edit_form') {
    $form['eq_node']['und']['add']['entity']['#size'] = 140;
    $form['eq_node']['und']['add']['entity']['#title'] = t('Type few characters to search by item name');
    drupal_add_css('label {display: block !important;}', 'inline');
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