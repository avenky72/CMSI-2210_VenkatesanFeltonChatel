section .data
    input_string db 'RACECAR', 0
    string_length equ $ - input_string

section .text
    global _start
