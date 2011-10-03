<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function landlord_watchlist_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-watchlist-checklist
  $menus['menu-watchlist-checklist'] = array(
    'menu_name' => 'menu-watchlist-checklist',
    'title' => 'Watchlist Checklist',
    'description' => 'A checklist for Watchlist site administrators',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A checklist for Watchlist site administrators');
  t('Watchlist Checklist');


  return $menus;
}
