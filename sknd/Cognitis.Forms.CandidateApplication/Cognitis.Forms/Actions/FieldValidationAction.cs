using WatiN.Core;

namespace Cognitis.Forms
{
    public class FieldValidationAction : ValidationAction
    {
        public IFieldDefinition Field { get; private set; }

        public FieldValidationAction(IValidationAction condition, IFieldDefinition field) 
            : base(condition)
        {
            Field = field;
        }
    }
}