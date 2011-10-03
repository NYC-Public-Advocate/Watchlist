<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function landlord_watchlist_user_default_permissions() {
  $permissions = array();

  // Exported permission: create landlord content
  $permissions['create landlord content'] = array(
    'name' => 'create landlord content',
    'roles' => array(),
  );

  // Exported permission: create landlord_container content
  $permissions['create landlord_container content'] = array(
    'name' => 'create landlord_container content',
    'roles' => array(),
  );

  // Exported permission: delete any landlord content
  $permissions['delete any landlord content'] = array(
    'name' => 'delete any landlord content',
    'roles' => array(),
  );

  // Exported permission: delete any landlord_container content
  $permissions['delete any landlord_container content'] = array(
    'name' => 'delete any landlord_container content',
    'roles' => array(),
  );

  // Exported permission: delete own landlord content
  $permissions['delete own landlord content'] = array(
    'name' => 'delete own landlord content',
    'roles' => array(),
  );

  // Exported permission: delete own landlord_container content
  $permissions['delete own landlord_container content'] = array(
    'name' => 'delete own landlord_container content',
    'roles' => array(),
  );

  // Exported permission: edit any landlord content
  $permissions['edit any landlord content'] = array(
    'name' => 'edit any landlord content',
    'roles' => array(),
  );

  // Exported permission: edit any landlord_container content
  $permissions['edit any landlord_container content'] = array(
    'name' => 'edit any landlord_container content',
    'roles' => array(),
  );

  // Exported permission: edit own landlord content
  $permissions['edit own landlord content'] = array(
    'name' => 'edit own landlord content',
    'roles' => array(),
  );

  // Exported permission: edit own landlord_container content
  $permissions['edit own landlord_container content'] = array(
    'name' => 'edit own landlord_container content',
    'roles' => array(),
  );

  return $permissions;
}
