<?php

/**
 * Implementation of hook_uuid_features_default_terms().
 */
function landlord_watchlist_dummy_data_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'uuid' => '0a16eac0-e359-11e0-96c3-40408e9676d4',
    'name' => 'Bronx',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '0a16c175-e359-11e0-96c3-40408e9676d4',
  );
  $terms[] = array(
    'uuid' => '0a16fde7-e359-11e0-96c3-40408e9676d4',
    'name' => 'Brooklyn',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '0a16c175-e359-11e0-96c3-40408e9676d4',
  );
  $terms[] = array(
    'uuid' => '0a170d01-e359-11e0-96c3-40408e9676d4',
    'name' => 'Manhattan',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '0a16c175-e359-11e0-96c3-40408e9676d4',
  );
  $terms[] = array(
    'uuid' => '0a171aaf-e359-11e0-96c3-40408e9676d4',
    'name' => 'Queens',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '0a16c175-e359-11e0-96c3-40408e9676d4',
  );
  $terms[] = array(
    'uuid' => '0a17282a-e359-11e0-96c3-40408e9676d4',
    'name' => 'Staten Island',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '0a16c175-e359-11e0-96c3-40408e9676d4',
  );
  return $terms;
}
