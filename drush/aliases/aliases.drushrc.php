<?php
$aliases['test'] = array(
  'uri' => 'test7.chm-cbd.net',
  'remote-host' => 'www.chm-cbd.net',
  'remote-user' => 'please-fill-in-local-aliases',
  'root' => 'please-fill-in-local-aliases',
  'path-aliases' => array(
    '%files' => 'sites/all/files',
  ),
);
$aliases['prod'] = array(
  'uri' => 'www.chm-cbd.net',
  'remote-host' => 'www.chm-cbd.net',
  'remote-user' => 'please-fill-in-local-aliases',
  'root' => 'please-fill-in-local-aliases',
  'path-aliases' => array(
    '%files' => 'sites/all/files',
  ),
);

// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
