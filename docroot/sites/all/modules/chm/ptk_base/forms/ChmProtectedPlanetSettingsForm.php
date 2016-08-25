<?php

/**
 * Class ChmProtectedPlanetSettingsForm configures protected planet integration.
 */
class ChmProtectedPlanetSettingsForm {

  static function form() {
    if ($filename = variable_get(PROTECTED_PLANET_AREA_CSV_VAR)) {
      $q = new EntityFieldQuery();
      $q->entityCondition('entity_type', 'file');
      $q->propertyCondition('uri', $filename);
      $result = $q->execute();
      if (count($result)) {
        $file = file_load(array_pop($result['file'])->fid);
        $url = file_create_url($file->uri);
        $form['current'] = array(
          '#type' => 'item',
          '#markup' => t('There is already a file uploaded <strong>!link</strong>', array('!link' => l($file->filename, $url)))
        );
      }
    }
    $form['file'] = [
      '#type' => 'file',
      '#title' => t('Upload Protected Planet CSV file'),
      '#description' => t('Upload a file, allowed extensions: csv. Download, unzip the WDPA dataset from <a target="_blank" href="http://www.protectedplanet.net/">here</a> then upload the CSV file.'),
    ];
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['upload'] = array(
      '#type' => 'submit',
      '#value' => t('Upload & import'),
    );
    $form['#validate'][] = array('ChmProtectedPlanetSettingsForm', 'validate');
    $form['#submit'][] = array('ChmProtectedPlanetSettingsForm', 'submit');
    return $form;
  }

  static function validate($form, &$form_state) {
    $file = file_save_upload('file', array(
      'file_validate_extensions' => array('csv'),
    ));
    if ($file) {
      $upload_dir = 'public://protected-areas/';
      // Move the file into the Drupal file system
      file_prepare_directory($upload_dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      if ($file = file_move($file, PROTECTED_PLANET_AREA_CSV_UPLOAD_DIR, FILE_EXISTS_REPLACE)) {
        $form_state['storage']['file'] = $file;
      }
      else {
        form_set_error('file', t("Failed to write the uploaded file to destination folder."));
      }
    }
    else {
      form_set_error('file', t('No file was uploaded.'));
    }
  }

  static function submit($form, &$form_state) {
    $file = $form_state['storage']['file'];
    // We are done with the file, remove it from storage.
    unset($form_state['storage']['file']);
    // Make the storage of the file permanent.
    $file->status = FILE_STATUS_PERMANENT;
    // Save file status.
    file_save($file);
    variable_set(PROTECTED_PLANET_AREA_CSV_VAR, $file->uri);
    // Set a response to the user.
    drupal_set_message(t('The file has been successfully uploaded. Due to the large amount of records, to conserve server resources the data will be processed in the background'));
  }
}
