.name "phoenix"
.comment "easy-peasy"

getnum:		sti r1, %:live, %1
		and r6, r6, r6

live:		live %1
		zjmp %:getnum
