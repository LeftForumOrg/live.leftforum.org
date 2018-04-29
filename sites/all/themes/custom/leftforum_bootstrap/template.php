<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

/********** HELPER FUNCTIONS **********/
function get_group($code_type) {
  switch ($code_type) {
    case 'css': return CSS_THEME;
    case 'js': return JS_THEME;
    default: return '';
  }
}

function add_code($code_type, $sub_path, $name, $type = 'file') {
  if ($type === 'file') {
    $path = path_to_theme() . "/$code_type/$sub_path/$name.$code_type";
    if (!file_exists($path)) {
      return;
    }
  } else {
    $path = $name;
  }
  $func = "drupal_add_$code_type";
  $func($path, array('type' => $type, 'group' => get_group($code_type)));
}

/********** PREPROCESSING FUNCTIONS **********/
function leftforum_bootstrap_preprocess_node(&$vars, $hook) {
  // Add content-type-specific css
  add_code('css', 'content-type', $vars['node']->type);
  
  // Add node-specific css
  add_code('css', 'node', $vars['node']->nid);
}

function leftforum_bootstrap_preprocess_views_view(&$vars) {
  // Add view-specific css
  add_code('css', 'view', $vars['name']);
}

function leftforum_bootstrap_preprocess_user_profile(&$vars) {
  // Add user-profile global css
  add_code('css', '', 'user');
}

/********** OTHER HOOK FUNCTIONS **********/
function leftforum_bootstrap_form_alter(&$form, &$form_state, $form_id) {
  // Add content-type-specific css for form
  add_code('css', 'form/content-type', $form['#node']->type);
}