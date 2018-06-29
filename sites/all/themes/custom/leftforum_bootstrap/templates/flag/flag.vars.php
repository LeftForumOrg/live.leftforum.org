<?php

/**
 * @file
 * Stub file for "flag" theme hook [pre]process functions.
 */

 /**
 * Pre-processes variables for the "flag" theme hook.
 * See template for list of available variables.
 *
 * @param array $vars
 *   An associative array of variables, passed by reference.
 *
 * @ingroup theme_preprocess
 */
function leftforum_bootstrap_preprocess_flag(&$vars) {
  switch ($vars['flag']->name) {
    case 'schedule':
      $vars['flag_classes_array'][] = 'btn';
      $vars['flag_classes_array'][] = 'btn-primary';
      break;
    case 'videolist':
      $vars['flag_classes_array'][] = 'btn';
      $vars['flag_classes_array'][] = 'btn-success';
      break;
    default:
  }
}