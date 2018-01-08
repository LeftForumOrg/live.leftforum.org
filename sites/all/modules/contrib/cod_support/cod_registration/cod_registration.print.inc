<?php

function cod_registration_confirmation_print_submit($form, $form_state) {

  $ticket_registration = $form['#entity'];

  if ($form_state['clicked_button']['#value'] == 'Print Badge') {
    $content['username']['first'] = $form_state['input']['field_profile_first'][LANGUAGE_NONE][0]['value'];
    $content['username']['last'] = $form_state['input']['field_profile_last'][LANGUAGE_NONE][0]['value'];
    $content['company'] = $form_state['input']['field_profile_org'][LANGUAGE_NONE][0]['value'];
    //get vcard data
    $vcard = cod_registration_get_vcard($ticket_registration);
    $vcard_text = $vcard->fetch();

    // We need to encode the vcard url to protect PII.
    $encode = base64_encode(crc32($ticket_registration->created . $ticket_registration->trid));
    $content['qr_code'] = theme('mobilecode', array('data' => 'https://lfnw.org/v/'.$ticket_registration->trid.'/'.$encode.'.vcf', 'attributes' => array('#preset' => 'cod_registration_qrcode')));

    $output = theme('cod_registration_pdf', array('content' => $content));

    _sendtopdf($output, $ticket_registration->trid);
    exit();
  }
}

function _sendtopdf($output, $ticket_id) {
  global $base_url;
  require_once(drupal_get_path('module', 'print_pdf') . '/print_pdf.pages.inc');
  require_once(drupal_get_path('module', 'print') . '/print.pages.inc');
  $print = array();
  $print['submitted'] = '';
  $print['title'] = 'Badge';
  $print['taxonomy'] = '';
  // Disable caching for generated PDFs, as Drupal doesn't ouput the proper headers from the cache
  $GLOBALS['conf']['cache'] = FALSE;
  $print_pdf_pdf_tool = variable_get('print_pdf_pdf_tool', PRINT_PDF_PDF_TOOL_DEFAULT);

  // Img elements must be set to absolute
  $pattern = '!<(img\s[^>]*?)>!is';
  $content = preg_replace_callback($pattern, '_print_rewrite_urls', $output);

  // Send to printer option causes problems with PDF
  $print['sendtoprinter'] = '';

//  $node = $print['node'];
//  $html = theme('print_page', $print, PRINT_PDF_FORMAT, $node);
  $html = $content;

  // Convert the a href elements, to make sure no relative links remain
  $pattern = '!<(a\s[^>]*?)>!is';
  $html = preg_replace_callback($pattern, '_print_rewrite_urls', $html);
  // And make anchor links relative again, to permit in-PDF navigation
  $html = preg_replace("!${base_url}/" . PRINTPDF_PATH . "/.*?%2523!", '#', $html);

  $pdf_filename = 'cod_badge_' . $ticket_id . '.pdf';
/*
  if (headers_sent()) {
    die("Unable to stream pdf: headers already sent");
  }
 // header("Cache-Control: private");
  header("Content-Type: application/pdf");

  $attachment = "inline";

  header("Content-Disposition: $attachment; filename=\"$pdf_filename\"");
  */
  //$pdf_filename = str_replace(' ', '_', $path) .'.pdf';

  if (basename($print_pdf_pdf_tool) == 'dompdf_config.inc.php') {
    _print_pdf_dompdf($print, $html, $pdf_filename);
  }
  elseif (basename($print_pdf_pdf_tool) == 'tcpdf.php') {
    _print_pdf_tcpdf($print, $html, $pdf_filename);
  }
  elseif (substr(basename($print_pdf_pdf_tool, '.exe'), 0, 11) == 'wkhtmltopdf') {
    _print_pdf_wkhtmltopdf($print, $html, $pdf_filename);
  }
  else {
    return drupal_not_found();
  }
/*
  $nodepath = (isset($node->path)) ? drupal_get_normal_path($node->path) : 'node/'. $path;
  db_query("UPDATE {print_pdf_page_counter} SET totalcount = totalcount + 1, timestamp = %d WHERE path = '%s'", time(), $nodepath);
  // If we affected 0 rows, this is the first time viewing the node.
  if (!db_affected_rows()) {
    // We must create a new row to store counters for the new node.
    db_query("INSERT INTO {print_pdf_page_counter} (path, totalcount, timestamp) VALUES ('%s', 1, %d)", $nodepath, time());
  }
  */
}