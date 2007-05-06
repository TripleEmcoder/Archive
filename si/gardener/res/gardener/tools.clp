(defrule tool_store_answer
	(step ?step)
	(answer ?answer)
=>
	(assert (answer ?step ?answer))
	(assert (refresh reassert))
	(assert (debug store ?step ?answer))
)

(defrule tool_initial_refresh
	(initial-fact)
=>
	(assert (refresh))
)

(defrule tool_reassert_refresh
	?i <- (refresh reassert)
	?j <- (refresh)
=>

	(retract ?i)
	(retract ?j)
	(assert (refresh))
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
;	(assert (debug cleanup ?name ?value))
)
