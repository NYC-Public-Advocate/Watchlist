/**
 * Custom JS for STARTERKIT theme
 */

Drupal.behaviors.landlord_watchlist = function(context){
  $('.tabs.primary a[href=/import/landlord_watchlist/delete-items]').attr('href', '/admin/landlord-watchlist/clear');
  $('.tabs.primary a[href=/admin/content/taxonomy/1/add/term]').attr('href', '/node/add/neighborhood?destination=admin/content/taxonomy/1');
}
