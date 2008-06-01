/// <reference name='MicrosoftAjax.js'/>

Type.registerNamespace('Frontend');

Frontend.AnnotationListSelectEventArgs = function(annotation)     
{     
    Frontend.AnnotationListSelectEventArgs.initializeBase(this);     
    this._annotation = annotation;
}     
  
Frontend.AnnotationListSelectEventArgs.prototype =     
{     
  get_annotation: function()     
  {        
    return this._annotation;
  },     
}     
  
Frontend.AnnotationListSelectEventArgs.registerClass('Frontend.AnnotationListSelectEventArgs', Sys.EventArgs);     

Frontend.AnnotationListClientControl = function(element)
{
    Frontend.AnnotationListClientControl.initializeBase(this, [element]);
    this._annotations = [];
}

Frontend.AnnotationListClientControl.prototype = 
{
    initialize: function()
    {
        Frontend.AnnotationListClientControl.callBaseMethod(this, 'initialize');
    },

    dispose: function()
    {
        Frontend.AnnotationListClientControl.callBaseMethod(this, 'dispose');
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
        builder.append('<th>Added</th>');
        builder.append('<th>Title</th>');
        builder.append('<th>Description</th>');
        builder.append('<tr>');
        
        builder.appendLine();
    
        for (var index = 0; index < this._annotations.length; index++)
            builder.appendLine(this._buildRow(index));
            
        return builder.toString();
    },
    
    _buildRow: function(annotationIndex)
    {
        var linkFormat = 'javascript:Frontend.AnnotationListClientControl._select(\'{0}\', {1})';
        var linkCellFormat = '<td><a href="{0}">{1}</a></td>';
        var normalCellFormat = '<td>{0}</td>';
        
        var link = String.format(linkFormat, this.get_id(), annotationIndex);

        var annotation = this._annotations[annotationIndex];
        var builder = new Sys.StringBuilder();
        
        builder.append('<tr>');
        builder.append(String.format(linkCellFormat, link, annotation.Added.toLocaleString()));
        builder.append(String.format(linkCellFormat, link, annotation.Title));
        builder.append(String.format(normalCellFormat, annotation.Description.substring(0, 150)));
        builder.append('</tr>');
        
        return builder.toString();
    },
    
    _select: function(index)
    {
        var handler = this.get_events().getHandler('select')
                
        if (handler)
            handler(this, new Frontend.AnnotationListSelectEventArgs(this._annotations[index]));
    },
}

Frontend.AnnotationListClientControl._select = function(id, index)
{
    $find(id)._select(index);
}

Frontend.AnnotationListClientControl.registerClass('Frontend.AnnotationListClientControl', Sys.UI.Control);

if (typeof(Sys) !== 'undefined') Sys.Application.notifyScriptLoaded();
