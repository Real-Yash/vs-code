.model small
.stack 100h

.data
      num1 db 12h    ; First unpacked BCD number
      num2 db 34h    ; Second unpacked BCD number
      packed_num db ? ; Packed BCD number

.code
main proc
      mov al, num1   ; Move the first unpacked BCD number to AL register
      and al, 0Fh    ; Mask the upper nibble (decimal digit)
      shl al, 4      ; Shift the lower nibble to the upper nibble position

      mov ah, num2   ; Move the second unpacked BCD number to AH register
      and ah, 0Fh    ; Mask the upper nibble (decimal digit)

      or al, ah      ; Combine the upper nibbles of both numbers

      mov packed_num, al ; Store the packed BCD number

      ; Add your code here to perform further operations or display the result

      mov ah, 4Ch    ; Exit program
      int 21h
main endp

end main