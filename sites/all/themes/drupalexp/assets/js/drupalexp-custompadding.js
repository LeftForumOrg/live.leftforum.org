(function($) {
    Drupal.behaviors.drupalexp_custompadding = {
        attach: function(context, settings) {
            $('.custompadding').each(function() {
                var $this = $(this), padding = $this.data('padding'), $rows = $(this).find('.row');
                if (isNaN(parseInt(padding)) || padding == 15 || padding < 0)
                    return;
                if ($rows.length === 0) {
                    $this.css({
                        marginLeft: -padding + 'px',
                        marginRight: -padding + 'px'
                    });
                    $this.find('>*[class*=col-]').css({
                        paddingLeft: padding + 'px',
                        paddingRight: padding + 'px'
                    });
                } else {
                    $rows.each(function() {
                        if ($(this).parents('.row', $this).length === 0) {
                            $(this).css({
                                marginLeft: -padding + 'px',
                                marginRight: -padding + 'px'
                            });
                            $(this).find('>*[class*=col-]').css({
                                paddingLeft: padding + 'px',
                                paddingRight: padding + 'px'
                            });
                        }
                    });
                }
            });
        }
    };
})(jQuery);
