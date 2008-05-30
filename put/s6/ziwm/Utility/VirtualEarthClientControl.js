/// <reference name="MicrosoftAjax.js"/>
/// <reference path="VirtualEarthApiIntelliSense.js" />

Type.registerNamespace("Utility");

Utility.VirtualEarthClientControl = function(element)
{
    Utility.VirtualEarthClientControl.initializeBase(this, [element]);
    this._instance = null;
    this._initialLongitude = 0.0;   
    this._initialLatitude = 0.0;   
    this._initialZoomLevel = 1; 
}

Utility.VirtualEarthClientControl.prototype = 
{
    initialize: function()
    {
        Utility.VirtualEarthClientControl.callBaseMethod(this, 'initialize');
        
        this._instance = new VEMap(this.get_element().id);
        this._instance.onLoadMap = Function.createDelegate(this, onLoadComplete);   
           
        function onLoadComplete()
        {   
            this._instance.SetCenter(new VELatLong(this._initialLatitude, this._initialLongitude));
            this._instance.SetZoomLevel(this._initialZoomLevel);   
        }   
           
        this._instance.LoadMap();   

    },
    
    dispose: function()
    {
        Utility.VirtualEarthClientControl.callBaseMethod(this, 'dispose');
    },
    
    get_initialLatitude : function()
    {
        return this._initialLatitude;   
    },   
       
    set_initialLatitude : function(value)
    {
        if (this._instance != null)
            throw new Sys.InvalidOperationException();
            
        this._initialLatitude = value;   
    },

    get_initialLongitude : function()
    {   
        return this._initialLongitude;   
    },   
       
    set_initialLongitude : function(value)
    {
        if (this._instance != null)
            throw new Sys.InvalidOperationException();

        this._initialLongitude = value;   
    },   
    
    get_initialZoomLevel : function()
    {
        return this._initialZoomLevel;   
    },   
       
    set_initialZoomLevel : function(value)
    {
        if (this._instance != null)
            throw new Sys.InvalidOperationException();
        
        this._initialZoomLevel = value;   
    },    
}

Utility.VirtualEarthClientControl.registerClass('Utility.VirtualEarthClientControl', Sys.UI.Control);

if (typeof(Sys) !== 'undefined') Sys.Application.notifyScriptLoaded();
