<?php

/**
 * Class ChmGefSettingsForm configures the GEF data migration integration.
 */
class ChmGefSettingsForm {

  static function form() {
    if ($filename = variable_get(GEF_CSV_VAR)) {
      $q = new EntityFieldQuery();
      $q->entityCondition('entity_type', 'file');
      $q->propertyCondition('uri', $filename);
      $result = $q->execute();
      if (count($result)) {
        $file = file_load(array_pop($result['file'])->fid);
        $url = file_create_url($file->uri);
        $form['current'] = array(
          '#type' => 'item',
          '#markup' => '<div class="">' . t('There is already a file uploaded on <strong>!timestamp</strong>. <strong>!link.</strong>',
            array(
              '!link' => l(t('Click here to download'), $url),
              '!timestamp' => format_date($file->timestamp, 'long'),
            )
          ) . '</div>'
        );
      }
    }
    $form['file'] = [
      '#type' => 'file',
      '#title' => t('Upload GEF projects CSV file'),
      '#description' => t('Upload a file, allowed extensions: csv. Download, the GEF projects dataset from <a target="_blank" href="http://www.thegef.org/projects">here</a> then upload the CSV file.'),
    ];
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['upload'] = array(
      '#type' => 'submit',
      '#value' => t('Upload & import'),
    );
    $form['#validate'][] = array('ChmGefSettingsForm', 'validate');
    $form['#submit'][] = array('ChmGefSettingsForm', 'submit');
    return $form;
  }

  static function validate($form, &$form_state) {
    $file = file_save_upload('file', array(
      'file_validate_extensions' => array('csv'),
    ));
    if ($file) {
      $upload_dir = GEF_CSV_UPLOAD_DIR;
      // Move the file into the Drupal file system
      file_prepare_directory($upload_dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      if ($file = file_move($file, $upload_dir . 'projects.csv', FILE_EXISTS_REPLACE)) {
        // Save file status.
        $file->status = FILE_STATUS_PERMANENT;
        dpm($file);
        file_save($file);
        dpm($file);
        variable_set(GEF_CSV_VAR, $file->uri);
      }
      else {
        form_set_error('file', t('Failed to write the uploaded file to destination folder.'));
      }
    }
    else {
      form_set_error('file', t('No file was uploaded.'));
    }
  }

  static function submit($form, &$form_state) {
    // Set a response to the user.
    drupal_set_message(t('The file has been successfully uploaded. Due to the large amount of records, to conserve server resources the data will be processed in the background'));
  }
}
