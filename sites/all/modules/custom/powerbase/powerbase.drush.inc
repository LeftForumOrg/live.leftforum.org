<?php

/**
 * @file Powerbase drush commands
 */


function powerbase_drush_command() {
  $items = array();
  $items['powerbase-sync-contacts'] = array(
    'description' => 'Synchronize all session contacts to their respective Powerbase Groups.',
  );
  return $items;
}

function drush_powerbase_sync_contacts() {
  $report = powerbase_process_all_nodes();
  drush_log(dt("Total Nodes: @nodes", array('@nodes' => $report['nodes'])), 'ok');
  drush_log(dt("Total Organizers: @organizers", array('@organizers' => $report['organizers'])), 'ok');
  drush_log(dt("Total Faciliators: @facilitators", array('@facilitators' => $report['facilitators'])), 'ok');
}
