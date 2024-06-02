.model small
.stack 100h

.data
      msg1 db "Enter a number: $"
      msg2 db "Factorial: $"
      newline db 0Ah, 0Dh, "$"
      num db ?
      fact dw 1

.code
      main proc
            mov ax, @data
            mov ds, ax

            ; Display message to enter a number
            mov ah, 09h
            mov dx, offset msg1
            int 21h

            ; Read a single digit number from the user
            mov ah, 01h
            int 21h
            sub al, 30h
            mov num, al

            ; Calculate factorial
            mov cx, num
            mov bx, num
            dec bx

      loop1:
            mul bx
            loop loop1

            mov fact, ax

            ; Display message for the factorial
            mov ah, 09h
            mov dx, offset msg2
            int 21h

            ; Display the factorial value
            mov ax, fact
            add ax, 30h
            mov dl, al
            mov ah, 02h
            int 21h

            ; Display newline
            mov ah, 09h
            mov dx, offset newline
            int 21h

            mov ah, 4Ch
            int 21h
      main endp
end main