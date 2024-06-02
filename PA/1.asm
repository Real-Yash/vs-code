.model small
.stack 100h
.data
.code
main proc
MOV AH,02H ; (OR:MOV AH, 06H)
MOV DL, 90H
INT 21H
main endp
end main
