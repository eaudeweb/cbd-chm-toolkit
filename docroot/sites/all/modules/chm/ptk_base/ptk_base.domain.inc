<?php

class PTKDomain {

  public static $CHM_DOMAIN_ID = 1;
  public static $DEMO_DOMAIN_ID = 3;

  /**
   * Get the ID of default domain
   *
   * @return integer
   *   ID of the default domain
   */
  public static function getDefaultDomainId() {
    if ($domain = self::getDefaultDomain()) {
      return $domain['domain_id'];
    }
    return NULL;
  }

  public static function isDefaultDomain($domain) {
    $self = domain_get_domain();
    if (!empty($self['domain_id']) && !empty($domain['domain_id'])) {
      return $self['domain_id'] == $domain['domain_id'];
    }
    return FALSE;
  }

  /**
   * Get the ID of default domain
   *
   * @return integer
   *   ID of the default domain
   */
  public static function getDefaultDomain() {
    $all = domain_domains();
    foreach ($all as $domain) {
      if (!empty($domain['is_default']) && $domain['is_default'] == 1) {
        return $domain;
      }
    }
    return NULL;
  }

  /**
   * Retrieve the enabled languages
   */
  public static function getLanguages($domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    $ret = array('en' => 'en');
    $enabled = self::variable_get('language_list', $domain);
    if (!empty($enabled) && is_array($enabled)) {
      $enabled = array_filter($enabled);
      $ret += $enabled;
      $ret = array_values($ret);
    }
    return $ret;
  }

  /**
   * Retrieve the domain object corresponding to a country ISO code.
   * @deprecated by getDomainsByCountryISO.
   * @see PTKDomain::getDomainsByCountryISO
   */
  public static function getDomainByCountryISO($iso) {
    $all = domain_domains();
    foreach ($all as $domain_id => $domain) {
      if ($value = PTKDomain::variable_get('country', $domain)) {
        if (strtoupper($iso) == strtoupper($value)) {
          return $domain;
        }
      }
    }
    return NULL;
  }

  /**
   * Retrieve all domains configured for a country ISO code.
   */
  public static function getDomainsByCountryISO($iso) {
    static $all = NULL;
    $iso = strtoupper($iso);
    if (empty($all)) {
      $domains = domain_domains();
      foreach ($domains as $domain_id => $domain) {
        if ($value = PTKDomain::variable_get('country', $domain)) {
          $country = PTK::getCountryByCode($value);
          $iso2 = $country->iso2l;
          if (empty($all[$iso2])) {
            $all[$iso2] = array();
          }
          $all[$iso2][$domain_id] = $domain;
          $iso3 = $country->iso3l;
          if (empty($all[$iso3])) {
            $all[$iso3] = array();
          }
          $all[$iso3][$domain_id] = $domain;
        }
      }
    }
    if (array_key_exists($iso, $all)) {
      return $all[$iso];
    }
    return array();
  }

  /**
   * Retrieve all domains configured for a country term ID.
   */
  public static function getDomainsByCountryTid($tid) {
    static $all = NULL;
    if (empty($all)) {
      $domains = domain_domains();
      foreach ($domains as $domain_id => $domain) {
        if ($value = PTKDomain::variable_get('country', $domain)) {
          if ($country = PTK::getCountryByCode($value)) {
            if (empty($all[$country->tid])) {
              $all[$country->tid] = array();
            }
            $all[$country->tid][$domain_id] = $domain;
          }
        }
      }
    }
    if (array_key_exists($tid, $all)) {
      return $all[$tid];
    }
    return array();
  }

  /**
   * Get the Country of the current portal.
   *
   * @param array $domain
   *   A domain, if NULL the current domain (or default domain) is returned
   *
   * @return null|\stdClass
   *   Taxonomy term from 'countries' taxonomy for the current country
   */
  public static function getPortalCountry($domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    if ($iso = self::variable_get('country', $domain)) {
      return PTK::getCountryByCode($iso);
    }
    return NULL;
  }


  public static function variable_get($name, $domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    if (!empty($domain['domain_id'])) {
      return domain_variable_get($domain['domain_id'], $name);
    }
    return NULL;
  }

  public static function variable_set($name, $value, $domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    $realm_key = $domain['machine_name'];
    variable_realm_set('domain', $realm_key, $name, $value);
  }

  public static function set_country_treaty_data($country = NULL, $domain = NULL) {
    if (empty($domain)) {
      $domain = domain_get_domain();
    }
    if (empty($country)) {
      $country =  PTK::getCountryByCode(self::variable_get('country', $domain));
    }
    $treaties = ['cbd', 'nagoya', 'cartagena'];
    foreach ($treaties as $treaty) {
      if (!empty($url = variable_get($treaty . '_ratification_xml_url'))) {
        $ratification = self::treaty_ratification_process_xml($url);
        if (!empty($ratification) && !empty($ratification->ratification)) {
          foreach ($ratification->ratification as $item) {
            if ($item->country == $country->name) {
              $value = serialize($item);
              self::variable_set($treaty . '_ratification', $value, $domain);
            }
          }
        }
      }
    }
  }

  /**
   * @param string $url URL to the XML
   * @return stdClass Object with data extracted from XML. Fields:
   * - source_url - Original URL
   * - ratification - array with ratification information (keys are country names in English)
   */
  public static function treaty_ratification_process_xml($url) {
    $ret = new stdClass();
    $ret->source_url = $url;
    $ret->ratification = array();
    $ret->entry_into_force = NULL;
    $response = drupal_http_request($url, array(
      'headers' =>  array('Accept' => 'text/xml'),
    ));
    if (!isset($response->error)) {
      $xml_str = $response->data;
      $xml = simplexml_load_string($xml_str, 'SimpleXMLElement', LIBXML_NOEMPTYTAG);
      if ($xml === FALSE) {

        return FALSE;
      }
      if ($eif = $xml->xpath('//EIF')) {
        if (!empty($eif[0])) {
          $eif = $eif[0];
          $entry_into_force = (string)$eif->Labeltext;
          if (!empty($entry_into_force)) {
            if ($pos = strpos($entry_into_force, ',')) {
              $entry_into_force = substr($entry_into_force, 0, $pos);
            }
            if ($date = DateTime::createFromFormat('d F Y', $entry_into_force)) {
              $ret->entry_into_force = $date->getTimestamp();
            }
          }
        }
      }

      $rows = $xml->xpath('//Participants/Table/TGroup/Tbody/Rows/Row');
      if (empty($rows)) {
        $rows = $xml->xpath('//Row');
      }
      if (!empty($rows)) {
        foreach($rows as $row) {
          $warnings = '';
          $row = $row->children();
          $new_row = array((string)$row[0], (string)$row[1], (string)$row[2]);
          if (!empty($row[3])) {
            $new_row[] = (string)$row[3];
          }
          $row = $new_row;
          $country = $row[0];
          if (!empty($country)) {
            // Remove additional data from country name such as footnote references
            $country = preg_replace('/\<superscript\>.*\<\/superscript\>/', '', $country);
          }
          else {
            $warnings .= 'Could not reliably determine the country name;';
          }

          $date1 = '';
          if (!empty($row[1]) && is_string($row[1])) {
            $parsed = date_parse($row[1]);
            if ($parsed !== FALSE) {
              //@todo: Inspect error_count, errors, warning_count and warnings inside $date1p
              $date1 = date('Y-m-d', mktime(0, 0, 0, $parsed['month'], $parsed['day'], $parsed['year']));
            } else {
              $warnings = sprintf('Canot parse date1: %s', $row[1]);
            }
          } else {
            if (!empty($row[1])) {
              $warnings = 'date1 is not a string. Removed';
            }
          }

          $date2 = '';
          if (!empty($row[2]) && is_string($row[2])) {
            $parsed = date_parse($row[2]);
            if ($parsed !== FALSE) {
              //@todo: Inspect error_count, errors, warning_count and warnings inside $date2p
              $date2 = date('Y-m-d', mktime(0, 0, 0, $parsed['month'], $parsed['day'], $parsed['year']));
            } else {
              $warnings = sprintf('Cannot parse date2: %s', $row[2]);
            }
          } else {
            if (!empty($row[2])) {
              $warnings = 'date2 is not a string. Setting to empty';
            }
          }
          $status = NULL;
          if (!empty($row[3])) {
            $status = strtolower($row[3]);
          } else if(preg_match('/\ a$/', $row[2])) { // a
            $status = 'accession';
          } elseif(preg_match('/\ AA$/', $row[2])) { // AA
            $status = 'approval';
          } elseif(preg_match('/\ A$/', $row[2])) { // A
            $status = 'acceptance';
          } elseif (!empty($date2)) {
            $status = 'ratification';
          } else {
            $status = 'signatory';
          }
          $ob = new stdClass();
          $ob->country = $country;
          $ob->country_verbatim = $row[0];
          $ob->date1 = $date1;
          $ob->date1_verbatim = $row[1];
          $ob->date2 = $date2;
          $ob->date2_verbatim = $row[2];
          $ob->status = $status;
          $ob->warnings = $warnings;
          $ob->errors = array();
          $ret->ratification[] = $ob;
        }
      }
    }
    return $ret;
  }


  /**
   * Compute entity absolute URL using its original domain
   * @param int $entity_id
   * @return string
   *   Absolute URL
   */
  public static function url($entity_id) {
    $e = entity_load('node',array($entity_id));
    if(!isset($e[$entity_id])) {
      return false;
    }
    $entity = $e[$entity_id];
    $entity_uri = entity_uri('node',$entity);
    //Base url
    $base_url = self::baseDomain($entity->domains);
    return  $base_url . '/' . $entity_uri['path'];
  }

  /**
   * Compute entity html formatted absolute URL using its original domain
   * @param int $entity_id
   * @return string
   *  a href element
   */
  public static function fieldUrl($entity_id, $options = array()) {
    $url = self::url($entity_id);
    if($url) {
      return l($url, $url, $options);
    }
  }

    /**
     * Gets base domain url
     * @param $domain_id
     * @return string
     * Domain url
     */

  public static function baseDomain($entity_domains = NULL){
    static $domains = [];
    if(!$entity_domains || !is_array($entity_domains)) {
      return '';
    }
    $domain_id = array_shift($entity_domains);
    if(!$domain_id) {
      return '';
    }
    if (!$domains) {
      $all = db_query('SELECT domain_id, subdomain, scheme, valid FROM {domain} where valid=1')->fetchAll();
      foreach($all as $domain) {
        $domains[$domain->domain_id] = $domain->scheme . '://' . $domain->subdomain;
      }
    }
    return isset($domains[$domain_id]) ? $domains[$domain_id] : '';
  }
}
