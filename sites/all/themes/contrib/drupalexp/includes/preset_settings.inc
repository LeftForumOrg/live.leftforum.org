<?php

function drupalexp_preset_settings_form_alter(&$form){
	drupal_add_js(drupal_get_path('theme','drupalexp').'/admin/js/farbtastic.js');
	drupal_add_css(drupal_get_path('theme','drupalexp').'/admin/css/farbtastic.css');
	$theme = drupalexp_get_theme();
	$presets = $theme->presets;
	if(empty($presets)){
		$presets = array(
			'drupalexp_presets' => array(
				array(
					'key' => 'preset1',
					'base_color' => '#0072b9',
					'text_color' => '#494949',
					'link_color' => '#027ac6',
					'link_hover_color' => '#027ac6',
					'heading_color' => '#2385c2',
				)
			)
		);
	}else{
		$presets = array(
			'drupalexp_presets' => $presets,
		);
	}
	drupal_add_js($presets,'setting');
	$preset_options = array();
	foreach($presets['drupalexp_presets'] as $k=>$p){
		$p = (array)$p;
		$preset_options[] = $p['key'];
	}
	$form['preset_settings'] = array(
		'#type' => 'fieldset',
		'#title' => 'Presets',
		'#group' => 'drupalexp_settings',
		'#weight' => 1
	);
	$form['preset_settings']['drupalexp_presets'] = array(
		'#type' => 'hidden',
		'#default_value' => theme_get_setting('drupalexp_presets'),
	);
	$form['preset_settings']['drupalexp_default_preset'] = array(
		'#type' => 'select',
		'#title' => 'Default preset',
		'#options' => $preset_options,
		'#default_value' => $theme->get('drupalexp_default_preset'),
		'#description' => 'Check to set this preset is default',
	);
	$form['preset_settings']['drupalexp_presets_settings'] = array(
		'#type' => 'fieldset',
		'#title' => 'Preset settings',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
	);
	$form['preset_settings']['drupalexp_presets_settings']['drupalexp_presets_list'] = array(
		'#type' => 'select',
		'#title' => 'Presets',
		'#default_value' => $theme->preset,
		'#options' => $preset_options,
	);

	$default_preset = (array)$presets['drupalexp_presets'][0];
	$form['preset_settings']['drupalexp_presets_settings']['drupalexp_preset_key'] = array(
		'#type' => 'textfield',
		'#title' => 'Preset name',
		'#default_value' => $default_preset['key'],
		'#description' => 'The css file generated based on this name. e.g: style-[preset_name].css',
		'#attributes' => array('data-property'=>'key','class'=>array('preset-option')),
	);
	$form['preset_settings']['drupalexp_presets_settings']['drupalexp_base_color'] = array(
		'#type' => 'textfield',
		'#title' => 'Base color',
		'#default_value' => $default_preset['base_color'],
		'#attributes' => array('data-property'=>'base_color','class'=>array('color','preset-option')),
	);
    $form['preset_settings']['drupalexp_presets_settings']['drupalexp_base_color_opposite'] = array(
		'#type' => 'textfield',
		'#title' => 'Opposite Base color',
		'#default_value' => isset($default_preset['base_color_opposite'])?$default_preset['base_color_opposite']:$default_preset['base_color'],
		'#attributes' => array('data-property'=>'base_color_opposite','class'=>array('color','preset-option')),
	);
	$form['preset_settings']['drupalexp_presets_settings']['drupalexp_link_color'] = array(
		'#type' => 'textfield',
		'#title' => 'Link color',
		'#default_value' => $default_preset['link_color'],
		'#attributes' => array('data-property'=>'link_color','class'=>array('color','preset-option')),
	);
	$form['preset_settings']['drupalexp_presets_settings']['drupalexp_link_hover_color'] = array(
		'#type' => 'textfield',
		'#title' => 'Link hover color',
		'#default_value' => $default_preset['link_hover_color'],
		'#attributes' => array('data-property'=>'link_hover_color','class'=>array('color','preset-option')),
	);
	$form['preset_settings']['drupalexp_presets_settings']['drupalexp_text_color'] = array(
		'#type' => 'textfield',
		'#title' => 'Text color',
		'#default_value' => $default_preset['text_color'],
		'#attributes' => array('data-property'=>'text_color','class'=>array('color','preset-option')),
	);
	$form['preset_settings']['drupalexp_presets_settings']['drupalexp_heading_color'] = array(
		'#type' => 'textfield',
		'#title' => 'Headding color',
		'#default_value' => $default_preset['heading_color'],
		'#attributes' => array('data-property'=>'heading_color','class'=>array('color','preset-option')),
	);
	$form['preset_settings']['drupalexp_presets_settings']['drupalexp_link_picker'] = array(
		'#markup' => '<div id="placeholder"></div>',
	);
}
