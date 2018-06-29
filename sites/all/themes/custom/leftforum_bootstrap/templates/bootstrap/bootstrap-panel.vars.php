<?php
/**
 * @file
 * Stub file for "bootstrap_panel" theme hook [pre]process functions.
 */

 /**
 * Pre-processes variables for the "bootstrap_panel" theme hook.
 * See template for list of available variables.
 *
 * @param array $vars
 *   An associative array of variables, passed by reference.
 *
 * @ingroup theme_preprocess
 */
function leftforum_bootstrap_preprocess_bootstrap_panel(&$vars) {
  $attributes = &$vars['attributes'];
  if (preg_match('/^bootstrap-panel/', $attributes['id'])) {
    $attributes['class'][] = 'col-xs-12';
  }
}
