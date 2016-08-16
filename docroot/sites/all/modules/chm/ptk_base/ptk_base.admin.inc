<?php

function ptk_base_admin_page_system_report() {
  $attributes = array('class' => array('links', 'site-menu'));
  $ret = theme('links', array('links' => menu_navigation_links('management', 3), 'attributes' => $attributes));
  if (empty($ret)) {
    $ret = 'No system report available';
  }
  return $ret;
}

function ptk_base_admin_page_content_types_overview() {
  $ret = [
    'download' => [
      '#type' => 'markup',
      '#markup' => l(t('Download Excel report'), 'admin/reports/chm/types/export', ['attributes' => ['class' => ['hidden-print']]]),
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

function ptk_base_admin_page_taxonomies_overview() {
  $ret = [
    'download' => [
      '#type' => 'markup',
      '#markup' => l(t('Download Excel report'), 'admin/reports/chm/taxonomy/export', ['attributes' => ['class' => ['hidden-print']]]),
    ],
  ];
  $vocabularies = taxonomy_get_vocabularies();
  uasort($vocabularies, function($a, $b) { return strcmp($a->name, $b->name); });

  foreach ($vocabularies as $vid => $voc) {
    $ret['voc_' . $vid]['title'] = [
      '#type' => 'markup',
      '#markup' => '<h2>' . $voc->name . ' (' . $voc->machine_name . ')</h2>' ,
    ];
    $table = [
      '#theme' => 'table',
      '#header' => [
        [ 'data' => 'Term', 'class' => 'col-1' ],
        [ 'data' => 'Description', 'class' => 'col-2' ],
      ],
      '#rows' => []
    ];
    if ($terms = taxonomy_get_tree($vid)) {
      uasort($terms, function($a, $b) { return strcmp($a->name, $b->name);});
      foreach ($terms as $term) {
        $row = [
          ['data' => $term->name],
          ['data' => $term->description],
        ];
        $table['#rows'][] = $row;
      }
      $ret['tbl_' . $vid]['table'] = $table;
    }
    else {
      $ret['tbl_' . $vid]['table'] = array('#type' => 'markup', '#markup' => 'No terms in this vocabulary');
    }
    $ret['#attached']['css'] = [
      'content_types_report' => drupal_get_path('module', 'ptk_base') . '/css/taxonomies_report.css',
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
        $sheet->setCellValue('C1', t('Field type'));
        $sheet->setCellValue('D1', t('Cardinality'));
        $sheet->setCellValue('E1', t('Description'));
        $j++;
      }
      if (!empty($field_data['label'])) {
        $sheet->setCellValue('A' . $j, $field_data['label']);
      }
      if (!empty($field_name)) {
        $sheet->setCellValue('B' . $j, $field_name);
      }
      if (!empty($fi['type'])) {
        $sheet->setCellValue('C' . $j, $fi['type']);
      }
      if ($j > 1) {
        $sheet->setCellValue('D' . $j, $cardinality);
      }
      if (!empty($field_data['description'])) {
        $sheet->setCellValue('E' . $j, $field_data['description']);
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


function ptk_base_admin_page_export_taxonomies_overview() {
  module_load_include('inc', 'phpexcel');
  libraries_load('PHPExcel');

  // Create new PHPExcel object
  $objPHPExcel = new \PHPExcel();
  // Set document properties
  $objPHPExcel->getProperties()->setCreator("CHM portal")
    ->setLastModifiedBy("CHM portal")
    ->setTitle("Taxonomies overview")
    ->setSubject("Taxonomies overview")
    ->setDescription("Export of the taxonomy content defined in the CHM portal")
    ->setKeywords("drupal taxonomy");

  $vocabularies = taxonomy_get_vocabularies();
  uasort($vocabularies, function($a, $b) { return strcmp($a->name, $b->name); });
  foreach ($vocabularies as $vid => $voc) {
    $j = 1;
    $sheet = new \PHPExcel_Worksheet();
    $sheet->setTitle($voc->name);
    if ($terms = taxonomy_get_tree($vid)) {
      uasort($terms, function ($a, $b) {
        return strcmp($a->name, $b->name);
      });
      //@todo: Add translations if available
      foreach ($terms as $term) {
        if ($j == 1) {
          $sheet->setCellValue('A1', t('Term'));
          $sheet->setCellValue('B1', t('Description'));
          $j++;
        }
        else {
          $sheet->setCellValue('A' . $j, $term->name);
          if (!empty($term->description)) {
            $sheet->setCellValue('B' . $j, $term->description);
          }
        }
        $j++;
      }
      $objPHPExcel->addSheet($sheet);
    }
  }
  $objPHPExcel->removeSheetByIndex(0);
  // Set active sheet index to the first sheet, so Excel opens this as the first sheet
  $objPHPExcel->setActiveSheetIndex(0);
  // Redirect output to a client’s web browser (Excel2007)
  header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
  header('Content-Disposition: attachment;filename="taxonomies_overview.xlsx"');
  header('Cache-Control: max-age=0');
  $objWriter = \PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel2007');
  $objWriter->save('php://output');
  die();
}

/**
 * Populate new domain with sample content and menus
 */
function ptk_base_domain_content_config($domain) {
  module_load_include('inc', 'ptk_base', 'include/forms');
  drupal_set_title('Populate domain with sample content and menus');
  return drupal_get_form('ptk_base_domain_content_config_form', $domain);
}

function ptk_base_chm_global_settings_form() {
  $form = [];
  $form['cbd_ratification_xml_url'] = [
    '#type' => 'textfield',
    '#title' => t('URL to CBD ratification XML file'),
    '#default_value' => variable_get('cbd_ratification_xml_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  ];
  $form['cartagena_ratification_xml_url'] = [
    '#type' => 'textfield',
    '#title' => t('URL to Cartagena Biosafety Protocol ratification XML file'),
    '#default_value' => variable_get('cartagena_ratification_xml_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  ];
  $form['nagoya_ratification_xml_url'] = [
    '#type' => 'textfield',
    '#title' => t('URL to Nagoya Protocol ratification XML file'),
    '#default_value' => variable_get('nagoya_ratification_xml_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  ];
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

function ptk_base_chm_global_settings_form_submit($form, $form_state) {
  $variables = [
    'cbd_ratification_xml_url',
    'cartagena_ratification_xml_url',
    'nagoya_ratification_xml_url',
  ];
  foreach ($variables as $variable) {
    variable_set($variable, $form_state['values'][$variable]);
  }
}

function ptk_base_chm_website_settings_form() {
  module_load_include('inc', 'domain_variable', 'domain_variable.admin');
  $form = domain_variable_admin_variables(domain_get_domain());
  return system_settings_form($form);
}
