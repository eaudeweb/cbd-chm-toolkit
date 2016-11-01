<?php

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render each item representing a country on a map.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_amcharts_ammap_world_countries extends views_plugin_style {

  /**
   * Set default options
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['iso_code_field'] = array('default' => '');
    $options['tooltip_field'] = array('default' => '');
    $options['dataProvider']['map'] = array('default' => 'worldLow');
    $options['areaSettings']['autoZoom'] = array('default' => false);
    $options['areaSettings']['selectedColor'] = array('default' => '#CC0000');
    $options['smallMap'] = array('default' => false);

    return $options;
  }

  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $field_options = array('' => t('<None>'));
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      $field_options[$handler->options['id']] = (!empty($handler->options['label'])) ? $handler->options['label'] : $handler->options['id'];
    }

    $form['iso_code_field'] = array(
        '#type' => 'select',
        '#title' => t('ISO code field'),
        '#options' => $field_options,
        '#default_value' => $this->options['iso_code_field'],
        '#description' => t('Select the field containing the country ISO code (either 2 or 3-letter code)'),
        '#required' => TRUE,
    );
    $form['tooltip_field'] = array(
        '#type' => 'select',
        '#title' => t('Tooltip field'),
        '#options' => $field_options,
        '#default_value' => $this->options['tooltip_field'],
        '#description' => t('Select the field containing the description contained within the country tooltip'),
        '#required' => FAlSE,
    );

    $options = array(
        '' => t('<None>'),
        'worldLow' => 'World, low resolution',
        'worldHigh' => 'World, high resolution'
    );
    $form['dataProvider']['map'] = array(
        '#type' => 'select',
        '#title' => t('Data provider'),
        '#options' => $options,
        '#default_value' => $this->options['dataProvider']['map'],
        '#description' => t('Map quality - low (~100kB), high (~1MB)'),
    );
    $form['areaSettings']['autoZoom'] = array(
        '#type' => 'checkbox',
        '#title' => t('Use AutoZoom'),
        '#value' => true,
        '#default_value' => $this->options['areaSettings']['autoZoom'],
        '#description' => t('Check to zoom-in the map on the clicked area'),
    );
    $form['areaSettings']['selectedColor'] = array(
        '#type' => 'textfield',
        '#title' => t('Selected color'),
        '#default_value' => $this->options['areaSettings']['selectedColor'],
        '#description' => t('Hex color of the selected area (ex. #c942e2)'),
    );
    $form['smallMap'] = array(
        '#type' => 'checkbox',
        '#title' => t('Show minimap'),
        '#default_value' => $this->options['smallMap'],
    );
  }

  /**
   * Validate the options form.
   */
  public function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    // Check if highlight color is a valid hex color.
    if (!preg_match('/^#[a-f0-9]{6}$/i', $form_state['values']['style_options']['areaSettings']['selectedColor'])) {
      form_set_error($form['areaSettings']['selectedColor'], t('Highlight colour must be a valid hex code in the form #RRGGBB.'));
    }
  }

  public function render() {
    if (isset($this->view->live_preview) && $this->view->live_preview) {
      return t('This view is not compatible with live preview.');
    }
    return parent::render();
  }

  public static function extract_countries_from_rows($variables) {
    $ret = array();
    $rows = $variables['rows'];
    $options = $variables['options'];
    $id_field = 'field_' . $options['iso_code_field'];
    $tooltip_field = 'field_' . $options['tooltip_field'];
    foreach ($rows as $row) {
      $description = NULL;
      if (!empty($row->{$tooltip_field}[0]['rendered']['#access'])
          && $value = drupal_render($row->{$tooltip_field}[0]['rendered'])) {
        $description = $value;
      }
      if (!empty($row->{$id_field}[0]['rendered']['#access'])
          && $id = drupal_render($row->{$id_field}[0]['rendered'])) {
        $id = strtoupper($id);
        if (array_key_exists($id, $ret)) {
          if (!empty($description)) {
            $ret[$id]['description'] .= '<br>' . $description;
          }
        }
        else {
          $ret[$id] = array('description' => $description);
        }
      }
    }
    return $ret;
  }
}
