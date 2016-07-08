<?php

class IUCNRedListAPI {

  private $serviceUrl = NULL;
  private $apiToken= NULL;
  private static $DEFAULT_REMOTE_CALL_DELAY = 300;

  static function instance() {
    $url = variable_get('iucnredlist_url');
    $key = variable_get('iucnredlist_apikey');
    if (empty($url) || empty($key)) {
      throw new Exception('RedList API is not correctly configured');
    }
    return new IUCNRedListAPI($url, $key);
  }

  public function __construct($serviceUrl, $apiToken) {
    $this->serviceUrl = $serviceUrl;
    $this->apiToken = $apiToken;
  }

  function getRemoteSpeciesTaxonomicIDsForCountry($iso) {
    $url = $this->getEndpointUrl() . '/country/getspecies/' . strtoupper($iso) . '?token=' . $this->getApiToken();
    $data = $this->getRemoteJSON($url);
    return !empty($data->result) && is_array($data->result) ? $data->result : array();
  }

  /**
   * Retrieve remote species record.
   *
   * Example: http://apiv3.iucnredlist.org/api/v3/species/id/12392?token=XXXX
   *
   * @param integer $taxonid
   *   Species unique taxonomic ID
   *
   * @return object
   *   Species record from the remote service
   */
  function getRemoteSpeciesRecord($taxonid) {
    $url = sprintf('%s/species/id/%s?token=%s', $this->getEndpointUrl() , $taxonid, $this->getApiToken());
    $data = $this->getRemoteJSON($url);
    return !empty($data->result) && is_array($data->result) ? $data->result[0] : NULL;
  }

  function getRemoteJSON($url, $headers = array()) {
    $ret = NULL;
    if ($data = $this->getRemoteData($url, $headers)) {
      $ret = json_decode($data);
    }
    return $ret;
  }

  function getRemoteData($url, $headers) {
    // Check the delay between calls
    $delay = variable_get('iucnredlist_calldelay', 300);
    if (empty($delay) || $delay < self::$DEFAULT_REMOTE_CALL_DELAY) {
      $delay = self::$DEFAULT_REMOTE_CALL_DELAY;
    }
    $delay = $delay * 1000; // microseconds
    $last_call = variable_get('iucnredlist_lastcalltimestamp', microtime(TRUE));
    $now = microtime(TRUE);
    if (($now - $last_call) < $delay) {
      usleep($delay);
    }

    $default_headers = array('Accept' => 'application/json');
    if (empty($headers)) {
      $headers = $default_headers;
    }
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 10);
    curl_setopt($ch, CURLOPT_TIMEOUT, 400);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($ch, CURLOPT_NOBODY, 0);
    if (function_exists('drush_log')) {
      drush_log(strtr('Loading data from @url', array('@url' => $url)), \Drush\Log\LogLevel::INFO);
    } else {
      watchdog('iucn_redlist', 'Loading data from @url', array('@url' => $url), WATCHDOG_INFO);
    }
    $ret = curl_exec($ch);
    $info = curl_getinfo($ch);
    if ($info['http_code'] != 200) {
      $code = $info['http_code'];
      module_invoke_all('iucn_redlist_log', 'HTTP error @code while getting data from @url', array('@code' => $code, '@url' => $url), WATCHDOG_ERROR);
      $ret = NULL;
    }
    curl_close($ch);
    variable_set('iucnredlist_lastcalltimestamp', microtime(TRUE));
    return $ret;
  }

  function getEndpointUrl() {
    return $this->serviceUrl;
  }

  function getApiToken() {
    return $this->apiToken;
  }


  function populateCountrySpecies($iso) {
    $species = $this->getRemoteSpeciesTaxonomicIDsForCountry($iso);
    db_delete('iucn_redlist_species_country')->condition('iso', $iso)->execute();
    foreach ($species as $row) {
      $record = array('taxonid' => $row->taxonid);
      db_merge('iucn_redlist_species')->key($record)->fields($record)->execute();
      $record = array('taxonid' => $row->taxonid, 'iso' => $iso);
      db_merge('iucn_redlist_species_country')->key($record)->fields($record)->execute();
    }
  }

  function getLocalSpeciesIDs() {
    $q = db_select('iucn_redlist_species', 'a')->fields('a', array('taxonid'));
    return $q->execute()->fetchCol();
  }
}
