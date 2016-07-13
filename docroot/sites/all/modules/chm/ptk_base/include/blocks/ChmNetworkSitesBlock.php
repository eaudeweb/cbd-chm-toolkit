<?php

namespace Drupal\ptk_base\blocks;

class ChmNetworkSitesBlock extends AbstractBlock {

  public function info() {
    return [
      'chm_network_sites' => [
        'info' => t('National CHM Training Sites'),
        'status' => TRUE,
        'region' => 'content',
        'cache' => DRUPAL_CACHE_GLOBAL,
        'visibility' => BLOCK_VISIBILITY_LISTED,
        'pages' => 'chm-network',
        'weight' => 1,
      ],
    ];
  }

  public function view() {
    $content = [
      'empty' => 'There are no domains defined',
      'header' => ['', t('National CHM Site'), t('URL')],
      'rows' => [],
    ];
    $domains = domain_domains();
    $default_did = \PTKDomain::getDefaultDomainId();
    foreach ($domains as $id => $domain) {
      $flag_image = '';
      $label = str_replace(array(
        'https://',
        'http://',
        '/'
      ), '', $domain['path']);
      if (!empty($domain['valid']) && $id != $default_did) {
        if ($country = \PTKDomain::getPortalCountry($domain)) {
          if ($flag = \PTK::getCountryFlagURL($country)) {
            $flag_image = theme('image', array('path' => $flag, 'width' => 30));
          }
        }
        $content['rows'][] = [
          $flag_image,
          $domain['sitename'],
          l($label, $domain['path']),
        ];
      }
    }
    $ret = array(
      'subject' => t('National CHM Training Sites'),
      'content' => theme('table', $content),
    );
    return $ret;
  }

}
