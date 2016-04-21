<?php

/**
 * @file
 * Contains Drupal\ptk_base\CHMPortal.
 *
 * Part of the ptk_base module test cases.
 */

namespace Drupal\ptk_base;

/**
 * Class CHMPortal is registered as service 'chm.ptk' and provides access to
 * portal global functionality.
 *
 * <code>
 * \Drupal::service('chm.ptk')->getCountry()
 * </code>
 *
 * @package Drupal\ptk_base
 */
class CHMPortal {

  public function getCountry() {
    if ($iso = \Drupal::config('chm.ptk')->get('country')) {
      return country_taxonomy_load_by_iso($iso);
    }
    return NULL;
  }

  public function setCountry($iso) {
    /** @var \Drupal\Core\Config\Config $config */
    $config = \Drupal::service('config.factory')->getEditable('chm.ptk');
    $config->set('country', $iso)->save();
  }
}
