.model small
.stack 100h
.data
.code
main proc
MOV AH,02H ;(OR:     MOV AH, 06H)
MOV DL, 65
INT 21H
MOV AH,02H ;(OR:     MOV AH, 06H)
MOV DL, 110 
INT 21H
MOV AH,02H ;(OR:     MOV AH, 06H)
MOV DL, 105
INT 21H
MOV AH,02H ;(OR:     MOV AH, 06H)
MOV DL, 109
INT 21H
MOV AH,02H ;(OR:     MOV AH, 06H)
MOV DL, 101
INT 21H
MOV AH,02H ;(OR:     MOV AH, 06H)
MOV DL,  115
INT 21H
MOV AH,02H ;(OR:     MOV AH, 06H)
MOV DL, 104
INT 21H
       main endp
       end main

z