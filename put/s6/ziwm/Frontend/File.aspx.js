/// <reference name="MicrosoftAjax.js"/>

function loadAnnotations()
{
    var onSuccess = function(annotations)
    {
        loadTable(annotations);
        loadMap(annotations);
    }
    
    Frontend.FileWebService.GetAnnotations(onSuccess);
}

function loadTable(annotations)
{
    var annotationList = $get(annotationListId);
    var annotationEditor = $get(annotationEditorId); 

    annotationList.style.display = 'block';
    annotationEditor.style.display = 'none';
    
    $find(annotationListId).set_annotations(annotations);
}

function loadMap(annotations)
{
    var imagePanel = $find(imagePanelId);
    
    imagePanel._instance.Clear();
    
    for (var index = 0; index < annotations.length; index++)
        imagePanel._instance.AddShape(loadShape(annotations[index]));    
}

function loadEditor(annotation)
{
    var annotationList = $get(annotationListId);
    var annotationEditor = $get(annotationEditorId);
    var annotationTitleInput = $get(annotationTitleInputId);
    var annotationDescriptionInput = $get(annotationDescriptionInputId);
    var annotationSaveButton = $get(annotationSaveButtonId);
    var annotationCancelButton = $get(annotationCancelButtonId);
    var annotationDeleteButton = $get(annotationDeleteButtonId);
    
    annotationList.style.display = 'none';
    annotationEditor.style.display = 'block';
    annotationTitleInput.value = annotation.Title;
    annotationDescriptionInput.value = annotation.Description;
    
    setActiveShapeFormat(annotation._shape);
    $find(imagePanelId)._instance.PanToLatLong(annotation.Points[0]);
   
    annotationCancelButton.onclick = function()
    {    
        loadAnnotations();
        return false;
    };
    
    annotationDeleteButton.onclick = function()
    {    
        deleteAnnotation(annotation);
        return false;
    };
    
    annotationSaveButton.onclick = function()
    {
        annotation.Title = annotationTitleInput.value;
        annotation.Description = annotationDescriptionInput.value;
        saveAnnotation(annotation);
        return false;
    };
}

function deleteAnnotation(annotation)
{
    annotation._shape = null;
 
    var onSuccess = function(guid)
    {
        alert("Deleted.");
        loadAnnotations();
    }
    
    Frontend.FileWebService.DeleteAnnotation(annotation.Guid, onSuccess);
}

function saveAnnotation(annotation)
{
    annotation._shape = null;
 
    var onSuccess = function(guid)
    {
        alert("Saved.");
        annotation.Guid = guid;
        loadAnnotations();
    }
    
    Frontend.FileWebService.AddOrUpdateAnnotation(annotation, onSuccess);
}

function saveShape(annotation, shape)
{
    annotation.ShapeType = shape.GetType();
    annotation.Points = shape.GetPoints();
}

function loadShape(annotation)
{
    var shapeDescriptionFormat = "<b>{0}</b><br />{1}";

    annotation.Points = convertToLatLong(annotation.Points);    
    var shape = new VEShape(annotation.ShapeType, annotation.Points);
    
    shape.SetDescription(String.format(
        annotation.Title,
        annotation.Description.substring(1, 150)));
    
    setInactiveShapeFormat(shape);    
    
    annotation._shape = shape;
    shape._annotation = annotation;
    
    return shape;
}

function convertToLatLong(input)
{
    var output = [];
    
    for (var index = 0; index < input.length; index++)
        output.push(new VELatLong(input[index].Latitude, input[index].Longitude));
    
    return output;
}

function setInactiveShapeFormat(shape)
{
    shape.SetLineColor(new VEColor(0, 255, 0, 1));
    shape.SetFillColor(new VEColor(0, 255, 0, 0.1));
}

function setActiveShapeFormat(shape)
{
    shape.SetLineColor(new VEColor(255, 0, 0, 1));
    shape.SetFillColor(new VEColor(255, 0, 0, 0.1));
}

function annotationList_select(sender, e)
{
    loadEditor(e.get_annotation());
}

function drawingToggleButton_start(sender, e)
{
    var imagePanel = $find(imagePanelId);
    imagePanel.startDrawing(sender.shapeType);
}

function drawingToggleButton_stop(sender, e)
{
    var imagePanel = $find(imagePanelId);
    var shape = imagePanel.stopDrawing();
    
    var annotation = new Frontend.Annotation();
    annotation.Title = "New";
    saveShape(annotation, shape);
    saveAnnotation(annotation);
}

function imagePanel_shapeClick(sender, e)
{
    loadEditor(e.get_shape()._annotation);
}

function load()
{
    var imagePanel = $find(imagePanelId);
    var pushpinToggleButton = $find(pushpinToggleButtonId);
    var polylineToggleButton = $find(polylineToggleButtonId);
    var polygonToggleButton = $find(polygonToggleButtonId);
    var annotationList = $find(annotationListId);
    
    pushpinToggleButton.shapeType = VEShapeType.Pushpin;
    pushpinToggleButton.add_start(drawingToggleButton_start);
    pushpinToggleButton.add_stop(drawingToggleButton_stop);
    
    polylineToggleButton.shapeType = VEShapeType.Polyline;
    polylineToggleButton.add_start(drawingToggleButton_start);
    polylineToggleButton.add_stop(drawingToggleButton_stop);
    
    polygonToggleButton.shapeType = VEShapeType.Polygon;
    polygonToggleButton.add_start(drawingToggleButton_start);
    polygonToggleButton.add_stop(drawingToggleButton_stop);
   
    annotationList.add_select(annotationList_select);  
    
    imagePanel.add_shapeClick(imagePanel_shapeClick);
    
    loadAnnotations();
}

function unload()
{
    var annotationList = $find(annotationListId);
    annotationList.remove_select(annotationList_Select);
    
    //...
}

Sys.Application.add_load(load);
Sys.Application.add_unload(unload);
