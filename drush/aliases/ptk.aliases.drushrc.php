<?php

// Site iucnwildlifed8, environment dev
$aliases['dev'] = array(
  'root' => '/var/www/html/chm-ptk.edw.ro/docroot',
  'uri' => 'http://chm-ptk.edw.ro',
  'remote-host' => 'php-devel1.edw.ro',
  'remote-user' => 'php',
);

// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
