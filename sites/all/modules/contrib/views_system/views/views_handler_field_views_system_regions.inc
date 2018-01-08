<?php

/**
 * @file
 * Definition of views_handler_field_views_system_regions.
 */


/**
 * Field handler to display all regions of a theme.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_regions extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        foreach (unserialize($field) as $name => $label) {

          $this->items[$field][$name]['label'] = $label;
          $this->items[$field][$name]['name'] = $name;
        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['label'];
  }

  function document_self_tokens(&$tokens) {
    $tokens['[' . $this->options['id'] . '-label' . ']'] = t('The human readable name of the region.');
    $tokens['[' . $this->options['id'] . '-name' . ']'] = t('The machine-name of the region.');
  }

  function add_self_tokens(&$tokens, $item) {
    if (!empty($item['name'])) {
      $tokens['[' . $this->options['id'] . '-label' . ']'] = $item['label'];
      $tokens['[' . $this->options['id'] . '-name' . ']'] = $item['name'];
    }
  }
}
