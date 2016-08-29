<?php


class ChmDomainDeleteFormForm {

  static function alter(&$form) {
    array_unshift($form['#submit'], array('ChmDomainDeleteFormForm', 'submit'));
  }

  /**
   * Cleanup the domain after during deletion.
   * @todo cristiroma: delete the corresponding pages?
   * @todo cristiroma: remove pages from block visibility assignments
   * <ul>
   *   <li>Delete the main menu</li>
   * </ul>
   */
  static function submit($form, $form_state) {
    if (!empty($form_state['values']['domain'])) {
      $domain = $form_state['values']['domain'];
      if ($menu = menu_load('menu-main-menu-' . $domain['machine_name'])) {
        menu_delete($menu);
      };
      $country = PTKDomain::getPortalCountry($domain);
      if ($menu = menu_load('menu-main-menu-' . $country->iso2l)) {
        menu_delete($menu);
      };
    }
  }
}
