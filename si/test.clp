(defrule rule1
	(initial-fact)
=>
	(send-to-java "question;A wpierdol byś chciał ?;Tak=fact1;Nie=fact2;Nie wiem=fact3")
)

(defrule rule2
	(fact1)
=>
	(send-to-java "question;To dostaniesz !!!;Tak=fact3;Nie=fact4;Nie wiem=fact5")
)

(defrule rule3
	(fact2)
=>
	(send-to-java "question;Nie to nie !!;Tak=fact6;Nie=fact7;Nie wiem=fact8")
)
