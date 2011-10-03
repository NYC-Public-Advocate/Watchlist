<?php

/**
 * @file
 * Handles configuration settings form for Toolbar module
 */

/**
 * Handles Toolbar settings form display
 *
 * @return
 *  A form
 *
 * @see toolbar_settings_form_submit()
 * @see theme_toolbar_settings_form()
 * @ingroup forms
 */
function toolbar_settings_form(&$form_state) {


  // convert toolbar names as numeric
  // avoid 'Illegal choice...' problem with form validation

  $toolbars = _toolbar_get_toolbars();
  $toolbars_options[0] = t('disabled');
  $id = 1;
  while ( list($key, $value) = each($toolbars) ) {
    $toolbars_id[$key] = $id;
    $toolbars_options[$id++] = $value;
  }

  $max_weight = db_result(db_query("SELECT MIN(weight) FROM {toolbar_role}"));
  if ( FALSE === $max_weight ) {
    // if first item
    $max_weight = 0;
  }
  else {
    $max_weight++;
  }

  $weight = array();
  $toolbar_role = array();
  $roles = user_roles();

  $key = 0;

  // set defaults, and set role title
  foreach ($roles as $rid => $role) {
    $result = db_query('SELECT * FROM {toolbar_role} WHERE rid=%d', $rid);
    $row = db_fetch_array($result);
    if ( FALSE === $row ) {
      $toolbar_role[$key] = array(
        'rid'     => $rid,
        'name'    => 0,
        'weight'  => ++$max_weight,
        'title'   => $role
      );
    }
    else {
      $toolbar_role[$key] = array(
        'rid'     => (int)$row['rid'],
        'name'    => $toolbars_id[$row['name']],
        'weight'  => (int)$row['weight'],
        'title'   => $role
      );
    }
    $weight[$key] = $toolbar_role[$key]['weight'];
    $key++;
  }

  // sort by weight
  array_multisort($weight, SORT_ASC, $toolbar_role);
  $form = array();

  // save some data, no need to fetch them again
  $form['#toolbars_id'] = $toolbars_id;

  $form['roles']['#tree'] = TRUE;
  $delta = count($roles);

  foreach ($toolbar_role as $item) {
    $rid = $item['rid'];
    $form['roles'][$rid]['title'] = array(
      '#type' => 'markup',
      '#value' => check_plain($item['title']),
    );
    $form['roles'][$rid]['toolbar'] = array(
      '#type' => 'select',
      '#default_value' => $item['name'],
      '#options' => $toolbars_options
    );
    $form['roles'][$rid]['weight'] = array(
      '#type'           => 'weight',
      '#delta'          => $delta,
      '#default_value'  => $item['weight'],
    );
    $form['roles'][$rid]['id'] = array(
      '#type' => 'hidden',
      '#value' => $rid,
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration')
  );

  return $form;
}

/**
 * Submit handler for toolbar_settings_form()
 *
 * @see toolbar_shortcuts_settings_form()
 * @ingroup forms
 */
function toolbar_settings_form_submit($form, &$form_state) {
  foreach ($form_state['values']['roles'] as $rid => $values) {

    $current = $form['roles'][$rid]['toolbar']['#default_value'];
    if ( '0' == $current ) {
      $current = NULL;
    }

    $new = $values['toolbar'];
    if ( '0' == $new ) {
      $new = NULL;
    }
    else {
      $new = array_search($new, $form['#toolbars_id']);
    }

    if ( is_null($current) ) {
      if ( !is_null($new) ) {
        // if current value is not set (null) and toolbar changed (not null), insert
        db_query("INSERT INTO {toolbar_role} VALUES(%d, '%s', %d)", $rid, $new, $values['weight']);
      }
    }
    else {
      if ( is_null($new) ) {
        // if current value is set (not null) and new value is disabled(not null) - delete
        db_query("DELETE FROM {toolbar_role} WHERE rid=%d ", $rid);

      }
      else {
        // if current value is set (not null) and new value is different (not 'current'),
        // but not disabled (not null) - update
        db_query("UPDATE {toolbar_role} SET name='%s', weight=%d WHERE rid=%d", $new, $values['weight'], $rid);
      }
    }
  }
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Theme handler for toolbar_settings_form()
 *
 * @see theme_toolbar_settings_form()
 * @ingroup themable
 */
function theme_toolbar_settings_form($form) {
  $rows = array();
  foreach (element_children($form['roles']) as $rid) {
    $element = &$form['roles'][$rid];
    $row = array();

    $element['weight']['#attributes']['class'] = 'weight-group';
    $element['itemid']['#attributes']['class'] = 'itemid';
    $row[] = drupal_render($element['title']);
    $row[] = drupal_render($element['toolbar']);
    $row[] = drupal_render($element['weight']) . drupal_render($element['id']);

    $rows[] = array('data' => $row, 'class' => 'draggable');
  }
  if (empty($rows)) {
    $empty_message = t('No toolbars found, !add.', array('!add' => l(t('Add toolbar'), 'admin/build/toolbar/add')));
    $rows[] = array(array('data' => $empty_message, 'colspan' => '3'));
  }
  $header = array(t('Role'), t('Toolbar'), t('Weight'));
  drupal_add_tabledrag('toolbar_roles_order_table', 'order', 'sibling', 'weight-group');
  $output = theme('table', $header, $rows, array('id' => 'toolbar_roles_order_table'));
  $output .= drupal_render($form);

  return $output;
}
