<?php

/**
 * @file
 * Definition of views_handler_field_views_system_settings.
 */


/**
 * Field handler to display all settings of a theme.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_settings extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        $settings = views_system_convert_nested_array_into_flat_array(unserialize($field));
        foreach ($settings as $name => $value) {

          $this->items[$field][$name]['name'] = $name;
          $this->items[$field][$name]['value'] = $value;
        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['name'] . ' = ' . $item['value'];
  }

  function document_self_tokens(&$tokens) {
    $tokens['[' . $this->options['id'] . '-name' . ']'] = t('The name of the setting.');
    $tokens['[' . $this->options['id'] . '-value' . ']'] = t('The value of the setting.');
  }

  function add_self_tokens(&$tokens, $item) {
    if (!empty($item['name'])) {
      $tokens['[' . $this->options['id'] . '-name' . ']'] = $item['name'];
      $tokens['[' . $this->options['id'] . '-value' . ']'] = $item['value'];
    }
  }
}
