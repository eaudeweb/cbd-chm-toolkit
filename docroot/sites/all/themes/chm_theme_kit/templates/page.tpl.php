<a href="#main" class="element-invisible element-focusable"><?php print t('Skip to content'); ?></a>
<?php if ($main_menu): ?>
<a href="#main-nav" class="element-invisible element-focusable" data-target=".nav-collapse" data-toggle="collapse"><?php print t('Skip to navigation'); ?></a>
<?php endif; ?>
<!-- /#skipnav -->
<?php //if ((($user->uid) && ($page['admin_shortcuts'])) || (($user->uid) && ($secondary_nav))): ?>
<div id="admin-shortcuts" class="admin-shortcuts clearfix">
  <div class="container">
    <?php if(variable_get('environment') == 'test'): ?>
    <span class="label label-warning" style="position: absolute; left: 0; margin: 10px 0 0 10px;">Test website</span>
    <?php endif; ?>
    <?php //print render($secondary_nav); ?>
    <?php print render($page['admin_shortcuts']); ?>
  </div>
</div>
<?php //endif; ?>
<!-- /#admin-shortcuts -->

<div class="<?php print $container_class; ?>">
  <header role="banner" id="page-header">
    <div class="row">
      <div class="header-section col-xs-12">
        <?php if ($logo): ?>
          <div id="logo">
            <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
            </a>
          </div>
        <?php endif; ?>
        <div id="name-and-slogan">
            <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
            <?php if (!empty($site_slogan)): ?>
            <div id="site-slogan" class="site-slogan"><?php print $site_slogan; ?></div>
            <?php endif; ?>
        </div>
        <?php if ($page['search_box']): ?>
          <div id="nav-search" class="nav-search"> <?php print render($page['search_box']); ?> </div>
        <?php endif; ?>
      </div>
    </div>

    <div class="row">
      <div class="col-xs-12">
        <?php print render($page['header']); ?>
      </div>
    </div>
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

        <?php if ($page['search_box']): ?>
          <div id="nav-search" class="nav-search"> <?php print render($page['search_box']); ?> </div>
        <?php endif; ?>
      </div>
      <?php if (!empty($primary_nav)): ?>
        <div class="navbar-collapse collapse">
          <nav role="navigation">
            <?php print render($primary_nav); ?>
          </nav>
        </div>
      <?php endif; ?>
    </div>
  </header>
</div>

<div class="breadcrumb-container">
  <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
</div>

<div class="main-container <?php print $container_class; ?>">
  <?php print render($title_prefix); ?>
  <?php if (!empty($title)): ?>
    <h1 class="title" id="page-title"> <?php print $title; ?> </h1>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
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
      <a id="main-content"></a>
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
        <div class="row">
            <div id="main-top" class="col-xs-12 main-top"> <?php print render($page['main_top']); ?> </div>
        </div>
      <?php endif; ?>
      <div class="row">
        <div class="col-xs-12">
          <?php print render($page['content']); ?>
        </div>
      </div>
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
        <div class="row">
          <div id="content-bottom" class="col-xs-12 content-bottom"> <?php print render($page['content_bottom']); ?> </div>
        </div>
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
	 <div id="footer-content" class="row footer-content">
       <div class="footer-logo">
         <?php echo theme('ptk_base_footer_logo', array('title' => $site_name) ); ?>
       </div>
       <div class="footer-support">
         <div class="text"><?php print t('With the support of the'); ?></div>
         <?php echo theme('ptk_base_footer_support'); ?>
       </div>
       <div class="clearfix"></div>
       <?php
       $search = '</li>
</ul>';
       $replace = '</li><li class="leaf copyright">' . $copyright . '</li></ul>';
       print str_replace($search, $replace, render($page['footer']));
       ?>
     </div>
  </div>
</div>
<!-- /#footer -->
