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
  $handler->name = 'node_view__media-first-page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 11;
  $handler->conf = array(
    'title' => 'Media-first page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'media-first-page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'document' => 'document',
              'organization' => 'organization',
              'person' => 'person',
              'video' => 'video',
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
        'class' => 'media-first-page node-details-page',
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
          0 => 27,
          1 => 26,
          2 => 18,
          3 => 23,
        ),
        'class' => 'container',
        'hide_empty' => 1,
      ),
      18 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 19,
          1 => 20,
        ),
        'parent' => '1',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      19 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '18',
        'children' => array(
          0 => 21,
        ),
        'class' => 'col-sm-8',
        'hide_empty' => 0,
      ),
      20 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '18',
        'children' => array(
          0 => 22,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      21 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_',
        ),
        'parent' => '19',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      22 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right_',
        ),
        'parent' => '20',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right_' => array(
        'type' => 'region',
        'title' => 'Relevant Info',
        'width' => 100,
        'width_type' => '%',
        'parent' => '22',
        'class' => '',
        'hide_empty' => 0,
      ),
      23 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 24,
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      24 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '23',
        'children' => array(
          0 => 25,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      25 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'extra_content',
        ),
        'parent' => '24',
        'class' => '',
        'hide_empty' => 0,
      ),
      'extra_content' => array(
        'type' => 'region',
        'title' => 'Extra content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      26 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      27 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'header' => array(
        'type' => 'region',
        'title' => 'Header',
        'width' => 100,
        'width_type' => '%',
        'parent' => '26',
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
      'related' => NULL,
      'left_' => NULL,
      'right_' => NULL,
      'extra_content' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = 'cbabb6f5-307c-424f-b532-c4cd7b78452c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_d38b0274-09f9-4ff7-b110-30051e66d8b0';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-29e5eac7-f2f2-43e4-9c33-0777731a3a32';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_organization_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_link',
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
  $pane->uuid = '29e5eac7-f2f2-43e4-9c33-0777731a3a32';
  $display->content['new-29e5eac7-f2f2-43e4-9c33-0777731a3a32'] = $pane;
  $display->panels['header'][0] = 'new-29e5eac7-f2f2-43e4-9c33-0777731a3a32';
  $pane = new stdClass();
  $pane->pid = 'new-91ffc82a-9ae8-4164-a0d2-16509628cbaa';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_document_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_link',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '91ffc82a-9ae8-4164-a0d2-16509628cbaa';
  $display->content['new-91ffc82a-9ae8-4164-a0d2-16509628cbaa'] = $pane;
  $display->panels['header'][1] = 'new-91ffc82a-9ae8-4164-a0d2-16509628cbaa';
  $pane = new stdClass();
  $pane->pid = 'new-cf7d8a2b-be61-482d-b4b2-33b8132413ea';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_salutation';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cf7d8a2b-be61-482d-b4b2-33b8132413ea';
  $display->content['new-cf7d8a2b-be61-482d-b4b2-33b8132413ea'] = $pane;
  $display->panels['header'][2] = 'new-cf7d8a2b-be61-482d-b4b2-33b8132413ea';
  $pane = new stdClass();
  $pane->pid = 'new-1f1eed44-8979-4ef9-b153-d07effd403ad';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_last_name';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '1f1eed44-8979-4ef9-b153-d07effd403ad';
  $display->content['new-1f1eed44-8979-4ef9-b153-d07effd403ad'] = $pane;
  $display->panels['header'][3] = 'new-1f1eed44-8979-4ef9-b153-d07effd403ad';
  $pane = new stdClass();
  $pane->pid = 'new-a6cfc7e8-e19f-4e16-9d43-c1eb19bae1c3';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_first_name';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a6cfc7e8-e19f-4e16-9d43-c1eb19bae1c3';
  $display->content['new-a6cfc7e8-e19f-4e16-9d43-c1eb19bae1c3'] = $pane;
  $display->panels['header'][4] = 'new-a6cfc7e8-e19f-4e16-9d43-c1eb19bae1c3';
  $pane = new stdClass();
  $pane->pid = 'new-dc4a0d57-0beb-4edf-8458-e75058a39845';
  $pane->panel = 'left_';
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
  $display->panels['left_'][0] = 'new-dc4a0d57-0beb-4edf-8458-e75058a39845';
  $pane = new stdClass();
  $pane->pid = 'new-955c1f98-4db6-40b5-ac00-532afd24f72b';
  $pane->panel = 'left_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_video_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'video_embed_field',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'video_style' => 'normal',
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
  $pane->uuid = '955c1f98-4db6-40b5-ac00-532afd24f72b';
  $display->content['new-955c1f98-4db6-40b5-ac00-532afd24f72b'] = $pane;
  $display->panels['left_'][1] = 'new-955c1f98-4db6-40b5-ac00-532afd24f72b';
  $pane = new stdClass();
  $pane->pid = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $pane->panel = 'left_';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $display->content['new-0e195d4e-168f-4220-85bd-4f7d51c778c2'] = $pane;
  $display->panels['left_'][2] = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $pane = new stdClass();
  $pane->pid = 'new-cd407435-244a-4ac9-8fcd-9fcb66ea1524';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
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
  $pane->uuid = 'cd407435-244a-4ac9-8fcd-9fcb66ea1524';
  $display->content['new-cd407435-244a-4ac9-8fcd-9fcb66ea1524'] = $pane;
  $display->panels['right_'][0] = 'new-cd407435-244a-4ac9-8fcd-9fcb66ea1524';
  $pane = new stdClass();
  $pane->pid = 'new-b0753c3c-430c-4117-a052-97236021468b';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_files';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'file_default',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b0753c3c-430c-4117-a052-97236021468b';
  $display->content['new-b0753c3c-430c-4117-a052-97236021468b'] = $pane;
  $display->panels['right_'][1] = 'new-b0753c3c-430c-4117-a052-97236021468b';
  $pane = new stdClass();
  $pane->pid = 'new-6aec6557-e54d-4eeb-b724-49a3e0b81215';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_person_positions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'field_collection_fields',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'full',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6aec6557-e54d-4eeb-b724-49a3e0b81215';
  $display->content['new-6aec6557-e54d-4eeb-b724-49a3e0b81215'] = $pane;
  $display->panels['right_'][2] = 'new-6aec6557-e54d-4eeb-b724-49a3e0b81215';
  $pane = new stdClass();
  $pane->pid = 'new-18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_aichi_targets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $display->content['new-18fe92ed-86ce-4b50-82cb-668d0e8177e0'] = $pane;
  $display->panels['right_'][3] = 'new-18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $pane = new stdClass();
  $pane->pid = 'new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_countries';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'country_taxonomy_flag_formatter',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'image_style' => 'thumbnail',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $display->content['new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7'] = $pane;
  $display->panels['right_'][4] = 'new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $pane = new stdClass();
  $pane->pid = 'new-05035de3-5819-4843-9f18-76a4272319b1';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_reference';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'default',
      'links' => 1,
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Related content:',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '05035de3-5819-4843-9f18-76a4272319b1';
  $display->content['new-05035de3-5819-4843-9f18-76a4272319b1'] = $pane;
  $display->panels['right_'][5] = 'new-05035de3-5819-4843-9f18-76a4272319b1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__media-first-page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__media-second-page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 12;
  $handler->conf = array(
    'title' => 'Media-second page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'media-second-page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ecosystem' => 'ecosystem',
              'event' => 'event',
              'news' => 'news',
              'project' => 'project',
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
        'class' => 'media-second-page node-details-page',
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
          0 => 27,
          1 => 26,
          2 => 18,
          3 => 23,
        ),
        'class' => 'container',
        'hide_empty' => 1,
      ),
      18 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 19,
          1 => 20,
        ),
        'parent' => '1',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      19 => array(
        'type' => 'column',
        'width' => '37.71842512718425',
        'width_type' => '%',
        'parent' => '18',
        'children' => array(
          0 => 21,
        ),
        'class' => 'col-sm-8',
        'hide_empty' => 0,
      ),
      20 => array(
        'type' => 'column',
        'width' => '37.28157487281575',
        'width_type' => '%',
        'parent' => '18',
        'children' => array(
          0 => 22,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      21 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_',
        ),
        'parent' => '19',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      22 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right_',
        ),
        'parent' => '20',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right_' => array(
        'type' => 'region',
        'title' => 'Relevant Info',
        'width' => 100,
        'width_type' => '%',
        'parent' => '22',
        'class' => '',
        'hide_empty' => 0,
      ),
      23 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 24,
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      24 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '23',
        'children' => array(
          0 => 25,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      25 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'extra_content',
        ),
        'parent' => '24',
        'class' => '',
        'hide_empty' => 0,
      ),
      'extra_content' => array(
        'type' => 'region',
        'title' => 'Extra content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      26 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      27 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'header' => array(
        'type' => 'region',
        'title' => 'Header',
        'width' => 100,
        'width_type' => '%',
        'parent' => '26',
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
      'related' => NULL,
      'left_' => NULL,
      'right_' => NULL,
      'extra_content' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = 'cbabb6f5-307c-424f-b532-c4cd7b78452c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_d38b0274-09f9-4ff7-b110-30051e66d8b0';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-94ca6291-41fc-4e61-a03b-f70fb2d526ae';
  $pane->panel = 'extra_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_images';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'colorbox',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'colorbox_node_style' => 'medium',
      'colorbox_node_style_first' => '',
      'colorbox_image_style' => 'extra_large',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'title',
      'colorbox_caption_custom' => '',
      'use_image_caption_field' => 0,
      'image_class' => 'col-sm-3',
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
  $pane->uuid = '94ca6291-41fc-4e61-a03b-f70fb2d526ae';
  $display->content['new-94ca6291-41fc-4e61-a03b-f70fb2d526ae'] = $pane;
  $display->panels['extra_content'][0] = 'new-94ca6291-41fc-4e61-a03b-f70fb2d526ae';
  $pane = new stdClass();
  $pane->pid = 'new-29469a76-96d8-48e0-81db-3cc98a66408b';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_event_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
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
  $display->panels['header'][0] = 'new-29469a76-96d8-48e0-81db-3cc98a66408b';
  $pane = new stdClass();
  $pane->pid = 'new-36e0ea6f-728a-4fce-afcf-93bf58d92b26';
  $pane->panel = 'header';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_organization_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'i18n_taxonomy_term_reference_link',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '36e0ea6f-728a-4fce-afcf-93bf58d92b26';
  $display->content['new-36e0ea6f-728a-4fce-afcf-93bf58d92b26'] = $pane;
  $display->panels['header'][1] = 'new-36e0ea6f-728a-4fce-afcf-93bf58d92b26';
  $pane = new stdClass();
  $pane->pid = 'new-ba03ef63-23d2-40eb-8de4-98e2627ccf91';
  $pane->panel = 'left_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_dates';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'event_date_formatter',
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
  $display->panels['left_'][0] = 'new-ba03ef63-23d2-40eb-8de4-98e2627ccf91';
  $pane = new stdClass();
  $pane->pid = 'new-0f51bfc0-bc14-4c58-9a52-218c98755fe5';
  $pane->panel = 'left_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_event_address';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $display->panels['left_'][1] = 'new-0f51bfc0-bc14-4c58-9a52-218c98755fe5';
  $pane = new stdClass();
  $pane->pid = 'new-532b5895-367a-453f-b23c-28345b855f3c';
  $pane->panel = 'left_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_url';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '532b5895-367a-453f-b23c-28345b855f3c';
  $display->content['new-532b5895-367a-453f-b23c-28345b855f3c'] = $pane;
  $display->panels['left_'][2] = 'new-532b5895-367a-453f-b23c-28345b855f3c';
  $pane = new stdClass();
  $pane->pid = 'new-eeafd3d1-31de-4167-9166-dabe53c87cc5';
  $pane->panel = 'left_';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'eeafd3d1-31de-4167-9166-dabe53c87cc5';
  $display->content['new-eeafd3d1-31de-4167-9166-dabe53c87cc5'] = $pane;
  $display->panels['left_'][3] = 'new-eeafd3d1-31de-4167-9166-dabe53c87cc5';
  $pane = new stdClass();
  $pane->pid = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $pane->panel = 'left_';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $display->content['new-0e195d4e-168f-4220-85bd-4f7d51c778c2'] = $pane;
  $display->panels['left_'][4] = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $pane = new stdClass();
  $pane->pid = 'new-dc4a0d57-0beb-4edf-8458-e75058a39845';
  $pane->panel = 'right_';
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
  $display->panels['right_'][0] = 'new-dc4a0d57-0beb-4edf-8458-e75058a39845';
  $pane = new stdClass();
  $pane->pid = 'new-18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_aichi_targets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'i18n_taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $display->content['new-18fe92ed-86ce-4b50-82cb-668d0e8177e0'] = $pane;
  $display->panels['right_'][1] = 'new-18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $pane = new stdClass();
  $pane->pid = 'new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_countries';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'country_taxonomy_flag_formatter',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'image_style' => 'thumbnail',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $display->content['new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7'] = $pane;
  $display->panels['right_'][2] = 'new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $pane = new stdClass();
  $pane->pid = 'new-f195baad-8a5f-4527-8f62-6ce5f4c7ec40';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_reference';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'default',
      'links' => 1,
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Related content:',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f195baad-8a5f-4527-8f62-6ce5f4c7ec40';
  $display->content['new-f195baad-8a5f-4527-8f62-6ce5f4c7ec40'] = $pane;
  $display->panels['right_'][3] = 'new-f195baad-8a5f-4527-8f62-6ce5f4c7ec40';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__media-second-page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_902a75d9-6da4-450b-b1b9-2a30fd7e2923';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Species page',
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
              'species' => 'species',
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
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
        'class' => 'row',
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
      'main' => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
        'class' => 'col-sm-8',
        'hide_empty' => 0,
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 3,
          1 => 4,
        ),
        'parent' => 'main',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 7,
        ),
        'class' => 'col-sm-6',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'children' => array(
          0 => 8,
        ),
        'class' => 'col-sm-6',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_1',
        ),
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_1' => array(
        'type' => 'region',
        'title' => 'Left 1',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_2',
        ),
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_2' => array(
        'type' => 'region',
        'title' => 'left 2',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
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
      'left_1' => NULL,
      'left_2' => NULL,
      'left_3' => NULL,
      'left_4' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = '7a2e4ef5-1da7-4176-82d1-d83911dc40a9';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_902a75d9-6da4-450b-b1b9-2a30fd7e2923';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-80621848-5e02-4705-902f-da79605b27e3';
  $pane->panel = 'left_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_species_class';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->uuid = '80621848-5e02-4705-902f-da79605b27e3';
  $display->content['new-80621848-5e02-4705-902f-da79605b27e3'] = $pane;
  $display->panels['left_1'][0] = 'new-80621848-5e02-4705-902f-da79605b27e3';
  $pane = new stdClass();
  $pane->pid = 'new-edc5c79e-f679-42ec-bc96-af829e69f082';
  $pane->panel = 'left_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_species_order';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'edc5c79e-f679-42ec-bc96-af829e69f082';
  $display->content['new-edc5c79e-f679-42ec-bc96-af829e69f082'] = $pane;
  $display->panels['left_1'][1] = 'new-edc5c79e-f679-42ec-bc96-af829e69f082';
  $pane = new stdClass();
  $pane->pid = 'new-54653846-a831-4d16-8bf7-535e6b0d694d';
  $pane->panel = 'left_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_species_family';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '54653846-a831-4d16-8bf7-535e6b0d694d';
  $display->content['new-54653846-a831-4d16-8bf7-535e6b0d694d'] = $pane;
  $display->panels['left_1'][2] = 'new-54653846-a831-4d16-8bf7-535e6b0d694d';
  $pane = new stdClass();
  $pane->pid = 'new-37b3f009-b81c-49f8-b42b-1d65ba521030';
  $pane->panel = 'left_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_species_genus';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_plain',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '37b3f009-b81c-49f8-b42b-1d65ba521030';
  $display->content['new-37b3f009-b81c-49f8-b42b-1d65ba521030'] = $pane;
  $display->panels['left_1'][3] = 'new-37b3f009-b81c-49f8-b42b-1d65ba521030';
  $pane = new stdClass();
  $pane->pid = 'new-e1b36636-3d63-4a79-9386-7b6b7ac6c486';
  $pane->panel = 'left_1';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_species_kingdom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'e1b36636-3d63-4a79-9386-7b6b7ac6c486';
  $display->content['new-e1b36636-3d63-4a79-9386-7b6b7ac6c486'] = $pane;
  $display->panels['left_1'][4] = 'new-e1b36636-3d63-4a79-9386-7b6b7ac6c486';
  $pane = new stdClass();
  $pane->pid = 'new-a3358720-3cdf-4acb-accb-077fc31713a1';
  $pane->panel = 'left_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_redlist_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->uuid = 'a3358720-3cdf-4acb-accb-077fc31713a1';
  $display->content['new-a3358720-3cdf-4acb-accb-077fc31713a1'] = $pane;
  $display->panels['left_2'][0] = 'new-a3358720-3cdf-4acb-accb-077fc31713a1';
  $pane = new stdClass();
  $pane->pid = 'new-6485b9c6-b200-4b8f-827c-32a1c2f79853';
  $pane->panel = 'left_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'year',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6485b9c6-b200-4b8f-827c-32a1c2f79853';
  $display->content['new-6485b9c6-b200-4b8f-827c-32a1c2f79853'] = $pane;
  $display->panels['left_2'][1] = 'new-6485b9c6-b200-4b8f-827c-32a1c2f79853';
  $pane = new stdClass();
  $pane->pid = 'new-510a3ab4-5ab5-47fa-839f-263fc240eb54';
  $pane->panel = 'left_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_species_authority';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '510a3ab4-5ab5-47fa-839f-263fc240eb54';
  $display->content['new-510a3ab4-5ab5-47fa-839f-263fc240eb54'] = $pane;
  $display->panels['left_2'][2] = 'new-510a3ab4-5ab5-47fa-839f-263fc240eb54';
  $pane = new stdClass();
  $pane->pid = 'new-af15d13d-624a-4733-964f-b58ec6e9e0b5';
  $pane->panel = 'left_2';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_species_phylum';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'af15d13d-624a-4733-964f-b58ec6e9e0b5';
  $display->content['new-af15d13d-624a-4733-964f-b58ec6e9e0b5'] = $pane;
  $display->panels['left_2'][3] = 'new-af15d13d-624a-4733-964f-b58ec6e9e0b5';
  $pane = new stdClass();
  $pane->pid = 'new-1f114204-5766-4d5c-aa17-92ce3555efe0';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_images';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'slick',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'colorbox_node_style' => 'large',
      'colorbox_node_style_first' => '',
      'colorbox_image_style' => 'large',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'none',
      'colorbox_caption_custom' => '',
      'use_image_caption_field' => 0,
      'slide_style' => 'large',
      'thumb_style' => 'thumbnail',
      'style' => 'nostyle',
      'linking_method' => 'onclick_full',
      'link_to_full' => 1,
      'link_to_full_style' => 'large',
      'modal' => 'colorbox',
      'image_style' => 'large',
      'colorbox_style' => '',
      'markup' => 0,
      'mousewheel' => 0,
      'thumbnail_style' => '',
      'thumbnail_hover' => 0,
      'current_view_mode' => 'ctools',
      'asnavfor_main' => '',
      'asnavfor_thumbnail' => '',
      'asnavfor_auto' => 0,
      'media_switch' => '',
      'optionset' => 'sidebar',
      'optionset_thumbnail' => '',
      'skin' => 'default',
      'skin_thumbnail' => 'default',
      'skin_arrows' => '',
      'skin_dots' => '',
      'slide_caption' => array(
        'title_field' => 0,
        'alt_field' => 0,
      ),
      'slide_layout' => '',
      'thumbnail_caption' => '',
      'override' => 0,
      'overridables' => array(
        'arrows' => 0,
        'autoplay' => 0,
        'dots' => 0,
        'draggable' => 0,
      ),
      'cache' => '',
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
  $pane->uuid = '1f114204-5766-4d5c-aa17-92ce3555efe0';
  $display->content['new-1f114204-5766-4d5c-aa17-92ce3555efe0'] = $pane;
  $display->panels['right'][0] = 'new-1f114204-5766-4d5c-aa17-92ce3555efe0';
  $pane = new stdClass();
  $pane->pid = 'new-891780fa-b7e6-4a50-a8cf-5fa1cee4240a';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'chm_structure-species_arkive';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '891780fa-b7e6-4a50-a8cf-5fa1cee4240a';
  $display->content['new-891780fa-b7e6-4a50-a8cf-5fa1cee4240a'] = $pane;
  $display->panels['right'][1] = 'new-891780fa-b7e6-4a50-a8cf-5fa1cee4240a';
  $pane = new stdClass();
  $pane->pid = 'new-5def36d4-d39f-4440-ba68-b0cc613a172c';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'views-species-block_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Related species',
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
  $pane->uuid = '5def36d4-d39f-4440-ba68-b0cc613a172c';
  $display->content['new-5def36d4-d39f-4440-ba68-b0cc613a172c'] = $pane;
  $display->panels['right'][2] = 'new-5def36d4-d39f-4440-ba68-b0cc613a172c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_902a75d9-6da4-450b-b1b9-2a30fd7e2923'] = $handler;

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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_d38b0274-09f9-4ff7-b110-30051e66d8b0';
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
    'formatter' => 'event_date_formatter',
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
  $pane->pid = 'new-18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $pane->panel = 'left_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_aichi_targets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'i18n_taxonomy_term_reference_plain',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $display->content['new-18fe92ed-86ce-4b50-82cb-668d0e8177e0'] = $pane;
  $display->panels['left_3'][1] = 'new-18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $pane = new stdClass();
  $pane->pid = 'new-94ca6291-41fc-4e61-a03b-f70fb2d526ae';
  $pane->panel = 'left_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_images';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'colorbox',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'colorbox_node_style' => 'medium',
      'colorbox_node_style_first' => '',
      'colorbox_image_style' => 'extra_large',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'title',
      'colorbox_caption_custom' => '',
      'use_image_caption_field' => 0,
      'image_class' => 'col-sm-3',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '94ca6291-41fc-4e61-a03b-f70fb2d526ae';
  $display->content['new-94ca6291-41fc-4e61-a03b-f70fb2d526ae'] = $pane;
  $display->panels['left_3'][2] = 'new-94ca6291-41fc-4e61-a03b-f70fb2d526ae';
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

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__protected-areas-page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 13;
  $handler->conf = array(
    'title' => 'Protected areas page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'protected-areas-page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'protected_area' => 'protected_area',
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
        'class' => 'media-second-page node-details-page',
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
          0 => 27,
          1 => 18,
          2 => 23,
        ),
        'class' => 'container',
        'hide_empty' => 1,
      ),
      18 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 19,
          1 => 20,
        ),
        'parent' => '1',
        'class' => 'row',
        'hide_empty' => 0,
      ),
      19 => array(
        'type' => 'column',
        'width' => '37.71842512718425',
        'width_type' => '%',
        'parent' => '18',
        'children' => array(
          0 => 34,
          1 => 33,
        ),
        'class' => 'col-sm-8',
        'hide_empty' => 0,
      ),
      20 => array(
        'type' => 'column',
        'width' => '37.28157487281575',
        'width_type' => '%',
        'parent' => '18',
        'children' => array(
          0 => 22,
        ),
        'class' => 'col-sm-4',
        'hide_empty' => 0,
      ),
      22 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right_',
        ),
        'parent' => '20',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right_' => array(
        'type' => 'region',
        'title' => 'Relevant Info',
        'width' => 100,
        'width_type' => '%',
        'parent' => '22',
        'class' => '',
        'hide_empty' => 0,
      ),
      23 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 24,
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      24 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '23',
        'children' => array(
          0 => 25,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      25 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'extra_content',
        ),
        'parent' => '24',
        'class' => '',
        'hide_empty' => 0,
      ),
      'extra_content' => array(
        'type' => 'region',
        'title' => 'Extra content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '25',
        'class' => '',
        'hide_empty' => 0,
      ),
      27 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      33 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'main_content',
        ),
        'parent' => '19',
        'class' => '',
        'hide_empty' => 0,
      ),
      'main_content' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '33',
        'class' => '',
        'hide_empty' => 0,
      ),
      34 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'characteristics',
        ),
        'parent' => '19',
        'class' => '',
        'hide_empty' => 0,
      ),
      'characteristics' => array(
        'type' => 'region',
        'title' => 'Characteristics',
        'width' => 100,
        'width_type' => '%',
        'parent' => '34',
        'class' => 'protected-area-detail-columns',
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
      'related' => NULL,
      'left_' => NULL,
      'right_' => NULL,
      'extra_content' => NULL,
      'main_content' => NULL,
      'characteristics' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = 'cbabb6f5-307c-424f-b532-c4cd7b78452c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_d38b0274-09f9-4ff7-b110-30051e66d8b0';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b46fb5a2-72cc-4c7e-b505-fe13e73e3bf9';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->uuid = 'b46fb5a2-72cc-4c7e-b505-fe13e73e3bf9';
  $display->content['new-b46fb5a2-72cc-4c7e-b505-fe13e73e3bf9'] = $pane;
  $display->panels['characteristics'][0] = 'new-b46fb5a2-72cc-4c7e-b505-fe13e73e3bf9';
  $pane = new stdClass();
  $pane->pid = 'new-dcf5669f-b113-40f4-8eee-4a7133cc4e88';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_iucn_category';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dcf5669f-b113-40f4-8eee-4a7133cc4e88';
  $display->content['new-dcf5669f-b113-40f4-8eee-4a7133cc4e88'] = $pane;
  $display->panels['characteristics'][1] = 'new-dcf5669f-b113-40f4-8eee-4a7133cc4e88';
  $pane = new stdClass();
  $pane->pid = 'new-f1a5b8c6-7d26-49ed-a5de-93e916b2692f';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_designation_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f1a5b8c6-7d26-49ed-a5de-93e916b2692f';
  $display->content['new-f1a5b8c6-7d26-49ed-a5de-93e916b2692f'] = $pane;
  $display->panels['characteristics'][2] = 'new-f1a5b8c6-7d26-49ed-a5de-93e916b2692f';
  $pane = new stdClass();
  $pane->pid = 'new-d032299f-8bf1-465b-ba94-98bc06404253';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_designation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd032299f-8bf1-465b-ba94-98bc06404253';
  $display->content['new-d032299f-8bf1-465b-ba94-98bc06404253'] = $pane;
  $display->panels['characteristics'][3] = 'new-d032299f-8bf1-465b-ba94-98bc06404253';
  $pane = new stdClass();
  $pane->pid = 'new-86118b8b-b239-495f-b47c-70228a972dea';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_surface_area';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '86118b8b-b239-495f-b47c-70228a972dea';
  $display->content['new-86118b8b-b239-495f-b47c-70228a972dea'] = $pane;
  $display->panels['characteristics'][4] = 'new-86118b8b-b239-495f-b47c-70228a972dea';
  $pane = new stdClass();
  $pane->pid = 'new-2d515b99-d46c-4dbd-b279-ed0fcfc9fad2';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_status_year';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '2d515b99-d46c-4dbd-b279-ed0fcfc9fad2';
  $display->content['new-2d515b99-d46c-4dbd-b279-ed0fcfc9fad2'] = $pane;
  $display->panels['characteristics'][5] = 'new-2d515b99-d46c-4dbd-b279-ed0fcfc9fad2';
  $pane = new stdClass();
  $pane->pid = 'new-01522e67-661f-43cf-b188-0832e46ee9b6';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_governing_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '01522e67-661f-43cf-b188-0832e46ee9b6';
  $display->content['new-01522e67-661f-43cf-b188-0832e46ee9b6'] = $pane;
  $display->panels['characteristics'][6] = 'new-01522e67-661f-43cf-b188-0832e46ee9b6';
  $pane = new stdClass();
  $pane->pid = 'new-7828fce0-ee30-45f5-ad10-591e26bac052';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_owner_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '7828fce0-ee30-45f5-ad10-591e26bac052';
  $display->content['new-7828fce0-ee30-45f5-ad10-591e26bac052'] = $pane;
  $display->panels['characteristics'][7] = 'new-7828fce0-ee30-45f5-ad10-591e26bac052';
  $pane = new stdClass();
  $pane->pid = 'new-ad9f9a29-100e-4a8d-bbed-2e7c4332696d';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_management_authority';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'ad9f9a29-100e-4a8d-bbed-2e7c4332696d';
  $display->content['new-ad9f9a29-100e-4a8d-bbed-2e7c4332696d'] = $pane;
  $display->panels['characteristics'][8] = 'new-ad9f9a29-100e-4a8d-bbed-2e7c4332696d';
  $pane = new stdClass();
  $pane->pid = 'new-56ea2586-29cc-48c3-b97a-a42d2638ca9e';
  $pane->panel = 'characteristics';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_pa_management_plan';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '56ea2586-29cc-48c3-b97a-a42d2638ca9e';
  $display->content['new-56ea2586-29cc-48c3-b97a-a42d2638ca9e'] = $pane;
  $display->panels['characteristics'][9] = 'new-56ea2586-29cc-48c3-b97a-a42d2638ca9e';
  $pane = new stdClass();
  $pane->pid = 'new-94ca6291-41fc-4e61-a03b-f70fb2d526ae';
  $pane->panel = 'extra_content';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_images';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'colorbox',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'colorbox_node_style' => 'medium',
      'colorbox_node_style_first' => '',
      'colorbox_image_style' => 'extra_large',
      'colorbox_gallery' => 'post',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'title',
      'colorbox_caption_custom' => '',
      'use_image_caption_field' => 0,
      'image_class' => 'col-sm-3',
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
  $pane->uuid = '94ca6291-41fc-4e61-a03b-f70fb2d526ae';
  $display->content['new-94ca6291-41fc-4e61-a03b-f70fb2d526ae'] = $pane;
  $display->panels['extra_content'][0] = 'new-94ca6291-41fc-4e61-a03b-f70fb2d526ae';
  $pane = new stdClass();
  $pane->pid = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $pane->panel = 'main_content';
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
  $display->panels['main_content'][0] = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $pane = new stdClass();
  $pane->pid = 'new-dc4a0d57-0beb-4edf-8458-e75058a39845';
  $pane->panel = 'right_';
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
  $display->panels['right_'][0] = 'new-dc4a0d57-0beb-4edf-8458-e75058a39845';
  $pane = new stdClass();
  $pane->pid = 'new-18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_aichi_targets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'i18n_taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $display->content['new-18fe92ed-86ce-4b50-82cb-668d0e8177e0'] = $pane;
  $display->panels['right_'][1] = 'new-18fe92ed-86ce-4b50-82cb-668d0e8177e0';
  $pane = new stdClass();
  $pane->pid = 'new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_countries';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'i18n_taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $display->content['new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7'] = $pane;
  $display->panels['right_'][2] = 'new-6d92f0e2-572c-43b7-a95a-5f9e54f46ff7';
  $pane = new stdClass();
  $pane->pid = 'new-f195baad-8a5f-4527-8f62-6ce5f4c7ec40';
  $pane->panel = 'right_';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_reference';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'default',
      'links' => 1,
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'f195baad-8a5f-4527-8f62-6ce5f4c7ec40';
  $display->content['new-f195baad-8a5f-4527-8f62-6ce5f4c7ec40'] = $pane;
  $display->panels['right_'][3] = 'new-f195baad-8a5f-4527-8f62-6ce5f4c7ec40';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__protected-areas-page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__text-only-page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 10;
  $handler->conf = array(
    'title' => 'Text-only page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'text-only-page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'cbd_national_target' => 'cbd_national_target',
              'fact' => 'fact',
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
        'class' => 'text-only-page node-details-page',
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
          1 => 10,
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
      'related' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title_field';
  $display->uuid = 'cbabb6f5-307c-424f-b532-c4cd7b78452c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_d38b0274-09f9-4ff7-b110-30051e66d8b0';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f7173a5e-f11a-4ed2-869f-6dbee331e84a';
  $pane->panel = 'left';
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
      'image_style' => '',
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
  $pane->uuid = 'f7173a5e-f11a-4ed2-869f-6dbee331e84a';
  $display->content['new-f7173a5e-f11a-4ed2-869f-6dbee331e84a'] = $pane;
  $display->panels['left'][0] = 'new-f7173a5e-f11a-4ed2-869f-6dbee331e84a';
  $pane = new stdClass();
  $pane->pid = 'new-ada474ab-9fec-44bb-8fbe-364c5990c3e3';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_date';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ada474ab-9fec-44bb-8fbe-364c5990c3e3';
  $display->content['new-ada474ab-9fec-44bb-8fbe-364c5990c3e3'] = $pane;
  $display->panels['left'][1] = 'new-ada474ab-9fec-44bb-8fbe-364c5990c3e3';
  $pane = new stdClass();
  $pane->pid = 'new-799b985b-c15c-4f25-97c6-78dda9f25ce5';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_url';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '799b985b-c15c-4f25-97c6-78dda9f25ce5';
  $display->content['new-799b985b-c15c-4f25-97c6-78dda9f25ce5'] = $pane;
  $display->panels['left'][2] = 'new-799b985b-c15c-4f25-97c6-78dda9f25ce5';
  $pane = new stdClass();
  $pane->pid = 'new-915daf07-40ce-41c0-bd03-82e512b8983e';
  $pane->panel = 'left_3';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_reference_number';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_plain',
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
  $pane->uuid = '915daf07-40ce-41c0-bd03-82e512b8983e';
  $display->content['new-915daf07-40ce-41c0-bd03-82e512b8983e'] = $pane;
  $display->panels['left_3'][0] = 'new-915daf07-40ce-41c0-bd03-82e512b8983e';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $display->content['new-0e195d4e-168f-4220-85bd-4f7d51c778c2'] = $pane;
  $display->panels['left_3'][1] = 'new-0e195d4e-168f-4220-85bd-4f7d51c778c2';
  $pane = new stdClass();
  $pane->pid = 'new-888038eb-198e-4eda-b430-880a2e6f9dc3';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_aichi_targets';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'i18n_taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
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
  $pane->uuid = '888038eb-198e-4eda-b430-880a2e6f9dc3';
  $display->content['new-888038eb-198e-4eda-b430-880a2e6f9dc3'] = $pane;
  $display->panels['right'][0] = 'new-888038eb-198e-4eda-b430-880a2e6f9dc3';
  $pane = new stdClass();
  $pane->pid = 'new-9087467c-48ba-472c-80e1-aafa1ebb50da';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_countries';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'country_taxonomy_flag_formatter',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'image_style' => 'thumbnail',
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
  $pane->uuid = '9087467c-48ba-472c-80e1-aafa1ebb50da';
  $display->content['new-9087467c-48ba-472c-80e1-aafa1ebb50da'] = $pane;
  $display->panels['right'][1] = 'new-9087467c-48ba-472c-80e1-aafa1ebb50da';
  $pane = new stdClass();
  $pane->pid = 'new-b8510c7e-dad2-47f3-8791-5770cd217d1f';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_reference';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'default',
      'links' => 1,
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Related content:',
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
  $pane->uuid = 'b8510c7e-dad2-47f3-8791-5770cd217d1f';
  $display->content['new-b8510c7e-dad2-47f3-8791-5770cd217d1f'] = $pane;
  $display->panels['right'][2] = 'new-b8510c7e-dad2-47f3-8791-5770cd217d1f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__text-only-page'] = $handler;

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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_main_home_page__panel';
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
