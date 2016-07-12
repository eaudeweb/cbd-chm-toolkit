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
    'fr' => 2,
    'es' => 4,
    'ar' => 6,
    'ru' => 8,
    'zh-hans' => 10,
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

  foreach ($data as $key => $row) {
    $id = $row[$columns['en']];
    $parent = NULL;
    if (empty($id)) {
      continue;
    }
    if (preg_match('/Goal (\d*).*/', $id, $matches)) {
      $id = $matches[1];
    }
    else {
      $parent = explode('.', $id)[0];
    }
    if (!empty($existing_goals[$id])) {
      $term = is_numeric($existing_goals[$id]) ? taxonomy_term_load($existing_goals[$id]) : $existing_goals[$id];
    }
    else {
      $term = new stdClass();
      $term->vid = $voc->vid;
      $term->language = 'en';
    }
    $name = $row[$columns['en']] . ' ' . $row[$columns['en'] + 1];
    $term->name = strlen($name) > 255 ? substr($name, 0, 252) . '...' : $name;
    $term->name_field = [];
    $term->field_official_name = [];
    $term->field_index = [
      LANGUAGE_NONE => [
        0 => [
          'value' => $id,
        ],
      ],
    ];
    foreach ($columns as $lang => $colNum) {
      $name_field = $row[$columns[$lang]] . ' ' . $row[$columns[$lang] + 1];
      if ($lang == 'ar') {
        $name_field = $row[$columns[$lang] + 1] . ' ' . $row[$columns[$lang]];
      }
      $term->name_field[$lang] = [
        0 => [
          'value' => $name_field,
        ],
      ];
      $term->field_official_name[$lang] = [
        0 => [
          'value' => $row[$columns[$lang] + 1],
        ],
      ];
    }
    if (!empty($parent)) {
      $term->parent = $parent;
    }
    taxonomy_term_save($term);

    $handler = entity_translation_get_handler('taxonomy_term', $term);
    $handler->setOriginalLanguage('en');
    $handler->initTranslations();
    foreach ($columns as $lang => $colNum) {
      if ($lang == 'en') {
        continue;
      }
      $handler->setTranslation([
        'translate' => 0,
        'status' => 1,
        'uid' => 1,
        'language' => $lang,
        'source' => 'en',
      ]);
    }
    taxonomy_term_save($term);

    drush_log('Imported: ' . $row[$columns['en']], 'success');

    $existing_goals[$id] = $term;
  }
}