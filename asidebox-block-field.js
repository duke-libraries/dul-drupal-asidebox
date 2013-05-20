(function($) {
	/**
	 * 
	 */
	Drupal.behaviors.asidebox_block_field = {
		attach: function (context, settings) {
			if (Drupal.jsAC) {
				Drupal.jsAC.prototype.select = function(node) {
					var $blockModuleField = $('#asideboxBlockModule'),
							$blockDeltaField = $('#asideboxBlockDelta');
					
					pieces = $(node).data('autocompleteValue').split('|');
					$blockModuleField.attr('defaultValue', pieces[1]);
					$blockDeltaField.attr('defaultValue', pieces[2]);
					$('#asideboxBlockID').attr('defaultValue', pieces[0]);

					$(this.input).val( $(node).text() );

					// in order to prevent the jsAC.hidePopup function from erasing the value
					// just placed in the textfield, set 'selected' to FALSE
					// this = jsAC instance
					this.selected = false;
				}
			}
		}
	}
})(jQuery);	
