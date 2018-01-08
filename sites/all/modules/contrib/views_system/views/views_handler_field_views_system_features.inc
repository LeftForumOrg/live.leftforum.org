<?php

/**
 * @file
 * Definition of views_handler_field_views_system_features.
 */


/**
 * Field handler to display all features of a theme.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_features extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        foreach (unserialize($field) as $feature) {

          $this->items[$field][$feature]['name'] = $feature;
        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['name'];
  }
}
