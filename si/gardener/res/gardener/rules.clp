(defrule tool_initialize_properties
	(initial-fact)
=>
	(assert (property "grupa" "=" "balkonowe"))
	(assert (property "grupa" "=" "byliny"))
	(assert (property "grupa" "=" "domowe"))
	(assert (property "grupa" "=" "iglaste"))
	(assert (property "grupa" "=" "krzewy"))
	(assert (property "grupa" "=" "trawy"))
	(assert (property "stanowisko" "=" "słoneczne"))
	(assert (property "stanowisko" "=" "widne"))
	(assert (property "stanowisko" "=" "półcieniste"))
	(assert (property "stanowisko" "=" "cieniste"))
	(assert (property "podlewanie" "=" "częste"))
	(assert (property "podlewanie" "=" "umiarkowane"))
	(assert (property "podlewanie" "=" "rzadkie"))
	(assert (property "nawożenie" "=" "częste"))
	(assert (property "nawożenie" "=" "umiarkowane"))
	(assert (property "nawożenie" "=" "rzadkie"))
	(assert (property "kwiaty" "=" "brak"))
	(assert (property "kwiaty" "=" "dowolne"))
	(assert (property "pochodzenie" "=" "dowolne"))
	(assert (property "wysokość" ">=" 0))
	(assert (property "wysokość" "<=" 1000))
)

(defrule rule_stanowisko1
	(answer "lokalizacja1" "w domu")
=>
	(assert (property "grupa" "!=" "byliny"))
	(assert (property "grupa" "!=" "iglaste"))
	(assert (property "grupa" "!=" "krzewy"))
	(assert (property "grupa" "!=" "trawy"))
	(assert (property "wysokość" "<=" 200))
)

(defrule rule_stanowisko2
	(answer "lokalizacja1" "w ogrodzie")
=>
	(assert (property "grupa" "!=" "balkonowe"))
	(assert (property "grupa" "!=" "domowe"))
)

(defrule rule_stanowisko3
	(answer "lokalizacja2" "w pokoju"|"na parapecie")
=>
	(assert (property "grupa" "!=" "balkonowe"))
)

(defrule rule_stanowisko4
	(answer "lokalizacja2" "na balkonie")
=>
	(assert (property "grupa" "!=" "domowe"))
)

(defrule rule_stanowisko5
	(answer "lokalizacja3" "zdala od okna")
=>
	(assert (property "stanowisko" "!=" "słoneczne"))
	(assert (property "stanowisko" "!=" "widne"))
)

(defrule rule_stanowisko6
	(answer "orientacja" "od północy")
=>
	(assert (property "stanowisko" "!=" "słoneczne"))
)

(defrule rule_stanowisko7
	(answer "osłonięcie1" "wśród budynków"|"wśród drzew")
=>
	(assert (property "stanowisko" "!=" "słoneczne"))
)

(defrule rule_stanowisko8
	(answer "osłonięcie1" ~"wśród budynków"&~"wśród drzew")
=>
	(assert (property "stanowisko" "!=" "półcieniste"))
	(assert (property "stanowisko" "!=" "cieniste"))
)

(defrule rule_stanowisko89
	(answer "osłonięcie2" "tak")
=>
	(assert (property "wysokość" "<=" 200))
)

(defrule rule_podlewanie1
	(answer "osłonięcie2" "tak")
	(answer "sikawki" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property "podlewanie" "!=" "częste"))
	(assert (property "podlewanie" "!=" "umiarkowane"))
)

(defrule rule_podlewanie2
	(answer "osłonięcie2" "nie")
	(answer "opady" "częste")
=>
	(assert (property "podlewanie" "!=" "umiarkowane"))
	(assert (property "podlewanie" "!=" "rzadkie"))
)


(defrule rule_podlewanie3
	(answer "osłonięcie2" "nie")
	(answer "opady" "przeciętne")
=>
	(assert (property "podlewanie" "!=" "rzadkie"))
)

(defrule rule_podlewanie4
	(answer "osłonięcie2" "nie")
	(answer "opady" "rzadkie")
	(answer "sikawki" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property "podlewanie" "!=" "umiarkowane"))
	(assert (property "podlewanie" "!=" "częste"))
)

(defrule rule_podlewanie5
	(answer "osłonięcie2" "nie")
	(answer "opady" "przeciętne")
	(answer "sikawki" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property "podlewanie" "!=" "częste"))
)

(defrule rule_nawozenie1
	(answer "prochnica" "tak")
=>
	(assert (property "nawożenie" "!=" "umiarkowane"))
	(assert (property "nawożenie" "!=" "rzadkie"))
)

(defrule rule_nawozenie2
	(answer "prochnica" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property "nawożenie" "!=" "częste"))
	(assert (property "nawożenie" "!=" "umiarkowane"))
)

(defrule rule_nawozenie3
	(answer "lokalizacja1" "w domu")
	(answer "pielęgnacja" "nie")
=>
	(assert (property "nawożenie" "!=" "częste"))
	(assert (property "nawożenie" "!=" "umiarkowane"))
)

(defrule rule_pochodzenie
	(answer "pochodzenie" ?pochodzenie&~"obojętnie")
=>
	(assert (property "pochodzenie" "!=" "dowolne"))
	(assert (property "pochodzenie" "=" ?pochodzenie))
)

(defrule rule_kwiaty1
	(answer "kwiaty1" "nie")
=>
	(assert (property "kwiaty" "!=" "dowolne"))
)

(defrule rule_kwiaty2
	(answer "kwiaty2" ?kolor&~"dowolne")
=>
	(assert (property "kwiaty" "!=" "dowolne"))
	(assert (property "kwiaty" "=" ?kolor))
)
