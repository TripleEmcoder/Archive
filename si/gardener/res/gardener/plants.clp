(defrule plant_argyranthemum_frutescens
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"żółte")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Argyranthemum frutescens"))
)

(defrule plant_brassica_oleracea
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Brassica oleracea"))
)

(defrule plant_campanula
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"niebieskie")
	(refresh)
=>
	(assert (plant "Campanula"))
)

(defrule plant_centradenia
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różowe")
	(refresh)
=>
	(assert (plant "Centradenia"))
)

(defrule plant_fuksja_x_hybrida
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "kwiaty" "dowolne"|"czerwone")
	(refresh)
=>
	(assert (plant "Fuksja x hybrida"))
)

(defrule plant_helichrysum_bracteatum
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Helichrysum bracteatum"))
)

(defrule plant_impatiens
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Impatiens"))
)

(defrule plant_lobelia_pendula
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"niebieskie")
	(refresh)
=>
	(assert (plant "Lobelia pendula"))
)

(defrule plant_mentha_suaveolens
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Mentha suaveolens"))
)

(defrule plant_pelargonium_peltatum
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Pelargonium peltatum"))
)

(defrule plant_pelargonium_peltatum
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Pelargonium peltatum"))
)

(defrule plant_petunia_hybrida
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różnobarwne")
	(refresh)
=>
	(assert (plant "Petunia hybrida"))
)

(defrule plant_sanvitalia_procumbens
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "kwiaty" "dowolne"|"żółte")
	(refresh)
=>
	(assert (plant "Sanvitalia procumbens"))
)

(defrule plant_surfinia_blue_vein
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Surfinia 'Blue Vein'"))
)

(defrule plant_surfinia_hot_pink
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"czerwone")
	(refresh)
=>
	(assert (plant "Surfinia 'Hot Pink'"))
)

(defrule plant_surfinia_purple_vein
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"niebieskie")
	(refresh)
=>
	(assert (plant "Surfinia 'Purple Vein'"))
)

(defrule plant_surfinia_white
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Surfinia 'White'"))
)

(defrule plant_thunbergia_alata
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"pomarańczowe"|"żółte")
	(refresh)
=>
	(assert (plant "Thunbergia alata"))
)

(defrule plant_viola_wittrockiana
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "kwiaty" "dowolne"|"różnobarwne")
	(refresh)
=>
	(assert (plant "Viola wittrockiana"))
)

(defrule plant_werbena_tukana_denim_blue
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Północna mieszaniec")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"niebieskie")
	(refresh)
=>
	(assert (plant "Werbena Tukana 'Denim Blue'"))
)

(defrule plant_werbena_tukana_scarlet
	(declare (salience -10))
	(property "grupa" "dowolne"|"balkonowe")
	(property "pochodzenie" "dowolne"|"Ameryka Północna mieszaniec")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"czerwone")
	(refresh)
=>
	(assert (plant "Werbena Tukana 'Scarlet'"))
)

(defrule plant_achillea_millefolium
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja"|"Australia")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Achillea millefolium"))
)

(defrule plant_alyssum_saxatile
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"sloneczne")
	(property "kwiaty" "dowolne"|"żółte")
	(refresh)
=>
	(assert (plant "Alyssum saxatile"))
)

(defrule plant_anemone_x_hybrida
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"półcieniste")
	(property "kwiaty" "dowolne"|"białe"|"czerwone")
	(refresh)
=>
	(assert (plant "Anemone x hybrida"))
)

(defrule plant_armeria_maritima
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Armeria maritima"))
)

(defrule plant_aster_amellus
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Polska")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"czerwone"|"fioletowe")
	(refresh)
=>
	(assert (plant "Aster amellus"))
)

(defrule plant_aubrieta_cultorum
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"fioletowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Aubrieta cultorum"))
)

(defrule plant_bellis_perennis
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"różowe")
	(refresh)
=>
	(assert (plant "Bellis perennis"))
)

(defrule plant_campanula_carpatica
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Campanula carpatica"))
)

(defrule plant_campanula_persicifolia
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Azja"|"Europa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"niebieskie")
	(refresh)
=>
	(assert (plant "Campanula persicifolia"))
)

(defrule plant_cerastium_biebersteinii
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"rzadkie"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Cerastium biebersteinii"))
)

(defrule plant_cobaea
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "dowolne"|"białe"|"różowe")
	(refresh)
=>
	(assert (plant "Cobaea"))
)

(defrule plant_crocus
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różnobarwne")
	(refresh)
=>
	(assert (plant "Crocus"))
)

(defrule plant_dianthus_gratianopolitanus
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Dianthus gratianopolitanus"))
)

(defrule plant_dianthus_plumarius_ine
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Dianthus plumarius 'Ine'"))
)

(defrule plant_dicentra_spectabilis
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"cieniste"|"półcieniste")
	(property "kwiaty" "dowolne"|"białe"|"różowe")
	(refresh)
=>
	(assert (plant "Dicentra spectabilis"))
)

(defrule plant_echinacea_purpurea
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Ameryka Północna")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"purpurowe")
	(refresh)
=>
	(assert (plant "Echinacea purpurea"))
)

(defrule plant_geranium_dalmaticum
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różowe")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Geranium dalmaticum"))
)

(defrule plant_helleborus_niger
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Helleborus niger"))
)

(defrule plant_hemerocallis_fulva
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane"|"rzadkie")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "kwiaty" "dowolne"|"czerwone"|"pomarańczowe")
	(refresh)
=>
	(assert (plant "Hemerocallis fulva"))
)

(defrule plant_heuchera
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Polska")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "kwiaty" "dowolne"|"białe"|"różowe")
	(refresh)
=>
	(assert (plant "Heuchera"))
)

(defrule plant_hosta_sieboldiana
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"fioletowe")
	(refresh)
=>
	(assert (plant "Hosta sieboldiana"))
)

(defrule plant_houstonia
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Ameryka Północna")
	(property "stanowisko" "dowolne"|"półcieniste")
	(property "kwiaty" "dowolne"|"niebieskie"|"żółte")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Houstonia"))
)

(defrule plant_houttuynia_cordata_kameleon
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe"|"żółte")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Houttuynia cordata 'Kameleon'"))
)

(defrule plant_iris_barbata_syn._iris_germanica
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różnobarwne")
	(refresh)
=>
	(assert (plant "Iris Barbata syn. Iris Germanica"))
)

(defrule plant_leontopodium_alpinum
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Leontopodium alpinum"))
)

(defrule plant_leucanthemum_vulgare
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Polska")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"żółte")
	(refresh)
=>
	(assert (plant "Leucanthemum vulgare"))
)

(defrule plant_lilium_martagon
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"nieokreślone")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Lilium martagon"))
)

(defrule plant_lysimachia_nummularia
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"widne"|"cieniste")
	(property "kwiaty" "dowolne"|"żółte")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Lysimachia nummularia"))
)

(defrule plant_muscari_armeniacum
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"niebieskie")
	(refresh)
=>
	(assert (plant "Muscari armeniacum"))
)

(defrule plant_narcissus
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Azja"|"Europa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Narcissus"))
)

(defrule plant_nepeta_x_faassenii
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Afryka"|"Azja Mniejsza")
	(property "podlewanie" "dowolne"|"rzadkie"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"fioletowe")
	(refresh)
=>
	(assert (plant "Nepeta x faassenii"))
)

(defrule plant_oenothera_missouriensis
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Ameryka Północna")
	(property "podlewanie" "dowolne"|"rzadkie"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"żółte")
	(refresh)
=>
	(assert (plant "Oenothera missouriensis"))
)

(defrule plant_origanum_kent_beauty
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Origanum 'Kent Beauty'"))
)

(defrule plant_papaver_orientale
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Azja Mniejsza")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"czerwone")
	(refresh)
=>
	(assert (plant "Papaver orientale"))
)

(defrule plant_phlox_douglasii
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Phlox douglasii"))
)

(defrule plant_phlox_subulata
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"fioletowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Phlox subulata"))
)

(defrule plant_phlox_subulata
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"fioletowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Phlox subulata"))
)

(defrule plant_pulsatilla_vulgaris
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"fioletowe"|"purpurowe"|"żółte")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Pulsatilla vulgaris"))
)

(defrule plant_salvia_officinalis
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Azja Mniejsza"|"Europa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"fioletowe")
	(refresh)
=>
	(assert (plant "Salvia officinalis"))
)

(defrule plant_saxifraga_arendsii
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "kwiaty" "dowolne"|"inne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Saxifraga arendsii"))
)

(defrule plant_sedum_album_coral_carpet
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Sedum album 'Coral Carpet'"))
)

(defrule plant_sempervivum
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Sempervivum"))
)

(defrule plant_thymus_serpyllum
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Thymus serpyllum"))
)

(defrule plant_tradescantia_virginica
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"fioletowe"|"niebieskie")
	(refresh)
=>
	(assert (plant "Tradescantia virginica"))
)

(defrule plant_trollius_cultorum
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Europa"|"Azja")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "kwiaty" "dowolne"|"pomarańczowe")
	(refresh)
=>
	(assert (plant "Trollius cultorum"))
)

(defrule plant_veronica_incana
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Azja"|"Polska")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"niebieskie")
	(refresh)
=>
	(assert (plant "Veronica incana"))
)

(defrule plant_viola_odorata
	(declare (salience -10))
	(property "grupa" "dowolne"|"byliny")
	(property "pochodzenie" "dowolne"|"Polska")
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "dowolne"|"białe"|"fioletowe"|"pomarańczowe")
	(refresh)
=>
	(assert (plant "Viola odorata"))
)

(defrule plant_abutilon_megapotamicum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "kwiaty" "dowolne"|"czerwone"|"żółte")
	(refresh)
=>
	(assert (plant "Abutilon megapotamicum"))
)

(defrule plant_acalypha_hispida
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"różowe")
	(refresh)
=>
	(assert (plant "Acalypha hispida"))
)

(defrule plant_adenium_obessum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"czerwone"|"żółte")
	(refresh)
=>
	(assert (plant "Adenium obessum"))
)

(defrule plant_aechmea_fasciata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"różowe")
	(refresh)
=>
	(assert (plant "Aechmea fasciata"))
)

(defrule plant_agava_americana_marginata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Agava americana 'Marginata'"))
)

(defrule plant_aglonema_commutatum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"półcieniste"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Aglonema commutatum"))
)

(defrule plant_alocasia_lowii
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Alocasia lowii"))
)

(defrule plant_ananas_comosus
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"półcieniste"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Ananas comosus"))
)

(defrule plant_anigozanthos
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Australia")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe"|"czerwone"|"różowe"|"żółte")
	(refresh)
=>
	(assert (plant "Anigozanthos"))
)

(defrule plant_anthurium_scherzerianum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"półcieniste"|"widne")
	(property "kwiaty" "dowolne"|"czerwone"|"różowe")
	(refresh)
=>
	(assert (plant "Anthurium scherzerianum"))
)

(defrule plant_aphelandra_squarrosa
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"żółte")
	(refresh)
=>
	(assert (plant "Aphelandra squarrosa"))
)

(defrule plant_areca_catechu
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "kwiaty" "dowolne"|"żółte")
	(refresh)
=>
	(assert (plant "Areca catechu"))
)

(defrule plant_asparagus_plumosus
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Asparagus plumosus"))
)

(defrule plant_asplenium_nidus
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne ale nie słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Asplenium nidus"))
)

(defrule plant_aucuba_japonica
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"purpurowe")
	(refresh)
=>
	(assert (plant "Aucuba japonica"))
)

(defrule plant_beaucarnea_recurvata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Beaucarnea recurvata"))
)

(defrule plant_begonia_boweri_tiger
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Begonia boweri 'Tiger'"))
)

(defrule plant_begonia_rex
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Begonia rex"))
)

(defrule plant_beloperone_gutta
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"czerwone"|"żółte")
	(refresh)
=>
	(assert (plant "Beloperone gutta"))
)

(defrule plant_bougainvillea_glabra
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Bougainvillea glabra"))
)

(defrule plant_caffea_arabica
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Caffea Arabica"))
)

(defrule plant_calathea_makoyana
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Calathea makoyana"))
)

(defrule plant_callisia_repens
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Callisia repens"))
)

(defrule plant_capiscum_annuum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Capiscum annuum"))
)

(defrule plant_chameadora_elegans
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Chameadora elegans"))
)

(defrule plant_cissus_antarctica
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Australia")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Cissus antarctica"))
)

(defrule plant_citrofortunella_mitis
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Citrofortunella mitis"))
)

(defrule plant_clivia_minata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Clivia minata"))
)

(defrule plant_coffea_arabica
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Coffea arabica"))
)

(defrule plant_cordyline_fruticosa
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Cordyline fruticosa"))
)

(defrule plant_crassula
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Crassula"))
)

(defrule plant_cthenanthe_oppenheimiana
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Cthenanthe oppenheimiana"))
)

(defrule plant_cupressus_macrocarpa
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Północna")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Cupressus macrocarpa"))
)

(defrule plant_cycas_revoluta
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Cycas revoluta"))
)

(defrule plant_cyperus_papyrus
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka"|"Azja"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Cyperus papyrus"))
)

(defrule plant_davallia_bullata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Davallia bullata"))
)

(defrule plant_dionaea_muscipula
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Północna")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Dionaea muscipula"))
)

(defrule plant_dracaena_deremensis_lemon
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Dracaena deremensis 'Lemon'"))
)

(defrule plant_dracena_india
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Dracena india"))
)

(defrule plant_dracena_sanderiana
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"widne ale nie słoneczne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Dracena sanderiana"))
)

(defrule plant_echinocactus_grusonii
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"żółte")
	(refresh)
=>
	(assert (plant "Echinocactus grusonii"))
)

(defrule plant_euphorbia_caput-medusae
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"żółte")
	(refresh)
=>
	(assert (plant "Euphorbia caput-medusae"))
)

(defrule plant_euphorbia_milii
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"czerwone"|"różowe")
	(refresh)
=>
	(assert (plant "Euphorbia milii"))
)

(defrule plant_euphorbia_trigona
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Euphorbia trigona"))
)

(defrule plant_ficus_benjamina
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Ficus benjamina"))
)

(defrule plant_ficus_lyrata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Ficus lyrata"))
)

(defrule plant_fittonia_verschaffeltii
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Fittonia verschaffeltii"))
)

(defrule plant_guzmania_dissitiflora
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"czerwone"|"pomarańczowe")
	(refresh)
=>
	(assert (plant "Guzmania dissitiflora"))
)

(defrule plant_gynura_scandens
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"pomarańczowe")
	(refresh)
=>
	(assert (plant "Gynura scandens"))
)

(defrule plant_hebe_bukszpanowate
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Australia")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"różowe")
	(refresh)
=>
	(assert (plant "Hebe bukszpanowate"))
)

(defrule plant_hedera_helix_helvig
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Hedera helix 'Helvig'"))
)

(defrule plant_hedera_helix_mini_heron
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Hedera helix 'Mini Heron'"))
)

(defrule plant_hedera_helix_variegata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Hedera helix 'Variegata'"))
)

(defrule plant_hedera_helix_ssp._canariensis_svendborg
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Hedera helix ssp. canariensis 'Svendborg'"))
)

(defrule plant_hypoestes_sanguinoleta_hypoestes_phyllostachya
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"fioletowe")
	(refresh)
=>
	(assert (plant "Hypoestes sanguinoleta Hypoestes phyllostachya"))
)

(defrule plant_kalanchoe_blossfeldiana
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Kalanchoe blossfeldiana"))
)

(defrule plant_kalanchoe_manginii
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"pomarańczowe")
	(refresh)
=>
	(assert (plant "Kalanchoe manginii"))
)

(defrule plant_laurus_nobilis
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Europa"|"Afryka"|"Azja Mniejsza")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Laurus nobilis"))
)

(defrule plant_lithops
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"żółte")
	(refresh)
=>
	(assert (plant "Lithops"))
)

(defrule plant_maranta_leuconeura
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Maranta leuconeura"))
)

(defrule plant_mulenbekia
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Australia")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Mulenbekia"))
)

(defrule plant_musa_cavendishii
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Musa cavendishii"))
)

(defrule plant_nephrolepis_exaltata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka"|"Azja"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Nephrolepis exaltata"))
)

(defrule plant_nertera_granadensis
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne ale nie słoneczne")
	(property "kwiaty" "dowolne"|"białe"|"czerwone"|"żółte")
	(refresh)
=>
	(assert (plant "Nertera granadensis"))
)

(defrule plant_pachypodium_lamerei
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Pachypodium lamerei"))
)

(defrule plant_passiflora_caerulea
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"niebieskie")
	(refresh)
=>
	(assert (plant "Passiflora caerulea"))
)

(defrule plant_peperomia
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa"|"Łacińska")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Peperomia"))
)

(defrule plant_phalaenopsis
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja"|"Australia"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe"|"różowe"|"żółte")
	(refresh)
=>
	(assert (plant "Phalaenopsis"))
)

(defrule plant_philodendron_erubescens_new_red
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"cieniste"|"półcieniste")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Philodendron erubescens 'New Red'"))
)

(defrule plant_pilea_cadierei
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Pilea cadierei"))
)

(defrule plant_pinguicula_moranensis
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"różowe")
	(refresh)
=>
	(assert (plant "Pinguicula moranensis"))
)

(defrule plant_platycerium_bifurcatum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Australia"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Platycerium bifurcatum"))
)

(defrule plant_plumbago_auriculata
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"niebieskie")
	(refresh)
=>
	(assert (plant "Plumbago auriculata"))
)

(defrule plant_polyscias_balfouriana_fabian
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Polyscias balfouriana 'Fabian'"))
)

(defrule plant_primula_vulgaris
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Primula vulgaris"))
)

(defrule plant_punica_granatum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"czerwone")
	(refresh)
=>
	(assert (plant "Punica granatum"))
)

(defrule plant_rheo_spathacea
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe"|"żółte")
	(refresh)
=>
	(assert (plant "Rheo spathacea"))
)

(defrule plant_rosa
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Rosa"))
)

(defrule plant_saintpaulia_ionantha
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Saintpaulia ionantha"))
)

(defrule plant_sarracenia_purpurea
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Północna")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Sarracenia purpurea"))
)

(defrule plant_saxifraga_stolonifera_tricolor
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Saxifraga stolonifera 'Tricolor'"))
)

(defrule plant_scindapsus_aureus
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Australia")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Scindapsus aureus"))
)

(defrule plant_scirpus_cernuus_isolepis_gracilis
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Scirpus cernuus Isolepis gracilis"))
)

(defrule plant_sedum_rubrotinctum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Sedum rubrotinctum"))
)

(defrule plant_senecio_macroglossus_variegatus
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"żółte")
	(refresh)
=>
	(assert (plant "Senecio macroglossus 'Variegatus'"))
)

(defrule plant_solanum_pseudocapiscum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Solanum pseudocapiscum"))
)

(defrule plant_spathiphyllum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Spathiphyllum"))
)

(defrule plant_stereospermum_sinicum
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Stereospermum sinicum"))
)

(defrule plant_synningia_speciosa_hybrid
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Południowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne ale nie słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Synningia speciosa hybrid"))
)

(defrule plant_tolmia_menziesii
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Północna")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Tolmia menziesii"))
)

(defrule plant_vriesea
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"czerwone"|"pomarańczowe")
	(refresh)
=>
	(assert (plant "Vriesea"))
)

(defrule plant_yucca_elephantipes
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Ameryka Środkowa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Yucca elephantipes"))
)

(defrule plant_zantedeschia_aethiopca
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Afryka")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Zantedeschia aethiopca"))
)

(defrule plant_zingiber_officinale
	(declare (salience -10))
	(property "grupa" "dowolne"|"domowe")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"fioletowe"|"żółte")
	(refresh)
=>
	(assert (plant "Zingiber officinale"))
)

(defrule plant_chamaecyparis_nootkanesis_tatra
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Chamaecyparis nootkanesis 'Tatra'"))
)

(defrule plant_chamaecyparis_pisifera_curly_tops
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Chamaecyparis pisifera 'Curly Tops'"))
)

(defrule plant_chamaecyparis_pisifera_plumosa
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Chamaecyparis pisifera 'Plumosa'"))
)

(defrule plant_ginkgo_biloba
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"cieniste")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Ginkgo biloba"))
)

(defrule plant_juniperus_chinensis_blue_alps
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Juniperus chinensis 'Blue Alps'"))
)

(defrule plant_juniperus_communis_green_carpet
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Juniperus communis 'Green Carpet'"))
)

(defrule plant_juniperus_horizontalis_andorra_compact
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Juniperus horizontalis 'Andorra Compact'"))
)

(defrule plant_juniperus_horizontalis_wiltonii
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Juniperus horizontalis 'Wiltonii'"))
)

(defrule plant_juniperus_media_pfitzeriana_aurea
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Juniperus media 'Pfitzeriana Aurea'"))
)

(defrule plant_juniperus_pingii_loderi
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Juniperus pingii 'Loderi'"))
)

(defrule plant_juniperus_squamata_blue_carpet
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne"|"półcieniste")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Juniperus squamata 'Blue Carpet'"))
)

(defrule plant_juniperus_virginiana_skyrocket
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Juniperus virginiana 'Skyrocket'"))
)

(defrule plant_thuja_occidentalis_abel_twa
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Thuja occidentalis 'Abel Twa'"))
)

(defrule plant_thuja_occidentalis_filiformis
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Thuja occidentalis 'Filiformis'"))
)

(defrule plant_thuja_occidentalis_little_dorrit
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Thuja occidentalis 'Little Dorrit'"))
)

(defrule plant_thuja_occidentalis_smaragd
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Thuja occidentalis 'Smaragd'"))
)

(defrule plant_thuja_occidentalis_teddy
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "kwiaty" "brak")
	(refresh)
=>
	(assert (plant "Thuja occidentalis 'Teddy'"))
)

(defrule plant_thuja_plicata_kornik_iii
	(declare (salience -10))
	(property "grupa" "dowolne"|"iglaste")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Thuja plicata 'Kórnik III'"))
)

(defrule plant_budldleja_davidii
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Budldleja davidii"))
)

(defrule plant_cornus_alba
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Cornus alba"))
)

(defrule plant_cotinus_coggygria
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różowe")
	(refresh)
=>
	(assert (plant "Cotinus coggygria"))
)

(defrule plant_cytisus
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Europa"|"Afryka")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"żółte")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Cytisus"))
)

(defrule plant_forsythia
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
	(property "kwiaty" "dowolne"|"żółte")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Forsythia"))
)

(defrule plant_hydrangea_macrophylla
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Hydrangea macrophylla"))
)

(defrule plant_ilex_aquifolium
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Europa"|"Afryka"|"Azja Mniejsza")
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Ilex aquifolium"))
)

(defrule plant_lonicera_japonica_aureoreticulata
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Lonicera japonica 'Aureoreticulata'"))
)

(defrule plant_magnolia_liliflora
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"purpurowe")
	(refresh)
=>
	(assert (plant "Magnolia liliflora"))
)

(defrule plant_potentilla_fruticosa
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"żółte")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Potentilla fruticosa"))
)

(defrule plant_pyracantha_coccinea
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"umiarkowane"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"białe")
	(refresh)
=>
	(assert (plant "Pyracantha coccinea"))
)

(defrule plant_rosa_barkarole
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Azja"|"Europa"|"Ameryka Północna")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"czerwone")
	(refresh)
=>
	(assert (plant "Rosa 'Barkarole'"))
)

(defrule plant_spirea_kaponica_goldflame
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"różowe")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Spirea kaponica 'Goldflame'"))
)

(defrule plant_weigela
	(declare (salience -10))
	(property "grupa" "dowolne"|"krzewy")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne lub widne")
	(property "kwiaty" "dowolne"|"białe"|"czerwone")
	(refresh)
=>
	(assert (plant "Weigela"))
)

(defrule plant_arrhenaterum_bulbosum_variegatum
	(declare (salience -10))
	(property "grupa" "dowolne"|"trawy")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Arrhenaterum bulbosum 'Variegatum'"))
)

(defrule plant_elymus_arenarius
	(declare (salience -10))
	(property "grupa" "dowolne"|"trawy")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Elymus arenarius"))
)

(defrule plant_festuca_gautieri
	(declare (salience -10))
	(property "grupa" "dowolne"|"trawy")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "brak")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Festuca gautieri"))
)

(defrule plant_festuca_scoparia
	(declare (salience -10))
	(property "grupa" "dowolne"|"trawy")
	(property "pochodzenie" "dowolne"|"Europa")
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Festuca scoparia"))
)

(defrule plant_juncus_ensifolius
	(declare (salience -10))
	(property "grupa" "dowolne"|"trawy")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Juncus ensifolius"))
)

(defrule plant_miskant_chinski
	(declare (salience -10))
	(property "grupa" "dowolne"|"trawy")
	(property "pochodzenie" "dowolne"|"Azja")
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(refresh)
=>
	(assert (plant "Miskant chiński"))
)

(defrule plant_spartina_pectinata_aureomarginata
	(declare (salience -10))
	(property "grupa" "dowolne"|"trawy")
	(property "stanowisko" "dowolne"|"słoneczne")
	(property "kwiaty" "dowolne"|"inne")
	(property "pochodzenie" "dowolne"|"nieokreślone")
	(property "podlewanie" "dowolne"|"nieokreślone")
	(property "nawożenie" "dowolne"|"nieokreślone")
	(refresh)
=>
	(assert (plant "Spartina pectinata 'Aureomarginata'"))
)

