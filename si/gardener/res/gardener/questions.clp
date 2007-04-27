(defrule question_lokalizacja1
	(declare (salience -20))
	(step "lokalizacja1")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w domu;w ogrodzie;nie wiem"))
)

(defrule question_lokalizacja2
	(declare (salience -20))
	(step "lokalizacja2")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w pokoju;na balkonie;na parapecie;nie wiem"))
)

(defrule question_lokalizacja3
	(declare (salience -20))
	(step "lokalizacja3")
=>
	(assert (question "Gdzie zostanie posadzona roślina?;w pobliżu okna;zdala od okna;nie wiem"))
)

(defrule question_orientacja
	(declare (salience -20))
	(step "orientacja")
=>
	(assert (question "Jakie jest umiejscowienie stanowiska?;od południa;od północy;nie wiem"))
)

(defrule question_osloniecie1
	(declare (salience -20))
	(step "osłonięcie1")
=>
	(assert (question "Jakie jest umiejscowienie stanowiska?;wśrod budynków;wśrod drzew;nieosłonięte;nie wiem"))
)

(defrule question_osloniecie2
	(declare (salience -20))
	(step "osłonięcie2")
=>
	(assert (question "Czy stanowisko jest osłonięte od opadów?;nie;nie wiem;tak"))
)

(defrule question_opady
	(declare (salience -20))
	(step "opady")
=>
	(assert (question "Jakie jest występowanie opadów?;częste;rzadkie;przeciętne;nie wiem"))
)

(defrule question_sikawki
	(declare (salience -20))
	(step "sikawki")
=>
	(assert (question "Czy automatyczne podlewanie sięga stanowiska?;tak;nie;nie wiem"))
)

(defrule question_prochnica
	(declare (salience -20))
	(step "próchnica")
=>
	(assert (question "Czy na stanowisku występuje próchnica?;tak;nie;nie wiem"))
)

(defrule question_osloniecie3
	(declare (salience -20))
	(step "osłonięcie3")
=>
	(assert (question "Czy stanowisko jest osłonięte od wiatru?;tak;nie;nie wiem"))
)

(defrule question_kwiaty1
	(declare (salience -20))
	(step "kwiaty1")
=>
	(assert (question "Czy roślina ma mieć kwiaty?;tak;nie;obojętnie"))
)

(defrule question_kwiaty2
	(declare (salience -20))
	(step "kwiaty2")
=>
	(assert (question "Jakiego koloru mają być kwiaty?;białe;czerwone;fioletowe;niebieskie;pomarańczowe;purpurowe;różowe;żółte;różnobarwne;inne;dowolne"))
)

(defrule question_pochodzenie
	(declare (salience -20))
	(step "pochodzenie")
=>
	(assert (question "Skąd ma pochodzić roślina?;Polska;Europa;Afryka;Azja;Azja Mniejsza;Australia;Ameryka Północna;Ameryka Środkowa;Ameryka Południowa;obojętnie"))
)

(defrule question_pielegnacja
	(declare (salience -20))
	(step "pielęgnacja")
=>
	(assert (question "Czy masz czas pielęgnowac roślinę?;tak;nie;nie wiem"))
)

(defrule question_start
	(declare (salience -20))
	(step "START")
=>
	(assert (question "START;solid"))
)

(defrule question_stop
	(declare (salience -20))
	(step "STOP")
=>
	(assert (question "STOP"))
)

(defrule answer_lokalizacja1_w_domu
	(declare (salience -20))
	?i <- (step "lokalizacja1")
	?j <- (answer "w domu")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "lokalizacja2"))
)

(defrule answer_lokalizacja1_w_ogrodzie
	(declare (salience -20))
	?i <- (step "lokalizacja1")
	?j <- (answer "w ogrodzie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie2"))
)

(defrule answer_lokalizacja1_nie_wiem
	(declare (salience -20))
	?i <- (step "lokalizacja1")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_lokalizacja2_w_pokoju
	(declare (salience -20))
	?i <- (step "lokalizacja2")
	?j <- (answer "w pokoju")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "lokalizacja3"))
)

(defrule answer_lokalizacja2_na_balkonie
	(declare (salience -20))
	?i <- (step "lokalizacja2")
	?j <- (answer "na balkonie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)

(defrule answer_lokalizacja2_na_parapecie
	(declare (salience -20))
	?i <- (step "lokalizacja2")
	?j <- (answer "na parapecie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)

(defrule answer_lokalizacja2_nie_wiem
	(declare (salience -20))
	?i <- (step "lokalizacja2")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_lokalizacja3_w_poblizu_okna
	(declare (salience -20))
	?i <- (step "lokalizacja3")
	?j <- (answer "w pobliżu okna")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)

(defrule answer_lokalizacja3_zdala_od_okna
	(declare (salience -20))
	?i <- (step "lokalizacja3")
	?j <- (answer "zdala od okna")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_lokalizacja3_nie_wiem
	(declare (salience -20))
	?i <- (step "lokalizacja3")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_orientacja_od_poludnia
	(declare (salience -20))
	?i <- (step "orientacja")
	?j <- (answer "od południa")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie1"))
)

(defrule answer_orientacja_od_polnocy
	(declare (salience -20))
	?i <- (step "orientacja")
	?j <- (answer "od północy")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_orientacja_nie_wiem
	(declare (salience -20))
	?i <- (step "orientacja")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_osloniecie1_wsrod_budynkow
	(declare (salience -20))
	?i <- (step "osłonięcie1")
	?j <- (answer "wśrod budynków")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_osloniecie1_wsrod_drzew
	(declare (salience -20))
	?i <- (step "osłonięcie1")
	?j <- (answer "wśrod drzew")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_osloniecie1_nieosloniete
	(declare (salience -20))
	?i <- (step "osłonięcie1")
	?j <- (answer "nieosłonięte")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_osloniecie1_nie_wiem
	(declare (salience -20))
	?i <- (step "osłonięcie1")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty1"))
)

(defrule answer_osloniecie2_nie
	(declare (salience -20))
	?i <- (step "osłonięcie2")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "opady"))
)

(defrule answer_osloniecie2_nie_wiem
	(declare (salience -20))
	?i <- (step "osłonięcie2")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "opady"))
)

(defrule answer_osloniecie2_tak
	(declare (salience -20))
	?i <- (step "osłonięcie2")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)

(defrule answer_opady_czeste
	(declare (salience -20))
	?i <- (step "opady")
	?j <- (answer "częste")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)

(defrule answer_opady_rzadkie
	(declare (salience -20))
	?i <- (step "opady")
	?j <- (answer "rzadkie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)

(defrule answer_opady_przecietne
	(declare (salience -20))
	?i <- (step "opady")
	?j <- (answer "przeciętne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)

(defrule answer_opady_nie_wiem
	(declare (salience -20))
	?i <- (step "opady")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "sikawki"))
)

(defrule answer_sikawki_tak
	(declare (salience -20))
	?i <- (step "sikawki")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "próchnica"))
)

(defrule answer_sikawki_nie
	(declare (salience -20))
	?i <- (step "sikawki")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "próchnica"))
)

(defrule answer_sikawki_nie_wiem
	(declare (salience -20))
	?i <- (step "sikawki")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "próchnica"))
)

(defrule answer_prochnica_tak
	(declare (salience -20))
	?i <- (step "próchnica")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie3"))
)

(defrule answer_prochnica_nie
	(declare (salience -20))
	?i <- (step "próchnica")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie3"))
)

(defrule answer_prochnica_nie_wiem
	(declare (salience -20))
	?i <- (step "próchnica")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "osłonięcie3"))
)

(defrule answer_osloniecie3_tak
	(declare (salience -20))
	?i <- (step "osłonięcie3")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)

(defrule answer_osloniecie3_nie
	(declare (salience -20))
	?i <- (step "osłonięcie3")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)

(defrule answer_osloniecie3_nie_wiem
	(declare (salience -20))
	?i <- (step "osłonięcie3")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "orientacja"))
)

(defrule answer_kwiaty1_tak
	(declare (salience -20))
	?i <- (step "kwiaty1")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "kwiaty2"))
)

(defrule answer_kwiaty1_nie
	(declare (salience -20))
	?i <- (step "kwiaty1")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty1_obojetnie
	(declare (salience -20))
	?i <- (step "kwiaty1")
	?j <- (answer "obojętnie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_biale
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "białe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_czerwone
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "czerwone")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_fioletowe
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "fioletowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_niebieskie
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "niebieskie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_pomaranczowe
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "pomarańczowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_purpurowe
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "purpurowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_rozowe
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "różowe")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_zolte
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "żółte")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_roznobarwne
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "różnobarwne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_inne
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "inne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_kwiaty2_dowolne
	(declare (salience -20))
	?i <- (step "kwiaty2")
	?j <- (answer "dowolne")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pochodzenie"))
)

(defrule answer_pochodzenie_polska
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Polska")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_europa
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Europa")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_afryka
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Afryka")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_azja
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Azja")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_azja_mniejsza
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Azja Mniejsza")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_australia
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Australia")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_ameryka_polnocna
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Ameryka Północna")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_ameryka_srodkowa
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Ameryka Środkowa")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_ameryka_poludniowa
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "Ameryka Południowa")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pochodzenie_obojetnie
	(declare (salience -20))
	?i <- (step "pochodzenie")
	?j <- (answer "obojętnie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "pielęgnacja"))
)

(defrule answer_pielegnacja_tak
	(declare (salience -20))
	?i <- (step "pielęgnacja")
	?j <- (answer "tak")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "STOP"))
)

(defrule answer_pielegnacja_nie
	(declare (salience -20))
	?i <- (step "pielęgnacja")
	?j <- (answer "nie")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "STOP"))
)

(defrule answer_pielegnacja_nie_wiem
	(declare (salience -20))
	?i <- (step "pielęgnacja")
	?j <- (answer "nie wiem")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "STOP"))
)

(defrule answer_start_solid
	(declare (salience -20))
	?i <- (step "START")
	?j <- (answer "solid")
=>
	(retract ?i)
	(retract ?j)
	(assert (step "lokalizacja1"))
)

