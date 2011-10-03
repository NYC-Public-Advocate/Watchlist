<?php
/**
 * @file
 *
 * Features support for Toolbar
 */

/**
 * Implementation of hook_features_export().
 */
function toolbar_features_export($data, &$export, $module_name) {

  // Hooks for menu is provided by features so we need to add it as dependency
  $export['dependencies']['toolbar'] = 'toolbar';
  $export['dependencies']['menu'] = 'menu';

  $pipe = array();
  foreach ($data as $toolbar) {
    $export['features']['toolbar'][$toolbar] = $toolbar;
    $toolbar = toolbar_toolbar_load_features($toolbar);

    // Add menu and menu links to export pipe
    $menu_links = menu_parent_options(array($toolbar['name'] => $toolbar['name']), NULL);
    foreach ($menu_links as $key => $name) {
      list($menu_name, $mlid) = explode(':', $key, 2);
      if ($mlid != 0) {
        $link = menu_link_load($mlid);
        $identifier = menu_links_features_identifier($link);
        $pipe['menu_links'][] = $identifier;
      }
    }
  }
  return $pipe;
}

/**
 * Implementation of hook_features_export_options().
 */
function toolbar_features_export_options() {
  return _toolbar_get_toolbars();
  $options = array();
  foreach ($toolbars as $toolbar) {
    $options[$toolbar['name']] = $toolbar['title'];
  }
  return $options;
}

/**
 * Implementation of hook_features_export_render().
 */
function toolbar_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  $code[] = '  $toolbars = array();';
  foreach ($data as $name) {
    $export = features_var_export(toolbar_toolbar_load_features($name), '  ');
    $code[] = "  // Exported toolbar: {$name}";
    $code[] = "  \$toolbars['{$name}'] = {$export};";
  }

  $code[] = "  return \$toolbars;";
  $code = implode("\n", $code);
  return array('toolbar_default_toolbars' => $code);
}

/**
 * Implementation of hook_features_export_revert().
 */
function toolbar_features_revert($module) {
  toolbar_features_rebuild($module);
}

/**
 * Implementation of hook_features_export_rebuild().
 */
function toolbar_features_rebuild($module) {
  if ($defaults = features_get_default('toolbar', $module)) {
    foreach ($defaults as $toolbar) {
      $existing = db_result(db_query("SELECT name FROM {toolbar_toolbar} WHERE name = '%s'", $toolbar['name']));
      drupal_write_record('toolbar_toolbar', $toolbar, $existing ? array('name') : array());
    }
  }
}


/**
 * Toolbar load function adapted for features
 */
function toolbar_toolbar_load_features($name = '*', $reset = FALSE) {
  static $toolbars;

  if ( '*' == $name ) {
    $toolbars = array();
    $result = db_query('SELECT name, title FROM {toolbar_toolbar}');
    while ( $toolbar = db_fetch_array($result) ) {
      $toolbars[$toolbar['name']] = $toolbar;
    }
    return $toolbars;
  }
  elseif ( !isset($toolbars[$name]) || $reset ) {
    $toolbars[$name] = db_fetch_array(db_query("SELECT name, title FROM {toolbar_toolbar} WHERE name = '%s'", $name));
  }
  return $toolbars[$name];
}
