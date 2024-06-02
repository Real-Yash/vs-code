.model small
.stack 100h
.data
    str1 db 'Enter an array: $'
    str2 db 10,'Smallest number: $'
    str3 db 100 dup('$')
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
    lea dx, str3
    int 21h
    
    ; Initialize variables
    mov si, offset str3+2
    mov bl, [si]
    
larr:
    ; Load current element into dl
    mov dl, [si]
    
    ; Check if end of array ('$' character)
    cmp dl, '$'
    je print
    
    ; Compare current element with smallest found so far
    cmp dl, bl
    jg move
    
    ; If current element is smaller, update smallest found so far
    mov bl, dl
    
move:
    ; Move to next element in array
    inc si
    jmp larr
    
print:
    ; Display message for smallest number
    mov ah, 09h
    lea dx, str2
    int 21h
    
    ; Display smallest number
    mov dl, bl
    mov ah, 02h
    int 21h
    
    ; Exit program
    mov ah, 4ch
    int 21h
main endp
end main
