
* domain_views
    - description: in views we cannot show content that belongs to a specific domain + conten sent to all affiliates. There is an issue in domain_views - it joins with domain_access and adds condition “realm = ‘domain_id’” preventing where condition on (realm=‘domain_site’ AND gid = ‘0’)
    - issue: https://www.drupal.org/node/1276694#comment-7173746
    - file: https://www.drupal.org/files/domains_views_current_domain-1276694-19.patch

* search_api
    - description: search_api_node_access_records_alter does not check for NULL item_ids
    - issue: https://www.drupal.org/node/2742053
    - file: https://www.drupal.org/files/issues/edit-2738911-1.patch
