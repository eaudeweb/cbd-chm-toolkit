jQuery(document).ready(function ($) {
   $('.dropdown-toggle', '#navbar').removeAttr('data-toggle');
});
(function($){
	$(document).ready(function(){
	  if(document.getElementsByTagName("HTML")[0].dir == "rtl"){
	    $('#slick-views-home-page-image-slider-1-slider').slick('slickSetOption', 'rtl', true, true);;
	  }
		$('navbar-nav > li > a > .toggle-submenu').on('click', function(){

		});
		
		$('.toggle-submenu').on("click", function(e) {
  			e.preventDefault();
			var expanded = $(this).closest('.expanded');
			$(expanded).toggleClass('d-open');

			// $(document).find('.last-open').not(expanded).removeClass('last-open');
			// $(expanded).toggleClass('last-open');
			
			$(this).parent().next('ul').slideToggle('fast');
			e.stopPropagation();
		});
	});
})(jQuery);
// .dropdown-submenu a