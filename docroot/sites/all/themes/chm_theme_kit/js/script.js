// jQuery(document).ready(function ($) {
//    $('.dropdown-toggle', '#navbar').removeAttr('data-toggle');
// });
(function($) {
  "use strict";
  $.fn.getHiddenDimensions = function (includeMargin) {
    var $item = this,
    props = { position: 'absolute', visibility: 'hidden', display: 'block' },
    dim = { width: 0, height: 0, innerWidth: 0, innerHeight: 0, outerWidth: 0, outerHeight: 0 },
    $hiddenParents = $item.parents().andSelf().not(':visible'),
    includeMargin = (includeMargin == null) ? false : includeMargin;

    var oldProps = [];
    $hiddenParents.each(function () {
      var old = {};

      for (var name in props) {
        old[name] = this.style[name];
        this.style[name] = props[name];
      }

      oldProps.push(old);
    });

    dim.width = $item.width();
    dim.outerWidth = $item.outerWidth(includeMargin);
    dim.innerWidth = $item.innerWidth();
    dim.height = $item.height();
    dim.innerHeight = $item.innerHeight();
    dim.outerHeight = $item.outerHeight(includeMargin);

    $hiddenParents.each(function (i) {
      var old = oldProps[i];
      for (var name in props) {
        this.style[name] = old[name];
      }
    });

    return dim;
  }

  $(document).ready(function() {
    if(document.getElementsByTagName("HTML")[0].dir == "rtl") {
      $('#slick-views-home-page-image-slider-1-slider').slick('slickSetOption', 'rtl', true, true);
    }
    $('ul.dropdown-menu [data-toggle=dropdown]').on('click', function(event) {
      event.preventDefault();
      event.stopPropagation();
      var parent = $(this).parent();
      parent.siblings().removeClass('open');
      parent.toggleClass('open');
    });
    var t;
    $(window).resize(function() {
      clearTimeout(t);
      t=setTimeout(function() {
        var windowWidth = $( window ).innerWidth();

        if($('#navbar-search').is(':visible')) return;
        $('.dropdown', '#navbar').each(function(index, element) {
          var offset = $(element).offset().left;
          var dropdownMenus = $(element).find('.dropdown-menu');
          var dropdownSubmenus = $(element).find('.dropdown-submenu');
          var fullWidth = 0;
          dropdownMenus.each(function(index, element) {
            fullWidth += $(element).getHiddenDimensions().width;
          });
          dropdownMenus.removeClass('dropdown-menu-right');
          dropdownSubmenus.removeClass('dropdown-submenu-right');
          if (offset + fullWidth >  windowWidth) {
            dropdownMenus.addClass('dropdown-menu-right');
            dropdownSubmenus.addClass('dropdown-submenu-right');
          }
        });
      }, 200);
    });
    $(window).resize();
  });
})(jQuery);