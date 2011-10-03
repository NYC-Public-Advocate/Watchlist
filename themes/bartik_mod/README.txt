$Id$

Installation
------------
1.  Unpack the downloaded file, place the entire theme folder in your Drupal
    installation under any one of the following directory:

      sites/all/themes         - Making it available to the default Drupal site
                                 and to all Drupal sites in a multi-site
                                 configuration.
      sites/default/themes     - Making it available to only the default Drupal
                                 site.
      sites/example.com/themes - Making it available to only the example.com
                                 site if there is a
                                 sites/example.com/settings.php configuration
                                 file.

2.  Log in as administrator on your Drupal site and go to Administer > Site
    building > Themes (admin/build/themes) and set it to the default theme.

Optional
--------
1.  If your theme comes with drop down menu functionality, make sure that every
    menu item is set to Expanded.

      Primary links   - admin/build/menu-customize/primary-links
      Secondary links - admin/build/menu-customize/secondary-links
      Custom menus    - admin/build/menu-customize/<menu_name>

2.  For themes that allow configurable settings, navigate to
    admin/build/themes/settings/<theme_name> for more details.

3.  If you're experiencing problems with your theme, kindly visit
    admin/settings/performance and click on the button 'Clear cached data' and
    refresh your web browser.


For further theme-related support or enquiries, please send an email to
<leow@kahthong.com> or visit http://kahthong.com/contact
