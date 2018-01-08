<?php

/**
 * @file
 * Plugin file for Views Nested Accordion module.
 */

/**
 * Implements hook_views_plugin().
 */
function views_nested_accordion_views_plugins() {
  return array(
    'style' => array(
      'views_nested_accordion' => array(
        'title' => t('Views nested Accordion'),
        'theme' => 'views_view_accordion',
        'parent' => 'views_accordion',
        'help' => t('Display Nested Accordion.'),
        'handler' => 'views_nested_accordion_style_plugin',
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
