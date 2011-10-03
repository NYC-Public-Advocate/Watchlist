// $Id$

$(function() {
  // Initialise Superfish drop down menu.
  $('#primary ul.menu').superfish({
    delay: 600,  // 1000 miliseconds is 1 second, 600 is 0.6 seconds delay.
    animation: {opacity: 'toggle'},  // Same as jQuery's .animate() function. See jQuery's API for more animations.
    speed: 'normal',  // 'slow', 'normal', 'fast'.
    autoArrows: false,
    dropShadows: false,
    disableHI: false  // Set to true to disable hoverIntent detection or delayed event trigger.
  });

  // Search box focus and blur events.
  var searchThemeFormText = Drupal.t('Search this site');
  $('#search-theme-form .form-text').val(searchThemeFormText);
  $('#search-theme-form .form-text').focus(function() {
    if ($(this).val() == searchThemeFormText) $(this).val('');
    $(this).css('color', '#333');
  });
  $('#search-theme-form .form-text').blur(function() {
    if ($(this).val() == '') $(this).val(searchThemeFormText);
    $(this).css('color', '#a5a5a5');
  });
  // Search box do not search with the <searchThemeFormText> variable string.
  $('#search-theme-form').submit(function(e) {
    if ($(this).find('.form-text').val() == searchThemeFormText) {
      $(this).find('.form-text').focus().select();
      return false;
    } else {
      return true;
    }
  });
});
