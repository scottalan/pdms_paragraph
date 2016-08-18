<?php
/**
 * @file
 * Renders the PDMS Paragraph Button bundle.
 */

/**
 * Render function used for any option selected on a paragraph widget that is
 * of the bundle: pdms_paragraph_button.
 *
 * @param array $vars
 *   Variables available for pre-processing.
 * @param string $name
 *   The paragraph bundle.
 * @param string $field_name
 *   The name of the field providing the data.
 * @param string $value
 *   The field data.
 */
function pdms_paragraph_button_render_values(&$vars, $name, $field_name, $value = NULL) {

  // Add our template to the suggestions and custom css for our widget.
  if (!in_array('pdms_paragraph_button_render', $vars['theme_hook_suggestions'])) {
    $vars['theme_hook_suggestions'][] = 'pdms_paragraph_button_render';
    // Add our css as well.
    drupal_add_css(drupal_get_path('module', 'pdms_paragraph') . '/css/pdms_paragraph.css');
  }

  // Metadata wrapper for the paragraph item.
  $wrapper = entity_metadata_wrapper('paragraphs_item', $vars['paragraphs_item']);

  // Define output based on the field.
  switch ($field_name) {
    case 'field_button_bg_color':
      $vars['bg_color'] = '';
      $vars['linkit'] = '';
      if (isset($wrapper->{$field_name})) {
        $linkit = $wrapper->field_button_link;
        if (isset($linkit)) {
          $vars['linkit'] = $linkit->value()['url'];
        }
        else {
          $vars['linkit'] = '#';
        }
        $value = $wrapper->{$field_name}->value()['rgb'];
        if (!empty($value)) {
          $vars['bg_color'] = $value;
        }
      }
      break;

    case 'field_button_text':
      $vars['button_text'] = '';
      if (isset($wrapper->{$field_name})) {
        $value = $wrapper->{$field_name}->value();
        if (!empty($value)) {
          $vars['button_text'] = check_markup($value['value'], $value['format']);
        }
        else {
          $vars['button_text'] = NULL;
        }
      }
      break;

    case 'field_button_text_color':
      $vars['text_color'] = '';
      if (isset($wrapper->{$field_name})) {
        $value = $wrapper->{$field_name}->value()['rgb'];
        if (!empty($value)) {
          $vars['text_color'] = $value;
        }
      }
      break;

    case 'field_button_image':
      $image_style = $wrapper->field_button_image_style->value();
      $vars['button_image'] = '';
      if (isset($wrapper->{$field_name})) {
        $value = $wrapper->{$field_name}->value();
        if (isset($value)) {
          $value['path'] = $value['uri'];
          if (isset($image_style) && !(empty($image_style))) {
            $value['style_name'] = $image_style;
            $styled_image = theme_image_style($value);
          }
          else {
            $styled_image = theme_image($value);
          }
          $vars['button_image'] = $styled_image;
        }
        else {
          $vars['button_image'] = NULL;
        }
      }
      break;
  }
}
