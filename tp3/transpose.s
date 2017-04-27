.globl matrix_transpose_asm

matrix_transpose_asm:
        push %ebp      /* save old base pointer */
        mov %esp, %ebp /* set ebp to current esp */
        
        push %edi #On souhaite utiliser %edi comme compteur de lignes (r)
        push %ebx #On souhaite utiliser %ebx comme compteur de colonnes (c)
        xor %edi, %edi #On initialise ces compteurs à 0
        xor %ebx, %ebx
        
    testBoucle1:
        xor %ebx,%ebx #À chaque fois qu'on incrémente le compteur de ligne, on réinitialise le compteur de colonne à 0
        mov 16(%ebp), %eax #On charge %eax avec matorder
        cmp %edi, %eax
        jg testBoucle2 #r<matorder
        
        jmp fin
    
    testBoucle2:  
        mov 16(%ebp), %eax  #On charge %eax avec matorder
        cmp %ebx, %eax  
        jg boucle2 #c<matorder
        inc %edi #++r
        jmp testBoucle1
        
    boucle2:
        mov 16(%ebp), %eax #On charge %eax de matorder
        mul %ebx #On multiplie le compteur de colonne par %eax
        add %edi, %eax
        mov 8(%ebp), %edx #On charge %edx de la valeur de l'adresse de inmatdata
        mov (%edx,%eax,4),%ecx #On charge %ecx de la donnée à inmatdata[r + c * matorder]
        
        mov 16(%ebp), %eax #On charge %eax de matorder
        mul %edi #On multiplie le compteur de ligne par %eax
        add %ebx, %eax
        mov 12(%ebp), %edx #On charge %edx de la valeur de l'adresse de outmatdat
        # mov %edx(%ebx,%eax,4),%edx #On charge %edx de la donnée de outmatdata[c + r * matorder]
        
        mov %ecx, (%edx,%eax,4) #On remplace le contenu outmatdata[c + r * matorder] par le contenu de %ecx
    
        
        
        inc %ebx # ++c
        
        jmp testBoucle2
        
    fin:
        
        pop %ebx #On rend la valeur initiale à ce registre
        pop %edi #On rend la valeur initiale à ce registre
         
        leave          /* restore ebp and esp */
        ret            /* return to the caller */
