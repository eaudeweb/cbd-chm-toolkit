<?php

function chm_sdg_drush_command() {
  $items = array();

  $items['chm-sdg-full-import'] = array(
    'drupal dependencies' => array('phpexcel'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'description' => 'SDG Full Import',
    'aliases' => array('sdg-fi'),
  );

  return $items;
}

/**
 * Imports SDG goals, targets & indicators from SDGs.xlsx file.
 */
function drush_chm_sdg_full_import() {
  $voc = taxonomy_vocabulary_machine_name_load('sdg');
  $columns = [
    'en' => 0,
    'fr' => 3,
    'es' => 5,
    'ar' => 7,
    'ru' => 9,
    'zh-hans' => 11,
  ];
  module_load_include('inc', 'phpexcel');
  $path = drupal_get_path('module', 'chm_sdg') . '/data/SDGs.xlsx';
  $data = phpexcel_import($path, FALSE)[0];
  if (!is_array($data)) {
    drush_log("We could not get the data from the excel file.", 'error');
    return;
  }

  $existing_goals = db_select('field_data_field_index', 'i')
    ->fields('i', ['field_index_value', 'entity_id'])
    ->condition('i.bundle', 'sdg')
    ->execute()->fetchAllKeyed();

  $goals = [];

  foreach ($data as $key => $row) {
    $id = $row[$columns['en']];
    $parent = NULL;
    if (empty($id)) {
      continue;
    }
    if (preg_match('/Goal (\d).*/', $id, $matches)) {
      $id = $matches[1];
    }
    else {
      $parent = explode('.', $id)[0];
    }
    if (!empty($existing_goals[$id])) {
      $term = taxonomy_term_load($existing_goals[$id]);
    }
    else {
      $term = new stdClass();
      $term->vid = $voc->vid;
      $term->language = 'en';
    }
    $term->name_field = [
      'ar' => [
        0 => [
          'value' => '',
        ],
      ],
    ];
  }
}