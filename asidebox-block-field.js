(function($) {
	/**
	 * 
	 */
	Drupal.behaviors.asidebox_block_field = {
		attach: function (context, settings) {
			if (Drupal.jsAC) {
				Drupal.jsAC.prototype.select = function(block) {
					debugger;
					var $blockModuleField = $('#asideboxBlockModule'),
							$blockDeltaField = $('#asideboxBlockDelta');
					
				}
			}
		}
	}
})(jQuery);	
