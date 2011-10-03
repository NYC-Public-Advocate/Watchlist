<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function landlord_watchlist_taxonomy_default_vocabularies() {
  return array(
    'neighborhood' => array(
      'name' => 'Neighborhood',
      'description' => 'Stores the various neighborhoods.',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_neighborhood',
      'weight' => '0',
      'nodes' => array(
        'landlord' => 'landlord',
        'neighborhood' => 'neighborhood',
      ),
    ),
  );
}
