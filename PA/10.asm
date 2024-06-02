.model small
.stack 100h

.data
str1 db 'Animesh$'
str2 db 100 dup('$')
str3 db 'copied string: $'

.code
mov ax,@data
mov ds,ax
mov es,ax

lea si,str1
lea di,str2
mov ah,00h

copy:
mov al,[si]
mov [di],al

inc si
inc di

cmp al,'$'
je end

jmp copy

end:
lea dx,str3
mov ah,09h
int 21h

lea dx,str2
mov ah,09h
int 21h

mov ah,4ch
int 21h
end
