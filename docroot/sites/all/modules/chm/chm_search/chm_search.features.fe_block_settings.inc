<?php
/**
 * @file
 * chm_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function chm_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['chm_search-chm_search_reset'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'chm_search_reset',
    'module' => 'chm_search',
    'node_types' => array(),
    'pages' => 'search-network
search-network/*
search
search/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => 1,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -17,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['facetapi-19bHdUnmFxK7eb920GDpzRM1qyfR1Cyi'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '19bHdUnmFxK7eb920GDpzRM1qyfR1Cyi',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -20,
      ),
    ),
    'title' => 'Aichi targets',
    'visibility' => 0,
  );

  $export['facetapi-1CYaGOaIEXdnamCgdq1Gdpv77bnvUD7D'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '1CYaGOaIEXdnamCgdq1Gdpv77bnvUD7D',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -26,
      ),
    ),
    'title' => 'Species status',
    'visibility' => 0,
  );

  $export['facetapi-2WsraxK8PCznJ9C72fpnhpQInTbjXcLN'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '2WsraxK8PCznJ9C72fpnhpQInTbjXcLN',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -19,
      ),
    ),
    'title' => 'Subjects',
    'visibility' => 0,
  );

  $export['facetapi-AoCU3rlr8GYfymdYLwGLFYxa8sASyjOs'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'AoCU3rlr8GYfymdYLwGLFYxa8sASyjOs',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -32,
      ),
    ),
    'title' => 'Event status',
    'visibility' => 0,
  );

  $export['facetapi-Bm1bFo1uzE4d6EjU6qepYYd59viej6Q3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'Bm1bFo1uzE4d6EjU6qepYYd59viej6Q3',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -25,
      ),
    ),
    'title' => 'Species class',
    'visibility' => 0,
  );

  $export['facetapi-FaEBMg4xO8nfYnrqTSnqs5hinkp5gVOu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'FaEBMg4xO8nfYnrqTSnqs5hinkp5gVOu',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -28,
      ),
    ),
    'title' => 'Species phylum',
    'visibility' => 0,
  );

  $export['facetapi-HBnDnNdQro2m18tWDTQPGM6CxcHYfI8j'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'HBnDnNdQro2m18tWDTQPGM6CxcHYfI8j',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -27,
      ),
    ),
    'title' => 'Species family',
    'visibility' => 0,
  );

  $export['facetapi-Ni2wJj4X0kSm5Wq62qAEbTQjmG2zj0sa'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'Ni2wJj4X0kSm5Wq62qAEbTQjmG2zj0sa',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -36,
      ),
    ),
    'title' => 'Designation',
    'visibility' => 0,
  );

  $export['facetapi-VRABx9f9oV3wwlTHUXFbD14ZHPUlGYCM'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'VRABx9f9oV3wwlTHUXFbD14ZHPUlGYCM',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -31,
      ),
    ),
    'title' => 'Type',
    'visibility' => 0,
  );

  $export['facetapi-VbD1tOijarFO9gzpcliDHzBJ8YKhKhP5'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'VbD1tOijarFO9gzpcliDHzBJ8YKhKhP5',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -29,
      ),
    ),
    'title' => 'Organization type',
    'visibility' => 0,
  );

  $export['facetapi-a2Q4rVt6DWWT27ii3ZepIItnu6yWtxzy'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'a2Q4rVt6DWWT27ii3ZepIItnu6yWtxzy',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -18,
      ),
    ),
    'title' => 'Keywords',
    'visibility' => 0,
  );

  $export['facetapi-bhmRHTzU2n0ejKZP9wDI0S1oi2DgbSDm'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'bhmRHTzU2n0ejKZP9wDI0S1oi2DgbSDm',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -38,
      ),
    ),
    'title' => 'Information type',
    'visibility' => 0,
  );

  $export['facetapi-iMhaaj0arVkCJe1zZp7gBw8i81U5iE1p'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'iMhaaj0arVkCJe1zZp7gBw8i81U5iE1p',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -24,
      ),
    ),
    'title' => 'Protected area status',
    'visibility' => 0,
  );

  $export['facetapi-iu7RY0T7EA1lGTC0TxpuexRxeqj3ZsX9'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'iu7RY0T7EA1lGTC0TxpuexRxeqj3ZsX9',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -23,
      ),
    ),
    'title' => 'Project Status',
    'visibility' => 0,
  );

  $export['facetapi-jmsS3R9uZ3SlC7IbspnkfTuPbMMgaFB0'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'jmsS3R9uZ3SlC7IbspnkfTuPbMMgaFB0',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -22,
      ),
    ),
    'title' => 'CHM website',
    'visibility' => 0,
  );

  $export['facetapi-k0hWqhTI8R0yy5qQwUQWpEM1BT0nBoL9'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'k0hWqhTI8R0yy5qQwUQWpEM1BT0nBoL9',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -30,
      ),
    ),
    'title' => 'Document type',
    'visibility' => 0,
  );

  $export['facetapi-l7Vt5CsW9OC11lWXp1Bg4vU1aOHyCELN'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'l7Vt5CsW9OC11lWXp1Bg4vU1aOHyCELN',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'chm_theme_kit',
        'weight' => -39,
      ),
    ),
    'title' => 'Department',
    'visibility' => 0,
  );

  $export['facetapi-o4l2jSSBJ1Oe1Xg10QKJADPu0ekQn8xI'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'o4l2jSSBJ1Oe1Xg10QKJADPu0ekQn8xI',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -33,
      ),
    ),
    'title' => 'IUCN category',
    'visibility' => 0,
  );

  $export['facetapi-quOCSH73Ih7QlyLc5C8uqdPNEZVwj6u6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'quOCSH73Ih7QlyLc5C8uqdPNEZVwj6u6',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -37,
      ),
    ),
    'title' => 'Countries',
    'visibility' => 0,
  );

  $export['facetapi-saSOniarzepx25uEEito7x1bTGpvdNqU'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'saSOniarzepx25uEEito7x1bTGpvdNqU',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'chm_theme_kit',
        'weight' => -39,
      ),
    ),
    'title' => 'Status',
    'visibility' => 0,
  );

  $export['facetapi-wf1wQ0tQOF09OyA05Ha7sJMmqvhy5kPU'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'wf1wQ0tQOF09OyA05Ha7sJMmqvhy5kPU',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -35,
      ),
    ),
    'title' => 'Designation type',
    'visibility' => 0,
  );

  $export['facetapi-yJSewVbtoL4B0ngOcQBoQIhAfTXyAGzO'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'yJSewVbtoL4B0ngOcQBoQIhAfTXyAGzO',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -21,
      ),
    ),
    'title' => 'Dates',
    'visibility' => 0,
  );

  $export['facetapi-zzq5edF4HoXxtUjaWHvJcUsxkt0tHlYD'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'zzq5edF4HoXxtUjaWHvJcUsxkt0tHlYD',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'chm_theme_kit' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'chm_theme_kit',
        'weight' => -34,
      ),
    ),
    'title' => 'Ecosystem types',
    'visibility' => 0,
  );

  return $export;
}
