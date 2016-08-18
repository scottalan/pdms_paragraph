<?php
/**
 * @file
 * Template used to render the Paragraph Button.
 *
 * Bundle: pdms_paragraph_button
 */
?>

<div class="pdms-paragraph-button-background" style="background-color: <?php print $bg_color; ?>; ">
  <a class="pdms-paragraph-button-link" href="/<?php print $linkit; ?>">
    <div class="inner-button-contents">
      <div class="pdms-paragraph-button-image">
        <?php if (isset($button_image)): ?>
        <?php print $button_image; ?>
        <?php endif; ?>
      </div>
      <div class="pdms-paragraph-button-text" <?php if (isset($text_color)): ?> style="color: <?php print$text_color; ?>"<?php endif; ?>>
        <?php if (isset($button_text)): ?>
          <?php print $button_text; ?>
        <?php endif; ?>
      </div>
    </div>
  </a>
</div>
