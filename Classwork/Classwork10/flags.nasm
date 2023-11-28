global _start
    pushf
    pop eax
    mov ebx, eax
    mov edx, 0xCAFEBABE 
    add eax, edx 
    mov edx, 0xCAFEBABE 
    add eax, edx 
    mov edx, 0xCAFEBABE 
    add eax, edx 
    mov edx, 0xCAFEBABE
    add eax, edx
    jc carry_message
    jmp end
carry_msg:
    mov [carry_msg_str], eax 
    call msg_m  
end:
    mov eax, 1
    int 0x80
section .data
carry_msg_str: db "Carry flag", 0x0A
msg_m:
    mov eax, 4
    mov ebx, 1 
    mov ecx, carry_msg_str 
    int 0x80 
    ret
