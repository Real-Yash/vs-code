.model small
.stack 100h

.data
      string db 'Hello, World!', '$'
      searchChar db 'o'

.code
main proc
      mov ax, @data
      mov ds, ax

      mov si, offset string
      mov al, searchChar

searchLoop:
      cmp byte ptr [si], al
      je found

      inc si
      cmp byte ptr [si], '$'
      jne searchLoop

      mov ah, 4Ch
      int 21h

found:
      mov ah, 9
      lea dx, foundMessage
      int 21h

      mov ah, 4Ch
      int 21h

main endp
end main