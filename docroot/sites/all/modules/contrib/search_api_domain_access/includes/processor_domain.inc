<?php

/**
 * @file
 * Contains SearchApiDomainFilter.
 */

/**
 * Processor for filtering nodes based on their assigned domain(s).
 */
class SearchApiDomainFilter extends SearchApiAbstractProcessor {

  public function supportsIndex(SearchApiIndex $index) {
    // This processor is only compatible with node indexes, which hold the
    // domains value.
    $fields = $index->getFields();
    return $index->getEntityType() === 'node' && isset($fields['domains']);
  }

  public function configurationForm() {
    $form = parent::configurationForm();
    
    $options = array(
      'search_api_domain_active_domain' => t('Active domain'),
      'search_api_domain_user_domains' => t('User domains'),
    );
    foreach (domain_domains() as $value) {
      $options[$value['machine_name']] = $value['sitename'];
    }

    $form += array(
      'default' => array(
        '#type' => 'radios',
        '#title' => t('Which nodes should be included in the search results?'),
        '#default_value' => isset($this->options['default']) ? $this->options['default'] : 1,
        '#options' => array(
          1 => t('Exclude all nodes <strong>not assigned</strong> to one of the selected domains.'),
          0 => t('Exclude all nodes <strong>assigned</strong> to one of the selected domains.'),
        ),
      ),
      'domains' => array(
        '#type' => 'select',
        '#title' => t('Domains'),
        '#description' => t('Select one or more domains. This filter will not be applied if no domains are selected.'),
        '#default_value' => isset($this->options['domains']) ? $this->options['domains'] : array(),
        '#options' => $options,
        '#size' => min(4, count($options)),
        '#multiple' => TRUE,
      ),
      'operator' => array(
        '#type' => 'select',
        '#title' => t('Operator'),
        '#description' => t('By default, the OR operator is used between the selected domains. This option only applies when more than 1 domain is selected.'),
        '#options' => array('AND' => 'AND', 'OR' => 'OR'),
        '#default_value' => isset($this->options['operator']) ? $this->options['operator'] : 'OR',
      ),
    );

    return $form;
  }

  public function preprocessSearchQuery(SearchApiQuery $query) {
    parent::preprocessSearchQuery($query);

    if (isset($this->options['domains']) && !empty($this->options['domains'])) {
      // Get the options.
      $default = (bool) $this->options['default'];
      $conjunction = $this->options['operator'];
      $domains = $this->options['domains'];

      // Translate the selected domains to domain ids.
      $domains_by_machine_name = domain_list_by_machine_name();
      $selected_domains = array();
      foreach ($domains as $machine_name) {
        if (isset($domains_by_machine_name[$machine_name])) {
          $selected_domains[$domains_by_machine_name[$machine_name]['domain_id']] = $domains_by_machine_name[$machine_name]['domain_id'];
        }
        elseif ($machine_name === 'search_api_domain_active_domain') {
          $domain = domain_get_domain();
          // Users on our main CHM Network domain can search for any data
          if ($domain['domain_id'] != 1) {
            $selected_domains[$domain['domain_id']] = $domain['domain_id'];
          }
        }
        elseif ($machine_name === 'search_api_domain_user_domains') {
          global $user;
          $selected_domains += domain_get_user_domains($user);
        }
      }

      // Build the filter and add it to the query.
      $domain_filter = new SearchApiQueryFilter($conjunction);
      $condition_operator = $default ? '=' : '<>';
      foreach ($selected_domains as $selected_domain) {
        $domain_filter->condition('domains', $selected_domain, $condition_operator);
      }
      $query->filter($domain_filter);
    }
  }
}
