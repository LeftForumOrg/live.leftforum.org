<?php

Use Drush\Log\LogLevel;

/**
 * @file Multisite Install Drush Command
 */

/**
 * Implements hook_drush_command().
 */
function multisite_install_drush_command() {
  return [
    'multisite-install' => [
      'description' => 'Installs a multisite into an existing Drupal environment.',
      'bootstrap' => DRUSH_BOOTSTRAP_NONE,
      'drush dependencies' => ['sql', 'core'],
      'aliases' => ['msi'],
      'arguments' => [
        'site' => 'The mutlisite to install into the current database'
      ],
      'required-arguments' => TRUE,
      'examples' => [
        'drush multisite-install site' => 'Installs "site" into the current multisite Drupal setup.'
      ]
    ]
  ];
}

/**
 * Make sure site and settings exist within the filesystem.
 */
function drush_multisite_install_validate($site) {
  $path = DRUPAL_ROOT . "/sites/$site";
  $rep = ['!site' => $site];

  if (!file_exists($path)) {
    return drush_set_error(dt('Site directory for \'!site\' does not exist.', $rep));
  }

  if (!file_exists("$path/tables.json")) {
    return drush_set_error(dt('The \'tables.json\' file for \'!site\' does not exist.', $rep));
  }
}

/**
 * Callback for the multisite-install command.
 */
function drush_multisite_install($site) {
  $tables_json = file_get_contents(DRUPAL_ROOT . "/sites/$site/tables.json");
  $tables = json_decode($tables_json, true);
  
  if (empty($tables) || empty($tables['prefix'])) {
    drush_log(dt('No site-specific tables to create for \'!site.\'', ['!site' => $site]), LogLevel::OK);
    return;
  }

  foreach ($tables['prefix'] as $prefix => &$names) {
    foreach ($names as $name) {
      $table = "$prefix$name";
      try {
        db_create_table($table, drupal_get_schema($name));
        db_query("INSERT INTO $table SELECT * FROM $name");
        drush_log(dt('Created table \'!table\'.', ['!table' => $table]), LogLevel::SUCCESS);
      } catch (DatabaseSchemaObjectExistsException $e) {
        drush_log(dt('The \'!table\' table already exists.', ['!table' => $table]), LogLevel::CANCEL);
      }
    }
  }
}