.global matrix_diagonal_asm

matrix_diagonal_asm:
        push %ebp      			/* Save old base pointer */
        mov %esp, %ebp 			/* Set ebp to current esp */

		push %esi     #sauvegarde %esi
		push %edi     #sauvegarde %edi
		push %ebx     #sauvegarde %ebx
		
		mov 16(%ebp), %eax    #load 3e parametre (matorder)
		mul %eax              #calcul matorder²
		mov %eax, %ecx
		
		dec %ecx # décrémente matorder² afin de donner initialement le dernier elem d'une matrice
		
		mov 12(%ebp), %edx
		
boucleInit:
    
        xor %esi, %esi
        mov %esi,(%edx, %ecx, 4)    # %esi = 0, on place %esi dans la ie case de outmatdata
                        
        loop boucleInit     # ecx décrémente a chaque boucle pour donne l'indice de l'elem en cours (en partant du dernier elem)                           

continue:
            
        mov 16(%ebp), %ecx    #réinitialise la valeur de matorder  
        xor %edx, %edx        #initialisation de la ligne en cours
        xor %esi, %esi        #initialisation de la colonne en cours
            
		
boucleDiagonale:
		
        mov %edx, %eax              #copie ligne en cours dans %eax
        mov 8(%ebp), %ebx           #load addresse de la premiere valeur de inmatdata
        
        push %edx   
        mul %ecx                    #ligneEnCours * matorder
        pop %edx 
        
        add %edx, %eax              #ligne + ligne * matorder
            
        mov (%ebx,%eax,4), %edi     #%edi = valeur de l'elem sur la diagonale de inmatdata
        
        mov $4, %esi
        push %edx
        mul %esi
        pop %edx
       
        mov 12(%ebp), %esi          #adresse du premier elem de outmatdata
        add %esi, %eax            
            
        mov %edi, (%eax)    #inmatdata[i] = outmatdata[i]            
            
        inc %edx        #incremente ligne en cours
        cmp %edx, %ecx
        jne boucleDiagonale  #la boucle s'effectue jusqu'à la derniere ligne de intmatdata

		
		
		pop %ebx      #on dépile les trois reigstres empilés au début
		pop %edi
		pop %esi
		
        leave          			/* Restore ebp and esp */
        ret           			/* Return to the caller */
