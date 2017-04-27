.global func_s

func_s:

	flds g
	flds e
	fsubrp # g - e
	
	flds f
	fdivrp # (g - e) / f
	
	flds e
	flds b
	flds d
	fmulp # b * d
	
	flds c
	fsubrp # (b * d) - c
	
	flds f
	flds g
	fsubrp # f - g
	
	fdivrp # ((b * d) - c)/ ( f - g)
	faddp # + e
	fmulp # parenthese1 * parenthese 2
	
	fstps a # a = resultat
	
	ret
