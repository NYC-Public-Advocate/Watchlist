<?php
// $Id$
?>
<div id="comments">
  <?php if ($node->comment == 1 || $node->comment == 2): ?>
    <h3 class="comments-title">
      <?php if ($node->comment_count == 0): ?>
        <?php print t('No comments for \'%title\'', array('%title' => $node->title)); ?>
      <?php else: ?>
        <?php print t('%comments for \'%title\'', array('%comments' => format_plural($node->comment_count, '1 comment', '@count comments'), '%title' => $node->title)); ?>
      <?php endif; ?>
    </h3>
  <?php endif; ?>

  <div id="comments-content">
    <?php print $content; ?>
  </div>
</div>
