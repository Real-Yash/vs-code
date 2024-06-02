.model small
.stack 100h

.data

str db 'Animesh$'
char db 'e'
str1 db 10,'character found is : $'

.code
mov ax,@data
mov ds,ax
mov es,ax

lea di,str
mov al,char
mov cx,09h
cld 
repne scasb     

mov ah,09h
lea dx,str1
int 21h

mov ah,02h
mov dl,al
int 21h

mov ah,4ch
int 21h
end
