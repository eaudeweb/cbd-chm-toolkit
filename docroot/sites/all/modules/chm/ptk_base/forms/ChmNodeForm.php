<?php

class ChmNodeForm {

  /**
   * This method is called for all node forms.
   *
   * @param $form
   * @param $form_state
   */
  static function alter(&$form, &$form_state) {
    // Non-administrators does not have access to authoring information
    if (!user_access('configure chm settings')) {
      $form['author']['#access'] = FALSE;
    }
  }
}
