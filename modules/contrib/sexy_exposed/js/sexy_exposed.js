// $Id: sexy_exposed.js,v 1.1.2.1 2010/09/09 10:18:23 zserno Exp $
Drupal.behaviors.sexyExposed = function (context) {
  var settings = Drupal.settings.sexyExposed;
  $.each(settings, function(key, element) {
    $key = $(key);
    // Adjust max height if maximum number of visible items is set.
    if (element > 0) {
      height = sexyExposedCalculateMaxHeight($key, element);
      $key.dropdownchecklist({maxDropHeight: height});
    }
    else if (element == 0) {
      $key.dropdownchecklist();
    }
  });
};

/**
 * Calculate max height value in pixels from number of elements.
 */
function sexyExposedCalculateMaxHeight(key, element) {
  // We must build a temporary dropdownchecklist to get height of one item.
  key.dropdownchecklist();
  var height = $('.ui-dropdownchecklist-item:first-child').height();
  key.dropdownchecklist("destroy");
  return element * height;
}
