.model small
.stack 100h
.data
buffer db 100 dup('$')
string1 db 'give a string : $'
stirng2 db 10,13,'given string reversed is : $'
.code
mov ax,@data
mov ds,ax
mov es,ax
mov ah,09h
lea dx,string1
int 21h

mov ah,0ah
lea dx,buffer
int 21h

lea si,buffer +2
lea di,buffer +2
mov bl, buffer +1
add di,bx
dec di

rev:
cmp di,si
jle print

mov al,[si]
xchg al,[di]
mov [si],al

inc si
dec di
jmp rev

print:
mov ah,09h
lea dx,stirng2
int 21h

mov ah,09h
lea dx,buffer+2
int 21h

mov ah,4ch
int 21h
end
