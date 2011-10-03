<?php
// $Id: sharethis.admin.inc,v 1.1.2.1 2009/06/05 19:58:57 robloach Exp $

/**
 * @file
 * Provides the administration settings for ShareThis.
 */

/**
 * Menu callback; Settings administration.
 */
function sharethis_admin_settings() {
  $form['sharethis_code'] = array(
    '#type' => 'textarea',
    '#title' => t('Code'),
    '#default_value' => variable_get('sharethis_code', ''),
    '#description' => t('The <a href="@code">Get the Button code</a> provided by ShareThis. If this is not given, the default one will be used.', array('@code' => 'http://sharethis.com/publishers/getbutton/')),
  );
  $form['sharethis_sharethis_this_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node types'),
    '#description' => t('Choose which node types to display the ShareThis button on.'),
    '#default_value' => variable_get('sharethis_sharethis_this_node_types', array()),
    '#options' => node_get_types('names'),
  );
  $form['sharethis_teaser'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display in teaser view'),
    '#description' => t('If enabled, the ShareThis links will appear in node teasers. If disabled, they will only appear on the full node page.'),
    '#default_value' => variable_get('sharethis_teaser', 1),
  );
  $form['sharethis_sharethis_this_where'] = array(
    '#type' => 'select',
    '#title' => t('Where to display'),
    '#description' => t('Select where you would like the ShareThis link to appear.'),
    '#default_value' => variable_get('sharethis_sharethis_this_where', 'links'),
    '#options'=> array(
      'links' => t('Links'),
      'nodes' => t('Nodes'),
    ),
  );
  $form['sharethis_sharethis_weight'] = array(
    '#type' => 'weight',
    '#delta' => 10,
    '#description' => t('Only applies when node type display is selected.'),
    '#title' => t('Weight'),
    '#default_value' => variable_get('sharethis_sharethis_weight', 0),
  );
  return system_settings_form($form);
}
