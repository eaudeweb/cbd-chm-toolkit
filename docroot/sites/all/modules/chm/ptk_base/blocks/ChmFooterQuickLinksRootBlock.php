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
    return self::getContent();
//    return self::cacheGet(__METHOD__, array('Drupal\ptk_base\blocks\ChmFooterQuickLinksRootBlock', 'getContent'));
  }

  public static function getContent() {
    $domain = domain_get_domain();
    if ($domain['domain_id'] == \PTKDomain::getDefaultDomainId()) {
      $menu_links = menu_tree_all_data('main-menu');
      $items = [];
      foreach ($menu_links as $link) {
        $link = $link['link'];
        if ($link['depth'] == 1 && empty($link['hidden'])) {
          $items[] = l(_i18n_menu_link_title($link), $link['link_path']);
        }
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
