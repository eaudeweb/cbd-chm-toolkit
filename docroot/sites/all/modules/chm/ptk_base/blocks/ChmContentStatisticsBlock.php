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
    return self::cacheGet(__METHOD__, array('Drupal\ptk_base\blocks\ChmContentStatisticsBlock', 'getContent'));
  }

  public static function getContent() {
    global $_domain;
    $domain_id = $_domain['domain_id'];
    $types = node_type_get_types();
    $domain_nids = db_select('domain_access', 'da')
      ->fields('da', ['nid'])
      ->condition('realm', 'domain_id')
      ->condition('da.gid', $domain_id)
      ->execute()->fetchCol();
    $q = db_select('node', 'n')->fields('n', ['type']);
    if (!empty($domain_nids)) {
      $q->condition('n.nid', $domain_nids, 'IN');
    }
    else {
      $q->condition('n.nid', -1);
    }
    $q->groupBy('n.type');
    $q->addExpression('COUNT(*)', 'count');
    $count = $q->execute()->fetchAllKeyed();
    $content = [
      'empty' => t('No statistics available'),
      'rows' => [],
      'header' => [],
    ];
    $delta = 'chm_content_statistics';
    $rows = array();
    foreach ($types as $machine_name => $type) {
      $hide = variable_get($delta . '_' . $machine_name . '_hide', 0);
      if (empty($hide) && !empty($count[$machine_name])) {
        $c = $count[$machine_name];
        $url = variable_get("{$delta}_{$machine_name}_url");
        $icon = variable_get("{$delta}_{$machine_name}_icon");
        $singular = variable_get("{$delta}_{$machine_name}_singular");
        $plural = variable_get("{$delta}_{$machine_name}_plural");
        $weight = variable_get("{$delta}_{$machine_name}_weight");
        $label = $c . ' ' . format_plural($c, !empty($singular) ? $singular : $type->name, !empty($plural) ? $plural : $type->name);
        if (!empty($url)) {
          if (arg(0) != $url) {
            $rows[$weight] = [l($icon . $label, $url, ['html' => TRUE])];
          }
          else {
            $rows[$weight] = [$icon . $label];
          }
        }
        else {
          $rows[$weight] = [$icon . $label];
        }
      }
    }
    ksort($rows);
    $content['rows'] = $rows;
    $content['context'] = [
      'hover' => FALSE,
      'striped' => FALSE,
    ];
    $ret = [
      'subject' => t('Content Statistics'),
      'content' => theme('table', $content),
    ];
    return $ret;
  }

  public function configure() {
    $form = array('#theme' => 'ptk_base_chm_content_statistics_block_config_form');
    $form[$this->delta] = [
      '#type' => 'fieldset',
      '#title' => t('Configure display'),
      '#collapsible' => FALSE,
      '#weight' => -100,
    ];
    $types = node_type_get_types();
    $rows = array();
    foreach ($types as $machine_name => $type) {
      $form[$this->delta]['#tree'] = TRUE;
      $rows[$machine_name] = [
        'name' => ['#markup' => check_plain($type->name)],
        'hide' => [
          '#type' => 'checkbox',
          '#default_value' => variable_get($this->delta . '_' . $machine_name . '_hide'),
        ],
        'singular' => [
          '#type' => 'textfield',
          '#size' => 25,
          '#default_value' => variable_get($this->delta . '_' . $machine_name . '_singular'),
        ],
        'plural' => [
          '#type' => 'textfield',
          '#size' => 25,
          '#default_value' => variable_get($this->delta . '_' . $machine_name . '_plural'),
        ],
        'url' => [
          '#type' => 'textfield',
          '#size' => 30,
          '#default_value' => variable_get($this->delta . '_' . $machine_name . '_url'),
        ],
        'icon' => [
          '#type' => 'textfield',
          '#size' => 40,
          '#default_value' => variable_get($this->delta . '_' . $machine_name . '_icon'),
        ],
        'weight' => [
          '#type' => 'weight',
          '#default_value' => variable_get($this->delta . '_' . $machine_name . '_weight', 0),
          '#delta' => 20,
          '#attributes' => array('class' => array('item-row-weight')),
        ],
      ];
    }
    uasort($rows, function($a, $b) {
      return $a['weight']['#default_value'] > $b['weight']['#default_value'];
    });
    $form[$this->delta] += $rows;
    return $form;
  }

  public function save($edit) {
    foreach ($edit['chm_content_statistics'] as $machine_name => $values) {
      foreach ($values as $key => $value) {
        $name = $this->delta . '_' . $machine_name . '_' . $key;
        variable_set($name, $value);
      }
    }
  }
}
