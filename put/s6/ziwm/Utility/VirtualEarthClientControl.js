/// <reference name="MicrosoftAjax.js"/>
/// <reference path="VirtualEarthApiIntelliSense.js" />

Type.registerNamespace("Utility");

Utility.VirtualEarthClientControl = function(element)
{
    Utility.VirtualEarthClientControl.initializeBase(this, [element]);
    this._instance = null;
    this._initialLongitude = 0;   
    this._initialLatitude = 0;   
    this._initialZoomLevel = 0;
    this._onClickDelegate = null;
}

Utility.VirtualEarthClientControl.prototype = 
{
    initialize: function()
    {
        Utility.VirtualEarthClientControl.callBaseMethod(this, 'initialize');
        
        this._onClickDelegate = Function.createDelegate(this, this._onClick);
        
        this._instance = new VEMap(this.get_element().id);
        this._instance.LoadMap();
        
        this._instance.SetCenter(new VELatLong(this._initialLatitude, this._initialLongitude));
        this._instance.SetZoomLevel(this._initialZoomLevel);
        this._instance.AttachEvent('onclick', this._onClickDelegate);
    },
    
    dispose: function()
    {
        this._instance.DetachEvent('onclick', this._onClickDelegate);
        delete this._onClickDelegate;
        
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
    
    startDrawing: function(shapeType)
    {
        
    },
    
    CreateTemporaryShape: function( points)
    {
        var shapeType = VEShapeType.Pushpin;
        
        if (points.length > 1)
        {
            switch(drawMode)
            {
                case DrawModes.DrawPolyline:
                case DrawModes.DrawPolygon:
                    shapeType = VEShapeType.Polyline;
            }
        }

        var shape = new VEShape(shapeType, points);
        shape.SetLineColor(new VEColor(255, 0, 0, 1));
        
        if (shapeType != VEShapeType.Pushpin)
            shape.HideIcon();

        return shape;
    },
    
    _onClick: function(e)
    {
    var points=[];
        var position = this._instance.PixelToLatLong(new VEPixel(e.mapX, e.mapY));
        alert(position);
        points.push(position);

        var shape = this.CreateTemporaryShape(points);
        this._instance.AddShape(shape);
    },
}

Utility.VirtualEarthClientControl.registerClass('Utility.VirtualEarthClientControl', Sys.UI.Control);

if (typeof(Sys) !== 'undefined') Sys.Application.notifyScriptLoaded();
