/**
 * Custom JS for STARTERKIT theme
 */

Drupal.behaviors.landlord_watchlist = function(context){
  var url = window.location.href + '#map';
  $('.view-landlords .quicktabs_tabs li a.active').each(function(index) {
    if (url.indexOf($(this).attr('href')) == -1){
      $(this).removeClass('active').parent().removeClass('active');
    } else {
      $(this).addClass('active').parent().addClass('active');
    }
  });
  if (!$('.view-landlords .quicktabs_tabs li.active').length){
    $('.view-landlords .quicktabs_tabs li:first').addClass('active');
  }
  
  var action = $('#views-exposed-form-landlords-page-1').attr('action') + '#map';
  $('#views-exposed-form-landlords-page-1').attr('action', action);
  
  



  
  /**
   * If we're on the landlord page, and its a full page load put in place holder
   
  if(!($('body.ajax-gmap-clicked').length) && $('form#views-exposed-form-landlord-container-page-1').length) {
    $('body').addClass('landlords-only-gmap');
    $('.view-landlords .quicktabs_wrapper .quicktabs_main').prepend('<div class="landlord-choose-filters">Select a landlord from the list below to see their buildings mapped or click a tab above to display the worst buildings by borough.</a>');
  }*/
  
  /**
   * Click handler for landlords!
   
  
  $('.view-landlords .attachment-after .view-landlord-container table tr .show-buildings a').click(function() {
    if($('.view-landlords .quicktabs_wrapper .quicktabs_main div.gmap-gmap').length) {
      var $link = $(this);
      var dest = $link.attr('href');*/
      /**********************************
      
      Hey Jeff....
      Change this next line to: 
      var landlord = dest.substring(dest.indexOf('landlord=')+9, dest.length-4);
      When appropriate.
      
      *********************************
      var landlord = dest.substring(dest.indexOf('landlord=')+9, dest.length);
      $('.view-landlords .view-filters form#views-exposed-form-landlord-container-page-1 .views-exposed-widgets input#edit-landlord').val(landlord.replace('%20',' '));
      $('.view-landlords .view-filters form#views-exposed-form-landlord-container-page-1').submit();
      $('.view-landlords .attachment-after .view-landlord-container table tr .show-buildings.active').removeClass('active');
      $link.parent('.show-buildings').addClass('active');
      if(typeof scrollTo == 'function') { 
        $.scrollTo($('.view-landlords form#views-exposed-form-landlord-container-page-1'),1500);
		  }
		  //remove the first-page-load tag from body
		  $('body').removeClass('landlords-only-gmap').addClass('ajax-gmap-clicked');
      return false;
    }
  });*/
  
  /**
   * Click handler for boroughs!
   
  $('.view-landlords .quicktabs_wrapper ul.quicktabs_tabs li a').click(function() {
    if($('.view-landlords .quicktabs_wrapper .quicktabs_main div.gmap-gmap').length && $('form#views-exposed-form-landlord-buildings-page-1').length) {
      var $link = $(this);
      var dest = $link.attr('href');
      if(dest.indexOf('borough%5B%5D=') > 0) {
        var borough = dest.substring(dest.indexOf('borough%5B%5D=')+14, dest.length-4);
        $select = $('.view-landlords .view-filters form#views-exposed-form-landlord-buildings-page-1 .views-exposed-widgets .views-exposed-widget #edit-borough-wrapper select#edit-borough').val(borough.replace('%20',' '));
	      //console.log($select.find('option:selected').html());
	      var index = $('.view-landlords .view-filters form#views-exposed-form-landlord-buildings-page-1 .views-exposed-widgets .views-exposed-widget #edit-borough-wrapper select#edit-borough option').index($select.find('option:selected'));
	      $('.ui-dropdownchecklist-dropcontainer:eq(0) .ui-dropdownchecklist-item input').attr('checked', false);
	      $('.ui-dropdownchecklist-dropcontainer:eq(0) .ui-dropdownchecklist-item:eq('+ index +') input').attr('checked', true);
        $('#edit-borough-wrapper .ui-dropdownchecklist-text').text(borough).attr('title', borough.replace('%20',' '));
        
	      $('.view-landlords .view-filters form#views-exposed-form-landlord-buildings-page-1').submit();
	      $('.view-landlords .quicktabs_wrapper ul.quicktabs_tabs li.active').removeClass('active').children('active').removeClass('active');
	      $link.addClass('active').parent('li').addClass('active');
	      // String magic for getting latitude/longitude... could probably be more concise
	      var boroughVal = Drupal.settings.landlord_watchlist_coords[borough.replace('%20',' ')];
	      boroughVal = boroughVal.substring(boroughVal.indexOf('center=')+7, boroughVal.length);
	      var latitude = boroughVal.substring(0,boroughVal.indexOf(','));
	      var longitude = boroughVal.substring(boroughVal.indexOf(',')+1,boroughVal.indexOf(' '));
	      Drupal.gmap.getMap('auto1map').map.panTo(new GLatLng(latitude,longitude));
	      return false;
      }
    }
  });*/
}

// Show Google StreetView Picture
function streetview_click($this){
  $picture = $this.parent().find('.streetview-picture');
  if (!$picture.hasClass('streetview-processed')){
    $picture.addClass('streetview-processed').append('<img src="' + $this.attr('href') + '" alt="Google Streeview of Building" /><a href="http://www.google.com/streetview" target="_blank" class="google-streetview-link">Picture provided by Google StreetView</a><a href="#" class="streetview-close">Close</a>');
    $picture.find('.streetview-close').click(function(){
      $(this).parent().hide();
      return false;
    });
  }
  $picture.show();
  return false;
}
