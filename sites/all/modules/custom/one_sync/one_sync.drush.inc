<?php

/**
 * @file One Sync for All Drush Command
 */

/*
 * Implements hook_drush_command().
 */
function one_sync_drush_command() {
  return [
    'one-sync' => [
      'description' => 'Synchronize two drupal sites with one command.',
      'bootstrap' => DRUSH_BOOTSTRAP_NONE,
      'drush dependencies' => ['sql', 'core'],
      'arguments' => [
        'source' => 'A site-alias whose files and data you want to copy from.',
        'target' => 'A site-alias whose files and data you want to replace.'
      ],
      'required-arguments' => TRUE,
      'examples' => [
        'drush one-sync @source @target' => 'Copy the database and files from the site with the alias "source" to the site with the alias "target".'
      ]
    ]
  ];
}

/*
 * Callback for the one-sync command.
 */
function drush_one_sync($source, $target) {
  // Synchronize 'files' directories
  $result = drush_invoke_process($source, 'site-alias', [], [], ['output' => FALSE]);
  $sites = preg_split('/@\S+|\s+/', $result['output'], -1, PREG_SPLIT_NO_EMPTY);
  foreach ($sites as $site) {
    drush_invoke_process('@self', 'rsync', [
      "$source:sites/$site/files",
      "$target:sites/$site/files"
    ], ['delete' => 0]);
  }

  // Synchronize databases
  drush_invoke_process('@self', 'sql-sync', [$source, $target]);
}