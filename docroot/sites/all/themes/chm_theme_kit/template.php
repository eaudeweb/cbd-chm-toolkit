<?php

/**
 * Returns HTML for an active facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function chm_theme_kit_facetapi_link_active($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );
  $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
  return theme_link($variables) . $link_text . ' ' . theme('facetapi_count', $variables);
}

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
  if ($domain = domain_get_domain()) {
    if ($domain['domain_id'] == PTKDomain::$DEMO_DOMAIN_ID) {
      $variables['classes_array'][] = 'country-portal';
    }
  }
}

function chm_theme_kit_preprocess_page(&$vars) {
  if (!empty($vars['navbar_classes_array'])) {
    if ($idx = array_search('container', $vars['navbar_classes_array'])) {
      unset($vars['navbar_classes_array'][$idx]);
    }
    unset($vars['navbar_classes_array']['container']);
  }
  if ($country = PTKDomain::getPortalCountry()) {
    if ($flag = PTK::getCountryFlag($country)) {
      $vars['logo'] = image_style_url('header_flag', $flag);
    }
  }
  else if ($domain = domain_get_domain()) {
    if ($domain['domain_id'] == PTKDomain::$DEMO_DOMAIN_ID) {
      $vars['logo'] = image_style_url('header_flag', 'public://images/flags/flag-bioland.png');
    }
    if ($domain['domain_id'] == PTKDomain::$CHM_DOMAIN_ID) {
      global $language;
      $langcode = $language->language;
      $uri = "public://images/logos/chm/logo-chm-$langcode.png";
      /** @var DrupalPublicStreamWrapper $w */
      $w = file_stream_wrapper_get_instance_by_uri($uri);
      if (!file_exists($w->realpath())) {
        $uri = "public://images/logos/chm/logo-chm-en.png";
      }
      $vars['logo'] = image_style_url('header_flag', $uri);
    }
  }
  if (strtolower(arg(0)) == 'search' || strtolower(arg(0)) == 'search-network') {
    $breadcrumb = array(
      l(t('Home'), '<front>')
    );
    drupal_set_breadcrumb($breadcrumb);
  }
}

function chm_theme_kit_breadcrumb($variables) {
  // Use the Path Breadcrumbs theme function if it should be used instead.
  if (_bootstrap_use_path_breadcrumbs()) {
    return path_breadcrumbs_breadcrumb($variables);
  }

  $output = '';
  $breadcrumb = $variables['breadcrumb'];

  // Determine if we are to display the breadcrumb.
  $bootstrap_breadcrumb = bootstrap_setting('breadcrumb');
  if (($bootstrap_breadcrumb == 1 || ($bootstrap_breadcrumb == 2 && arg(0) == 'admin')) && !empty($breadcrumb)) {
    $output = theme('item_list', array(
      'attributes' => array(
        'class' => array('breadcrumb', 'container'),
      ),
      'items' => $breadcrumb,
      'type' => 'ol',
    ));
  }
  return $output;
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


function chm_theme_kit_menu_link($variables) {
  $element = $variables['element'];
  $sub_menu = '';
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    } elseif ((!empty($element['#original_link']['depth'])) && $element['#original_link']['depth'] > 1) {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#title'] .= ' <a class="dropdown-toggle" role="button" data-toggle="dropdown"><span class="caret"></span></a>';
      $element['#attributes']['class'][] = 'dropdown-submenu';
      $element['#localized_options']['html'] = TRUE;
      $element['#localized_options']['attributes']['class'][] = 'dropdown-title';
    } else {
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#title'] .= ' <a class="dropdown-toggle" role="button" data-toggle="dropdown"><span class="caret"></span> </a>';
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;
      $element['#localized_options']['attributes']['class'][] = 'dropdown-title';
    }
  }
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}


/**
 * Implements hook_preprocess().
 *
 * {@inheritdoc}
 */
function chm_theme_kit_preprocess_button(&$vars) {
  $element = &$vars['element'];
  if ($element['#type'] == 'submit') {
     unset($element['#attributes']['class']['btn-info']);
     $element['#attributes']['class'][] = 'btn-primary';
  }
}