<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function landlord_watchlist_dashboard_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'dashboard';
  $context->description = 'Used on the dashboard';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'admin/dashboard' => 'admin/dashboard',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-watchlist-checklist' => array(
          'module' => 'menu',
          'delta' => 'menu-watchlist-checklist',
          'region' => 'left',
          'weight' => 0,
        ),
        'menu-menu-watchlist-other-resources' => array(
          'module' => 'menu',
          'delta' => 'menu-watchlist-other-resources',
          'region' => 'left',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Used on the dashboard');
  $export['dashboard'] = $context;

  return $export;
}
