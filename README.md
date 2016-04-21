# Drupal 8 CHM toolkit for CBD


Technical information

![Testing status](https://travis-ci.org/eaudeweb/cbd-chm-toolkit.svg "Travis integration") [![Code Climate](https://codeclimate.com/github/eaudeweb/cbd-chm-toolkit/badges/gpa.svg)](https://codeclimate.com/github/eaudeweb/cbd-chm-toolkit) [![Issue Count](https://codeclimate.com/github/eaudeweb/cbd-chm-toolkit/badges/issue_count.svg)](https://codeclimate.com/github/eaudeweb/cbd-chm-toolkit)



# Developer notes

- Create your own aliases by adding a file `drush/aliases/aliases.local.php`

- Use the `chm.ptk` injected service to access global functionality. Also add new functionality to this service. To access this service:

  ```
  $chm = \Drupal::service('chm.ptk');
  $example = $chm->getExampleConfiguration();
  ```

