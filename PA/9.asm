.model small
.stack 100h

.data
      packed_num db 0A1h    ; Packed BCD number to unpack
      unpacked_num db ?     ; Unpacked BCD number

.code
      main proc
            mov ax, @data       ; Initialize data segment
            mov ds, ax

            mov al, packed_num  ; Load packed BCD number into AL register

            and al, 0Fh         ; Extract lower 4 bits (least significant digit)
            add al, 30h         ; Convert to ASCII
            mov unpacked_num, al

            mov al, packed_num  ; Load packed BCD number into AL register

            shr al, 4           ; Shift right to get higher 4 bits (most significant digit)
            add al, 30h         ; Convert to ASCII
            mov unpacked_num+1, al

            mov ah, 09h         ; Print unpacked BCD number
            lea dx, unpacked_num
            int 21h

            mov ah, 4Ch         ; Exit program
            int 21h
      main endp
end main