<?php

/**
 * Implements hook_preprocess_HOOK().
 */
function chm_theme_kit_preprocess_html(&$variables) {
  if (!empty($variables['head_title_array'])) {
    $hta = $variables['head_title_array'];
    if (is_array($hta) && isset($hta[0])) {
      $variables['head_title'] = $hta[0];
    }
    else {
      $variables['head_title'] = implode(' - ', $hta);
    }
  }

  if ($country = PTKDomain::getPortalCountry()) {
    $variables['classes_array'][] = 'country-portal';
    $variables['classes_array'][] = 'country-' . strtolower($country->iso2l);
  }
}

function chm_theme_kit_preprocess_page(&$vars) {
  if ($country = PTKDomain::getPortalCountry()) {
    if ($flag = PTK::getCountryFlag($country)) {
      $vars['logo'] = image_style_url('header_flag', $flag);
    }
  }
}


function chm_theme_kit_css_alter(&$css) {
  $path = drupal_get_path('module', 'addressfield');
  if (!empty($path) && isset($css[$path . '/addressfield.css'])) {
    unset($css[$path . '/addressfield.css']);
  }
}

/**
 * Theme flexible layout of panels.
 * Copied the panels function and removed the css files.
 */
function chm_theme_kit_panels_flexible($vars) {
  $css_id = $vars['css_id'];
  $content = $vars['content'];
  $settings = $vars['settings'];
  $display = $vars['display'];
  $layout = $vars['layout'];
  $handler = $vars['renderer'];
  panels_flexible_convert_settings($settings, $layout);
  $renderer = panels_flexible_create_renderer(FALSE, $css_id, $content, $settings, $display, $layout, $handler);
  $output = "<div class=\"panel-flexible " . $renderer->base['canvas'] . " clearfix\" $renderer->id_str>\n";
  $output .= "<div class=\"panel-flexible-inside " . $renderer->base['canvas'] . "-inside\">\n";
  $output .= panels_flexible_render_items($renderer, $settings['items']['canvas']['children'], $renderer->base['canvas']);
  // Wrap the whole thing up nice and snug
  $output .= "</div>\n</div>\n";
  return $output;
}
