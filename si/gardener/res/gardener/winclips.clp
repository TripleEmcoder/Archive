(defrule tool_load_rules
	(initial-fact)
=>
	(load "tools.clp")
	(load "questions.clp")
	(load "rules.clp")
	;(load "plants.clp")
)
