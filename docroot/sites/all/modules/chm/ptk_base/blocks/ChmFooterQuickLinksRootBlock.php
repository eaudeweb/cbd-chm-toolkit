<?php

namespace Drupal\ptk_base\blocks;

class ChmFooterQuickLinksRootBlock extends AbstractBlock {

  public function info() {
    return [
      'chm_footer_quick_links_root' => [
        'info' => t('Footer quick links for root domain'),
        'status' => TRUE,
        'region' => 'footer_col_1',
        'cache' => DRUPAL_NO_CACHE,
        'visibility' => BLOCK_VISIBILITY_NOTLISTED,
        'pages' => '',
        'weight' => 1,
      ],
    ];
  }

  public function view() {
    $domain = domain_get_domain();
    if ($domain['domain_id'] == \PTKDomain::getDefaultDomainId()) {
      $items = [];
      $link_home = domain_get_uri($domain);
      $items[] = l(t('Home'), $link_home);
      if ($link = l(t('Network'), 'chm-network')) {
        $items[] = $link;
      }
      if ($link = l(t('Guidance'), 'guidance')) {
        $items[] = $link;
      }
      if ($link = l(t('Tools'), 'tools')) {
        $items[] = $link;
      }
      if ($link = l(t('About Us'), 'about')) {
        $items[] = $link;
      }
      $config = [
        'type' => 'ul',
        'attributes' => array('class' => ['menu', 'nav']),
        'items' => $items,
      ];
      $ret = [
        'subject' => t('Quick Links'),
        'content' => theme('item_list', $config),
      ];
      return $ret;
    }
    return '';
  }

}
