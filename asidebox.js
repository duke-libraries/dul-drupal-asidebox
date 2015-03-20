/**
 * @file
 * Utility functions to display settings summaries on vertical tabs.
 */

(function ($) {

Drupal.behaviors.asideboxFieldsetSummaries = {
  attach: function (context) {

		var asideboxStatusSelected = $('#asidebox-status option:selected').val();
		$('#edit-html-content-value').closest('.text-format-wrapper').toggle(asideboxStatusSelected == 'html');
		$('#asidebox-status').change(function() {
			var asideboxStatusSelected = $(this).val();
			$('#edit-html-content-value').closest('.text-format-wrapper').toggle(asideboxStatusSelected == 'html');
		});

		$('fieldset#edit-asidebox', context).drupalSetSummary(function(context) {
      var vals = [];
			vals.push(Drupal.checkPlain( $('#asidebox-status option:selected').text() ));

      return vals.join(', ');
    });
  }
};

})(jQuery);
