.model small 
.stack 100h 
.data 
str1 db 'give an array: $' 
str2 db 10,'largest number: $' 
str3 db 100 dup('$') 
.code 
mov ax,@data 
mov ds,ax 
mov ah,09h 
lea dx,str1 
int 21h 
mov ah,0ah 
lea dx,str3 
int 21h 
mov si, offset str3+2 
mov bl,[si] 
larr: 
mov dl,[si] 
cmp dl,'$' 
je print 
~ 8 ~cmp bl,dl 
jl move 
back: 
inc si 
jmp larr 
move: 
mov bl,dl 
jmp back 
print: 
mov ah,09h 
lea dx,str2 
int 21h 
mov dl,bl 
mov ah,02h 
int 21h 
mov ah,4ch 
int 21h 
end
