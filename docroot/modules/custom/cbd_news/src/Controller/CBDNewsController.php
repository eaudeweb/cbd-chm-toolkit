<?php

/**
 * @file
 * Contains \Drupal\cbd_news\Controller\CBDNewsController.
 */

namespace Drupal\cbd_news\Controller;

use Drupal\Core\Controller\ControllerBase;

/**
 * Controller routines for cbd_news.
 *
 * @ingroup cbd_news
 */
class CBDNewsController extends ControllerBase {

  /**
   * A simple controller method to explain what this module is about.
   */
  public function description() {
    $build = array(
      '#markup' => t(
          '<p>Use this node type to create a news content item.</p>' .
          '<p>This module contains the functionality of the news items throughout the website</p>' .
          '<p>Should you uninstall this module, the content node type will remain with all the content, but will be possible to delete everything</p>'
      ),
    );
    return $build;
  }
}
