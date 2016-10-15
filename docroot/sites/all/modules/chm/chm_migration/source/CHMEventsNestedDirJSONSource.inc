<?php

class CHMEventsNestedDirJSONSource extends CHMNestedDirJSONSource {

  public function fields() {
    return array(
      'domain_source' => 'Domain where this record belongs to (domain_access)',
      'domains' => 'Array of domain IDs to assign the record to (domain_access)',
      'domain_path' => 'Local domain URL alias (domain_access)',

      // single-valued string - Primary key within a single portal
      'url' => 'URL alias',
      // single-valued string
      'event_url' => 'External Internet link to event page or source',
      // single-valued string
      'event_type' => 'Type of event, seen values: other, meeting',
      // single-valued boolean
      'topitem' => 'Show at the top of lists',
      // single-valued string
      'contributor' => 'Username who created the item',
      // single-valued string
      'id' => 'Item URL alias',
      // single-valued string
      'location_url' => 'Event venue link for location information',
      // single-valued boolean
      'discussion' => 'Open for comments',
      // Single-valued array with [latitude, longitude] double values
      'geo_location' => 'Array of latitude, longitude values',
      // single-valued string
      'approved_by' => 'User that approved the item',
      // !!!! Single-value string OR Array of strings keyed by language, each value is single ['en' => 'value1', 'fr' => 'value2']
      'location' => 'Venue description (ex. University of Sibiu, Floor 1, Room 26)',
      // @todo single-valued integer?
      'version' => 'Probably revision. Seems always NULL',
      // single-valued string
      'folder' => 'Path on disk relative to export directory',
      // single-valued string
      'contact_phone' => 'Phone number',
      // single-valued date string
      'start_date' => 'Event start date',
      // single-valued date string
      'end_date' => 'Event end date',
      // single-valued string
      'agenda_url' => 'URL to the event agenda',
      // single-valued string
      'host' => 'Name of the host entity (ex. University of Sibiu)',
      // single-valued email address
      'contact_email' => 'Email of the contact point',
      // single-valued string
      'contact_fax' => 'Fax number of the contact point',
      // single-valued string
      'contact_person' => 'Name of the contact point',
      // single-valued integer
      'sortorder' => 'Order to appear in listing',
      // @todo single-valued integer?
      'approved' => 'Published field',
      // single-valued boolean
      'checkout' => 'Lock for edit (feature of Naaya to prevent others from editing)',
      // single-valued string
      'checkout_user' => 'User who locked it for edit',
      // Multilingual structure. Array keyed by language with array of a single string
      // having inside a comma-separated list of tags, and crappy float apendix.
      // Example:
      // "keywords": {
      //   "en": ["green spaces, protected areas, project", 1296072533.37013],
      //   "ro": ["spa\u0163ii verzi, arii protejate, proiecte", 1296073061.267298]
      // }
      'keywords' => 'Tags (multilingual)',
      'keywords_languages' => 'Tags available languages',
      // Multilingual structure (see keywords above).
      'details' => 'Detailed description (multilingual)',
      'details_languages' => 'Detailed description available languages',
      // Multilingual structure (see keywords above).
      'description' => 'Shorter description of the event (multilingual)',
      'description_languages' => 'Shorter description available languages',
      // Multilingual structure (see keywords above).
      'coverage' => 'Geographical area coverage (ex. România) (multilingual)',
      'coverage_languages' => 'Geographical area coverage available languages',
      // Multilingual structure (see keywords above).
      'title_en' => 'Event name in English (mandatory)',
      'title' => 'Event name',
      'title_languages' => 'Event name available languages',
      // single-valued boolean
      'submitted' => 'Unknown',
      // single-valued date string
      'releasedate' => 'Published date',
      // single-valued date string
      'last_modification' => 'Updated date',
      // Single-valued string OR multilingual structure (see keywords above).
      'location_address' => 'Venue address',
      'location_address_languages' => 'Venue address available languages',
    );
  }

  public function processRawRecord($source) {
    $ret = (object)array('title_en' => NULL);
    foreach ($this->fields() as $field_name => $description) {
      switch ($field_name) {
        case 'geo_location':
          //
          break;

        case 'location':
          //
          break;

        // Multilingual fields in _local_properties
        case 'description':
        case 'title':
        case 'details':
          $this->processLocalPropertiesField($field_name, $ret, $source);
          break;

        // @todo: case 'keywords' needs special handling for taxonomy terms.
        case 'coverage':
          $this->processRootMultilingualField($field_name, $ret, $source);
          break;

        case 'location_address':
          $this->processLocationAddressField($ret, $source);
          break;

        // @todo Date fields
//        case 'start_date':
//        case 'end_date':
//        case 'releasedate':
//        case 'last_modification':
          //
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

  protected function processLocationAddressField($row, array $source) {
    $field_name = 'location_address';
    if (!empty($source[$field_name])) {
      if (is_string($source[$field_name])) {
        $row->{$field_name} = array($source[$field_name]);
        $row->{$field_name . '_languages'} = array('en');
      }
      else {
        list ($languages, $values) = $this->processLocalPropertiesField('_local_properties', $row, $source[$field_name]);
        if (!empty($languages) && !empty($values)) {
          $row->{$field_name} = $values;
          $row->{$field_name . '_languages'} = $languages;
        }
      }
    }
  }
}
