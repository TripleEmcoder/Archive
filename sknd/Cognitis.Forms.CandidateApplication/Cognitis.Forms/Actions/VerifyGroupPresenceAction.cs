using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    class VerifyGroupPresenceAction : GroupValidationAction
    {
        public VerifyGroupPresenceAction(IValidationAction condition, IGroupDefinition group) 
            : base(condition, group)
        {
        }

        public override bool Run(Browser browser)
        {
            return browser.Element(Find.ByClass(Group.Name.Replace("_", "-"))).Exists;
        }
    }
}
