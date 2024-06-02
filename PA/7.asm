.model small
.stack 100h

.data
      count db 0

.code
main proc
      mov ax, 0BEEFh    ; Example register value
      mov cx, 16        ; Number of bits in the register

      mov bl, 0         ; Counter for number of 1's

count_loop:
      shr ax, 1         ; Shift right, moving the least significant bit into the carry flag
      jnc skip_inc      ; Jump if the carry flag is not set (bit was 0)
      inc bl            ; Increment the counter

skip_inc:
      loop count_loop   ; Repeat the loop until cx becomes zero

      mov count, bl     ; Store the count in memory

      ; Add your code here to display or use the count value

      mov ah, 4Ch       ; Exit program
      int 21h

main endp
end main