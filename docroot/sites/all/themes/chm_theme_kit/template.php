<?php

function chm_theme_kit_preprocess_html(&$variables) {
  if (!empty($variables['head_title_array'])) {
     $hta = $variables['head_title_array'];
     if (count($hta) == 1) {
       $variables['head_title'] = $hta[0];
     }
     else {
      $variables['head_title'] = implode(' - ', $hta);
    }
  }
}