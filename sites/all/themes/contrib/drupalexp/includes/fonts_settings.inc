<?php

function drupalexp_fonts_settings_form_alter(&$form) {
  $form['fonts_settings'] = array(
      '#type' => 'fieldset',
      '#title' => 'Fonts',
      '#group' => 'drupalexp_settings',
      '#weight' => 2
  );
  $form['fonts_settings']['drupalexp_fonts'] = array(
      '#markup' => '<div id="fonts"></div>',
  );
  $theme_key = arg(3);
  if (function_exists($theme_key.'_fonts')) {
    $fonts = call_user_func($theme_key.'_fonts');
  }else{
    $fonts = array(
      'body' => array(
        '#title' => t('Body Font'),
        '#description' => t('Typography option with each property can be called individually.'),
      ),
      'h1' => array(
        '#title' => t('H1'),
      ),
      'h2' => array(
        '#title' => t('H2'),
      ),
      'h3' => array(
        '#title' => t('H3'),
      ),
      'h4' => array(
        '#title' => t('H4'),
      ),
      'h5' => array(
        '#title' => t('H5'),
      ),
      'h6' => array(
        '#title' => t('H6'),
      ),
    );
  }
  foreach($fonts as $key=>$font){
    $font['#type'] = 'textfield';
    $font['#default_value'] = theme_get_setting($key);
    $font['#attributes'] = array('class'=>array('google-font'));
    $form['fonts_settings'][$key] = $font;

  }
  $custom_fonts = array(1,2,3,4,5);
  foreach($custom_fonts as $font){
    $form['fonts_settings']['custom_font_'.$font] = array(
      '#type' => 'textfield',
      '#default_value' => theme_get_setting('custom_font_'.$font),
      '#attributes' => array('class'=>array('google-font','custom-font')),
      '#title' => t('Custom font #'.$font),
      '#maxlength' => 256,
    );
  }
  drupal_add_library('system', 'ui.autocomplete');
  $fonts = json_decode(file_get_contents(__DIR__.'/font-list.json'));
  foreach($fonts->items as $k=>$font){
    $fonts->items[$k]->label = $font->family;
    $fonts->items[$k]->value = $font->family;
    if(!isset($fonts->items[$k]->{'data-google'})){
      $fonts->items[$k]->{'data-google'} = true;
    }
  }
  drupal_add_js(array('google_fonts'=>$fonts),'setting');
}
