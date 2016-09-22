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
  $path_breadcrumb->machine_name = 'first_level_menu_node_pages';
  $path_breadcrumb->name = 'First level menu node pages';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
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
            'paths' => 'biodiversity
strategy
implementation
information
participate
about',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['first_level_menu_node_pages'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_biodiversity_facts';
  $path_breadcrumb->name = 'Listing biodiversity facts';
  $path_breadcrumb->path = 'facts';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_biodiversity_facts'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_ecosystems';
  $path_breadcrumb->name = 'Listing ecosystems';
  $path_breadcrumb->path = 'ecosystems';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_ecosystems'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_events';
  $path_breadcrumb->name = 'Listing events';
  $path_breadcrumb->path = 'events';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_events'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_library';
  $path_breadcrumb->name = 'Listing library';
  $path_breadcrumb->path = 'library';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_library'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_links';
  $path_breadcrumb->name = 'Listing links';
  $path_breadcrumb->path = 'links';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_links'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_national_targets';
  $path_breadcrumb->name = 'Listing national targets';
  $path_breadcrumb->path = 'national-targets';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_national_targets'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_network_directory';
  $path_breadcrumb->name = 'Listing network directory';
  $path_breadcrumb->path = 'network-directory';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_network_directory'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_news';
  $path_breadcrumb->name = 'Listing news';
  $path_breadcrumb->path = 'news';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_news'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_photo_galleries';
  $path_breadcrumb->name = 'Listing photo galleries';
  $path_breadcrumb->path = 'photo-galleries';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_photo_galleries'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_projects';
  $path_breadcrumb->name = 'Listing projects';
  $path_breadcrumb->path = 'projects';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_projects'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_protected_areas';
  $path_breadcrumb->name = 'Listing protected areas';
  $path_breadcrumb->path = 'protected-areas';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_protected_areas'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_species';
  $path_breadcrumb->name = 'Listing species';
  $path_breadcrumb->path = 'species';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_species'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'listing_videos';
  $path_breadcrumb->name = 'Listing videos';
  $path_breadcrumb->path = 'videos';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Information',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'information',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['listing_videos'] = $path_breadcrumb;

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
  $path_breadcrumb->weight = -95;
  $export['search_page'] = $path_breadcrumb;

  return $export;
}
