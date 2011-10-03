<?php
// $Id$
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <!--[if lte IE 8]><style type="text/css">body{behavior:url(<?php print $base_path . path_to_theme() . '/scripts/csshover3.htc'; ?>);}</style><![endif]-->
  <?php print $scripts; ?>
</head>
<body class="<?php print bartik_mod_body_class($is_front, $logged_in, $is_admin, $node, $left, $right); ?>">
  <div id="header">
    <div class="container_16">
      <?php if (!empty($header)): ?>
        <div id="header-region" class="grid_16">
          <?php print $header; ?>
        </div>
      <?php endif; ?>

      <div id="site-title">
        <div class="grid_16">
          <?php if (!empty($logo)): ?>
            <div id="logo">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
                <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
              </a>
            </div>
          <?php endif; ?>

          <?php if (!empty($site_name) || !empty($site_slogan)): ?>
            <div id="site-name-and-slogan">
              <?php if (!empty($site_name)): ?>
                <h1 id="site-name">
                  <a href="<?php print $front_page ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
                </h1>
              <?php endif; ?>

              <?php if (!empty($site_slogan)): ?>
                <h3 id="site-slogan">
                  <?php print $site_slogan; ?>
                </h3>
              <?php endif; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>

      <?php if (!empty($primary_links)): ?>
        <div id="primary" class="grid_16 skele-reset">
          <?php print menu_tree($menu_name = 'primary-links'); ?>
        </div>
      <?php endif; ?>

      <div class="clear"></div>
    </div>
  </div>

  <div id="main-wrapper">
    <div class="container_16">
      <?php if (!empty($left)): ?>
        <div id="sidebar-left" class="grid_4 sidebar">
          <?php print $left; ?>
        </div>
      <?php endif; ?>

      <?php
      if (empty($left) && empty($right)) {
        $mainGridClass = 'grid_16';
      }
      else {
        if (empty($left) || empty($right)) {
          $mainGridClass = 'grid_12';
        }
        else {
          $mainGridClass = 'grid_8';
        }
      }
      ?>
      <div id="main" class="<?php print $mainGridClass; ?>">
        <?php if (!empty($breadcrumb)): ?><div id="breadcrumb"><?php print $breadcrumb; ?></div><?php endif; ?>
        <?php if (!empty($mission)): ?><div id="mission"><?php print $mission; ?></div><?php endif; ?>

        <div id="content">
          <?php if (!empty($title)): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
          <?php if (!empty($tabs)): ?><div class="tabs"><?php print $tabs; ?></div><?php endif; ?>
          <?php if (!empty($messages)): print $messages; endif; ?>
          <?php if (!empty($help)): print $help; endif; ?>
          <div id="content-content">
            <?php print $content; ?>
          </div>
          <?php print $feed_icons; ?>
        </div>
      </div>

      <?php if (!empty($right)): ?>
        <div id="sidebar-right" class="grid_4 sidebar">
          <?php print $right; ?>
        </div>
      <?php endif; ?>

      <div class="clear"></div>
    </div>
  </div>

  <div id="footer">
    <div class="container_16">
      <?php if (!empty($footer)): ?>
        <div id="footer-region" class="grid_16">
          <?php print $footer; ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($secondary_links)): ?>
        <div id="secondary" class="grid_16 skele-reset">
          <?php print theme('links', $secondary_links, array('id' => 'secondary-links')); ?>
        </div>
      <?php endif; ?>

      <?php if (!empty($footer_message)): ?>
        <div id="footer-message" class="grid_16">
          <?php print $footer_message; ?>
        </div>
      <?php endif; ?>

      <div id="theme-credits" class="grid_16">
        <?php print t('Modified <a href="@bartik-project">Bartik</a> Drupal 7 theme, designed by Jen Simmons.', array('@bartik-project' => url('http://drupal.org/project/bartik'))) ?>
      </div>

      <div class="clear"></div>
    </div>
  </div>

  <?php print $closure; ?>
</body>
</html>
