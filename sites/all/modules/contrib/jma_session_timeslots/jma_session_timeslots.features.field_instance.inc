<?php
/**
 * @file
 * jma_session_timeslots.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function jma_session_timeslots_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-session-field_room'.
  $field_instances['node-session-field_room'] = array(
    'bundle' => 'session',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 83,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_room',
    'label' => 'Room',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference_dragdrop',
      'settings' => array(
        'available_entities_label' => 'Drag a room to the right to schedule it',
        'display_filter' => 0,
        'selected_entities_label' => 'Selected Room',
        'view_mode' => 'title',
      ),
      'type' => 'entityreference_dragdrop',
      'weight' => 51,
    ),
  );

  // Exported field_instance: 'node-session-field_timeslot'.
  $field_instances['node-session-field_timeslot'] = array(
    'bundle' => 'session',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 84,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_timeslot',
    'label' => 'Timeslot',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference_dragdrop',
      'settings' => array(
        'available_entities_label' => 'Available Time Slots',
        'display_filter' => 0,
        'selected_entities_label' => 'Selected Time Slot',
        'view_mode' => 'title',
      ),
      'type' => 'entityreference_dragdrop',
      'weight' => 53,
    ),
  );

  // Exported field_instance: 'rooms-rooms-field_room_capacity'.
  $field_instances['rooms-rooms-field_room_capacity'] = array(
    'bundle' => 'rooms',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'rooms',
    'field_name' => 'field_room_capacity',
    'label' => 'Capacity',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Capacity');
  t('Room');
  t('Timeslot');

  return $field_instances;
}
