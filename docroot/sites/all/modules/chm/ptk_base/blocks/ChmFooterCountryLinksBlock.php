<?php

namespace Drupal\ptk_base\blocks;

class ChmFooterCountryLinksBlock extends AbstractBlock {

  public function info() {
    return [
      'chm_footer_country_links' => [
        'info' => t('Country links'),
        'status' => TRUE,
        'region' => 'footer_col_3',
        'cache' => DRUPAL_NO_CACHE,
        'visibility' => BLOCK_VISIBILITY_NOTLISTED,
        'pages' => '',
        'weight' => 1,
      ],
    ];
  }

  public function view() {
    $domain = domain_get_domain();
    $domain_id = $domain['domain_id'];
    if ($domain_id != \PTKDomain::getDefaultDomainId()) {
      $block_title = t('Country links');
      $country = \PTKDomain::getPortalCountry($domain);
      // We must link the domain to a country otherwise the block is empty
      if ($domain_id == \PTKDomain::$DEMO_DOMAIN_ID) {
        $country = \PTK::getCountryByCode('AL');
      }
      $items = [];
      // GEF
      if ($country) {
        $block_title = $country->name;
        $link = sprintf('https://www.thegef.org/gef/project_list?countryCode=%s&focalAreaCode=B&op=Search', strtoupper($country->iso2l));
        $items[] = l(t('GEF Projects'), $link, ['attributes' => ['target' => '_blank']]);
      }
      // Protected planet
      if ($id = \PTKDomain::variable_get('ptk_protected_planet_id')) {
        // @todo: Make this configurable form the back-end
        $link = 'http://www.protectedplanet.net/search?country=' . $id;
        $items[] = l(t('Protected areas (protectedplanet.net)'), $link,
          ['attributes' => ['target' => '_blank']]
        );
      }
      if ($country) {
        $link = sprintf('https://www.cbd.int/countries/?country=%s', strtolower($country->iso2l));
        $items[] = l(t('CBD Country Profile'), $link, ['attributes' => ['target' => '_blank']]);

        $link = sprintf('http://www.informea.org/countries/%s', strtolower($country->iso2l));
        $items[] = l(t('InforMEA Country Profile'), $link, ['attributes' => ['target' => '_blank']]);

        $link = sprintf('http://uneplive.unep.org/country/index/%s', strtoupper($country->iso2l));
        $items[] = l(t('UNEP Country Profile'), $link, ['attributes' => ['target' => '_blank']]);

        $link = sprintf('http://data.un.org/CountryProfile.aspx?crName=%s', $country->name);
        $items[] = l(t('United Nations Country Profile'), $link, ['attributes' => ['target' => '_blank']]);
      }
      $config = [
        'type' => 'ul',
        'attributes' => array('class' => ['menu', 'nav']),
        'items' => $items,
      ];
      // We must link the domain to a country otherwise the block is empty
      if ($domain_id == \PTKDomain::$DEMO_DOMAIN_ID) {
        $block_title = 'Bioland';
      }
      $ret = [
        'subject' => $block_title,
        'content' => theme('item_list', $config),
      ];
      return $ret;
    }
    return '';
  }

}
