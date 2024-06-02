model small 
.stack 100h 
.data 
str1 db 'give an array of numbers: $' 
str2 db 10,'sorted array: $' 
buf db 100 dup('$') 
size db 00h 
.code 
mov ax,@data 
mov ds,ax 
mov ah,09h 
lea dx,str1 
int 21h 
mov ah,0ah 
lea dx,buf 
int 21h 
mov cl,buf+1 
mov size,cl 
mov ax,0 
mov bx,0 
loop1: 
mov dl,size 
dec dl 
mov si,offset buf+2 
~ 23 ~loop2: 
mov al,[si] 
mov bl,[si+1] 
cmp bl,al 
jl repl 
back: 
inc si 
dec dl 
cmp dl,0 
jne loop2 
dec cl 
cmp cl,0 
jne loop1 
jmp print 
repl: 
mov [si],bl 
mov [si+1],al 
jmp back 
print: 
mov dx,0000h 
mov ah,09h 
lea dx,str2 
~ 24 ~int 21h 
mov ah,09h 
lea dx,buf+2 
int 21h 
mov ah,4ch 
int 21h 
end 
