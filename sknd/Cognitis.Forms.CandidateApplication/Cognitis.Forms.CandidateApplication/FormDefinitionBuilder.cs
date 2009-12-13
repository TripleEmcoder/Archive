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
                    "",
                    new FieldDefinition("field_candidate_first_name[{0}][value]", "Imię:", ""),
                    new FieldDefinition("field_candidate_last_name[{0}][value]", "Nazwisko:", ""),
                    new FieldDefinition("field_candidate_birth_date[{0}][value]", "Data urodzenia:", ""),
                    new FieldDefinition("field_candidate_phone_number[{0}][value]", "Numer telefonu:", ""),
                    new FieldDefinition("field_candidate_email_address[{0}][email]", "Adres e-mail:", "")
                    ),
                //new GroupDefinition(
                //    "",
                //    "Adres domowy",
                //    "",
                //    new FieldDefinition("field_candidate_home_address[{0}][street]", "Ulica:", ""),
                //    new FieldDefinition("field_candidate_home_address[{0}][city]", "Miast:", ""),
                //    new FieldDefinition("field_candidate_home_address[{0}][postal_code]", "Kod pocztowy:", "")
                //    ),
                //new FieldDefinition(
                //    "field_candidate_study_at_home[{0}][value]",
                //    "Adres w trakcie studiów taki sam jak domowy:",
                //    ""),
                //new GroupDefinition(
                //    "",
                //    "Adres w trakcie studiów",
                //    "",
                //    new FieldDefinition("field_candidate_study_address[{0}][street]", "Ulica:", ""),
                //    new FieldDefinition("field_candidate_study_address[{0}][city]", "Miast:", ""),
                //    new FieldDefinition("field_candidate_study_address[{0}][postal_code]", "Kod pocztowy:", "")
                //    ),
                //new GroupDefinition(
                //    "",
                //    "Główne studia",
                //    "",
                //    new FieldDefinition("field_candidate_study_main[0][field_candidate_study_uni][value]", "Uczelnia:", ""),
                //    new FieldDefinition("field_candidate_study_main[0][field_candidate_study_uni_other][value]", "Inna uczelnia:", ""),
                //    new FieldDefinition("field_candidate_study_main[0][field_candidate_study_degree][value]", "Stopień:", ""),
                //    new FieldDefinition("field_candidate_study_main[0][field_candidate_study_major][value]", "Kierunek:", ""),
                //    new FieldDefinition("field_candidate_study_main[0][field_candidate_study_minor][value]", "Specjalność:", ""),
                //    new FieldDefinition("field_candidate_study_main[0][field_candidate_study_year][value]", "Rok:", "")
                //    ),
                new FieldDefinition(
                    "field_candidate_study_extra[{0}][value]",
                    "Dodatkowe studia:",
                    ""
                    ),
                new FieldDefinition(
                    "field_candidate_org_activity[{0}][value]",
                    "Działalność w organizacjach:",
                    "Czy działałeś dotąd w jakichś organizacjach? Jeśli tak to w jakich i co w nich robiłeś? (np. organizacjach studenckich, kołach naukowych, samorządzie studenckim lub uczniowskim, organizacjach politycznych, religijnych, charytatywnych, społecznych, klubach sportowych, harcerstwie, itp.)"
                    ),
                new FieldDefinition(
                    "field_candidate_study_results[{0}][value]",
                    "Wyniki w nauce:",
                    "Jakbyś określił swoje dotychczasowe wyniki na uczelni (studenci II roku i wyższych), lub w szkole średniej (studenci I roku)?"
                    ),
                new FieldDefinition(
                    "field_candidate_competition_part[{0}][value]",
                    "Udział w konkursach:",
                    "Czy brałeś udział w konkursach lub olimpiadach? Jeśli tak, to w jakich i z jakim skutkiem?"
                    ),
                new FieldDefinition(
                    "field_candidate_other_achieves[{0}][value]",
                    "Inne osiągnięcia:",
                    "Czy masz jakieś pozanaukowe osiągnięcia? Jeśli tak, to jakie?"
                    ),
                new FieldDefinition(
                    "field_candidate_work_experience[{0}][value]",
                    "Doświadczenie zawodowe:",
                    "Czy masz jakieś doświadczenia praktyczne związane z przedmiotem Twoich studiów? (dot. pracy, praktyk, staży). Jeśli tak to gdzie i co robiłeś?"
                    ),
                new FieldDefinition(
                    "field_candidate_residence_abroad[{0}][value]",
                    "Pobyt zagraniczny:",
                    "Czy przebywałeś(aś) dłuższy okres czasu (co najmniej 2 miesiące bez przerwy) za granicą? Jeśli tak to w jakim kraju, jaka była okazja ku temu? (studia, praca, staż, wakacje)"
                    ),
                //new GroupDefinition(
                //    "",
                //    "Znajomość języków obcych",
                //    "Jak oceniasz swoją znajomość języków obcych?",
                //    new FieldDefinition("field_candidate_lang_skill_en[{0}][value]", "Znajomość języka angielskiego:", ""),
                //    new FieldDefinition("field_candidate_lang_skill_de[{0}][value]", "Znajomość języka niemieckiego:", ""),
                //    new FieldDefinition("field_candidate_lang_skill_fr[{0}][value]", "Znajomość języka francuskiego:", ""),
                //    new FieldDefinition("field_candidate_lang_skill_es[{0}][value]", "Znajomość języka hiszpańskiego:", ""),
                //    new FieldDefinition("field_candidate_lang_skill_ru[{0}][value]", "Znajomość języka rosyjskiego:", ""),
                //    new FieldDefinition("field_candidate_lang_other_name[{0}][value]", "Nazwa innego języka:", ""),
                //    new FieldDefinition("field_candidate_lang_other_skill[{0}][value]", "Znajomość innego niemieckiego:", "")
                //    ),
                new FieldDefinition(
                    "field_candidate_language_certs[{0}][value]",
                    "Certyfikaty językowe:",
                    "Czy posiadasz jakieś certyfikaty językowe? Jeśli tak to jakie?"
                    ),
                new FieldDefinition(
                    "field_candidate_own_interests[{0}][value]",
                    "Zainteresowania własne:",
                    "Czy posiadasz jakieś certyfikaty językowe? Jeśli tak to jakie?"
                    ),
                //new FieldDefinition(
                //    "field_candidate_prcvd_qualities[{0}][value]",
                //    "Cechy osobiste:",
                //    "Podaj trzy przymiotniki które najlepiej Cię opisują."
                //    ),
                new FieldDefinition(
                    "field_candidate_apply_reasons[{0}][value]",
                    "Powody aplikowania:",
                    "Co zachęciło Cię do aplikowania do Cognitis?"
                    ),
                new FieldDefinition(
                    "field_candidate_planned_activity[{0}][value]",
                    "Planowana działalność:",
                    "W jakich obszarach chciałbyś(aś) działać i jakie umiejętności/cechy chciałbyś(aś) rozwinąć w Stowarzyszeniu?"
                    ),
                new FieldDefinition(
                    "field_candidate_int_references[{0}][value]",
                    "Znajomi w Stowarzyszeniu:",
                    "Czy znasz kogoś będącego członkiem SKND? Podaj jego imię i nazwisko (możesz wpisać więcej niż 1 osobę)"
                    ),
                new SelectListFieldDefinition(
                    "field_candidate_ref_channel[value]",
                    "Źródło informacji:",
                    "Skąd dowiedziałeś się o możliwości dołączenia do Cognitis?",
                    new ValueDefinition("151", "Członek Cognitis – jeśli chcesz, wpisz poniżej kto"),
                    new ValueDefinition("152", "Inna strona Internetowa - wpisz poniżej jaka")
                    ),
                new FieldDefinition(
                    "field_candidate_ref_chnnl_other[{0}][value]",
                    "Inne źródło informacj:",
                    "Czy znasz kogoś będącego członkiem SKND? Podaj jego imię i nazwisko (możesz wpisać więcej niż 1 osobę)"
                    ),
                new FieldDefinition(
                    "field_candidate_data_agreement[{0}][value]",
                    "Zgoda na przetwarzanie danych:",
                    "Wyrażam zgodę na przechowywanie i przetwarzanie moich danych osobowych zawartych w powyższej aplikacji przez SKND (zgodnie z Ustawą z 2002 roku o Ochronie Danych Osobowych, Dz. U. Nr 101 poz, 926 ze zmianami)."
                    )
                );
        }
    }
}
