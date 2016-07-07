<?php

class IUCNRedListAPI {

  private $serviceUrl = NULL;
  private $apiToken= NULL;

  public function __construct($serviceUrl, $apiToken) {
    $this->serviceUrl = $serviceUrl;
    $this->apiToken = $apiToken;
  }

  function getSpeciesTaxonomicIDsForCountry($iso) {
    $url = $this->getEndpointUrl() . '/country/getspecies/' . strtoupper($iso) . '?token=' . $this->getApiToken();
    return $this->getRemoteJSON($url);
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

}