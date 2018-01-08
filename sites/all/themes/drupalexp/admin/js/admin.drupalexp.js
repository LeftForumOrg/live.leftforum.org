(function ($) {
  var DRUPALEXP = DRUPALEXP || {};
  DRUPALEXP.currentRegion = null;
  DRUPALEXP.currentLayout = null;
  DRUPALEXP.currentLayoutIndex = null;
  DRUPALEXP.currentPreset = null;
  DRUPALEXP.currentSection = null;
  DRUPALEXP.base64Encode = function (c) {
    var keyString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    var a = "";
    var k, h, f, j, g, e, d;
    var b = 0;
    c = DRUPALEXP.UTF8Encode(c);
    while (b < c.length) {
      k = c.charCodeAt(b++);
      h = c.charCodeAt(b++);
      f = c.charCodeAt(b++);
      j = k >> 2;
      g = ((k & 3) << 4) | (h >> 4);
      e = ((h & 15) << 2) | (f >> 6);
      d = f & 63;
      if (isNaN(h)) {
        e = d = 64
      } else {
        if (isNaN(f)) {
          d = 64
        }
      }
      a = a + keyString.charAt(j) + keyString.charAt(g) + keyString.charAt(e) + keyString.charAt(d)
    }
    return a;
  };
  DRUPALEXP.UTF8Encode = function (b) {
    b = b.replace(/\x0d\x0a/g, "\x0a");
    var a = "";
    for (var e = 0; e < b.length; e++) {
      var d = b.charCodeAt(e);
      if (d < 128) {
        a += String.fromCharCode(d)
      } else {
        if ((d > 127) && (d < 2048)) {
          a += String.fromCharCode((d >> 6) | 192);
          a += String.fromCharCode((d & 63) | 128)
        } else {
          a += String.fromCharCode((d >> 12) | 224);
          a += String.fromCharCode(((d >> 6) & 63) | 128);
          a += String.fromCharCode((d & 63) | 128)
        }
      }
    }
    return a;
  };
  DRUPALEXP.keyGen = function (title) {
    return title.replace(/[^a-z0-9]/g, function (s) {
      var c = s.charCodeAt(0);
      if (c == 32)
        return '-';
      if (c >= 65 && c <= 90)
        return s.toLowerCase();
      return '__' + ('000' + c.toString(16)).slice(-4);
    });
  };
  DRUPALEXP.draw = function (layout) {
    $('ul#dexp_sections').html('');
    $(layout.sections).each(function () {
      this.regions == this.regions || [];
      var section = $('<li>');
      section.data({
        backgroundcolor: this.backgroundcolor || '',
        colpadding: this.colpadding || '',
        custom_class: this.custom_class || '',
        fullwidth: this.fullwidth || 'no',
        hdesktop: this.hdesktop || false,
        hphone: this.hphone || false,
        htablet: this.htablet || false,
        key: this.key || "",
        sticky: this.sticky || false,
        title: this.title || "",
        vdesktop: this.vdesktop || false,
        vphone: this.vphone || false,
        vtablet: this.vtablet || false,
        weight: this.weight || 0,
      });
      section.css({backgroundColor: this.backgroundcolor});
      section.addClass('dexp-section');
      if (this.key == 'unassigned') {
        section.addClass('dexp-section-unassigned');
      }
      var sectionHeader = $('<div class="dexp-section-header">');
      sectionHeader.append('<i class="fa fa-arrows section-sortable"></i>');
      sectionHeader.append('<span class="section_title">' + this.title + '</span>');
      sectionHeader.append('<i class="fa fa-gears section-settings pull-right"></i>');
      section.append(sectionHeader);
      section.append('<ul class="dexp-section-inner row"></ul>');
      $('ul#dexp_sections').append(section);
      $('ul#dexp_sections').sortable({
        handle: '.section-sortable',
        cancel: '.dexp-section-unassigned',
      });
      $(this.regions).each(function () {
        var region = $('<li class="dexp-region">');
        this.collg = this.collg || 6;
        this.colmd = this.colmd || 6;
        this.colsm = this.colsm || 12;
        this.colxs = this.colxs || 12;
        this.collgoffset = this.collgoffset || 0;
        this.colmdoffset = this.colmdoffset || 0;
        this.colsmoffset = this.colsmoffset || 0;
        this.colxsoffset = this.colxsoffset || 0;
        region.data({
          collg: this.collg,
          colmd: this.colmd,
          colsm: this.colsm,
          colxs: this.colxs,
          collgoffset: this.collgoffset,
          colmdoffset: this.colmdoffset,
          colsmoffset: this.colsmoffset,
          colxsoffset: this.colxsoffset,
          custom_class: this.custom_class || '',
          key: this.key || '',
          title: this.title || '',
          weight: this.weight || 0
        });
        region.append('<div class="region-inner"><i class="fa fa-arrows region-sortable"></i>' + this.title + '<i class="fa fa-gears region-settings pull-right"></i></div>');
        region.addClass('col-lg-' + this.collg);
        region.addClass('col-md-' + this.colmd);
        region.addClass('col-sm-' + this.colsm);
        region.addClass('col-xs-' + this.colxs);
        region.addClass('col-lg-offset-' + this.collgoffset);
        region.addClass('col-md-offset-' + this.colmdoffset);
        region.addClass('col-sm-offset-' + this.colsmoffset);
        region.addClass('col-xs-offset-' + this.colxsoffset);
        section.find('.dexp-section-inner').append(region);
      });
      $('.dexp-section-inner').sortable({
        handle: '.region-sortable',
        connectWith: '.dexp-section-inner'
      });
    });
    Drupal.attachBehaviors($('ul#dexp_sections'));
  }

  DRUPALEXP.saveLayout = function () {
    if (DRUPALEXP.currentLayoutIndex == null)
      return false;
    Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].sections = [];
    $('.dexp-section').each(function (index) {
      var section = {
        backgroundcolor: $(this).data('backgroundcolor'),
        colpadding: $(this).data('colpadding'),
        custom_class: $(this).data('custom_class'),
        fullwidth: $(this).data('fullwidth'),
        hdesktop: $(this).data('hdesktop'),
        hphone: $(this).data('hphone'),
        htablet: $(this).data('htablet'),
        key: $(this).data('key'),
        sticky: $(this).data('sticky'),
        title: $(this).data('title'),
        vdesktop: $(this).data('vdesktop'),
        vphone: $(this).data('vphone'),
        vtablet: $(this).data('vtablet'),
        weight: index,
        regions: [],
      };
      $($(this).find('.dexp-region')).each(function (index) {
        var region = {
          collg: $(this).data('collg'),
          colmd: $(this).data('colmd'),
          colsm: $(this).data('colsm'),
          colxs: $(this).data('colxs'),
          collgoffset: $(this).data('collgoffset'),
          colmdoffset: $(this).data('colmdoffset'),
          colsmoffset: $(this).data('colsmoffset'),
          colxsoffset: $(this).data('colxsoffset'),
          custom_class: $(this).data('custom_class'),
          key: $(this).data('key'),
          title: $(this).data('title'),
          weight: index
        };
        section.regions.push(region);
      });
      Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].sections.push(section);
    });
  }

  DRUPALEXP.setFormVal = function (context, element) {
    $('[data-key]', context).each(function () {
      if ($(this).is('[type=checkbox]')) {
        $(this).attr('checked', $(element).data($(this).data('key')));
      } else {
        $(this).val($(element).data($(this).data('key')));
      }
    });
  };

  DRUPALEXP.saveFormVal = function (context, element) {
    $('[data-key]', context).each(function () {
      if ($(this).is('[type=checkbox]')) {
        $(element).data($(this).data('key'), $(this).is(':checked'));
      } else {
        $(element).data($(this).data('key'), $(this).val());
      }
    });
  };

  /*Layout settings*/
  Drupal.behaviors.drupalexp_init = {
    attach: function (context, settings) {
      $('ul#dexp_layouts', context).find('li').remove();
      $(settings.drupalexp.layouts).each(function (index) {
        var tab = $('<li class="dexp_layout">');
        tab.data({
          title: this.title,
          key: this.key,
          pages: this.pages,
          isdefault: this.isdefault
        });
        var defaultText = "";
        if (this.isdefault) {
          defaultText = '<span style="color:#ff0000">*</span>';
        }
        tab.append('<a href="#" class="layout-title">' + this.title + defaultText + '</a>');
        tab.append('<span class="fa fa-gears layout-settings"></span>');
        tab.find('.layout-title').once('click', function () {
          $(this).click(function () {
            DRUPALEXP.saveLayout();
            DRUPALEXP.currentLayoutIndex = index;
            $('.dexp_layout').removeClass('active');
            $(this).closest('.dexp_layout').addClass('active');
            DRUPALEXP.draw(Drupal.settings.drupalexp.layouts[index]);
            return false;
          });
        });
        $('ul#dexp_layouts', context).append(tab);
      });
    }
  }

  Drupal.behaviors.drupalexp_layout_settings = {
    attach: function (context, settings) {
      $('#edit-drupalexp-layouts-edit').dialog({
        autoOpen: false,
        title: Drupal.t('Layout settings'),
        width: '60%',
        height: 400,
        modal: true,
        open: function () {
          var layout = settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex];
          $('[name=layout_name]').val(layout.title);
          $('[name=layout_default]').attr('checked', layout.isdefault);
          $('[name=dexp_layout_pages]').val(layout.pages);
          if (layout.isdefault) {
            $('[name=dexp_layout_pages]').closest('.form-item').hide();
          } else {
            $('[name=dexp_layout_pages]').closest('.form-item').show();
          }
        },
        buttons: [
          {
            text: Drupal.t('Save'),
            click: function () {
              Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].title = $('[name=layout_name]').val();
              Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].key = DRUPALEXP.keyGen($('[name=layout_name]').val());
              Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].pages = $('[name=dexp_layout_pages]').val();
              Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].isdefault = $('[name=layout_default]').is(':checked');
              if (Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].isdefault) {
                $(Drupal.settings.drupalexp.layouts).each(function (index) {
                  if (index != DRUPALEXP.currentLayoutIndex) {
                    Drupal.settings.drupalexp.layouts[index].isdefault = false;
                  }
                });
              } else {
                var hasdefault = false;
                $(Drupal.settings.drupalexp.layouts).each(function (index) {
                  if (Drupal.settings.drupalexp.layouts[index].isdefault) {
                    hasdefault = Drupal.settings.drupalexp.layouts[index].isdefault;
                  }
                });
                if (!hasdefault)
                  Drupal.settings.drupalexp.layouts[0].isdefault = true;
              }
              Drupal.attachBehaviors();
              $('ul#dexp_layouts li:eq(' + DRUPALEXP.currentLayoutIndex + ') .layout-title').trigger('click');
              $(this).dialog('close');
            }
          },
          {
            text: Drupal.t('Clone layout'),
            click: function () {
              DRUPALEXP.saveLayout(Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex]);
              var newLayout = {};
              $.extend(true, newLayout, Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex]);
              newLayout.title = 'copy of ' + newLayout.title;
              newLayout.isdefault = false;
              newLayout.pages = '';
              Drupal.settings.drupalexp.layouts.push(newLayout);
              Drupal.attachBehaviors();
              $('ul#dexp_layouts li:last .layout-title').trigger('click');
              $(this).dialog('close');
            }
          },
          {
            text: Drupal.t('Remove layout'),
            click: function () {
              if (settings.drupalexp.layouts.length == 1) {
                alert(Drupal.t('Can not remove this layout'));
              } else if (confirm(Drupal.t('Are you sure you want to remove this layout?'))) {
                Drupal.settings.drupalexp.layouts.splice(DRUPALEXP.currentLayoutIndex, 1);
                DRUPALEXP.currentLayoutIndex = null;
                Drupal.attachBehaviors();
                $('ul#dexp_layouts li:first .layout-title').trigger('click');
                $(this).dialog('close');
              }
            }
          },
          {
            text: Drupal.t('Cancel'),
            click: function () {
              $(this).dialog('close');
            }
          }
        ]
      });
      $('.layout-settings', context).once('click', function () {
        DRUPALEXP.currentLayout = $(this).closest('.dexp_layout');
        $(this).click(function () {
          $('#edit-drupalexp-layouts-edit').dialog('open');
        });
      });
    }
  }

  Drupal.behaviors.drupalexp_section_settings = {
    attach: function (context, settings) {
      $('#edit-drupalexp-section-settings', context).once('dialog', function () {
        $(this).dialog({
          autoOpen: false,
          title: Drupal.t('Section settings'),
          width: '60%',
          height: 500,
          modal: true,
          open: function (event, ui) {
            DRUPALEXP.setFormVal('#edit-drupalexp-section-settings', DRUPALEXP.currentSection);
          },
          buttons: [
            {
              text: Drupal.t('Save'),
              click: function () {
                DRUPALEXP.saveFormVal('#edit-drupalexp-section-settings', DRUPALEXP.currentSection);
                DRUPALEXP.currentSection.find('.section_title').text(DRUPALEXP.currentSection.data('title'));
                DRUPALEXP.saveLayout(settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex]);
                DRUPALEXP.draw(settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex]);
                $(this).dialog('close');
              }
            }, {
              text: Drupal.t('Remove section'),
              click: function () {
                if (confirm(Drupal.t('Are you sure you want to remove this section?'))) {
                  DRUPALEXP.currentSection.find('.dexp-region').each(function () {
                    $('.dexp-section-unassigned ul').append($(this));
                  });
                  DRUPALEXP.currentSection.remove();
                  DRUPALEXP.saveLayout(Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex]);
                  $(this).dialog('close');
                }
              }
            }
          ]
        });
      });

      $('.section-settings').once('click', function () {
        $(this).click(function () {
          DRUPALEXP.currentSection = $(this).closest('.dexp-section');
          $('#edit-drupalexp-section-settings').dialog('open');
        });
      });
    }
  }

  Drupal.behaviors.drupalexp_region_settings = {
    attach: function (context, settings) {
      $('#edit-drupalexp-region-settings', context).once('dialog', function () {
        $(this).dialog({
          autoOpen: false,
          title: Drupal.t('Region settings'),
          width: '70%',
          height: 400,
          modal: true,
          open: function (event, ui) {
            DRUPALEXP.setFormVal('#edit-drupalexp-region-settings', DRUPALEXP.currentRegion);
          },
          buttons: [
            {
              text: Drupal.t('Save'),
              click: function () {
                DRUPALEXP.saveFormVal('#edit-drupalexp-region-settings', DRUPALEXP.currentRegion);
                DRUPALEXP.currentRegion.attr('class', '');
                DRUPALEXP.currentRegion.addClass('dexp-region');
                DRUPALEXP.currentRegion.addClass('col-lg-' + $('[name=region_col_lg]').val());
                DRUPALEXP.currentRegion.addClass('col-md-' + $('[name=region_col_md]').val());
                DRUPALEXP.currentRegion.addClass('col-sm-' + $('[name=region_col_sm]').val());
                DRUPALEXP.currentRegion.addClass('col-xs-' + $('[name=region_col_xs]').val());
                $(this).dialog('close');
              }
            },
            {
              text: Drupal.t('Cancel'),
              click: function () {
                $(this).dialog('close');
              }
            }
          ]
        });
      });
      $('.region-settings').once('click', function () {
        $(this).click(function () {
          DRUPALEXP.currentRegion = $(this).closest('.dexp-region');
          $('#edit-drupalexp-region-settings').dialog('open');
        });
      });
    }
  }

  Drupal.behaviors.drupalexp_add_section = {
    attach: function (context, settings) {
      $('#drupalexp_add_section_dialog').dialog({
        autoOpen: false,
        modal: true,
        width: 300,
        height: 200,
        buttons: [
          {
            text: Drupal.t('Save'),
            click: function () {
              if ($('[name=section_name]').val().trim() != '') {
                var newSection = {
                  title: $('[name=section_name]').val().trim(),
                  key: DRUPALEXP.keyGen($('[name=section_name]').val().trim()),
                  regions: []
                };
                settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].sections.splice(settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex].sections.length - 1, 0, newSection);
                DRUPALEXP.draw(settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex]);
              }
              $(this).dialog('close');
            }
          }
        ]
      }
      );
      $('#drupalexp_add_section a').once('click', function () {
        $(this).click(function () {
          $('#drupalexp_add_section_dialog').dialog('open');
          return false;
        });
      });
    }
  }

  Drupal.behaviors.drupalexp_add_layout = {
    attach: function () {
      $('.dexp-add-layout').once('click', function () {
        $(this).click(function () {
          DRUPALEXP.saveLayout(Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex]);
          var newLayout = {
            title: Drupal.t('New Layout'),
            key: DRUPALEXP.keyGen(Drupal.t('New Layout'))
          };
          var unassigned_section = {key: 'unassigned', title: Drupal.t('Unassigned'), regions: []};
          $(Drupal.settings.drupalexp.layouts[0].sections).each(function () {
            $(this.regions).each(function () {
              var region = {};
              $.extend(true, region, this);
              unassigned_section.regions.push(region);
            });
          });
          newLayout.sections = [unassigned_section];
          Drupal.settings.drupalexp.layouts.push(newLayout);
          Drupal.attachBehaviors();
          $('ul#dexp_layouts li:last .layout-title').trigger('click');
        });
      });
    }
  }

  /*Preset settings*/
  Drupal.behaviors.drupalexp_presets = {
    attach: function (context, settings) {
      //var presets = settings.drupalexp_presets;
      var farb = $.farbtastic('#placeholder');
      $('#edit-drupalexp-presets-list').once()
      $('#edit-drupalexp-presets-list').once('change',function () {
        DRUPALEXP.currentPreset = $(this).val();
        $(this).change(function(){
          $('.preset-option').change(function () {
            Drupal.settings.drupalexp_presets[DRUPALEXP.currentPreset][$(this).data('property')] = $(this).val();
          });
          DRUPALEXP.currentPreset = $(this).val();
          $('#edit-drupalexp-preset-key').val(settings.drupalexp_presets[DRUPALEXP.currentPreset].key);
          $('#edit-drupalexp-base-color').val(settings.drupalexp_presets[DRUPALEXP.currentPreset].base_color);
          $('#edit-drupalexp-base-color-opposite').val(settings.drupalexp_presets[DRUPALEXP.currentPreset].base_color_opposite || settings.drupalexp_presets[DRUPALEXP.currentPreset].base_color);
          $('#edit-drupalexp-link-color').val(settings.drupalexp_presets[DRUPALEXP.currentPreset].link_color);
          $('#edit-drupalexp-link-hover-color').val(settings.drupalexp_presets[DRUPALEXP.currentPreset].link_hover_color);
          $('#edit-drupalexp-text-color').val(settings.drupalexp_presets[DRUPALEXP.currentPreset].text_color);
          $('#edit-drupalexp-heading-color').val(settings.drupalexp_presets[DRUPALEXP.currentPreset].heading_color);
          $('.color').each(function () {
            farb.linkTo(this);
          });
        }).trigger('change');
      });

      $('.color').focus(function () {
        $('#edit-preset-settings .form-item').removeClass('focus');
        $(this).parents('.form-item').addClass('focus');
        farb.linkTo(this);
      });
    }
  }

  Drupal.behaviors.drupalexp_form_submit = {
    attach: function () {
      $('form#system-theme-settings').once('drupalexp-submit', function () {
        $(this).submit(function () {
          DRUPALEXP.saveLayout(Drupal.settings.drupalexp.layouts[DRUPALEXP.currentLayoutIndex]);
          var layoutstr = DRUPALEXP.base64Encode(JSON.stringify(Drupal.settings.drupalexp.layouts));
          var layoutstrs = layoutstr.match(/.{1,1000}/g);
          for (var i = 0; i < layoutstrs.length; i++) {
            var $input = $('<input type="hidden" name="dexp_layout_' + i + '"/>');
            $input.val(layoutstrs[i]);
            $('input[name=drupalexp_layouts]').after($input);
          }
          $('input[name=drupalexp_layouts]').val('');
          $('.preset-option').each(function () {
            Drupal.settings.drupalexp_presets[DRUPALEXP.currentPreset][$(this).data('property')] = $(this).val();
          });
          $('input[name=drupalexp_presets]').val(DRUPALEXP.base64Encode(JSON.stringify(Drupal.settings.drupalexp_presets)));
          return true;
        });
      });
    }
  }

  Drupal.behaviors.drupalexp_google_font = {
    attach: function(context, settings){
      $('.google-font').once('google-font', function(){
        var $this = $(this);
        var font = $this.val().split(':');
        font[1] = font[1]||'';
        font[2] = font[2]||'13px';
        font[3] = font[3]||'';
        font[4] = font[4]||'';
        var $font = $('<fieldset class="form-wrapper"><div class="col-sm-6"><label>Font family</label><input type="text" name="family" class="form-text" value="'+font[0]+'"/></div><div class="col-sm-2"><label>Font Weight & Style</label><select name="style" class="form-select"></select></div><div class="col-sm-2"><label>Font Size (px/pt)</label><input name="size" value="'+font[2]+'" class="form-text"/></div><div class="col-sm-2"><label>Line height</label><input name="height" value="'+font[3]+'" class="form-text"/></div></fieldset>');
        var $family = $('[name=family]', $font);
        var $style = $('[name=style]', $font);
        var $size = $('[name=size]', $font);
        var $height = $('[name=height]', $font);
        var $selector = null;
        if($this.hasClass('custom-font')){
          $font.append('<div class="col-sm-12"><label>Selector (add html tags ID or class (body,a,.class,#id))</label><input type="text" name="selector" value="'+font[4]+'" class="form-text"/></div>');
          $selector = $('[name=selector]',$font);
        }
        if(font[0] != ''){
          var font_selected = $.grep(Drupal.settings.google_fonts.items, function(e){ return e.value == font[0];});
          if(font_selected.length > 0){
            $(font_selected[0].variants).each(function(index, el){
               $style.append(new Option(el,el));
            });
            $style.val(font[1]);
          }
        }else{
          $style.append(new Option(400,400));
        }
        $(this).after($font);
        $style.change(function(){
          $this.val($family.val()+':'+$style.val()+':'+$size.val()+':'+$height.val());
        });
        $family.autocomplete({
          source: Drupal.settings.google_fonts.items,
          minLength: 3,
          select: function( event, ui ) {
            $style.find('option').remove();
            $(ui.item.variants).each(function(index, el){
              $style.append(new Option(el,el));
            });
            $this.val(ui.item.value+':'+$style.val()+':'+$size.val()+':'+$height.val());
          }
        });
        setInterval(function(){
          if($selector != null){
            $this.val($family.val()+':'+$style.val()+':'+$size.val()+':'+$height.val()+':'+$selector.val());
          }else{
            $this.val($family.val()+':'+$style.val()+':'+$size.val()+':'+$height.val());
          }
        },500);
      })
    }
  }

  $(document).ready(function () {
    $('ul#dexp_layouts li:eq(0) .layout-title').trigger('click');
  });
})(jQuery)
