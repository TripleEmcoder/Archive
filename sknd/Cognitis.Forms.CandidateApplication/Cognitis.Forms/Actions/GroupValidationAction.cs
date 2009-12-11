using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    class GroupValidationAction : ValidationAction
    {
        public IGroupDefinition Group { get; private set; }

        public GroupValidationAction(IValidationAction condition, IGroupDefinition group)
            : base(condition)
        {
            Group = group;
        }
    }
}
