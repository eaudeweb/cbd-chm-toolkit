function arkiveEmbedCallback(data) {
    var iframeCreation = '<iframe id="frame" name="widget" src ="#" width="100%" height="1" marginheight="0" marginwidth="0" frameborder="no"></iframe>';
    var iframe = window.location.protocol + "//" + (data.results[0].url);
    if (data.error != 'null') {
        document.getElementById("arkiveIframe").innerHTML = iframeCreation;
        var iframeAttr = parent.document.getElementById("frame");
        iframeAttr.height = 350;
        iframeAttr.width =  360;
        iframeAttr.src = iframe;
    }
}
(function($){
    Drupal.behaviors.species_arkive = {
        attach: function (context, settings) {
            $('#arkiveIframe').once('species_arkive', function() {
                // var arkiveApiKey = 'GeD0TksVjMOk8vxTX5gkI6dFRNM1H0yFRvbciFtivm81',
                //     arkiveApiSpeciesName = 'canis%20lupus',
                var arkiveApiKey = Drupal.settings.chm_structure.species_arkive_key,
                    arkiveApiSpeciesName = Drupal.settings.chm_structure.species_arkive_name, // note spaces replaced by %20

                    arkiveApiSpeciesId = false,
                // optional, but recommended
                    arkiveApiWidth = 340,
                    arkiveApiHeight = 350,
                    arkiveApiImages = false, // whether to include thumbnails
                    arkiveApiText = false;

                    var s = document.createElement('script');
                    s.type = 'text/javascript';
                    s.async = true;
                    s.src = 'https://api.arkive.org/v2/embedScript/species/scientificName/' + arkiveApiSpeciesName
                        + '?key=' + arkiveApiKey + (arkiveApiSpeciesId ? '&id=' + arkiveApiSpeciesId : '') + '&mtype=all&w='
                        + arkiveApiWidth + '&h=' + arkiveApiHeight + '&tn=' + (arkiveApiImages ? 1 : 0) + '&text='
                        + (arkiveApiText ? 1 : 0) + '&callback=arkiveEmbedCallback';
                    var x = document.getElementsByTagName('script')[0];
                    x.parentNode.insertBefore(s, x);
            });
        }
    };
})(jQuery);
