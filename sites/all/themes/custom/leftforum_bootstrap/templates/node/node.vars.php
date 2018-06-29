<?php

/**
 * Pre-processes variables for the "sponsor" content type theme hook.
 * See template for list of available variables.
 *
 * @param array $vars
 *   An associative array of variables, passed by reference.
 *
 * @ingroup theme_preprocess
 */
function leftforum_bootstrap_preprocess_node_sponsor(&$vars, $hook) {
  $node =& $vars['node'];
  $logo_field = 'field_org_logo_circle_or_square';
  $banner_img = field_get_items('node', $node, 'field_org_logo_rectangle');
  $logo_img = field_get_items('node', $node, $logo_field);
  if (!(empty($banner_img) || empty($logo_img))) {
    hide($vars['content'][$logo_field]);
  }
}