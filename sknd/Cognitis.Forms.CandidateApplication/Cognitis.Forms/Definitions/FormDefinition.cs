using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms
{
    public class FormDefinition : IFormDefinition
    {
        public Uri Uri{ get; private set; }
        public IEnumerable<IElementDefinition> Elements { get; private set; }
        
        public FormDefinition(Uri uri, IEnumerable<IElementDefinition> elements)
        {
            Uri = uri;
            Elements = elements;
        }

        public FormDefinition(Uri uri, params IElementDefinition[] elements)
        {
            Uri = uri;
            Elements = elements;
        }

        public IEnumerable<IValidationAction> BuildValidationActions(IValidationAction condition)
        {
            foreach (IElementDefinition element in Elements)
                foreach (IValidationAction action in element.BuildValidationActions(condition))
                    yield return action;
        }
    }
}
