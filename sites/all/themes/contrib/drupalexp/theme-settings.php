<?php
require_once dirname(__FILE__) . '/includes/core.php';
require_once dirname(__FILE__) . '/includes/layout_settings.inc';
require_once dirname(__FILE__) . '/includes/preset_settings.inc';
require_once dirname(__FILE__) . '/includes/basic_settings.inc';
require_once dirname(__FILE__) . '/includes/fonts_settings.inc';

/**
 * Implements hook_form_system_theme_settings_alter()
 */
function drupalexp_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL) {
    $theme_key = arg(3);
    if (file_exists(drupal_get_path('theme', $theme_key) . '/template.php')) {
      require_once drupal_get_path('theme', $theme_key) . '/template.php';
    }
    $theme = drupalexp_get_theme();
    $form['drupalexp_settings'] = array(
        '#type' => 'vertical_tabs',
    );
    $form['drupal_core_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('Drupal core'),
        '#group' => 'drupalexp_settings',
        '#weight' => 99,
    );
    $form['drupal_core_settings']['theme_settings'] = $form['theme_settings'];
    $form['drupal_core_settings']['logo'] = $form['logo'];
    $form['drupal_core_settings']['favicon'] = $form['favicon'];
    unset($form['theme_settings']);
    unset($form['logo']);
    unset($form['favicon']);
    drupalexp_layout_settings_form_alter($form);
    drupalexp_preset_settings_form_alter($form);
    drupalexp_fonts_settings_form_alter($form);
    drupalexp_basic_settings_form_alter($form);
    $form['#submit'][] = 'drupalexp_theme_settings_submit';
    $form['#validate'][] = 'drupalexp_theme_settings_validate';
}

function drupalexp_theme_settings_validate(&$form, &$form_state) {
    $layouts = '';
    $theme_key = arg(3);
    $i = 0;
    while (isset($form_state['input']['dexp_layout_' . $i])) {
        $layouts .= $form_state['input']['dexp_layout_' . $i];
        $i++;
    }
    if(isset($_GET['resetlayouts']) && $_GET['resetlayouts']){
        $func = $theme_key .'_default_layouts';
        $layouts = $func();
    }
    if(isset($_GET['resetpresets']) && $_GET['resetpresets']){
        $func = $theme_key .'_default_presets';
        $presets = $func();
        form_set_value($form['preset_settings']['drupalexp_presets'], $presets, $form_state);
    }
    form_set_value($form['layout_settings']['drupalexp_layouts'], $layouts, $form_state);
}

function drupalexp_theme_settings_submit(&$form, &$form_state) {
    //Mark update status is TRUE
    variable_set('drupalexp_assets_path', '');
    unset($_SESSION['drupalexp_default_preset']);
    unset($_SESSION['drupalexp_default_direction']);
    unset($_SESSION['drupalexp_layout']);
    variable_set('drupalexp_settings_updated', REQUEST_TIME);
}
