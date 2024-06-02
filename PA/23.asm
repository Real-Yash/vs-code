.model small
.stack 100h
.data
    str1 db 'Enter an array of numbers: $'
    str2 db 10,'Sorted array (Descending order): $'
    buf db 100 dup('$')
    size db 00h
.code
main proc
    mov ax, @data
    mov ds, ax
    
    ; Display message asking for an array
    mov ah, 09h
    lea dx, str1
    int 21h
    
    ; Read array from user
    mov ah, 0ah
    lea dx, buf
    int 21h
    
    ; Get the size of the array
    mov cl, buf+1
    mov size, cl
    
    ; Initialize loop counters
    mov ax, 0
    mov bx, 0
    
loop1:
    ; Get current size of the array
    mov dl, size
    dec dl
    
    ; Set SI to point to the start of the array
    mov si, offset buf+2
    
loop2:
    ; Load two adjacent elements into AL and BL
    mov al, [si]
    mov bl, [si+1]
    
    ; Compare BL and AL (switching for descending order)
    cmp bl, al
    jg repl ; If BL > AL, swap them
    
back:
    ; Move to the next pair of elements in the array
    inc si
    dec dl
    
    ; Check if there are more elements to compare
    cmp dl, 0
    jne loop2
    
    ; Decrement the size of the array
    dec cl
    
    ; Check if all elements have been compared
    cmp cl, 0
    jne loop1
    
    ; Jump to print when done sorting
    jmp print
    
repl:
    ; Swap BL and AL
    mov [si], bl
    mov [si+1], al
    jmp back
    
print:
    ; Display message for sorted array (descending order)
    mov ah, 09h
    lea dx, str2
    int 21h
    
    ; Display the sorted array
    mov ah, 09h
    lea dx, buf+2
    int 21h
    
    ; Exit program
    mov ah, 4ch
    int 21h
main endp
end main
