namespace Cognitis.Forms
{
    public class FieldValidationAction : ValidationAction
    {
        public FieldValidationAction(IValidationAction condition, IFieldDefinition field) 
            : base(condition)
        {
        }
    }
}