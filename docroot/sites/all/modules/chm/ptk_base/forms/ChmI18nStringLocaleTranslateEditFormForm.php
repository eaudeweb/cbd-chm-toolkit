<?php

class ChmI18nStringLocaleTranslateEditFormForm {

  static function alter(&$form, &$form_state) {
    $form['override-warning'] = array(
      '#type' => 'item',
      '#markup' => '<div class="messages warning">' . t('This change affects the translation in <em>all</em> CHM websites') . '</div>',
      '#weight' => -99
    );
  }
}