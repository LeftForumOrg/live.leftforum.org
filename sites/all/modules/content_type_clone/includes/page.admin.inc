<?php

/**
 * @file
 * Content Type Clone utility functions.
 */

/**
 * Redirect to the content type clone form.
 *
 * This function redirects the user to the content type clone form.
 *
 * @param string $node_type
 *   The node type needing cloning.
 */
function content_type_clone_menu_redirect($node_type) {
  // Redirect the user.
  drupal_goto('admin/' . $node_type->type . '/clone/create');
}
