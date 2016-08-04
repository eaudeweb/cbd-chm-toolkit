<?php
/**
 * @file
 * Interface between domain_views.module and views.module.
 *
 * @ingroup domain_views
 */

/**
 * Field handler to provide simple renderer that allows linking to a domain.
 *
 * @ingroup domain_views
 */
class domain_views_handler_field_domain_access_current_all extends views_handler_field_boolean {

  /**
   * Constructor to provide additional field to add.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['realm'] = 'realm';
  }

  function render($values) {
    $value = $this->get_value($values);
    if (!empty($this->options['not'])) {
      $value = !$value;
    }
    // Set $value to true if the current realm is domain_site, otherwise the value is 0 and marked as false.
    if (isset($values->domain_access_realm) && $values->domain_access_realm == 'domain_site') {
      $value = TRUE;
    }

    if (isset($this->formats[$this->options['type']])) {
      return $value ? $this->formats[$this->options['type']][0] : $this->formats[$this->options['type']][1];
    }
    else {
      return $value ? $this->formats['yes-no'][0] : $this->formats['yes-no'][1];
    }
  }

}
