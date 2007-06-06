(defrule tool_store_answer
	(step ?step)
	(answer ?answer)
=>
	(assert (answer ?step ?answer))
;	(assert (refresh reassert))
	(assert (debug store ?step ?answer))
)

(defrule tool_assert_refresh
	?i <- (refresh reassert)
	(not (refresh))
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


(defrule tool_write_property_debug
	(property ?name ?operator ?value)
=>
	(assert (debug property ?name ?operator ?value))
)

(defrule tool_constrain_property_equal
	?i <- (property ?name "=" ?value)
	?j <- (property ?name "!=" ?value)
=>
	(retract ?i)
	(retract ?j)
)

(defrule tool_constrain_property_max
	?i <- (property ?name "<=" ?left)
	?j <- (property ?name "<=" ?right&~?left)
	(test (<= ?left ?right))
=>
	(retract ?i)
	(retract ?j)
	(assert (property ?name "<=" ?left))
)

(defrule tool_constrain_property_min
	?i <- (property ?name ">=" ?left)
	?j <- (property ?name ">=" ?right&~?left)
	(test (>= ?left ?right))
=>
	(retract ?i)
	(retract ?j)
	(assert (property ?name ">=" ?left))
)

(defrule tool_format_property_debug
	?i <- (debug property ?name ?operator ?value)
=>
	(retract ?i)
	(assert (debug (str-cat "property " ?name " " ?operator " " ?value)))
)
