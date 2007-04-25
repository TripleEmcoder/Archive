(defrule tool_store_answer
	(step ?step)
	(answer ?answer)
=>
	(assert (answer ?step ?answer))
)

;dodajemy własności, które są zabronione lub nie są dozwolone
(defrule tool_retract_property
	(property retract|~assert ?name ?value)
	?i <- (property ?name ?value)
=>
	(retract ?i)
	(assert (debug retract ?name ?value))
)

;dodajemy własności, które są dozwolone i nie są zabronione
(defrule tool_assert_property
	?i <- (property assert ?name ?value)
	(not (property retract ?name ?value))
=>
	(retract ?i)
	(assert (property ?name ?value))
	(assert (debug assert ?name ?value))
)

;po dodaniu odpowiednich własności usuwany wszystkie zakazy
(defrule tool_retract_negative
	?i <- (property retract ?name ?value)
	(not (property assert ?name ?value))
	(not (property ?name ?value))
=>
	(retract ?i)
)