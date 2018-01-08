<?php
/**
 * @file
 * cod_registration_reminder.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function cod_registration_reminder_eck_bundle_info() {
  $items = array(
    'cod_email_ticket_reminder' => array(
      'machine_name' => 'cod_email_ticket_reminder',
      'entity_type' => 'cod_email',
      'name' => 'ticket_reminder',
      'label' => 'Ticket Reminder',
      'config' => array(),
    ),
  );
  return $items;
}
