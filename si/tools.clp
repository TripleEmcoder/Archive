﻿(defrule tool_setup_facts
	(initial-fact)
=>
	(assert (property "podlewanie" "dowolne"))
	(assert (property "nawożenie" "dowolne"))
	(assert (property "stanowisko" "dowolne"))
)

(defrule tool_send_plant
	?i <- (plant ?plant)
=>
	(retract ?i)
	(send-to-java "plant;" ?plant)
)

(defrule tool_cancel_answer
	?i <- (cancel ?fact)
	?j <- (answer ?fact)
=>
	(retract ?i)
	(retract ?j)
)
