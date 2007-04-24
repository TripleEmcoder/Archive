(defrule question_lokalizacja1
	(step "lokalizacja1")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w domu;w ogrodzie"))
)
(defrule question_lokalizacja2
	(step "lokalizacja2")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w pokoju;na balkonie;na parapecie"))
)
(defrule question_lokalizacja3
	(step "lokalizacja3")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w pobliżu okna;zdala od okna"))
)
(defrule question_orientacja
	(step "orientacja")
=>
	(assert (question "Jakie jest umiejscowienie okna/balkonu?;od południa;od północy"))
)
(defrule question_osloniecie1
	(step "osłonięcie1")
=>
	(assert (question "Jakie jest umiejscowienie okna/balkonu?;wśrod drzew;nieosłonięte;wśrod budynków"))
)
(defrule question_pielegnacja
	(step "pielęgnacja")
=>
	(assert (question "Czy masz czas pielęgnowac roślinę?;tak;nie"))
)
(defrule question_naslonecznienie
	(step "nasłonecznienie")
=>
	(assert (question "Jakie jest planowane stanowisko?;słoneczne;półcieniste;cieniste"))
)
(defrule question_wilgotnosc
	(step "wilgotność")
=>
	(assert (question "Jakie jest planowane stanowisko?;suche;przeciętne;wilgotne"))
)
(defrule question_sikawki
	(step "sikawki")
=>
	(assert (question "Czy jest automatyczne podlewanie?;tak;nie"))
)
(defrule question_prochnica
	(step "próchnica")
=>
	(assert (question "Czy na stanowisku występuje próchnica?;tak;nie"))
)
(defrule question_osloniecie2
	(step "osłonięcie2")
=>
	(assert (question "Czy stanowisko jest osłonięte od wiatru?;tak;nie"))
)
(defrule question_kwiaty
	(step "kwiaty")
=>
	(assert (question "Czy roślina ma mieć kwiaty?;tak;nie"))
)
(defrule question_kolor
	(step "kolor")
=>
	(assert (question "Jakiego koloru mają być kwiaty?;białe;czerwone;fioletowe;malinowe;niebieskie;pomarańczowe;różowe;żółte;różnobarwne;dowolne"))
)
(defrule question_pochodzenie
	(step "pochodzenie")
=>
	(assert (question "Skąd ma pochodzić roślina?;...;dowolne"))
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
	(assert (step "nasłonecznienie"))
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
	(assert (step "kwiaty"))
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
	(assert (step "kwiaty"))
)
(defrule answer_osloniecie1_wsrod_drzew
	?i <- (step "osłonięcie1")
	?j <- (answer "wśrod drzew")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty"))
)
(defrule answer_osloniecie1_nieosloniete
	?i <- (step "osłonięcie1")
	?j <- (answer "nieosłonięte")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty"))
)
(defrule answer_osloniecie1_wsrod_budynkow
	?i <- (step "osłonięcie1")
	?j <- (answer "wśrod budynków")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty"))
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
(defrule answer_naslonecznienie_sloneczne
	?i <- (step "nasłonecznienie")
	?j <- (answer "słoneczne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "wilgotność"))
)
(defrule answer_naslonecznienie_polcieniste
	?i <- (step "nasłonecznienie")
	?j <- (answer "półcieniste")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "wilgotność"))
)
(defrule answer_naslonecznienie_cieniste
	?i <- (step "nasłonecznienie")
	?j <- (answer "cieniste")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "wilgotność"))
)
(defrule answer_wilgotnosc_suche
	?i <- (step "wilgotność")
	?j <- (answer "suche")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)
(defrule answer_wilgotnosc_przecietne
	?i <- (step "wilgotność")
	?j <- (answer "przeciętne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)
(defrule answer_wilgotnosc_wilgotne
	?i <- (step "wilgotność")
	?j <- (answer "wilgotne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "próchnica"))
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
(defrule answer_prochnica_tak
	?i <- (step "próchnica")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie2"))
)
(defrule answer_prochnica_nie
	?i <- (step "próchnica")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie2"))
)
(defrule answer_osloniecie2_tak
	?i <- (step "osłonięcie2")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty"))
)
(defrule answer_osloniecie2_nie
	?i <- (step "osłonięcie2")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty"))
)
(defrule answer_kwiaty_tak
	?i <- (step "kwiaty")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kolor"))
)
(defrule answer_kwiaty_nie
	?i <- (step "kwiaty")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_biale
	?i <- (step "kolor")
	?j <- (answer "białe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_czerwone
	?i <- (step "kolor")
	?j <- (answer "czerwone")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_fioletowe
	?i <- (step "kolor")
	?j <- (answer "fioletowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_malinowe
	?i <- (step "kolor")
	?j <- (answer "malinowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_niebieskie
	?i <- (step "kolor")
	?j <- (answer "niebieskie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_pomaranczowe
	?i <- (step "kolor")
	?j <- (answer "pomarańczowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_rozowe
	?i <- (step "kolor")
	?j <- (answer "różowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_zolte
	?i <- (step "kolor")
	?j <- (answer "żółte")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_roznobarwne
	?i <- (step "kolor")
	?j <- (answer "różnobarwne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)
(defrule answer_kolor_dowolne
	?i <- (step "kolor")
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
(defrule answer_start_solid
	?i <- (step "START")
	?j <- (answer "solid")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "lokalizacja1"))
)
