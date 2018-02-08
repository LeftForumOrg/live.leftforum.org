(function ($) {
  Drupal.behaviors.drupalexp_base = {
      attach: function (context, settings) {
        var lightbox2 = settings.lightbox2 || null;
        if (lightbox2 !== null) {

        }
        $("a[href*=#]").click(function (e) {
          e.preventDefault();
          if($(this).is('[data-slide]')) return true;
          var url = $(this).attr('href');
          var hash = url.substring(url.indexOf("#") + 1);
          if(hash == '') return true;
          var element = $('[id=' + hash + ']');
          if (element.length > 0) {
            e.preventDefault();
            $('html, body').animate({
              scrollTop: element.offset().top
            }, 800);
          }
        });
      }
    }
    /*Set detect device*/
  var setDevice = function () {
    $('body').removeClass('dexp-xs dexp-sm dexp-md dexp-lg');
    var window_width = $(window).width();
    if (window_width < 768) {
      $('body').addClass('dexp-xs');
    } else if (window_width < 993) {
      $('body').addClass('dexp-sm');
    } else if (window_width < 1200) {
      $('body').addClass('dexp-md');
    } else {
      $('body').addClass('dexp-lg');
    }
  };
  $(document).ready(function () {
    setDevice();
  });
  $(window).bind('resize', function () {
    setDevice();
  });
})(jQuery);
