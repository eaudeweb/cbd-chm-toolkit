Requirements:
- set language negotiation to "Path prefix only". We are overriding $language in
  bootstrap hence overwriting any changes that might of been user's preferred
  language specific. Also user's preferred language might not exist all domains.
  You can leave the setting to "Path prefix with language fallback" but the
  language fallback will be overwritten.

Recommended:
- Use the module Drush Language Commands to add/remove languages:
  https://www.drupal.org/project/drush_language

Optional:
- make sure all languages have a prefix (by default English does not). This
  gives unique URLS for all languages.

Configuration:
- Add/Remove languages:
  - via the UI:
    /admin/config/regional/language
  - or using the module drush_language
    https://www.drupal.org/project/drush_language
- Edit the available languages for a domain:
    - via the UI:
        /admin/structure/domain/view/[domain_id]/language
    - via drush:
        domain-locale-set [domain_machine_name] '[list of language codes]' --defalt=[language_code]
        Eg.: domain-locale-set usa.example.com 'en es' --default=en

