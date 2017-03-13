<?php


class ChmUserProfileFormForm {

  static function alter(&$form, $form_state) {
    if (!empty($form['locale']['language'])) {
      $form['locale']['#weight'] = 100;
    }
  }
}