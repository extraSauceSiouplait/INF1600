.global matrix_row_aver_asm

matrix_row_aver_asm:
        push %ebp      			/* Save old base pointer */
        mov %esp, %ebp 			/* Set ebp to current esp */

		push %esi     #sauvegarde %esi
		push %edi     #sauvegarde %edi
		push %ebx#    #sauvegarde %ebx
		
		
		xor %edx, %edx          #initialisation de la ligne en cours
		xor %esi, %esi          #initialisation de la colonne en cours
		mov 16(%ebp), %ecx    #load 3e parametre (matorder)
		
		
		
		boucleStockage:
            mov %edx, %eax              #copie ligne en cours dans %eax
            mov 8(%ebp), %ebx           #load addresse de la ie valeur de inmatdata
            
            push %edx
            mul %ecx                    #ligne * matorder
            pop %edx
            
            add %esi, %eax              #Colonne + ligne * matorder
            mov (%ebx,%eax,4), %eax     #acces memoire elem en cours
            
            push %eax       #sauvegarde valeur de elem en cours
            
            inc %esi        #incremente colonne en cours
            cmp %esi, %ecx
            jne boucleStockage  #si colonne non achevée on recommence la boucleStockage
            
            xor %esi, %esi    #reinitialise colonne en cours a 0
            xor %ebx, %ebx    #initialise registre de somme
            
        boucleAddition:     #Addition des elems de la ligne#
            pop %eax        #load dernier élem
            add %eax, %ebx  # somme = somme + elem
            
            inc %esi
            cmp %esi, %ecx
            jne boucleAddition   #on additionne les termes de la ligne
            
            #Division#
            push %edx       #sauvegarde ligne en cours car %edx est affecté par la division
            xor %edx, %edx
            
            mov %ebx, %eax  #déplace sommeLigne dans %eax pour division
            mov 16(%ebp), %ebx
            div %ebx        #divise sommeLigne par matorder et stocke résultat dans %eax
            
            pop %edx
            
            mov 12(%ebp), %ebx
            mov %eax, (%ebx,%edx,4) #Stockage dans le parametre à modfier outmatdata
            
            ### Boucle conditionnelle ###
            
            inc %edx
            xor %esi, %esi        #initialisation a 0 de la colonne en cours
            
            cmp %edx, %ecx
            jne boucleStockage   #on recommence la boucle en procédant a la prochaine ligne
		
		
		pop %ebx      #on dépile les trois reigstres empilés au début
		pop %edi
		pop %esi
		
        leave          			/* Restore ebp and esp */
        ret           			/* Return to the caller */
		
