/// <reference name="MicrosoftAjax.js"/>
/// <reference path="VirtualEarthApiIntelliSense.js" />

Type.registerNamespace("Utility");

Utility.VirtualEarthShapeClickEventArgs = function(shape)     
{     
    Utility.VirtualEarthShapeClickEventArgs.initializeBase(this);     
    this._shape = shape;
}     
  
Utility.VirtualEarthShapeClickEventArgs.prototype =     
{     
  get_shape: function()     
  {        
    return this._shape;
  },     
}     
  
Utility.VirtualEarthShapeClickEventArgs.registerClass('Utility.VirtualEarthShapeClickEventArgs', Sys.EventArgs);     

Utility.VirtualEarthClientControl = function(element)
{
    Utility.VirtualEarthClientControl.initializeBase(this, [element]);
    this._instance = null;
    this._initialLongitude = 0;   
    this._initialLatitude = 0;   
    this._initialZoomLevel = 0;
    this._onClickDelegate = null;
    this._drawingShapeType = null;
    this._drawingPoints = [];
    this._drawingShape = null;
}

Utility.VirtualEarthClientControl.prototype = 
{
    initialize: function()
    {
        Utility.VirtualEarthClientControl.callBaseMethod(this, 'initialize');
        
        this._onClickDelegate = Function.createDelegate(this, this._onClick);
        
        this._instance = new VEMap(this.get_element().id);
        this._instance.LoadMap();
        //this._instance
        
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
    
    add_shapeClick: function(handler)
    {
        this.get_events().addHandler('shapeClick', handler);
    },
    
    remove_shapeClick: function(handler)
    {
        this.get_events().removeHandler('shapeClick', handler);
    },
    
    startDrawing: function(shapeType)
    {
        this._drawingShapeType = shapeType;
    },
    
    stopDrawing: function()
    {
        var shape = this._createPernamentDrawingShape();
        
        this._drawingShapeType = null;
        this._drawingPoints = [];
        this._drawingShape = null;

        return shape;
    },
    
    _createPernamentDrawingShape: function()
    {
        var shapeType = VEShapeType.Pushpin;
        
        if (this._drawingPoints.length > 1)
            shapeType = this._drawingShapeType;
            
        var shape = new VEShape(shapeType, this._drawingPoints);
        shape.SetLineColor(new VEColor(0, 255, 0, 1));
        shape.SetFillColor(new VEColor(0, 255, 0, 0.1));

        if (shapeType != VEShapeType.Pushpin)
            shape.HideIcon();
        
        this._replaceDrawingShape(shape);
        return shape;
    },
    
    _createTemporaryDrawingShape: function()
    {
        var shapeType = VEShapeType.Pushpin;
        
        if (this._drawingPoints.length > 1)
        {
            switch(this._drawingShapeType)
            {
                case VEShapeType.Polyline:
                case VEShapeType.Polygon:
                    shapeType = VEShapeType.Polyline;
            }
        }

        var shape = new VEShape(shapeType, this._drawingPoints);
        shape.SetLineColor(new VEColor(255, 0, 0, 1));
        
        if (shapeType != VEShapeType.Pushpin)
            shape.HideIcon();

        this._replaceDrawingShape(shape);
        return shape;
    },
    
    _replaceDrawingShape: function(shape)
    {
        if (this._drawingShape != null)
            this._instance.DeleteShape(this._drawingShape);
            
        this._instance.AddShape(shape);
        this._drawingShape = shape;
    },
    
    _onClick: function(e)
    {
        if (this._drawingShapeType != null)
        {
            var position = this._instance.PixelToLatLong(new VEPixel(e.mapX, e.mapY));
            this._drawingPoints.push(position);
            this._createTemporaryDrawingShape();
        }
        else if (e.elementID != null)
        {
            var handler = this.get_events().getHandler('shapeClick')

            if (handler)
            {
                var shape = this._instance.GetShapeByID(e.elementID);
                handler(this, new Utility.VirtualEarthShapeClickEventArgs(shape));
            }
        }
    },
}

Utility.VirtualEarthClientControl.registerClass('Utility.VirtualEarthClientControl', Sys.UI.Control);

if (typeof(Sys) !== 'undefined') Sys.Application.notifyScriptLoaded();
