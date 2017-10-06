<?php
/**
 * @file views-views-json-style-simple.tpl.php
 * Default template for the Views JSON style plugin using the simple format
 *
 * Variables:
 * - $view: The View object.
 * - $rows: Hierachial array of key=>value pairs to convert to JSON
 * - $options: Array of options for this style
 *
 * @ingroup views_templates
 */

$jsonp_prefix = $options['jsonp_prefix'];
foreach ($rows['items'] as &$row) {
  $tid = $row['item']['tid'];
  $term = (array)taxonomy_term_load($tid);
  foreach($term as $name => $values) {
    if (strpos($name, 'field') === FALSE) {
      continue;
    }
    $name = str_replace(['field_', '_field'], ['', ''], $name);
    foreach($values as $lang => $value) {
      $suffix = ($lang == 'und') ? '' : '_' . $lang;
      $key = $name . $suffix;

      if (isset($value[0]['uri'])) {
        $row['item'][$name . $suffix] = file_create_url($value[0]['uri']);
      }
      elseif (isset($value[0]['tid'])) {
        $rel_term = taxonomy_term_load($value[0]['tid']);
        $row['item'][$name . $suffix] = $rel_term->name;
      }
      elseif (isset($value[0]['safe_value'])) {
        $row['item'][$name . $suffix] = $value[0]['safe_value'];
      }
      elseif (isset($value[0]['value'])) {
        if ($value[0]['value']) {
          $row['item'][$name . $suffix] = $value[0]['value'];
        }
      }

    }
  }
  $row['item']['translations'] = array_keys($term['translations']->data);
}

if ($view->override_path) {
  // We're inside a live preview where the JSON is pretty-printed.
  $json = _views_json_encode_formatted($rows, $options);
  if ($jsonp_prefix) $json = "$jsonp_prefix($json)";
  print "<code>$json</code>";
}
else {
  $json = _views_json_json_encode($rows, $bitmask);
  if ($options['remove_newlines']) {
     $json = preg_replace(array('/\\\\n/'), '', $json);
  }

  if (isset($_GET[$jsonp_prefix]) && $jsonp_prefix) {
    $json = check_plain($_GET[$jsonp_prefix]) . '(' . $json . ')';
  }

  if ($options['using_views_api_mode']) {
    // We're in Views API mode.
    print $json;
  }
  else {
    // We want to send the JSON as a server response so switch the content
    // type and stop further processing of the page.
    $content_type = ($options['content_type'] == 'default') ? 'application/json' : $options['content_type'];
    drupal_add_http_header("Content-Type", "$content_type; charset=utf-8");
    print $json;
    drupal_page_footer();
    exit;
  }
}
