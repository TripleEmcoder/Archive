(defrule tool_load_tools
	(initial-fact)
=>
	(load "winclips.clp")
)

(defrule tool_send_question
	?i <- (question ?question)
=>
	(retract ?i)
	(send-to-java (str-cat "question;" ?question))
)

(defrule tool_send_plant
	?i <- (plant ?plant)
=>
	(retract ?i)
	(send-to-java (str-cat "plant;" ?plant))
)