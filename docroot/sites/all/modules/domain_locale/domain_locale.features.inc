<?php
/**
 * @file
 * Features integration for Domain Locale.
 */

/**
 * Implements hook_features_export().
 */
function domain_locale_features_export($data, &$export, $module_name) {
  $export['dependencies']['domain_locale'] = 'domain_locale';
  $list = domain_locale_features_selection($data);
  foreach ($list as $machine_name) {
    $export['features']['domain_locale'][$machine_name] = $machine_name;
  }
  domain_locale_features_export_set_wipe_tables($export, $data, 'domain_locale');
  return array();
}

/**
 * Implements hook_features_export_options().
 */
function domain_locale_features_export_options() {
  return domain_locale_features_get_options();
}

/**
 * Implements hook_features_export_render().
 */
function domain_locale_features_export_render($module_name, $data, $export = NULL) { // TODO remake this function
  domain_locale_features_load($module_name, 'domain_locale_default_locales', FALSE);
  $code = array();
  $code[] = '  $locales = array();';
  // Set the wipe tables item.
  if ($wipe = domain_locale_features_export_wipe_tables_code($data, $code, $export, 'locales') && empty($export)) {  // domains to locales
    // list all domain locales
    foreach (domain_locale_list(FALSE) as $domain_id => $languages) {
      $this_domain = domain_lookup($domain_id);
      foreach ($languages as $language => $weight) {
        $data[$this_domain['machine_name'] . '__locale-placeholder__' . $language] = $this_domain['machine_name'] . '__locale-placeholder__' . $language;
      }
    }
  }
  // remove wipe form $data as it is already on $code
  unset($data['wipe-domain-locale-tables']);
  // Get all enabled languages for each domain_id
  $locales = domain_locale_list(FALSE);
  $exportable = array();
  foreach ($data as $name) {
    //dpm($name);
    // Separate domain machine-name and language code
    $items = explode('__locale-placeholder__', $name);
    if (isset($items[1])) {
      $domain_machine_name = $items[0];
      $language = $items[1];
      // Get the domain information
      $domain_info = domain_machine_name_load($domain_machine_name);
      if (isset($locales[$domain_info['domain_id']][$language]['weight'])) {
        // Get the weight of the language
        $weight = $locales[$domain_info['domain_id']][$language]['weight'];
        //write the locale data on the exportable array
        $exportable[$domain_machine_name][$language] = $weight;
      }
    }
  }
  // Write $exportable it it exists.
  if (isset($exportable)) {
    foreach ($exportable as $export_name => $export_vars) {
      $code[] = "  \$locales['" . $export_name . "'] = " . features_var_export($export_vars, '  ') . ";";
    }
  }
  // Close the code
  $code[] = "\n  return \$locales;";
  // Return the output
  $output = implode("\n", $code);
  return array('domain_locale_default_locales' => $output);
}

/**
 * Implements hook_features_revert().
 */
function domain_locale_features_revert($module) {
  return domain_locale_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function domain_locale_features_rebuild($module) {
  if ($defaults = domain_locale_features_load($module, 'domain_locale_default_locales', TRUE)) {
 /*   // Check for hard rebuild/revert.
    if ($wipe = domain_locale_features_wipe_tables($defaults)) {
      // list all domain locales
      foreach (domain_locale_list(FALSE) as $domain_id => $languages) {
        $this_domain = domain_lookup($domain_id);
        foreach ($languages as $language => $weight) {
          $locale_machine_name = $this_domain['machine_name'] . '__locale-placeholder__' . $language;
          $locales[$locale_machine_name] = array(
            'domain_id'           => $this_domain['domain_id'],
            'locale_machine_name' => $locale_machine_name,
            'language'            => $language,
            'weight'              => $weight,
            );
        }
      }
      // loop locales and delete entries that does not exist anymore
      foreach ($locales as $locale) {
        if (!isset($defaults[$locale['locale_machine_name']])) {
          // Delete a single language
          domain_locale_delete_domain_language($locale['domain_id'], $locale['language']);
        }
      }
    }
    // Save the locales in this feature.
    foreach ($defaults as $domain_machine_name => $languages) {
      // Get the languages and weights for this domain
      foreach ($languages as $language => $weight) {
        $params = array(
          'language' => $language,
          'weight'   => $weight,
        )
      }
      // Load this domain
      $this_domain = domain_machine_name_load($domain_machine_name);
      // Write locale
      domain_locale_insert_domain($this_domain['domain_id'], $params);
    }
  */
  }
}
