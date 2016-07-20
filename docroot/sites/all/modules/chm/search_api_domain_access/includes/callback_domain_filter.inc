<?php

/**
 * @file
 * Contains SearchApiAlterDomainFilter.
 */

/**
 * Represents a data alteration that restricts node indexes to some domains.
 */
class SearchApiAlterDomainFilter extends SearchApiAbstractAlterCallback {

  public function supportsIndex(SearchApiIndex $index) {
    return $index->getEntityType() === 'node';
  }

  public function configurationForm() {
    $options = array();
    foreach (domain_domains() as $value) {
      $options[$value['machine_name']] = $value['sitename'];
    }

    $form = array(
      'default' => array(
        '#type' => 'radios',
        '#title' => t('Which nodes should be indexed?'),
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
        '#description' => t('By default, the OR operator is used between the selected domains when filtering out nodes. This option only applies when more than 1 domain is selected.'),
        '#options' => array('AND' => 'AND', 'OR' => 'OR'),
        '#default_value' => isset($this->options['operator']) ? $this->options['operator'] : 'OR',
      ),
    );

    return $form;
  }

  public function alterItems(array &$items) {
    if (!empty($items) && isset($this->options['domains']) && !empty($this->options['domains'])) {
      // Get the options.
      $default = (bool) $this->options['default'];
      $selected_domains = $this->options['domains'];
      $operator = $this->options['operator'];

      // Collect the allowed and disallowed domains.
      $domains_by_machine_name = domain_list_by_machine_name();
      $domains = array('allowed' => array(), 'disallowed' => array());
      foreach ($domains_by_machine_name as $machine_name => $domain) {
        $key = 'disallowed';
        if (($default && in_array($machine_name, $selected_domains)) || (!$default && !in_array($machine_name, $selected_domains))) {
          $key = 'allowed';
        }
        $domains[$key][$domain['domain_id']] = $domain['domain_id'];
      }

      // Remove items which shouldn't be indexed.
      $domains_key = $default ? 'allowed' : 'disallowed';
      foreach ($items as $id => $item) {
        $intersect = array_intersect($item->domains, $domains[$domains_key]);
        switch (TRUE) {
          case $default && $operator === 'OR' && empty($intersect):
          case $default && $operator === 'AND' && count($intersect) !== count($domains[$domains_key]):
          case !$default && $operator === 'OR' && !empty($intersect):
          case !$default && $operator === 'AND' && count($intersect) === count($domains[$domains_key]):
            unset($items[$id]);
            break;
        }
      }
    }
  }
}
