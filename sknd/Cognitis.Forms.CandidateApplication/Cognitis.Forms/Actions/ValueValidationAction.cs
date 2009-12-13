namespace Cognitis.Forms
{
    public class ValueValidationAction : ValidationAction
    {
        public IValueDefinition Value { get; private set; }

        public ValueValidationAction(IValidationAction condition, IValueDefinition value) 
            : base(condition)
        {
            Value = value;
        }
    }
}