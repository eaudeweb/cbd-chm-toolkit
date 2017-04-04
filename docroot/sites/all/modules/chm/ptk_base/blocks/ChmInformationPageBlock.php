<?php

namespace Drupal\ptk_base\blocks;

class ChmInformationPageBlock extends AbstractBlock {

  public function info() {
    // <none> - title
    return [
      'chm_information_page' => [
        'info' => t('Information page block'),
        'status' => TRUE,
        'region' => 'content',
        'cache' => DRUPAL_NO_CACHE,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'pages' => 'node/995
node/1011
node/2561
node/4130
node/5742
node/6456
node/6463
node/6470
node/6477
node/6484
node/6491
node/6498
node/6505
node/6512
node/6519
node/6526
node/6533
node/6540
node/6547
node/6554
node/6561
node/6568
node/6575
node/6582
node/6589
node/11783
node/11789
node/11795
node/11851
node/11857
node/11863
node/11869
node/11900
node/22117
',
        'weight' => 1,
      ],
    ];
  }

  public function view() {
    return self::getContent();
  }

  public static function getContent() {
    $content = '';

    $main_menu = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    foreach($main_menu as $item) {
      if (@$item['#title'] == 'Information') {
        $item['#below']['#theme_wrappers'] = array('menu_tree__primary');
        $content = render($item['#below']);
        $content = str_replace('menu nav navbar-nav', 'menu nav', $content);
      }
    }
    $ret = [
      'subject' => NULL,
      'content' => $content,
    ];
    return $ret;
  }
}
