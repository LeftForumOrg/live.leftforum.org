<?php

/**
 * @file
 * Definition of views_handler_field_views_system_regions_hidden.
 */


/**
 * Field handler to display all hidden regions of a theme.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_regions_hidden extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        foreach (unserialize($field) as $region) {

          $this->items[$field][$region]['name'] = $region;
        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['name'];
  }
}
