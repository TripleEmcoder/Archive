(defrule tool_setup_facts
	(initial-fact)
=>
	(assert (property "podlewanie" "dowolne"))
	(assert (property "nawożenie" "dowolne"))
	(assert (property "stanowisko" "dowolne"))
)

(defrule tool_send_answer
	?i <- (answer ?answer)
=>
	(retract ?i)
	(send-to-java ?answer)
)
