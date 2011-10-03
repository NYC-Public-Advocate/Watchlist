<?php
// $Id: color.inc,v 1.4 2007/12/14 17:00:14 goba Exp $

$info = array(

  // Pre-defined color schemes.
  'schemes' => array(
    '#00AEEF,#00AEEF,#00AEEF,#000000,#000000' => t('Bright Blue (Default)'),
    '#00a0e0,#00a0e0,#00a0e0,#000000,#000000' => t('Process Blue'),
    '#0087bb,#0087bb,#0087bb,#000000,#000000' => t('Royal Blue'),
    '#2566a2,#2566a2,#2566a2,#000000,#000000' => t('Reflex Blue'),
    '#6b296d,#6b296d,#6b296d,#000000,#000000' => t('Deep Purple'),
    '#95427a,#95427a,#95427a,#000000,#000000' => t('Cerise'),
    '#bc1d6c,#bc1d6c,#bc1d6c,#000000,#000000' => t('Process Red'),
    '#b9183e,#b9183e,#b9183e,#000000,#000000' => t('IMC Red'),
    '#fcec2a,#fcec2a,#fcec2a,#000000,#000000' => t('Process Yellow'),
    '#c56332,#c56332,#c56332,#000000,#000000' => t('Spartan Red'),
    '#ca753c,#ca753c,#ca753c,#000000,#000000' => t('Vivid Orange'),
    '#84511d,#84511d,#84511d,#000000,#000000' => t('October Brown'),
    '#489c69,#489c69,#489c69,#000000,#000000' => t('Shamrock Green'),
    '#0993a5,#0993a5,#0993a5,#000000,#000000' => t('Turquoise'),
  ),
   
  // Images to copy over.
  /*'copy' => array(
    'images/menu-collapsed.gif',
    'images/menu-collapsed-rtl.gif',
    'images/menu-expanded.gif',
    'images/menu-leaf.gif',
  ),*/

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => array(
    'style.css',
    'style-custom.css',
    'style.css',
  ),
/*
  // Coordinates of gradient (x, y, width, height).
  'gradient' => array(0, 37, 760, 121),

  // Color areas to fill (x, y, width, height).
  'fill' => array(
    'base' => array(0, 0, 760, 568),
    'link' => array(107, 533, 41, 23),
  ),
*/
  // Coordinates of all the theme slices (x, y, width, height)
  // with their filename as used in the stylesheet.
  /*'slices' => array(
    'images/body.png'                      => array(0, 37, 1, 280),
    'images/bg-bar.png'                    => array(202, 530, 76, 14),
    'images/bg-bar-white.png'              => array(202, 506, 76, 14),
    'images/bg-tab.png'                    => array(107, 533, 41, 23),
    'images/bg-navigation.png'             => array(0, 0, 7, 37),
    'images/bg-content-left.png'           => array(40, 117, 50, 352),
    'images/bg-content-right.png'          => array(510, 117, 50, 352),
    'images/bg-content.png'                => array(299, 117, 7, 200),
    'images/bg-navigation-item.png'        => array(32, 37, 17, 12),
    'images/bg-navigation-item-hover.png'  => array(54, 37, 17, 12),
    'images/gradient-inner.png'            => array(646, 307, 112, 42),

    'logo.png'                             => array(622, 51, 64, 73),
    'screenshot.png'                       => array(0, 37, 400, 240),
  ),*/

  // Reference color used for blending. Matches the base.png's colors.
  'blend_target' => '#ffffff',

  // Preview files.
  'preview_image' => 'color/preview.png',
  'preview_css' => 'color/preview.css',

  // Base file for image generation.
  //'base_image' => 'color/base.png',
);
