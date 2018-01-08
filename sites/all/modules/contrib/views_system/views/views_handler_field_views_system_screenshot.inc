<?php

/**
 * @file
 * Definition of views_handler_field_views_system_screenshot.
 */


/**
 * Field handler to display the thumbnail image of a theme.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_screenshot extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();

    $options['image'] = array('default' => TRUE);
    $options['image_width'] = array('default' => '110');
    $options['image_height'] = array('default' => '');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['image'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display as image'),
      '#description' => t('If checked, the screenshot will be displayed as image.'),
      '#default_value' => $this->options['image'],
    );
    $form['image_width'] = array(
      '#type' => 'textfield',
      '#title' => t('Width'),
      '#default_value' => $this->options['image_width'],
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array(
        'edit-options-image' => array(1),
      ),
    );
    $form['image_height'] = array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#default_value' => $this->options['image_height'],
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array(
        'edit-options-image' => array(1),
      ),
    );
  }

  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);

    if ($form_state['values']['options']['image_width'] != '' && !is_numeric($form_state['values']['options']['image_width'])) {
      form_error($form['image_width'], t('You have to enter a numeric value for the image width.'));
    }
    if ($form_state['values']['options']['image_height'] != '' && !is_numeric($form_state['values']['options']['image_height'])) {
      form_error($form['image_height'], t('You have to enter a numeric value for the image height.'));
    }
  }

  function render($values) {
    $value = $values->{$this->field_alias};

    if (!$this->options['image']) {
      return $value;
    }

    if (!empty($value)) {
      $screenshot = array(
        'path' => $value,
        'alt' => t('Screenshot'),
        'title' => t('Screenshot'),
        'width' => $this->options['image_width'],
        'height' => $this->options['image_height'],
        'attributes' => array('class' => array('screenshot')),
      );
    }
    else {
      $screenshot = array(
        'path' => drupal_get_path('module', 'views_system') . '/images/no_screenshot.png',
        'alt' => t('No screenshot'),
        'title' => t('No screenshot'),
        'width' => $this->options['image_width'],
        'height' => $this->options['image_height'],
        'attributes' => array('class' => array('no-screenshot')),
      );
    }

    return theme('image', $screenshot);
  }
}
