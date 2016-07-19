<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in html.tpl.php and page.tpl.php.
 * Some may be blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 *
 * @ingroup themeable
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">
<div id="page">
  <div id="header">
    <div id="logo-title">

      <div class="container">
        <header role="banner" id="page-header">
          <div class="row">
            <div class="col-xs-12">
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
            </div>
          </div>

          <div class="row">
            <div class="col-xs-12">
              <?php print render($page['header']); ?>
            </div>
          </div>
        </header> <!-- /#page-header -->
      </div>
    </div> <!-- /logo-title -->

    <div class="container">
      <div class="row">
        <div class="col-xs-12">
          <?php if (!empty($header)): ?>
            <div id="header-region">
              <?php print $header; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    </div>

  </div> <!-- /header -->

  <div class="navbar-container">
    <header id="navbar" role="banner" class="navbar container navbar-default>">
      <div class="<container">
        <div class="navbar-header">

        </div>
      </div>
    </header>
  </div>

  <div id="container" class="clearfix">

    <div id="main" class="column"><div id="main-squeeze">

        <div id="content">
          <?php if (!empty($title)): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
          <?php if (!empty($messages)): print $messages; endif; ?>
          <div id="content-content" class="clearfix">
            <?php print $content; ?>
          </div> <!-- /content-content -->
        </div> <!-- /content -->

      </div></div> <!-- /main-squeeze /main -->

    <?php if (!empty($sidebar_second)): ?>
      <div id="sidebar-second" class="column sidebar">
        <?php print $sidebar_second; ?>
      </div> <!-- /sidebar-second -->
    <?php endif; ?>

  </div> <!-- /container -->

  <div id="footer-wrapper">
    <div id="footer">
      <?php if (!empty($footer)): print $footer; endif; ?>
    </div> <!-- /footer -->
  </div> <!-- /footer-wrapper -->

</div> <!-- /page -->

<div id="footer-container">
  <div id="footer" class="clearfix site-footer" role="contentinfo">
    <div class="container">
      <div id="footer-content" class="row footer-content content-row">
      </div>
    </div>
  </div>

  <div id="footer2" class="clearfix site-footer" role="contentinfo">
    <div class="container">
      <div id="footer-content" class="row footer-content">
        <div class="footer-logo">
          <img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>" />
        </div>
        <div class="footer-support">
          <div class="text"><?php print t('With the support of the'); ?></div>
          <img src="<?php print drupal_get_path('theme', 'chm_theme_kit') . '/img/jbf.jpg'; ?>" align="Japan Biodiversity Fund" />
        </div>
        <div class="clearfix"></div>
        <?php print render($page['footer']); ?>
      </div>
    </div>
  </div>
</div>

</body>
</html>
