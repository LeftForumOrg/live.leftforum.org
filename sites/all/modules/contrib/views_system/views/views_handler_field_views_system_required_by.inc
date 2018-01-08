<?php

/**
 * @file
 * Definition of views_handler_field_views_system_required_by.
 */


/**
 * Field handler to display all other items that depends on this item.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_required_by extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        foreach (unserialize($field) as $name => $value) {

          $label = db_query('SELECT vs.label FROM {views_system} vs INNER JOIN {system} s ON vs.filename = s.filename WHERE s.name = :name', array(':name' => $name))
            ->fetchField();

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
    $tokens['[' . $this->options['id'] . '-label' . ']'] = t('The human readable name of the item.');
    $tokens['[' . $this->options['id'] . '-name' . ']'] = t('The machine-name of the item.');
  }

  function add_self_tokens(&$tokens, $item) {
    if (!empty($item['name'])) {
      $tokens['[' . $this->options['id'] . '-label' . ']'] = $item['label'];
      $tokens['[' . $this->options['id'] . '-name' . ']'] = $item['name'];
    }
  }
}
