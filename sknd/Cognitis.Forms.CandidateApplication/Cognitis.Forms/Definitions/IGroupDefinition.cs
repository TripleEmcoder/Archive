﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public interface IGroupDefinition : IElementDefinition
    {
        IEnumerable<IFieldDefinition> Fields { get; }
    }
}
