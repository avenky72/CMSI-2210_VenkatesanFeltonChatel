         global   _main                ; this is the main entry point
         extern   _printf              ; external code from "C" library
         default  rel                  ; default to 'relative' addressing

         section  .text                ; text [code] segment

_main:
         push     rbx                  ; save this for return to O/S
         lea      rdi, [message]       ; load effective address of message
         call     _printf              ; call "C" printf function

exit:    pop      rbx                  ; restore base pointer
         ret                           ; return to O/S

         section  .data
message: db       "Hello, world!", 0x0A, 0x00

            
