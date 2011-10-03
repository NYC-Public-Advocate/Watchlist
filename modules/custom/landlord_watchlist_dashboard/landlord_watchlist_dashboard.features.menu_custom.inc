<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function landlord_watchlist_dashboard_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-watchlist-checklist
  $menus['menu-watchlist-checklist'] = array(
    'menu_name' => 'menu-watchlist-checklist',
    'title' => 'Setup Checklist',
    'description' => 'A checklist for Watchlist site administrators',
  );
  // Exported menu: menu-watchlist-other-resources
  $menus['menu-watchlist-other-resources'] = array(
    'menu_name' => 'menu-watchlist-other-resources',
    'title' => 'Other Resrouces',
    'description' => 'Other resources that might be useful for Watchlist administrators.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('A checklist for Watchlist site administrators');
  t('Other Resrouces');
  t('Other resources that might be useful for Watchlist administrators.');
  t('Setup Checklist');


  return $menus;
}
