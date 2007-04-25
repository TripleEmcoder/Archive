(defrule rule_stanowisko1
	(answer "lokalizacja1" "nie wiem"|"w domu"|"w ogrodzie")
=>
	(assert (property assert "stanowisko" "słoneczne"))
	(assert (property assert "stanowisko" "widne"))
	(assert (property assert "stanowisko" "półcieniste"))
	(assert (property assert "stanowisko" "cieniste"))
	(assert (property assert "podlewanie" "częste"))
	(assert (property assert "podlewanie" "umiarkowane"))
	(assert (property assert "podlewanie" "rzadkie"))
)
	
(defrule rule_stanowisko2
	(answer "lokalizacja3" "zdala od okna")
=>
	(assert (property retract "stanowisko" "słoneczne"))
	(assert (property retract "stanowisko" "widne"))
)

(defrule rule_stanowisko3
	(answer "orientacja" "od północy")
=>
	(assert (property retract "stanowisko" "słoneczne"))
)

(defrule rule_stanowisko4
	(answer "orientacja" "od południa")
=>
	(assert (property retract "stanowisko" "cieniste"))
)

(defrule rule_stanowisko5
	(answer "osłonięcie1" "wśród budynków"|"wśród drzew")
=>
	(assert (property retract "stanowisko" "słoneczne"))
)

(defrule rule_stanowisko6
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
	(assert (property retract "nawożenie" "umiarkowanie"))
	(assert (property retract "nawożenie" "rzadkie"))
)

(defrule rule_nawozenie2
	(answer "prochnica" "nie")
	(answer "pielęgnacja" "nie")
=>
	(assert (property retract "nawożenie" "częste"))
	(assert (property retract "nawożenie" "umiarkowanie"))
)

(defrule rule_nawozenie3
	(answer "lokalizacja1" "w domu")
	(answer "pielęgnacja" "nie")
=>
	(assert (property retract "nawożenie" "częste"))
	(assert (property retract "nawożenie" "umiarkowanie"))
)

(defrule rule_kwiaty1
	(answer "kwiaty1" "nie")
=>
	(assert (property assert "kwiaty" "brak"))
)

(defrule rule_kwiaty2
	(answer "kwiaty2" ?kolor)
=>
	(assert (property assert "kwiaty" ?kolor))
)
