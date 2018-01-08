<div id="node-<?php print $node->nid; ?>" class="sh-clients <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content">
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    ?>                
    <div class="clients">
      <div class="client-img">
        <a rel="tooltip" title="<?php print $title; ?>"><?php print render($content['field_image']); ?></a>
      </div>
    </div>
  </div>
</div> 
