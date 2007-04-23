(defrule plant_argyranthemum_frutescens
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Argyranthemum frutescens"))
)
(defrule plant_brassica_oleracea
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Brassica oleracea"))
)
(defrule plant_campanula
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Campanula"))
)
(defrule plant_centradenia
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Centradenia"))
)
(defrule plant_fuksja_x_hybrida
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Fuksja x hybrida"))
)
(defrule plant_helichrysum_bracteatum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Helichrysum bracteatum"))
)
(defrule plant_impatiens
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Impatiens"))
)
(defrule plant_lobelia_pendula
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Lobelia pendula"))
)
(defrule plant_mentha_suaveolens
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Mentha suaveolens"))
)
(defrule plant_pelargonium_peltatum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Pelargonium peltatum"))
)
(defrule plant_pelargonium_peltatum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Pelargonium peltatum"))
)
(defrule plant_petunia_hybrida
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Petunia hybrida"))
)
(defrule plant_sanvitalia_procumbens
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Sanvitalia procumbens"))
)
(defrule plant_surfinia_blue_vein
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Surfinia 'Blue Vein'"))
)
(defrule plant_surfinia_hot_pink
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Surfinia 'Hot Pink'"))
)
(defrule plant_surfinia_purple_vein
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Surfinia 'Purple Vein'"))
)
(defrule plant_surfinia_white
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Surfinia 'White'"))
)
(defrule plant_thunbergia_alata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Thunbergia alata"))
)
(defrule plant_viola_wittrockiana
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne-widne")
=>
	(assert (answer "Viola wittrockiana"))
)
(defrule plant_werbena_tukana_denim_blue
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Werbena Tukana 'Denim Blue'"))
)
(defrule plant_werbena_tukana_scarlet
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Werbena Tukana 'Scarlet'"))
)
(defrule plant_achillea_millefolium
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Achillea millefolium"))
)
(defrule plant_alyssum_saxatile
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"sloneczne")
=>
	(assert (answer "Alyssum saxatile"))
)
(defrule plant_anemone_x_hybrida
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"wilgotne")
=>
	(assert (answer "Anemone x hybrida"))
)
(defrule plant_armeria_maritima
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Armeria maritima"))
)
(defrule plant_aster_amellus
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Aster amellus"))
)
(defrule plant_aubrieta_cultorum
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Aubrieta cultorum"))
)
(defrule plant_bellis_perennis
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Bellis perennis"))
)
(defrule plant_campanula_carpatica
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Campanula carpatica"))
)
(defrule plant_campanula_persicifolia
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Campanula persicifolia"))
)
(defrule plant_cerastium_biebersteinii
	(property "podlewanie" "dowolne"|"żadkie"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Cerastium biebersteinii"))
)
(defrule plant_cobaea
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Cobaea"))
)
(defrule plant_crocus
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Crocus"))
)
(defrule plant_dianthus_gratianopolitanus
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Dianthus gratianopolitanus"))
)
(defrule plant_dianthus_plumarius_ine
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Dianthus plumarius 'Ine'"))
)
(defrule plant_dicentra_spectabilis
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"cieniste"|"półcieniste")
=>
	(assert (answer "Dicentra spectabilis"))
)
(defrule plant_echinacea_purpurea
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Echinacea purpurea"))
)
(defrule plant_geranium_dalmaticum
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Geranium dalmaticum"))
)
(defrule plant_helleborus_niger
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Helleborus niger"))
)
(defrule plant_hemerocallis fulva
	(property "podlewanie" "dowolne"|"umiarkowane"|"rzadkie")
	(property "nawożenie" "dowolne"|"gleba żyzna")
	(property "stanowisko" "dowolne"|"miejsca wilgotne i słoneczne"|"częściowo zacienione")
=>
	(assert (answer "Hemerocallis fulva"))
)
(defrule plant_heuchera
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcieniste")
=>
	(assert (answer "Heuchera"))
)
(defrule plant_hosta_sieboldiana
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Hosta sieboldiana"))
)
(defrule plant_houstonia
	(property "stanowisko" "dowolne"|"półcieniste")
=>
	(assert (answer "Houstonia"))
)
(defrule plant_houttuynia_cordata_kameleon
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Houttuynia cordata 'Kameleon'"))
)
(defrule plant_iris_barbata_syn._iris_germanica
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Iris Barbata syn. Iris Germanica"))
)
(defrule plant_leontopodium_alpinum
	(property "stanowisko" "dowolne"|"nasłonecznione")
=>
	(assert (answer "Leontopodium alpinum"))
)
(defrule plant_leucanthemum_vulgare
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Leucanthemum vulgare"))
)
(defrule plant_lilium_martagon
	(property "podlewanie" "dowolne"|"-")
	(property "nawożenie" "dowolne"|"-")
	(property "stanowisko" "dowolne"|"-")
=>
	(assert (answer "Lilium martagon"))
)
(defrule plant_lysimachia_nummularia
	(property "stanowisko" "dowolne"|"widne"|"cieniste")
=>
	(assert (answer "Lysimachia nummularia"))
)
(defrule plant_muscari_armeniacum
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Muscari armeniacum"))
)
(defrule plant_narcissus
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Narcissus"))
)
(defrule plant_nepeta_x_faassenii
	(property "podlewanie" "dowolne"|"rzadkie"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne i suche")
=>
	(assert (answer "Nepeta x faassenii"))
)
(defrule plant_oenothera_missouriensis
	(property "podlewanie" "dowolne"|"rzadkie"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne i ciepłe")
=>
	(assert (answer "Oenothera missouriensis"))
)
(defrule plant_origanum_kent_beauty
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Origanum 'Kent Beauty'"))
)
(defrule plant_papaver_orientale
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Papaver orientale"))
)
(defrule plant_phlox_douglasii
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Phlox douglasii"))
)
(defrule plant_phlox_subulata
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Phlox subulata"))
)
(defrule plant_phlox_subulata
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Phlox subulata"))
)
(defrule plant_pulsatilla_vulgaris
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Pulsatilla vulgaris"))
)
(defrule plant_salvia_officinalis
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"zaciszne")
=>
	(assert (answer "Salvia officinalis"))
)
(defrule plant_saxifraga_arendsii
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Saxifraga arendsii"))
)
(defrule plant_sedum_album_coral_carpet
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Sedum album 'Coral Carpet'"))
)
(defrule plant_sempervivum
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Sempervivum"))
)
(defrule plant_thymus_serpyllum
	(property "stanowisko" "dowolne"|"nasłonecznione")
=>
	(assert (answer "Thymus serpyllum"))
)
(defrule plant_tradescantia_virginica
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Tradescantia virginica"))
)
(defrule plant_trollius_cultorum
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"średnie")
	(property "stanowisko" "dowolne"|"wilgotne i słoneczne")
=>
	(assert (answer "Trollius cultorum"))
)
(defrule plant_veronica_incana
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne i ciepłe")
=>
	(assert (answer "Veronica incana"))
)
(defrule plant_viola_odorata
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste i wilgotne")
=>
	(assert (answer "Viola odorata"))
)
(defrule plant_abutilon_megapotamicum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Abutilon megapotamicum"))
)
(defrule plant_acalypha_hispida
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Acalypha hispida"))
)
(defrule plant_adenium_obessum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Adenium obessum"))
)
(defrule plant_aechmea_fasciata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Aechmea fasciata"))
)
(defrule plant_agava_americana_marginata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Agava americana 'Marginata'"))
)
(defrule plant_aglonema_commutatum
	(property "podlewanie" "dowolne"|"umiarkowanie")
	(property "nawożenie" "dowolne"|"umiarkowanie")
	(property "stanowisko" "dowolne"|"półcień")
=>
	(assert (answer "Aglonema commutatum"))
)
(defrule plant_alocasia_lowii
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Alocasia lowii"))
)
(defrule plant_ananas_comosus
	(property "podlewanie" "dowolne"|"umiarkowanie do podstawka")
	(property "nawożenie" "dowolne"|"umiarkowanie")
	(property "stanowisko" "dowolne"|"półcień")
=>
	(assert (answer "Ananas comosus"))
)
(defrule plant_anigozanthos
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Anigozanthos"))
)
(defrule plant_anthurium_scherzerianum
	(property "podlewanie" "dowolne"|"umiarkowanie")
	(property "nawożenie" "dowolne"|"umiarkowanie")
	(property "stanowisko" "dowolne"|"półcień")
=>
	(assert (answer "Anthurium scherzerianum"))
)
(defrule plant_aphelandra_squarrosa
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Aphelandra squarrosa"))
)
(defrule plant_areca_catechu
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Areca catechu"))
)
(defrule plant_asparagus_plumosus
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Asparagus plumosus"))
)
(defrule plant_asplenium_nidus
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne lecz nie słoneczne")
=>
	(assert (answer "Asplenium nidus"))
)
(defrule plant_aucuba_japonica
	(property "podlewanie" "dowolne"|"umiarkowene")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Aucuba japonica"))
)
(defrule plant_beaucarnea_recurvata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Beaucarnea recurvata"))
)
(defrule plant_begonia_boweri_tiger
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Begonia boweri 'Tiger'"))
)
(defrule plant_begonia_rex
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Begonia rex"))
)
(defrule plant_beloperone_gutta
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Beloperone gutta"))
)
(defrule plant_bougainvillea_glabra
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Bougainvillea glabra"))
)
(defrule plant_caffea_arabica
	(property "podlewanie" "dowolne"|"Umiarkowanie")
	(property "nawożenie" "dowolne"|"częste")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Caffea Arabica"))
)
(defrule plant_calathea_makoyana
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Calathea makoyana"))
)
(defrule plant_callisia_repens
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Callisia repens"))
)
(defrule plant_capiscum_annuum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Capiscum annuum"))
)
(defrule plant_chameadora_elegans
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"cieniste")
=>
	(assert (answer "Chameadora elegans"))
)
(defrule plant_cissus_antarctica
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Cissus antarctica"))
)
(defrule plant_citrofortunella_mitis
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Citrofortunella mitis"))
)
(defrule plant_clivia_minata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Clivia minata"))
)
(defrule plant_coffea_arabica
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Coffea arabica"))
)
(defrule plant_cordyline_fruticosa
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Cordyline fruticosa"))
)
(defrule plant_crassula
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Crassula"))
)
(defrule plant_cthenanthe_oppenheimiana
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Cthenanthe oppenheimiana"))
)
(defrule plant_cupressus_macrocarpa
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Cupressus macrocarpa"))
)
(defrule plant_cycas_revoluta
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Cycas revoluta"))
)
(defrule plant_cyperus_papyrus
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Cyperus papyrus"))
)
(defrule plant_davallia_bullata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Davallia bullata"))
)
(defrule plant_dionaea_muscipula
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Dionaea muscipula"))
)
(defrule plant_dracaena_deremensis_lemon
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Dracaena deremensis 'Lemon'"))
)
(defrule plant_dracena_india
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Dracena india"))
)
(defrule plant_dracena_sanderiana
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"nie jest konieczne")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Dracena sanderiana"))
)
(defrule plant_echinocactus_grusonii
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Echinocactus grusonii"))
)
(defrule plant_euphorbia_caput-medusae
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Euphorbia caput-medusae"))
)
(defrule plant_euphorbia_milii
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Euphorbia milii"))
)
(defrule plant_euphorbia_trigona
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Euphorbia trigona"))
)
(defrule plant_ficus_benjamina
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Ficus benjamina"))
)
(defrule plant_ficus_lyrata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Ficus lyrata"))
)
(defrule plant_fittonia_verschaffeltii
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Fittonia verschaffeltii"))
)
(defrule plant_guzmania_dissitiflora
	(property "podlewanie" "dowolne"|"częste do doniczki")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Guzmania dissitiflora"))
)
(defrule plant_gynura_scandens
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Gynura scandens"))
)
(defrule plant_hebe_bukszpanowate
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Hebe bukszpanowate"))
)
(defrule plant_hedera_helix_helvig
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Hedera helix 'Helvig'"))
)
(defrule plant_hedera_helix_mini_heron
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Hedera helix 'Mini Heron'"))
)
(defrule plant_hedera_helix_variegata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Hedera helix 'Variegata'"))
)
(defrule plant_hedera_helix_ssp._canariensis_svendborg
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Hedera helix ssp. canariensis 'Svendborg'"))
)
(defrule plant_hypoestes_sanguinoleta_hypoestes_phyllostachya
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Hypoestes sanguinoleta Hypoestes phyllostachya"))
)
(defrule plant_kalanchoe_blossfeldiana
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Kalanchoe blossfeldiana"))
)
(defrule plant_kalanchoe_manginii
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Kalanchoe manginii"))
)
(defrule plant_laurus_nobilis
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Laurus nobilis"))
)
(defrule plant_lithops
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Lithops"))
)
(defrule plant_maranta_leuconeura
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Maranta leuconeura"))
)
(defrule plant_mulenbekia
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Mulenbekia"))
)
(defrule plant_musa_cavendishii
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Musa cavendishii"))
)
(defrule plant_nephrolepis_exaltata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Nephrolepis exaltata"))
)
(defrule plant_nertera_granadensis
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Nertera granadensis"))
)
(defrule plant_pachypodium_lamerei
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Pachypodium lamerei"))
)
(defrule plant_passiflora_caerulea
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Passiflora caerulea"))
)
(defrule plant_peperomia
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Peperomia"))
)
(defrule plant_phalaenopsis
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Phalaenopsis"))
)
(defrule plant_philodendron_erubescens_new_red
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"cieniste"|"półcieniste")
=>
	(assert (answer "Philodendron erubescens 'New Red'"))
)
(defrule plant_pilea_cadierei
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Pilea cadierei"))
)
(defrule plant_pinguicula_moranensis
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Pinguicula moranensis"))
)
(defrule plant_platycerium_bifurcatum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Platycerium bifurcatum"))
)
(defrule plant_plumbago_auriculata
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Plumbago auriculata"))
)
(defrule plant_polyscias_balfouriana_fabian
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Polyscias balfouriana 'Fabian'"))
)
(defrule plant_primula_vulgaris
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Primula vulgaris"))
)
(defrule plant_punica_granatum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Punica granatum"))
)
(defrule plant_rheo_spathacea
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Rheo spathacea"))
)
(defrule plant_rosa
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Rosa"))
)
(defrule plant_saintpaulia_ionantha
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Saintpaulia ionantha"))
)
(defrule plant_sarracenia_purpurea
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Sarracenia purpurea"))
)
(defrule plant_saxifraga_stolonifera_tricolor
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Saxifraga stolonifera 'Tricolor'"))
)
(defrule plant_scindapsus_aureus
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Scindapsus aureus"))
)
(defrule plant_scirpus_cernuus_isolepis_gracilis
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"rzadkie. Lubi ubogą")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Scirpus cernuus Isolepis gracilis"))
)
(defrule plant_sedum_rubrotinctum
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Sedum rubrotinctum"))
)
(defrule plant_senecio_macroglossus_variegatus
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Senecio macroglossus 'Variegatus'"))
)
(defrule plant_solanum_pseudocapiscum
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Solanum pseudocapiscum"))
)
(defrule plant_spathiphyllum
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste")
=>
	(assert (answer "Spathiphyllum"))
)
(defrule plant_stereospermum_sinicum
	(property "podlewanie" "dowolne"|"Umiarkowanie")
	(property "nawożenie" "dowolne"|"rzadkie")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Stereospermum sinicum"))
)
(defrule plant_synningia_speciosa_hybrid
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"częste podczas kwitnienia")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Synningia speciosa hybrid"))
)
(defrule plant_tolmia_menziesii
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Tolmia menziesii"))
)
(defrule plant_vriesea
	(property "podlewanie" "dowolne"|"Umiarkowanie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Vriesea"))
)
(defrule plant_yucca_elephantipes
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"cieniste"|"widne")
=>
	(assert (answer "Yucca elephantipes"))
)
(defrule plant_zantedeschia_aethiopca
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Zantedeschia aethiopca"))
)
(defrule plant_zingiber_officinale
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Zingiber officinale"))
)
(defrule plant_chamaecyparis_nootkanesis_tatra
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Chamaecyparis nootkanesis 'Tatra'"))
)
(defrule plant_chamaecyparis_pisifera_curly_tops
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Chamaecyparis pisifera 'Curly Tops'"))
)
(defrule plant_chamaecyparis_pisifera_plumosa
	(property "stanowisko" "dowolne"|"widne"|"słoneczne")
=>
	(assert (answer "Chamaecyparis pisifera 'Plumosa'"))
)
(defrule plant_ginkgo_biloba
	(property "podlewanie" "dowolne"|"umiarkowanie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne"|"cieniste i wilgotne")
=>
	(assert (answer "Ginkgo biloba"))
)
(defrule plant_juniperus_chinensis_blue_alps
	(property "stanowisko" "dowolne"|"słoneczne"|"półcień")
=>
	(assert (answer "Juniperus chinensis 'Blue Alps'"))
)
(defrule plant_juniperus_communis_green_carpet
	(property "stanowisko" "dowolne"|"słoneczne"|"półcień")
=>
	(assert (answer "Juniperus communis 'Green Carpet'"))
)
(defrule plant_juniperus_horizontalis_andorra_compact
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Juniperus horizontalis 'Andorra Compact'"))
)
(defrule plant_juniperus_horizontalis_wiltonii
	(property "stanowisko" "dowolne"|"słoneczne"|"półcień")
=>
	(assert (answer "Juniperus horizontalis 'Wiltonii'"))
)
(defrule plant_juniperus_media_pfitzeriana_aurea
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Juniperus media 'Pfitzeriana Aurea'"))
)
(defrule plant_juniperus_pingii_loderi
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Juniperus pingii 'Loderi'"))
)
(defrule plant_juniperus_squamata_blue_carpet
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Juniperus squamata 'Blue Carpet'"))
)
(defrule plant_juniperus_virginiana_skyrocket
	(property "podlewanie" "dowolne"|"-")
	(property "nawożenie" "dowolne"|"-")
	(property "stanowisko" "dowolne"|"słoneczne"|"półcień")
=>
	(assert (answer "Juniperus virginiana 'Skyrocket'"))
)
(defrule plant_thuja_occidentalis_abel_twa
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Thuja occidentalis 'Abel Twa'"))
)
(defrule plant_thuja_occidentalis_filiformis
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Thuja occidentalis 'Filiformis'"))
)
(defrule plant_thuja_occidentalis_little_dorrit
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Thuja occidentalis 'Little Dorrit'"))
)
(defrule plant_thuja_occidentalis_smaragd
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Thuja occidentalis 'Smaragd'"))
)
(defrule plant_thuja_occidentalis_teddy
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Thuja occidentalis 'Teddy'"))
)
(defrule plant_thuja_plicata_kórnik_iii
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Thuja plicata 'Kórnik III'"))
)
(defrule plant_budldleja_davidii
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Budldleja davidii"))
)
(defrule plant_cornus_alba
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Cornus alba"))
)
(defrule plant_cotinus coggygria
	(property "podlewanie" "dowolne"|"umiarkowanie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne i ciepłe")
=>
	(assert (answer "Cotinus coggygria"))
)
(defrule plant_cytisus
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Cytisus"))
)
(defrule plant_forsythia
	(property "stanowisko" "dowolne"|"słoneczne"|"widne")
=>
	(assert (answer "Forsythia"))
)
(defrule plant_hydrangea_macrophylla
	(property "podlewanie" "dowolne"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Hydrangea macrophylla"))
)
(defrule plant_ilex_aquifolium
	(property "podlewanie" "dowolne"|"umiarkowane"|"częste")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Ilex aquifolium"))
)
(defrule plant_lonicera_japonica_aureoreticulata
	(property "stanowisko" "dowolne"|"słoneczne"|"półcień")
=>
	(assert (answer "Lonicera japonica 'Aureoreticulata'"))
)
(defrule plant_magnolia_liliflora
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Magnolia liliflora"))
)
(defrule plant_potentilla_fruticosa
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Potentilla fruticosa"))
)
(defrule plant_pyracantha_coccinea
	(property "podlewanie" "dowolne"|"umiarkowane"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Pyracantha coccinea"))
)
(defrule plant_rosa_barkarole
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Rosa 'Barkarole'"))
)
(defrule plant_spirea_kaponica_goldflame
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Spirea kaponica 'Goldflame'"))
)
(defrule plant_weigela
	(property "podlewanie" "dowolne"|"umiarkowanie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne lub widne")
=>
	(assert (answer "Weigela"))
)
(defrule plant_arrhenaterum_bulbosum_variegatum
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Arrhenaterum bulbosum 'Variegatum'"))
)
(defrule plant_elymus_arenarius
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Elymus arenarius"))
)
(defrule plant_festuca_gautieri
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Festuca gautieri"))
)
(defrule plant_festuca_scoparia
	(property "podlewanie" "dowolne"|"rzadkie")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"widne")
=>
	(assert (answer "Festuca scoparia"))
)
(defrule plant_juncus_ensifolius
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Juncus ensifolius"))
)
(defrule plant_miskant_chinski
	(property "podlewanie" "dowolne"|"umiarkowane")
	(property "nawożenie" "dowolne"|"umiarkowane")
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Miskant chiński"))
)
(defrule plant_spartina_pectinata_aureomarginata
	(property "stanowisko" "dowolne"|"słoneczne")
=>
	(assert (answer "Spartina pectinata 'Aureomarginata'"))
)
