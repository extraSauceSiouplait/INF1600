.data
    
    colonneProduit:
                    .byte 0

.text
.global matrix_multiply_asm

matrix_multiply_asm:
        push %ebp      			/* Save old base pointer */
        mov %esp, %ebp 			/* Set ebp to current esp */

		push %esi     #sauvegarde %esi
		push %edi     #sauvegarde %edi
		push %ebx#    #sauvegarde %ebx
		
		
		xor %edi, %edi          #initialisation de la ligne en cours
		xor %esi, %esi          #initialisation de la colonne en cours
		mov 20(%ebp), %ecx    #load 4e parametre (matorder)
		
		
		xor %edx, %edx        #initialise le compteur de somme (i dans le code c)
		boucleStockage:
            ### trouver valeur de elem i de ligne j de inmatdata1 ##
            
            mov %edi, %eax              #copie ligne en cours dans %eax
            mov 8(%ebp), %ebx           #load addresse de la première valeur de inmatdata1
            
            push %edx
            mul %ecx                    #ligne * matorder
            pop %edx
            
            add %edx, %eax              #%eax= i + ligne * matorder
            mov (%ebx,%eax,4), %eax     #acces memoire elem en cours
            
            push %eax       #sauvegarde valeur de elem en cours
                        
            ### Trouver valeur de elem j de la ligne i de inmatdata2 ##
            
            mov %edx, %eax              #copie i dans %eax
            mov 12(%ebp), %ebx           #load addresse de la ie valeur de inmatdata2
            
            push %edx
            mul %ecx                    #%eax = i * matorder
            pop %edx
            
            add colonneProduit, %eax              #Colonne + i * matorder
            mov (%ebx,%eax,4), %eax     #acces memoire elem en cours
            
            push %eax       #sauvegarde valeur de elem en cours
            
            inc %edx        #incremente i
            cmp %edx, %ecx
            ja boucleStockage  #si ligne de inmatdata1 non achevée on recommence la boucleStockage
            
            xor %esi, %esi    #reinitialise colonne en cours a 0
            xor %edx, %edx    #initialise registre de somme
            
        boucleAdditionDesProduits:     
        ###Somme des produits issus du produit matriciel d'une ligne de inmatdata1###
        
            pop %eax
            pop %ebx
            
            push %edx
            mul %ebx        # produit de inmatdata1[i,j] * inmatdata2[j,i]
            pop %edx
            
            add %eax, %edx  # somme = somme + produitEnCours
            
            inc %esi        #incrémente colonne en cours
            cmp %esi, %ecx
            ja boucleAdditionDesProduits   #on additionne les produits issus d'une même ligne de inmatdata1
            
            push %edx   #sauvegarde de l'elem pour outmatdata
            
        ### test de la boucle des colonnes de inmatdata1 ##    
            incb (colonneProduit)
            xor %edx,%edx
            cmp (colonneProduit), %ecx
            ja boucleStockage
            
        ### test de la boucle des lignes de inmatdata1 ##
            
            inc %edi              #on incrémente la ligne en cours
            movb $0, (colonneProduit)
            
            cmp %edi, %ecx
            ja boucleStockage   #on recommence la boucle en procédant a la prochaine ligne
		
		
		### Construction de outmatdata ##
		
            mov 20(%ebp), %eax    #load 3e parametre (matorder)
            mul %eax              #calcul matorder²
            mov %eax, %ecx
		
            dec %ecx # décrémente matorder² afin de donner initialement le dernier elem d'une matrice
		
            mov 16(%ebp), %edx  #load adresse du 1er element de outMatData 
		
		boucleOutMatData:
		
		    
            pop %esi
            mov %esi,(%edx, %ecx, 4)
                        
            loop boucleOutMatData   
            
            ## loop ne permet pas >=0 donc il faut placer manuellement le dernier élément
            pop %esi
            mov %esi, (%edx)
	
		
		pop %ebx      #on dépile les trois reigstres empilés au début
		pop %edi
		pop %esi
		
        leave          			/* Restore ebp and esp */
        ret           			/* Return to the caller */
