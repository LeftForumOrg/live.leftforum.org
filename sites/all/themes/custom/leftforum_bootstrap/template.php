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

function add_code($code_type, $dir, $name, $type = 'file') {
  if ($type === 'file') {
    $path = path_to_theme() . "$dir$name.$code_type";
    if (!file_exists($path)) {
      return;
    }
  } else {
    $path = $name;
  }
  ("drupal_add_$code_type")(
    $path, array('type' => $type, 'group' => get_group($code_type))
  );
}

/********** PREPROCESSING FUNCTIONS **********/
function leftforum_bootstrap_preprocess_node(&$vars, $hook) {
  // Add content-type-specific css
  add_code('css', '/css/content-type/', $vars['node']->type);
  
  // Add node-specific css
  add_code('css', '/css/node/', $vars['node']->nid);
}

function leftforum_bootstrap_cdn_preprocess_views_view(&$vars) {
  // Add view-specific css
  add_code('css', '/css/view/', $vars['name']);
}

