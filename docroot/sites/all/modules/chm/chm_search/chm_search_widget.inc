<?php

class CHM_SearchApi_Facetapi_QueryType_DateRangeQueryType extends SearchApiFacetapiDate implements FacetapiQueryTypeInterface {

  /**
   * Implements FacetapiQueryTypeInterface::getType().
   */
  static public function getType() {
    return 'date_range';
  }

  /**
   * Implements FacetapiQueryTypeInterface::execute().
   */
  public function execute($query) {
    $this->adapter->addFacet($this->facet, $query);
    if ($active = $this->adapter->getActiveItems($this->facet)) {
      // Check the first value since only one is allowed.
      $filter = self::mapFacetItemToFilter(key($active), $this->facet);
      if ($filter) {
        $this->addFacetFilter($query, $this->facet['field'], $filter);
      }
    }
  }

  /**
   * Maps a facet item to a filter.
   *
   * @param string $range_machine_name
   *   For example 'past_hour'.
   *
   * @return string|false
   *   A string that can be used as a filter, false if no filter was found.
   */
  public static function mapFacetItemToFilter($range_machine_name, $facet) {
    $range_machine_name = str_replace(array('[',']'), array('',''), $range_machine_name);
    $start_end = explode(' TO ', $range_machine_name);
    $start = mktime(0, 0, 0, 1, 1, $start_end[0]);
    $end = mktime(0, 0, 0, 1, 1, $start_end[1]+1)-1;

    $filter_str = "[$start TO $end]";
    return $filter_str;
  }
}

/**
 * @file
 * Widget for facets rendered as UI slider with Min/Max.
 */
class CustomSearchApiRangesWidgetUISlider extends FacetapiWidget {

  /**
   * Renders the links.
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];

    $theme_suffix = '';
    $theme_suffix .= '__' . preg_replace('/\W+/', '_', $this->facet->getAdapter()->getSearcher());
    $theme_suffix .= '__' . preg_replace('/\W+/', '_', $this->facet['field alias']);

    $settings = $this->settings->settings;
    $step = isset($settings['slider-step']) ? $settings['slider-step'] : 1;
    $round_precision = isset($settings['round-precision']) ? (int)$settings['round-precision'] : 0;
    $element = array(
      '#theme' => 'chm_search_slider' . $theme_suffix,
      '#slider' => $this->_buildUISliderForm(),
      '#prefix' => '<div id="search-api-ranges-' . $this->facet['field alias'] . '">',
      '#suffix' => '</div>',
      '#attached' => array(
        'js' => array(
          array(
            'data' => array(
              'chm_search' => array(
                $this->facet['field alias'] => array(
                  'slider-step' => $step,
                  'round-precision' => $round_precision,
                ),
              ),
            ),
            'type' => 'setting'
          ),
        ),
      ),
    );
  }

  /**
   * Allows the widget to provide additional settings to the form.
   */
  function settingsForm(&$form, &$form_state) {

    $form['widget']['widget_settings']['links'][$this->id]['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#default_value' => $this->settings->settings['name'],
      '#description' => t('The name of the range field.'),
      '#states' => array('visible' => array('select[name="widget"]' => array('value' => $this->id),),),
    );
    $form['widget']['widget_settings']['links'][$this->id]['prefix'] = array(
      '#type' => 'textfield',
      '#title' => t('Prefix'),
      '#default_value' => $this->settings->settings['prefix'],
      '#description' => t('Adds a prefix to the slider, e.g. $, #.'),
      '#states' => array('visible' => array('select[name="widget"]' => array('value' => $this->id),),),
    );
    $form['widget']['widget_settings']['links'][$this->id]['suffix'] = array(
      '#type' => 'textfield',
      '#title' => t('Suffix'),
      '#default_value' => $this->settings->settings['suffix'],
      '#description' => t('Adds a suffix to the slider, e.g. &euro;, pcs., etc.'),
      '#states' => array('visible' => array('select[name="widget"]' => array('value' => $this->id),),),
    );
    $form['widget']['widget_settings']['links'][$this->id]['auto-submit-delay'] = array(
      '#type' => 'textfield',
      '#title' => t('Auto Submit Delay'),
      '#default_value' => $this->settings->settings['auto-submit-delay'],
      '#description' => t('Automatically submit form after the user changes 
        releases slider handles. Enter a delay in milliseconds,
        i.e. 1000 for 1 second.'),
      '#states' => array('visible' => array('select[name="widget"]' => array('value' => $this->id),),),
    );
  $form['widget']['widget_settings']['links'][$this->id]['slider-step'] = array(
      '#type' => 'textfield',
      '#title' => t('Step for the slider'),
      '#default_value' => is_numeric($this->settings->settings['slider-step']) ? $this->settings->settings['slider-step'] : 1,
      '#description' => t('Default is 1. Can be decimal: 0.1, 0.5 and so on. Use point as delimeter in decimals. From jQuery UI API documentation: Determines the size or amount of each interval or step the slider takes between the min and max. The full specified value range of the slider (max - min) should be evenly divisible by the step.'),
      //'#states' => array('invisible' => array( ':input[name="use-decimals"]' => array('checked' => FALSE),),),
      '#states' => array('visible' => array('select[name="widget"]' => array('value' => $this->id),),),
    );
  $form['widget']['widget_settings']['links'][$this->id]['round-precision'] = array(
      '#type' => 'textfield',
      '#title' => t('Round precision'),
      '#default_value' => is_numeric($this->settings->settings['round-precision']) ? (int)$this->settings->settings['round-precision'] : 0,
      '#description' => t('Specifies the number of decimal digits to round to. Default is 0. Can be only integer number.'),
      //'#states' => array('invisible' => array( ':input[name="use-decimals"]' => array('checked' => FALSE),),),
      '#states' => array('visible' => array('select[name="widget"]' => array('value' => $this->id),),),
    );
  }

  /**
   * Returns defaults for the settings form.
   */
  function getDefaultSettings() {

    return array(
      'name' => '',
      'prefix' => '',
      'suffix' => '',
      'auto-submit-delay' => 1500,
      'slider-step' => 1,
      'round-precision' => 0,
    );
  }

  /**
   * Builds a UI slider themed form.
   * Performs min/max queries through Search API.
   */
  public function _buildUISliderForm() {
    $slider = array();

    // Get Search API stuff
    $searcher = $this->facet->getAdapter()->getSearcher();
    $index_id = explode('@', $searcher);
    $index = search_api_index_load($index_id[1]);
    list($query, $results) = $this->facet->getAdapter()->getCurrentSearch();
    $settings = $this->settings->settings;
    $round_precision = isset($settings['round-precision']) ? (int)$settings['round-precision'] : 0;
    // Make a clone of the query, as to not alter the current search query
    $query = clone $query;

    $filters = &$query->getFilter()->getFilters();
    $tag = 'facet:' . $this->facet['field alias'];
    foreach ($filters as $key => $filter) {
      if (is_array($filter) && $this->facet['field alias']==$filter[0]) {
        unset($filters[$key]);
        continue;
      }
      if (isset($filter->tags) && is_array($filter->tags) && in_array($tag, $filter->tags)) {
        unset($filters[$key]);
      }
    }

      // Prepare variables for min/max query
    $variables = array(
      'index' => $index,
      'range_field' => $this->facet['field alias'],
      'query' => $query,
      'round-precision' => $round_precision,
    );

    //@todo fid how to get query without filter or how to clear filters... - extra solr call. or may be to use drupal to get min max field... or set from settings...

    $max_value = search_api_ranges_minmax($variables, 'DESC');
    if ($max_value) {
      $max_value = date('Y', $max_value);
    }

    // Query the min/max values for the range slider
    $min_value = search_api_ranges_minmax($variables, 'ASC');
    if ($min_value) {
      $min_value = date('Y', $min_value);
    }

    // Kill widget if there is nothing to do
    if (empty($min_value) && empty($max_value)) {
      return array();
    };

    // Calculate user input from/to values (different concept than min/max)
    foreach ($this->facet->getAdapter()->getAllActiveItems() as $key => $active_item) {
      if ($active_item['field alias'] == $this->facet['field alias']) {
        $values = explode(' ', substr($active_item['value'], 1, -1));
        $from_value = round($values[0], $round_precision, PHP_ROUND_HALF_DOWN);
        $to_value = round($values[2], $round_precision, PHP_ROUND_HALF_UP);
        break;
      };
    };

    // User from/to cannot exceed queried min/max, adjust if needed
    if (!isset($from_value) || $from_value < $min_value) {
      $from_value = $min_value;
    };
    if (!isset($to_value) || $max_value < $to_value) {
      $to_value = $max_value;
    };

    // Get facet path field/alias
    $range_field = $this->facet['field alias'];
    if (module_exists('facetapi_pretty_paths')) {
      $processor = new FacetapiUrlProcessorPrettyPaths($this->facet->getAdapter());
      $range_field = $processor->getFacetPrettyPathsAlias($this->facet->getFacet());
    };

    // Prepare the slider variables and return themed form
    // @see search-api-ranges-slider.tpl.php
    $variables = array(
      'range_field' => rawurlencode($range_field),
      'name' => $this->settings->settings['name'],
      'prefix' => $this->settings->settings['prefix'],
      'suffix' => $this->settings->settings['suffix'],
      'min' => $min_value,
      'max' => $max_value,
      'from' => $from_value,
      'to' => $to_value,
      'auto_submit_delay' => is_numeric($this->settings->settings['auto-submit-delay']) ? $this->settings->settings['auto-submit-delay'] : 0,
      'active_items' => $this->facet->getAdapter()->getAllActiveItems(),
      'target' => $this->facet->getAdapter()->getSearchPath(),
    );
    // We need to generate unique form IDs in case multiple forms get rendered
    // on the same page. chm_search_forms() takes care of mapping them
    // back to the base form ID 'chm_search_block_slider_view_form'.
    return drupal_get_form('chm_search_block_slider_view_form_' . $range_field, $variables);
  }

}

class CustomFacetapiWidgetLinks extends FacetapiWidget {

  /**
   * Overrides FacetapiWidget::__construct().
   *
   * For links, it is better to use the machine name of the facet as opposed to
   * the alias for the key. Alias are usually, but not necessarily, unique. It
   * doesn't make sense to group links in the same element as they are usually
   * rendered in blocks with are separate from one another.
   */
  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);
    $this->jsSettings['limit'] = $this->settings->settings['soft_limit'];
    $this->key = $facet['name'];
  }

  /**
   * Implements FacetapiWidget::execute().
   *
   * Transforms the render array into something that can be themed by
   * theme_item_list().
   *
   * @see FacetapiWidgetLinks::setThemeHooks()
   * @see FacetapiWidgetLinks::buildListItems()
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];
    $range_field = $this->facet['field alias'];

    // Get facet path field/alias
    if (module_exists('facetapi_pretty_paths')) {
      $processor = new FacetapiUrlProcessorPrettyPaths($this->facet->getAdapter());
      $range_field = $processor->getFacetPrettyPathsAlias($this->facet->getFacet());
    };
    // Sets each item's theme hook, builds item list.
    $this->setThemeHooks($element);
    $element = array(
      '#theme' => 'item_list',
      '#items' => $this->buildListItems($element),
      '#attributes' => $this->build['#attributes'],
    );
  }

  /**
   * Recursive function that sets each item's theme hook.
   *
   * The indivual items will be rendered by different theme hooks depending on
   * whether or not they are active.
   *
   * @param array &$build
   *   A render array containing the facet items.
   *
   * @return FacetapiWidget
   *   An instance of this class.
   *
   * @see theme_facetapi_link_active()
   * @see theme_facetapi_link_inactive()
   */
  protected function setThemeHooks(array &$build) {
    foreach ($build as $value => &$item) {
      $item['#theme'] = ($item['#active']) ? 'facetapi_link_active' : 'facetapi_link_inactive';
      if (!empty($item['#item_children'])) {
        $this->setThemeHooks($item['#item_children']);
      }
    }
    return $this;
  }

  /**
   * Transforms the render array for use with theme_item_list().
   *
   * The recursion allows this function to act on the various levels of a
   * hierarchical data set.
   *
   * @param array $build
   *   The items in the facet's render array being transformed.
   *
   * @return array
   *   The "items" parameter for theme_item_list().
   */
  function buildListItems($build) {
    $settings = $this->settings->settings;

    // Initializes links attributes, adds rel="nofollow" if configured.
    $attributes = ($settings['nofollow']) ? array('rel' => 'nofollow') : array();
    $attributes += array('class' => $this->getItemClasses());

    // Builds rows.
    $items = array();
    foreach ($build as $value => $item) {
      $row = array('class' => array());

      // Allow adding classes via altering.
      if (isset($item['#class'])) {
        $attributes['class'] = array_merge($attributes['class'], $item['#class']);
      }
      // Initializes variables passed to theme hook.
      $variables = array(
        'text' => $item['#markup'],
        'path' => $item['#path'],
        'count' => $item['#count'],
        'options' => array(
          'attributes' => $attributes,
          'html' => $item['#html'],
          'query' => $item['#query'],
        ),
      );

      // Adds the facetapi-zero-results class to items that have no results.
      if (!$item['#count']) {
        $variables['options']['attributes']['class'][] = 'facetapi-zero-results';
      }

      // Add an ID to identify this link.
      $variables['options']['attributes']['id'] = drupal_html_id('facetapi-link');

      // If the item has no children, it is a leaf.
      if (empty($item['#item_children'])) {
        $row['class'][] = 'leaf';
      }
      else {
        // If the item is active or the "show_expanded" setting is selected,
        // show this item as expanded so we see its children.
        if ($item['#active'] || !empty($settings['show_expanded'])) {
          $row['class'][] = 'expanded';
          $row['children'] = $this->buildListItems($item['#item_children']);
        }
        else {
          $row['class'][] = 'collapsed';
        }
      }

      // Gets theme hook, adds last minute classes.
      $class = ($item['#active']) ? 'facetapi-active' : 'facetapi-inactive';
      $variables['options']['attributes']['class'][] = $class;

      // Themes the link, adds row to items.
      $row['data'] = theme($item['#theme'], $variables);
      $items[] = $row;
    }

    return $items;
  }

  /**
   * Gets the base class array for a facet item.
   *
   * Classes that extend FacetapiWidgetLinks will often overide this method to
   * alter the link displays via CSS without having to touch the render array.
   *
   * @return array
   *   An array of classes.
   */
  function getItemClasses() {
    return array();
  }

  /**
   * Overrides FacetapiWidget::settingsForm().
   */
  function settingsForm(&$form, &$form_state) {
    // @see http://drupal.org/node/735528 for supporting multiple values in the
    // FAPI #states. The following hack adds multiple form elements and uses CSS
    // and JavaScript to ensure only one is displayed at a time. Only the last
    // form element actually passes the value.
    $form['widget']['widget_settings']['links'][$this->id]['soft_limit'] = array(
      '#type' => 'select',
      '#title' => t('Soft limit'),
      '#default_value' => $this->settings->settings['soft_limit'],
      '#options' => array(0 => t('No limit')) + drupal_map_assoc(array(50, 40, 30, 20, 15, 10, 5, 3)),
      '#description' => t('Limits the number of displayed facets via JavaScript.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    // @see http://drupal.org/node/1370342
    $form['widget']['widget_settings']['links'][$this->id]['nofollow'] = array(
      '#type' => 'checkbox',
      '#title' => t('Prevent crawlers from following facet links'),
      '#default_value' => !empty($this->settings->settings['nofollow']),
      '#description' => t('Add the <code>rel="nofollow"</code> attribute to facet links to maximize SEO by preventing crawlers from indexing duplicate content and getting stuck in loops.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    // @see http://drupal.org/node/735528
    if ($this->facet['hierarchy callback']) {
      $form['widget']['widget_settings']['links'][$this->id]['show_expanded'] = array(
        '#type' => 'checkbox',
        '#title' => t('Expand hierarchy'),
        '#default_value' => !empty($this->settings->settings['show_expanded']),
        '#description' => t('Show the entire tree regardless of whether the parent items are active.'),
        '#states' => array(
          'visible' => array(
            'select[name="widget"]' => array('value' => $this->id),
          ),
        ),
      );
    }

    // Hides all but the last element. The #states system will override this,
    // however it is necessary if JavaScript is disabled so multiple elements
    // aren't displayed to the user.
    $last = end($form['widget']['widget_settings']['links']);
    foreach ($form['widget']['widget_settings']['links'] as $id => $element) {
      if ($last != $element) {
        $form['widget']['widget_settings']['links'][$id]['#attributes']['style'] = 'display: none;';
      }
    }
  }

  /**
   * Overrides FacetapiWidget::getDefaultSettings().
   */
  function getDefaultSettings() {
    return array(
      'soft_limit' => 20,
      'nofollow' => 1,
      'show_expanded' => 0,
    );
  }
}

class CustomFacetapiWidgetSelect extends FacetapiWidget {

  public function execute() {
    $element = &$this->build[$this->facet['field alias']];
    $aa = $this->build['#settings']->name;
    $cc = explode(':', $aa);
    $name = array_pop($cc);

    // Create pretty path
    if (module_exists('facetapi_pretty_paths')) {
      foreach($element as $key => $e) {
        if (isset($e['#query']['f'][0])) {
          $element[$key]['#query']['f'][0] = str_replace(':', '/', $e['#query']['f'][0]);

          // Remove the queries from the f array and add them to the path
          if (isset($e['#path']) && substr_count($e['#path'],'/'.$element[$key]['#query']['f'][0])>0 ) {
            $element[$key]['#active'] = TRUE;
            $element[$key]['#path'] = str_replace('/'.$element[$key]['#query']['f'][0],'',$e['#path']);
          }
          else {
            $element[$key]['#path'] = $element[$key]['#path'] . '/' . $element[$key]['#query']['f'][0];
          }
          unset($element[$key]['#query']['f']);
        }
      }
    }

    $element = drupal_get_form('chm_search_' .  $name, $element);
  }
}
