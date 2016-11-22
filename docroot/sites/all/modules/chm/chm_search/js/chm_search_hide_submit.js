(function($){
  /**
   * Hide submit button in select widget facet.
   **/
  Drupal.behaviors.ExampleHideSubmit = {
  attach: function(context) {
    $('.chm-search-select-facet .ctools-auto-submit-click:not(.chm_search-hide-submit-processed)', context)
    .addClass('chm_search-hide-submit-processed').hide();
  }}

})(jQuery);
