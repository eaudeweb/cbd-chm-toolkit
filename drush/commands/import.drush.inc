<?php

/**
 * Implements hook_drush_command().
 */
function import_drush_command() {
  $items = array();
  $items['import-chm-sites'] = array(
    'description' => 'Script to import xls data as content type ‘CHM Site’',
    'callback' => '_drush_prepare_import_chm_sites',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'examples' => array(
      'drush import-chm-sites /path/to/excel/file' => 'Import xls data as content type ‘CHM Site’',
    ),
    'arguments' => array(
      'path' => 'Path to excel file',
    ),
  );
  $items['import-gef-countrycodes'] = array(
    'description' => 'Assign GEF country codes to each country',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'examples' => array(
      'drush import-gef-countrycodes' => 'Assign all countries',
    ),
  );
  return $items;
}

function _drush_prepare_import_chm_sites($path = NULL) {
  if (!file_exists($path)) {
    drupal_set_message(t('File !path does not exists!', array('!path'=>$path)), 'error');
    return ;
  }
  libraries_load('PHPExcel');
  //  Read your Excel workbook
  try {
    $inputFileType = PHPExcel_IOFactory::identify($path);
    $objReader = PHPExcel_IOFactory::createReader($inputFileType);
    $objPHPExcel = $objReader->load($path);
  } catch(Exception $e) {
    drupal_set_message('Error loading file "'.pathinfo($path, PATHINFO_BASENAME).'": '.$e->getMessage(), 'error');
    return ;
  }

  $sheet = $objPHPExcel->getSheet(0); 
  $highestRow = $sheet->getHighestRow(); 
  $highestColumn = $sheet->getHighestColumn();
  $highestColumnIndex = PHPExcel_Cell::columnIndexFromString($highestColumn); 
  $objWorksheet = $objPHPExcel->setActiveSheetIndexbyName('QD_Countries_CHM');

  // header names
  $headers = array();
  for ($col = 0; $col <= $highestColumnIndex; ++$col) {
    $value = $objWorksheet->getCellByColumnAndRow($col, 1)->getValue();
    if ($value) {
      $headers[$col] = $value;
    }
  }

  $items = array();
  for ($row = 2; $row <= $highestRow; $row++) {
    $item = array();
    foreach($headers as $col => $header) {
      $value = $objWorksheet->getCellByColumnAndRow($col, $row)->getValue();
      $item[$header] = $value;
    }
    if (!$item['country_chm_web']) {
      continue;
    }
    $items[] = $item;
  }

  foreach ($items as $item) {
    import_drush_create_chm_site($item);
  }

  $total = count($items);  
  drupal_set_message("Total = $total");
}

function import_drush_create_chm_site($item) {
  $node_attributes = array(
    'type' => 'chm_site',
    'title' => $item['sitename'],
    'status' => 1,
    'uid' => 1,
    'language' => 'en',
    'name' => 'chm',
    'domains' => array(PTKDomain::$CHM_DOMAIN_ID),
    'domain_site' => PTKDomain::$CHM_DOMAIN_ID,
    'field_url' => ['en' => [0 => ['url' => $item['country_chm_web']]]],
  );

  if ($status_tid = PTK::getOrCreateTermIdByName($item['country_chm_status'], 'chm_site_status', false)) {
    $node_attributes['field_chm_site_status'] = [LANGUAGE_NONE => [0 => ['tid' => $status_tid]]];
  }
  if ($country = PTK::getCountryByCode($item['country_code'])) {
    $node_attributes['field_government'] = [LANGUAGE_NONE => [0 => ['tid' => $country->tid]]];
  }
  else {
    drush_log('Missing country: ' . $item['country_code'], 'warn');
    drupal_set_message('Missing country: ' . $item['country_code'], 'error');
    return ;
  }
  $node_attributes['title'] = $country->name;
  $node = (object) $node_attributes;
  node_object_prepare($node);
  node_save($node);
  drush_log('Adding: ' . $node_attributes['title'], 'ok');
}

function drush_import_gef_countrycodes() {
  require_once dirname(__FILE__) . '/_gef_countries.inc';
  global $gef_country_codes;
  foreach ($gef_country_codes as $name => $gef_id) {
    if ($cid = PTK::getCountryByName($name)) {
      $country = taxonomy_term_load($cid);
      $country->field_gef_id[LANGUAGE_NONE][0]['value'] = $gef_id;
      taxonomy_term_save($country);
    }
    else {
      drush_log('Missing country: ' . $name, 'warn');
    }
  }
}
