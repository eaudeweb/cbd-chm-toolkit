<?php

class CHMNewsNestedDirJSONSource extends CHMNestedDirJSONSource {

  public function fields() {
    return array(
      /* Computed fields (not found in source dataset) */
      'domain_source' => 'Domain where this record belongs to (domain_access)',
      'domains' => 'Array of domain IDs to assign the record to (domain_access)',
      'domain_path' => 'Local domain URL alias (domain_access)',
      'country' => 'Domain/Portal associated country',
      // single-valued boolean
      'topitem' => 'Show at the top of lists',
      // @todo single-valued integer?
      'approved' => 'Published field',
      // single-valued string
      'contributor' => 'Username who created the item',
      // String
      'geo_type' => 'Unknown',
      // single-valued string
      'id' => 'Item URL alias',
      // single-valued integer
      'sortorder' => 'Order to appear in listing',
      // single-valued string - Primary key within a single portal
      'url' => 'URL alias',
      // single-valued boolean
      'checkout' => 'Lock for edit (feature of Naaya to prevent others from editing)',
      // single-valued string
      'checkout_user' => 'User who locked it for edit',
      // single-valued boolean
      'discussion' => 'Open for comments',
      // Multilingual structure (see keywords above).
      'description' => 'Shorter description of the news (multilingual)',
      'description_languages' => 'Shorter description available languages',
      // Multilingual structure (see keywords above).
      'title_en' => 'Item name in English (mandatory)',
      'title' => 'Item name',
      'title_languages' => 'Item name available languages',
      // Multilingual structure (see keywords above).
      'details' => 'Detailed description (multilingual)',
      'details_languages' => 'Detailed description available languages',
      // Multilingual structure (see keywords above).
      'coverage' => 'Geographical area coverage (ex. România) (multilingual)',
      'coverage_languages' => 'Geographical area coverage available languages',
      // Multilingual structure. Array keyed by language with array of a single string
      // having inside a comma-separated list of tags, and crappy float apendix.
      // Example:
      // "keywords": {
      //   "en": ["green spaces, protected areas, project", 1296072533.37013],
      //   "ro": ["spa\u0163ii verzi, arii protejate, proiecte", 1296073061.267298]
      // }
      'keywords' => 'Tags (multilingual)',
      'keywords_languages' => 'Tags available languages',
      // single-valued boolean
      'submitted' => 'Unknown',
      // single-valued date string
      'releasedate' => 'Published date',
      // single-valued date string
      'last_modification' => 'Updated date',
      // single-valued string
      'folder' => 'Path on disk relative to export directory',
      // @todo single-valued integer (always null)?
      'version' => 'Probably revision. Seems always NULL',
      // single-valued string
      'approved_by' => 'User that approved the item',
      // Single-valued array with [latitude, longitude] double values
      'geo_location' => 'Array of latitude, longitude values',

      // String
      'resourceurl' => 'News source',
      // ??
      'source' => 'Source entity of the news item',
    );
  }

  public function processRawRecord($source) {
    $ret = (object)array('title_en' => NULL);
    foreach ($this->fields() as $field_name => $description) {
      switch ($field_name) {
        case 'geo_location':
          //
          break;

        // Multilingual fields in _local_properties
        case 'description':
        case 'title':
        case 'details':
          $this->processLocalPropertiesField($field_name, $ret, $source);
          break;

        // @todo: case 'keywords' needs special handling for taxonomy terms.
        case 'keywords':
          $ret->keywords = array();
          if (!empty($source['_local_properties']['keywords'])) {
            foreach ($source['_local_properties']['keywords'] as $language => $keyword_str) {
              $keyword_str = array_shift($keyword_str);
              $keyword_arr = explode(',', $keyword_str);
              foreach($keyword_arr as $term) {
                if (!empty(trim($term))) {
                  $kw_ob = new stdClass();
                  $kw_ob->language = $language;
                  $kw_ob->term = trim($term);
                  $ret->keywords[] = $kw_ob;
                }
              }
            }
          }
          break;

        case 'coverage':
          $this->processRootMultilingualField($field_name, $ret, $source);
          break;

        // Simple fields
        default:
          if (!empty($source[$field_name])) {
            if (is_string($source[$field_name])) {
              $ret->{$field_name} = $source[$field_name];
            }
            else if (is_float($source[$field_name])) {
              $ret->{$field_name} = floatval($source[$field_name]);
            }
            else if (is_bool($source[$field_name])) {
              $ret->{$field_name} = boolval($source[$field_name]);
            }
            else if (is_int($source[$field_name])) {
              $ret->{$field_name} = intval($source[$field_name]);
            }
            else {
              // Complain about skipped complex fields not handled above.
              $this->warning("    > Skipping '{$field_name}'. Unhandled type: " . gettype($source[$field_name]));
            }
          }
      }
      $ret->url = $source['url'];
    }
    // Copy first value from the title
    $ret->title_en = $ret->title[0];
    // @todo: Consistency check for missing fields
    // (fields found in $source, but not declared in fields()"
    return $ret;
  }
}
