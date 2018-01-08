
Introduction
------------

  Views Nested Accordion help in creating nested Accordion. If accordion is 
  grouped by more then one field then each header will act as accordion for its 
  inner elelment.

REQUIREMENTS
------------

  * Views Module
  * Views UI Module
  * Views Accordion


INSTALLATION
------------

  * Install as usual, see http://drupal.org/node/70151 for further information.

USING VIEWS NESTED ACCORDION MODULE
-----------------------------------

  Your view must meet the following requirements:
  * Row style must be set to Fields
  * Provide at least three fields to show.

  Choose Views Nested Accordion in the Style dialog within your view, which 
  will prompt you to configure the Nested Accordion.

  *        IMPORTANT       *
  Each grouped field will be used as the header for each accordion section, when
  header is clicked then inner fields will be displayed. The module creates an
  accordion section per row of results from the view. If the first field 
  includes a link, this link will not function, (the js returns false) Nothing 
  will break though.

CONFIGURATION
-------------
  To implement nested accordion the option "Nested Accordion" should be checked.
  When more then one field grouping is done then nested Accordion will be 
  implemented.
