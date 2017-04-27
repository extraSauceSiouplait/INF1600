.data
        factor: .float 2.0

.text
.globl	_ZNK9CTriangle9HeightAsmEv

_ZNK9CTriangle9HeightAsmEv:
        push %ebp      /* save old base pointer */
        mov %esp, %ebp /* set ebp to current esp */
        
        mov 8(%ebp), %eax   #move ObjetTriangle dans %ebx
        mov 0(%eax), %ebx    # %eax = VtableTriangle
        
        push %eax           #push %eax sur le stack pour l'utiliser comme paramètre de triangle_area
        call *16(%ebx)      #st[0] = triangle_area
        fld factor          #st[0] = 2.0    st[1] = triangle_area
        fmulp               #st[0] = triangle_area * 2.0
        
        

        fld 12(%eax)        #st[0] = mSides[2] st[1] = trangle_area * 2.0
        fdivrp              #st[0] = triangle_height
        
        ##
        #La valeur retournée par la fonction est dans st[0]
        ##
        
        leave          /* restore ebp and esp */
        ret            /* return to the caller */
