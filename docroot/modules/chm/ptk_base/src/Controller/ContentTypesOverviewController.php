<?php

/**
 * @file
 * Contains \Drupal\ptk_base\Controller\ContentTypesOverviewController.
 */

namespace Drupal\ptk_base\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Field\Annotation\FieldType;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Field\FieldTypePluginManager;
use Drupal\field\Entity\FieldStorageConfig;


class ContentTypesOverviewController extends ControllerBase {

  public function content() {
    $ret = [];

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

}