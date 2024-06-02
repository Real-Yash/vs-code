.model small
.stack 100h

.data
      str1 db "Hello, World!", 0
      len equ $ - str1

.code
      mov ax, @data
      mov ds, ax

      lea si, str1
      lea di, str1

      mov cx, len
      dec cx

reverse_loop:
      cmp si, di
      jge reverse_done

      mov al, [si]
      mov ah, [di]
      mov [di], al
      mov [si], ah

      inc si
      dec di
      jmp reverse_loop

reverse_done:
      mov ah, 4Ch
      int 21h
end