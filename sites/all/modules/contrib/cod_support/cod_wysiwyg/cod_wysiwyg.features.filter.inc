<?php
/**
 * @file
 * cod_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cod_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_url' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 128,
        ),
      ),
      'filter_html' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<h4> <h5> <h6> <em> <strong> <pre> <code> <del> <img> <blockquote> <q> <cite> <sup> <sub> <s> <p> <br>  <ul> <ol> <li> <dl> <dt> <dd> <a> <address> <b> <u> <i> <table> <tr> <td> <th> <tbody> <thead> <tfoot> <colgroup> <caption> <hr> <div> <!-->',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 1,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_url' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 128,
        ),
      ),
    ),
  );

  return $formats;
}
