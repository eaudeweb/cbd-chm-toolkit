<?php

namespace Drupal\ptk_base\blocks;

class ChmContentStatisticsBlock extends AbstractBlock {

  public function getDelta() {
    return 'chm_content_statistics';
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
      if (!empty($count[$machine_name])) {
        $content['rows'][] = [
          $count[$machine_name],
          $type->name,
        ];
      }
    }
    $ret = [
      'subject' => t('Content Statistics'),
      'content' => theme('table', $content),
    ];
    return $ret;
  }

  protected function settings() {
    return [];
  }

}
