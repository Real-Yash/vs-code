.model small
.stack 100h
.data
buffer db 'Animesh$'
string1 db 'string : $'
string2 db 10,13,'string reversed is : $'

.code

mov ax,@data
mov ds,ax
mov es,ax

mov ah,09h
lea dx,string1
int 21h

mov ah,09
lea dx,buffer
int 21h

lea si,buffer

lea di,buffer +6

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
lea dx,string2
int 21h

lea dx,buffer
int 21h

mov ah,4ch
int 21h
end
