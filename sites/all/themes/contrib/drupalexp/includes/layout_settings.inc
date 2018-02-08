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
    drupal_add_js(array('drupalexp'=>array('layouts'=> $theme->layouts)), 'setting');
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
		'#size' => '',
        '#attributes' => array('data-key'=>'title'),
	);
	$form['layout_settings']['drupalexp_layouts_edit']['layout_default'] = array(
		'#type' => 'checkbox',
		'#title' => t('Set as default'),
	);
    $form['layout_settings']['drupalexp_layouts_edit']['dexp_layout_pages'] = array(
		'#type' => 'textarea',
		'#title' => t('Pages Assignment'),
		'#description' => t('List of pages to apply this layout. Enter one path per line. The \'*\' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. &lt;front&gt; is the front page.'),
        '#size' =>'',
        '#states' => array(
            'visible' => array(
                ':input[name="layout_default"]' => array('checked' => FALSE),
            ),
        ),
	);
	$form['layout_settings']['drupalexp_layouts'] = array(
		'#type' => 'hidden',
		'#default_value' => base64_encode($layouts),
	);
	$form['layout_settings']['drupalexp_layouts_ui'] = array(
		'#markup' => '<a href="#" class="dexp-add-layout"><i class="fa fa-plus-circle"></i> New layout</a><ul id="dexp_layouts"></ul><ul id="dexp_sections"></ul>',
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
        '#attributes' => array('data-key'=>'collg'),
	);
	$form['layout_settings']['drupalexp_region_settings']['cols']['region_col_md'] = array(
		'#type' => 'select',
		'#options' => $coloptions,
		'#field_prefix' => '<i class="fa fa-laptop"></i>',
        '#attributes' => array('data-key'=>'colmd'),
	);
	$form['layout_settings']['drupalexp_region_settings']['cols']['region_col_sm'] = array(
		'#type' => 'select',
		'#options' => $coloptions,
		'#field_prefix' => '<i class="fa fa-tablet"></i>',
        '#attributes' => array('data-key'=>'colsm'),
	);
	$form['layout_settings']['drupalexp_region_settings']['cols']['region_col_xs'] = array(
		'#type' => 'select',
		'#options' => $coloptions,
		'#field_prefix' => '<i class="fa fa-mobile-phone"></i>',
        '#attributes' => array('data-key'=>'colxs'),
	);
    $form['layout_settings']['drupalexp_region_settings']['offset'] = array(
		'#type' =>'fieldset',
		'#title' => 'Offsets',
        '#description' => '<a target="_blank" href="http://getbootstrap.com/css/#grid-offsetting">What is offset?</a>',
	);
    $form['layout_settings']['drupalexp_region_settings']['offset']['region_col_offset_lg'] = array(
		'#type' => 'select',
		'#options' => array(0=>'Not set',1,2,3,4,5,6,7,8,9,10,11,12),
		'#field_prefix' => 'col-lg-offset-',
        '#attributes' => array('data-key'=>'collgoffset'),
	);
    $form['layout_settings']['drupalexp_region_settings']['offset']['region_col_offset_md'] = array(
		'#type' => 'select',
		'#options' => array(0=>'Not set',1,2,3,4,5,6,7,8,9,10,11,12),
		'#field_prefix' => 'col-md-offset-',
        '#attributes' => array('data-key'=>'colmdoffset'),
	);
    $form['layout_settings']['drupalexp_region_settings']['offset']['region_col_offset_sm'] = array(
		'#type' => 'select',
		'#options' => array(0=>'Not set',1,2,3,4,5,6,7,8,9,10,11,12),
		'#field_prefix' => 'col-sm-offset-',
        '#attributes' => array('data-key'=>'colsmoffset'),
	);
    $form['layout_settings']['drupalexp_region_settings']['offset']['region_col_offset_xs'] = array(
		'#type' => 'select',
		'#options' => array(0=>'Not set',1,2,3,4,5,6,7,8,9,10,11,12),
		'#field_prefix' => 'col-xs-offset-',
        '#attributes' => array('data-key'=>'colxsoffset'),
	);
	$form['layout_settings']['drupalexp_region_settings']['region_custom_class'] = array(
		'#title' => 'Custom class',
		'#type' => 'textfield',
        '#attributes' => array('data-key'=>'custom_class'),
	);
	//Section settings
	$form['layout_settings']['drupalexp_section_settings'] = array(
		'#type' => 'container',
		'#title' => t('Section settings'),
	);
	$form['layout_settings']['drupalexp_section_settings']['section_title'] = array(
		'#type' => 'textfield',
		'#title' => t('Section'),
		'#size' => '',
        '#attributes' => array('data-key' => 'title'),
	);
	$form['layout_settings']['drupalexp_section_settings']['section_fullwidth'] = array(
		'#type' => 'select',
		'#title' => t('Full width'),
		'#options' => array('no' => 'No', 'yes' => 'Yes'),
        '#attributes' => array('data-key' => 'fullwidth'),
	);
    $form['layout_settings']['drupalexp_section_settings']['section_vphone'] = array(
        '#type' => 'checkbox',
        '#title' => t('Visible Phone'),
        '#attributes' => array('data-key' => 'vphone'),
    );
    $form['layout_settings']['drupalexp_section_settings']['section_vtablet'] = array(
        '#type' => 'checkbox',
        '#title' => t('Visible Tablet'),
        '#attributes' => array('data-key' => 'vtablet'),
    );
    $form['layout_settings']['drupalexp_section_settings']['section_vdesktop'] = array(
        '#type' => 'checkbox',
        '#title' => t('Visible Desktop'),
        '#attributes' => array('data-key' => 'vdesktop'),
    );
    $form['layout_settings']['drupalexp_section_settings']['section_hphone'] = array(
        '#type' => 'checkbox',
        '#title' => t('Hide on Phone'),
        '#attributes' => array('data-key' => 'hphone'),
    );
    $form['layout_settings']['drupalexp_section_settings']['section_htablet'] = array(
        '#type' => 'checkbox',
        '#title' => t('Hide on Tablet'),
        '#attributes' => array('data-key' => 'htablet'),
    );
    $form['layout_settings']['drupalexp_section_settings']['section_hdesktop'] = array(
        '#type' => 'checkbox',
        '#title' => t('Hide on Desktop'),
        '#attributes' => array('data-key' => 'hdesktop'),
    );
	$form['layout_settings']['drupalexp_section_settings']['section_background_color'] = array(
		'#type' => 'textfield',
		'#title' => t('Background color'),
		'#size' =>'',
        '#attributes' => array('data-key' => 'backgroundcolor'),
	);
	$form['layout_settings']['drupalexp_section_settings']['section_sticky'] = array(
		'#type' => 'checkbox',
		'#title' => t('Sticky on top'),
		'#size' =>'',
        '#attributes' => array('data-key' => 'sticky'),
	);

  $form['layout_settings']['drupalexp_section_settings']['section_custom_class'] = array(
		'#type' => 'textfield',
		'#title' => t('Custom class'),
		'#size' =>'',
        '#attributes' => array('data-key' => 'custom_class'),
	);
  $form['layout_settings']['drupalexp_section_settings']['section_colpadding'] = array(
		'#type' => 'textfield',
		'#title' => t('Custom column padding'),
		'#description' => t('Leave blank to use default bootstrap padding (15px)'),
        '#field_suffix' => 'px',
		'#size' =>'',
        '#attributes' => array('data-key' => 'colpadding'),
	);
  $form['#attached'] = array(
		'css' => array(
			$drupalexp_theme_path.'/admin/css/bootstrap.css',
			$drupalexp_theme_path.'/vendor/font-awesome/css/font-awesome.min.css',
			$drupalexp_theme_path.'/admin/css/admin.drupalexp.css'
		),
		'js' => array(
			$drupalexp_theme_path.'/admin/js/admin.drupalexp.js',
		)
	);
	drupal_add_library('system', 'ui.draggable');
	drupal_add_library('system', 'ui.dropable');
	drupal_add_library('system', 'ui.sortable');
	drupal_add_library('system', 'ui.dialog');
}
