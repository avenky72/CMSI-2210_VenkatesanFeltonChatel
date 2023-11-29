global start
section .data
num1 db "Enter number" 0       
num2 db "Enter number" 0

segment .bss
input1  resd 1
input2  resd 1
section .text
start:

    mov eax, [num1]
    mov ebx, [num2]
    call gcd
    mov eax, 4
    mov ebx, 1
    mov ecx, [result]
    mov edx, 4
    int 80h
    mov eax, 1
    int 80h
    gcd:
    push ebp
    mov ebp, esp
    cmp ebx, 0
    je done
    mov eax, ebx
    div ebx
    mov ebx, edx
    jmp gcd
    done:
    mov esp, ebp
    pop ebp

    mov [result], eax
    ret
result: dd 0
