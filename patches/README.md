# How to read this directory

This directory contains the active patched applied to contrib modules & Drupal Core (yeah, we need to do that from time to time). In order to keep things tidy, we need to carefully record each of these patches so we can avoid a cataclysm in the future (updates).

Each directory here is the name of the module. In each directory add the patches applied to the modules and core. Drupal core is in 'drupal' directory.


## Patches


* bootstrap
  - Desc : Fixed problem with profile installation tests
  - Issue: https://www.drupal.org/node/2697075
  - File : bootstrap/bootstrap-StorageException-2697075-3-D8.patch
