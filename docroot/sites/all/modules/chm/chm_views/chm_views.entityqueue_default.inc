<?php
/**
 * @file
 * chm_views.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function chm_views_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'slideshow_www';
  $queue->label = 'slideshow_www';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'node';
  $queue->settings = array(
    'target_bundles' => array(
      'event' => 'event',
      'news' => 'news',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 1,
  );
  $export['slideshow_www'] = $queue;

  return $export;
}
