(function($){
  
  Drupal.entityreference_dragdrop = Drupal.entityreference_dragdrop ? Drupal.entityreference_dragdrop : {};
  
  Drupal.entityreference_dragdrop.update = function (event, ui) {
    var items = [];
    var ec = $(event.target).attr("data-ec");
    $(".entityreference-dragdrop-selected[data-ec=" + ec + "] li").each(function(index) {
      items.push($(this).attr('data-id'));
    });
    $("input.entityreference-dragdrop-values[data-ec=" + ec +"]").val(items.join(','));
    
    if (Drupal.settings.entityreference_dragdrop[ec] != -1) {
      if (items.length > Drupal.settings.entityreference_dragdrop[ec]) {
        $(".entityreference-dragdrop-message[data-ec=" + ec + "]").show();
        $(".entityreference-dragdrop-selected[data-ec=" + ec + "]").css("border", "1px solid red");
      }
      else {
        $(".entityreference-dragdrop-message[data-ec=" + ec + "]").hide();
        $(".entityreference-dragdrop-selected[data-ec=" + ec + "]").css("border", "");
      }
    }
  };
  
  Drupal.behaviors.entityreference_dragdrop = {
    attach: function() {
      var $avail = $(".entityreference-dragdrop-available"),
        $select = $(".entityreference-dragdrop-selected");


      $avail.once('entityreference-dragdrop', function () {
        var ec = $(this).data('ec');
        $(this).sortable({
          connectWith: 'ul.entityreference-dragdrop[data-ec=' + ec + ']'
        });
      });

      $select.once('entityreference-dragdrop', function() {
        var ec = $(this).data('ec');
        $(this).sortable({
          connectWith: "ul.entityreference-dragdrop[data-ec=" + ec + ']',
          update: Drupal.entityreference_dragdrop.update
        });
      });

      $('.entityreference-dragdrop-filter').once('entityreference-dragdrop-filter', function(){
        $(this).bind('keyup paste', function(){
          var $this = $(this);
          var val = $this.val().toLowerCase();
          if (val != '') {
            $this.parents('.entityreference-dragdrop-container').find('li').each(function(i, elem){
              var $elem = $(elem);
              if ($elem.data('label').toLowerCase().indexOf(val) >= 0) {
                $elem.show();
              }
              else {
                $elem.hide();
              }
            });
          }
          else {
            $this.parents('.entityreference-dragdrop-container').find('li').show();
          }
        });
      });
    }
  };
})(jQuery);
