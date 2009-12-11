using System.Collections.Generic;

namespace Cognitis.Forms
{
    public interface IFieldDefinition : IElementDefinition
    {
        string Name { get; }
        string Title { get; }
        string Description { get; }
        //int MinValues { get; }
        //int MaxValues { get; }
        //IEnumerable<IValidInput> ValidInputs { get; }
        //IEnumerable<IInvalidInput> InvalidInputs { get; }
    }
}