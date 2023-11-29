global _paritygen

section .text
_paritygen:
    push ebp
    mov ebp, esp
    mov bl, [ebp + 8] ; Byte of data
    mov cl, 0
    parityloop:
        shl bl, 1
        ;lsb 1
        inc cl 
        ;lsb zero
        jnc paritycheck
        inc cl 
        jmp parityloop
paritycheck:
    mov al, cl
    and al, 1 
    mov esp, ebp
    pop ebp
    ret
