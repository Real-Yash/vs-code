.model small 
.stack 100h 
.data 
str1 db 'Give a 
array of 
numbers: $' 
str2 db 
10,'Their 
average:- $' 
buf db 100 
dup('$') 
str3 db 
10,'Questiant: 
$' 
str4 db 
10,'Remainder: 
$' 
.code 
mov ax,@data 
mov ds,ax 
mov ah,09 
lea dx,str1 
int 21h 
mov ah,0ah 
~ 10 ~lea dx,buf 
int 21h 
mov si,offset 
buf+2 
mov ax,0 
mov cx,0 
mov cl,buf+1 
sum: 
mov bl,[si] 
sub bl,30h 
add al,bl 
inc si 
dec cl 
cmp cl,0 
jne sum 
mov cl,buf+1 
mov bx,ax 
div cl 
mov bx,ax 
mov ah,09h 
lea dx,str2 
int 21h 
mov ah,09h 
lea dx,str3 
~ 11 ~int 21h 
mov dx,0 
mov al,bl 
and al,0f0h 
rol al,4 
add al,30h 
mov dl,al 
mov ah,02h 
int 21h 
mov al,bl 
and al,0fh 
add al,30h 
mov dl,al 
mov ah,02h 
int 21h 
mov ah,09h 
lea dx,str4 
int 21h 
mov dx,0 
mov al,bh 
and al,0f0h 
rol al,4 
add al,30h 
mov dl,al 
mov ah,02h 
~ 12 ~int 21h 
mov al,bh 
and al,0fh 
add al,30h 
mov dl,al 
mov ah,02h 
int 21h 
mov ah,4ch 
int 21h 
end
