.model small 
.stack 100h 
.data 
str1 db 100 dup('$') 
ask1 db 10,'give a string: $' 
ask2 db 10,'character: $' 
ask3 db 10,'count: $' 
.code 
mov ax,@data 
mov ds,ax 
mov ah,09h 
lea dx,ask1 
int 21h 
mov ah,0ah 
lea dx,str1 
int 21h 
mov ah,09h 
lea dx,ask2 
int 21h 
mov ah,01h 
~ 5 ~int 21h 
mov si,offset str1+2 
mov cl,00h 
coun: 
mov bl,[si] 
cmp al,bl 
je plus 
back: 
inc si 
cmp bl,'$' 
je outt 
jmp coun 
plus: 
inc cl 
jmp back 
outt: 
mov ah,09h 
lea dx,ask3 
int 21h 
mov al,cl 
and al,0f0h 
rol al,04h 
add al,30h 
mov dl,al 
mov ah,02h 
int 21h 
mov al,cl 
and al,0fh 
add al,30h 
mov dl,al 
mov ah,02h 
int 21h 
mov ah,4ch 
int 21h 
end
