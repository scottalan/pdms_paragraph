; From DRUPAL_ROOT Run:
; drush make --no-core --no-cache --no-gitinfofile sites/all/modules/custom/pdms_paragraph/pdms_paragraph.make --

api = 2
core = 7.x

; Color Field
projects[color_field][version] = 1.8

; JQuery Simple Color
libraries[jquery-simple-color][download][type] = git
libraries[jquery-simple-color][download][url] = http://github.com/recurser/jquery-simple-color.git
libraries[jquery-simple-color][download][branch] = v1.2.1
libraries[jquery-simple-color][destination] = libraries
libraries[jquery-simple-color][directory_name] = jquery-simple-color
