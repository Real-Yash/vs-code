.model small
.stack 100h

.data
array db 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 


arraySize equ ($ - array) / 2
newline db 0ah, 0dh, '$'

.code
main proc
      mov ax, @data
      mov ds, ax

      mov si, offset array
      mov di, offset array + (arraySize - 1) * 2

      mov cx, arraySize
      shr cx, 1

reverseLoop:
      mov ax, [si]
      xchg ax, [di]
      mov [si], ax

      add si, 2
      sub di, 2

      loop reverseLoop

      mov ah, 09h
      mov dx, offset newline
      int 21h

      mov cx, arraySize
      mov si, offset array

printLoop:
      mov ax, [si]
      mov ah, 02h
      int 21h

      add si, 2

      loop printLoop

      mov ah, 4Ch
      int 21h
main endp

end main