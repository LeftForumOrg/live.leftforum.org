<?php

/**
 * @file
 * Stub file for leftforum_bootstrap_form().
 */

function leftforum_bootstrap_form(&$vars) {
  $element = $vars['element'];
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }
  // Anonymous DIV to satisfy XHTML compliance.
  return '<form' . drupal_attributes($element['#attributes']) . '><div class="row">' . $element['#children'] . '</div></form>';
}