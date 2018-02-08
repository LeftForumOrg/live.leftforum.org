(function ($) {
	Drupal.behaviors.bootstrap_subtheme = {
		attach: function (context) {
			var subThemes = ["Path to a Radical New World", 
				"By Any Means Necessary?", 
				"Breaking the Sexist, Racist, Kleptocratic, Earth-destroying, Billionaire Class",
				"A Unified Left for Universal Liberation?",
				"Then. Now. Tomorrow."];

			$(".resisText").TickerScrambler(
			{list: subThemes,
			index: 1,
			pause: 5000}
			);
		}
	};
})(jQuery);