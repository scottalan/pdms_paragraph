<?php
/**
 * @file
 * pdms_paragraph.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pdms_paragraph_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function pdms_paragraph_image_default_styles() {
  $styles = array();

  // Exported image style: paragraph_button_image_style.
  $styles['paragraph_button_image_style'] = array(
    'label' => 'Paragraph Button',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      1 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 300,
          'height' => 150,
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_paragraphs_info().
 */
function pdms_paragraph_paragraphs_info() {
  $items = array(
    'pdms_paragraph_button' => array(
      'name' => 'Paragraph Button',
      'bundle' => 'pdms_paragraph_button',
      'locked' => '1',
    ),
  );
  return $items;
}
