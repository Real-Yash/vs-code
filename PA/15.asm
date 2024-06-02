.model small
.stack 100h
.data

ask db 'enter a string: $'
rev db 13,10,'reversed string: $'
input db 100 dup('$')
len dw ?

.code
mov ax,@data
mov ds,ax
mov es,ax

mov ah,09h
lea dx,ask
int 21h

mov ah,0ah
lea dx,input
int 21h

mov bl, input +1
mov len,bx

lea si,input+2
mov cl,bl


pushh:
mov bl,[si]
push bx
inc si
loop pushh
         
lea di,input+2
mov cx,len

popp:
pop bx
mov [di],bl
inc di
loop popp

mov ah,09h
lea dx,rev
int 21h

mov ah,09h
lea dx,input+2
int 21h

mov ah,4ch
int 21h
end
