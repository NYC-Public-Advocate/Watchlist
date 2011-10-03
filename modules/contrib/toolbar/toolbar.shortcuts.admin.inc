<?php

/**
 * @file
 * Handles shortcut administration functions and forms for Toolbar module
 *
 * Functions and forms to overview, order, create, edit and delete toolbar shortcuts.
 */


/**
 * Form to overview and order toolbar shortcuts.
 *
 * Presents an overview page with all the shortcut in the system for given toolbar
 *
 * @param $toolbar
 *  The toolbar.
 *
 * @return
 *  A form with all shorcuts in the toolbar.
 *
 * @see toolbar_shortcuts_overview_form_submit()
 * @see theme_toolbar_shortcuts_overview_form()
 * @ingroup forms
 */
function toolbar_shortcuts_overview_form(&$form_state, $toolbar) {

  $destination = drupal_get_destination();
  $form = array();
  $form['weight'] = array('#tree' => TRUE);

  $shorcuts = _toolbar_get_shortcuts($toolbar);
  foreach ($shorcuts as $shortcut) {
    $form['weight'][$shortcut['mlid']] = array(
      '#type' => 'weight',
      '#default_value' => $shortcut['weight'],
      // drag group
      '#attributes' => array('class' => 'toolbar-links-order-weight')
    );
    $form['id'][$shortcut['mlid']] = array(
      '#type' => 'hidden',
      '#value' => $shortcut['mlid'],
    );

    // we need the generated path as in rendered toolbar
    $link = menu_link_load($shortcut['mlid']);

    $form['title'][$shortcut['mlid']] = array(
      '#type' => 'markup',
      '#value' => l(t($shortcut['link_title']), $link['href']),
    );

    $form['operations'][$shortcut['mlid']] = array(
      '#type' => 'markup',
      '#value' =>
        l(t('edit'), "admin/build/toolbar/{$toolbar['name']}/shortcut/{$shortcut['mlid']}/edit", array('query' => $destination))
        . '&nbsp;'
        . l(t('delete'), "admin/build/toolbar/{$toolbar['name']}/shortcut/{$shortcut['mlid']}/delete", array('query' => $destination))
    );
  }

  $form['#toolbar'] = $toolbar;
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save configuration'));

  return $form;
}

/**
 * Submit handler for toolbar_shortcuts_overview_form()
 *
 * @see toolbar_shortcuts_overview_form()
 * @ingroup forms
 */
function toolbar_shortcuts_overview_form_submit($form, &$form_state) {
  foreach ($form_state['values']['weight'] as $mlid => $weight) {
    // update only modified items
    if ( $form['weight'][$mlid]['#default_value'] != $weight ) {
      $shorcut = menu_link_load($mlid);
      $shorcut['weight'] = $weight;
      menu_link_save($shorcut);
    }
  }

  drupal_set_message(t('The shortcut ordering has been updated.'));
}

/**
 * Theme handler for toolbar_shortcuts_links_admin_form()
 *
 * @see theme_toolbar_shortcuts_admin_form()
 * @ingroup themable
 */
function theme_toolbar_shortcuts_overview_form($form) {
  $rows = array();
  foreach (element_children($form['title']) as $mlid) {
    if ( is_array( $form['title'][$mlid] ) ) {
      $rows[] = array(
        'data' => array(
          drupal_render($form['title'][$mlid]),
          drupal_render($form['operations'][$mlid]),
          drupal_render($form['weight'][$mlid]) . drupal_render($form['id'][$mlid]),
        ),
        'class' => 'draggable'
      );
    }
  }

  if (empty($rows)) {
    $empty_message = t("There are no shortcut items yet, !add.", array("!add" => l(t("Add shortcut"), "admin/build/toolbar/{$form['#toolbar']['name']}/shortcut/add")));
    $rows[] = array(array('data' => $empty_message, 'colspan' => '3'));
  }

  $header = array(t('Title'), array('data' => t('Operations'), 'colspan' => 2) );
  $output = theme('table', $header, $rows, array('id' => 'toolbar-links-order'));
  $output .= drupal_render($form);

  drupal_add_tabledrag('toolbar-links-order', 'order', 'sibling', 'toolbar-links-order-weight');

  return $output;
}

function toolbar_shortcut_edit_form(&$form_state, $toolbar, $shortcut = NULL) {

  $form['#toolbar'] = $toolbar;

  if ( is_null($shortcut) ) {
    // insert

    // Append shortcut at the end of menu
    $max_weight = db_result(db_query("SELECT MAX(weight) FROM {menu_links} WHERE menu_name ='%s'", $toolbar['name']));
    if ( FALSE === $max_weight ) {
      // if first item
      $max_weight = 0;
    }
    else {
      $max_weight++;
    }

    $shortcut = array(
      'mlid'        => 0,
      'link_title'  => '',
      'link_path'   => '',
      'weight'      => $max_weight,
    );
  }

  $form['mlid'] = array(
    '#type' => 'hidden',
    '#value' => $shortcut['mlid']
  );

  $form['link_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $shortcut['link_title'],
    '#maxlength' => 128,
    '#size' => 45,
    '#description' => t('Specify a title for this shortcut.'),
    '#required' => TRUE,
  );

  $form['link_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#default_value' => $shortcut['link_path'],
    '#maxlength' => 128,
    '#size' => 45,
    '#description' => t('Specify a path for this shortcut.'),
    '#required' => TRUE,
  );

  $form['weight'] = array(
    '#type' => 'hidden',
    '#value' => $shortcut['weight'],
  );

  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));

  return $form;
}

/**
 * Handles toolbar_shortcut_edit_form() validation
 *
 * If shortcuts points to internal path and this path is not correct the link
 * won't be saved. We need to validate this.
 *
 * @return
 *  Error message if validation don't pass
 *
 * @see toolbar_shortcut_edit_form()
 * @see menu_path_is_external()
 * @see menu_valid_path()
 * @ingroup forms
 */
function toolbar_shortcut_edit_form_validate($form, &$form_state) {

  // alias lookup
  $normal_path = drupal_get_normal_path($form_state['values']['link_path']);
  if ($form_state['values']['link_path'] != $normal_path) {
    $form_state['values']['link_path'] = $normal_path;
  }

  if (!menu_path_is_external($form_state['values']['link_path'])) {
    if (!trim($form_state['values']['link_path']) || !menu_valid_path($form_state['values'])) {
      form_set_error('link_path', t("The path '@link_path' is either invalid or you do not have access to it.", array('@link_path' => $form_state['values']['link_path'])));
    }
  }
}

/**
 * Submit handler for the toolbar_shortcut_edit_form()
 *
 * Build the $shortcut array and then save it as a link in the menu system
 * using menu_link_save()
 *
 * @return
 *  A success message
 *
 * @see toolbar_shortcut_edit_form()
 * @see toolbar_shortcut_edit_form_validate()
 * @see menu_link_save()
 * @ingroup forms
 */
function toolbar_shortcut_edit_form_submit($form, &$form_state) {
  $toolbar = $form['#toolbar'];
  $shortcut = $form_state['values'];

  $link = array(
    'mlid' => $shortcut['mlid'],
    // reset plid
    'plid' => 0,
    'menu_name' => $toolbar['name'],
    'link_path' => $shortcut['link_path'],
    'link_title' => $shortcut['link_title'],
    'module' => 'toolbar',
    'weight' => $shortcut['weight'],
  );
  menu_link_save($link);

  // Inform everybody

  $title = array('%title' => $shortcut['link_title']);
  if ( 0 == $shortcut['mlid'] ) {
    module_invoke_all('toolbar_insert_shortcut', $toolbar, $shortcut);
    watchdog('toolbar', "The shortcut '%title' created.", $title, WATCHDOG_NOTICE);
    drupal_set_message(t("The shortcut '%title' has been created.", $title));
  }
  else {
    module_invoke_all('toolbar_update_shortcut', $toolbar, $shortcut);
    watchdog('toolbar', "The shortcut '%title' updated.", $title, WATCHDOG_NOTICE);
    drupal_set_message(t("The shortcut '%title' has been updated.", $title));
  }

  $form_state['redirect'] = "admin/build/toolbar/{$toolbar['name']}/shortcut";
}


/**
 * Confirmation form to delete a shortcut
 *
 * present a confirmation form to delete a shortcut.
 *
 * @param $toolbar
 *  An array of shortcut's toolbar
 * @param $shortcut
 *  An array of the shortcut to delete
 *
 * @return
 *  A confirmation form to delete a shortcut
 *
 * @see confirm_form()
 * @see toolbar_shortcut_delete_confirm_submit()
 * @ingroup forms
 */
function toolbar_shortcut_delete_confirm($form_state, $toolbar, $shortcut) {
  $form['#toolbar'] = $toolbar;
  $form['#shortcut'] = $shortcut;

  return confirm_form($form,
    t("Are you sure you want to delete the shortcut '%title'?", array('%title' => check_plain($shortcut['link_title']))),
    "admin/build/toolbar/{$toolbar['name']}/shortcut");
}

/**
 * Submit handler to delete a shortcut
 *
 * @see toolbar_shortcut_delete_confirm()
 * @see menu_link_delete()
 * @ingroup forms
 */
function toolbar_shortcut_delete_confirm_submit($form, &$form_state) {

  menu_link_delete($form['#shortcut']['mlid']);

  // Inform everybody
  $title = array('%title' => $form['#shortcut']['link_title']);
  module_invoke_all('toolbar_delete_shortcut', $form['#toolbar'], $form['#shortcut']);
  watchdog('toolbar', "The shortcut '%title' deleted.", $title, WATCHDOG_NOTICE);
  drupal_set_message(t("The shortcut '%title' has been deleted.", $title));

  $form_state['redirect'] = "admin/build/toolbar/{$form['#toolbar']['name']}/shortcut";
}
