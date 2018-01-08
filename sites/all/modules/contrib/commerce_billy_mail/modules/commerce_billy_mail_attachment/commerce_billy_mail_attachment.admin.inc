<?php

/**
 * @file
 * Settings for Commerce Billy E-mail Attachment.
 */

/**
 * Admin settings form for e-mail attachment.
 */
function commerce_billy_mail_attachment_admin_form($form, &$form_state) {
  $settings = variable_get('commerce_billy_mail_attachment_fids', array());

  $form = array();
  for ($i=1; $i<=5; $i++) {
    $form['billy_mail_attachment_' . $i] = array(
      '#type' => 'managed_file',
      '#title' => t('Upload attachment'),
      '#default_value' => isset($settings[$i]) ? $settings[$i] : '',
      '#description' => t("Upload a file to be send as attachment"),
      '#upload_location' => 'public://commerce_billy_mail_attachments/',
    );
  }
  $form['#submit'][] = 'commerce_billy_mail_attachment_admin_form_submit';
  return system_settings_form($form);
}

/**
 * Submit handler for settings form.
 */
function commerce_billy_mail_attachment_admin_form_submit($form, $form_state) {
  global $user;

  $file_ids = array();
  for ($i=1; $i<=5; $i++) {
    if($form_state['values']['billy_mail_attachment_' . $i]) {

      $file = file_load($form_state['values']['billy_mail_attachment_' . $i]);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'file', 'commerce_billy_mail_attachment', $user->uid);

      $file_ids[$i] = $file->fid;
    }
  }

  variable_set('commerce_billy_mail_attachment_fids', $file_ids);
}
