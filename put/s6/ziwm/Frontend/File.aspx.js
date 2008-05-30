/// <reference path="VirtualEarthtIntelliSense.js" />

var DrawModes = { None:0, DrawPolyline:1, DrawPolygon:2 };

function CreateTemporaryShape(drawMode, points)
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
}

function CreatePernamentShape(drawMode, points)
{
    var shapeType = VEShapeType.Pushpin;

    if (points.length > 1)
    {
        switch(drawMode)
        {
            case DrawModes.DrawPolyline:
                shapeType = VEShapeType.Polyline;
                break;
                
            case DrawModes.DrawPolygon:
                shapeType = VEShapeType.Polygon;
                break;
        }
    }

    var shape = new VEShape(shapeType, points);
    shape.SetLineColor(new VEColor(0, 255, 0, 1));
    shape.SetFillColor(new VEColor(0, 255, 0, 0.3));
    
    if (shapeType != VEShapeType.Pushpin)
        shape.HideIcon();
        
    return shape;
}

function PageLoad()
{
    var 
    var map = new VEMap("map");

    var drawPolylineButton = document.getElementById("drawPolylineButton");
    var drawPolygonButton = document.getElementById("drawPolygonButton");
    
    var drawMode = DrawModes.None;
    var points = [];
    var shape = null;
    
    map.AttachEvent("onclick", function(e)
    {
        if (drawMode != DrawModes.None)
        {
            var position = map.PixelToLatLong(new VEPixel(e.mapX, e.mapY));
            
            points.push(position);
            
            if (shape != null)
                map.DeleteShape(shape);

            shape = CreateTemporaryShape(drawMode, points);
            map.AddShape(shape);
        }
    });
   
   var ToggleShapeDrawing = function(button)
    {
        if (drawMode == DrawModes.None)
        {
            button.innerHTML = button.activeHTML;
            drawMode = button.drawMode;
        }
        else
        {
            button.innerHTML = button.inactiveHTML;;
            
            if (shape != null)
                map.DeleteShape(shape);
                
            if (points.length > button.minPointCount)
                map.AddShape(CreatePernamentShape(drawMode, points));

            drawMode = DrawModes.None;
            points = [];                
            shape = null;
        }
    }
       
    drawPolylineButton.drawMode = DrawModes.DrawPolyline;
    drawPolylineButton.minPointCount = 2;
    drawPolylineButton.inactiveHTML =  "Draw Polyline";
    drawPolylineButton.activeHTML = "End Polyline Drawing";
    drawPolylineButton.innerHTML = drawPolylineButton.inactiveHTML;
    drawPolylineButton.onclick = function() { ToggleShapeDrawing(drawPolylineButton); };
    
    drawPolygonButton.drawMode = DrawModes.DrawPolygon;
    drawPolygonButton.minPointCount = 2;
    drawPolygonButton.inactiveHTML =  "Draw Polygon";
    drawPolygonButton.activeHTML = "End Polygon Drawing";
    drawPolygonButton.innerHTML = drawPolygonButton.inactiveHTML;
    drawPolygonButton.onclick = function() { ToggleShapeDrawing(drawPolygonButton); };
    
    //map.HideDashboard();
    map.LoadMap();
    map.SetZoomLevel(1);
}

window.onload = PageLoad;
