.globl _ZNK7CCircle7AreaAsmEv

_ZNK7CCircle7AreaAsmEv:
        push %ebp      /* save old base pointer */
        mov %esp, %ebp /* set ebp to current esp */
        
        mov 8(%ebp), %ebx
        
        fld 4(%ebx)   #st[0] = mRadius
        fld 4(%ebx)   #st[0] = mRadius    st[1] = mRadius
        
        fmulp       #st[0] = mRadius²
        
        fldpi       #st[0] = 3.1415...  st[1] = mRadius²
        fmulp       #st[0] = 3.1415... * mRadius²
        
        ##
        #La valeur retournée par la fonction est celle sur le dessus de la pile de calcul flottant
        # C-A-D st[0]
        ##
        
        
        leave          /* restore ebp and esp */
        ret            /* return to the caller */
