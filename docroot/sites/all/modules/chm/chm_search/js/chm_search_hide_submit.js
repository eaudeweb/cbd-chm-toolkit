(function($) {
  $(document).ready(function() {
      // Select2
      var initialSelects = $('[id^=edit-select]');
      var placeholderValue = initialSelects.eq(0).data('placeholder');
      initialSelects.each(function() {
        var self = $(this);
        self.css('width', '100%').removeClass('form-control').select2({
          allowClear: true,
          placeholder: placeholderValue,
          escapeMarkup: function (text) { return text; }
        });
      });
      // $('[id^=s2id_autogen]','#chm-search-type')
      $('.select2-input').each(function () {
        $(this)[0].placeholder = placeholderValue;
      });
      $('.ctools-auto-submit-click:not(.chm_search-hide-submit-processed)').addClass('chm_search-hide-submit-processed').hide();
      $('.chm-search-select-facet.collapse').on('shown.bs.collapse', function () {
        $(this).find('.select2-input').focus();
      });
    });
})(jQuery);
// (function($){
//   /**
//    * Hide submit button in select widget facet.
//    **/
//   Drupal.behaviors.ExampleHideSubmit = {
//   attach: function(context) {
//     $('.chm-search-select-facet .ctools-auto-submit-click:not(.chm_search-hide-submit-processed)', context)
//     .addClass('chm_search-hide-submit-processed').hide();
//   }}

// })(jQuery);

// (function ($, window, document) {

//   Drupal.Select2.functionsScope.chm_search_format_selection = function (term) {

//     if (term.hover_title) {
//       return term.hover_title;
//     }

//     return term.text;
//   };

// })(jQuery, window, document);
