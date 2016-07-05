<?php

namespace Drupal\ptk_base\blocks;

class ChmContentStatisticsBlock extends AbstractBlock {

  public function info() {
    return [
      'chm_content_statistics' => [
        'info' => t('Content Statistics'),
        'status' => TRUE,
        'region' => 'content_col2-2',
        'cache' => DRUPAL_NO_CACHE,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'pages' => '<front>',
        'weight' => 1,
      ],
    ];
  }

  public function view() {
    global $_domain;
    $types = node_type_get_types();
    $domain_nids = db_select('domain_access', 'da')
      ->fields('da', ['nid'])
      ->condition('realm', 'domain_id')
      ->condition('da.gid', $_domain['domain_id'])
      ->execute()->fetchCol();
    $q = db_select('node', 'n')
      ->condition('n.nid', $domain_nids, 'IN')
      ->fields('n', ['type']);
    $q->groupBy('n.type');
    $q->addExpression('COUNT(*)', 'count');
    $count = $q->execute()->fetchAllKeyed();
    $content = [
      'empty' => t('No statistics available'),
      'rows' => [],
    ];
    foreach ($types as $machine_name => $type) {
      if (variable_get("{$this->delta}_{$machine_name}_hide", 0) == 0) {
        if (!empty($count[$machine_name])) {
          $content['rows'][] = [
            $count[$machine_name],
            $type->name,
          ];
        }
      }
    }
    $ret = [
      'subject' => t('Content Statistics'),
      'content' => theme('table', $content),
    ];
    return $ret;
  }

  protected function settings() {
    $array = [];
    $types = node_type_get_types();
    foreach ($types as $machine_name => $type) {
      $array["{$machine_name}_hide"] = [
        '#type' => 'checkbox',
        '#title' => 'Hide',
      ];
      $array["{$machine_name}_url"] = [
        '#type' => 'textfield',
        '#title' => 'Page url',
        '#size' => 60,
        '#maxlength' => 128,
      ];
      $array["{$machine_name}_icon"] = [
        '#type' => 'textfield',
        '#title' => 'Icon url',
        '#size' => 60,
        '#maxlength' => 128,
      ];
    }
    return $array;
  }

  public function configure() {
    $form = [];
    $types = node_type_get_types();
    $form['content_types_settings'] = [
      '#type' => 'fieldset',
      '#title' => 'Content types settings',
      '#collapsible' => FALSE,
    ];
    foreach ($types as $machine_name => $type) {
      $form['content_types_settings'][$machine_name] = [
        '#type' => 'fieldset',
        '#title' => $type->name,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        "{$this->delta}_{$machine_name}_hide" => [
          '#type' => 'checkbox',
          '#title' => 'Hide',
          '#default_value' => variable_get("{$this->delta}_{$machine_name}_hide", 0),
        ],
        "{$this->delta}_{$machine_name}_url" => [
          '#type' => 'textfield',
          '#title' => 'Page url',
          '#default_value' => variable_get("{$this->delta}_{$machine_name}_url", ''),
          '#size' => 60,
          '#maxlength' => 128,
        ],
        "{$this->delta}_{$machine_name}_icon" => [
          '#type' => 'textfield',
          '#title' => 'Icon url',
          '#default_value' => variable_get("{$this->delta}_{$machine_name}_icon", ''),
          '#size' => 60,
          '#maxlength' => 128,
        ],
      ];
    }
    return $form;
  }

}
