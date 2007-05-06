(defrule tool_load_tools
	(initial-fact)
=>
;	(load "tools.clp")
;	(load "questions.clp")
;	(load "rules.clp")
;	(load "plants.clp")
	(assert (step "lokalizacja1"))
)

(defrule tool_send_debug
	?i <- (debug ?action ?name ?value)
=>
	(retract ?i)
	(send-to-java (str-cat ?action ": " ?name "=" ?value))
)

(defrule tool_send_question
	?i <- (question ?question)
=>
	(retract ?i)
	(send-to-java (str-cat "question;" ?question))
)

(defrule tool_send_plant
	(declare (salience -20))
	?i <- (plant ?plant)
=>
	(retract ?i)
	(send-to-java (str-cat "plant;" ?plant))
)
