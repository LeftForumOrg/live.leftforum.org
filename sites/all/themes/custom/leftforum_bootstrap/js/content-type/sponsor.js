jQuery(document).ready(function ($) {
  var org_banner = $('#block-system-main .field-name-field-org-logo-rectangle');
  var org_image = $('#block-system-main .field-name-field-org-logo-circle-or-square');

  if (!org_banner.empty() && !org_image.empty()) {
    console.log('Hey Man :(');
  }
});