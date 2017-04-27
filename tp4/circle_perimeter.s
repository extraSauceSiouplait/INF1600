.data
        factor: .float 2.0 /* use this to multiply by two */

.text
.globl _ZNK7CCircle12PerimeterAsmEv

_ZNK7CCircle12PerimeterAsmEv:
        push %ebp      /* save old base pointer */
        mov %esp, %ebp /* set ebp to current esp */
        
        mov 8(%ebp), %ebx
        
        fldpi               # st[0] = 3.1415...
        fld     4(%ebx)     # st[0] = mRadius   st[1] = 3.1415..
        fmulp               # st[0] = mRaduis * 3.1415
        
        fld     factor      # st[0] = 2         st[1] = mRadius * 3.1415
        fmulp               # st[0] = 2 * mRadius * 3.1415
        
        ##
        #La valeur retournée par la fonction est celle sur le dessus de la pile de calcul flottant
        # C-A-D st[0]
        ##
        
        leave          /* restore ebp and esp */
        ret            /* return to the caller */
