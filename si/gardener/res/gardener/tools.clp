(defrule tool_store_answer
	(step ?step)
	(answer ?answer)
=>
	(assert (answer ?step ?answer))
)

;dodajemy własności, które są zabronione lub nie są dozwolone
(defrule tool_retract_property
	(property retract|~assert $?arguments)
	?i <- (property $?arguments)
=>
	(retract ?i)
)

;dodajemy własności, które są dozwolone i nie są zabronione
(defrule tool_assert_property
	?i <- (property assert $?arguments)
	(not (property retract $?arguments))
=>
	(retract ?i)
	(assert (property $?arguments))
)

;po dodaniu odpowiednich własności usuwany wszystkie zakazy
(defrule tool_retract_negative
	?i <- (property retract $?arguments)
	(not (property assert $?arguments))
	(not (property $?arguments))
=>
	(retract ?i)
)