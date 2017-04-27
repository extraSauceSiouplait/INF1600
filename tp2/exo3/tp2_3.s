.data
	/* Votre programme assembleur ici... */
	i: .int 0

.global func_s

func_s:	
	/* Votre programme assembleur ici... */
        mov i, %edi
        jmp boucleFor
        
	boucleFor:
	
        mov d, %eax
        mov e, %edx
        add %eax, %edx
    
        mov b, %ebx
        sub %ebx, %edx
        mov %edx, a # a = d + e - b
        
        mov b, %ebx
        sub $1000, %ebx
        
        mov c, %ecx
        add $500, %ecx
        cmp %ebx, %ecx #Résultat comparaison pour premierIf
        
        jna premierElse
        
    premierIf:
        mov c, %ecx
        sub $500, %ecx # c - 500
        mov %ecx , c
        mov b, %ebx
        cmp %ebx, %ecx
        
        jae testBoucleFor
        
    deuxiemeIf:
        mov b, %ebx
        sub $500, %ebx
        mov %ebx, b
        
        jmp testBoucleFor
        
	premierElse:
        mov b,%ebx
        mov e, %edx
        sub %edx, %ebx
        mov %ebx, b
        
        mov d, %eax
        add $500, %eax
        mov %eax, d
        
        jmp testBoucleFor
        
    testBoucleFor:
        inc %edi
        cmp $10, %edi
        jna boucleFor
        
    ret
