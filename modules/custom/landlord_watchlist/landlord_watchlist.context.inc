<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function landlord_watchlist_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_ui-section-landlord_watchlist';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'landlord-watchlist*' => 'landlord-watchlist*',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-landlord' => array(
          'module' => 'menu',
          'delta' => 'menu-landlord',
          'weight' => 51,
          'region' => 'span_top',
          'status' => '0',
          'label' => 'NYC&#039;s Worst Landlords Watchlist',
          'type' => 'context_ui',
        ),
        'block-32' => array(
          'module' => 'block',
          'delta' => '32',
          'weight' => 52,
          'region' => 'span_top',
          'status' => '0',
          'label' => 'Landlord Watchlist Header',
          'type' => 'context_ui',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['context_ui-section-landlord_watchlist'] = $context;

  return $export;
}
