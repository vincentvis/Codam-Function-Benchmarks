global _ft_strlen_asm
_ft_strlen_asm:
    mov                         rax, -16                        ; Load 0 in return value
    pxor                        xmm0, xmm0                      ; Make sure xmm1 is all zero's
.ft_strlen_loop:
    lea                         rax, [rax + 16]
    pcmpistri                   xmm0, [rdi + rax], 00001010b    ; Commpare xmm0 with xmm1, ------10b = use 128-bit as 16 packed signed bytes
                                                                ; ----10--b = comp. mode = "equal each", since xmm1 is all 0 it finds zero's in any place
                                                                ; pcmpistri returns the left-most index of an valid comparison in rcx
                                                                ; is one of the bytes in second operand are NULL the zero flag is set
    jnz                         .ft_strlen_loop
    add                         rax, rcx
    ret