.MODEL SMALL
.stack 100h
.DATA
    num1 DW 1234h    ; First 16-bit number (change as needed)
    num2 DW 5678h    ; Second 16-bit number (change as needed)
    result DW ?      ; Variable to store the result

.CODE
MAIN PROC
    MOV AX, @DATA   ; Initialize DS
    MOV DS, AX

    MOV AX, num1    ; Load first number into AX
    MOV BX, num2    ; Load second number into BX

    MUL BX          ; Multiply AX by BX
    MOV result, AX  ; Store the result in memory

    MOV AH, 4CH     ; Exit to DOS function
 INT 21H         ; Call DOS

MAIN ENDP
END MAIN
