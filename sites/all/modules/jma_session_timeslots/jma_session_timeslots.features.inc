<?php
/**
 * @file
 * jma_session_timeslots.features.inc
 */

/**
 * Implements hook_views_api().
 */
function jma_session_timeslots_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function jma_session_timeslots_eck_bundle_info() {
  $items = array(
    'rooms_rooms' => array(
      'machine_name' => 'rooms_rooms',
      'entity_type' => 'rooms',
      'name' => 'rooms',
      'label' => 'Rooms',
      'config' => array(),
    ),
    'timeslot_timeslot' => array(
      'machine_name' => 'timeslot_timeslot',
      'entity_type' => 'timeslot',
      'name' => 'timeslot',
      'label' => 'Timeslot',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function jma_session_timeslots_eck_entity_type_info() {
  $items = array(
    'rooms' => array(
      'name' => 'rooms',
      'label' => 'Rooms',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
    'timeslot' => array(
      'name' => 'timeslot',
      'label' => 'Timeslot',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_default_pet().
 */
function jma_session_timeslots_default_pet() {
  $items = array();
  $items['test_confirmation_mail_jma'] = entity_import('pet', '{
    "name" : "test_confirmation_mail_jma",
    "title" : "Test Confirmation Mail - JMA",
    "subject" : "This is a test mail",
    "mail_body" : "\\u003Ctable align=\\u0022center\\u0022 border=\\u00220\\u0022 cellpadding=\\u00220\\u0022 cellspacing=\\u00220\\u0022 width=\\u0022560\\u0022\\u003E\\r\\n\\t\\u003Ctbody\\u003E\\r\\n\\t\\t\\u003Ctr\\u003E\\r\\n\\t\\t\\t\\u003Ctd\\u003E\\r\\n\\t\\t\\t\\t\\u003Ch2\\u003E\\r\\n\\t\\t\\t\\t\\tLeft Forum\\u003C\\/h2\\u003E\\r\\n\\t\\t\\t\\t\\u003Cp\\u003E\\r\\n\\t\\t\\t\\t\\tHelping people in all over the world to get the\\u0026nbsp; they need.\\u003C\\/p\\u003E\\r\\n\\t\\t\\t\\t\\u003Cp\\u003E\\r\\n\\t\\t\\t\\t\\t\\u003Cstrong\\u003E[current-date:date_no_time]\\u003C\\/strong\\u003E.\\u003C\\/p\\u003E\\r\\n\\t\\t\\t\\t\\u003Cp\\u003E\\r\\n\\t\\t\\t\\t\\tWe especially need people to help with the registration and admission process, to direct conference attendees to the hundreds of panels and our book exhibits, and to guide people into our plenary events. We also need help with media, video recording and coordinating, and closing operations. Volunteering for one shift gets you a free 3-day conference pass, but we hope that you can do more!\\u003C\\/p\\u003E\\r\\n\\t\\t\\t\\t\\u003Cp\\u003E\\r\\n\\t\\t\\t\\t\\t\\u003Ca href=\\u0022http:\\/\\/www.leftforum.org\\/2011\\/volunteer-left-forum\\u0022\\u003ESupport our efforts to get the conference rolling!\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n\\t\\t\\t\\u003C\\/td\\u003E\\r\\n\\t\\t\\u003C\\/tr\\u003E\\r\\n\\t\\u003C\\/tbody\\u003E\\r\\n\\u003C\\/table\\u003E\\r\\n\\u003Cdiv style=\\u0022text-align: left; font-size: 90%\\u0022\\u003E\\r\\n\\tThis email is sent from:\\u003Cbr \\/\\u003E\\r\\n\\t[site:name]\\u003C\\/div\\u003E\\r\\n\\u003Cdiv style=\\u0022text-align: left; font-size: 90%;\\u0022\\u003E\\r\\n\\t\\u0026nbsp;\\u003C\\/div\\u003E\\r\\n",
    "mail_body_plain" : "",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : ""
  }');
  return $items;
}
