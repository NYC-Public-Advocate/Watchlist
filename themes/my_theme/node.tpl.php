<?php
// $Id$
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> node-<?php print $type; ?> node-<?php print $type; ?> node-<?php print $type; ?><?php print ($page) ? '-page' : '-teaser'; ?> clearfix">
  <?php print $picture; ?>

  <?php if (!$page): ?>
    <h2 class="node-title"><a href="<?php print $node_url; ?>" title="<?php print $title; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <?php if ($submitted): ?>
    <div class="submitted"><?php print $submitted; ?></div>
    <div class="submitted"><?php print t('Last updated on ') . format_date($node->changed, 'medium'); ?></div>
  <?php endif; ?>

  <div class="content">
    <?php print $content; ?>
  </div>

  <?php if ($terms): ?>
    <div class="terms skele-reset">
      <?php print t('Tags:') . $terms; ?>
    </div>
  <?php endif;?>

  <?php if (!empty($links)): ?>
    <div class="node-links skele-reset clearfix">
      <?php print $links; ?>
    </div>
  <?php endif; ?>
</div>
