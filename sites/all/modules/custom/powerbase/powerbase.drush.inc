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
  drush_log(dt("Total Nodes: @nodes", array('@nodes' => $report['nodes'])));
  drush_log(dt("Total Contacts: @contacts", array('@contacts' => $report['contacts'])));
  drush_log(dt("Nodes without contacts: @nodes_without_contacts", array('@nodes_without_contacts' => $report['nodes_without_contacts'])));
}
