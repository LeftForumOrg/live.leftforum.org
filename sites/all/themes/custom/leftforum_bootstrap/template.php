<?php

/**
 * @file
 * The primary PHP file for this theme.
 */

function leftforum_bootstrap_preprocess_node(&$vars, $hook) {
  // Add content-type-specific css
  drupal_add_css(
    path_to_theme() . '/css/content-type/' . $vars['node']->type . '.css',
    array('type' => 'file', 'group' => CSS_THEME, 'every_page' => FALSE)
  );

  // Add node-specific css
  drupal_add_css(
    path_to_theme() . '/css/node/' . $vars['node']->nid . '.css',
    array('type' => 'file', 'group' => CSS_THEME, 'every_page' => FALSE)
  );
}

function leftforum_bootstrap_preprocess_views_view(&$vars) {
  // Add view-specific css
  drupal_add_css(
    path_to_theme() . '/css/view/' . $vars['name'] . '.css',
    array('type' => 'file', 'group' => CSS_THEME, 'every_page' => FALSE)
  );
}

function leftforum_bootstrap_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
    'info' => t('Informative message'),
  );

  // Map Drupal message types to their corresponding Bootstrap classes.
  // @see http://twitter.github.com/bootstrap/components.html#alerts
  $status_class = array(
    'status' => 'success',
    'error' => 'danger',
    'warning' => 'warning',
    // Not supported, but in theory a module could send any type of message.
    // @see drupal_set_message()
    // @see theme_status_messages()
    'info' => 'info',
  );

  // Retrieve messages.
  $message_list = drupal_get_messages($display);

  // Allow the disabled_messages module to filter the messages, if enabled.
  if (module_exists('disable_messages') && variable_get('disable_messages_enable', '1')) {
    $message_list = disable_messages_apply_filters($message_list);
  }

  foreach ($message_list as $type => $messages) {
    $class = (isset($status_class[$type])) ? ' alert-' . $status_class[$type] : '';
    $output .= "<div class=\"alert alert-block$class messages $type\">\n";
    $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\">&times;</a>\n";

    if (!empty($status_heading[$type])) {
      $output .= '<h4 class="element-invisible">' . filter_xss_admin($status_heading[$type]) . "</h4>\n";
    }

    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . alert_filter($message) . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= alert_filter($messages[0]);
    }

    $output .= "</div>\n";
  }
  return $output;
}

function alert_filter(&$message) {
  return filter_xss_admin(
    str_replace('<a href', '<a class="alert-link" href', $message)
  );
}
