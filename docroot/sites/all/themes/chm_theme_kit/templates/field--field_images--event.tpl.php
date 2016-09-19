<div class="container <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items row"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item col-md-3 col-sm-4 col-xs-6 <?php print $delta % 3 ? '' : 'clearfix'; ?>"<?php print $item_attributes[$delta]; ?>>
        <?php print render($item); ?>
        <div class="img-title"><?php print $item['#item']['title']; ?></div>
      </div>
    <?php endforeach; ?>
  </div>
</div>
