<?php

/**
 * Implements hook_views_plugins().
 */
function ptk_base_views_plugins() {
  $plugin = array();
  $plugin['query']['ptk_filter_domain_access_user_is_domain_editor_views_plugin'] = array(
    'title' => t('Filter nodes by user assigned domains'),
    'help' => t("Use this filter to show only the nodes assigned to domains where current user is assigned as editor"),
    'handler' => 'ptk_filter_domain_access_user_is_domain_editor_views_plugin',
  );
  return $plugin;
}

/**
 * Implementation of hook_views_data().
 */
function ptk_base_views_data() {
  $data = array();
  $data['domain_access']['current_user_is_editor'] = array(
    'title' => t('Node assigned to domains user is editor (PTK)'),
    'help' => t('Filters out nodes not available on domain(s) where user is currently assigned as editor'),
    'filter' => array(
      'handler' => 'domain_views_handler_filter_domain_current_user_is_editor',
      'label' => t("Available on domains where current user is assigned as editor"),
    ),
  );
  return $data;
}


/**
 *
 * Get the latest 4 tools. (At least one OiRA tool & one E-tool)
 */
class domain_views_handler_filter_domain_current_user_is_editor extends views_handler_filter_boolean_operator {

  /**
   * Overrides views_handler_field::query().
   */
  function query() {
    if ($this->value) {
      global $user;
      if (!PTK::userIsAdministrator($user)) {
        /** @var views_plugin_query_default $query */
        $query = $this->query;
        $domain_access = $this->ensure_my_table();
        $join = new views_join;
        $join->construct('domain_editor', $domain_access, 'gid', 'domain_id', array());
        $domain_editor = $query->add_relationship('domain_editor', $join, $domain_access);
        $and = db_and()->condition($domain_access . '.realm', 'domain_site')->condition($domain_access . '.gid', 0);
        $or = db_or()->condition($domain_editor . '.uid', $user->uid)->condition($and);
        $query->add_where($this->options['group'], $or);

     }
    }
  }
}
