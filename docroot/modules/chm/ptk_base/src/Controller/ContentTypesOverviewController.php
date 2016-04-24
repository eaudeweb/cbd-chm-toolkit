<?php

/**
 * @file
 * Contains \Drupal\ptk_base\Controller\ContentTypesOverviewController.
 */

namespace Drupal\ptk_base\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Field\FieldTypePluginManager;
use Drupal\Core\Link;


class ContentTypesOverviewController extends ControllerBase {

  public function content() {
    $d = Link::createFromRoute($this->t('Download Excel report'), 'ptk_base.admin.content_types_overview.export');
    $ret = [
      'download' => [
        '#type' => 'markup',
        '#markup' => $d->toString()
      ],
    ];

    $ctypes = \Drupal::entityTypeManager()->getStorage('node_type')->loadMultiple();
    ksort($ctypes);

    /** @var FieldTypePluginManager $fts */
    $fts = \Drupal::service('plugin.manager.field.field_type');
    $field_definitions = $fts->getDefinitions();
    foreach ($ctypes as $machine_name => $ctype) {
      $ret[$machine_name]['title'] = [
        '#type' => 'markup',
        '#markup' => '<h2>' . $ctype->label() . ' (' . $machine_name . ')' . '</h2>' ,
      ];
      $fields = \Drupal::service('entity_field.manager')->getFieldDefinitions('node', $machine_name);
      $table = [
        '#type' => 'table',
        '#header' => [
          [ 'data' => t('Field name') ],
          [ 'data' => t('Machine name') ],
          [ 'data' => t('Description') ],
          [ 'data' => t('Data type') ],
        ],
        '#rows' => []
      ];
      /** @var BaseFieldDefinition $field_data */
      foreach ($fields as $field_name => $field_data) {
        $fd = $field_definitions[$field_data->getType()];
        $row = [
          [ 'data' => $field_data->getLabel() ],
          [ 'data' => $field_data->getName() ],
          [ 'data' => $field_data->getDescription() ],
          [ 'data' => $fd['label']->render() ],
        ];
        $table['#rows'][] = $row;
      }
      $ret[$machine_name]['fieldset'] = [
        '#type' => 'details',
        '#title' => t('Information'),
        '#open' => FALSE,
      ];
      $ret[$machine_name]['fieldset']['table'] = $table;
    }

    return $ret;
  }

  public function export() {
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


    $ctypes = \Drupal::entityTypeManager()->getStorage('node_type')->loadMultiple();
    ksort($ctypes);

    /** @var FieldTypePluginManager $fts */
    $fts = \Drupal::service('plugin.manager.field.field_type');
    $field_definitions = $fts->getDefinitions();
    $objPHPExcel->setActiveSheetIndex(0);
    $i = 0;
    foreach ($ctypes as $machine_name => $ctype) {
      $j = 1;
      $sheet = new \PHPExcel_Worksheet();
      $sheet->setTitle($machine_name);
      $fields = \Drupal::service('entity_field.manager')->getFieldDefinitions('node', $machine_name);
      /** @var BaseFieldDefinition $field_data */
      foreach ($fields as $field_name => $field_data) {
        if ($j == 1) {
          $sheet->setCellValue('A1', 'Field name');
          $sheet->setCellValue('B1', 'Machine name');
          $sheet->setCellValue('C1', 'Description');
          $sheet->setCellValue('D1', 'Data type');
        }
        $fd = $field_definitions[$field_data->getType()];
        if ($s = $field_data->getLabel()) {
          $sheet->setCellValue('A' . $j, is_object($s) ? $s->render() : $s);
        }
        if ($s = $field_data->getName()) {
          $sheet->setCellValue('B' . $j, is_object($s) ? $s->render() : $s);
        }
        if ($s = $field_data->getDescription()) {
          $sheet->setCellValue('C' . $j, is_object($s) ? $s->render() : $s);
        }
        if (!empty($fd['label']) && $label = $fd['label']) {
          $sheet->setCellValue('D' . $j, is_object($label) ? $label->render() : $label);
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
}
