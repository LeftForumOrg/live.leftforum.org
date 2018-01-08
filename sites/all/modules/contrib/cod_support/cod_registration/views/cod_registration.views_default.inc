<?php
/**
 * @file
 * cod_session.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cod_registration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cod_registration_checkin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'ticket_registration';
  $view->human_name = 'Registration Checkin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Check-in';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit all ticket registrations';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/!1/cod_registration?checkin=1">Register and Check-in New Users</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Ticket registration: Author entity author_uid */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  $handler->display->display_options['relationships']['author']['label'] = 'Author User';
  /* Relationship: Ticket registration: User entity user_uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['label'] = 'Registered User';
  /* Relationship: Ticket registration: Ticket Type */
  $handler->display->display_options['relationships']['ticket_type_ttid']['id'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['table'] = 'ticket_registration';
  $handler->display->display_options['relationships']['ticket_type_ttid']['field'] = 'ticket_type_ttid';
  $handler->display->display_options['relationships']['ticket_type_ttid']['required'] = TRUE;
  /* Field: Ticket registration Revisions: Ticket Registration ID */
  $handler->display->display_options['fields']['trid']['id'] = 'trid';
  $handler->display->display_options['fields']['trid']['table'] = 'ticket_registration_revision';
  $handler->display->display_options['fields']['trid']['field'] = 'trid';
  $handler->display->display_options['fields']['trid']['label'] = 'Ticket ID';
  $handler->display->display_options['fields']['trid']['separator'] = '';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_profile_first']['id'] = 'field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['table'] = 'field_data_field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['field'] = 'field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_profile_first']['label'] = 'Full Name';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_profile_last']['id'] = 'field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['table'] = 'field_data_field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['field'] = 'field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_profile_last']['label'] = '';
  $handler->display->display_options['fields']['field_profile_last']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'author';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'Attendee Username';
  /* Contextual filter: Ticket type: Entity ID */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'ticket_type';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['relationship'] = 'ticket_type_ttid';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['entity_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['entity_id']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['entity_id']['validate']['fail'] = 'access denied';
  /* Filter criterion: User: First name (field_profile_first) */
  $handler->display->display_options['filters']['field_profile_first_value']['id'] = 'field_profile_first_value';
  $handler->display->display_options['filters']['field_profile_first_value']['table'] = 'field_data_field_profile_first';
  $handler->display->display_options['filters']['field_profile_first_value']['field'] = 'field_profile_first_value';
  $handler->display->display_options['filters']['field_profile_first_value']['relationship'] = 'user';
  $handler->display->display_options['filters']['field_profile_first_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_profile_first_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['operator_id'] = 'field_profile_first_value_op';
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['operator'] = 'field_profile_first_value_op';
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['identifier'] = 'field_profile_first_value';
  $handler->display->display_options['filters']['field_profile_first_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_profile_first_value']['group_info']['label'] = 'First name (field_profile_first)';
  $handler->display->display_options['filters']['field_profile_first_value']['group_info']['identifier'] = 'field_profile_first_value';
  $handler->display->display_options['filters']['field_profile_first_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_profile_first_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: User: Last name (field_profile_last) */
  $handler->display->display_options['filters']['field_profile_last_value']['id'] = 'field_profile_last_value';
  $handler->display->display_options['filters']['field_profile_last_value']['table'] = 'field_data_field_profile_last';
  $handler->display->display_options['filters']['field_profile_last_value']['field'] = 'field_profile_last_value';
  $handler->display->display_options['filters']['field_profile_last_value']['relationship'] = 'user';
  $handler->display->display_options['filters']['field_profile_last_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_profile_last_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['operator_id'] = 'field_profile_last_value_op';
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['operator'] = 'field_profile_last_value_op';
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['identifier'] = 'field_profile_last_value';
  $handler->display->display_options['filters']['field_profile_last_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    7 => 0,
    3 => 0,
    6 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'author';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail (Registrar)';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail_1']['id'] = 'mail_1';
  $handler->display->display_options['filters']['mail_1']['table'] = 'users';
  $handler->display->display_options['filters']['mail_1']['field'] = 'mail';
  $handler->display->display_options['filters']['mail_1']['relationship'] = 'user';
  $handler->display->display_options['filters']['mail_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail_1']['expose']['operator_id'] = 'mail_1_op';
  $handler->display->display_options['filters']['mail_1']['expose']['label'] = 'Attendee E-mail';
  $handler->display->display_options['filters']['mail_1']['expose']['operator'] = 'mail_1_op';
  $handler->display->display_options['filters']['mail_1']['expose']['identifier'] = 'mail_1';
  $handler->display->display_options['filters']['mail_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );
  /* Filter criterion: Ticket registration: Ticket Registration ID */
  $handler->display->display_options['filters']['trid']['id'] = 'trid';
  $handler->display->display_options['filters']['trid']['table'] = 'ticket_registration';
  $handler->display->display_options['filters']['trid']['field'] = 'trid';
  $handler->display->display_options['filters']['trid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['trid']['expose']['operator_id'] = 'trid_op';
  $handler->display->display_options['filters']['trid']['expose']['label'] = 'Registration ID';
  $handler->display->display_options['filters']['trid']['expose']['operator'] = 'trid_op';
  $handler->display->display_options['filters']['trid']['expose']['identifier'] = 'trid';
  $handler->display->display_options['filters']['trid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    8 => 0,
    4 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/registration/checkin';
  $export['cod_registration_checkin'] = $view;

  return $export;
}
