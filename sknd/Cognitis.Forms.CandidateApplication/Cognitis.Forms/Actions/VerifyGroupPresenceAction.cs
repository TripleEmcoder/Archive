using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class VerifyGroupPresenceAction : GroupValidationAction
    {
        public VerifyGroupPresenceAction(IValidationAction condition, IGroupDefinition group) 
            : base(condition, group)
        {
        }

        public override bool Run(Browser browser)
        {
            return new GroupWrapper(browser, Group).GetFieldset().Exists;
        }

        public override string ToString()
        {
            return ToString(new { Group.Name });
        }
    }
}
