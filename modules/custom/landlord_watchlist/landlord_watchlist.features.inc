<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function landlord_watchlist_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function landlord_watchlist_node_info() {
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
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function landlord_watchlist_views_api() {
  return array(
    'api' => '2',
  );
}
