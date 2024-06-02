.MODEL SMALL
.STACK 100h
.DATA
      num DW ?
      pos_msg DB 'Positive', 0Dh, 0Ah, '$'
      neg_msg DB 'Negative', 0Dh, 0Ah, '$'
      zero_msg DB 'Zero', 0Dh, 0Ah, '$'
.CODE
START:
      MOV AH, 1h    ; Function to read character from console
      INT 21h       ; Call DOS services
      SUB AL, '0'   ; Convert from ASCII to number
      MOV BL, AL    ; Store the first digit in BL

      MOV AH, 1h    ; Function to read character from console
      INT 21h       ; Call DOS services
      SUB AL, '0'   ; Convert from ASCII to number
      MOV BH, AL    ; Store the second digit in BH

      MOV AX, BX    ; Move the number to AX for checking
      OR AX, AX     ; Perform OR operation on the number
      JZ zero        ; If zero, jump to zero label
      JS negative    ; If sign bit is set, jump to negative label
      JMP positive   ; If not zero or negative, it must be positive

zero:
      ; Code for zero number
      LEA DX, zero_msg
      MOV AH, 9h
      INT 21h
      JMP exit

negative:
      ; Code for negative number
      LEA DX, neg_msg
      MOV AH, 9h
      INT 21h
      JMP exit

positive:
      ; Code for positive number
      LEA DX, pos_msg
      MOV AH, 9h
      INT 21h

exit:
      MOV AH, 4Ch   ; Terminate program
      INT 21h
END START
