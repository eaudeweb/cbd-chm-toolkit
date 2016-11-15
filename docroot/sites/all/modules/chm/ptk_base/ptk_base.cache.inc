<?php

namespace Drupal\ptk_base;

trait DomainAwareCacheableTrait {

  public static function cacheGet($key, $callable) {
    global $_domain;
    $lifetime = variable_get('cache_lifetime');
    if ($lifetime == 0) {
      return call_user_func($callable);
    }
    $domain_id = $_domain['domain_id'];
    $cache_key = $key . '_' . $domain_id;
    if (!$cache = cache_get($cache_key)) {
      $ret = call_user_func($callable);
      cache_set($cache_key, $ret, 'cache', time() + $lifetime);
    }
    else {
      $ret = $cache->data;
    }
    return $ret;
  }
}
