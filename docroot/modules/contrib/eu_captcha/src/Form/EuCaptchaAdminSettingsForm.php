<?php
/**
 * @file
 * Contains \Drupal\eu_captcha\Form\EuCaptchaAdminSettingsForm.
 */

namespace Drupal\eu_captcha\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure EU-CAPTCHA settings for this site.
 */
class EuCaptchaAdminSettingsForm extends ConfigFormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'eu_captcha_admin_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return ['eu_captcha.settings'];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('eu_captcha.settings');

    $form['help'] = array(
      '#type' => 'item',
      '#markup' => t('Visit the EU CAPTCHA project <a target="_blank" href="!url_doc">documentation</a> and <a target="_blank" href="!url_examples">examples</a> pages',
        array('!url_doc' => 'http://ec.europa.eu/ipg/services/interactive_services/captcha/index_en.htm',
          '!url_examples' => 'http://webtools.ec.europa.eu/captcha/examples')
      ),
    );
    $form['type'] = array(
      '#type' => 'select',
      '#title' => t('Type'),
      '#options' => array('string' => 'String', 'math' => 'Math'),
      '#default_value' => $config->get('type'),
      '#description' => t('Type of the CAPTCHA, either a list of characters to copy OR a simple math problem to solve'),
    );
    $form['length'] = array(
      '#type' => 'number',
      '#title' => t('Length'),
      '#default_value' => $config->get('length'),
      '#description' => t('Number of characters for the captcha'),
    );
    $form['case_sensitive'] = array(
      '#type' => 'checkbox',
      '#title' => t('Case sensitive'),
      '#default_value' => $config->get('case_sensitive'),
      '#description' => t('Indicates if captcha is case sensitive'),
    );
    $form['autodetect_protocol'] = array(
      '#type' => 'checkbox',
      '#title' => t('Autodetect protocol'),
      '#default_value' => $config->get('autodetect_protocol'),
      '#description' => t('Use the same protocol (HTTP or HTTPS) for CAPTCHA elements as the hosting page, if unchecked uses HTTPS'),
    );
    $form['perturbation'] = array(
      '#type' => 'number',
      '#title' => t('Perturbation'),
      '#default_value' => $config->get('perturbation'),
      '#min' => 0,
      '#max' => 1,
      '#step' => 0.1,
      '#description' => t('Perturbation to apply on characters. Float between 0 (no perturbation) and 1 (maximal perturbation)'),
    );
    $form['num_lines'] = array(
      '#type' => 'number',
      '#title' => t('Number of lines'),
      '#default_value' => $config->get('eu_captcha_num_lines'),
      '#description' => t('Number of strikeout lines to display in the background'),
    );
    $form['noise_level'] = array(
      '#type' => 'number',
      '#title' => t('Noise level'),
      '#default_value' => $config->get('noise_level'),
      '#description' => t('Quantity of noise to display in the background (Example: 3)'),
    );
    $form['image_bg_color'] = array(
      '#type' => 'color',
      '#title' => t('Image background color'),
      '#default_value' => $config->get('image_bg_color'),
      '#description' => t('HEX color code for the background (Example F3C9A2)'),
    );
    $form['text_color'] = array(
      '#type' => 'color',
      '#title' => t('Text color'),
      '#default_value' => $config->get('text_color'),
      '#description' => t('HEX color code of the text (Example A18382)'),
    );
    $form['line_color'] = array(
      '#type' => 'color',
      '#title' => t('Line color'),
      '#default_value' => $config->get('line_color'),
      '#description' => t('HEX code for the background strikeout lines'),
    );
    $form['noise_color'] = array(
      '#type' => 'color',
      '#title' => t('Noise color'),
      '#default_value' => $config->get('noise_color'),
      '#description' => t('HEX code for the background noise'),
    );
    $use_transparency = $config->get('use_transparent_text');
    $form['use_transparent_text'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enable text transparency'),
      '#default_value' => $use_transparency,
    );
    $form['text_transparency_percentage'] = array(
      '#type' => 'number',
      '#title' => t('Text transparency percentage'),
      '#min' => 0,
      '#max' => 100,
      '#default_value' => $config->get('text_transparency_percentage'),
      '#description' => t('Transparency level of the captcha. Integer between 0 (no transparency) and 100 (maximum transparency)'),
    );

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
    parent::validateForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $config = $this->config('eu_captcha.settings');
    $config
      ->set('type', $form_state->getValue('type'))
      ->set('length', $form_state->getValue('length'))
      ->set('case_sensitive', $form_state->getValue('case_sensitive'))
      ->set('autodetect_protocol', $form_state->getValue('autodetect_protocol'))
      ->set('perturbation', $form_state->getValue('perturbation'))
      ->set('num_lines', $form_state->getValue('num_lines'))
      ->set('noise_level', $form_state->getValue('noise_level'))
      ->set('image_bg_color', $form_state->getValue('image_bg_color'))
      ->set('text_color', $form_state->getValue('text_color'))
      ->set('line_color', $form_state->getValue('line_color'))
      ->set('noise_color', $form_state->getValue('noise_color'))
      ->set('use_transparent_text', $form_state->getValue('use_transparent_text'))
      ->set('text_transparency_percentage', $form_state->getValue('text_transparency_percentage'))
      ->save();

    parent::submitForm($form, $form_state);
  }

}
