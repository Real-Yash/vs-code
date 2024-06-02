.model small
.stack 100h

.data
      prompt db "Enter an email address: $"
      valid_msg db "Valid email address format.", 0
      invalid_msg db "Invalid email address format.", 0
      buffer db 100 dup('$')

.code
      main proc
            mov ax, @data
            mov ds, ax

            ; Display prompt
            mov ah, 09h
            lea dx, prompt
            int 21h

            ; Read input
            mov ah, 0Ah
            lea dx, buffer
            int 21h

            ; Check if valid email address format
            lea si, buffer
            mov cl, 0

      check_loop:
            lodsb
            cmp al, '@'
            je valid_email
            cmp al, '.'
            je valid_email
            cmp al, 0
            je invalid_email
            inc cl
            cmp cl, 100
            jne check_loop

      valid_email:
            mov ah, 09h
            lea dx, valid_msg
            int 21h
            jmp exit_program

      invalid_email:
            mov ah, 09h
            lea dx, invalid_msg
            int 21h

      exit_program:
            mov ah, 4Ch
            int 21h
      main endp
end main