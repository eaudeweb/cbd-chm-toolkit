<?php
/**
 * @file
 * Custom CHM Search ion.rangeSlider widget.
 */
?>
<!-- <div class="search-api-ranges-text"><?php print drupal_render($form['text-range']); ?></div> -->
<div class="search-api-ranges-elements">
  <div class="search-api-ranges-element range-slider-box">
  <?php print drupal_render($form['range-slider']); ?>
  </div>
  <div class="pull-left">
  <?php print drupal_render($form['range-from']); ?>
  <?php print drupal_render($form['range-to']); ?>
  </div>
  <div class="pull-right">
  <?php print drupal_render($form['submit']); ?>
  </div>
</div>
<?php
  // Render required hidden fields.
  print drupal_render_children($form);
