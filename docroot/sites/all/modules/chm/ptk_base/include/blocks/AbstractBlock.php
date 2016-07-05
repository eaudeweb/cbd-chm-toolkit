<?php

namespace Drupal\ptk_base\blocks;

abstract class AbstractBlock {

  /**
   * Implements hook_block_view().
   */
  abstract public function view();

  /**
   * Implements hook_block_configure().
   */
  public function configure() {
  }

  /**
   * Implements hook_block_save().
   */
  public function save() {
  }
}
