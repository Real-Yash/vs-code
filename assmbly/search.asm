.model small
.stack 100h

.data
array db 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
arraySize equ $ - array

searchValue db 6

result db "Value found at index: $"

.code
main proc
      mov ax, @data
      mov ds, ax

      mov cx, arraySize
      mov al, searchValue

      mov bx, 0
searchLoop:
      cmp al, [array+bx]
      je found
      inc bx
      loop searchLoop

      mov ah, 09h
      lea dx, notFound
      int 21h
      jmp exit

found:
      mov ah, 09h
      lea dx, result
      int 21h

      mov ah, 02h
      mov dl, bx
      add dl, '0'
      int 21h

exit:
      mov ah, 4Ch
      int 21h
main endp

end main