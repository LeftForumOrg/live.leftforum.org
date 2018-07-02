<?php

/**
 * @file
 * The primary PHP file for this theme.
 */
const CODE_TYPES = array('css', 'js');

/********** HELPER FUNCTIONS **********/
function get_group($code_type) {
  switch ($code_type) {
    case 'css': return CSS_THEME;
    case 'js': return JS_THEME;
    default: return NULL;
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

function add_all_code($sub_path, $name) {
  foreach (CODE_TYPES as $code_type) {
    add_code($code_type, $sub_path, $name);
  }
}

/********** PREPROCESSING FUNCTIONS **********/
function leftforum_bootstrap_preprocess_node(&$vars, $hook) {
  // Add content-type-specific css
  add_all_code('content-type', $vars['node']->type);

  // Call content-type-specific preprocess function
  $func = __FUNCTION__ . '_' . $vars['node']->type;
  if (function_exists($func)) {
    $func($vars, $hook);
  }
  
  // Add node-specific css
  add_all_code('node', $vars['node']->nid);
}

function leftforum_bootstrap_preprocess_views_view(&$vars) {
  // Add view-specific css
  add_all_code('view', $vars['name']);
}

function leftforum_bootstrap_preprocess_user_profile(&$vars) {
  // Add user-profile global css
  add_all_code('', 'user');
}

/********** OTHER HOOK FUNCTIONS **********/
function leftforum_bootstrap_form_alter(&$form, &$form_state, $form_id) {
  // Add form global css
  add_all_code('form', 'form');
}

function leftforum_bootstrap_form_node_form_alter(&$form, &$form_state, $form_id) {
  // Add content-type-specific css for form
  add_all_code('form/content-type', $form['#node']->type);
}