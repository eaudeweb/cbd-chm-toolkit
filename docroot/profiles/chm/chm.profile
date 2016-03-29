<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

use Drupal\contact\Entity\ContactForm;
use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function chm_form_install_configure_form_alter(&$form, FormStateInterface $form_state) {
  // TODO Add some install form options (i.e skin)
}
