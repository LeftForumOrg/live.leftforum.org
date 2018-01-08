<?php

function drupalexp_layout_settings_form_alter(&$form){
	$theme = drupalexp_get_theme();
	$drupalexp_theme_path = drupal_get_path('theme','drupalexp');
	$layouts = json_encode($theme->layouts);
	$regions = array();
	foreach($theme->getRegions() as $key=>$name){
		$region = new stdClass();
		$region->region = $key;
		$region->title = $name;
		$regions[] = $region;
	}
	
	$sections = array('header','banner');
	$sections = json_encode($sections);
	$regions = json_encode($regions);
	$js = <<<JS
	var dexp_layouts = {$layouts};
	var dexp_sections = {$sections};
	var dexp_regions = {$regions};
JS;
	$coloptions = array(1=>'1 col',2=>'2 cols',3=>'3 cols',4=>'4 cols',5=>'5 cols',6=>'6 cols',7=>'7 cols',8=>'8 cols',9=>'9 cols',10=>'10 cols',11=>'11 cols',12=>'12 cols');
	$form['layout_settings'] = array(
		'#type' => 'fieldset',
		'#title' => 'Layouts',
		'#group' => 'drupalexp_settings',
		'#weight' => 0
	);
	$form['layout_settings']['drupalexp_layouts_edit'] = array(
		'#type' => 'container',
		'#title' => t('Edit layout'),
	);
	$form['layout_settings']['drupalexp_layouts_edit']['layout_name'] = array(
		'#type' => 'textfield',
		'#title' => t('Title'),
		'#size' => ''
	);
	$form['layout_settings']['drupalexp_layouts'] = array(
		'#type' => 'hidden',
		'#default_value' => base64_encode($layouts),
	);
	$form['layout_settings']['drupalexp_layouts_ui'] = array(
		'#markup' => '<a href="#" class="dexp-add-layout"><i class="fa fa-plus-circle"></i> Add layout</a><ul id="dexp_layouts"></ul><ul id="dexp_sections"></ul>',
	);
	
	$form['layout_settings']['drupalexp_add_section'] = array(
		'#markup' => '<div id="drupalexp_add_section"><a href="#"><i class="fa fa-plus-circle"></i> Add section</a></div>',
	);
	$form['layout_settings']['drupalexp_add_section_dialog'] = array(
		'#markup' => '<div id="drupalexp_add_section_dialog" title="Add section">Section: <input type="text" class="form-text" name="section_name"/></div>',
	);
	
	//Region settings
	$form['layout_settings']['drupalexp_region_settings'] = array(
		'#type' => 'container',
		'#title' => t('Region settings'),
	);
	$form['layout_settings']['drupalexp_region_settings']['cols'] = array(
		'#type' =>'fieldset',
		'#title' => 'Colunms',
	);
	$form['layout_settings']['drupalexp_region_settings']['cols']['region_col_lg'] = array(
		'#type' => 'select',
		'#options' => $coloptions,
		'#field_prefix' => '<i class="fa fa-desktop"></i>',
	);
	$form['layout_settings']['drupalexp_region_settings']['cols']['region_col_md'] = array(
		'#type' => 'select',
		'#options' => $coloptions,
		'#field_prefix' => '<i class="fa fa-laptop"></i>'
	);
	$form['layout_settings']['drupalexp_region_settings']['cols']['region_col_sm'] = array(
		'#type' => 'select',
		'#options' => $coloptions,
		'#field_prefix' => '<i class="fa fa-tablet"></i>'
	);
	$form['layout_settings']['drupalexp_region_settings']['cols']['region_col_xs'] = array(
		'#type' => 'select',
		'#options' => $coloptions,
		'#field_prefix' => '<i class="fa fa-mobile-phone"></i>'
	);
	
	//Section settings
	$form['layout_settings']['drupalexp_section_settings'] = array(
		'#type' => 'container',
		'#title' => t('Section settings'),
	);
	$form['layout_settings']['drupalexp_section_settings']['section_title'] = array(
		'#type' => 'textfield',
		'#title' => t('Section'),
		'#size' => ''
	);
	$form['layout_settings']['drupalexp_section_settings']['section_fullwidth'] = array(
		'#type' => 'select',
		'#title' => t('Full width'),
		'#options' => array('no' => 'No', 'yes' => 'Yes'),
	);
	$form['layout_settings']['drupalexp_section_settings']['section_visible'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Visible'),
		'#options' => array(
			'vphone' => 'Visible Phone',
			'vtablet' => 'Visible Tablet',
			'vdesktop' => 'Visible Desktop',
			'hphone' => 'Hidden Phone',
			'htablet' => 'Hidden Tablet',
			'hdesktop' => 'Hiddeny Desktop',
		),
	);
	$form['layout_settings']['drupalexp_section_settings']['section_background_color'] = array(
		'#type' => 'textfield',
		'#title' => t('Background color'),
		'#size' =>''
	);
	$form['layout_settings']['drupalexp_section_settings']['section_sticky'] = array(
		'#type' => 'checkbox',
		'#title' => t('Sticky on top'),
		'#size' =>''
	);
	
  $form['layout_settings']['drupalexp_section_settings']['section_custom_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Custom class'),
		'#size' =>''
	);
  $form['layout_settings']['drupalexp_section_settings']['section_colpadding'] = array(
		'#type' => 'textfield',
		'#title' => t('Custom column padding'),
		'#description' => t('Leave blank to use default bootstrap padding (15px)'),
    '#field_suffix' => 'px',
		'#size' =>''
	);
  $form['layout_settings']['dexp_layout_pages'] = array(
		'#type' => 'textarea',
		'#title' => t('Pages Assignment'),
		'#description' => t('List of pages to apply this layout. Enter one path per line. The \'*\' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. &lt;front&gt; is the front page.'),
    '#size' =>''
	);
	$form['#attached'] = array(
		'css' => array(
			$drupalexp_theme_path.'/admin/css/bootstrap.css',
			$drupalexp_theme_path.'/vendor/font-awesome/css/font-awesome.min.css',
			$drupalexp_theme_path.'/admin/css/admin.drupalexp.css'
		),
		'js' => array(
			$js => array('type'=>'inline'),
			$drupalexp_theme_path.'/admin/js/admin.drupalexp.js',
		)
	);
	drupal_add_library('system', 'ui.draggable');
	drupal_add_library('system', 'ui.dropable');
	drupal_add_library('system', 'ui.sortable');
	drupal_add_library('system', 'ui.dialog');
}