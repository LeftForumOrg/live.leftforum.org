(function($){
	Drupal.behaviors.drupalexp_presets = {
		attach: function(context,settings) {			
			var presets = settings.drupalexp_presets;
			var current_preset = 0;
			var farb = $.farbtastic('#placeholder');
			$('#edit-drupalexp-presets-list').change(function(){
				current_preset = $(this).val();
        $('#edit-drupalexp-preset-key').val(presets[current_preset].key);
        $('#edit-drupalexp-base-color').val(presets[current_preset].base_color);
				$('#edit-drupalexp-link-color').val(presets[current_preset].link_color);
				$('#edit-drupalexp-link-hover-color').val(presets[current_preset].link_hover_color);
				$('#edit-drupalexp-text-color').val(presets[current_preset].text_color);
				$('#edit-drupalexp-heading-color').val(presets[current_preset].heading_color);
				$('.color').each(function(){
					farb.linkTo(this);
				});
			}).change().change(function(){
				$('.preset-option').trigger('change');
			});
			$('.color').focus(function(){
				$('#edit-preset-settings .form-item').removeClass('focus');
				$(this).parents('.form-item').addClass('focus');
				farb.linkTo(this);
			});
			$('.preset-option').change(function(){
				presets[current_preset][$(this).data('property')] = $(this).val();
			});
			$('form#system-theme-settings').submit(function () {
				$('input[name=drupalexp_presets]').val(base64Encode(JSON.stringify(presets)));
			});
		}
	};
})(jQuery)