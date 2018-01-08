<?php

/**
 * @file
 * Administrative functions for the Eventbrite Subuser module.
 */

module_load_include('inc', 'eventbrite', 'eventbrite.organizer');
module_load_include('inc', 'eventbrite', 'eventbrite.venue');

/**
 * Form constructor for the enabled-subuser form.
 *
 * @see eventbrite_subuser_list_form_submit()
 *
 * @ingroup forms
 */
function eventbrite_subuser_list_form($form, $form_state) {
  $form = array();

  $header = array(
    'email' => array(
      'data' => t('Email'),
      'field' => 'email',
    ),
    'user_id' => array(
      'data' => t('User ID'),
      'field' => 'user_id',
    ),
    'enabled_organizers' => array(
      'data' => t('Enabled Organizers'),
      'field' => 'user_id',
    ),
    'enabled_venues' => array(
      'data' => t('Enabled Venues'),
      'field' => 'user_id',
    ),
    'user_key' => array(
      'data' => t('User Key'),
      'field' => 'user_key',
    ),
  );

  $subuser_array = array();
  $checked = array();
  if ($subusers = eventbrite_subuser_refresh()) {
    $sql = 'SELECT user_id, status, email, user_key, enabled_organizers, enabled_venues '
      . 'FROM {eventbrite_subuser} WHERE 1';

    $result = db_query($sql);

    $destination = drupal_get_destination();

    foreach ($result as $subuser) {
      $subuser_id = $subuser->user_id;

      $organizers_link = l(
      	'configure',
      	"admin/config/services/eventbrite/subuser/$subuser_id/organizers",
        array('query' => $destination)
      );

      $enabled_organizers_val = '0, ' . $organizers_link;
      if (isset($subuser->enabled_organizers)) {
        if ($enabled_organizers = unserialize($subuser->enabled_organizers)) {
          $enabled_organizers_val = sizeof($enabled_organizers) . ', ' . $organizers_link;
        }
      }

      $venues_link = l(
      	'configure',
      	"admin/config/services/eventbrite/subuser/{$subuser->user_id}/venues",
        array('query' => $destination)
      );

      $venues_bycity_link = l(
      	'configure by city',
      	"admin/config/services/eventbrite/subuser/{$subuser->user_id}/venues-city",
        array('query' => $destination)
      );

      $enabled_venues_val = '0, ' . $venues_link; // .', '. $venues_bycity_link;
      if (isset($subuser->enabled_venues)) {
        if ($enabled_venues = unserialize($subuser->enabled_venues)) {
          $enabled_venues_val = sizeof($enabled_venues) . ', ' . $venues_link; // .', '. $venues_bycity_link;
        }
      }

      $subuser_array[$subuser_id] = array(
        'email' => l(
          $subuser->email,
          "admin/config/services/eventbrite/subuser/$subuser_id/view",
          array('query' => $destination)
        ),
        'user_id' => $subuser->user_id,
        'enabled_organizers' => $enabled_organizers_val,
        'enabled_venues' => $enabled_venues_val,
        'user_key' => $subuser->user_key,
      );
    }

    $enabled_subusers = eventbrite_subuser_get_enabled();
    if ($enabled_subusers) {
      foreach ($enabled_subusers as $uid=>$email) {
        $checked[$uid] = 1;
      }
    }

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save enabled subusers'),
      '#weight' => 100,
    );
  }

  $form['enabled_subusers'] = array (
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $subuser_array,
    '#empty' => t('There are currently no subusers configured for this user account'),
    '#default_value' => $checked,
    '#prefix' => '<div class="form-item"><label>' . t('Enabled Subusers:') . '</label></div>',
    '#js_select' => FALSE,
  );

  return $form;
}

/**
 * Form submission handler for eventbrite_subuser_list_form().
 */
function eventbrite_subuser_list_form_submit($form, &$form_state) {
  $enabled_subusers = $form_state['values']['enabled_subusers'];

  // Get current status for all subusers in DB
  $db_subusers = array();
  // Make sure DB matches enabled organizers list
  // TODO Please convert this statement to the D7 database API syntax.
  $result = db_query('SELECT user_id, status FROM {eventbrite_subuser} WHERE 1');
  foreach ($result as $subuser) {
    $db_subusers[$subuser->user_id] = $subuser;
  }

  // Scroll through subusers returned by form. Since this was a pager query we
  // don't want to affect any subusers that weren't listed on this pager page.
  foreach ($enabled_subusers as $user_id => $form_subuser_status) {
    $form_subuser_status = ($form_subuser_status) ? 1 : 0;
    // For each organizer, if status has changed update the DB
    $db_subuser = $db_subusers[$user_id];
    if ($form_subuser_status != $db_subuser->status) {
      $db_subuser->status = $form_subuser_status;
      drupal_write_record('eventbrite_subuser', $db_subuser, array('user_id'));
      // TODO: Log to watchdog if this doesn't write
    }
  }
}

/**
 * Page callback: Displays information about a subuser.
 *
 * @param $user_id
 *   The Eventbrite user ID.
 */
function eventbrite_subuser($user_id = NULL) {
  if (isset($user_id) && $subuser = eventbrite_subuser_load($user_id)) {
    return theme('eventbrite_subuser', array('subuser' => $subuser));
  }
  // TODO: Show message if !subuser
}

/**
 * Form constructor for the enabled-subuser form.
 *
 * Lists available venues or organizers as checkbox items in a form. Checked
 * items will be enabled for the relevant subuser.
 *
 * @param $user_id
 *   The Eventbrite user ID.
 * @param $subuser_op
 *   The type of object to list, 'organizers' or 'venues'.
 *
 * @see eventbrite_subuser_objects_submit()
 *
 * @ingroup forms
 */
function eventbrite_subuser_objects($form, $form_state, $user_id, $subuser_op) {
  $form = array();

  if (isset($user_id) && $subuser = eventbrite_subuser_load($user_id)) {
    // Add user id to form
    $form['user_id'] = array(
      '#type' => 'value',
      '#value' => $user_id,
    );

    $form['subuser_op'] = array(
      '#type' => 'value',
      '#value' => $subuser_op,
    );

    switch ($subuser_op) {
      case 'organizers':
        // Show select list of enabled organizers to activate
        $form['enabled_organizers'] = array(
          '#type' => 'checkboxes',
          '#title' => t('Enabled Organizers'),
          '#description' => t('Organizers accessible to this subuser'),
          '#options' => eventbrite_organizer_get_enabled(),
          '#default_value' => $subuser->enabled_organizers,
          '#weight' => 2,
        );
        break;
      case 'venues':
        // Show select list of enabled venues to activate
        $form['enabled_venues'] = array(
          '#type' => 'checkboxes',
          '#title' => t('Enabled venues'),
          '#description' => t('Venues accessible to this subuser'),
          '#options' => eventbrite_venue_get_enabled(),
          '#default_value' => $subuser->enabled_venues,
          '#weight' => 3,
        );
        break;
      case 'venues-city':
        // Show select list of cities to use for toggle venues
        $form['enabled_venues_by_city'] = array(
          '#type' => 'checkboxes',
          '#title' => t('Enable all venues in these cities'),
          '#description' => t('Venues accessible to this subuser'),
          '#options' => eventbrite_venue_get_enabled_bycity(),
          //          '#default_value' => $subuser->enabled_venues,
          '#weight' => 3,
        );
        break;
    }

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Update subuser access'),
      '#weight' => 10,
    );
  }

  return $form;
}

/**
 * Form submission handler for eventbrite_subuser_objects().
 */
function eventbrite_subuser_objects_submit($form, &$form_state) {
  if (!empty($form_state['values']['user_id']) && !empty($form_state['values']['subuser_op'])) {
    $subuser = new stdClass();

    $subuser->user_id = $form_state['values']['user_id'];

    switch ($form_state['values']['subuser_op']) {
      case 'organizers':
        $enabled_organizers = $form_state['values']['enabled_organizers'];
        foreach ($enabled_organizers as $key => $value) {
          if (!$value) {
            unset($enabled_organizers[$key]);
          }
        }
        $subuser->enabled_organizers = serialize($enabled_organizers);
        break;
      case 'venues':
        $enabled_venues = $form_state['values']['enabled_venues'];
        foreach ($enabled_venues as $key => $value) {
          if (!$value) {
            unset($enabled_venues[$key]);
          }
        }
        $subuser->enabled_venues = serialize($enabled_venues);
        break;
      case 'venues-city':
//        $subuser->enabled_venues = serialize($form_state['values']['enabled_venues']);
        break;
    }

    // Subuser already exists in DB, update with changes
    if (drupal_write_record('eventbrite_subuser', $subuser, array('user_id'))) {
      drupal_set_message('The configuration for this subuser has been updated locally.');
    }
    else {
      drupal_set_message('The configuration for this subuser could not be updated locally.', 'error');
      // TODO: Set watchdog entry
    }
  }
}

/**
 * Returns HTML for a subuser.
 *
 * @param array $variables
 *   An associative array containing:
 *   - subuser: The subuser object that is being formatted.
 *
 * @ingroup themeable
 */
function theme_eventbrite_subuser($variables) {
  $subuser = $variables['subuser'];
  $output = '<h2>' . $subuser->email;
  if ($subuser->status) {
    $output .= ' ' . t('(enabled)');
  }
  else {
    $output .= ' ' . t('(disabled)');
  }
  $output .= '</h2><br/>';

  if ($subuser->enabled_organizers) {
    $enabled_organizers = eventbrite_organizer_get_enabled();
    $output .= t('Enabled Organizers:') . '<br/>';
    $output .= '<ul>';
    foreach ($subuser->enabled_organizers as $organizer_id) {
      if (isset($enabled_organizers[$organizer_id])) {
        $output .= '<li>' . $enabled_organizers[$organizer_id] . '</li>';
      }
    }
    $output .= '</ul><br/>';
  }

  if ($subuser->enabled_venues) {
    $enabled_venues = eventbrite_venue_get_enabled();
    $output .= t('Enabled Venues:') . '<br/>';
    $output .= '<ul>';
    foreach ($subuser->enabled_venues as $venue_id) {
      if (isset($enabled_venues[$venue_id])) {
        $output .= '<li>' . $enabled_venues[$venue_id] . '</li>';
      }
    }
    $output .= '</ul></br>';
  }

  return $output;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 *
 * This function does not appear to be used.
 */
function eventbrite_subuser_submit($form, &$form_state) {
  if (!empty($form_state['values']['user_id'])) {
    $subuser = new stdClass();

    $subuser->user_id = $form_state['values']['user_id'];
    $subuser->status = $form_state['values']['status'];
    $subuser->enabled_organizers = serialize($form_state['values']['enabled_organizers']);

    $venue_access_method = variable_get('eventbrite_subuser_venue_access', 'venue');
    switch ($venue_access_method) {
      case 'venue':
        $subuser->enabled_venues = serialize($form_state['values']['enabled_venues']);
        break;
      case 'city':
        $subuser->enabled_venues = serialize($form_state['values']['enabled_venues']);
        break;
    }

    // Subuser already exists in DB, update with changes
    if (drupal_write_record('eventbrite_subuser', $subuser, array('user_id'))) {
      drupal_set_message('The configuration for this subuser has been updated locally.');
    }
    else {
      drupal_set_message('The configuration for this subuser could not be updated locally.', 'error');
      // TODO: Set watchdog entry
    }
  }
}
