<?php


/**
 * Class CHMNestedDirJSONSource recursively scans and loads JSON files from
 * subdirectories within a given base path.
 */
abstract class CHMNestedDirJSONSource extends MigrateSource {


  use CHMLoggingTrait;

  protected $allowed_tags = array(
    'b', 'strong', 'u', 'i', 'em',
    'a', 'img',
    'table', 'caption', 'tr', 'td', 'thead', 'tbody',

    'ul', 'li', 'ol', 'dd', 'dt', 'dl',
    'h2', 'h3', 'h4', 'h5', 'h6',
    'p', 'br', 'center', 'span', 'div', 'article', 'aside', 'blockquote',
    'code', 'hr', 'section', 'pre', 'q', 'small', 'sub',
  );

  /**
   * @var string Base directory where to recursively scan for records.
   */
  protected $source_dir;
  protected $raw_data = array();
  protected $config = NULL;

  abstract function processRawRecord($source);

  public function __construct(array $options) {
    parent::__construct($options);
    $this->config = $options;
    $this->source_dir = $options['source_dir'];
  }

  public function scan() {
    $this->raw_data = array();
    $this->_recursive_scan($this->raw_data, $this->source_dir);
    $this->debug(sprintf('Found %d items in the source tree', count($this->raw_data)));
    reset($this->raw_data);
  }

  public function __toString() {
    $machine_name = $this->config['machine_name'] . '_source';
    return $machine_name;
  }

  private function _recursive_scan(&$ret, $dir) {
    $subdirs = array_diff(scandir($dir), array('.', '..'));
    foreach ($subdirs as $path_item) {
      $absolute_path = $dir . '/' . $path_item;
      if (is_dir($absolute_path)) {
        $this->_recursive_scan($ret, $absolute_path);
      }
      else {
        $this->debug("Reading: $absolute_path");
        if ($json = json_decode(file_get_contents($absolute_path), TRUE)) {
          if (!empty($json['url'])) {
            $id = $json['url'];
            // Save some memory by removing unused structures
            unset($json['_NyProperties__dynamic_properties']);
            unset($json['_NyComments__comments_collection']);
            unset($json['__ac_local_roles__']);
            unset($json['_local_properties_metadata']);
            $ret[$id] = $json;
          }
          else {
            $this->debug("  > Ignoring entry without 'url': $absolute_path");
          }
        }
        else {
          $this->warning("  > Cannot decode JSON file: $absolute_path");
        }
      }
    }
  }


  public function computeCount() {
    if (empty($this->raw_data)) {
      $this->scan();
    }
    return count($this->raw_data);
  }


  public function performRewind() {
    if (empty($this->raw_data)) {
      $this->scan();
    }
    reset($this->raw_data);
  }


  public function getNextRow() {
    $ret = NULL;
    if (empty($this->raw_data)) {
      $this->scan();
      $ob = reset($this->raw_data);
    }
    else {
      $ob = next($this->raw_data);
    }
    if ($ob) {
      $ret = $this->processRawRecord($ob);
    }
    return $ret;
  }


  protected function processLocalPropertiesField($field_name, $row, array $source) {
    if (!empty($source['_local_properties'][$field_name])) {
      list ($languages, $values) = $this->processMultilingualField($field_name, $row, $source['_local_properties'][$field_name]);
      if (!empty($languages) && !empty($values)) {
        $row->{$field_name} = $values;
        $row->{$field_name . '_languages'} = $languages;
      }
    }
  }

  protected function processRootMultilingualField($field_name, $row, array $source) {
    if (!empty($source[$field_name])) {
      list ($languages, $values) = $this->processMultilingualField($field_name, $row, $source[$field_name]);
      if (!empty($languages) && !empty($values)) {
        $row->{$field_name} = $values;
        $row->{$field_name . '_languages'} = $languages;
      }
    }
  }

  protected function processMultilingualField($field_name, $row, $values) {
    $ret_languages = array();
    $ret_values = array();
    foreach ($values as $language => $value) {
      $v = array_shift($value);
      if (!empty($language) && !empty($v)) {
        $ret_languages[] = $language;
        $ret_values[] = strip_tags($v, $this->allowed_tags);
      }
    }
    return array($ret_languages, $ret_values);
  }

}
