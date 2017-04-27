.data
        factor: .float 2.0
        demiPerim: .float 0

.text
.globl _ZNK9CTriangle7AreaAsmEv

_ZNK9CTriangle7AreaAsmEv:
        push %ebp      /* save old base pointer */
        mov %esp, %ebp /* set ebp to current esp */
        
        ##
        # La formule de Héron est utilisée afin de calculer l'aire d'un triangle quelconque dont on connait
        # la mesure des 3 cotés.
        #   p = Périmètre / 2
        #   a,b,c sont les mesures des 3 cotés
        #   A = sqrt(p(p-a)(p-b)(p-c))
        ##
        
        mov 8(%ebp), %ebx   # %ebx = adresse de l'objet triangle
        
        fld 4(%ebx)         #st[0] = mSides[0]
        fld 8(%ebx)         #st[0] = mSides[1]              st[1] = mSides[0]
        faddp               #st[0] = mSides[1] + mSides[0] 
        
        fld 12(%ebx)       #st[0] = mSides[2]              st[1] = mSides[1] + mSides[0]  st[2] = mSides[1] + mSides[0]
        
        faddp               #st[0] = perimTriangle          
        fld factor          #st[0] = 2                      st[1] = perimTriangle 
        fdivrp              #st[0] = perimTriangle / 2      
        
        fstp demiPerim         # demiPerimTriangle sauvegardé 
        
        fld demiPerim
        fld 4(%ebx)        #st[0] = mSides[0]              st[1] = demiPerim
        fsubrp              #st[0] = demiPerim-mSides[0]
                            
        fld demiPerim       #st[0] = demiPerim              st[1] = demiPerim-mSides[0]
        fld 8(%ebx)         #st[0] = mSides[1]              st[1] = demiPerim              st[2] = demiPerim-mSides[0]
        fsubrp              #st[0] = demiPerim-mSides[1]    st[2] = demiPerim-mSides[0] 

        
        fld demiPerim       #st[0] = demiPerim              st[1] = demiPerim-mSides[1]    st[2] = demiPerim-mSides[0]
        fld 12(%ebx)        #st[0] = mSides[2]              st[1] = demiPerim              st[2] = demiPerim-mSides[1]    st[3] = demiPerim-mSides[0]
        fsubrp              #st[0] = demiPerim-mSides[2]    st[1] = demiPerim-mSides[1]    st[2] = demiPerim-mSides[0]
        
        fmulp               # (p-a)(p-b)
        fmulp               # (p-a)(p-b)(p-c)
                
        fld demiPerim       # st[0] = demiPerim
        fmulp               # p*(p-a)(p-b)(p-c)
        
        fsqrt               # sqrt(p*(p-a)(p-b)(p-c))
        
        leave          /* restore ebp and esp */
        ret            /* return to the caller */
