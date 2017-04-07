<?php
/**
 * @file
 * chm_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function chm_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function chm_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function chm_search_default_search_api_index() {
  $items = array();
  $items['default_multilingual_node_index'] = entity_import('search_api_index', '{
    "name" : "Default multilingual node index",
    "machine_name" : "default_multilingual_node_index",
    "description" : "An automatically created search index for indexing multilingual node data. Might be configured to specific needs.",
    "server" : "apache_solr_search_server",
    "item_type" : "search_api_et_node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "search_api_et" : {
        "include" : "incomplete",
        "restrict undefined" : 0,
        "fallback language" : ""
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : { "status" : 0, "weight" : "-50", "settings" : { "fields" : [] } },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_domain_alter_domain_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "domains" : [], "operator" : "OR" }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_aichi_targets:parent" : "field_aichi_targets:parent",
              "field_aichi_targets:parents_all" : "field_aichi_targets:parents_all"
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title (aggregated)",
                "type" : "fulltext",
                "fields" : [ "title_field" ],
                "description" : "A Fulltext aggregation of the following fields: Title."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        }
      },
      "processors" : {
        "search_api_domain" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "fields" : [],
            "default" : "1",
            "domains" : { "search_api_domain_active_domain" : "search_api_domain_active_domain" },
            "operator" : "OR"
          }
        },
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "title_field" : true,
              "field_address" : true,
              "field_alternative_emails" : true,
              "field_city" : true,
              "field_department" : true,
              "field_email" : true,
              "field_fax_numbers" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_nfp_designation" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_address" : true,
              "field_alternative_emails" : true,
              "field_city" : true,
              "field_department" : true,
              "field_email" : true,
              "field_fax_numbers" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_nfp_designation" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "title_field" : true,
              "field_address" : true,
              "field_alternative_emails" : true,
              "field_city" : true,
              "field_department" : true,
              "field_email" : true,
              "field_fax_numbers" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_nfp_designation" : true,
              "body:value" : true,
              "body:summary" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_address" : true,
              "field_alternative_emails" : true,
              "field_city" : true,
              "field_department" : true,
              "field_email" : true,
              "field_fax_numbers" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_nfp_designation" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_address" : true,
              "field_alternative_emails" : true,
              "field_city" : true,
              "field_department" : true,
              "field_email" : true,
              "field_fax_numbers" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_nfp_designation" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "attachments_field_files" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "domain_site" : { "type" : "integer" },
        "domains" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_address" : { "type" : "text" },
        "field_aichi_targets" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_alternative_emails" : { "type" : "list\\u003Ctext\\u003E" },
        "field_city" : { "type" : "text" },
        "field_countries" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_dates:value" : { "type" : "date" },
        "field_dates:value2" : { "type" : "date" },
        "field_department" : { "type" : "text" },
        "field_document_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_ecosystem_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_email" : { "type" : "text" },
        "field_event_status" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_fax_numbers" : { "type" : "list\\u003Ctext\\u003E" },
        "field_first_name" : { "type" : "text" },
        "field_government" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_keywords" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_last_name" : { "type" : "text" },
        "field_nfp_designation" : { "type" : "text" },
        "field_nfp_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_organization_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_pa_designation_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_pa_iucn_category" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_pa_status" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_project_status" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_redlist_status" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_species_class" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_species_family" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_species_phylum" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_subjects" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "promote" : { "type" : "boolean" },
        "search_api_aggregation_1" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "title_field" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : null,
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : { "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] } },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\nh2 = 3\\nh3 = 2\\nstrong = 2\\nb = 2\\nem = 1.5\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "promote" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "0",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function chm_search_default_search_api_server() {
  $items = array();
  $items['apache_solr_search_server'] = entity_import('search_api_server', '{
    "name" : "Apache Solr Search",
    "machine_name" : "apache_solr_search_server",
    "description" : "The Solr server used for the search functionality",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/chm-cbd-prod",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "log_query" : 0,
      "log_response" : 0
    },
    "enabled" : "1"
  }');
  return $items;
}
