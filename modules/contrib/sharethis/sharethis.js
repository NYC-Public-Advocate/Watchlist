// $Id: sharethis.js,v 1.1.2.4 2009/06/05 19:58:57 robloach Exp $

/**
 * Drupal ShareThis behaviors.
 */
Drupal.behaviors.shareThis = function(context) {
  // Retrieve the ShareThis URL code, if desired.
  var code = Drupal.settings.sharethisUrl || null;

  // Process each of the ShareThis links.
  $('.sharethis-link:not(.sharethis-link-processed)', context).addClass('sharethis-link-processed').sharethis(code);
};
