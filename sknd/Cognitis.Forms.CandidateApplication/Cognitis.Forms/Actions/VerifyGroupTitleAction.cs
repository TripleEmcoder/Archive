using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    class VerifyGroupTitleAction : GroupValidationAction
    {
        public VerifyGroupTitleAction(IValidationAction condition, IGroupDefinition group) 
            : base(condition, group)
        {
        }
    }
}
