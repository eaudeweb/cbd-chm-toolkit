<?php

class ChmUserLoginForm {

  static function alter(&$form, &$form_alter) {
    $form['#attributes']['class'][] = 'form';
  }
}