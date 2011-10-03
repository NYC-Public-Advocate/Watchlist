<?php
// $Id$

/**
 * Adding HTML classes to <body> tag for styling.
 */
function bartik_mod_body_class($is_front, $logged_in, $is_admin, $node, $left, $right) {
  $class = array();

  // Checks if current page is front or not.
  if ($is_front) {
    $class[] = 'front-page';
  }
  else {
    $class[] = 'not-front-page';
  }

  // Checks whether user is logged in or not.
  if ($logged_in) {
    $class[] = 'logged-in';
  }
  else {
    $class[] = 'not-logged-in';
  }

  // Checks whether user has permission to access administration pages.
  if ($is_admin) {
    $class[] = 'admin';
  }
  else {
    $class[] = 'not-admin';
  }

  // Add arg(0) for easier styling depending on the current page type.
  // Eg: node, admin, user
  // Illegal characters are removed and prevented from breaking the class names.
  $class[] = preg_replace('![^abcdefghijklmnopqrstuvwxyz0-9-_]+!s', '', 'page-' . drupal_strtolower(arg(0)));

  // Add the node type on individual node page.
  if (isset($node->type)) {
    $class[] = 'node-type-' . $node->type;
  }

  // Layout classes.
  if ($left != '' && $right != '') {
    $class[] = 'sidebar-left-and-right';
  }
  else {
    if ($left != '') {
      $class[] = 'sidebar-left';
    }
    elseif ($right != '') {
      $class[] = 'sidebar-right';
    }
  }

  return implode(' ', $class);
}

/**
 * Override theme_username() function.
 * Removes the text '(not verified)' for anonymous users.
 */
function bartik_mod_username($object) {
  if ($object->uid && $object->name) {
    if (drupal_strlen($object->name) > 20) {
      $name = drupal_substr($object->name, 0, 15) . '...';
    }
    else {
      $name = $object->name;
    }

    if (user_access('access user profiles')) {
      $output = l($name, 'user/' . $object->uid, array('attributes' => array('title' => t('View user profile.'))));
    }
    else {
      $output = check_plain($name);
    }
  }
  else if ($object->name) {
    if (!empty($object->homepage)) {
      $output = l($object->name, $object->homepage, array('attributes' => array('rel' => 'nofollow')));
    }
    else {
      $output = check_plain($object->name);
    }
  }
  else {
    $output = check_plain(variable_get('anonymous', t('Anonymous')));
  }

  return $output;
}
