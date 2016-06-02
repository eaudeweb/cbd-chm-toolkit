<?php

function ptk_base_admin_page_content_types_overview() {
  $ret = [
    'download' => [
      '#type' => 'markup',
      '#markup' => l(t('Download Excel report'), 'admin/reports/content_types_overview/export', ['attributes' => ['class' => ['hidden-print']]]),
    ],
  ];
  $types = node_type_get_types();
  ksort($types);
  foreach ($types as $machine_name => $type) {
    $fields = field_info_instances('node', $machine_name);
    $ret[$machine_name]['title'] = [
      '#type' => 'markup',
      '#markup' => '<h2>' . $type->name . ' (' . $machine_name . ')' . '</h2>' ,
    ];
    $table = [
      '#theme' => 'table',
      '#header' => [
        [ 'data' => 'FIELD NAME', 'class' => 'col-1' ],
        [ 'data' => 'MACHINE NAME', 'class' => 'col-2' ],
        [ 'data' => 'DESCRIPTION', 'class' => 'col-3' ],
        [ 'data' => 'DATA TYPE', 'class' => 'col-4' ],
        [ 'data' => 'CARDINALITY', 'class' => 'col-5' ],
      ],
      '#rows' => []
    ];
    foreach ($fields as $field_name => $field_data) {
      $fi = field_info_field($field_name);
      $cardinality = $fi['cardinality'] == -1 ? 'unlimited' : format_plural($fi['cardinality'], '@count value', '@count values');
      $row = [
        [ 'data' => $field_data['label'] ],
        [ 'data' => $field_name ],
        [ 'data' => $field_data['description'] ],
        [ 'data' => $fi['type'] ],
        [ 'data' => $cardinality ],
      ];
      $table['#rows'][] = $row;
    }
    $ret[$machine_name]['table'] = $table;
    $ret['#attached']['css'] = [
      'content_types_report' => drupal_get_path('module', 'ptk_base') . '/css/content_types_report.css',
    ];
  }
  return $ret;
}

function ptk_base_admin_page_export_content_types_overview() {
  module_load_include('inc', 'phpexcel');
  libraries_load('PHPExcel');

  // Create new PHPExcel object
  $objPHPExcel = new \PHPExcel();
  // Set document properties
  $objPHPExcel->getProperties()->setCreator("CHM portal")
    ->setLastModifiedBy("CHM portal")
    ->setTitle("Content types overview")
    ->setSubject("Content types overview")
    ->setDescription("Export of the content types defined in the CHM portal")
    ->setKeywords("drupal structure");

  $types = node_type_get_types();
  ksort($types);
  $i = 0;
  foreach ($types as $machine_name => $type) {
    $j = 1;
    $fields = field_info_instances('node', $machine_name);
    $sheet = new \PHPExcel_Worksheet();
    $sheet->setTitle($machine_name);
    foreach ($fields as $field_name => $field_data) {
      $fi = field_info_field($field_name);
      $cardinality = $fi['cardinality'] == -1 ? 'unlimited' : format_plural($fi['cardinality'], '@count value', '@count values');
      if ($j == 1) {
        $sheet->setCellValue('A1', t('Field name'));
        $sheet->setCellValue('B1', t('Machine name'));
        $sheet->setCellValue('C1', t('Description'));
        $sheet->setCellValue('D1', t('Data type'));
        $sheet->setCellValue('E1', t('Cardinality'));
      }
      if (!empty($field_data['label'])) {
        $sheet->setCellValue('A' . $j, $field_data['label']);
      }
      if (!empty($field_name)) {
        $sheet->setCellValue('B' . $j, $field_name);
      }
      if (!empty($field_data['description'])) {
        $sheet->setCellValue('C' . $j, $field_data['description']);
      }
      if (!empty($fi['type'])) {
        $sheet->setCellValue('D' . $j, $fi['type']);
      }
      if ($j > 1) {
        $sheet->setCellValue('E' . $j, $cardinality);
      }
      $j++;
    }
    $objPHPExcel->addSheet($sheet);
    $i++;
  }
  $objPHPExcel->removeSheetByIndex(0);
  // Set active sheet index to the first sheet, so Excel opens this as the first sheet
  $objPHPExcel->setActiveSheetIndex(0);
  // Redirect output to a client’s web browser (Excel2007)
  header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
  header('Content-Disposition: attachment;filename="content_types_overview.xlsx"');
  header('Cache-Control: max-age=0');
  $objWriter = \PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel2007');
  $objWriter->save('php://output');
  die();
}


function ptk_base_admin_page_configure_portal_global_settings() {
  $domain = domain_get_domain();
  $form = [ '#tree' => TRUE, ];
  $form['warning'] = [
    '#type' => 'item',
    '#markup' => t('Configuration for <strong>!portal_name</strong>', array('!portal_name' => $domain['sitename']))
  ];
  $form += PTKForm::socialMediaForm($form, array());
  $form['ptk']['protected_planet_id'] = [
    '#type' => 'textfield',
    '#title' => t('Protected planet country ID'),
    '#default_value' => PTK::variable_realm_get('ptk_protected_planet_id'),
  ];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => 'Save'
  ];
  return $form;
}

function ptk_base_admin_page_configure_portal_global_settings_validate($form, $form_state) {
}

function ptk_base_admin_page_configure_portal_global_settings_submit($form, $form_state) {
  $values = $form_state['values'];
  PTKForm::socialMediaFormSubmit($form, $form_state, domain_get_domain());
  PTK::variable_realm_set('ptk_protected_planet_id', $values['ptk']['protected_planet_id']);
}

/**
 * Populate new domain with sample content and menus
 */
function ptk_base_domain_content_config($domain) {
  module_load_include('inc', 'ptk_base', 'include/forms');
  drupal_set_title('Populate domain with sample content and menus');
  return drupal_get_form('ptk_base_domain_content_config_form', $domain);
}
