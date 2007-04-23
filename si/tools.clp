(defrule tool_setup_facts
	(initial-fact)
=>
	(assert (podlewanie dowolne))
	(assert (nawozenie dowolne))
	(assert (stanowisko dowolne))
)

(defrule tool_send_answer
	?i <- (answer ?answer)
=>
	(retract ?i)
	(send-to-java ?answer)
)
