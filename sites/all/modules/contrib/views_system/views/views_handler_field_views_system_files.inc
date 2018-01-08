<?php

/**
 * @file
 * Definition of views_handler_field_views_system_files.
 */


/**
 * Field handler to display all files of an item.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_files extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        foreach (unserialize($field) as $file) {

          $this->items[$field][$file]['name'] = $file;
        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['name'];
  }
}
