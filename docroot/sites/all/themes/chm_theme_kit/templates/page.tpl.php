<a href="#main" class="element-invisible element-focusable"><?php print t('Skip to content'); ?></a>
<?php if ($main_menu): ?>
<a href="#main-nav" class="element-invisible element-focusable" data-target=".nav-collapse" data-toggle="collapse"><?php print t('Skip to navigation'); ?></a>
<?php endif; ?>
<!-- /#skipnav -->
<?php //if ((($user->uid) && ($page['admin_shortcuts'])) || (($user->uid) && ($secondary_nav))): ?>
<div id="admin-shortcuts" class="admin-shortcuts clearfix"><div class="container"> <?php //print render($secondary_nav); ?> <?php print render($page['admin_shortcuts']); ?> </div></div>
<?php //endif; ?>
<!-- /#admin-shortcuts -->

<div class="<?php print $container_class; ?>">
  <header role="banner" id="page-header">
    <?php if ($logo): ?>
      <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>
    <?php endif; ?>

    <?php if (!empty($site_name)): ?>
      <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
    <?php endif; ?>

    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->
</div>

<div class="navbar-container">
  <header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <div class="<?php print $container_class; ?>">
      <div class="navbar-header">
        <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        <?php endif; ?>
      </div>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <div class="navbar-collapse collapse">
          <nav role="navigation">
            <?php if (!empty($primary_nav)): ?>
              <?php print render($primary_nav); ?>
            <?php endif; ?>
          </nav>
        </div>
      <?php endif; ?>
    </div>
  </header>
</div>

<div class="main-container <?php print $container_class; ?>">
  <div class="row">
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="title" id="page-title"> <?php print $title; ?> </h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>

      <?php if ($page['main_top']): ?>
        <div id="main-top" class="main-top"> <?php print render($page['main_top']); ?> </div>
      <?php endif; ?>

      <?php print render($page['content']); ?>

      <?php if (($page['content_col2-1']) || ($page['content_col2-2'])): ?>
        <div id="content-col2" class="row content-col2">
          <?php if ($page['content_col2-1']): ?>
            <div class="col-xs-12 col-sm-6">
              <div id="content-col2-1"> <?php print render($page['content_col2-1']); ?> </div>
            </div>
          <?php endif; ?>
          <?php if ($page['content_col2-2']): ?>
            <div class="col-xs-12 col-sm-6">
              <div id="content-col2-2"> <?php print render($page['content_col2-2']); ?> </div>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <?php if ($page['content_bottom']): ?>
        <div id="content-bottom" class="content-bottom"> <?php print render($page['content_bottom']); ?> </div>
      <?php endif; ?>

    </section>


    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
<!-- /#main, /#main-wrapper -->
<div id="footer" class="clearfix site-footer" role="contentinfo">
  <div class="container">
    <div id="footer-content" class="row footer-content content-row">
    <?php if ($page['footer_col_1']): ?>
      <div id="footer-row1-4" class="col-sm-3">  <?php print render($page['footer_col_1']); ?> </div>
     <?php endif; ?>
    <?php if ($page['footer_col_2']): ?>
      <div id="footer-row2-4" class="col-sm-3"> <?php print render($page['footer_col_2']); ?> </div>
    <?php endif; ?>
    <?php if ($page['footer_col_3']): ?>
      <div id="footer-row3-4" class="col-sm-3"> <?php print render($page['footer_col_3']); ?> </div>
    <?php endif; ?>
    <?php if ($page['footer_col_4']): ?>
      <div id="footer-row4-4" class="col-sm-3"> <?php print render($page['footer_col_4']); ?> </div>
    <?php endif; ?>
    </div>
  </div>
</div>
<div id="footer2" class="clearfix site-footer" role="contentinfo">
  <div class="container">
	 <div id="footer-content" class="row footer-content"> <?php print render($page['footer']); ?> </div>
  </div>
</div>
<!-- /#footer -->
