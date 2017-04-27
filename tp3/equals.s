.globl matrix_equals_asm

matrix_equals_asm:
        push %ebp      /* Save old base pointer */
        mov %esp, %ebp /* Set ebp to current esp */

            mov 16(%ebp), %eax  #load le 3e parametre de fonction, taille des 2 matrices
            mul %eax  #Nb d'éléments dans les matrices, ce sera notre condition du loop for(int i=0, i < matorder² ; i++)
            mov %eax, %ecx #On place matorder² dans %ecx pour l'utiliser dans le loop assembleur
            
        boucle:
        
        ### On traite les matrices comme deux tableaux unidimensionnels et on compare les éléments ###
        ### un a un en partant du dernier (position matorder²)  ###
            mov %ecx, %eax
            dec %eax
            mov 8(%ebp), %edx   
            
            mov (%edx, %eax, 4), %eax
            push %eax           #stocke l'élément i de la matrice 1
            
            mov %ecx, %edx
            dec %edx 
            mov 12(%ebp), %eax
            
            mov (%eax, %edx, 4), %eax  
            pop %edx        # #stocke l'élément i de la matrice 2
            
            cmp %eax, %edx  
            je continue     #si les éléments sont égaux, on continue
                        
        break:
            xor %eax, %eax
            jmp leave       #si un couple d'élément est différent, la fonction retourne 0
            
        continue:
            loop boucle     #décrémente matorder²
            
            mov $1, %eax    #si tous les éléments sont égaux, les matrices sont égales, la fonction ret 1
            
        leave:    
            leave          /* Restore ebp and esp */
            ret            /* Return to the caller */
