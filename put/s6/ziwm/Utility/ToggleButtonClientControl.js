/// <reference name="MicrosoftAjax.js"/>

Type.registerNamespace("Utility");

Utility.ToggleButtonState = function() {};

Utility.ToggleButtonState.prototype = 
{
    Unknown: 0,
    Stopped: 1,
    Started: 2,
}

Utility.ToggleButtonState.registerEnum("Utility.ToggleButtonState");

Utility.ToggleButtonClientControl = function(element)
{
    Utility.ToggleButtonClientControl.initializeBase(this, [element]);
    this._startText = "";
    this._stopText = "";
    this._state = Utility.ToggleButtonState.Unknown;
}

Utility.ToggleButtonClientControl.prototype = 
{
    initialize: function()
    {
        Utility.ToggleButtonClientControl.callBaseMethod(this, 'initialize');      
        
        //chyba to jest hack; chodzi o to, żeby anulować submit
        this.get_element().setAttribute("onclick", "return false");
        
        var handlers = 
        {
            click: this._onClick,
        };
        
        $addHandlers(this.get_element(), handlers, this);

        this._state = Utility.ToggleButtonState.Stopped;
        this._update();
    },
    
    dispose: function()
    {
        $clearHandlers(this.get_element());
        Utility.ToggleButtonClientControl.callBaseMethod(this, 'dispose');
    },
    
    get_stopText : function()
    {
        return this._stopText;   
    },   
       
    set_stopText : function(value)
    {
        this._stopText = value;   
    },

    get_startText : function()
    {   
        return this._startText;   
    },   
       
    set_startText : function(value)
    {
        this._startText = value;   
    },
    
    add_start: function(handler)
    {
        this.get_events().addHandler('start', handler);
    },
    
    remove_start: function(handler)
    {
        this.get_events().removeHandler('start', handler);
    },
    
    add_stop: function(handler)
    {
        this.get_events().addHandler('stop', handler);
    },
    
    remove_stop: function(handler)
    {
        this.get_events().removeHandler('stop', handler);
    },
    
    get_currentText: function()
    {
        switch (this._state)
        {
            case Utility.ToggleButtonState.Stopped:
                return this._startText;
            
            case Utility.ToggleButtonState.Started:
                return this._stopText;
        }
    },
    
    _update: function()
    {
        this.get_element().innerText = this.get_currentText();
    },
    
    _onClick: function(event)
    {
        switch (this._state)
        {
            case Utility.ToggleButtonState.Stopped:
                this._state = Utility.ToggleButtonState.Started;
                
                var handler = this.get_events().getHandler('start')
                
                if (handler)
                    handler(this, Sys.EventArgs.Empty);
                
                this._update();
                break;
                
            case Utility.ToggleButtonState.Started:
                this._state = Utility.ToggleButtonState.Stopped;
                
                var handler = this.get_events().getHandler('stop')
                
                if (handler)
                    handler(this, Sys.EventArgs.Empty);
                
                this._update();
                break;    
        }
    }
}

Utility.ToggleButtonClientControl.registerClass('Utility.ToggleButtonClientControl', Sys.UI.Control);

if (typeof(Sys) !== 'undefined') Sys.Application.notifyScriptLoaded();
