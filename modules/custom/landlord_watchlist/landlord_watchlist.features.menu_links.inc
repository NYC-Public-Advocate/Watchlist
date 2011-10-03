<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function landlord_watchlist_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-watchlist-checklist:admin/build/themes/settings/bartik_mod
  $menu_links['menu-watchlist-checklist:admin/build/themes/settings/bartik_mod'] = array(
    'menu_name' => 'menu-watchlist-checklist',
    'link_path' => 'admin/build/themes/settings/bartik_mod',
    'router_path' => 'admin/build/themes/settings/bartik_mod',
    'link_title' => 'Customize appearance',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: menu-watchlist-checklist:admin/content/taxonomy/1
  $menu_links['menu-watchlist-checklist:admin/content/taxonomy/1'] = array(
    'menu_name' => 'menu-watchlist-checklist',
    'link_path' => 'admin/content/taxonomy/1',
    'router_path' => 'admin/content/taxonomy/%',
    'link_title' => 'Add neighborhoods',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-watchlist-checklist:import/landlord_watchlist
  $menu_links['menu-watchlist-checklist:import/landlord_watchlist'] = array(
    'menu_name' => 'menu-watchlist-checklist',
    'link_path' => 'import/landlord_watchlist',
    'router_path' => 'import/landlord_watchlist',
    'link_title' => 'Import data',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add neighborhoods');
  t('Customize appearance');
  t('Import data');


  return $menu_links;
}
