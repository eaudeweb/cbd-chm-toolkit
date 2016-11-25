<?php
/**
 * @file
 * chm_search.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function chm_search_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::domains';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'domains';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'domains',
  );
  $export['search_api@default_multilingual_node_index::domains'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_aichi_targets';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_aichi_targets';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_aichi_targets',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'aichi_biodiversity_targets',
  );
  $export['search_api@default_multilingual_node_index::field_aichi_targets'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_countries';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_countries';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_countries',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'countries',
  );
  $export['search_api@default_multilingual_node_index::field_countries'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_dates:value2';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_dates:value2';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'date_range',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'date_granularity' => 'MINUTE',
    'pretty_paths_alias' => 'field_date',
  );
  $export['search_api@default_multilingual_node_index::field_dates:value2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_document_type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_document_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'document',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_document_type',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'document_type',
  );
  $export['search_api@default_multilingual_node_index::field_document_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_event_status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_event_status';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'event',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_event_status',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'event_status',
  );
  $export['search_api@default_multilingual_node_index::field_event_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_keywords';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_keywords';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_keywords',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'keywords',
  );
  $export['search_api@default_multilingual_node_index::field_keywords'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_organization_type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_organization_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'organization',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_organization_type',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'organization_type',
  );
  $export['search_api@default_multilingual_node_index::field_organization_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_pa_designation_type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_pa_designation_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'protected_area',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_pa_designation_type',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'pa_designation_type',
  );
  $export['search_api@default_multilingual_node_index::field_pa_designation_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_pa_iucn_category';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_pa_iucn_category';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'protected-area',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_pa_iucn_category',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'pa_iucn_category',
  );
  $export['search_api@default_multilingual_node_index::field_pa_iucn_category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_pa_status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_pa_status';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'protected_area',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_pa_status',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'pa_status',
  );
  $export['search_api@default_multilingual_node_index::field_pa_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_project_status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_project_status';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'project',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_project_status',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'project_status',
  );
  $export['search_api@default_multilingual_node_index::field_project_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_redlist_status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_redlist_status';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_redlist_status',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'species_redlist_status',
  );
  $export['search_api@default_multilingual_node_index::field_redlist_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_species_class';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_species_class';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'species',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_species_class',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'species_class',
  );
  $export['search_api@default_multilingual_node_index::field_species_class'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_species_family';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_species_family';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'species',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_species_family',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'species_family',
  );
  $export['search_api@default_multilingual_node_index::field_species_family'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_species_phylum';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_species_phylum';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'status' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_status' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'species',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_species_phylum',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'species_phylum',
  );
  $export['search_api@default_multilingual_node_index::field_species_phylum'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::field_subjects';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'field_subjects';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'facets' => array(),
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_subjects',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'subject',
  );
  $export['search_api@default_multilingual_node_index::field_subjects'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'status';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
      ),
      'bundle' => 'selected',
      'bundle_selected' => array(
        'fact' => 0,
        'book' => 0,
        'cbd_nfp' => 0,
        'cbd_national_target' => 0,
        'chm_site' => 0,
        'document' => 0,
        'ecosystem' => 0,
        'event' => 0,
        'faq' => 0,
        'gallery' => 0,
        'link' => 0,
        'news' => 0,
        'organization' => 0,
        'page' => 0,
        'person' => 0,
        'project' => 0,
        'protected_area' => 0,
        'species' => 0,
        'video' => 0,
        'webform' => 0,
      ),
      'facets' => array(
        'type' => 'type',
        'field_species_class' => 0,
        'field_species_family' => 0,
        'field_species_phylum' => 0,
        'field_document_type' => 0,
        'field_aichi_targets' => 0,
        'field_keywords' => 0,
        'field_subjects' => 0,
        'field_event_status' => 0,
        'field_project_status' => 0,
        'field_pa_designation_type' => 0,
        'field_dates:value2' => 0,
        'field_organization_type' => 0,
        'field_pa_iucn_category' => 0,
        'field_pa_status' => 0,
        'field_ecosystem_types' => 0,
        'field_countries' => 0,
        'field_nfp_type' => 0,
        'domains' => 0,
        'field_nfp_designation' => 0,
        'field_department' => 0,
      ),
      'reverse_dependency' => 0,
      'force_deactivation' => 1,
      'regex' => 0,
      'facet_items_field_species_class' => '',
      'facet_items_field_species_family' => '',
      'facet_items_field_species_phylum' => '',
      'facet_items_field_document_type' => '',
      'facet_items_field_aichi_targets' => '',
      'facet_items_field_keywords' => '',
      'facet_items_field_subjects' => '',
      'facet_items_field_event_status' => '',
      'facet_items_field_project_status' => '',
      'facet_items_field_pa_designation_type' => '',
      'facet_items_field_dates:value2' => '',
      'facet_items_field_organization_type' => '',
      'facet_items_field_pa_iucn_category' => '',
      'facet_items_field_pa_status' => '',
      'facet_items_field_ecosystem_types' => '',
      'facet_items_field_countries' => '',
      'facet_items_field_nfp_type' => '',
      'facet_items_domains' => '',
      'facet_items_field_nfp_designation' => '',
      'facet_items_field_department' => '',
      'facet_items_type' => 'protected_area',
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'status',
  );
  $export['search_api@default_multilingual_node_index::status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index::type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = '';
  $facet->facet = 'type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'type',
  );
  $export['search_api@default_multilingual_node_index::type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:author';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'author';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:author'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:body:summary';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'body:summary';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:body:summary'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:body:value';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'body:value';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:body:value'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:changed';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'changed';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:changed'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:created';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'created';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:created'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:domains';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'domains';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:domains'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_address';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_address';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_address'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_aichi_targets';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_aichi_targets';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_aichi_targets'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_alternative_emails';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_alternative_emails';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_alternative_emails'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_city';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_city';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_city'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_countries';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_countries';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_countries'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_country';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_country';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_country'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_dates:value';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_dates:value';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_dates:value'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_dates:value2';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_dates:value2';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'custom_chm_search_ui_slider',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_dates:value2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_department';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_department';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_department'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_document_type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_document_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_document_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_ecosystem_types';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_ecosystem_types';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_ecosystem_types'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_email';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_email';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_email'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_event_status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_event_status';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_event_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_event_type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_event_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_event_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_fax_numbers';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_fax_numbers';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_fax_numbers'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_first_name';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_first_name';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_first_name'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_keywords';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_keywords';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_keywords'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_last_name';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_last_name';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_last_name'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_nfp_designation';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_nfp_designation';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_nfp_designation'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_nfp_type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_nfp_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:field_nfp_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_organization_type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_organization_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_organization_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_pa_designation_type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_pa_designation_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_pa_designation_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_pa_iucn_category';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_pa_iucn_category';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_pa_iucn_category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_pa_status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_pa_status';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_pa_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_project_status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_project_status';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_project_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_redlist_status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_redlist_status';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_redlist_status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_species_class';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_species_class';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_species_class'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_species_family';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_species_family';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_species_family'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_species_phylum';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_species_phylum';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_species_phylum'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:field_subjects';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'field_subjects';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:field_subjects'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:promote';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'promote';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:promote'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:search_api_access_node';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'search_api_access_node';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:search_api_access_node'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:search_api_language';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'search_api_language';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:search_api_language'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:status';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'status';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'natural' => '0',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@default_multilingual_node_index:block:status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:sticky';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'sticky';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:sticky'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:title';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'title';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:title'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:title_field';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'title_field';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:title_field'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:type';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'chm_search',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
    'name' => '',
    'prefix' => '',
    'suffix' => '',
    'auto-submit-delay' => '1500',
    'slider-step' => '1',
    'round-precision' => '0',
    'range_simple' => 10,
    'range_advanced' => '',
  );
  $export['search_api@default_multilingual_node_index:block:type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@default_multilingual_node_index:block:url';
  $facet->searcher = 'search_api@default_multilingual_node_index';
  $facet->realm = 'block';
  $facet->facet = 'url';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@default_multilingual_node_index:block:url'] = $facet;

  return $export;
}
