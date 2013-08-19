(function($) {
	Drupal.behaviors.asidebox_select_field = {
		attach: function (context, settings) {
			$('#edit-asidebox-block-menu').change(function(evt) {
				var $blockModuleField = $('#asideboxblockmodule'),
						$blockDeltaField = $('#asideboxblockdelta');
				pieces = $('option:selected', this).val().split('|');
				console.log(pieces);
				$blockModuleField.attr('defaultValue', pieces[1]);
				$blockDeltaField.attr('defaultValue', pieces[2]);
				$('#asideboxblockid').attr('defaultValue', pieces[0]);
			});
		}
	}
})(jQuery);
