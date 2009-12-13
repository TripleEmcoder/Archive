using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using WatiN.Core;

namespace Cognitis.Forms
{
    public class VerifyGroupTitleAction : GroupValidationAction
    {
        public VerifyGroupTitleAction(IValidationAction condition, IGroupDefinition group)
            : base(condition, group)
        {
        }

        public override bool Run(Browser browser)
        {
            return new GroupWrapper(browser, Group).GetLegend().Text == Group.Title;
        }

        public override string ToString()
        {
            return ToString(new { Group.Name, Group.Title });
        }
    }
}
