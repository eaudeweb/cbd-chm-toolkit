<?php

namespace Drupal\ptk_base\blocks;

class ChmFooterFollowUsBlock extends AbstractBlock {

  public function info() {
    return [
      'chm_footer_follow_us' => [
        'info' => t('Follow Us'),
        'status' => TRUE,
        'region' => 'footer_col_4',
        'cache' => DRUPAL_NO_CACHE,
        'visibility' => BLOCK_VISIBILITY_NOTLISTED,
        'pages' => '',
        'weight' => 1,
      ],
    ];
  }

  public function configure() {
    if (user_access('configure chm website settings')) {
      return array(
        'info' => array(
          '#type' => 'item',
          '#markup' => t('To configure this website\'s social media links !click_here.', array('!click_here' => l(t('click here'), 'admin/config/system/chm_website_settings')))
        ),
      );
    }
  }

  public function view() {
    $domain = domain_get_domain();
    $realm_name = 'domain';
    $realm_key = $domain['machine_name'];
    $items = [];
    if ($link = variable_realm_get($realm_name, $realm_key, 'ptk_social_facebook')) {
      $items[] = l(t('Facebook'), $link,
        ['attributes' => ['target' => '_blank', 'class' => ['fa', 'fa-facebook']]]
      );
    }
    if ($link = variable_realm_get($realm_name, $realm_key, 'ptk_social_linkedin')) {
      $items[] = l(t('LinkedIn'), $link,
        ['attributes' => ['class' => ['fa', 'fa-linkedin']]]
      );
    }
    if ($link = variable_realm_get($realm_name, $realm_key, 'ptk_social_twitter')) {
      $items[] = l(t('Twitter'), $link,
        ['attributes' => ['class' => ['fa', 'fa-twitter']]]
      );
    }
    if ($link = variable_realm_get($realm_name, $realm_key, 'ptk_social_youtube')) {
      $items[] = l(t('Youtube'), $link,
        ['attributes' => ['class' => ['fa', 'fa-youtube']]]
      );
    }
    if (!empty($items)) {
      $config = [
        'type' => 'ul',
        'attributes' => array('class' => ['menu', 'nav']),
        'items' => $items,
      ];
      return [
        'subject' => t('Social Media'),
        'content' => theme('item_list', $config),
      ];
    }
    else {
      return NULL;
    }
  }

}
