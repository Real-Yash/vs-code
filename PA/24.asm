.model small
.stack 100h

.data
source db "Hello, World!", '$'
destination db 20 dup('$')

.code
main proc
      mov ax, @data
      mov ds, ax

      lea si, source
      lea di, destination

copy_loop:
      mov al, [si]
      mov [di], al

      inc si
      inc di

      cmp al, '$'
      jne copy_loop

      mov al, '$'
      mov [di], al

      mov ah, 4Ch
      int 21h

main endp
end main