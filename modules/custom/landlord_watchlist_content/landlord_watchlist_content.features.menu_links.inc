<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function landlord_watchlist_content_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:node/1
  $menu_links['primary-links:node/1'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Watchlist Criteria',
    'options' => array(
      'attributes' => array(
        'title' => 'Watchlist Criteria',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: primary-links:node/2
  $menu_links['primary-links:node/2'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Landlord Resources',
    'options' => array(
      'attributes' => array(
        'title' => 'Landlord Resources',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: primary-links:node/3
  $menu_links['primary-links:node/3'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Tenants\' Rights',
    'options' => array(
      'attributes' => array(
        'title' => 'Tenants\' Rights',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: primary-links:node/6
  $menu_links['primary-links:node/6'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'How to File a Complaint',
    'options' => array(
      'attributes' => array(
        'title' => 'How to File a Complaint',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('How to File a Complaint');
  t('Landlord Resources');
  t('Tenants\' Rights');
  t('Watchlist Criteria');


  return $menu_links;
}
