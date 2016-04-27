<?php

function ptk_base_admin_page_content_types_overview() {
  $ret = [
    'download' => [
      '#type' => 'markup',
      '#markup' => l(t('Download Excel report'), 'admin/reports/content_types_overview/export')
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
        [ 'data' => t('Field name') ],
        [ 'data' => t('Machine name') ],
        [ 'data' => t('Description') ],
        [ 'data' => t('Data type') ],
        [ 'data' => t('Cardinality') ],
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
    $ret[$machine_name]['fieldset'] = [
      '#type' => 'fieldset',
      '#title' => t('Information'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ];
    $ret[$machine_name]['fieldset']['table'] = $table;
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
