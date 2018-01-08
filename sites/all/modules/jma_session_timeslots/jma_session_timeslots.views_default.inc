<?php
/**
 * @file
 * jma_session_timeslots.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function jma_session_timeslots_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'programs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Programs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Programs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Panels';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_speaker1_first_name']['id'] = 'field_speaker1_first_name';
  $handler->display->display_options['fields']['field_speaker1_first_name']['table'] = 'field_data_field_speaker1_first_name';
  $handler->display->display_options['fields']['field_speaker1_first_name']['field'] = 'field_speaker1_first_name';
  $handler->display->display_options['fields']['field_speaker1_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker1_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker1_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_speaker3_first_name']['id'] = 'field_speaker3_first_name';
  $handler->display->display_options['fields']['field_speaker3_first_name']['table'] = 'field_data_field_speaker3_first_name';
  $handler->display->display_options['fields']['field_speaker3_first_name']['field'] = 'field_speaker3_first_name';
  $handler->display->display_options['fields']['field_speaker3_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker3_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker3_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_po_first_name']['id'] = 'field_po_first_name';
  $handler->display->display_options['fields']['field_po_first_name']['table'] = 'field_data_field_po_first_name';
  $handler->display->display_options['fields']['field_po_first_name']['field'] = 'field_po_first_name';
  $handler->display->display_options['fields']['field_po_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_po_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_po_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_speaker6_first_name']['id'] = 'field_speaker6_first_name';
  $handler->display->display_options['fields']['field_speaker6_first_name']['table'] = 'field_data_field_speaker6_first_name';
  $handler->display->display_options['fields']['field_speaker6_first_name']['field'] = 'field_speaker6_first_name';
  $handler->display->display_options['fields']['field_speaker6_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker6_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker6_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_speaker5_first_name']['id'] = 'field_speaker5_first_name';
  $handler->display->display_options['fields']['field_speaker5_first_name']['table'] = 'field_data_field_speaker5_first_name';
  $handler->display->display_options['fields']['field_speaker5_first_name']['field'] = 'field_speaker5_first_name';
  $handler->display->display_options['fields']['field_speaker5_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker5_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker5_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_speaker4_first_name']['id'] = 'field_speaker4_first_name';
  $handler->display->display_options['fields']['field_speaker4_first_name']['table'] = 'field_data_field_speaker4_first_name';
  $handler->display->display_options['fields']['field_speaker4_first_name']['field'] = 'field_speaker4_first_name';
  $handler->display->display_options['fields']['field_speaker4_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker4_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker4_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_speaker2_first_name']['id'] = 'field_speaker2_first_name';
  $handler->display->display_options['fields']['field_speaker2_first_name']['table'] = 'field_data_field_speaker2_first_name';
  $handler->display->display_options['fields']['field_speaker2_first_name']['field'] = 'field_speaker2_first_name';
  $handler->display->display_options['fields']['field_speaker2_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker2_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker2_first_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_speaker5_last_name']['id'] = 'field_speaker5_last_name';
  $handler->display->display_options['fields']['field_speaker5_last_name']['table'] = 'field_data_field_speaker5_last_name';
  $handler->display->display_options['fields']['field_speaker5_last_name']['field'] = 'field_speaker5_last_name';
  $handler->display->display_options['fields']['field_speaker5_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker5_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker5_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_speaker6_last_name']['id'] = 'field_speaker6_last_name';
  $handler->display->display_options['fields']['field_speaker6_last_name']['table'] = 'field_data_field_speaker6_last_name';
  $handler->display->display_options['fields']['field_speaker6_last_name']['field'] = 'field_speaker6_last_name';
  $handler->display->display_options['fields']['field_speaker6_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker6_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker6_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_speaker4_last_name']['id'] = 'field_speaker4_last_name';
  $handler->display->display_options['fields']['field_speaker4_last_name']['table'] = 'field_data_field_speaker4_last_name';
  $handler->display->display_options['fields']['field_speaker4_last_name']['field'] = 'field_speaker4_last_name';
  $handler->display->display_options['fields']['field_speaker4_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker4_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker4_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_speaker3_last_name']['id'] = 'field_speaker3_last_name';
  $handler->display->display_options['fields']['field_speaker3_last_name']['table'] = 'field_data_field_speaker3_last_name';
  $handler->display->display_options['fields']['field_speaker3_last_name']['field'] = 'field_speaker3_last_name';
  $handler->display->display_options['fields']['field_speaker3_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker3_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker3_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_speaker1_last_name']['id'] = 'field_speaker1_last_name';
  $handler->display->display_options['fields']['field_speaker1_last_name']['table'] = 'field_data_field_speaker1_last_name';
  $handler->display->display_options['fields']['field_speaker1_last_name']['field'] = 'field_speaker1_last_name';
  $handler->display->display_options['fields']['field_speaker1_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker1_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker1_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_speaker2_last_name']['id'] = 'field_speaker2_last_name';
  $handler->display->display_options['fields']['field_speaker2_last_name']['table'] = 'field_data_field_speaker2_last_name';
  $handler->display->display_options['fields']['field_speaker2_last_name']['field'] = 'field_speaker2_last_name';
  $handler->display->display_options['fields']['field_speaker2_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_speaker2_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker2_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Enter search term';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Panel/Workshop Topics (field_panel_workshop_topics) */
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['id'] = 'field_panel_workshop_topics_value';
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['table'] = 'field_data_field_panel_workshop_topics';
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['field'] = 'field_panel_workshop_topics_value';
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['value'] = array(
    'Africa' => 'Africa',
    'Art' => 'Art',
    'Caribbean Basin' => 'Caribbean Basin',
    'China' => 'China',
    'Culture and Everyday Life' => 'Culture and Everyday Life',
    'Economics' => 'Economics',
    'Education' => 'Education',
    'Environment' => 'Environment',
    'Europe' => 'Europe',
    'Food' => 'Food',
    'Gender and Sexuality' => 'Gender and Sexuality',
    'Health' => 'Health',
    'Housing' => 'Housing',
    'India' => 'India',
    'Indigenous' => 'Indigenous',
    'International' => 'International',
    'Labor' => 'Labor',
    'Latin America' => 'Latin America',
    'Marxism, Anarchism and Theory' => 'Marxism, Anarchism and Theory',
    'Media' => 'Media',
    'Middle East' => 'Middle East',
    'Political And Social Movements' => 'Political And Social Movements',
    'Political Economy And The Current Crisis' => 'Political Economy And The Current Crisis',
    'Prison-Industrial Complex' => 'Prison-Industrial Complex',
    'Race' => 'Race',
    'Religion' => 'Religion',
    'Southeast Asia' => 'Southeast Asia',
    'U.S. Politics' => 'U.S. Politics',
    'Other' => 'Other',
  );
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['group'] = 1;
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['expose']['operator_id'] = 'field_panel_workshop_topics_value_op';
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['expose']['label'] = 'Panel/Workshop Topics';
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['expose']['operator'] = 'field_panel_workshop_topics_value_op';
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['expose']['identifier'] = 'field_panel_workshop_topics_value';
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_panel_workshop_topics_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Host/Sponsor (field_host_sponsor) */
  $handler->display->display_options['filters']['field_host_sponsor_value']['id'] = 'field_host_sponsor_value';
  $handler->display->display_options['filters']['field_host_sponsor_value']['table'] = 'field_data_field_host_sponsor';
  $handler->display->display_options['filters']['field_host_sponsor_value']['field'] = 'field_host_sponsor_value';
  $handler->display->display_options['filters']['field_host_sponsor_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_host_sponsor_value']['group'] = 1;
  $handler->display->display_options['filters']['field_host_sponsor_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_host_sponsor_value']['expose']['operator_id'] = 'field_host_sponsor_value_op';
  $handler->display->display_options['filters']['field_host_sponsor_value']['expose']['label'] = 'Host/Sponsor';
  $handler->display->display_options['filters']['field_host_sponsor_value']['expose']['operator'] = 'field_host_sponsor_value_op';
  $handler->display->display_options['filters']['field_host_sponsor_value']['expose']['identifier'] = 'field_host_sponsor_value';
  $handler->display->display_options['filters']['field_host_sponsor_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Abstract (field_abstract) */
  $handler->display->display_options['filters']['field_abstract_value']['id'] = 'field_abstract_value';
  $handler->display->display_options['filters']['field_abstract_value']['table'] = 'field_data_field_abstract';
  $handler->display->display_options['filters']['field_abstract_value']['field'] = 'field_abstract_value';
  $handler->display->display_options['filters']['field_abstract_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_abstract_value']['group'] = 1;
  $handler->display->display_options['filters']['field_abstract_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_abstract_value']['expose']['operator_id'] = 'field_abstract_value_op';
  $handler->display->display_options['filters']['field_abstract_value']['expose']['label'] = 'Abstract';
  $handler->display->display_options['filters']['field_abstract_value']['expose']['operator'] = 'field_abstract_value_op';
  $handler->display->display_options['filters']['field_abstract_value']['expose']['identifier'] = 'field_abstract_value';
  $handler->display->display_options['filters']['field_abstract_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Panel Track (field_panel_track) */
  $handler->display->display_options['filters']['field_panel_track_value']['id'] = 'field_panel_track_value';
  $handler->display->display_options['filters']['field_panel_track_value']['table'] = 'field_data_field_panel_track';
  $handler->display->display_options['filters']['field_panel_track_value']['field'] = 'field_panel_track_value';
  $handler->display->display_options['filters']['field_panel_track_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_panel_track_value']['group'] = 1;
  $handler->display->display_options['filters']['field_panel_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_panel_track_value']['expose']['operator_id'] = 'field_panel_track_value_op';
  $handler->display->display_options['filters']['field_panel_track_value']['expose']['label'] = 'Panel Track';
  $handler->display->display_options['filters']['field_panel_track_value']['expose']['operator'] = 'field_panel_track_value_op';
  $handler->display->display_options['filters']['field_panel_track_value']['expose']['identifier'] = 'field_panel_track_value';
  $handler->display->display_options['filters']['field_panel_track_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search by Speaker';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_speaker1_first_name' => 'field_speaker1_first_name',
    'field_speaker3_first_name' => 'field_speaker3_first_name',
    'field_po_first_name' => 'field_po_first_name',
    'field_speaker6_first_name' => 'field_speaker6_first_name',
    'field_speaker5_first_name' => 'field_speaker5_first_name',
    'field_speaker4_first_name' => 'field_speaker4_first_name',
    'field_speaker2_first_name' => 'field_speaker2_first_name',
  );
  $handler->display->display_options['path'] = 'programs';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Schedule';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_scheduled_date',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['use-grouping-header'] = 1;
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['style_options']['clearstyle'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_scheduled_date' => 'field_scheduled_date',
    'field_timeslot' => 'field_timeslot',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'Search for a Panel';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<br/><br.><a href="/programs">Search for a Panel</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['label'] = '';
  $handler->display->display_options['fields']['field_room']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_room']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Scheduled Date */
  $handler->display->display_options['fields']['field_scheduled_date']['id'] = 'field_scheduled_date';
  $handler->display->display_options['fields']['field_scheduled_date']['table'] = 'field_data_field_scheduled_date';
  $handler->display->display_options['fields']['field_scheduled_date']['field'] = 'field_scheduled_date';
  $handler->display->display_options['fields']['field_scheduled_date']['label'] = '';
  $handler->display->display_options['fields']['field_scheduled_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_scheduled_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scheduled_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot']['id'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['field'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['label'] = '';
  $handler->display->display_options['fields']['field_timeslot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br/>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Scheduled Date (field_scheduled_date) */
  $handler->display->display_options['sorts']['field_scheduled_date_value']['id'] = 'field_scheduled_date_value';
  $handler->display->display_options['sorts']['field_scheduled_date_value']['table'] = 'field_data_field_scheduled_date';
  $handler->display->display_options['sorts']['field_scheduled_date_value']['field'] = 'field_scheduled_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Room (field_room) */
  $handler->display->display_options['filters']['field_room_target_id']['id'] = 'field_room_target_id';
  $handler->display->display_options['filters']['field_room_target_id']['table'] = 'field_data_field_room';
  $handler->display->display_options['filters']['field_room_target_id']['field'] = 'field_room_target_id';
  $handler->display->display_options['filters']['field_room_target_id']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'schedules';
  $export['programs'] = $view;

  return $export;
}
