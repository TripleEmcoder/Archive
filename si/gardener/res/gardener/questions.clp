(defrule question_lokalizacja1
	(step "lokalizacja1")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w domu;w ogrodzie;nie wiem"))
)
(defrule question_lokalizacja2
	(step "lokalizacja2")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w pokoju;na balkonie;na parapecie;nie wiem"))
)
(defrule question_lokalizacja3
	(step "lokalizacja3")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w pobliżu okna;zdala od okna;nie wiem"))
)
(defrule question_orientacja
	(step "orientacja")
=>
	(assert (question "Jakie jest umiejscowienie stanowiska?;od południa;od północy;nie wiem"))
)
(defrule question_osloniecie1
	(step "osłonięcie1")
=>
	(assert (question "Jakie jest umiejscowienie stanowiska?;wśrod budynków;wśrod drzew;nieosłonięte;nie wiem"))
)
(defrule question_osloniecie2
	(step "osłonięcie2")
=>
	(assert (question "Czy stanowisko jest osłonięte od opadów?;nie;nie wiem;tak"))
)
(defrule question_opady
	(step "opady")
=>
	(assert (question "Jakie jest występowanie opadów?;częste;rzadkie;przeciętne;nie wiem"))
)
(defrule question_sikawki
	(step "sikawki")
=>
	(assert (question "Czy automatyczne podlewanie sięga stanowiska?;tak;nie;nie wiem"))
)
(defrule question_prochnica
	(step "próchnica")
=>
	(assert (question "Czy na stanowisku występuje próchnica?;tak;nie;nie wiem"))
)
(defrule question_osloniecie3
	(step "osłonięcie3")
=>
	(assert (question "Czy stanowisko jest osłonięte od wiatru?;tak;nie;nie wiem"))
)
(defrule question_kwiaty1
	(step "kwiaty1")
=>
	(assert (question "Czy roślina ma mieć kwiaty?;tak;nie;obojętnie"))
)
(defrule question_kwiaty2
	(step "kwiaty2")
=>
	(assert (question "Jakiego koloru mają być kwiaty?;białe;czerwone;fioletowe;malinowe;niebieskie;pomarańczowe;różowe;żółte;różnobarwne;dowolne"))
)
(defrule question_pochodzenie
	(step "pochodzenie")
=>
	(assert (question "Skąd ma pochodzić roślina?;...;dowolne"))
)
(defrule question_pielegnacja
	(step "pielęgnacja")
=>
	(assert (question "Czy masz czas pielęgnowac roślinę?;tak;nie;nie wiem"))
)
(defrule question_start
	(step "START")
=>
	(assert (question "START;solid"))
)
(defrule question_stop
	(step "STOP")
=>
	(assert (question "STOP"))
)
(defrule answer_lokalizacja1_w_domu
	?i <- (step "lokalizacja1")
	?j <- (answer "w domu")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "lokalizacja2"))
)
(defrule answer_lokalizacja1_w_ogrodzie
	?i <- (step "lokalizacja1")
	?j <- (answer "w ogrodzie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie2"))
)
(defrule answer_lokalizacja1_nie_wiem
	?i <- (step "lokalizacja1")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_lokalizacja2_w_pokoju
	?i <- (step "lokalizacja2")
	?j <- (answer "w pokoju")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "lokalizacja3"))
)
(defrule answer_lokalizacja2_na_balkonie
	?i <- (step "lokalizacja2")
	?j <- (answer "na balkonie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)
(defrule answer_lokalizacja2_na_parapecie
	?i <- (step "lokalizacja2")
	?j <- (answer "na parapecie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)
(defrule answer_lokalizacja2_nie_wiem
	?i <- (step "lokalizacja2")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_lokalizacja3_w_poblizu_okna
	?i <- (step "lokalizacja3")
	?j <- (answer "w pobliżu okna")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)
(defrule answer_lokalizacja3_zdala_od_okna
	?i <- (step "lokalizacja3")
	?j <- (answer "zdala od okna")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_lokalizacja3_nie_wiem
	?i <- (step "lokalizacja3")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_orientacja_od_poludnia
	?i <- (step "orientacja")
	?j <- (answer "od południa")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie1"))
)
(defrule answer_orientacja_od_polnocy
	?i <- (step "orientacja")
	?j <- (answer "od północy")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_orientacja_nie_wiem
	?i <- (step "orientacja")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_osloniecie1_wsrod_budynkow
	?i <- (step "osłonięcie1")
	?j <- (answer "wśrod budynków")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_osloniecie1_wsrod_drzew
	?i <- (step "osłonięcie1")
	?j <- (answer "wśrod drzew")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_osloniecie1_nieosloniete
	?i <- (step "osłonięcie1")
	?j <- (answer "nieosłonięte")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_osloniecie1_nie_wiem
	?i <- (step "osłonięcie1")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)
(defrule answer_osloniecie2_nie
	?i <- (step "osłonięcie2")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "opady"))
)
(defrule answer_osloniecie2_nie_wiem
	?i <- (step "osłonięcie2")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "opady"))
)
(defrule answer_osloniecie2_tak
	?i <- (step "osłonięcie2")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)
(defrule answer_opady_czeste
	?i <- (step "opady")
	?j <- (answer "częste")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)
(defrule answer_opady_rzadkie
	?i <- (step "opady")
	?j <- (answer "rzadkie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)
(defrule answer_opady_przecietne
	?i <- (step "opady")
	?j <- (answer "przeciętne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)
(defrule answer_opady_nie_wiem
	?i <- (step "opady")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)
(defrule answer_sikawki_tak
	?i <- (step "sikawki")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "próchnica"))
)
(defrule answer_sikawki_nie
	?i <- (step "sikawki")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "próchnica"))
)
(defrule answer_sikawki_nie_wiem
	?i <- (step "sikawki")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "próchnica"))
)
(defrule answer_prochnica_tak
	?i <- (step "próchnica")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie3"))
)
(defrule answer_prochnica_nie
	?i <- (step "próchnica")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie3"))
)
(defrule answer_prochnica_nie_wiem
	?i <- (step "próchnica")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie3"))
)
(defrule answer_osloniecie3_tak
	?i <- (step "osłonięcie3")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)
(defrule answer_osloniecie3_nie
	?i <- (step "osłonięcie3")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)
(defrule answer_osloniecie3_nie_wiem
	?i <- (step "osłonięcie3")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)
(defrule answer_kwiaty1_tak
	?i <- (step "kwiaty1")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty2"))
)
(defrule answer_kwiaty1_nie
	?i <- (step "kwiaty1")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty1_obojetnie
	?i <- (step "kwiaty1")
	?j <- (answer "obojętnie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_biale
	?i <- (step "kwiaty2")
	?j <- (answer "białe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_czerwone
	?i <- (step "kwiaty2")
	?j <- (answer "czerwone")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_fioletowe
	?i <- (step "kwiaty2")
	?j <- (answer "fioletowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_malinowe
	?i <- (step "kwiaty2")
	?j <- (answer "malinowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_niebieskie
	?i <- (step "kwiaty2")
	?j <- (answer "niebieskie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_pomaranczowe
	?i <- (step "kwiaty2")
	?j <- (answer "pomarańczowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_rozowe
	?i <- (step "kwiaty2")
	?j <- (answer "różowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_zolte
	?i <- (step "kwiaty2")
	?j <- (answer "żółte")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_roznobarwne
	?i <- (step "kwiaty2")
	?j <- (answer "różnobarwne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kwiaty2_dowolne
	?i <- (step "kwiaty2")
	?j <- (answer "dowolne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_pochodzenie_...
	?i <- (step "pochodzenie")
	?j <- (answer "...")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)
(defrule answer_pochodzenie_dowolne
	?i <- (step "pochodzenie")
	?j <- (answer "dowolne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)
(defrule answer_pielegnacja_tak
	?i <- (step "pielęgnacja")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "STOP"))
)
(defrule answer_pielegnacja_nie
	?i <- (step "pielęgnacja")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "STOP"))
)
(defrule answer_pielegnacja_nie_wiem
	?i <- (step "pielęgnacja")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "STOP"))
)
(defrule answer_start_solid
	?i <- (step "START")
	?j <- (answer "solid")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "lokalizacja1"))
)
