<?php

/**
 * @file
 * Content Type Clone cloning functions.
 */

/**
 * Form constructor for the clone creation.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   Reference to the form state array.
 * @param string $machine_name
 *   The machine name of the source content type.
 */
function content_type_clone_create_form(array $form, array &$form_state, $machine_name) {
  // Load the node type from machine name.
  $node_type = node_type_load($machine_name);

  // Prepare the new node type machine name prefix.
  $node_type_prefix = $node_type->type . '_clone';

  // Get the next occurrence count.
  $num = content_type_clone_get_next_type_number($node_type_prefix);

  // Source fieldset.
  $form['fieldset_1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content type source'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Source node type name field.
  $form['fieldset_1']['source_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $node_type->name,
    '#required' => TRUE,
    '#attributes' => array(
      'readonly' => 'readonly',
      'class' => array('ctc-readonly'),
    ),
  );

  // Source node type machine name field.
  $form['fieldset_1']['source_machine_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Machine name'),
    '#default_value' => $node_type->type,
    '#required' => TRUE,
    '#attributes' => array(
      'readonly' => 'readonly',
      'class' => array('ctc-readonly'),
    ),
  );

  // Source node type description field.
  $form['fieldset_1']['source_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $node_type->description,
    '#attributes' => array(
      'readonly' => 'readonly',
      'class' => array('ctc-readonly'),
    ),
  );

  // Target fieldset.
  $form['fieldset_2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content type target'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  // Target node type name field.
  $default_value = 'Clone of ' . $node_type->name . ' (' . $num . ')';
  $form['fieldset_2']['target_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $default_value,
    '#token' => FALSE,
    '#required' => TRUE,
  );

  // Target type machine name field.
  $form['fieldset_2']['target_machine_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Machine name'),
    '#default_value' => $node_type_prefix . '_' . $num,
    '#required' => TRUE,
  );

  // Source node type description field.
  $form['fieldset_2']['target_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => t(
      'Description of @name (@num)',
      array(
        '@name' => $node_type->name,
        '@num' => $num,
      )
    ),
  );

  // Clone parameters fieldset.
  $form['fieldset_2']['clone_source_nodes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Copy all nodes from the source content type to the target content type'),
  );

  // Delete parameters fieldset.
  $form['fieldset_2']['delete_source_nodes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete all nodes from the source content type after they have been copied to the target content type'),
  );

  // Token fieldset.
  $form['fieldset_3'] = array(
    '#type' => 'fieldset',
    '#title' => t('Replacement patterns'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Token fields.
  if (module_exists('token')) {
    // Display the node title pattern field.
    $default_value = t('Clone of @title', array('@title' => '[node:title]'));
    $form['fieldset_3']['title_pattern'] = array(
      '#type' => 'textfield',
      '#title' => t('Node title pattern'),
      '#default_value' => $default_value,
      '#token' => FALSE,
      '#required' => TRUE,
    );

    // List available tokens.
    $form['fieldset_3']['token_tree_link'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('node'),
      '#global_types' => TRUE,
      '#click_insert' => TRUE,
    );
  }
  else {
    $form['fieldset_3']['token_tree'] = array(
      '#markup' => '<p>' . t('Enable the <a href="@drupal-token">Token module</a> to view the available token browser.',
        array(
          '@drupal-token' => 'http://drupal.org/project/token',
        )
      ) . '</p>',
    );
  }

  // Submit button.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate'),
  );

  // Attach the admin css file.
  $form['#attached']['css'] = array(
    drupal_get_path('module', 'content_type_clone') . '/css/admin.css',
  );

  // Return the form.
  return $form;
}

/**
 * Generate a default item number for a new clone.
 *
 * This function will add the clone number to the machine name, the title
 * and the description fields in the content type creation form.
 *
 * The clone number is based on the number of existing clones
 * for the content type being cloned.
 *
 * @param string $node_type_prefix
 *   The default prefix defined for the new content type.
 */
function content_type_clone_get_next_type_number($node_type_prefix) {
  // Get node types.
  $node_types = array_keys(node_type_get_types());

  // Prepare the search pattern.
  $pattern = '/^' . $node_type_prefix . '/';

  // Count existing prefix occurrences.
  $occurrences = count(preg_grep($pattern, $node_types));

  // Return an incremented value.
  return $occurrences + 1;
}

/**
 * Form validation handler for the clone creation form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   Reference to the form state array.
 */
function content_type_clone_create_form_validate(array $form, array &$form_state) {
  if ($form['#form_id'] == 'content_type_clone_create_form') {
    // Get node types.
    $node_types = array_keys(node_type_get_types());

    // If the machine name already exists.
    if (in_array($form_state['values']['target_machine_name'], $node_types)) {
      form_set_error('target_machine_name', t('The content type name provided already exists'));
    }

    // Add the custom form submit handler.
    $form['#submit'][] = 'content_type_clone_create_form_submit';
  }
}

/**
 * Form submit handler for the clone creation form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   Reference to the form state array.
 */
function content_type_clone_create_form_submit(array $form, array &$form_state) {
  if ($form['#form_id'] == 'content_type_clone_create_form') {
    // Reset counter for debug information.
    $_SESSION['http_request_count'] = 0;

    // Execute the function batch function.
    $batch = content_type_clone_create($form_state['values']);
    batch_set($batch);
  }
}

/**
 * Create a content type clone.
 *
 * This function creates the new content type and adds the cloned fields.
 *
 * @param array $values
 *   Form values coming from the content type creation form.
 */
function content_type_clone_create(array $values) {
  // Create the type definition array.
  $type = array(
    'type' => $values['target_machine_name'],
    'name' => $values['target_name'],
    'base' => 'node_content',
    'description' => $values['target_description'],
    'custom' => 1,
    'modified' => 1,
    'locked' => 0,
  );

  // Set the type defaults.
  $type = node_type_set_defaults($type);

  // Save the ndoe type.
  node_type_save($type);

  // Add body field.
  node_add_body_field($type);

  // Prepare the operations array.
  $operations = array();

  // Get node type base fields.
  $base_fields = field_info_instances('node', $values['source_machine_name']);

  // Get node type extra fields.
  $extra_fields = field_info_extra_fields('node', $values['source_machine_name'], 'form');

  // Merge all fields.
  $all_fields = array_merge($base_fields, $extra_fields);

  // Create new fields.
  foreach ($all_fields as $name => $instance) {
    $operations[] = array(
      'content_type_clone_set_target_field',
      array($instance, $name, $values),
    );
  }

  // Also clone the nodes if requested.
  if ((int) $values['clone_source_nodes'] == 1) {
    // Load all nodes for the source content type.
    $nids = content_type_clone_get_type_nids($values['source_machine_name']);

    // Loop through each node.
    foreach ($nids as $nid) {
      // Add an operation.
      $operations[] = array(
        'content_type_clone_copy_node',
        array($nid, $values),
      );
    }
  }

  // Define batch operation.
  $batch = array(
    'title' => t('Clone content type'),
    'operations' => $operations,
    'file' => drupal_get_path('module', 'content_type_clone') . '/includes/clone.admin.inc',
    'finished' => 'content_type_clone_finished',
    'init_message' => t('Operation in progress...'),
    'progress_message' => t('Task @current/@total'),
    'error_message' => t('An error has occurred please try again.'),
  );

  return $batch;
}

/**
 * Create a field.
 *
 * This function creates a field for a cloned content type.
 *
 * @param object $instance
 *   The newly created content type.
 * @param string $field_name
 *   The name of the field in the source content type.
 * @param array $values
 *   Form values coming from the content type creation form.
 */
function content_type_clone_set_target_field($instance, $field_name, array $values, array &$context) {
  // Progress context results.
  $context['results'][] = $field_name;

  // Pass the cloned content type name to context.
  $context['results']['source_name'] = $values['source_name'];

  // Update the field count.
  $context['results']['field_count']++;

  // Progress context message.
  $context['message'] = t('Cloning field @field',
    array(
      '@field' => $field_name,
    )
  );

  // Verify the field does not already exist.
  if ($field_name != 'body' && $field_name != 'title') {
    // If field doesn't exist, create it.
    if (!field_info_field($field_name)) {
      $field = field_info_field($field_name);
      $field = field_create_field($field);
    }

    // Set the new bundle name.
    $instance['bundle'] = $values['target_machine_name'];
    $instance['field_name'] = $field_name;

    // Create an instance of the field and bind it to the bundle.
    field_create_instance($instance);
  }

  // Update progress.
  _content_type_clone_update_http_requests();
}

/**
 * Utility function to increment HTTP requests in a session variable.
 */
function _content_type_clone_update_http_requests() {
  $_SESSION['http_request_count']++;
}

/**
 * Get node ids by content type.
 *
 * This function returns all node ids for a given content type.
 *
 * @param string $type
 *   The content type.
 */
function content_type_clone_get_type_nids($type) {
  // Get all nids for the content type.
  $nids = db_query('SELECT nid FROM {node} WHERE type =  :type',
  array(
    ':type' => $type,
  ))->fetchCol();

  // Return the results.
  return $nids;
}

/**
 * Clone a node.
 *
 * This function copies a node from the
 * source content type to the target content type.
 *
 * @param object $node_id
 *   The id of the node to clone.
 * @param array $values
 *   Values from the content type clone form.
 * @param array $context
 *   The batch operations context.
 */
function content_type_clone_copy_node($node_id, array $values, array &$context) {
  // Load the node by id.
  $source_node = node_load($node_id);

  // Progress context results.
  $context['results'][] = 'nid' . $source_node->nid;

  // Update the node count.
  $context['results']['node_count']++;

  // Progress context message.
  $context['message'] = t('Cloning node @title',
    array(
      '@title' => $source_node->title,
    )
  );

  // Copy the source node.
  $target_node = clone $source_node;

  // Unset version and node id's.
  unset($target_node->nid);
  unset($target_node->vid);
  unset($target_node->path);

  // Set target node type.
  $target_node->type = $values['target_machine_name'];

  // Set the target node title.
  if (module_exists('token')) {
    $target_node->title = token_replace($values['title_pattern'], array('node' => $target_node));
  }
  else {
    $target_node->title = t('Clone of @title',
      array(
        '@title' => $source_node->title,
      )
    );
  }

  // Save the copy.
  node_save($target_node);

  // Delete the source node if required.
  if ((int) $values['delete_source_nodes'] == 1) {
    node_delete($source_node->nid);
  }

  // Update progress.
  _content_type_clone_update_http_requests();
}

/**
 * Utility function to count the HTTP requests in a session variable.
 *
 * @return int
 *   Number of requests.
 */
function _content_type_clone_get_http_requests() {
  return !empty($_SESSION['http_request_count']) ? $_SESSION['http_request_count'] : 0;
}

/**
 * Batch operation finished.
 *
 * This function displays a message after the batch operation ends.
 *
 * @param bool $success
 *   The batch status.
 * @param array $results
 *   The batch results array.
 * @param array $operations
 *   The batch operations array.
 */
function content_type_clone_finished($success, array $results, array $operations) {
  // Test the results.
  if ($success) {
    drupal_set_message(
      t(
        'The "@source_name" content type and @field_count fields have been cloned successfully.',
        array(
          '@source_name' => $results['source_name'],
          '@field_count' => $results['field_count'],
        )
      )
    );
  }
  else {
    $error_operation = reset($operations);
    drupal_set_message(
      t(
        'An error occurred while processing @operation with arguments : @args',
        array(
          '@operation' => $error_operation[0],
          '@args' => print_r($error_operation[0], TRUE),
        )
      )
    );
  }

  // Redirect to the content types list.
  drupal_goto('/admin/structure/types');
}
