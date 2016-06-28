<?php

class PTKBlocks {

  public static function render($delta) {
    if (method_exists('PTKBlocks', $delta)) {
      return PTKBlocks::$delta();
    }
    drupal_set_message(t('Invalid block render method !method', ['!method' => 'PTKBlocks::' . $delta]), 'error');
    return FALSE;
  }

  public static function chm_network_sites() {
    $content = [
      'empty' => 'There are no domains defined',
      'header' => ['', t('National CHM Site'), t('URL')],
      'rows' => [],
    ];
    $domains = domain_domains();
    $default_did = PTK::getDefaultDomainId();
    foreach ($domains as $id => $domain) {
      $flag_image = '';
      $label = str_replace(array(
        'https://',
        'http://',
        '/'
      ), '', $domain['path']);
      if (!empty($domain['valid']) && $id != $default_did) {
        if ($country = PTK::getPortalCountry($domain)) {
          if ($flag = PTK::getCountryFlagURL($country)) {
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


  public static function chm_footer_quick_links_root() {
    $domain = domain_get_domain();
    if ($domain['domain_id'] == PTK::getDefaultDomainId()) {
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
      if ($link = l(t('About Us'), 'about-us-0')) {
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

  public static function chm_footer_quick_links() {
    $domain = domain_get_domain();
    if ($domain['domain_id'] != PTK::getDefaultDomainId()) {
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
      if ($link = l(t('About Us'), 'about-us')) {
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


  public static function chm_footer_follow_us() {
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

  public static function chm_footer_country_links() {
    $domain = domain_get_domain();
    if ($domain['domain_id'] != PTK::getDefaultDomainId()) {
      $country = PTK::getPortalCountry($domain);
      $realm_name = 'domain';
      $realm_key = $domain['machine_name'];
      $items = [];
      // GEF
      if ($country) {
        $link = sprintf('https://www.thegef.org/gef/project_list?countryCode=%s&focalAreaCode=B&op=Search', strtoupper($country->iso2l));
        $items[] = l(t('GEF Projects'), $link, ['attributes' => ['target' => '_blank']]);
      }
      // Protected planet
      if ($id = variable_realm_get($realm_name, $realm_key, 'ptk_protected_planet_id')) {
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
      $ret = [
        'subject' => !empty($country) ? $country->name : 'Country links',
        'content' => theme('item_list', $config),
      ];
      return $ret;
    }
    return '';
  }
}
