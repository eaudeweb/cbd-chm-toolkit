<?php

namespace Drupal\ptk_base\blocks;

class ChmFooterQuickLinksBlock extends AbstractBlock {

  public function info() {
    return [
      'chm_footer_quick_links' => [
        'info' => t('Footer quick links'),
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
    return self::cacheGet(__METHOD__, array('Drupal\ptk_base\blocks\ChmFooterQuickLinksBlock', 'getContent'));
  }

  public static function getContent() {
    $domain = domain_get_domain();
    if ($domain['domain_id'] != \PTKDomain::getDefaultDomainId()) {
      $items = [];
      $link_home = domain_get_uri($domain);
      $items[] = l(t('Home'), $link_home);
      if ($link = l(t('Biodiversity'), 'biodiversity')) {
        $items[] = $link;
      }
      if ($link = l(t('Strategy'), 'strategy')) {
        $items[] = $link;
      }
      if ($link = l(t('Implementation'), 'implementation')) {
        $items[] = $link;
      }
      if ($link = l(t('Information'), 'information')) {
        $items[] = $link;
      }
      if ($link = l(t('Participate'), 'participate')) {
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
