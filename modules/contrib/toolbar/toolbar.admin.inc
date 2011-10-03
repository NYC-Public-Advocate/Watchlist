<?php

/**
 * @file
 * Handles toolbar administration functions and forms for Toolbar module
 *
 * Functions and forms to create, edit and delete toolbars.
 */

/**
 * Page to administer toolbars
 *
 * Overview of toolbars and links for toolbar related actions.
 *
 * @return
 *  A table with available toolbars.
 */
function toolbar_overview_page() {
  $toolbars = _toolbar_get_toolbars();
  $destination = drupal_get_destination();
  $rows = array();
  foreach ($toolbars as $name => $title) {
    $rows[] = array(
      check_plain($title),
      l(t('list shortcuts'), 'admin/build/toolbar/' . $name . '/shortcut'),
      l(t('edit'), 'admin/build/toolbar/' . $name . '/edit', array('query' => $destination)),
      l(t('export'), 'admin/build/toolbar/' . $name . '/export', array('query' => $destination)),
      l(t('delete'), 'admin/build/toolbar/' . $name . '/delete', array('query' => $destination)),
    );
  }
  if ( empty($rows) ) {
    $empty_message = t('No toolbars found, !add.', array('!add' => l(t('Add toolbar'), 'admin/build/toolbar/add')));
    $rows[] = array(array('data' => $empty_message, 'colspan' => '5'));
  }

  $header = array(
    array('data' => t('Title')),
    array('data' => t('Operations'), 'colspan' => '4')
  );
  $output .= theme('table', $header, $rows);

  return $output;
}

/**
 * Form to add and edit toolbar.
 *
 * @param $toolbar
 *  An array with the toolbar to edit or NULL if creating new toolbar.
 *
 * @return
 *  A form to add or edit a shortcut set
 *
 * @see toolbar_edit_form_validate()
 * @see toolbar_edit_form_submit()
 *
 * @ingroup forms
 */
function toolbar_edit_form(&$form_state, $toolbar = NULL) {

  if ( is_null($toolbar) ) {
    $toolbar = array('title' => '');
    $form['#insert'] = TRUE;

    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#maxsize' => TOOLBAR_MAX_NAME_LENGTH_UI,
      '#description' => t('The machine-readable name of this set. This name must contain only lowercase letters, numbers, and hyphens, and must be unique.'),
      '#required' => TRUE,
    );
  }
  else {
    $form['name'] = array('#type' => 'value', '#value' => $toolbar['name']);
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $toolbar['title'],
    '#description' => t('Specify title for this shortcut set.'),
    '#required' => TRUE,
  );

  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
  return $form;
}

/**
 * Validation handler for toolbar_edit_form()
 *
 * If adding new set we must check for unique set name.
 *
 * @see toolbar_edit_form()
 * @see toolbar_edit_form_submit()
 *
 * @ingroup forms
 */
function toolbar_edit_form_validate($form, &$form_state) {
  $toolbar = $form_state['values'];
  if (preg_match('/[^a-z0-9-]/', $toolbar['name'])) {
    form_set_error('name', t('The toolbar name may only consist of lowercase letters, numbers, and hyphens.'));
  }
  if (strlen($toolbar['name']) > TOOLBAR_MAX_NAME_LENGTH_UI) {
    form_set_error('name', format_plural(TOOLBAR_MAX_NAME_LENGTH_UI, 'The toolbar name can\'t be longer than 1 character.', 'The toolbar name can\'t be longer than @count characters.'));
  }
  if ($form['#insert']) {
    // Add the name prefix to avoid name-space conflicts.
    $toolbar['name'] = TOOLBAR_NAME_PREFIX . $toolbar['name'];
    if (db_result(db_query("SELECT name FROM {toolbar_toolbar} WHERE name = '%s'", $toolbar['name'])) ||
      db_result(db_query_range("SELECT menu_name FROM {menu_links} WHERE menu_name = '%s'", $toolbar['name'], 0, 1))) {
      form_set_error('name', t('The toolbar already exists.'));
    }
  }
}

/**
 * Submit handler for the toolbar_edit_form
 *
 * @return
 *  A success message if the shortcut et was saved
 *
 * @see toolbar_edit_form()
 * @see toolbar_edit_form_validate()
 *
 * @ingroup forms
 */
function toolbar_edit_form_submit($form, &$form_state) {
  $toolbar = $form_state['values'];

  $title = array('%title' => $toolbar['title']);

  if ($form['#insert']) {
    // Add the name prefix
    $toolbar['name'] = TOOLBAR_NAME_PREFIX . $toolbar['name'];
    db_query("INSERT INTO {toolbar_toolbar} VALUES ('%s', '%s')", $toolbar['name'], $toolbar['title']);

    // Inform everybody
    module_invoke_all('toolbar_insert_toolbar', $toolbar);
    watchdog('toolbar', "Toolbar '%title' created.", $title, WATCHDOG_NOTICE);
    drupal_set_message(t("The '%title' toolbar has been created.", $title));
  }
  else {
    db_query("UPDATE {toolbar_toolbar} SET title = '%s' WHERE name = '%s'", $toolbar['title'], $toolbar['name']);

    // Inform everybody
    module_invoke_all('toolbar_update_toolbar', $toolbar);
    watchdog('toolbar', "Toolbar '%title' updated.", $title, WATCHDOG_NOTICE);
    drupal_set_message(t("The '%title' toolbar has been updated.", $title));
  }
  $form_state['redirect'] = 'admin/build/toolbar';
}

/**
 * Confirmation page to delete a Toolbar
 *
 * We use this function to present a confirmation page to delete a toolbar and
 * all related shortcuts
 *
 * @param $name
 *  The toolbar to delete
 *
 * @see toolbar_load()
 * @see toolbar_delete_confirm_submit()
 *
 * @return
 * a confirmation page to delete a shortcut set
 */
function toolbar_delete_confirm(&$form_state, $toolbar) {
  $form['#toolbar'] = $toolbar;
  $caption = '';

  // Add warning with shortcut count
  $num_shortcuts = db_result(db_query("SELECT COUNT(*) FROM {menu_links} WHERE menu_name = '%s'", $toolbar['name']));
  if ($num_shortcuts) {
    $caption .= '<p>'.
      format_plural(
        $num_shortcuts,
        "<strong>Warning:</strong> There is currently 1 shortcut in toolbar '%title'. It will be deleted.",
        "<strong>Warning:</strong> There are currently @count shortcuts in toolbar '%title'. They will be deleted.", array('%title' => $toolbar['title'])
      ) .'</p>';
  }

  // Add warning with role and user usage
  // @todo insert warning if toolbar currently used by any user or role

  $caption .= '<p>'. t('This action cannot be undone.') .'</p>';
  return confirm_form($form, t('Are you sure you want to delete the toolbar %title?', array('%title' => $toolbar['title'])), 'admin/build/toolbar/'. $toolbar['name'], $caption, t('Delete'));
}

/**
 * Submit handler to delete a toolbar
 *
 * @see toolbar_delete_confirm()
 *
 * @ingroup forms
 */
function toolbar_delete_confirm_submit($form, &$form_state) {
  $toolbar = $form['#toolbar'];
  $form_state['redirect'] = 'admin/build/toolbar';

  // Delete all the shortcuts.
  db_query("DELETE FROM {menu_links} WHERE menu_name = '%s'", $toolbar['name']);
  menu_cache_clear_all();

  // Reset users and roles
  db_query("DELETE FROM {toolbar_user} WHERE name = '%s'", $toolbar['name']);
  db_query("DELETE FROM {toolbar_role} WHERE name = '%s'", $toolbar['name']);

  // Delete the toolbar itself
  db_query("DELETE FROM {toolbar_toolbar} WHERE name = '%s'", $toolbar['name']);

  $title = array('%title' => $toolbar['title']);
  // Inform everybody
  module_invoke_all('toolbar_delete_toolbar', $toolbar);
  watchdog('toolbar', "Deleted toolbar '%title' and all its shortcuts.", $title, WATCHDOG_NOTICE);

  drupal_set_message(t("The toolbar '%title' has been deleted.", $title));
}

/**
 * Toolbar export form.
 *
 *
 * @param $toolbar
 *  The toolbar to export
 *
 * @todo set all editor to not consider this textarea as HTML (especially CKEditor)
 *
 * @return
 *  Form array
 *
 * @ingroup forms
 */
function toolbar_export_form(&$form_state, $toolbar) {

  $form = array();
  $shortcuts = array();

  // get all set shortcuts
  $result = db_query("SELECT mlid FROM {menu_links} WHERE menu_name = '%s'", $toolbar['name']);
  while ( $link = db_fetch_array($result) ) {
    $link = menu_link_load($link['mlid']);
    $shortcuts[] = array(
      'link_path' => $link['link_path'],
      'link_title' => $link['link_title'],
      'weight' => $link['weight'],
    );
  }
  $data = '$toolbar = ' . var_export($shortcuts, TRUE) . ';';
  $lines = substr_count($data, "\n") + 1;

  $form['data'] = array(
    '#type' => 'textarea',
    '#title' => t('Data'),
    '#description' => 'Copy this value.',
    '#value' => $data,
    '#rows' => min($lines, 150),
  );

  return $form;
}


/**
 * Toolbart import form.
 *
 * @return
 *  Form array
 *
 * @see toolbar_import_form_validate()
 * @see toolbar_import_form_submit()
 * @ingroup forms
 */
function toolbar_import_form(&$form_state) {
  $form = array();

  $form['#insert'] = TRUE;
  $form['#validate'][] = 'toolbar_edit_form_validate';
  $form['#validate'][] = 'toolbar_import_form_validate';

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#maxsize' => TOOLBAR_MAX_NAME_LENGTH_UI,
    '#description' => t('The machine-readable name of this set. This name must contain only lowercase letters, numbers, and hyphens, and must be unique.'),
    '#required' => TRUE,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $toolbar['title'],
    '#description' => t('Specify title for this shortcut set.'),
    '#required' => TRUE,
  );

  $form['data'] = array(
    '#type' => 'textarea',
    '#title' => t('Toolbar export data'),
    '#description' => t('Paste toolbar export data as copied from the export form.'),
    '#rows' => 16,
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  return $form;
}

/**
 * Validation handler for Toolbar import form.
 *
 * @see toolbar_import_form()
 * @see toolbar_import_form_submit()
 *
 * @ingroup forms
 */
function toolbar_import_form_validate(&$form, &$form_state) {
  ob_start();
  eval($form_state['values']['data']);
  ob_end_clean();

  if ( empty($toolbar) ) {
    form_error($form['data'], t('Pasted data is not a valid toolbar export.'));
  }
  else {
    foreach ($toolbar as $shortcut) {
      if (
        !isset($shortcut['link_path']) || empty($shortcut['link_path']) ||
        !isset($shortcut['link_title']) || empty($shortcut['link_title']) ||
        !isset($shortcut['weight']) || '' == $shortcut['weight']
      ) {
        form_error($form['data'], t('Pasted data is not a valid toolbar export.'));
        break;
      }
    }
  }
  $form_state['values']['shortcuts'] = $toolbar;
}

/**
 * Submit handler for Toolbar shortcuts import form.
 *
 * Uses toolbar_edit_form_submit() to create new toolbar. Adds the minimal
 * requirements for new link and creates links with menu_link_save() for
 * the newly created toolbar.
 *
 * @see toolbar_edit_form_submit()
 * @see menu_link_save()
 * @see toolbar_import_form()
 * @see toolbar_import_form_validate()
 *
 * @ingroup forms
 */
function toolbar_import_form_submit(&$form, &$form_state) {
  foreach ($form_state['values']['shortcuts'] as $link) {
    $link['plid'] = 0;
    $link['module'] = 'toolbar';
    $link['menu_name'] = TOOLBAR_NAME_PREFIX . $form_state['values']['name'];
    menu_link_save($link);
  }
  toolbar_edit_form_submit($form, $form_state);
  drupal_set_message(t("The shortcuts have been imported."));
}
