# Drupal 7 CHM toolkit for CBD


# Developer notes

- Create your own aliases by adding a file `drush/aliases/aliases.local.php`



- Configure drushrc.php file

   vim ~/.drush/drushrc.php
   Add the following snippet

  ```
  <?php
        $repo_dir = drush_get_option('root') ? drush_get_option('root') : getcwd();
        $success = drush_shell_exec('cd %s && git rev-parse --show-toplevel 2> ' . drush_bit_bucket(), $repo_dir);
        if ($success) {
            $output = drush_shell_exec_output();
            $repo = $output[0];
            $options['config'] = $repo . '/drush/drushrc.php';
            $options['include'] = $repo . '/drush/commands';
            $options['alias-path'] = $repo . '/drush/aliases';
        }
  ```
