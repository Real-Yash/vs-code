.model small
.stack 100h
.data
str1 db 'give a string : $'
str2 db 10,'given string: $'
buffer db 100 dup('$')
.code
mov ax,@data
mov ds,ax
mov es,ax

mov ah,09h
lea dx,str1
int 21h

mov ah,0ah
lea dx,buffer
int 21h

mov ah,09h
lea dx,str2
int 21h

lea dx,buffer+2
int 21h

mov ah,4ch
int 21h
          end 
