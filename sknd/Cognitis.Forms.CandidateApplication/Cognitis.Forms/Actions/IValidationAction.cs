using WatiN.Core;

namespace Cognitis.Forms
{
    public interface IValidationAction
    {
        IValidationAction Condition { get; }
        bool Run(Browser browser);
    }
}