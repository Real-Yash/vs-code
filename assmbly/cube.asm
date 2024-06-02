.model small
.stack 100h

.data
      prompt db "Enter a number (0-9): $"
      result db "Cube of ", 0
      cube db 0

.code
main proc
      mov ax, @data
      mov ds, ax

      mov ah, 09h
      lea dx, prompt
      int 21h

      mov ah, 01h
      int 21h
      sub al, '0' ; convert ASCII digit to numeric value

      mov bl, al ; save the number in bl

      mov ah, 09h
      lea dx, result
      int 21h

      mov al, bl ; restore the number from bl

      mov ah, 02h
      add al, '0' ; convert numeric value to ASCII digit
      int 21h

      mov ah, 09h
      lea dx, cube
      int 21h

      mov al, bl ; restore the number from bl
      mul al ; multiply the number by itself
      mul al ; multiply the result by the number again

      add al, '0' ; convert numeric value to ASCII digit
      mov ah, 02h
      int 21h

      mov ah, 4Ch
      int 21h
main endp

end main