; $Id$
;
; Copyright (C) 2011  Jeff Lyon, Albatross Digital, <jeff@albatrossdigital.com>
; 
; This program is free software: you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation, either version 3 of the License, or
; (at your option) any later version.
; 
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.
; 
; You should have received a copy of the GNU General Public License
; along with this program.  If not, see <http://www.gnu.org/licenses/>
;
; Watchlist Profile Makefile
; ----------------

; Core version
; ------------
core = 6.x

; API version
; ------------
api = 2

; Core project
; ------------
; In order for your makefile to generate a full Drupal site, you must include
; a core project. This is usually Drupal core, but you can also specify
; alternative core projects like Pressflow. Note that makefiles included with
; install profiles *should not* include a core project.

projects[] = drupal
projects[] = admin
projects[] = computed_field
projects[] = draggableviews
projects[] = filefield
projects[] = imageapi
projects[] = jquery_ui
projects[] = openlayers
projects[] = taxonomy_node
projects[] = uuid_features
projects[] = views_bulk_operations
projects[] = admin_menu
projects[] = context
projects[] = email
projects[] = gmap
projects[] = imagecache
projects[] = libraries
projects[] = sexy_exposed
projects[] = token
projects[] = vertical_tabs
projects[] = views_customfield
projects[] = backup_migrate
projects[] = ctools
projects[] = features
projects[] = google_analytics
projects[] = imagefield
projects[] = location
projects[] = sharethis
projects[] = toolbar
projects[] = views
projects[] = webform
projects[] = cck
projects[] = devel
projects[] = feeds
projects[] = image
projects[] = job_scheduler
projects[] = location_feeds
projects[] = strongarm
projects[] = uuid
