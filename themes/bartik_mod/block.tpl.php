<?php
// $Id$
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module; ?> block-<?php print $block_id; ?> clearfix">
  <div class="block-b">
    <div class="block-t">
      <?php if ($block->subject): ?>
        <h2 class="block-subject"><?php print $block->subject; ?></h2>
      <?php endif;?>

      <div class="block-content content">
        <?php print $block->content; ?>
      </div>
    </div>
  </div>
</div>
