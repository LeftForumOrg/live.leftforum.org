<div id="node-<?php print $node->nid; ?>" class="sh-blog-teaser <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="catItem row">
        <div class="catItemMeta col-sx-12 col-sm-12 col-md-12 col-lg-12">  
            <div class="catTitle">
                <?php print render($title_prefix); ?>
                    <?php if (!$page): ?>
                        <h2 class="blog-content-tile" <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
                    <?php endif; ?>
                <?php print render($title_suffix); ?>
            </div>  
            <div class="catDate">
                <span class="date"><?php print format_date($created,'custom','d M Y');?></span>
            </div>            
            <div class="blog-image clearfix">
                <?php print render($content['field_media']);?>
            </div>
        </div>  

        <div class="catItemInfo-Text col-sx-12 col-sm-12 col-md-12 col-lg-12">
            <div class="blog-content content"<?php print $content_attributes; ?>>
                <?php print render($content['body']);?>
                <?php
                // We hide the comments and links now so that we can render them later.
                hide($content['comments']);
                hide($content['links']);
                //print render($content);
                ?>
            </div>
            <div class="read-more clearfix">
                <a class="" href="<?php print $node_url; ?>">Read more: <?php print $title; ?></a>
            </div>
            <?php //print l('Read more...','node/'.$nid);?>
            <?php //print render($content['links']); ?>
            <?php //print render($content['comments']); ?>
        </div>
    </div>
</div>