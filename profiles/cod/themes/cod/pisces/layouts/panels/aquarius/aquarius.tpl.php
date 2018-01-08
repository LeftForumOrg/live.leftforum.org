<?php
/**
 * @file
 * Template for Department Landing Pages.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display aquarius panel-layout clearfix <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if (!empty($content['primary']) ): ?>
    <div class="container primary clearfix panel-panel">
      <div class="container-inner primary-inner panel-panel-inner">
        <?php print $content['primary']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['secondary']) ): ?>
    <div class="container secondary clearfix panel-panel">
      <div class="container-inner secondary-inner panel-panel-inner">
        <?php print $content['secondary']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($content['tertiary_header'] || $content['tertiary_first'] || $content['tertiary_second'] || $content['tertiary_third'] || $content['tertiary_footer'] ): ?>
    <div class="container tertiary clearfix">
      <div class="container-inner tertiary-inner">
        <div class="column-content-region tertiary-header clearfix">
          <div class="column-content-region-inner tertiary-header-inner">
            <?php print $content['tertiary_header']; ?>
          </div>
        </div>
        <div class="tertiary-wrapper">
          <div class="column-content-region tertiary-first">
            <div class="column-content-region-inner tertiary-first-inner">
              <?php print $content['tertiary_first']; ?>
            </div>
          </div>
          <div class="column-content-region tertiary-second">
            <div class="column-content-region-inner tertiary-second-inner">
              <?php print $content['tertiary_second']; ?>
            </div>
          </div>
          <div class="column-content-region tertiary-third">
            <div class="column-content-region-inner tertiary-third-inner">
              <?php print $content['tertiary_third']; ?>
            </div>
          </div>
        </div>
        <div class="column-content-region tertiary-footer clearfix">
          <div class="column-content-region-inner tertiary-footer-inner">
            <?php print $content['tertiary_footer']; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['quaternary']) ): ?>
    <div class="container quaternary clearfix panel-panel">
      <div class="container-inner quaternary-inner panel-panel-inner">
        <?php print $content['quaternary']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['quinary']) ): ?>
    <div class="container quinary clearfix panel-panel">
      <div class="container-inner quinary-inner panel-panel-inner">
        <?php print $content['quinary']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['senary']) ): ?>
    <div class="container senary clearfix panel-panel">
      <div class="container-inner senary-inner panel-panel-inner">
        <?php print $content['senary']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['septenary']) ): ?>
    <div class="container septenary clearfix panel-panel">
      <div class="container-inner septenary-inner panel-panel-inner">
        <?php print $content['septenary']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['octonary']) ): ?>
    <div class="container octonary clearfix panel-panel">
      <div class="container-inner octonary-inner panel-panel-inner">
        <?php print $content['octonary']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['nonary']) ): ?>
    <div class="container nonary clearfix panel-panel">
      <div class="container-inner nonary-inner panel-panel-inner">
        <?php print $content['nonary']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['denary']) ): ?>
    <div class="container denary clearfix panel-panel">
      <div class="container-inner denary-inner panel-panel-inner">
        <?php print $content['denary']; ?>
      </div>
    </div>
  <?php endif; ?>
  
</div><!-- /.sutro -->
