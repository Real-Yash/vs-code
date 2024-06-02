.model small
.stack 100h

.data
      message db 10, 13, 'The number is: $'
      positive db 'Positive', 0
      negative db 'Negative', 0
      zero db 'Zero', 0

.code
      main proc
            mov ax, @data
            mov ds, ax

            mov ah, 9
            lea dx, message
            int 21h

            mov ah, 1
            int 21h

            sub al, '0' ; convert ASCII digit to binary

            cmp al, 0
            jg positive
            jl negative
            je zero

      positive:
            mov ah, 9
            lea dx, positive
            int 21h
            jmp exit

      negative:
            mov ah, 9
            lea dx, negative
            int 21h
            jmp exit

      zero:
            mov ah, 9
            lea dx, zero
            int 21h

      exit:
            mov ah, 4Ch
            int 21h
      main endp
end main