.globl _ZNK9CTriangle12PerimeterAsmEv

_ZNK9CTriangle12PerimeterAsmEv:
        push %ebp      /* save old base pointer */
        mov %esp, %ebp /* set ebp to current esp */
        
        mov 8(%ebp), %ebx
        
        fld 4(%ebx)        #st[0] = mSides[0]
        fld 8(%ebx)#       #st[0] = mSides[1]              st[1] = mSides[0]
        faddp              #st[0] = mSides[1] + mSides[0]  st[1] = mSides[1] + mSides[0]
        
        fld 12(%ebx)       #st[0] = mSides[2]              st[1] = mSides[1] + mSides[0]  st[2] = mSides[1] + mSides[0]
        
        faddp              #st[0] = perimTriangle          st[1] = perimTriangle
                
        ##
        #La valeur retournée par la fonction est dans st[0]
        ##
        
        leave          /* restore ebp and esp */
        ret            /* return to the caller */
