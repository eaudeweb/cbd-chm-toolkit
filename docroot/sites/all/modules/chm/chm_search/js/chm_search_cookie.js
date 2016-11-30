(function($) {
    Drupal.behaviors.cookie_search={
      attach: function(context, settings) {
          Drupal.cookie_search.setStatus();
      }
    }

    Drupal.cookie_search = {};

    Drupal.cookie_search.getCurrentStatus = function() {
        return Drupal.cookie_search.getCookie('cookie-search-goto');
    }

    Drupal.cookie_search.setStatus = function() {
        name = 'national';
        url = window.location.href;
        name = name.replace(/[\[\]]/g, "\\$&");
        var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
            results = regex.exec(url);
        if (!results) return null;
        if (!results[2]) return '';
        status = decodeURIComponent(results[2].replace(/\+/g, " "));
        if (status) {
            var parser1 = document.createElement('a');
            parser1.href = window.location.href;
            var parser2 = document.createElement('a');
            parser2.href = document.referrer;
            if (parser1.hostname != parser2.hostname) {
                status = document.referrer;
                var date = new Date();
                date.setDate(date.getDate() + 100);
                var cookie = "cookie-search-goto=" + status + ";expires=" + date.toUTCString() + ";path=" + Drupal.settings.basePath;
                document.cookie = cookie;
            }
        }
    }

    /**
     * Verbatim copy of Drupal.comment.getCookie().
     */
    Drupal.cookie_search.getCookie = function(name) {
        var search = name + '=';
        var returnValue = '';

        if (document.cookie.length > 0) {
            offset = document.cookie.indexOf(search);
            if (offset != -1) {
                offset += search.length;
                var end = document.cookie.indexOf(';', offset);
                if (end == -1) {
                    end = document.cookie.length;
                }
                returnValue = decodeURIComponent(document.cookie.substring(offset, end).replace(/\+/g, '%20'));
            }
        }

        return returnValue;
    };

})(jQuery);
