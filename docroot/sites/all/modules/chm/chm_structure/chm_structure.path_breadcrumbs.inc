<?php
/**
 * @file
 * chm_structure.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function chm_structure_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'biodiversity';
  $path_breadcrumb->name = 'Biodiversity';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Biodiversity',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'url_alias_domain',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'biodiversity',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -97;
  $export['biodiversity'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'implementation';
  $path_breadcrumb->name = 'Implementation';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Implementation',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'url_alias_domain',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'implementation',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -100;
  $export['implementation'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_page';
  $path_breadcrumb->name = 'Search page';
  $path_breadcrumb->path = 'search';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Search',
      1 => '!search_term',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'search',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -99;
  $export['search_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'strategy';
  $path_breadcrumb->name = 'Strategy';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Strategy',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'url_alias_domain',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'strategy',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -98;
  $export['strategy'] = $path_breadcrumb;

  return $export;
}
