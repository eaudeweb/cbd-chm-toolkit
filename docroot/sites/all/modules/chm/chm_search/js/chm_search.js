(function($) {
  Drupal.behaviors.chm_search = {
    attach: function(context, settings) {

      var submitTimeout = '';

      $('div.chm-search-widget').each(function() {

        var widget = $(this);
        var slider = widget.find('#edit-range-slider');
        var rangeMin = widget.find('input[name=range-min]');
        var rangeMax = widget.find('input[name=range-max]');
        var rangeFrom = widget.find('input[name=range-from]');
        var rangeTo = widget.find('input[name=range-to]');

        var widgetId = jQuery(this).parent('div').attr('id').replace('chm-search-','');
        var step = 1;
        var roundPrecision = 0;//Is not used in this file yet. Maybe in the future will needed.
        if (Drupal.settings.chm_search[widgetId] && Drupal.settings.chm_search[widgetId]['slider-step'])
          step = parseFloat(Drupal.settings.chm_search[widgetId]['slider-step']);

        if (Drupal.settings.chm_search[widgetId] && Drupal.settings.chm_search[widgetId]['round-precision']) {
          roundPrecision = parseFloat(Drupal.settings.chm_search[widgetId]['round-precision']);
        }

        var onChange = function (data) {
          saveResult(data);
          clearTimeout(submitTimeout);
        };
        var onFinish = function (data) {
          saveResult(data);
          clearTimeout(submitTimeout);
          delaySubmit(widget);
        };

        var saveResult = function (data) {
          widget.find('input[name=range-from]').val(data.from);
          widget.find('input[name=range-to]').val(data.to);
        };
        var slider = jQuery('#edit-range-slider');
        
        slider.ionRangeSlider({
            type: "double",
            prettify_enabled: false,
            step: step,
            min: parseFloat(rangeMin.val()),
            max: parseFloat(rangeMax.val()),
            from: parseFloat(rangeFrom.val()),
            to: parseFloat(rangeTo.val()),
            onLoad: function (data) {
                saveResult(data);
                writeResult();
            },
            onStart: function (data) {
                clearTimeout(submitTimeout);
            },
            onChange: onChange,
            onFinish: onFinish,
            onUpdate: function (data) {
            }
        });

        rangeFrom.attr('type', 'number').numeric({decimal : "."});

        var initialFromValue;
        rangeFrom.bind('focus', function() {
          initialFromValue = rangeFrom.val();
        });
        rangeFrom.bind('blur', function() {
          var from = rangeFrom.val();
          var to = rangeTo.val();
          if(initialFromValue === from) return;
          clearTimeout(submitTimeout);
          if (!isNaN(from) && from !== '') {
            var value = parseFloat(from);
            if (value > parseFloat(to)) {
              value = parseFloat(to);
            }
            slider.data("ionRangeSlider").update({
                from: value
            });
            delaySubmit(widget);
          }
        });

        rangeTo.attr('type', 'number').numeric({decimal : "."});

        var initialToValue;
        rangeTo.bind('focus', function() {
          initialToValue = rangeTo.val();
        });

        rangeTo.bind('blur', function() {
          var from = rangeFrom.val();
          var to = rangeTo.val();
          if(initialToValue === to) return;
          clearTimeout(submitTimeout);
          if (!isNaN(rangeTo.val()) && to !== '') {
            var value = parseFloat(to);
            if (value < parseFloat(from)) {
              value = parseFloat(from);
            }
            slider.data("ionRangeSlider").update({
                to: value
            });
            delaySubmit(widget);
          }
        });
      });

      function delaySubmit(widget) {
        var autoSubmitDelay = widget.find('input[name=delay]').val();
        if (autoSubmitDelay != undefined && autoSubmitDelay != 0) {
          submitTimeout = setTimeout(function() {
            widget.find('form').submit();
          }, autoSubmitDelay);
        }
      };
    }
  };
})(jQuery);
