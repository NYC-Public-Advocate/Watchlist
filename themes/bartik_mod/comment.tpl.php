<?php
// $Id$
?>
<div id="comment-<?php print $comment->cid; ?>" class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ($comment->uid == $node->uid) ? ' comment-by-author' : ''; print ' '. $status; ?> clearfix">
  <?php print $picture; ?>

  <?php if ($comment->new): ?>
    <span class="new"><?php print $new; ?></span>
  <?php endif; ?>

  <h3 class="comment-title"><?php print $title; ?></h3>

  <div class="submitted">
    <?php print $submitted; ?>
  </div>

  <div class="content">
    <?php print $content; ?>

    <?php if ($signature): ?>
      <div class="user-signature clearfix">
        <?php print $signature; ?>
      </div>
    <?php endif; ?>
  </div>

  <?php if (!empty($links)): ?>
    <div class="comment-links skele-reset clearfix">
      <?php print $links; ?>
    </div>
  <?php endif; ?>
</div>
