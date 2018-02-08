<?php
/**
 * @file
 * jma_session_timeslots.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function jma_session_timeslots_default_rules_configuration() {
  $items = array();
  $items['rules_send_email_after_session'] = entity_import('rules_config', '{ "rules_send_email_after_session" : {
      "LABEL" : "Send email after Session",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "pet" ],
      "ON" : { "node_insert--session" : { "bundle" : "session" } },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "session" : "session" } } } }
      ],
      "DO" : [
        { "pet_action_send_pet" : {
            "pet_name" : "test_confirmation_mail_jma",
            "to_text" : "[node:author:mail],lopez.edsel@gmail.com",
            "to_account" : [ "" ],
            "account_subs" : [ "" ],
            "node_subs" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
