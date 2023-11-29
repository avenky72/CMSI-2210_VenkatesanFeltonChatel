global main
extern networkByteOrder

section .data
    testVals dq 1234; 4321; 9876; 6789; 2022; 2796; 3456

section .text
main:
    push rbp
    mov rbp, rsp
    mov rdi, [testVals]
    call networkByteOrder ; Iterate and call function
    mov rsp, rbp
    pop rbp

    ; Exit
    mov eax, 60
    xor edi, edi
    syscall
