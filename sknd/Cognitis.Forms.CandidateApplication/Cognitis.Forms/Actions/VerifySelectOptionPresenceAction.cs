namespace Cognitis.Forms
{
    public class VerifySelectOptionPresenceAction : ValueValidationAction
    {
        public VerifySelectOptionPresenceAction(IValidationAction condition, IValueDefinition value) 
            : base(condition, value)
        {
        }
    }
}