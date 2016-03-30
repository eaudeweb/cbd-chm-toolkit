<?php

/**
 * @file
 * Contains \Drupal\chm\Form\ChmCustomInstallForm
 */

namespace Drupal\chm\Form;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Implements custom config form for MY_PROFILE
 */
class ChmCustomInstallForm extends FormBase {

  public static function getModules() {
    // TODO return by Group CHM.
    return array(
      'chm_comment' => 'Comments',
      'chm_events' => 'Events',
    );
  }

  public function getFormId() {
    return 'chm_custom_install_form';
  }

  public function buildForm(array $form, FormStateInterface $form_state) {
    $modules = self::getModules();
    $form['#title'] = 'CHM toolkit custom configuration';
    $form['modules'] = array(
      '#title' => 'Select functionality',
      '#description' => 'Select the functionality you would like to have available after install. You can enable later the ones that are left unchecked now.',
      '#type' => 'checkboxes',
      '#options' => $modules,
      '#default_value' => array_combine(array_keys($modules), array_keys($modules)),
    );
    $existing_default = \Drupal::state()->get('chm_profile_modules');
    if (!empty($existing_default)) {
      $form['modules']['#default_value'] = $existing_default;
    }
    $form['op'] = array(
      '#type' => 'submit',
      '#value' => 'Submit',
    );
    return $form;
  }

  public function validateForm(array &$form, FormStateInterface $form_state) {
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {
    $modules = $form_state->getValue('modules');
    $modules = array_filter($modules);
    \Drupal::state()->set('chm_profile_modules', $modules);
  }
}
