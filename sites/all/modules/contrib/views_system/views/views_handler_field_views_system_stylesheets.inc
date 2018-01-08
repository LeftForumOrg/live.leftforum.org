<?php

/**
 * @file
 * Definition of views_handler_field_views_system_stylesheets.
 */


/**
 * Field handler to display all stylesheets of an item.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_stylesheets extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        foreach (unserialize($field) as $type => $styles) {
          foreach ($styles as $name => $filename) {

            $this->items[$field][$type .'-'. $name]['filename'] = $filename;
            $this->items[$field][$type .'-'. $name]['name'] = $name;
            $this->items[$field][$type .'-'. $name]['type'] = $type;
          }
        }
      }
    }
  }

  function render_item($count, $item) {
    return '[' . $item['type'] . '] ' . $item['name'];
  }

  function document_self_tokens(&$tokens) {
    $tokens['[' . $this->options['id'] . '-filename' . ']'] = t('The filename of the stylesheet.');
    $tokens['[' . $this->options['id'] . '-name' . ']'] = t('The name of the stylesheet.');
    $tokens['[' . $this->options['id'] . '-type' . ']'] = t('The media type of the stylesheet.');
  }

  function add_self_tokens(&$tokens, $item) {
    if (!empty($item['name'])) {
      $tokens['[' . $this->options['id'] . '-filename' . ']'] = $item['filename'];
      $tokens['[' . $this->options['id'] . '-name' . ']'] = $item['name'];
      $tokens['[' . $this->options['id'] . '-type' . ']'] = $item['type'];
    }
  }
}
