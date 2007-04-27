(defrule tool_initial_properties
	(initial-fact)
=>
	(assert (property assert "grupa" "balkonowe"))
	(assert (property assert "grupa" "byliny"))
	(assert (property assert "grupa" "domowe"))
	(assert (property assert "grupa" "iglaste"))
	(assert (property assert "grupa" "krzewy"))
	(assert (property assert "grupa" "trawy"))
	(assert (property assert "stanowisko" "słoneczne"))
	(assert (property assert "stanowisko" "widne"))
	(assert (property assert "stanowisko" "półcieniste"))
	(assert (property assert "stanowisko" "cieniste"))
	(assert (property assert "podlewanie" "częste"))
	(assert (property assert "podlewanie" "umiarkowane"))
	(assert (property assert "podlewanie" "rzadkie"))
	(assert (property assert "nawożenie" "częste"))
	(assert (property assert "nawożenie" "umiarkowane"))
	(assert (property assert "nawożenie" "rzadkie"))
	(assert (property assert "pochodzenie" "dowolne"))
	(assert (property assert "kwiaty" "dowolne"))
)

(defrule rule_stanowisko1
	(answer "lokalizacja1" "w domu")
=>
	(assert (property retract "grupa" "byliny"))
	(assert (property retract "grupa" "iglaste"))
	(assert (property retract "grupa" "krzewy"))
	(assert (property retract "grupa" "trawy"))
)

(defrule rule_stanowisko2
	(answer "lokalizacja2" "w pokoju"|"na parapecie")
=>
	(assert (property retract "grupa" "balkonowe"))
)

(defrule rule_stanowisko3
	(answer "lokalizacja2" "na balkonie")
=>
	(assert (property retract "grupa" "domowe"))
)

(defrule rule_stanowisko4
	(answer "lokalizacja3" "zdala od okna")
=>
	(assert (property retract "stanowisko" "słoneczne"))
	(assert (property retract "stanowisko" "widne"))
)

(defrule rule_stanowisko5
	(answer "orientacja" "od północy")
=>
	(assert (property retract "stanowisko" "słoneczne"))
)

(defrule rule_stanowisko6
	(answer "orientacja" "od południa")
=>
	(assert (property retract "stanowisko" "cieniste"))
)

(defrule rule_stanowisko7
	(answer "osłonięcie1" "wśród budynków"|"wśród drzew")
=>
	(assert (property retract "stanowisko" "słoneczne"))
)

(defrule rule_stanowisko8
	(answer "osłonięcie1" "wśród budynków"|"wśród drzew")
=>
	(assert (property retract "stanowisko" "słoneczne"))
)

(defrule rule_podlewanie1
	(answer "osłonięcie2" "tak")
	(answer "sikawki" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property retract "podlewanie" "częste"))
	(assert (property retract "podlewanie" "umiarkowane"))
)

(defrule rule_podlewanie2
	(answer "osłonięcie2" "nie")
	(answer "opady" "częste")
=>
	(assert (property retract "podlewanie" "umiarkowanie"))
	(assert (property retract "podlewanie" "rzadko"))
)

(defrule rule_podlewanie3
	(answer "osłonięcie2" "nie")
	(answer "opady" "przeciętne")
=>
	(assert (property retract "podlewanie" "rzadko"))
)

(defrule rule_podlewanie4
	(answer "osłonięcie2" "nie")
	(answer "opady" "rzadkie")
	(answer "sikawki" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property retract "podlewanie" "umiarkowane"))
	(assert (property retract "podlewanie" "częśte"))
)

(defrule rule_podlewanie5
	(answer "osłonięcie2" "nie")
	(answer "opady" "przeciętne")
	(answer "sikawki" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property retract "podlewanie" "częste"))
)

(defrule rule_nawozenie1
	(answer "prochnica" "tak")
=>
	(assert (property retract "nawożenie" "umiarkowane"))
	(assert (property retract "nawożenie" "rzadkie"))
)

(defrule rule_nawozenie2
	(answer "prochnica" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property retract "nawożenie" "częste"))
	(assert (property retract "nawożenie" "umiarkowane"))
)

(defrule rule_nawozenie3
	(answer "lokalizacja1" "w domu")
	(answer "pielęgnacja" "nie")
=>
	(assert (property retract "nawożenie" "częste"))
	(assert (property retract "nawożenie" "umiarkowane"))
)

(defrule rule_pochodzenie
	(answer "pochodzenie" ?pochodzenie&~"obojętnie")
=>
	(assert (property retract "pochodzenie" "dowolne"))
	(assert (property assert "pochodzenie" ?pochodzenie))
)

(defrule rule_kwiaty1
	(answer "kwiaty1" "nie")
=>
	(assert (property assert "kwiaty" "brak"))
)

(defrule rule_kwiaty2
	(answer "kwiaty2" ?kolor&~"dowolne")
=>
	(assert (property retract "kwiaty" "dowolne"))
	(assert (property assert "kwiaty" ?kolor))
)
