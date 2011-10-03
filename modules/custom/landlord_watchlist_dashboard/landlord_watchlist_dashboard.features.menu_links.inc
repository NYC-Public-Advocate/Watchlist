<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function landlord_watchlist_dashboard_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-watchlist-checklist:admin/landlord-watchlist/clear
  $menu_links['menu-watchlist-checklist:admin/landlord-watchlist/clear'] = array(
    'menu_name' => 'menu-watchlist-checklist',
    'link_path' => 'admin/landlord-watchlist/clear',
    'router_path' => 'admin/landlord-watchlist/clear',
    'link_title' => 'Disable dummy data',
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
  // Exported menu link: menu-watchlist-checklist:admin/settings/gmap
  $menu_links['menu-watchlist-checklist:admin/settings/gmap'] = array(
    'menu_name' => 'menu-watchlist-checklist',
    'link_path' => 'admin/settings/gmap',
    'router_path' => 'admin/settings',
    'link_title' => 'Add Google API key',
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
  // Exported menu link: menu-watchlist-checklist:import/landlord_watchlist/dummy
  $menu_links['menu-watchlist-checklist:import/landlord_watchlist/dummy'] = array(
    'menu_name' => 'menu-watchlist-checklist',
    'link_path' => 'import/landlord_watchlist/dummy',
    'router_path' => 'import/landlord_watchlist',
    'link_title' => 'Import dummy data',
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
    'weight' => '-49',
  );
  // Exported menu link: menu-watchlist-other-resources:landlord-watchlist/download.xls
  $menu_links['menu-watchlist-other-resources:landlord-watchlist/download.xls'] = array(
    'menu_name' => 'menu-watchlist-other-resources',
    'link_path' => 'landlord-watchlist/download.xls',
    'router_path' => 'landlord-watchlist/download.xls',
    'link_title' => 'Download data',
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
  // Exported menu link: menu-watchlist-other-resources:node/add/webform
  $menu_links['menu-watchlist-other-resources:node/add/webform'] = array(
    'menu_name' => 'menu-watchlist-other-resources',
    'link_path' => 'node/add/webform',
    'router_path' => 'node/add/webform',
    'link_title' => 'Create Form',
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
  t('Add Google API key');
  t('Create Form');
  t('Disable dummy data');
  t('Download data');
  t('Import dummy data');
  t('Import data');
  t('Add neighborhoods');


  return $menu_links;
}
