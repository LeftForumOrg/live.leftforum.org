<?php
/**
 * This plugin array is more or less self documenting
 */
$plugin = array(
  'title' => t('Entity as Forms'),
  'single' => TRUE,
  'category' => array(t('Conference Organizing'), -9),
  'render callback' => 'cod_events_entity_forms_pane_render',
  'edit form' => 'cod_events_entity_forms_edit_form',
);

function cod_events_entity_forms_pane_render($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  list($conference, $bundle) = array_pad($context, 2, NULL);

  $entity_type = !empty($conf['entity_type']) ? $conf['entity_type'] : FALSE;
  $bundle = !empty($bundle) ? $bundle : $conf['bundle'];

  if (empty($entity_type)) {
    return;
  }

  // If no bundle is being shown, show helper text for sidebar.
  if (empty($bundle)) {
    $block->title = t('Conference Templates');
    $block->content = t('Select a template to edit.');
    return $block;
  }

  // TODO: Should load the bundle context in a context handler
  $bundle = Bundle::loadByMachineName($entity_type .'_' . $bundle);

  if (empty($bundle)) {
    watchdog('error', "Error loading bundles. Check the $entity_type feature.");
    return;
  }

  // First, check to see if a configuration entity exists
  $query = new EntityFieldQuery();
  $config = $query->entityCondition('entity_type', $entity_type)
    ->entityCondition('bundle', $bundle->name)
    ->fieldCondition('og_group_ref', 'target_id', $conference)
    ->range(0, 1)
    ->execute();

  // Found a config! load it.
   if (isset($config[$entity_type])) {
     $config_ids = array_keys($config[$entity_type]);
     $email_configs = entity_load($entity_type, $config_ids);
     $email_config = array_shift($email_configs);
     $email_config->og_group_ref[LANGUAGE_NONE][0]['target_id'] = $conference;
     $form = drupal_get_form("eck__entity__form_add_{$entity_type}_{$bundle->name}", $email_config);
   }
   // No config found, make a new entity.
  else {
    $email_config = entity_create($entity_type, array('type' => $bundle->name));
    $email_config->og_group_ref[LANGUAGE_NONE][0]['target_id'] = $conference;
    $form = drupal_get_form("eck__entity__form_edit_{$entity_type}_{$bundle->name}", $email_config);
  }
  // Hide URL redirects
  if (isset($form['redirect'])) {
    $form['redirect']['#access'] = FALSE;
  }
  // Hide the og_group_ref
  $form['og_group_ref']['#access'] = FALSE;
  
  $block->content = $form;
  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function cod_events_entity_forms_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['entity_type'] = array(
    '#type' => 'textfield',
    '#title' => t('Entity Type'),
    '#description' => t('Entity Type to pass into the form.'),
    '#default_value' => !empty($conf['entity_type']) ? $conf['entity_type'] : '',
  );
  $form['bundle'] = array(
    '#type' => 'textfield',
    '#title' => t('Bundle'),
    '#description' => t('Optional bundle type to pass into the form.'),
    '#default_value' => !empty($conf['bundle']) ? $conf['bundle'] : '',
  );
  return $form;
}

/**
 * Ctools edit form submit handler.
 *
 * @param $form
 * @param $form_state
 */
function cod_events_entity_forms_edit_form_submit($form, &$form_state) {
  foreach (array('entity_type', 'bundle') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}