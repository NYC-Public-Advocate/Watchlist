Watchlist Profile
Based on the NYC Public Advocate's Landlord Watchlist: http://advocate.nyc.gov/landlord-watchlist
=========

This Drupal 6 installation profile creates a Google-maps enabled mapping program for watchlists.


The Watchlist Profile is a joint effort between The New York City Public Advocate 
(advocate.nyc.gov), Albatross Digital (albatrossdigital.com), and Civic Commons
(civiccommons.org)

For a working demo, visit http://watchlist.albatrossdemos.com.


Installation
============

Download and extract the tarball from GitHub.

Install Drupal as outlined in the Drupal INSTALL.txt file.

  => Be sure to select the Watchlist profile


Working with the Source
=======================

The Watchlist is packaged as a profile with a Drush .make file.  To download the code from
the source, all you need to do is download the profile tarball from GitHub and run the .make
file:
  
  git clone ...
  mkdir drupal
  cp watchlist/watchlist.make drupal
  mv watchlist drupal/watchlist
  drush make drupal/watchlist.make
  
For more information on Drush Make, visit http://drupal.org/project/drush_make.


Contributing: Working with Features
=====================================
If you are interested in making enhancements to the Watchlist, we highly recommend contributing back
to the project.

The Watchlist is packaged as five feature modules, the Drupal 6 modified Bartik theme, and a
Drupal installation profile.  The main module, landlord_watchlist contains all of the
content types, views, and logic in the .module file to run the Watchlist.  The other four modules
contain support code and configuration for the profile.

Contributors
============
- jlyon (Jeff Lyon, <jeff@albatrossdigital.com>)
