<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function landlord_watchlist_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'landlord_watchlist';
  $feeds_importer->config = array(
    'name' => 'Landlord Watchlist',
    'description' => 'Upload a CSV file into the Watchlist',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'landlord',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'field_landlord_title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Company',
            'target' => 'field_landlord_company',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Units',
            'target' => 'field_landlord_units',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Total Infractions',
            'target' => 'field_landlord_vio_total',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'A Class',
            'target' => 'field_landlord_vio_a',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'B Class',
            'target' => 'field_landlord_vio_b',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'C Class',
            'target' => 'field_landlord_vio_c',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'I Class',
            'target' => 'field_landlord_vio_i',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'State',
            'target' => 'locations:province',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Landlord',
            'target' => 'title',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Address',
            'target' => 'locations:street',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Job Title',
            'target' => 'field_landlord_title',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Neighborhood',
            'target' => 'taxonomy:features_neighborhood',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'City',
            'target' => 'locations:city',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'Zipcode',
            'target' => 'locations:postal_code',
            'unique' => FALSE,
          ),
        ),
        'author' => 0,
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['landlord_watchlist'] = $feeds_importer;

  return $export;
}
