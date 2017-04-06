<?php
/**
 * @file
 * chm_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function chm_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'administrative_content';
  $view->description = 'The content view shown in the administrative area (admin/content)';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Administrative content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Administrative content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access administration pages';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'created' => 'created',
    'sitename' => 'sitename',
    'name' => 'name',
    'edit_node' => 'edit_node',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sitename' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_month_year_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_month_year_time';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Domains: Site name */
  $handler->display->display_options['fields']['sitename']['id'] = 'sitename';
  $handler->display->display_options['fields']['sitename']['table'] = 'domain';
  $handler->display->display_options['fields']['sitename']['field'] = 'sitename';
  $handler->display->display_options['fields']['sitename']['label'] = 'Domain';
  $handler->display->display_options['fields']['sitename']['link_to_site'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[edit_node] [delete_node] <span title="[nid]"></span>';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['description'] = 'Filter by content title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Domain Access: Node assigned to domains user is editor (PTK) */
  $handler->display->display_options['filters']['current_user_is_editor']['id'] = 'current_user_is_editor';
  $handler->display->display_options['filters']['current_user_is_editor']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_user_is_editor']['field'] = 'current_user_is_editor';
  $handler->display->display_options['filters']['current_user_is_editor']['value'] = '1';
  $handler->display->display_options['filters']['current_user_is_editor']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'book' => 'book',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;

  /* Display: Platform content */
  $handler = $view->new_display('page', 'Platform content', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_month_year_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_month_year_time';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Domains: Site name */
  $handler->display->display_options['fields']['sitename']['id'] = 'sitename';
  $handler->display->display_options['fields']['sitename']['table'] = 'domain';
  $handler->display->display_options['fields']['sitename']['field'] = 'sitename';
  $handler->display->display_options['fields']['sitename']['label'] = 'Domain';
  $handler->display->display_options['fields']['sitename']['link_to_site'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[edit_node] [delete_node] <span title="[nid]"></span>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['description'] = 'Filter by content title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Domain Access: Node assigned to domains user is editor (PTK) */
  $handler->display->display_options['filters']['current_user_is_editor']['id'] = 'current_user_is_editor';
  $handler->display->display_options['filters']['current_user_is_editor']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_user_is_editor']['field'] = 'current_user_is_editor';
  $handler->display->display_options['filters']['current_user_is_editor']['value'] = '1';
  $handler->display->display_options['filters']['current_user_is_editor']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'book' => 'book',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Domain Access: Domain ID */
  $handler->display->display_options['filters']['gid']['id'] = 'gid';
  $handler->display->display_options['filters']['gid']['table'] = 'domain_access';
  $handler->display->display_options['filters']['gid']['field'] = 'gid';
  $handler->display->display_options['filters']['gid']['group'] = 1;
  $handler->display->display_options['filters']['gid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['gid']['expose']['operator_id'] = 'gid_op';
  $handler->display->display_options['filters']['gid']['expose']['label'] = 'CHM Site';
  $handler->display->display_options['filters']['gid']['expose']['operator'] = 'gid_op';
  $handler->display->display_options['filters']['gid']['expose']['identifier'] = 'gid';
  $handler->display->display_options['filters']['gid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['path'] = 'admin/content';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Content';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Portal content */
  $handler = $view->new_display('page', 'Portal content', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Portal content';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'date_month_year_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'date_month_year_time';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[edit_node] [delete_node] <span title="[nid]"></span>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['description'] = 'Filter by content title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Domain Access: Node assigned to domains user is editor (PTK) */
  $handler->display->display_options['filters']['current_user_is_editor']['id'] = 'current_user_is_editor';
  $handler->display->display_options['filters']['current_user_is_editor']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_user_is_editor']['field'] = 'current_user_is_editor';
  $handler->display->display_options['filters']['current_user_is_editor']['value'] = '1';
  $handler->display->display_options['filters']['current_user_is_editor']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'book' => 'book',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/portal-content';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Portal content';
  $handler->display->display_options['menu']['description'] = 'View your website\'s content';
  $handler->display->display_options['menu']['weight'] = '-90';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: ER Widget */
  $handler = $view->new_display('entityreference_view_widget', 'ER Widget', 'entityreference_view_widget');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Select content';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'created' => 'created',
    'sitename' => 'sitename',
    'name' => 'name',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sitename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'european';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[edit_node] [delete_node] <span title="[nid]"></span>';

  /* Display: Author Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Author Widget', 'entityreference_view_widget_author');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Select content';
  $handler->display->display_options['display_description'] = 'Widget selection for field_authors';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'created' => 'created',
    'sitename' => 'sitename',
    'name' => 'name',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sitename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'european';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[edit_node] [delete_node] <span title="[nid]"></span>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['description'] = 'Filter by content title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'organization' => 'organization',
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;

  /* Display: Person Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Person Widget', 'entityreference_view_widget_person');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Select content';
  $handler->display->display_options['display_description'] = 'Widget to select persons only';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'created' => 'created',
    'sitename' => 'sitename',
    'name' => 'name',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sitename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'european';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[edit_node] [delete_node] <span title="[nid]"></span>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['description'] = 'Filter by content title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'person' => 'person',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;

  /* Display: Organization Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Organization Widget', 'entityreference_view_widget_organization');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Select content';
  $handler->display->display_options['display_description'] = 'Widget to select organizations only';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'created' => 'created',
    'sitename' => 'sitename',
    'name' => 'name',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sitename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'european';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Operations';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[edit_node] [delete_node] <span title="[nid]"></span>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['description'] = 'Filter by content title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'organization' => 'organization',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;

  /* Display: Species Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Species Widget', 'entityreference_view_widget_species');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Select content';
  $handler->display->display_options['display_description'] = 'Widget to select species only';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'created' => 'created',
    'sitename' => 'sitename',
    'name' => 'name',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sitename' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity Reference View Widget Checkbox: Content */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'european';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Scientific name';
  $handler->display->display_options['filters']['title_field_value']['expose']['description'] = 'Filter by species name';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'species' => 'species',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $translatables['administrative_content'] = array(
    t('Master'),
    t('Administrative content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('author'),
    t('Select'),
    t('- Choose an operation -'),
    t('Title'),
    t('Type'),
    t('Updated'),
    t('Created'),
    t('Domain'),
    t('Author'),
    t('Edit'),
    t('Delete'),
    t('Operations'),
    t('[edit_node] [delete_node] <span title="[nid]"></span>'),
    t('Filter by content title'),
    t('Published'),
    t('Platform content'),
    t('CHM Site'),
    t('Portal content'),
    t('ER Widget'),
    t('Select content'),
    t('Author Widget'),
    t('Widget selection for field_authors'),
    t('Person Widget'),
    t('Widget to select persons only'),
    t('Organization Widget'),
    t('Widget to select organizations only'),
    t('Species Widget'),
    t('Widget to select species only'),
    t('Scientific name'),
    t('Filter by species name'),
  );
  $export['administrative_content'] = $view;

  $view = new view();
  $view->name = 'aichi_biodiversity_targets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Aichi biodiversity targets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aichi biodiversity targets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'tid';
  $handler->display->display_options['style_options']['parent_field'] = 'tid_1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid_1']['label'] = 'Parent ID';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  /* Field: Entity translation: Image: translated */
  $handler->display->display_options['fields']['field_image_et']['id'] = 'field_image_et';
  $handler->display->display_options['fields']['field_image_et']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_et']['field'] = 'field_image_et';
  $handler->display->display_options['fields']['field_image_et']['label'] = '';
  $handler->display->display_options['fields']['field_image_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_et']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_et']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['name_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'aichi_biodiversity_targets' => 'aichi_biodiversity_targets',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tools/abt';
  $translatables['aichi_biodiversity_targets'] = array(
    t('Master'),
    t('Aichi biodiversity targets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Parent'),
    t('.'),
    t(','),
    t('Parent ID'),
    t('Page'),
  );
  $export['aichi_biodiversity_targets'] = $view;

  $view = new view();
  $view->name = 'cbd_national_targets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CBD National targets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'National targets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_reference_number' => 'field_reference_number',
    'title' => 'title',
    'body' => 'body',
    'field_aichi_targets' => 'field_aichi_targets',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_reference_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_aichi_targets' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Reference number */
  $handler->display->display_options['fields']['field_reference_number']['id'] = 'field_reference_number';
  $handler->display->display_options['fields']['field_reference_number']['table'] = 'field_data_field_reference_number';
  $handler->display->display_options['fields']['field_reference_number']['field'] = 'field_reference_number';
  $handler->display->display_options['fields']['field_reference_number']['label'] = '';
  $handler->display->display_options['fields']['field_reference_number']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Rationale';
  /* Field: Content: Aichi targets */
  $handler->display->display_options['fields']['field_aichi_targets']['id'] = 'field_aichi_targets';
  $handler->display->display_options['fields']['field_aichi_targets']['table'] = 'field_data_field_aichi_targets';
  $handler->display->display_options['fields']['field_aichi_targets']['field'] = 'field_aichi_targets';
  $handler->display->display_options['fields']['field_aichi_targets']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cbd_national_target' => 'cbd_national_target',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_reference_number' => 'field_reference_number',
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Content: Aichi targets (field_aichi_targets) */
  $handler->display->display_options['filters']['field_aichi_targets_tid']['id'] = 'field_aichi_targets_tid';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['table'] = 'field_data_field_aichi_targets';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['field'] = 'field_aichi_targets_tid';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['value'] = '';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_aichi_targets_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_aichi_targets_tid']['expose']['operator_id'] = 'field_aichi_targets_tid_op';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['expose']['label'] = 'Aichi targets';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['expose']['operator'] = 'field_aichi_targets_tid_op';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['expose']['identifier'] = 'field_aichi_targets_tid';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_aichi_targets_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['vocabulary'] = 'aichi_biodiversity_targets';
  $handler->display->display_options['filters']['field_aichi_targets_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'national-targets';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'targets');
  $translatables['cbd_national_targets'] = array(
    t('Master'),
    t('National targets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Title'),
    t('Rationale'),
    t('Aichi targets'),
    t('Search'),
    t('Page'),
    t('Block'),
  );
  $export['cbd_national_targets'] = $view;

  $view = new view();
  $view->name = 'chm_sites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CHM Sites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'The CHM Network';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_image_et' => 'field_image_et',
    'body' => 'body',
    'draggableviews' => 'draggableviews',
    'field_image' => 'field_image',
    'title' => 'title',
    'field_chm_site_status' => 'field_chm_site_status',
    'field_url' => 'field_url',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_image_et' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_chm_site_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Government (field_government) */
  $handler->display->display_options['relationships']['field_government_tid']['id'] = 'field_government_tid';
  $handler->display->display_options['relationships']['field_government_tid']['table'] = 'field_data_field_government';
  $handler->display->display_options['relationships']['field_government_tid']['field'] = 'field_government_tid';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Countries */
  $handler->display->display_options['fields']['field_countries']['id'] = 'field_countries';
  $handler->display->display_options['fields']['field_countries']['table'] = 'field_data_field_countries';
  $handler->display->display_options['fields']['field_countries']['field'] = 'field_countries';
  $handler->display->display_options['fields']['field_countries']['label'] = 'Country';
  $handler->display->display_options['fields']['field_countries']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_countries']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_countries']['delta_offset'] = '0';
  /* Field: Field: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url']['type'] = 'link_url';
  /* Field: Entity translation: Image: translated */
  $handler->display->display_options['fields']['field_image_et']['id'] = 'field_image_et';
  $handler->display->display_options['fields']['field_image_et']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_et']['field'] = 'field_image_et';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'chm_sites:block';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 0;
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'chm_site' => 'chm_site',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'body' => 'body',
    'title' => 'title',
    'field_countries' => 'field_countries',
    'field_url' => 'field_url',
  );
  /* Filter criterion: Content: Countries (field_countries) */
  $handler->display->display_options['filters']['field_countries_tid']['id'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['table'] = 'field_data_field_countries';
  $handler->display->display_options['filters']['field_countries_tid']['field'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_countries_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_countries_tid']['expose']['operator_id'] = 'field_countries_tid_op';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['operator'] = 'field_countries_tid_op';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['identifier'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_countries_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_countries_tid']['vocabulary'] = 'countries';
  $handler->display->display_options['filters']['field_countries_tid']['error_message'] = FALSE;

  /* Display: Geographical map of CHM network sites */
  $handler = $view->new_display('block', 'Geographical map of CHM network sites', 'block_sites_map');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ammap';
  $handler->display->display_options['style_options']['iso_code_field'] = 'field_iso_code';
  $handler->display->display_options['style_options']['tooltip_field'] = 'field_url';
  $handler->display->display_options['style_options']['dataProvider'] = array(
    'map' => 'worldLow',
  );
  $handler->display->display_options['style_options']['smallMap'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_government_tid';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url']['type'] = 'link_url';
  /* Field: Taxonomy term: Country ISO 2-letter Code */
  $handler->display->display_options['fields']['field_iso_code']['id'] = 'field_iso_code';
  $handler->display->display_options['fields']['field_iso_code']['table'] = 'field_data_field_iso_code';
  $handler->display->display_options['fields']['field_iso_code']['field'] = 'field_iso_code';
  $handler->display->display_options['fields']['field_iso_code']['relationship'] = 'field_government_tid';
  $handler->display->display_options['fields']['field_iso_code']['label'] = 'ISO 2-letter code';
  $handler->display->display_options['fields']['field_iso_code']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'chm_site' => 'chm_site',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_chm_network_sites');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Image: translated */
  $handler->display->display_options['fields']['field_image_et']['id'] = 'field_image_et';
  $handler->display->display_options['fields']['field_image_et']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_et']['field'] = 'field_image_et';
  $handler->display->display_options['fields']['field_image_et']['relationship'] = 'field_government_tid';
  $handler->display->display_options['fields']['field_image_et']['label'] = '';
  $handler->display->display_options['fields']['field_image_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_et']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_et']['settings'] = array(
    'image_style' => 'small_flag_icon',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_url']['type'] = 'link_url';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'chm_site' => 'chm_site',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Government (field_government) */
  $handler->display->display_options['filters']['field_government_tid']['id'] = 'field_government_tid';
  $handler->display->display_options['filters']['field_government_tid']['table'] = 'field_data_field_government';
  $handler->display->display_options['filters']['field_government_tid']['field'] = 'field_government_tid';
  $handler->display->display_options['filters']['field_government_tid']['value'] = '';
  $handler->display->display_options['filters']['field_government_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_government_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_government_tid']['expose']['operator_id'] = 'field_government_tid_op';
  $handler->display->display_options['filters']['field_government_tid']['expose']['label'] = 'Government';
  $handler->display->display_options['filters']['field_government_tid']['expose']['operator'] = 'field_government_tid_op';
  $handler->display->display_options['filters']['field_government_tid']['expose']['identifier'] = 'field_government_tid';
  $handler->display->display_options['filters']['field_government_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_government_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_government_tid']['vocabulary'] = 'countries';
  $handler->display->display_options['block_description'] = 'The CHM Network';
  $translatables['chm_sites'] = array(
    t('Master'),
    t('The CHM Network'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_government'),
    t('Content'),
    t('Title'),
    t('Country'),
    t('URL'),
    t('Image: translated'),
    t('Search'),
    t('Geographical map of CHM network sites'),
    t('ISO 2-letter code'),
    t('Block'),
    t('Government'),
  );
  $export['chm_sites'] = $view;

  $view = new view();
  $view->name = 'documents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Documents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Document library';
  $handler->display->display_options['css_class'] = 'portrait-image';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'portrait_image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body] [view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '30',
    'trim_type' => 'words',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'trim',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_field_value']['expose']['label'] = 'Title';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Type (field_document_type) */
  $handler->display->display_options['filters']['field_document_type_tid']['id'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['filters']['field_document_type_tid']['field'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_document_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['operator_id'] = 'field_document_type_tid_op';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['operator'] = 'field_document_type_tid_op';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['identifier'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_document_type_tid']['group_info']['label'] = 'Type (field_document_type)';
  $handler->display->display_options['filters']['field_document_type_tid']['group_info']['identifier'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_document_type_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_document_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_document_type_tid']['vocabulary'] = 'document_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'portrait_image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'day_month_year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="field-dates">[field_publication_date]</div>[body] [view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '30',
    'trim_type' => 'words',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'trim',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  $handler->display->display_options['path'] = 'library';

  /* Display: Latest NBSAP */
  $handler = $view->new_display('block', 'Latest NBSAP', 'nbsaps');
  $handler->display->display_options['display_description'] = 'Latest published NBSAPs documents for the current domain';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '30',
    'trim_type' => 'words',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'trim',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Type (field_document_type) */
  $handler->display->display_options['filters']['field_document_type_tid']['id'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['filters']['field_document_type_tid']['field'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_document_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['operator_id'] = 'field_document_type_tid_op';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['operator'] = 'field_document_type_tid_op';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['identifier'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_document_type_tid']['group_info']['label'] = 'Type (field_document_type)';
  $handler->display->display_options['filters']['field_document_type_tid']['group_info']['identifier'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_document_type_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_document_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_document_type_tid']['vocabulary'] = 'document_type';
  $translatables['documents'] = array(
    t('Master'),
    t('Document library'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Read more »'),
    t('[body] [view_node]'),
    t('Title'),
    t('Search'),
    t('Type'),
    t('Type (field_document_type)'),
    t('Page'),
    t('<div class="field-dates">[field_publication_date]</div>[body] [view_node]'),
    t('Latest NBSAP'),
    t('Latest published NBSAPs documents for the current domain'),
  );
  $export['documents'] = $view;

  $view = new view();
  $view->name = 'documents_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_multilingual_node_index';
  $view->human_name = 'Documents (solr)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Document library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 1;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Indexed Multilingual Node: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  /* Sort criterion: Indexed Multilingual Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Multilingual Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Multilingual Node: Type */
  $handler->display->display_options['filters']['field_document_type']['id'] = 'field_document_type';
  $handler->display->display_options['filters']['field_document_type']['table'] = 'search_api_index_default_multilingual_node_index';
  $handler->display->display_options['filters']['field_document_type']['field'] = 'field_document_type';
  $handler->display->display_options['filters']['field_document_type']['value'] = array();
  $handler->display->display_options['filters']['field_document_type']['group'] = 1;
  $handler->display->display_options['filters']['field_document_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_document_type']['expose']['operator_id'] = 'field_document_type_op';
  $handler->display->display_options['filters']['field_document_type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_document_type']['expose']['operator'] = 'field_document_type_op';
  $handler->display->display_options['filters']['field_document_type']['expose']['identifier'] = 'field_document_type';
  $handler->display->display_options['filters']['field_document_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_document_type']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'documents';

  /* Display: Latest NBSAP */
  $handler = $view->new_display('block', 'Latest NBSAP', 'block');
  $handler->display->display_options['display_description'] = 'Latest published NBSAPs documents for the current domain';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $translatables['documents_solr'] = array(
    t('Master'),
    t('Document library'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Multilingual ID'),
    t('Search'),
    t('Type'),
    t('Page'),
    t('Latest NBSAP'),
    t('Latest published NBSAPs documents for the current domain'),
  );
  $export['documents_solr'] = $view;

  $view = new view();
  $view->name = 'ecosystems';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ecosystems';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ecosystems';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body] [view_node] ';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ecosystem' => 'ecosystem',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body] [view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '100',
    'trim_type' => 'words',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => '',
    'summary_handler' => 'trim',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_main');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body] [view_node] ';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['path'] = 'ecosystems';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ecosystems';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-information-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['ecosystems'] = array(
    t('Master'),
    t('Ecosystems'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Read more »'),
    t('[body] [view_node] '),
    t('Block'),
    t('[body] [view_node]'),
    t('Page'),
  );
  $export['ecosystems'] = $view;

  $view = new view();
  $view->name = 'eu_targets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'EU Targets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'EU Targets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'tid_1';
  $handler->display->display_options['style_options']['parent_field'] = 'tid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['label'] = '';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid']['label'] = 'Parent ID';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'eu_targets' => 'eu_targets',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tools/eu-targets';
  $translatables['eu_targets'] = array(
    t('Master'),
    t('EU Targets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Parent'),
    t('.'),
    t(','),
    t('Parent ID'),
    t('Page'),
  );
  $export['eu_targets'] = $view;

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Project dates */
  $handler->display->display_options['fields']['field_dates']['id'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['table'] = 'field_data_field_dates';
  $handler->display->display_options['fields']['field_dates']['field'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['label'] = '';
  $handler->display->display_options['fields']['field_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dates']['type'] = 'event_date_formatter';
  $handler->display->display_options['fields']['field_dates']['settings'] = array(
    'format_type' => 'european',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Project dates -  start date (field_dates) */
  $handler->display->display_options['sorts']['field_dates_value']['id'] = 'field_dates_value';
  $handler->display->display_options['sorts']['field_dates_value']['table'] = 'field_data_field_dates';
  $handler->display->display_options['sorts']['field_dates_value']['field'] = 'field_dates_value';
  $handler->display->display_options['sorts']['field_dates_value']['expose']['label'] = 'Dates -  start date (field_dates)';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Project dates -  start date (field_dates) */
  $handler->display->display_options['filters']['field_dates_value']['id'] = 'field_dates_value';
  $handler->display->display_options['filters']['field_dates_value']['table'] = 'field_data_field_dates';
  $handler->display->display_options['filters']['field_dates_value']['field'] = 'field_dates_value';
  $handler->display->display_options['filters']['field_dates_value']['operator'] = '>=';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['events'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Dates -  start date (field_dates)'),
    t('All'),
    t('Block'),
  );
  $export['events'] = $view;

  $view = new view();
  $view->name = 'facts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Facts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Biodiversity facts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fact' => 'fact',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'facts';
  $translatables['facts'] = array(
    t('Master'),
    t('Biodiversity facts'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Page'),
  );
  $export['facts'] = $view;

  $view = new view();
  $view->name = 'faqs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FAQs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Frequently Asked Questions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_question_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_question_category']['id'] = 'field_question_category';
  $handler->display->display_options['fields']['field_question_category']['table'] = 'field_data_field_question_category';
  $handler->display->display_options['fields']['field_question_category']['field'] = 'field_question_category';
  $handler->display->display_options['fields']['field_question_category']['label'] = '';
  $handler->display->display_options['fields']['field_question_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_question_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_question_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'faqs:page_reorder';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faq' => 'faq',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 2;
  /* Filter criterion: Domain Access: Access Type */
  $handler->display->display_options['filters']['realm']['id'] = 'realm';
  $handler->display->display_options['filters']['realm']['table'] = 'domain_access';
  $handler->display->display_options['filters']['realm']['field'] = 'realm';
  $handler->display->display_options['filters']['realm']['value'] = array(
    'domain_site' => 'domain_site',
  );
  $handler->display->display_options['filters']['realm']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'faq';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'FAQs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'FAQs';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_reorder');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Order FAQs';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'update faq content on assigned domains';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_question_category' => 'field_question_category',
    'title_field' => 'title_field',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_question_category' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_question_category']['id'] = 'field_question_category';
  $handler->display->display_options['fields']['field_question_category']['table'] = 'field_data_field_question_category';
  $handler->display->display_options['fields']['field_question_category']['field'] = 'field_question_category';
  $handler->display->display_options['fields']['field_question_category']['label'] = '';
  $handler->display->display_options['fields']['field_question_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_question_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_question_category']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['path'] = 'faq/reorder';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Order FAQs';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'faq/all';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'FAQs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'FAQs';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['faqs'] = array(
    t('Master'),
    t('Frequently Asked Questions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
    t('Order FAQs'),
  );
  $export['faqs'] = $view;

  $view = new view();
  $view->name = 'home_page_image_slider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home Page Image Slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Front-Page Image Slider';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slick';
  $handler->display->display_options['style_options']['slide_field_wrapper'] = 0;
  $handler->display->display_options['style_options']['asnavfor_auto'] = 0;
  $handler->display->display_options['style_options']['optionset'] = 'home_slider';
  $handler->display->display_options['style_options']['skin'] = 'default';
  $handler->display->display_options['style_options']['slide_caption'] = array(
    'field_image' => 0,
    'title_field' => 0,
    'view_node' => 0,
    'body' => 0,
    'nothing' => 0,
  );
  $handler->display->display_options['style_options']['slide_overlay'] = '';
  $handler->display->display_options['style_options']['preserve_keys'] = 0;
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['overridables'] = array(
    'arrows' => 0,
    'autoplay' => 0,
    'dots' => 0,
    'draggable' => 0,
  );
  $handler->display->display_options['style_options']['cache'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entityqueue: Node Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'slideshow_www' => 'slideshow_www',
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'slider_image',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h2',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['field_api_classes'] = TRUE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Project dates */
  $handler->display->display_options['fields']['field_dates']['id'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['table'] = 'field_data_field_dates';
  $handler->display->display_options['fields']['field_dates']['field'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['label'] = '';
  $handler->display->display_options['fields']['field_dates']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dates']['type'] = 'event_date_formatter';
  $handler->display->display_options['fields']['field_dates']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="span12">
[field_image]
<div class="slick-content span6 well pull-right">
<h2>[title_field]</h2>
<p>[body-summary]</p>
<a href="[view_node]" class="more-link btn">[view_node]</a>
</div>
</div>';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '45',
    'trim_type' => 'words',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => '',
    'summary_handler' => 'trim',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['text'] = '[title_field]
[field_dates] 
[body]';
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Entityqueue: Node Queue Position */
  $handler->display->display_options['sorts']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['sorts']['entityqueue_relationship']['table'] = 'node';
  $handler->display->display_options['sorts']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Expire (field_expire) */
  $handler->display->display_options['filters']['field_expire_value']['id'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value']['table'] = 'field_data_field_expire';
  $handler->display->display_options['filters']['field_expire_value']['field'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expire_value']['group'] = 2;
  $handler->display->display_options['filters']['field_expire_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_expire_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expire (field_expire) */
  $handler->display->display_options['filters']['field_expire_value_1']['id'] = 'field_expire_value_1';
  $handler->display->display_options['filters']['field_expire_value_1']['table'] = 'field_data_field_expire';
  $handler->display->display_options['filters']['field_expire_value_1']['field'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expire_value_1']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['home_page_image_slider'] = array(
    t('Master'),
    t('Front-Page Image Slider'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Node Queue'),
    t('<div class="span12">
[field_image]
<div class="slick-content span6 well pull-right">
<h2>[title_field]</h2>
<p>[body-summary]</p>
<a href="[view_node]" class="more-link btn">[view_node]</a>
</div>
</div>'),
    t('[title_field]
[field_dates] 
[body]'),
    t('Block'),
  );
  $export['home_page_image_slider'] = $view;

  $view = new view();
  $view->name = 'latest_updates';
  $view->description = 'Front-page block with latest nodes';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Latest news & updates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest News & Updates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Project dates */
  $handler->display->display_options['fields']['field_dates']['id'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['table'] = 'field_data_field_dates';
  $handler->display->display_options['fields']['field_dates']['field'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['label'] = '';
  $handler->display->display_options['fields']['field_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dates']['type'] = 'event_date_formatter';
  $handler->display->display_options['fields']['field_dates']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'news' => 'news',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';

  /* Display: Front page latest */
  $handler = $view->new_display('block', 'Front page latest', 'block');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Project dates */
  $handler->display->display_options['fields']['field_dates']['id'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['table'] = 'field_data_field_dates';
  $handler->display->display_options['fields']['field_dates']['field'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['label'] = '';
  $handler->display->display_options['fields']['field_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dates']['type'] = 'event_date_formatter';
  $handler->display->display_options['fields']['field_dates']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '30',
    'trim_type' => 'words',
    'trim_suffix' => ' ...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Weight (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Content: Expire (field_expire) */
  $handler->display->display_options['filters']['field_expire_value']['id'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value']['table'] = 'field_data_field_expire';
  $handler->display->display_options['filters']['field_expire_value']['field'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expire_value']['group'] = 2;
  $handler->display->display_options['filters']['field_expire_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_expire_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expire (field_expire) */
  $handler->display->display_options['filters']['field_expire_value_1']['id'] = 'field_expire_value_1';
  $handler->display->display_options['filters']['field_expire_value_1']['table'] = 'field_data_field_expire';
  $handler->display->display_options['filters']['field_expire_value_1']['field'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expire_value_1']['group'] = 2;

  /* Display: News page */
  $handler = $view->new_display('page', 'News page', 'page_news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest News';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title_field';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '<div class=\'field-type\'> [type] </div> [title_field]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'day_month_year';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="field-dates">[created]</div>[body] [view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Expire (field_expire) */
  $handler->display->display_options['filters']['field_expire_value']['id'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value']['table'] = 'field_data_field_expire';
  $handler->display->display_options['filters']['field_expire_value']['field'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expire_value']['group'] = 2;
  $handler->display->display_options['filters']['field_expire_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_expire_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expire (field_expire) */
  $handler->display->display_options['filters']['field_expire_value_1']['id'] = 'field_expire_value_1';
  $handler->display->display_options['filters']['field_expire_value_1']['table'] = 'field_data_field_expire';
  $handler->display->display_options['filters']['field_expire_value_1']['field'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expire_value_1']['group'] = 2;
  $handler->display->display_options['path'] = 'news';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'News';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-information-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Events page */
  $handler = $view->new_display('page', 'Events page', 'page_events');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title_field';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '[title_field]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Project dates */
  $handler->display->display_options['fields']['field_dates']['id'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['table'] = 'field_data_field_dates';
  $handler->display->display_options['fields']['field_dates']['field'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['label'] = '';
  $handler->display->display_options['fields']['field_dates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dates']['type'] = 'event_date_formatter';
  $handler->display->display_options['fields']['field_dates']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class=\'field-dates\'>[field_dates]</div> [body] [view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['empty'] = '<div class=\'field-dates\'>[field_dates]</div>';
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Project dates -  start date (field_dates) */
  $handler->display->display_options['sorts']['field_dates_value']['id'] = 'field_dates_value';
  $handler->display->display_options['sorts']['field_dates_value']['table'] = 'field_data_field_dates';
  $handler->display->display_options['sorts']['field_dates_value']['field'] = 'field_dates_value';
  $handler->display->display_options['sorts']['field_dates_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Expire (field_expire) */
  $handler->display->display_options['filters']['field_expire_value']['id'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value']['table'] = 'field_data_field_expire';
  $handler->display->display_options['filters']['field_expire_value']['field'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_expire_value']['group'] = 2;
  $handler->display->display_options['filters']['field_expire_value']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_expire_value']['default_date'] = 'now';
  /* Filter criterion: Content: Expire (field_expire) */
  $handler->display->display_options['filters']['field_expire_value_1']['id'] = 'field_expire_value_1';
  $handler->display->display_options['filters']['field_expire_value_1']['table'] = 'field_data_field_expire';
  $handler->display->display_options['filters']['field_expire_value_1']['field'] = 'field_expire_value';
  $handler->display->display_options['filters']['field_expire_value_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_expire_value_1']['group'] = 2;
  $handler->display->display_options['path'] = 'events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-information-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['latest_updates'] = array(
    t('Master'),
    t('Latest News & Updates'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Read more »'),
    t('Front page latest'),
    t('News page'),
    t('Latest News'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<div class=\'field-type\'> [type] </div> [title_field]'),
    t('<div class="field-dates">[created]</div>[body] [view_node]'),
    t('Events page'),
    t('Latest Events'),
    t('[title_field]'),
    t('<div class=\'field-dates\'>[field_dates]</div> [body] [view_node]'),
    t('<div class=\'field-dates\'>[field_dates]</div>'),
  );
  $export['latest_updates'] = $view;

  $view = new view();
  $view->name = 'links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related websites';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title';
  $handler->display->display_options['style_options']['body_field'] = 'field_url';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_class'] = 'list-group-item-heading';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: URL */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_url']['click_sort_column'] = 'url';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body]<br>[field_url] ';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'link' => 'link',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_url' => 'field_url',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'links';
  $translatables['links'] = array(
    t('Master'),
    t('Related websites'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('[body]<br>[field_url] '),
    t('Post date'),
    t('Title'),
    t('Search'),
    t('Page'),
  );
  $export['links'] = $view;

  $view = new view();
  $view->name = 'national_focal_points';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'National Focal Points';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'National Focal Points Administration';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 250';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Countries */
  $handler->display->display_options['fields']['field_countries']['id'] = 'field_countries';
  $handler->display->display_options['fields']['field_countries']['table'] = 'field_data_field_countries';
  $handler->display->display_options['fields']['field_countries']['field'] = 'field_countries';
  $handler->display->display_options['fields']['field_countries']['label'] = 'Country';
  $handler->display->display_options['fields']['field_countries']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_countries']['delta_offset'] = '0';
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Content: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['type'] = 'text_plain';
  /* Field: Field: Department */
  $handler->display->display_options['fields']['field_department']['id'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['table'] = 'field_data_field_department';
  $handler->display->display_options['fields']['field_department']['field'] = 'field_department';
  $handler->display->display_options['fields']['field_department']['type'] = 'text_plain';
  /* Field: Field: Organization */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['type'] = 'text_plain';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cbd_nfp' => 'cbd_nfp',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cbd_nfp' => 'cbd_nfp',
  );
  /* Filter criterion: Content: Countries (field_countries) */
  $handler->display->display_options['filters']['field_countries_tid']['id'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['table'] = 'field_data_field_countries';
  $handler->display->display_options['filters']['field_countries_tid']['field'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_countries_tid']['expose']['operator_id'] = 'field_countries_tid_op';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['operator'] = 'field_countries_tid_op';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['identifier'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_countries_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_countries_tid']['vocabulary'] = 'countries';
  $handler->display->display_options['path'] = 'admin/content/nfp';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'National Focal Points';
  $handler->display->display_options['menu']['description'] = 'View the national focal points';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cbd_nfp' => 'cbd_nfp',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Countries (field_countries) */
  $handler->display->display_options['filters']['field_countries_tid']['id'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['table'] = 'field_data_field_countries';
  $handler->display->display_options['filters']['field_countries_tid']['field'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['value'] = '';
  $handler->display->display_options['filters']['field_countries_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_countries_tid']['expose']['operator_id'] = 'field_countries_tid_op';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['operator'] = 'field_countries_tid_op';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['identifier'] = 'field_countries_tid';
  $handler->display->display_options['filters']['field_countries_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_countries_tid']['vocabulary'] = 'countries';
  $translatables['national_focal_points'] = array(
    t('Master'),
    t('National Focal Points Administration'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('Title'),
    t('Country'),
    t('Email'),
    t('Address'),
    t('Department'),
    t('Organization'),
    t('Page'),
    t('Block'),
  );
  $export['national_focal_points'] = $view;

  $view = new view();
  $view->name = 'organizations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Organizations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organizations';
  $handler->display->display_options['css_class'] = 'logo-image';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body] [view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '30',
    'trim_type' => 'words',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: Type (field_organization_type) */
  $handler->display->display_options['sorts']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['sorts']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['sorts']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  $handler->display->display_options['sorts']['field_organization_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_organization_type_tid']['expose']['label'] = 'Type';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type (field_organization_type) */
  $handler->display->display_options['filters']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['operator_id'] = 'field_organization_type_tid_op';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['operator'] = 'field_organization_type_tid_op';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['identifier'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_organization_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_organization_type_tid']['vocabulary'] = 'organization_type';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'organizations';
  $translatables['organizations'] = array(
    t('Master'),
    t('Organizations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Read more »'),
    t('[body] [view_node]'),
    t('Title'),
    t('Type'),
    t('Search'),
    t('Page'),
  );
  $export['organizations'] = $view;

  $view = new view();
  $view->name = 'persons_network_directory';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Persons network directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Network directory';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Roles (field_nfp_roles) */
  $handler->display->display_options['relationships']['field_nfp_roles_value']['id'] = 'field_nfp_roles_value';
  $handler->display->display_options['relationships']['field_nfp_roles_value']['table'] = 'field_data_field_nfp_roles';
  $handler->display->display_options['relationships']['field_nfp_roles_value']['field'] = 'field_nfp_roles_value';
  $handler->display->display_options['relationships']['field_nfp_roles_value']['label'] = 'field collection field_nfp_roles';
  $handler->display->display_options['relationships']['field_nfp_roles_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Roles */
  $handler->display->display_options['fields']['field_nfp_roles']['id'] = 'field_nfp_roles';
  $handler->display->display_options['fields']['field_nfp_roles']['table'] = 'field_data_field_nfp_roles';
  $handler->display->display_options['fields']['field_nfp_roles']['field'] = 'field_nfp_roles';
  $handler->display->display_options['fields']['field_nfp_roles']['label'] = '';
  $handler->display->display_options['fields']['field_nfp_roles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nfp_roles']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_nfp_roles']['settings'] = array(
    'view_mode' => 'person_roles',
  );
  $handler->display->display_options['fields']['field_nfp_roles']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_nfp_roles']['multi_type'] = 'ul';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cbd_nfp' => 'cbd_nfp',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_person_positions' => 'field_person_positions',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'network-directory';
  $translatables['persons_network_directory'] = array(
    t('Master'),
    t('Network directory'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('field collection field_nfp_roles'),
    t('Search'),
    t('Page'),
  );
  $export['persons_network_directory'] = $view;

  $view = new view();
  $view->name = 'photo_galleries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo galleries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo galleries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_images';
  $handler->display->display_options['style_options']['heading_field'] = 'title';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'gallery' => 'gallery',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_images';
  $handler->display->display_options['style_options']['heading_field'] = 'title';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'photo-galleries';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Images';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-information-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['photo_galleries'] = array(
    t('Master'),
    t('Photo galleries'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Page'),
  );
  $export['photo_galleries'] = $view;

  $view = new view();
  $view->name = 'projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title_field';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '[title_field]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Project dates */
  $handler->display->display_options['fields']['field_dates']['id'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['table'] = 'field_data_field_dates';
  $handler->display->display_options['fields']['field_dates']['field'] = 'field_dates';
  $handler->display->display_options['fields']['field_dates']['type'] = 'event_date_formatter';
  $handler->display->display_options['fields']['field_dates']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<span class=\'field-dates\'>[field_dates]</span> [body] [view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Project dates -  start date (field_dates) */
  $handler->display->display_options['sorts']['field_dates_value']['id'] = 'field_dates_value';
  $handler->display->display_options['sorts']['field_dates_value']['table'] = 'field_data_field_dates';
  $handler->display->display_options['sorts']['field_dates_value']['field'] = 'field_dates_value';
  $handler->display->display_options['sorts']['field_dates_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_dates_value']['expose']['label'] = 'Project date';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_field_value']['expose']['label'] = 'Project name';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title_field' => 'title_field',
    'body' => 'body',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'listing');
  $handler->display->display_options['path'] = 'projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Projects';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-information-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_listing');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $translatables['projects'] = array(
    t('Master'),
    t('Projects'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('[title_field]'),
    t('Project dates'),
    t('Read more »'),
    t('<span class=\'field-dates\'>[field_dates]</span> [body] [view_node]'),
    t('Project date'),
    t('Project name'),
    t('Search'),
    t('Page'),
    t('Block'),
  );
  $export['projects'] = $view;

  $view = new view();
  $view->name = 'protected_areas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Protected areas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Protected areas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_image';
  $handler->display->display_options['style_options']['heading_field'] = 'title_field';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'image_listing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body][view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '100',
    'trim_type' => 'words',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'trim',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'protected_area' => 'protected_area',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'protected-areas';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Protected areas';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-information-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['protected_areas'] = array(
    t('Master'),
    t('Protected areas'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Read more »'),
    t('[body][view_node]'),
    t('Page'),
  );
  $export['protected_areas'] = $view;

  $view = new view();
  $view->name = 'reference_to_content_entity_reference_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reference to content entity reference view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'fact' => 'fact',
    'cbd_nfp' => 'cbd_nfp',
    'document' => 'document',
    'ecosystem' => 'ecosystem',
    'event' => 'event',
    'news' => 'news',
    'page' => 'page',
    'species' => 'species',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_tab');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'type',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'body' => 'body',
    'type' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['reference_to_content_entity_reference_view'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Entity Reference'),
  );
  $export['reference_to_content_entity_reference_view'] = $view;

  $view = new view();
  $view->name = 'species';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Species';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Species';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'field_species_main_common_name' => 'field_species_main_common_name',
    'field_species_class' => 'field_species_class',
    'field_species_family' => 'field_species_family',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_species_main_common_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_species_class' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_species_family' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Scientific name';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Main common name */
  $handler->display->display_options['fields']['field_species_main_common_name']['id'] = 'field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['table'] = 'field_data_field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['field'] = 'field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['label'] = 'Common name';
  $handler->display->display_options['fields']['field_species_main_common_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_species_main_common_name']['type'] = 'text_plain';
  /* Field: Content: Class */
  $handler->display->display_options['fields']['field_species_class']['id'] = 'field_species_class';
  $handler->display->display_options['fields']['field_species_class']['table'] = 'field_data_field_species_class';
  $handler->display->display_options['fields']['field_species_class']['field'] = 'field_species_class';
  $handler->display->display_options['fields']['field_species_class']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_species_class']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_species_family']['id'] = 'field_species_family';
  $handler->display->display_options['fields']['field_species_family']['table'] = 'field_data_field_species_family';
  $handler->display->display_options['fields']['field_species_family']['field'] = 'field_species_family';
  $handler->display->display_options['fields']['field_species_family']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_species_family']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'species' => 'species',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Content: Class (field_species_class) */
  $handler->display->display_options['filters']['field_species_class_tid']['id'] = 'field_species_class_tid';
  $handler->display->display_options['filters']['field_species_class_tid']['table'] = 'field_data_field_species_class';
  $handler->display->display_options['filters']['field_species_class_tid']['field'] = 'field_species_class_tid';
  $handler->display->display_options['filters']['field_species_class_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['operator_id'] = 'field_species_class_tid_op';
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['label'] = 'Class';
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['operator'] = 'field_species_class_tid_op';
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['identifier'] = 'field_species_class_tid';
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_species_class_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_species_class_tid']['vocabulary'] = 'species_class';
  /* Filter criterion: Content: Order (field_species_order) */
  $handler->display->display_options['filters']['field_species_order_tid']['id'] = 'field_species_order_tid';
  $handler->display->display_options['filters']['field_species_order_tid']['table'] = 'field_data_field_species_order';
  $handler->display->display_options['filters']['field_species_order_tid']['field'] = 'field_species_order_tid';
  $handler->display->display_options['filters']['field_species_order_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['operator_id'] = 'field_species_order_tid_op';
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['label'] = 'Order';
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['operator'] = 'field_species_order_tid_op';
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['identifier'] = 'field_species_order_tid';
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_species_order_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_species_order_tid']['vocabulary'] = 'species_order';
  /* Filter criterion: Content: Family (field_species_family) */
  $handler->display->display_options['filters']['field_species_family_tid']['id'] = 'field_species_family_tid';
  $handler->display->display_options['filters']['field_species_family_tid']['table'] = 'field_data_field_species_family';
  $handler->display->display_options['filters']['field_species_family_tid']['field'] = 'field_species_family_tid';
  $handler->display->display_options['filters']['field_species_family_tid']['value'] = '';
  $handler->display->display_options['filters']['field_species_family_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['operator_id'] = 'field_species_family_tid_op';
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['label'] = 'Family';
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['operator'] = 'field_species_family_tid_op';
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['identifier'] = 'field_species_family_tid';
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_species_family_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_species_family_tid']['vocabulary'] = 'species_family';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_images' => 'field_images',
    'title_field' => 'title_field',
    'field_species_main_common_name' => 'field_species_main_common_name',
    'field_species_class' => 'field_species_class',
    'field_species_order' => 'field_species_order',
    'field_species_family' => 'field_species_family',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_images' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_species_main_common_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_species_class' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_species_order' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_species_family' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Scientific name';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Main common name */
  $handler->display->display_options['fields']['field_species_main_common_name']['id'] = 'field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['table'] = 'field_data_field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['field'] = 'field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['label'] = 'Common name';
  $handler->display->display_options['fields']['field_species_main_common_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_species_main_common_name']['type'] = 'text_plain';
  /* Field: Content: Class */
  $handler->display->display_options['fields']['field_species_class']['id'] = 'field_species_class';
  $handler->display->display_options['fields']['field_species_class']['table'] = 'field_data_field_species_class';
  $handler->display->display_options['fields']['field_species_class']['field'] = 'field_species_class';
  $handler->display->display_options['fields']['field_species_class']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_species_class']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Order */
  $handler->display->display_options['fields']['field_species_order']['id'] = 'field_species_order';
  $handler->display->display_options['fields']['field_species_order']['table'] = 'field_data_field_species_order';
  $handler->display->display_options['fields']['field_species_order']['field'] = 'field_species_order';
  $handler->display->display_options['fields']['field_species_order']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_species_family']['id'] = 'field_species_family';
  $handler->display->display_options['fields']['field_species_family']['table'] = 'field_data_field_species_family';
  $handler->display->display_options['fields']['field_species_family']['field'] = 'field_species_family';
  $handler->display->display_options['fields']['field_species_family']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_species_family']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: IUCN status */
  $handler->display->display_options['fields']['field_redlist_status']['id'] = 'field_redlist_status';
  $handler->display->display_options['fields']['field_redlist_status']['table'] = 'field_data_field_redlist_status';
  $handler->display->display_options['fields']['field_redlist_status']['field'] = 'field_redlist_status';
  $handler->display->display_options['fields']['field_redlist_status']['label'] = 'IUCN Status';
  $handler->display->display_options['fields']['field_redlist_status']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'species' => 'species',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  $handler->display->display_options['filters']['current_all']['group'] = 1;
  /* Filter criterion: Content: Class (field_species_class) */
  $handler->display->display_options['filters']['field_species_class_tid']['id'] = 'field_species_class_tid';
  $handler->display->display_options['filters']['field_species_class_tid']['table'] = 'field_data_field_species_class';
  $handler->display->display_options['filters']['field_species_class_tid']['field'] = 'field_species_class_tid';
  $handler->display->display_options['filters']['field_species_class_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_species_class_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['operator_id'] = 'field_species_class_tid_op';
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['label'] = 'Class';
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['operator'] = 'field_species_class_tid_op';
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['identifier'] = 'field_species_class_tid';
  $handler->display->display_options['filters']['field_species_class_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_species_class_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_species_class_tid']['vocabulary'] = 'species_class';
  /* Filter criterion: Content: Order (field_species_order) */
  $handler->display->display_options['filters']['field_species_order_tid']['id'] = 'field_species_order_tid';
  $handler->display->display_options['filters']['field_species_order_tid']['table'] = 'field_data_field_species_order';
  $handler->display->display_options['filters']['field_species_order_tid']['field'] = 'field_species_order_tid';
  $handler->display->display_options['filters']['field_species_order_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_species_order_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['operator_id'] = 'field_species_order_tid_op';
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['label'] = 'Order';
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['operator'] = 'field_species_order_tid_op';
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['identifier'] = 'field_species_order_tid';
  $handler->display->display_options['filters']['field_species_order_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_species_order_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_species_order_tid']['vocabulary'] = 'species_order';
  /* Filter criterion: Content: Family (field_species_family) */
  $handler->display->display_options['filters']['field_species_family_tid']['id'] = 'field_species_family_tid';
  $handler->display->display_options['filters']['field_species_family_tid']['table'] = 'field_data_field_species_family';
  $handler->display->display_options['filters']['field_species_family_tid']['field'] = 'field_species_family_tid';
  $handler->display->display_options['filters']['field_species_family_tid']['value'] = '';
  $handler->display->display_options['filters']['field_species_family_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_species_family_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['operator_id'] = 'field_species_family_tid_op';
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['label'] = 'Family';
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['operator'] = 'field_species_family_tid_op';
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['identifier'] = 'field_species_family_tid';
  $handler->display->display_options['filters']['field_species_family_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_species_family_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_species_family_tid']['vocabulary'] = 'species_family';
  /* Filter criterion: Content: IUCN status (field_redlist_status) */
  $handler->display->display_options['filters']['field_redlist_status_tid']['id'] = 'field_redlist_status_tid';
  $handler->display->display_options['filters']['field_redlist_status_tid']['table'] = 'field_data_field_redlist_status';
  $handler->display->display_options['filters']['field_redlist_status_tid']['field'] = 'field_redlist_status_tid';
  $handler->display->display_options['filters']['field_redlist_status_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_redlist_status_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_redlist_status_tid']['expose']['operator_id'] = 'field_redlist_status_tid_op';
  $handler->display->display_options['filters']['field_redlist_status_tid']['expose']['label'] = 'IUCN status';
  $handler->display->display_options['filters']['field_redlist_status_tid']['expose']['operator'] = 'field_redlist_status_tid_op';
  $handler->display->display_options['filters']['field_redlist_status_tid']['expose']['identifier'] = 'field_redlist_status_tid';
  $handler->display->display_options['filters']['field_redlist_status_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_redlist_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_redlist_status_tid']['vocabulary'] = 'species_redlist_status';
  $handler->display->display_options['path'] = 'species';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Species';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-information-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Family related species */
  $handler = $view->new_display('block', 'Family related species', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Family related species';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => 'h4',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Main common name */
  $handler->display->display_options['fields']['field_species_main_common_name']['id'] = 'field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['table'] = 'field_data_field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['field'] = 'field_species_main_common_name';
  $handler->display->display_options['fields']['field_species_main_common_name']['label'] = '';
  $handler->display->display_options['fields']['field_species_main_common_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_species_main_common_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_species_main_common_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_species_main_common_name']['field_api_classes'] = TRUE;
  /* Field: Content: Genus */
  $handler->display->display_options['fields']['field_species_genus']['id'] = 'field_species_genus';
  $handler->display->display_options['fields']['field_species_genus']['table'] = 'field_data_field_species_genus';
  $handler->display->display_options['fields']['field_species_genus']['field'] = 'field_species_genus';
  $handler->display->display_options['fields']['field_species_genus']['label'] = '';
  $handler->display->display_options['fields']['field_species_genus']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_species_genus']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_species_genus']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_species_genus']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title_field]
[field_species_main_common_name] [field_species_genus]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Family (field_species_family) */
  $handler->display->display_options['arguments']['field_species_family_tid']['id'] = 'field_species_family_tid';
  $handler->display->display_options['arguments']['field_species_family_tid']['table'] = 'field_data_field_species_family';
  $handler->display->display_options['arguments']['field_species_family_tid']['field'] = 'field_species_family_tid';
  $handler->display->display_options['arguments']['field_species_family_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_species_family_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_species_family_tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['field_species_family_tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['field_species_family_tid']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['field_species_family_tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['field_species_family_tid']['default_argument_options']['vocabularies'] = array(
    'species_family' => 'species_family',
  );
  $handler->display->display_options['arguments']['field_species_family_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_species_family_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_species_family_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'species' => 'species',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $translatables['species'] = array(
    t('Master'),
    t('Species'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Scientific name'),
    t('Common name'),
    t('Class'),
    t('Family'),
    t('Order'),
    t('Block'),
    t('Page'),
    t('IUCN Status'),
    t('IUCN status'),
    t('Family related species'),
    t('[title_field]
[field_species_main_common_name] [field_species_genus]'),
    t('All'),
  );
  $export['species'] = $view;

  $view = new view();
  $view->name = 'sustainable_development_goals';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Sustainable Development Goals';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sustainable Development Goals';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'tid';
  $handler->display->display_options['style_options']['parent_field'] = 'tid_1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid_1']['label'] = 'Parent ID';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  /* Field: Entity translation: Image: translated */
  $handler->display->display_options['fields']['field_image_et']['id'] = 'field_image_et';
  $handler->display->display_options['fields']['field_image_et']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_et']['field'] = 'field_image_et';
  $handler->display->display_options['fields']['field_image_et']['label'] = '';
  $handler->display->display_options['fields']['field_image_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_et']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_et']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['name_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'sdg' => 'sdg',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tools/sdg';
  $translatables['sustainable_development_goals'] = array(
    t('Master'),
    t('Sustainable Development Goals'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Parent'),
    t('Term ID'),
    t('.'),
    t(','),
    t('Parent ID'),
    t('Page'),
  );
  $export['sustainable_development_goals'] = $view;

  $view = new view();
  $view->name = 'video_library';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Video Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_media_plugin_style';
  $handler->display->display_options['style_options']['image_field'] = 'field_video_link_1';
  $handler->display->display_options['style_options']['heading_field'] = 'title';
  $handler->display->display_options['style_options']['body_field'] = 'body';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Video */
  $handler->display->display_options['fields']['field_video_link_1']['id'] = 'field_video_link_1';
  $handler->display->display_options['fields']['field_video_link_1']['table'] = 'field_data_field_video_link';
  $handler->display->display_options['fields']['field_video_link_1']['field'] = 'field_video_link';
  $handler->display->display_options['fields']['field_video_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_video_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_link_1']['click_sort_column'] = 'input';
  $handler->display->display_options['fields']['field_video_link_1']['type'] = 'youtube_url';
  $handler->display->display_options['fields']['field_video_link_1']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more »';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[body][view_node]';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '100',
    'trim_type' => 'words',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'trim',
    'trim_options' => array(
      'text' => 0,
    ),
    'trim_preserve_tags' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title_field_value']['expose']['label'] = 'Title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );
  /* Filter criterion: Domain Access: Available on current domain */
  $handler->display->display_options['filters']['current_all']['id'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['table'] = 'domain_access';
  $handler->display->display_options['filters']['current_all']['field'] = 'current_all';
  $handler->display->display_options['filters']['current_all']['value'] = '1';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'videos';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Videos';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-information-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['video_library'] = array(
    t('Master'),
    t('Video Library'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Read more »'),
    t('[body][view_node]'),
    t('Post date'),
    t('Title'),
    t('Search'),
    t('Page'),
  );
  $export['video_library'] = $view;

  return $export;
}
