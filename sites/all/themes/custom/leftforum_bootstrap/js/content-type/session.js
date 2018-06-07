jQuery(document).ready(function ($) {
  var org_link = $('#block-system-main .field-name-field-organizer .field-item > a');
  var view = $('.view-people-cards');
  var cards = view.find('.views-row, .views-bootstrap-grid-plugin-style .col');
  var card_links = cards.find('.views-field-title .field-content > a');

  card_links.each(function (index, value) {
    if (value.href === org_link[0].href) {
      cards[index].className += ' card-organizer';
    }
    if (cards[index].lastElementChild.firstElementChild.className.includes('featured-1')) {
      cards[index].className += ' card-featured';
    }
  });
});