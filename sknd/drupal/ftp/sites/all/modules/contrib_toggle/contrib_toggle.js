// $Id$

/**
 * Activate a module and any modules it depends on.
 */
Drupal.contribToggleActivate = function (title, modules) {
  modules[title].self.attr('checked', true);
  jQuery.each(modules[title].dependsOn, function(i, val) {
    Drupal.contribToggleActivate(val, modules);
  });
}

/**
 * Deactivate a module and all the modules that depend on it.
 */
Drupal.contribToggleDeactivate = function (title, modules) {
  modules[title].self.attr('checked', false);
  jQuery.each(modules[title].requiredBy, function(i, val) {
    Drupal.contribToggleDeactivate(val, modules);
  });
}

/**
 * Parse a module's Required by, Depends on, or Missing strings.
 *
 * @param: str - e.g. 'Required by: Event Views (disabled), Views UI (disabled)'
 * @return: array - e.g. ['Event Views', 'Views UI']
 */
Drupal.contribToggleParse = function (str) {
  var result = [];
  if (str) {
    str = str.substr(str.indexOf(':')+1); // Remove 'Required by:'
    str = str.replace( /\([^)]*\)/g, ''); // Remove (stuff).
    result = jQuery.map(str.split(','), function(n,i) {
      return jQuery.trim(n);
    });
  }
  return result;
}

/**
 * Identify any required modules that are inactive.
 *
 * @param: title - e.g. 'Contrib Toggle'
 * @return: array - e.g. ['Module A', 'Module B']
 */
Drupal.contribToggleDependsOnInactive = function (title, modules) {
  var modulesToToggle = [];
  jQuery.each(modules[title].dependsOn, function(i, val) {
    if (!modules[val].self.attr('checked')) {
        modulesToToggle[modulesToToggle.length] = val;
    }
  });
  return modulesToToggle;
}

/**
 * Identify any dependent modules that are active.
 *
 * @param: title - e.g. 'Contrib Toggle'
 * @return: array - e.g. ['Module A', 'Module B']
 */
Drupal.contribToggleRequiredByActive = function (title, modules) {
  var modulesToToggle = [];
  jQuery.each(modules[title].requiredBy, function(i, val) {
    if (modules[val].self.attr('checked')) {
        modulesToToggle[modulesToToggle.length] = val;
    }
  });
  return modulesToToggle;
}

/**
 * Create alert handling object.
 * Based on original code released under the GPL by Cory S.N. LaViska in the jQuery Alert Dialogs Plugin.
 * See http://abeautifulsite.net/notebook/87 for more information.
 *
 * Usage:
 *   contrib_toggleAlerts.alert( message, [title, callback] )
 *   contrib_toggleAlerts.confirm( message, [title, callback] )
 *   contrib_toggleAlerts.prompt( message, [value, title, callback] )
 *
 */
contrib_toggleAlerts = {
  // These properties can be read/written by accessing contrib_toggleAlerts.propertyName from your scripts at any time.
    verticalOffset: -75,                // vertical offset of the dialog from center screen, in pixels.
    horizontalOffset: 0,                // horizontal offset of the dialog from center screen, in pixels.
    repositionOnResize: true,           // re-centers the dialog on window resize.
    overlayOpacity: .01,                // transparency level of overlay.
    overlayColor: '#FFF',               // base color of overlay.
    draggable: false,                   // make the dialogs draggable (requires UI Draggables plugin).
    okButton: '&nbsp;OK&nbsp;',         // text for the OK button.
    cancelButton: '&nbsp;Cancel&nbsp;', // text for the Cancel button.
    dialogClass: null,                  // if specified, this class will be applied to all dialogs.
    
    // Public methods.
    // Alert box.
    alert: function(message, title, callback) {
      if( title == null ) title = 'Alert';
      contrib_toggleAlerts._show(title, message, null, 'alert', function(result) {
        if( callback ) callback(result);
      });
    },

    // User confirmation box.
    confirm: function(message, title, callback) {
      if( title == null ) title = 'Confirm';
      contrib_toggleAlerts._show(title, message, null, 'confirm', function(result) {
        if( callback ) callback(result);
      });
    },

    // User prompt box.
    prompt: function(message, value, title, callback) {
      if( title == null ) title = 'Prompt';
      contrib_toggleAlerts._show(title, message, value, 'prompt', function(result) {
        if( callback ) callback(result);
      });
    },
    
    // Private methods.
    // Show alert.
    _show: function(title, msg, value, type, callback) {
      
      contrib_toggleAlerts._hide();
      contrib_toggleAlerts._overlay('show');
      
      $("BODY").append(
        '<div id="popup_container">' +
          '<h1 id="popup_title"></h1>' +
          '<div id="popup_content">' +
            '<div id="popup_message"></div>' +
        '</div>' +
        '</div>');
      
      if( contrib_toggleAlerts.dialogClass ) $("#popup_container").addClass(contrib_toggleAlerts.dialogClass);
      
      // IE6 Fix
      var pos = ($.browser.msie && parseInt($.browser.version) <= 6 ) ? 'absolute' : 'fixed'; 
      
      $("#popup_container").css({
        position: pos,
        zIndex: 99999,
        padding: 0,
        margin: 0
      });
      
      $("#popup_title").text(title);
      $("#popup_content").addClass(type);
      $("#popup_message").text(msg);
      $("#popup_message").html( $("#popup_message").text().replace(/\n/g, '<br />') );
      
      $("#popup_container").css({
        minWidth: $("#popup_container").outerWidth(),
        maxWidth: $("#popup_container").outerWidth()
      });
      
      contrib_toggleAlerts._reposition();
      contrib_toggleAlerts._maintainPosition(true);
      
      switch( type ) {
        case 'alert':
          $("#popup_message").after('<div id="popup_panel"><input type="button" value="' + contrib_toggleAlerts.okButton + '" id="popup_ok" /></div>');
          $("#popup_ok").click( function() {
            contrib_toggleAlerts._hide();
            callback(true);
          });
          $("#popup_ok").focus().keypress( function(e) {
            if( e.keyCode == 13 || e.keyCode == 27 ) $("#popup_ok").trigger('click');
          });
        break;
        case 'confirm':
          $("#popup_message").after('<div id="popup_panel"><input type="button" value="' + contrib_toggleAlerts.okButton + '" id="popup_ok" /> <input type="button" value="' + contrib_toggleAlerts.cancelButton + '" id="popup_cancel" /></div>');
          $("#popup_ok").click( function() {
            contrib_toggleAlerts._hide();
            if( callback ) callback(true);
          });
          $("#popup_cancel").click( function() {
            contrib_toggleAlerts._hide();
            if( callback ) callback(false);
          });
          $("#popup_ok").focus();
          $("#popup_ok, #popup_cancel").keypress( function(e) {
            if( e.keyCode == 13 ) $("#popup_ok").trigger('click');
            if( e.keyCode == 27 ) $("#popup_cancel").trigger('click');
          });
        break;
        case 'prompt':
          $("#popup_message").append('<br /><input type="text" size="30" id="popup_prompt" />').after('<div id="popup_panel"><input type="button" value="' + contrib_toggleAlerts.okButton + '" id="popup_ok" /> <input type="button" value="' + contrib_toggleAlerts.cancelButton + '" id="popup_cancel" /></div>');
          $("#popup_prompt").width( $("#popup_message").width() );
          $("#popup_ok").click( function() {
            var val = $("#popup_prompt").val();
            contrib_toggleAlerts._hide();
            if( callback ) callback( val );
          });
          $("#popup_cancel").click( function() {
            contrib_toggleAlerts._hide();
            if( callback ) callback( null );
          });
          $("#popup_prompt, #popup_ok, #popup_cancel").keypress( function(e) {
            if( e.keyCode == 13 ) $("#popup_ok").trigger('click');
            if( e.keyCode == 27 ) $("#popup_cancel").trigger('click');
          });
          if( value ) $("#popup_prompt").val(value);
          $("#popup_prompt").focus().select();
        break;
      }
      
      // Make draggable if jQuery UI draggables is installed and configuration is altered above.
      if( contrib_toggleAlerts.draggable ) {
        try {
          $("#popup_container").draggable({ handle: $("#popup_title") });
          $("#popup_title").css({ cursor: 'move' });
        } catch(e) { /* requires jQuery UI draggables */ }
      }
    },
    
    // Hide alert.
    _hide: function() {
      $("#popup_container").remove();
      contrib_toggleAlerts._overlay('hide');
      contrib_toggleAlerts._maintainPosition(false);
    },
    
    _overlay: function(status) {
      switch( status ) {
        case 'show':
          contrib_toggleAlerts._overlay('hide');
          $("BODY").append('<div id="popup_overlay"></div>');
          $("#popup_overlay").css({
            position: 'absolute',
            zIndex: 99998,
            top: '0px',
            left: '0px',
            width: '100%',
            height: $(document).height(),
            background: contrib_toggleAlerts.overlayColor,
            opacity: contrib_toggleAlerts.overlayOpacity
          });
        break;
        case 'hide':
          $("#popup_overlay").remove();
        break;
      }
    },
    
    // Reposition box based on box size to keep centered.
    _reposition: function() {
      var top = (($(window).height() / 2) - ($("#popup_container").outerHeight() / 2)) + contrib_toggleAlerts.verticalOffset;
      var left = (($(window).width() / 2) - ($("#popup_container").outerWidth() / 2)) + contrib_toggleAlerts.horizontalOffset;
      if( top < 0 ) top = 0;
      if( left < 0 ) left = 0;
      
      // IE6 fix
      if( $.browser.msie && parseInt($.browser.version) <= 6 ) top = top + $(window).scrollTop();
      
      $("#popup_container").css({
        top: top + 'px',
        left: left + 'px'
      });
      $("#popup_overlay").height( $(document).height() );
    },
    
    // Reposition box to keep centered on window resize.
    _maintainPosition: function(status) {
      if( contrib_toggleAlerts.repositionOnResize ) {
        switch(status) {
          case true:
            $(window).bind('resize', function() {
              contrib_toggleAlerts._reposition();
            });
          break;
          case false:
            $(window).unbind('resize');
          break;
        }
      }
    },
}

/**
 * Disable all non-core modules.
 */
Drupal.contribToggleSwitch = function () {
  // Read dependencies for all modules.
  var modules = [];
  $('#system-modules input[@type=checkbox][@name^="status"]').each( function() {
    var $row = $(this).parents('tr:first');
    var $title = $row.find('label:last').text();
    var $dependsOn = Drupal.contribToggleParse($row.find('.admin-dependencies').text());
    var $requiredBy = Drupal.contribToggleParse($row.find('.admin-required').text());
    modules[$title] = { self: $(this), dependsOn : $dependsOn, requiredBy : $requiredBy };
  });
  // Disable each non-core module, and any modules that depend on it.
  $('#system-modules input[@type=checkbox][@name^="status"]').each( function() {
    // Identify package that module belongs to.
    var fieldsetLegend = $(this).parents('fieldset').find('legend').text();
    // Mark to be disabled all modules not in packages listed as cases.
    switch (fieldsetLegend) {
      case "Core - optional":
        break;
        
      case "Core - required":
        break;

      default:
        var title = $(this).parents('tr:first').find('label:last').text();
        Drupal.contribToggleDeactivate(title, modules);
    }
  });
}

if( Drupal.jsEnabled ) {
  $(function() { 
  var modules = [];
    $('#system-modules input[@type=checkbox][@name^="status"]').each( function() {
      // Read dependencies for all modules.
    var $row = $(this).parents('tr:first');
    var $title = $row.find('label:last').text();
    var $dependsOn = Drupal.contribToggleParse($row.find('.admin-dependencies').text());
    var $requiredBy = Drupal.contribToggleParse($row.find('.admin-required').text());
      var $missing = Drupal.contribToggleParse($row.find('.admin-missing').text());
    modules[$title] = { self: $(this), dependsOn : $dependsOn, requiredBy : $requiredBy, missing : $missing };

      // If module has any missing requirements, set checkbox to not checked and disabled
      // and move to next checkbox
      if (modules[$title].missing.length > 0) {
          $(this).attr('checked', false);
          $(this).attr('disabled', true);
          // Returning true moves to next checkbox, bypassing the code below that would otherwise
          // enable the checkbox, but continues with overall loop.
          return true;
      }

      // Identify package that module belongs to.
      var fieldsetLegend = $(this).parents('fieldset').find('legend').text();
      
      // Enable checkboxes for all modules, even if they have dependencies.
      switch (fieldsetLegend) {
        // Keep checkboxes disabled for Core - required modules.
        case "Core - required":
          break;
        default:
          $(this).attr('disabled', false);
        };
      });
  
  // Activated when a module selection box is clicked.
  $('#system-modules input[@type=checkbox][@name^="status"]').click( function() {
    // Identify title of module and checked status
    var $title = $(this).parents('tr:first').find('label:last').text();
    var checked = $(this).attr('checked');
    if (checked) {
        // If module previously selected, do not uncheck box until remaining code is run.
        $(this).attr('checked', false);
         // Executed if there are modules this module depends on.
         if (modules[$title].dependsOn.length > 0) {
           var modulesToActivate = [];
           modulesToActivate = Drupal.contribToggleDependsOnInactive($title, modules);
           if (modulesToActivate.length > 0) {
             var $modulePlural = "module";
             if (modulesToActivate.length > 1) {
               $modulePlural = $modulePlural + "s";
             }
             // Confirm if user is happy for required modules to also be activated.
             $confirmMessage = $title + ' requires the following ' + $modulePlural + ' to be activated as well: <br/>&nbsp;&nbsp;&nbsp;<strong>'
               + modulesToActivate.join('<br />&nbsp;&nbsp;&nbsp;') 
               + '</strong><br />&nbsp;<br />Do you wish to proceed?';
             contrib_toggleAlerts.confirm($confirmMessage, 'Required ' + $modulePlural, function(proceed) {
               // If user clicks OK, activate selected module and its required modules.
              if (proceed) {
                Drupal.contribToggleActivate($title, modules);
                }
            });
          }
          else {
            // If all required modules are already active, activate this module.
            Drupal.contribToggleActivate($title, modules);
          }
        }
        else {
          // If this module does not require any other modules, activate it.
          Drupal.contribToggleActivate($title, modules);
        }
    }
    else {
        // If module previously unselected, do not check box until remaining code is run.
        $(this).attr('checked', true);
         // Executed if there are modules that depend on this module.
        if (modules[$title].requiredBy.length > 0) {
          var modulesToDeactivate = [];
          modulesToDeactivate = Drupal.contribToggleRequiredByActive($title, modules);
          if (modulesToDeactivate.length > 0) {
            var $modulePlural = "module";
            if (modulesToDeactivate.length > 1) {
              $modulePlural = $modulePlural + "s";
            }
            // Confirm if user is happy for dependent modules to also be deactivated.
            $confirmMessage = $title + ' is required by the following ' + $modulePlural + ', which would also need to be deactivated: <br/>&nbsp;&nbsp;&nbsp;<strong>'
              + modulesToDeactivate.join('<br />&nbsp;&nbsp;&nbsp;') 
              + '</strong><br />&nbsp;<br />Do you wish to proceed?';
            contrib_toggleAlerts.confirm($confirmMessage, 'Dependent ' + $modulePlural, function(proceed) {
              // If user clicks OK, deactivate selected module and modules that depend on it.
              if (proceed) {
                Drupal.contribToggleDeactivate($title, modules);
                }
            });
          }
          else {
            // If all dependent modules are already inactive, deactivate this module.
            Drupal.contribToggleDeactivate($title, modules);
          }
        }
        else {
          // If this module does not have any dependent modules, deactivate it.
          Drupal.contribToggleDeactivate($title, modules);
        }
    }
    });
  });
}