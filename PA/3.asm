.model small
.data
    msg db 0dh, 0ah, "Enter a character: $"
    char db ?
.code
main proc
    mov ax, @data
    mov ds, ax
    
    ; Display message
    lea dx, msg
    mov ah, 09h
    int 21h
    
    ; Read character
    mov ah, 01h
    int 21h
    mov char, al
    
    ; Display the entered character
    mov dl, char
    mov ah, 02h
    int 21h
    
    ; Exit
    mov ah, 4ch
    int 21h
main endp
end main
