;Program to read a String from user and display it

.model small
.stack 100h

.data
    prompt db "Enter a string: $"
    buffer db 80  ; Maximum string length
    output db 80 dup('$')  ; Buffer to store the input string

.code
main proc
    mov ax, @data
    mov ds, ax

    lea dx, prompt
    mov ah, 9
    int 21h  ; Display prompt

    lea dx, buffer
    mov ah, 0Ah
    int 21h  ; Read string from user

    ; Display the entered string
    lea dx, output
    mov ah, 9
    int 21h

    mov ah, 4Ch
    int 21h  ; Exit program

main endp
end main
