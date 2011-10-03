<?php

/**
 * @file
 * Handles user related administration functions and forms for Toolbar module
 */

function toolbar_user_select_toolbar_form(&$form_state, $user) {

  $toolbars = _toolbar_get_toolbars();

  $user_toolbar = _toolbar_get_user_selected_toolbar($user);
  $role_toolbar = _toolbar_get_role_selected_toolbar($user);

  $toolbar = 0;

  array_unshift($toolbars, t('Role default toolbar'), t('None'));

  if ( $role_toolbar ) {
    $toolbars[0] .= ' (' . $toolbars[$role_toolbar] . ')';
    unset($toolbars[$role_toolbar]);
    $toolbar = 0;
  }

  if ( $user_toolbar ) {
    if (TOOLBAR_NAME_DISABLED === $user_toolbar) {
      $toolbar = 1;
    }
    else {
      $toolbar = $user_toolbar;
    }
  }

  $form['toolbar'] = array(
    '#title'          => t('Select toolbar'),
    '#type'           => 'select',
    '#default_value'  => $toolbar,
    '#options'        => $toolbars
  );

  $form['uid'] = array(
    '#type'   => 'hidden',
    '#value'  => $user->uid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save')
  );

  return $form;
}

function toolbar_user_select_toolbar_form_submit($form, &$form_state) {

  $uid            = $form_state['values']['uid'];
  $old            = $form['toolbar']['#default_value'];
  $new            = $form_state['values']['toolbar'];

  // Toolbar value has changed.
  if ( $new !== $old ) {
    if ( '0' == $new ) {
      // Role default toolbar selected, delete from {user} table.
      db_query("DELETE FROM {toolbar_user} WHERE uid=%d ", $uid);
    }
    else {
      if ( '1' == $new ) {
        // Toolbar is 'None', get the 'None' toolbar name.
        $new = TOOLBAR_NAME_DISABLED;
      }
      if ( 0 === $old ) {
        // No toolbar configured before, insert as new.
        db_query("INSERT INTO {toolbar_user} VALUES(%d, '%s')", $uid, $new);
      }
      else {
        // User has selected different toolbar or has disabled toolbar, update.
        db_query("UPDATE {toolbar_user} SET name='%s' WHERE uid=%d", $new, $uid);
      }
    }
  }
  drupal_set_message(t('The configuration have been saved.'));
}
