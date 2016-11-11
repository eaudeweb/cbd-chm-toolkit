<?php

/**
 * Implementation of hook_views_plugins()
 */
function amcharts_views_plugins() {
  $plugin = array(
    'module' => 'amcharts',
    'style' => array(
      'ammap' => array(
        'title' => t('Ammap countries map'),
        'help' => t('Display highlighted countries on world map'),
        'handler' => 'views_plugin_style_amcharts_ammap_world_countries',
        'theme' => 'views_view_amcharts_ammap_world_countries',
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
      ),
    ),
  );
  return $plugin;
}
