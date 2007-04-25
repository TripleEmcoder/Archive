(defrule tool_setup_facts
	(initial-fact)
=>
	(assert (property "podlewanie" "dowolne"))
	(assert (property "nawożenie" "dowolne"))
	(assert (property "stanowisko" "dowolne"))
	(assert (step "lokalizacja1"))
)

(defrule tool_store_answer
	(step ?step)
	?i <- (answer ?answer)
=>
	(retract ?i)
	(assert (answer ?step ?answer))
)

(defrule tool_cancel_answer
	?i <- (cancel ?fact)
	?j <- (answer ?fact)
=>
	(retract ?i)
	(retract ?j)
)
