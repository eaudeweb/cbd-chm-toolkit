<?php
/**
 * @file
 * chm_structure.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function chm_structure_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_d38b0274-09f9-4ff7-b110-30051e66d8b0';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Event page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'event' => 'event',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
        ),
        'parent' => NULL,
        'class' => 'node-event-detail',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0.5em',
        'row_separation' => '0.5em',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
          1 => 3,
        ),
        'class' => 'container',
        'hide_empty' => 1,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 1,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 4,
          1 => 7,
        ),
        'parent' => '1',
        'class' => 'row',
        'hide_empty' => 1,
      ),
      4 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 6,
          1 => 9,
          2 => 10,
        ),
        'class' => 'col-sm-8',
        'hide_empty' => 1,
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
        ),
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 8,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left 1',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
        'hide_empty' => 0,
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 11,
          1 => 12,
          2 => 15,
        ),
        'parent' => '4',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_3',
        ),
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_3' => array(
        'type' => 'region',
        'title' => 'Left 3',
        'width' => 100,
        'width_type' => '%',
        'parent' => '10',
        'class' => '',
        'hide_empty' => 0,
      ),
      11 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '9',
        'children' => array(
          0 => 13,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      12 => array(
        'type' => 'column',
        'width' => 25,
        'width_type' => '%',
        'parent' => '9',
        'children' => array(
          0 => 14,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_2___left',
        ),
        'parent' => '11',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_2___left' => array(
        'type' => 'region',
        'title' => 'Left 2 - left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
        'hide_empty' => 0,
      ),
      14 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_2___right',
        ),
        'parent' => '12',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_2___right' => array(
        'type' => 'region',
        'title' => 'Left 2 - right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '14',
        'class' => '',
        'hide_empty' => 0,
      ),
      15 => array(
        'type' => 'column',
        'width' => 25,
        'width_type' => '%',
        'parent' => '9',
        'children' => array(
          0 => 16,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      16 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left__left_2',
        ),
        'parent' => '15',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left__left_2' => array(
        'type' => 'region',
        'title' => 'Left 2 right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '16',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'right' => NULL,
      'left' => NULL,
      'left_3' => NULL,
      'left_2' => NULL,
      'left_2___left' => NULL,
      'left_2___right' => NULL,
      'left__left_2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = 'cbabb6f5-307c-424f-b532-c4cd7b78452c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ba03ef63-23d2-40eb-8de4-98e2627ccf91';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_dates';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'long',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
        'show_remaining_days' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ba03ef63-23d2-40eb-8de4-98e2627ccf91';
    $display->content['new-ba03ef63-23d2-40eb-8de4-98e2627ccf91'] = $pane;
    $display->panels['left'][0] = 'new-ba03ef63-23d2-40eb-8de4-98e2627ccf91';
    $pane = new stdClass();
    $pane->pid = 'new-0f51bfc0-bc14-4c58-9a52-218c98755fe5';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_address';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'addressfield_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'use_widget_handlers' => 1,
        'format_handlers' => array(
          'address' => 'address',
        ),
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0f51bfc0-bc14-4c58-9a52-218c98755fe5';
    $display->content['new-0f51bfc0-bc14-4c58-9a52-218c98755fe5'] = $pane;
    $display->panels['left'][1] = 'new-0f51bfc0-bc14-4c58-9a52-218c98755fe5';
    $pane = new stdClass();
    $pane->pid = 'new-29469a76-96d8-48e0-81db-3cc98a66408b';
    $pane->panel = 'left_2___left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_status';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'i18n_taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '29469a76-96d8-48e0-81db-3cc98a66408b';
    $display->content['new-29469a76-96d8-48e0-81db-3cc98a66408b'] = $pane;
    $display->panels['left_2___left'][0] = 'new-29469a76-96d8-48e0-81db-3cc98a66408b';
    $pane = new stdClass();
    $pane->pid = 'new-301f81bf-8595-4da0-9a70-a5315c2367b1';
    $pane->panel = 'left_2___right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'i18n_taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '301f81bf-8595-4da0-9a70-a5315c2367b1';
    $display->content['new-301f81bf-8595-4da0-9a70-a5315c2367b1'] = $pane;
    $display->panels['left_2___right'][0] = 'new-301f81bf-8595-4da0-9a70-a5315c2367b1';
    $pane = new stdClass();
    $pane->pid = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
    $pane->panel = 'left_3';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0e195d4e-168f-4220-85bd-4f7d51c778c2';
    $display->content['new-0e195d4e-168f-4220-85bd-4f7d51c778c2'] = $pane;
    $display->panels['left_3'][0] = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
    $pane = new stdClass();
    $pane->pid = 'new-532b5895-367a-453f-b23c-28345b855f3c';
    $pane->panel = 'left__left_2';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_url';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'link_url',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '532b5895-367a-453f-b23c-28345b855f3c';
    $display->content['new-532b5895-367a-453f-b23c-28345b855f3c'] = $pane;
    $display->panels['left__left_2'][0] = 'new-532b5895-367a-453f-b23c-28345b855f3c';
    $pane = new stdClass();
    $pane->pid = 'new-dc4a0d57-0beb-4edf-8458-e75058a39845';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'large',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'dc4a0d57-0beb-4edf-8458-e75058a39845';
    $display->content['new-dc4a0d57-0beb-4edf-8458-e75058a39845'] = $pane;
    $display->panels['right'][0] = 'new-dc4a0d57-0beb-4edf-8458-e75058a39845';
    $pane = new stdClass();
    $pane->pid = 'new-eeafd3d1-31de-4167-9166-dabe53c87cc5';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_geolocation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'geofield_map_map',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'data' => 'full',
        'geofield_map_width' => '100%',
        'geofield_map_height' => '300px',
        'geofield_map_zoom' => '12',
        'geofield_map_min_zoom' => '0',
        'geofield_map_max_zoom' => '0',
        'geofield_map_controltype' => 'default',
        'geofield_map_mtc' => 'standard',
        'geofield_map_pancontrol' => 1,
        'geofield_map_maptype' => 'map',
        'geofield_map_baselayers_map' => 1,
        'geofield_map_baselayers_satellite' => 1,
        'geofield_map_baselayers_hybrid' => 1,
        'geofield_map_baselayers_physical' => 0,
        'geofield_map_scale' => 0,
        'geofield_map_overview' => 0,
        'geofield_map_overview_opened' => 0,
        'geofield_map_scrollwheel' => 0,
        'geofield_map_draggable' => 0,
        'geofield_map_streetview_show' => 0,
        'geofield_map_center' => array(
          'lat' => '',
          'lon' => '',
          'geocode' => 'Find my location',
        ),
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'eeafd3d1-31de-4167-9166-dabe53c87cc5';
    $display->content['new-eeafd3d1-31de-4167-9166-dabe53c87cc5'] = $pane;
    $display->panels['right'][1] = 'new-eeafd3d1-31de-4167-9166-dabe53c87cc5';
    $pane = new stdClass();
    $pane->pid = 'new-7609b3ca-2216-49e4-ad71-71db394504a8';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-events-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Upcoming events',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7609b3ca-2216-49e4-ad71-71db394504a8';
    $display->content['new-7609b3ca-2216-49e4-ad71-71db394504a8'] = $pane;
    $display->panels['right'][2] = 'new-7609b3ca-2216-49e4-ad71-71db394504a8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_d38b0274-09f9-4ff7-b110-30051e66d8b0'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function chm_structure_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'main_home_page';
  $page->task = 'page';
  $page->admin_title = 'Main home-page';
  $page->admin_description = '';
  $page->path = 'main-home-page';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_main_home_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'main_home_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Homepage',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'domain',
          'settings' => array(
            'domain_site' => 1,
            'domains' => array(
              'www' => 'www',
            ),
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 2,
          1 => 3,
        ),
        'parent' => 'main',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'children' => array(
          0 => 4,
        ),
        'class' => 'col-md-6',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '1',
        'children' => array(
          0 => 5,
        ),
        'class' => 'col-md-6',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_column',
        ),
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_column' => array(
        'type' => 'region',
        'title' => 'Left Column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right_column',
        ),
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right_column' => array(
        'type' => 'region',
        'title' => 'Right Column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left_column' => NULL,
      'right_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8d5f2b78-d4be-4f7b-8681-2b0ea0edbd46';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d59e6d6e-f130-4822-8cc3-562d212027dc';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'views-home_page_image_slider-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd59e6d6e-f130-4822-8cc3-562d212027dc';
    $display->content['new-d59e6d6e-f130-4822-8cc3-562d212027dc'] = $pane;
    $display->panels['center'][0] = 'new-d59e6d6e-f130-4822-8cc3-562d212027dc';
    $pane = new stdClass();
    $pane->pid = 'new-9d425136-b488-4705-8a0a-f5317a62ff8e';
    $pane->panel = 'left_column';
    $pane->type = 'block';
    $pane->subtype = 'views-latest_updates-block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9d425136-b488-4705-8a0a-f5317a62ff8e';
    $display->content['new-9d425136-b488-4705-8a0a-f5317a62ff8e'] = $pane;
    $display->panels['left_column'][0] = 'new-9d425136-b488-4705-8a0a-f5317a62ff8e';
    $pane = new stdClass();
    $pane->pid = 'new-d4245c41-4586-43de-8bc8-9361383f8303';
    $pane->panel = 'right_column';
    $pane->type = 'block';
    $pane->subtype = 'ptk_base-chm_content_statistics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd4245c41-4586-43de-8bc8-9361383f8303';
    $display->content['new-d4245c41-4586-43de-8bc8-9361383f8303'] = $pane;
    $display->panels['right_column'][0] = 'new-d4245c41-4586-43de-8bc8-9361383f8303';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-d59e6d6e-f130-4822-8cc3-562d212027dc';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['main_home_page'] = $page;

  return $pages;

}
