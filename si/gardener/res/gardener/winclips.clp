(defrule tool_load_rules
	(initial-fact)
=>
	(load "tools.clp")
	(load "questions.clp")
	(load "rules.clp")
	(load "plants.clp")
	(assert (step "lokalizacja1"))
)

(defrule tool_send_question
	?i <- (question ?question)
=>
	(retract ?i)
	(printout t "question;" ?question crlf)
)

(defrule tool_send_plant
	?i <- (plant ?plant)
=>
	(retract ?i)
	(printout t "plant;" ?plant crlf)
)

(defrule tool_send_debug
	?i <- (debug ?action ?name ?value)
=>
	(retract ?i)
	(printout t ?action ": " ?name "=" ?value crlf)
)
