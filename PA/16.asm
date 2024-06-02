.model small
.stack 100h
.data
string1 db 13,10, 'Give the first string: $'
string2 db 13,10, 'Give the second string: $'

buffer1 db 100 dup('$')
buffer2 db 100 dup('$')

out1 db 13,10, 'The strings are equal !$'
out2 db 13,10, 'The strings are not equal !$'
.code
main proc

mov ax,@data
mov ds,ax
mov es,ax

mov ah,09h
lea dx,string1
int 21h

mov ah,0ah
lea dx,buffer1
int 21h

mov ah,09h
lea dx,string2
int 21h

mov ah,0ah
lea dx,buffer2
int 21h

call comp

mov ah,4ch
int 21h
main endp

comp proc

lea si,buffer1 +2
lea di,buffer2 +2

mov bl,buffer1 +1
mov cl,buffer2 +1

cmp bl,cl
jne neq


compare:

mov bl,[si]
mov al,[di]

cmp al,bl
jne neq

dec cl

inc si
inc di

cmp cl,0
je eq

jmp compare

eq:

mov ah,09h
lea dx,out1
int 21h
ret

neq:

mov ah,09h
lea dx,out2
int 21h
ret

comp endp
end
