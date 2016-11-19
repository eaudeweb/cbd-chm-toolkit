<?php

namespace Drupal\ptk_base\blocks;

use Drupal\ptk_base\DomainAwareCacheableTrait;

abstract class AbstractBlock {

  use DomainAwareCacheableTrait;

  protected $delta;

  public function __construct() {
    $info = $this->info();
    $this->delta = key($info);
  }

  /**
   * If the delta is chm_content_statistics the class name should be
   * ChmContentStatisticsBlock.
  */
  static function getBlockClassName($delta) {
    $klass = str_replace(' ', '', ucwords(str_replace('_', ' ', $delta))) . 'Block';
    if (strpos($klass, 'Chm') === FALSE) {
      $klass = 'Chm' . $klass;
    }
    $klass = 'Drupal\\ptk_base\\blocks\\' . $klass;
    return $klass;

  }

  /**
   * Implements hook_block_info().
   */
  abstract public function info();

  /**
   * Implements hook_block_view().
   */
  abstract public function view();

  /**
   * Implementes hook_block_view_alter().
   *
   * @param array $data
   *   Block output
   * @param object $block
   *   Block object
   */
  public function alter(&$data, $block) {}

  /**
   * An array containing the settings of the block.
   * The return array should be based on Drupal's form api.
   * Each item will be created within block's configure form and will be saved
   * in the database as a variable. (Variable names will have the following
   * format: $block_delta . '_' . $setting_name)
   *
   * @return array
   */
  protected function settings() {
    return [];
  }

  /**
   * Implements hook_block_configure().
   */
  public function configure() {
    $form = [];
    foreach ($this->settings() as $name => $setting) {
      $name = $this->delta . '_' . $name;
      if (is_array($setting)) {
        $form[$name] = $setting;
        $form[$name]['#default_value'] = variable_get($name);
      }
      else {
        watchdog('ptk_base_blocks', 'Invalid settings array', [], WATCHDOG_WARNING);
      }
    }
    return $form;
  }

  /**
   * Implements hook_block_save().

   * @param array $edit
   */
  public function save($edit) {
    foreach ($this->settings() as $name => $setting) {
      $name = $this->delta . '_' . $name;
      variable_set($name, $edit[$name]);
    }
  }
}
