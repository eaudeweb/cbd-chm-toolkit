<?php

class IUCNRedListAPI {

  private $serviceUrl = NULL;
  private $apiToken= NULL;

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

  function getSpeciesTaxonomicIDsForCountry($iso) {
    $url = $this->getEndpointUrl() . '/country/getspecies/' . strtoupper($iso) . '?token=' . $this->getApiToken();
    $data = $this->getRemoteJSON($url);
    return !empty($data->result) && is_array($data->result) ? $data->result : array();
  }

  function getRemoteJSON($url, $headers = array()) {
    $ret = NULL;
    if ($data = $this->getRemoteData($url, $headers)) {
      $ret = json_decode($data);
    }
    return $ret;
  }


  function getRemoteData($url, $headers) {
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
    $ret = curl_exec($ch);
    $info = curl_getinfo($ch);
    if ($info['http_code'] != 200) {
      $code = $info['http_code'];
      watchdog('iucn_redlist', "Error $code while getting data from $url", array(), WATCHDOG_ERROR);
      $ret = NULL;
    }
    curl_close($ch);
    return $ret;
  }


  function getEndpointUrl() {
    return $this->serviceUrl;
  }

  function getApiToken() {
    return $this->apiToken;
  }


  function populateCountrySpecies($iso) {
    $species = $this->getSpeciesTaxonomicIDsForCountry($iso);
    db_delete('iucn_redlist_species_country')->condition('iso', $iso)->execute();
    foreach ($species as $row) {
      $record = array('taxonid' => $row->taxonid);
      db_merge('iucn_redlist_species')->key($record)->fields($record)->execute();
      $record = array('taxonid' => $row->taxonid, 'iso' => $iso);
      db_merge('iucn_redlist_species_country')->key($record)->fields($record)->execute();
    }
  }
}
