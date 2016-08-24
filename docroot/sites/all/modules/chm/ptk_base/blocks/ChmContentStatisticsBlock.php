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
    $q = db_select('node', 'n')->fields('n', ['type']);
    if (!empty($domain_nids)) {
      $q->condition('n.nid', $domain_nids, 'IN');
    } else {
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
    foreach ($types as $machine_name => $type) {
      if (variable_get("{$this->delta}_{$machine_name}_hide", 0) == 0) {
        if (!empty($count[$machine_name])) {
          $label = variable_get("{$this->delta}_{$machine_name}_title");
          $url = variable_get("{$this->delta}_{$machine_name}_url");
          $icon = variable_get("{$this->delta}_{$machine_name}_icon");
          $label = $count[$machine_name] . ' ' . (!empty($label) ? t($label) : t($type->name));
          $name = !empty($url) ? l($label, $url, ['html' => TRUE]) : $label;
          $content['rows'][] = [
            $icon ? $icon . $name : $name,
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
        '#title' => 'Hide ' . $type->name,
      ];
      $array["{$machine_name}_title"] = [
        '#type' => 'textfield',
        '#title' => 'Label',
        '#size' => 30,
        '#maxlength' => 128,
      ];
      $array["{$machine_name}_url"] = [
        '#type' => 'textfield',
        '#title' => 'Page URL',
        '#size' => 60,
        '#maxlength' => 128,
      ];
      $array["{$machine_name}_icon"] = [
        '#type' => 'textfield',
        '#title' => ' Icon',
        '#size' => 60,
        '#maxlength' => 128,
        '#description' => t("HTML can be entered here (ex. <span class='fa fa-video-o'></span>"),
      ];
    }
    return $array;
  }

  public function configure() {
    $form = parent::configure();
    $form[$this->delta] = [
      '#type' => 'fieldset',
      '#title' => 'Content types settings',
      '#collapsible' => FALSE,
      '#weight' => -100,
    ];
    $types = node_type_get_types();
    foreach ($types as $machine_name => $type) {
      $form[$this->delta][$machine_name] = [
        '#type' => 'fieldset',
        '#title' => $type->name,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      ];
      $form[$this->delta][$machine_name]["{$this->delta}_{$machine_name}_hide"] = $form["{$this->delta}_{$machine_name}_hide"];
      $form[$this->delta][$machine_name]["{$this->delta}_{$machine_name}_title"] = $form["{$this->delta}_{$machine_name}_title"];
      $form[$this->delta][$machine_name]["{$this->delta}_{$machine_name}_url"] = $form["{$this->delta}_{$machine_name}_url"];
      $form[$this->delta][$machine_name]["{$this->delta}_{$machine_name}_icon"] = $form["{$this->delta}_{$machine_name}_icon"];
      unset($form["{$this->delta}_{$machine_name}_hide"]);
      unset($form["{$this->delta}_{$machine_name}_title"]);
      unset($form["{$this->delta}_{$machine_name}_url"]);
      unset($form["{$this->delta}_{$machine_name}_icon"]);
    }
    return $form;
  }
}
