<?php

/**
 * @file
 * Definition of views_handler_field_views_system_scripts.
 */


/**
 * Field handler to display all JavaScript files of an item.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_scripts extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        foreach (unserialize($field) as $name => $filename) {

          $this->items[$field][$name]['filename'] = $filename;
          $this->items[$field][$name]['name'] = $name;
        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['name'];
  }

  function document_self_tokens(&$tokens) {
    $tokens['[' . $this->options['id'] . '-filename' . ']'] = t('The filename of the JavaScript file.');
    $tokens['[' . $this->options['id'] . '-name' . ']'] = t('The name of the JavaScript file.');
  }

  function add_self_tokens(&$tokens, $item) {
    if (!empty($item['name'])) {
      $tokens['[' . $this->options['id'] . '-filename' . ']'] = $item['filename'];
      $tokens['[' . $this->options['id'] . '-name' . ']'] = $item['name'];
    }
  }
}
