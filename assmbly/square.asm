section .data
      number db 100    ; The 8-bit binary number to find the square root of

section .text
      global _start

_start:
      mov al, [number]  ; Move the binary number into the AL register
      xor ah, ah        ; Clear the AH register

      mov bl, 1         ; Initialize the counter to 1
      mov cl, 8         ; Set the loop counter to 8

loop_start:
      shr ax, 1         ; Shift the number right by 1 bit
      jnc skip_inc      ; If the carry flag is not set, skip the increment

      inc bl            ; Increment the counter

skip_inc:
      loop loop_start   ; Repeat the loop until the counter reaches 8

      ; The square root of the binary number is now stored in the BL register

      ; Add your code here to handle the result

      ; Exit the program
      mov eax, 1
      xor ebx, ebx
      int 0x80