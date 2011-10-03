<?php
// $Id$
/* Copyright (C) 2011  Jeff Lyon, NYC Public Advocate, <jeff@albatrossdigital.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */



/**
 * Return a description of the profile for the initial installation screen.
 *
 * @return
 *   An array with keys 'name' and 'description' describing this profile,
 *   and optional 'language' to override the language selection for
 *   language-specific profiles, e.g., 'language' => 'fr'.
 */
function watchlist_profile_details() {
  return array(
    'name' => 'Watchlist',
    'description' => 'A clone of the NYC Public Advocate\'s <a href="http://advocate.nyc.gov/landlord-watchlist">Landlord Watchlist</a>. Created by <a href="Albatross Digital">Albatross Digital</a>.',
  );
}

/**
 * Return a list of tasks that this profile supports.
 *
 * @return
 *   A keyed array of tasks the profile will perform during
 *   the final stage. The keys of the array will be used internally,
 *   while the values will be displayed to the user in the installer
 *   task list.
 */
function watchlist_profile_task_list() {
  return array(
   // 'dept-info' => st('Departmental Info'),
   // 'support-message' => t('Support'),
  );
}

/**
 * Return an array of the modules to be enabled when this profile is installed.
 *
 * The following required core modules are always enabled:
 * 'block', 'filter', 'node', 'system', 'user'.
 *
 * @return
 *  An array of modules to be enabled.
 */
function watchlist_profile_modules() {
  return array(
    // Enable optional core modules.
      'dblog', 'color', 'help', 'taxonomy', 'search', 'menu', 
      'webform', 'aggregator',  'openid', 'path', 'upload',  //'contact',
      //'statistics', 'throttle', 'comment', 'ping',
      //'blog', 'book', 'forum', 'poll', 'profile', 
   
    // Enable contributed modules
      'admin', 'backup_migrate', //'admin_menu',
    // CCK
      'content', 'content_copy', 'email', 'fieldgroup', 'filefield', 'imagefield', 'nodereference', 'optionwidgets', 'text', 'number', 'userreference',
    // imageCache
      'imageapi', 'imageapi_gd', 'imagecache', 'imagecache_ui', 
    // mail
      //'smtp', 

    //context
      'context', 'context_ui',
    //features
      'features',
    
    // util
      //'system_module', 'util', 
    
    // token
      'token', // 'token_actions', 'logintoboggan',
      
    // Printer, e-mail and PDF versions
      //'print', 'print_pdf', 'print_mail', 
    // SEO (from SEO checklist)
      //'seochecklist', 'globalredirect', 'googleanalytics', 'pathauto', 'nodewords', 'page_title', 'path_redirect',  'service_links', 
      //'xmlsitemap', //'xmlsitemap_engines', 'xmlsitemap_menu',
    // User interface
      //'wysiwyg', 
    // Views
     'views', 'views_export', 'views_ui',
    // Devel
      'devel', //'macro',
    
    // strongarm
      'ctools', 'strongarm',
      
    // watchlist-specific
      'toolbar', 'location', 'location_node', 'gmap', 'gmap_location', 'gmap_taxonomy', 'taxonomynode', 'sexy_exposed', 'uuid', 
      'uuid_features', 'libraries', 'jquery_ui', 'vertical_tabs', 'feeds', 'feeds_ui', 'location_feeds', 'job_scheduler', 'login_destination', 
      
    // watchlist features
     'landlord_watchlist', 'landlord_watchlist_dashboard',  'landlord_watchlist_profile', 'landlord_watchlist_content', 'landlord_watchlist_dummy_data',
     //optional
       //'service_links', 'site_map',
       //'xmlsitemap_node', 'xmlsitemap_term', 'xmlsitemap_user',  
  );
}

/**
 * Perform final installation tasks for this installation profile.
 * Most of the heavy lifting is done with features.
 */
function watchlist_profile_tasks(&$task, $url) {
  // Set theme
  variable_set('theme_default', 'bartik_mod');
  variable_set('site_frontpage', 'landlord-watchlist');
  variable_set('gmap_default', array(
    'width' => '900px',
    'height' => '500px',
    'latlong' => '40.72280306615735,-73.99497985839844',
    'zoom' => 11,
  ));
  variable_set('taxonomynode_node_operations', 1);
  
  // login destination
  variable_set('ld_url_destination', 'admin/dashboard');
  variable_set('ld_destination', 0);
  
  variable_set('search_cron_limit', 500);
  
  variable_set('site_footer', 'Landlord data is aggregated by first and last name based on data from the New York City Department of Housing Preservation and Development (HPD). Errors may occur when landlords have filed paperwork using more than one name or if two landlords file paperwork using similar names. If you notice an error, please email GetHelp@pubadvocate.nyc.gov or call (212) 669-7200.');
  variable_set('site_name', 'Landlord Watchlist');
  variable_set('location_geocode_us', 'google');
 
  // Update the menu router information.
  menu_rebuild();
}


/**
 * Implementation of hook_form_alter().
 *
 * Allows the profile to alter the site-configuration form. This is
 * called through custom invocation, so $form_state is not populated.
 */
function watchlist_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'install_configure') {
    // Set default for site name field.
    $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  }
}
