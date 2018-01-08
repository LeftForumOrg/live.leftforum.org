<?php

/**
 * @file
 * Provide views data and handlers for the views_system module.
 */


/**
 * Implements of hook_views_data().
 */
function views_system_views_data() {

  $data['views_system']['table']['group'] = t('System');
  $data['views_system']['table']['join'] = array(
    'system' => array(
      'left_field' => 'filename',
      'field' => 'filename',
    ),
  );

  $data['views_system']['admin_theme'] = array(
    'title' => t('Administration theme'),
    'help' => t('Boolean indicating whether or not this theme is the administration theme.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Is administration theme'),
      'type' => 'yes-no',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'admin_theme',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['base_theme'] = array(
    'title' => t('Base theme'),
    'help' => t('The base theme of this theme.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'base_theme',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['configure'] = array(
    'title' => t('Configure'),
    'help' => t("The path of this module's (main) configuration page."),
    'field' => array(
      'handler' => 'views_handler_field_url',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'configure',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['core'] = array(
    'title' => t('Core'),
    'help' => t('The version of Drupal that this item is for.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'core',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['datestamp'] = array(
    'title' => t('Datestamp'),
    'help' => t('The release date of this item.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'name field' => 'datestamp',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $data['views_system']['default_theme'] = array(
    'title' => t('Default theme'),
    'help' => t('Boolean indicating whether or not this theme is the default theme.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Is default theme'),
      'type' => 'yes-no',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'default_theme',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['dependencies'] = array(
    'title' => t('Dependencies'),
    'help' => t('A list of other modules that this module requires.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_dependencies',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['description'] = array(
    'title' => t('Description'),
    'help' => t('The brief description of this item.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'description',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['engine'] = array(
    'title' => t('Engine'),
    'help' => t('The engine of this theme.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'engine',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['features'] = array(
    'title' => t('Features'),
    'help' => t('A list of available features of this theme.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_features',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['files'] = array(
    'title' => t('Files'),
    'help' => t('A list of files of this item.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_files',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['label'] = array(
    'title' => t('Label'),
    'help' => t('The human readable name of this item.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'label',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['mtime'] = array(
    'title' => t('Modification time'),
    'help' => t('The info file modification time of this item.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'name field' => 'mtime',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $data['views_system']['origin'] = array(
    'title' => t('Origin'),
    'help' => t('The origin of this item, either core or extension.'),
    'field' => array(
      'handler' => 'views_handler_field_machine_name',
      'options callback' => 'views_system_get_origin_list',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'views_system_get_origin_list',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'origin',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['package'] = array(
    'title' => t('Package'),
    'help' => t('The name of the package this module belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'package',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['php'] = array(
    'title' => t('PHP'),
    'help' => t('The minimum PHP version that this item requires.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'php',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['project'] = array(
    'title' => t('Project'),
    'help' => t('The name of the project this module belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'project',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['project_status_url'] = array(
    'title' => t('Project Status Url'),
    'help' => t('The URL to check for updates for the custom item.'),
    'field' => array(
      'handler' => 'views_handler_field_url',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'project_status_url',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['regions'] = array(
    'title' => t('Regions'),
    'help' => t('A list of regions of this theme.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_regions',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['regions_hidden'] = array(
    'title' => t('Hidden regions'),
    'help' => t('A list of hidden regions of this theme.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_regions_hidden',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['required'] = array(
    'title' => t('Required'),
    'help' => t('Boolean indicating whether or not this item is absolutely required.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Is required'),
      'type' => 'yes-no',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'required',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['required_by'] = array(
    'title' => t('Required by'),
    'help' => t('A full list of other items that depends on this item.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_required_by',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['requires'] = array(
    'title' => t('Requires'),
    'help' => t('A full list of other items that this item requires.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_requires',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['screenshot'] = array(
    'title' => t('Screenshot'),
    'help' => t('The thumbnail image of this theme.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_screenshot',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'screenshot',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['scripts'] = array(
    'title' => t('Scripts'),
    'help' => t('A list of JavaScript files of this item.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_scripts',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['settings'] = array(
    'title' => t('Settings'),
    'help' => t('A list of settings of this theme.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_settings',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['stylesheets'] = array(
    'title' => t('Stylesheets'),
    'help' => t('A list of stylesheets of this item.'),
    'field' => array(
      'handler' => 'views_handler_field_views_system_stylesheets',
      'no group by' => TRUE,
      'click sortable' => FALSE,
    ),
  );

  $data['views_system']['type'] = array(
    'title' => t('Type'),
    'help' => t('The type of the item, either module, theme, or theme_engine.'),
    'field' => array(
      'handler' => 'views_handler_field_machine_name',
      'options callback' => 'views_system_get_type_list',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'views_system_get_type_list',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'type',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['version'] = array(
    'title' => t('Version'),
    'help' => t('The version of this item.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'version',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_system']['visible'] = array(
    'title' => t('Visible'),
    'help' => t('Boolean indicating whether or not this item is visible on the modules and themes page.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Is visible'),
      'type' => 'yes-no',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'visible',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}


/**
 * Implements of hook_views_data_alter().
 */
function views_system_views_data_alter(&$data) {

  $data['system']['filename']['title'] = t('Filename');

  $data['system']['bootstrap'] = array(
    'title' => t('Bootstrap'),
    'help' => t("Boolean indicating whether this module is loaded during Drupal's early bootstrapping phase (e.g. even before the page cache is consulted)."),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'bootstrap',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['system']['info'] = array(
    'title' => t('Info'),
    'help' => t("A serialized array containing information from the module's .info file; keys can include name, description, package, version, core, dependencies, and php."),
    'field' => array(
      'handler' => 'views_handler_field_serialized',
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'info',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['system']['name']['title'] = t('Name');

  $data['system']['owner'] = array(
    'title' => t('Owner'),
    'help' => t("This theme's 'parent'. Can be either a theme or an engine."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'owner',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['system']['status']['filter']['label'] = t('Status');
  $data['system']['status']['filter']['type'] = 'enabled-disabled';

  $data['system']['type'] = NULL;

  $data['system']['weight'] = array(
    'title' => t('Weight'),
    'help' => t("The order in which this module's hooks should be invoked relative to other modules. Equal-weighted modules are ordered by name."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'weight',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
}
