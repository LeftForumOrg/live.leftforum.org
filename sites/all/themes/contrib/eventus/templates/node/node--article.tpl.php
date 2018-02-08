<div id="node-<?php print $node->nid; ?>" class="node-details <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="item row">
        <div class="node-meta col-sx-12 col-sm-12 col-md-12 col-lg-12">  
            <div class="node-title">
                <?php print render($title_prefix); ?>
                    <?php if (!$page): ?>
                        <h2 class="node-content-tile" <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
                    <?php endif; ?>
                <?php print render($title_suffix); ?>
            </div>  
            <div class="node-date">
                <span class="date">Created on <?php print format_date($created,'custom','l, d M Y H:i:s');?></span>
            </div>            
            <div class="node-images clearfix">
                <?php print render($content['field_media']);?>
            </div>
        </div>  

        <div class="node-body col-sx-12 col-sm-12 col-md-12 col-lg-12">
            <div class="node-content content"<?php print $content_attributes; ?>>
                <?php print render($content['body']);?>
                <?php
                // We hide the comments and links now so that we can render them later.
                hide($content['comments']);
                hide($content['links']);
                //print render($content);
                ?>
            </div>
        </div>
    </div>
</div>