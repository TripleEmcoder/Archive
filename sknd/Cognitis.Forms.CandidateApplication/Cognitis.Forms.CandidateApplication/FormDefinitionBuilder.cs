using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cognitis.Forms.CandidateApplication
{
    public class FormDefinitionBuilder : IFormDefinitionBuilder
    {
        public IEnumerable<IFormDefinition> BuildFormDefinitions(Uri baseUri)
        {
            yield return new FormDefinition(
                new Uri(baseUri, "pl/node/add/application-candidate"),
                new GroupDefinition(
                    "group_candidate_personal_info",
                    "Dane osobowe",
                    new FieldDefinition("field_candidate_first_name", "Imię", ""),
                    new FieldDefinition("field_candidate_last_name", "Nazwisko", "")
                    ),
                new GroupDefinition(
                    "group_candidate_home_address",
                    "Adres domowy",
                    new FieldDefinition("field_candidate_first_name", "Imię", ""),
                    new FieldDefinition("field_candidate_last_name", "Nazwisko", "")
                    )
                );
        }
    }
}
