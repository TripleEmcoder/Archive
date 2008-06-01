/// <reference name='MicrosoftAjax.js'/>

Type.registerNamespace('Frontend');

Frontend.AnnotationTableSelectEventArgs = function(annotation)     
{     
    Frontend.AnnotationTableSelectEventArgs.initializeBase(this);     
    this._annotation = annotation;
}     
  
Frontend.AnnotationTableSelectEventArgs.prototype =     
{     
  get_annotation: function()     
  {        
    return this._annotation;
  },     
}     
  
Frontend.AnnotationTableSelectEventArgs.registerClass('Frontend.AnnotationTableSelectEventArgs', Sys.EventArgs);     

Frontend.AnnotationTableClientControl = function(element)
{
    Frontend.AnnotationTableClientControl.initializeBase(this, [element]);
    this._annotations = [];
}

Frontend.AnnotationTableClientControl.prototype = 
{
    initialize: function()
    {
        Frontend.AnnotationTableClientControl.callBaseMethod(this, 'initialize');
    },

    dispose: function()
    {
        Frontend.AnnotationTableClientControl.callBaseMethod(this, 'dispose');
    },

    get_annotations: function()
    {
        return this._annotations;
    },
    
    set_annotations: function(value)
    {
        this._annotations = value;
        this._update();
    },
    
    add_select: function(handler)
    {
        this.get_events().addHandler('select', handler);
    },
    
    remove_select: function(handler)
    {
        this.get_events().removeHandler('select', handler);
    },
    
    _update: function()
    {
        this.get_element().innerHTML = this._buildTable();
    },
    
    _buildTable: function()
    {
        var builder = new Sys.StringBuilder();
    
        builder.append('<tr>');
        builder.append('<th>Guid</th>');
        builder.append('<th>Title</th>');
        builder.append('<tr>');
        
        builder.appendLine();
    
        for (var index = 0; index < this._annotations.length; index++)
            builder.appendLine(this._buildRow(index));
            
        return builder.toString();
    },
    
    _buildRow: function(annotationIndex)
    {
        var linkFormat = 'javascript:Frontend.AnnotationTableClientControl._select(\'{0}\', {1})';
        var linkCellFormat = '<td><a href="{0}">{1}</a></td>';
        
        var link = String.format(linkFormat, this.get_id(), annotationIndex);

        var annotation = this._annotations[annotationIndex];
        var builder = new Sys.StringBuilder();
        
        builder.append('<tr>');
        builder.append(String.format(linkCellFormat, link, annotation.Guid));
        builder.append(String.format(linkCellFormat, link, annotation.Title));
        builder.append('</tr>');
        
        return builder.toString();
    },
    
    _select: function(index)
    {
        var handler = this.get_events().getHandler('select')
                
        if (handler)
            handler(this, new Frontend.AnnotationTableSelectEventArgs(this._annotations[index]));
    },
}

Frontend.AnnotationTableClientControl._select = function(id, index)
{
    $find(id)._select(index);
}

Frontend.AnnotationTableClientControl.registerClass('Frontend.AnnotationTableClientControl', Sys.UI.Control);

if (typeof(Sys) !== 'undefined') Sys.Application.notifyScriptLoaded();
