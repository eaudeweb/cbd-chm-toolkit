<div id="views-bootstrap-media-<?php print $id ?>" class="<?php print $classes ?>">
  <ul class="media-list">
    <?php foreach ($items as $key => $item): ?>
      <li class="media well">
        <?php if ($item['image_field']): ?>
          <div class="media-object">
            <?php print $item['image_field'] ?>
          </div>
        <?php endif ?>
        <div class="media-body">
          <?php if ($item['heading_field']): ?>
            <h5 class="media-heading">
              <?php print $item['heading_field'] ?>
            </h5>
          <?php endif ?>

          <?php print $item['body_field'] ?>
        </div>
      </li>
    <?php endforeach ?>
  </ul>
</div>
