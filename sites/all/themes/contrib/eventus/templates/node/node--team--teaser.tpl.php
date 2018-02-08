<div id="node-<?php print $node->nid; ?>" class="sh-view-team <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="content"<?php print $content_attributes; ?>>
        <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
        <?php
// We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        ?>                
        <div class="team">
            <div class="team-item img-wrp">
                <?php print render($content['field_team_image']); ?>
            </div>
            <div class="team-item team-member-info-wrp">
                <div class="team-about">
                    <?php print render($content['body']); ?>
                    <div class="team-name">
                        <cite><span style="border:15px solid #ddd"></span><?php print $title; ?></cite>
                    </div>
                </div>
                <div class="team-social">                                        
                    <ul class="icons-social">
                        <?php if(!empty($content['field_team_facebook_link'])):?>
                        <li><a class="facebook" href="<?php print render($content['field_team_facebook_link'][0]);?>"><i class="fa fa-facebook"></i></a></li>
                        <?php endif;?>
                        <?php if(!empty($content['field_team_twitter_link'])):?>
                        <li><a class="twitter" href="<?php print render($content['field_team_twitter_link'][0]);?>"><i class="fa fa-twitter"></i></a></li>
                        <?php endif;?>
                        <?php if(!empty($content['field_team_google_plus_link'])):?>
                        <li><a class="gplus" href="<?php print render($content['field_team_google_plus_link'][0]);?>"><i class="fa fa-google-plus"></i></a></li>
                        <?php endif;?>
                        <?php if(!empty($content['field_team_linkedin_link'])):?>
                        <li><a class="linkedin" href="<?php print render($content['field_team_linkedin_link'][0]);?>"><i class="fa fa-linkedin"></i></a></li>
                        <?php endif;?>
                        <?php if(!empty($content['field_team_youtube_link'])):?>
                        <li><a class="linkedin" href="<?php print render($content['field_team_youtube_link'][0]);?>"><i class="fa fa-youtube"></i></a></li>
                        <?php endif;?>
                    </ul>
                </div>
            </div>
            <div class="clearfix"></div>
        </div>
    </div>
</div> 
