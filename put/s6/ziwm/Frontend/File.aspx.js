﻿/// <reference name="MicrosoftAjax.js"/>
/// <reference path="VirtualEarthtIntelliSense.js" />

function loadTable()
{
    var annotationTable = $get(annotationTableId);
    var annotationEditor = $get(annotationEditorId); 

    annotationTable.style.display = 'block';
    annotationEditor.style.display = 'none';
    
    Frontend.FileWebService.GetAnnotations(
        function(result) { $find(annotationTableId).set_annotations(result); });
}

function loadEditor(annotation)
{
    var annotationTable = $get(annotationTableId);
    var annotationEditor = $get(annotationEditorId);
    var annotationEditorTitleInput = $get(annotationEditorTitleInputId);
    var annotationEditorSaveButton = $get(annotationEditorSaveButtonId);
    var annotationEditorCancelButton = $get(annotationEditorCancelButtonId);
    
    annotationTable.style.display = 'none';
    annotationEditor.style.display = 'block';
    annotationEditorTitleInput.value = annotation.Guid;
   
    annotationEditorCancelButton.onclick = function()
    {    
        loadTable();
        
        return false;
    };
    
    annotationEditorSaveButton.onclick = function()
    {
        annotation.Title = annotationEditorTitleInput.value;
        
        Frontend.FileWebService.AddOrUpdateAnnotation(annotation,
            function(result) { annotation.Guid = result; alert("Saved."); });
    
        loadTable();
        
        return false;
    };
}

function annotationTable_Select(sender, e)
{
    loadEditor(e.get_annotation());
}

function load()
{
    var polylineToggleButton = $find(polylineToggleButtonId);
    polylineToggleButton.add_start(function(sender, e) { alert("start"); });
    polylineToggleButton.add_stop(function(sender, e) { alert("stop"); });
    
    var polygonToggleButton = $find(polygonToggleButtonId);
    polygonToggleButton.add_start(function(sender, e) { alert("start"); });
    polygonToggleButton.add_stop(function(sender, e) { alert("stop"); });
   
    var annotationTable = $find(annotationTableId);
    annotationTable.add_select(annotationTable_Select);  
    
    loadTable();
}

function unload()
{
    var annotationTable = $find(annotationTableId);
    annotationTable.remove_select(annotationTable_Select);
}

Sys.Application.add_load(load);
Sys.Application.add_unload(unload);

//var DrawModes = { None:0, DrawPolyline:1, DrawPolygon:2 };

//function CreateTemporaryShape(drawMode, points)
//{
//    var shapeType = VEShapeType.Pushpin;
//    
//    if (points.length > 1)
//    {
//        switch(drawMode)
//        {
//            case DrawModes.DrawPolyline:
//            case DrawModes.DrawPolygon:
//                shapeType = VEShapeType.Polyline;
//        }
//    }

//    var shape = new VEShape(shapeType, points);
//    shape.SetLineColor(new VEColor(255, 0, 0, 1));
//    
//    if (shapeType != VEShapeType.Pushpin)
//        shape.HideIcon();

//    return shape;
//}

//function CreatePernamentShape(drawMode, points)
//{
//    var shapeType = VEShapeType.Pushpin;

//    if (points.length > 1)
//    {
//        switch(drawMode)
//        {
//            case DrawModes.DrawPolyline:
//                shapeType = VEShapeType.Polyline;
//                break;
//                
//            case DrawModes.DrawPolygon:
//                shapeType = VEShapeType.Polygon;
//                break;
//        }
//    }

//    var shape = new VEShape(shapeType, points);
//    shape.SetLineColor(new VEColor(0, 255, 0, 1));
//    shape.SetFillColor(new VEColor(0, 255, 0, 0.3));
//    
//    if (shapeType != VEShapeType.Pushpin)
//        shape.HideIcon();
//        
//    return shape;
//}

//function PageLoad()
//{
//    var 
//    var map = new VEMap("map");

//    var drawPolylineButton = document.getElementById("drawPolylineButton");
//    var drawPolygonButton = document.getElementById("drawPolygonButton");
//    
//    var drawMode = DrawModes.None;
//    var points = [];
//    var shape = null;
//    
//    map.AttachEvent("onclick", function(e)
//    {
//        if (drawMode != DrawModes.None)
//        {
//            var position = map.PixelToLatLong(new VEPixel(e.mapX, e.mapY));
//            
//            points.push(position);
//            
//            if (shape != null)
//                map.DeleteShape(shape);

//            shape = CreateTemporaryShape(drawMode, points);
//            map.AddShape(shape);
//        }
//    });
//   
//   var ToggleShapeDrawing = function(button)
//    {
//        if (drawMode == DrawModes.None)
//        {
//            button.innerHTML = button.activeHTML;
//            drawMode = button.drawMode;
//        }
//        else
//        {
//            button.innerHTML = button.inactiveHTML;;
//            
//            if (shape != null)
//                map.DeleteShape(shape);
//                
//            if (points.length > button.minPointCount)
//                map.AddShape(CreatePernamentShape(drawMode, points));

//            drawMode = DrawModes.None;
//            points = [];                
//            shape = null;
//        }
//    }
//       
//    drawPolylineButton.drawMode = DrawModes.DrawPolyline;
//    drawPolylineButton.minPointCount = 2;
//    drawPolylineButton.inactiveHTML =  "Draw Polyline";
//    drawPolylineButton.activeHTML = "End Polyline Drawing";
//    drawPolylineButton.innerHTML = drawPolylineButton.inactiveHTML;
//    drawPolylineButton.onclick = function() { ToggleShapeDrawing(drawPolylineButton); };
//    
//    drawPolygonButton.drawMode = DrawModes.DrawPolygon;
//    drawPolygonButton.minPointCount = 2;
//    drawPolygonButton.inactiveHTML =  "Draw Polygon";
//    drawPolygonButton.activeHTML = "End Polygon Drawing";
//    drawPolygonButton.innerHTML = drawPolygonButton.inactiveHTML;
//    drawPolygonButton.onclick = function() { ToggleShapeDrawing(drawPolygonButton); };
//    
//    //map.HideDashboard();
//    map.LoadMap();
//    map.SetZoomLevel(1);
//}

//window.onload = PageLoad;
