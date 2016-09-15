<?php


class ChmUserAdminAccountForm {
  static function alter(&$form, &$form_state) {
    if (variable_get('environment') == 'test') {
      $form['warning'] = array(
        '#type' => 'item',
        '#markup' => '<p style="border: 1px solid red; height: 20px; padding: 10px; font-weight: bold;">USERS ARE HIDDEN AS THEY ARE SHARED FROM PRODUCTION TO ALLOW AUTHENTICATION</p>',
        '#weight' => 0,
      );
      unset($form['accounts']);
    }
  }
}