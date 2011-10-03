<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _landlord_watchlist_node_info() {
  $items = array(
    'landlord' => array(
      'name' => t('Landlord Building'),
      'module' => 'features',
      'description' => t('Used for the listing of slum landlords.'),
      'has_title' => '1',
      'title_label' => t('Landlord Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'landlord_container' => array(
      'name' => t('Landlord Container'),
      'module' => 'features',
      'description' => t('Holds groups of Landlord buildings (IE for the 50  worst landlords section).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'neighborhood' => array(
      'name' => t('Neighborhood'),
      'module' => 'features',
      'description' => t('Neighborhoods are sections of a city.  They are called "Boroughs" on the New York edition of the Watchlist.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
