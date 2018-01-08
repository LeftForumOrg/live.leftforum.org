/**
 * @file
 * JS for Nested Accordion.
 */

(function ($) {

Drupal.behaviors.views_nested_accordion = {
  attach: function(context) {
    if(Drupal.settings.views_nested_accordion){

        $.each(Drupal.settings.views_nested_accordion, function(id) {
          /* Our Nested Accordion Settings */
          var viewname = this.viewname;
          /* Add Class to the Group Header On Page Load */
          $('.view-id-' + viewname + ' .view-grouping:first-child .view-grouping-header').addClass('nested-accordion');
          /* Generate Accordion Effect on Outer Header Click */
          $('.view-id-' + viewname + ' .view-grouping .view-grouping-header').click(function() {

                  var attrib = $(this).attr("class");
                  var remove = attrib.split(" ");
                  if (remove[1] == 'nested-accordion') {
                    /* If Accordion is Open, then Clicking on it will close the Accordion. */
                    $(this).removeClass("nested-accordion");
                    $(this).siblings('.view-grouping-content').slideUp();
                  } else {
                    /* Clicking on Header will Open the Accordion */
                    $(this).addClass('nested-accordion');
                    $(this).siblings('.view-grouping-content').slideDown();
                    $(this).parents('.view-grouping').siblings('.view-grouping').children('.view-grouping-header').removeClass('nested-accordion');
                    $(this).parents('.view-grouping').siblings('.view-grouping').children('.view-grouping-content').slideUp();
                  }

          });
        });
    }
  }
};

})(jQuery);
