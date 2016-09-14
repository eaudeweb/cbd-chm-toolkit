// jQuery(document).ready(function ($) {
//    $('.dropdown-toggle', '#navbar').removeAttr('data-toggle');
// });
(function($){
	$(document).ready(function() {
		if(document.getElementsByTagName("HTML")[0].dir == "rtl") {
			$('#slick-views-home-page-image-slider-1-slider').slick('slickSetOption', 'rtl', true, true);
		}
		$('ul.dropdown-menu [data-toggle=dropdown]').on('click', function(event) {
			event.preventDefault();
			event.stopPropagation();
			$(this).parent().siblings().removeClass('open');
			$(this).parent().toggleClass('open');
		});
	});
})(jQuery);
