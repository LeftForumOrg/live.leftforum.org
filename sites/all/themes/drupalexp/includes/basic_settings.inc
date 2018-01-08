<?php

function drupalexp_basic_settings_form_alter(&$form) {
  $pagewidth = theme_get_setting('drupalexp_pagewidth');
  if(empty($pagewidth)) $pagewidth = 1170;
  $form['basic_settings'] = array(
      '#type' => 'fieldset',
      '#title' => 'Basic',
      '#group' => 'drupalexp_settings',
      '#weight' => 4
  );
  $form['basic_settings']['drupalexp_pagewidth'] = array(
      '#type' => 'textfield',
      '#title' => t('Page Width'),
      '#default_value' => $pagewidth
  );
  $form['basic_settings']['drupalexp_smoothscroll'] = array(
      '#type' => 'select',
      '#title' => t('Enable SmoothScroll'),
      '#options' => array(1 => 'Yes', 0 => 'No'),
      '#default_value' => theme_get_setting('drupalexp_smoothscroll')
  );
  $form['basic_settings']['drupalexp_layout'] = array(
      '#type' => 'select',
      '#title' => t('Layout'),
      '#options' => array('wide' => 'Wide', 'boxed' => 'Boxed'),
      '#default_value' => theme_get_setting('drupalexp_layout')
  );
  $form['basic_settings']['drupalexp_direction'] = array(
      '#type' => 'select',
      '#title' => t('Direction'),
      '#options' => array('default'=>t('Default (Current language direction)'), 'ltr' => 'LTR', 'rtl' => 'RTL'),
      '#default_value' => theme_get_setting('drupalexp_direction')
  );
  $form['basic_settings']['drupalexp_ga_analytics'] = array(
      '#type' => 'textfield',
      '#title' => t('Google Analytics Tracking Id'),
      '#description'=>t('Tracking Code. Example: UA-12345678-1'),
      '#default_value' => theme_get_setting('drupalexp_ga_analytics')
  );
  $form['basic_settings']['drupalexp_wrapper_class'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom HTML class'),
      '#description'=>t('Provides this text as an additional body class (in $classes in html.tpl.php) when this section is active.'),
      '#default_value' => theme_get_setting('drupalexp_wrapper_class')
  );
}
