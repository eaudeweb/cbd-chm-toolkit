jQuery(document).ready(function ($) {
   $('.dropdown-toggle', '#navbar').removeAttr('data-toggle');
});
(function($){
	$(document).ready(function(){
	  if(document.getElementsByTagName("HTML")[0].dir == "rtl"){
	    $('#slick-views-home-page-image-slider-1-slider').slick('slickSetOption', 'rtl', true, true);;
	  }
	});
})(jQuery);
