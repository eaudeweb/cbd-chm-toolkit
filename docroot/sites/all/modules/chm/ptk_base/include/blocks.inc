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
  }


  public static function chm_footer_quick_links_root() {
  }

  public static function chm_footer_quick_links() {
  }


  public static function chm_footer_follow_us() {
  }

  public static function chm_footer_country_links() {
  }
}
