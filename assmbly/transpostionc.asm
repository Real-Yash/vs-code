.model small
.stack 100h

.data
matrix db 1, 2, 3, 4, 5, 6, 7, 8, 9
transposedMatrix db 9 dup(0)

.code
main proc
      mov ax, @data
      mov ds, ax

      ; Print original matrix
      lea si, matrix
      mov cx, 9
      mov dl, 0Ah ; New line character
printOriginalMatrix:
      mov ah, 02h ; Print character
      mov dl, [si]
      add dl, 30h ; Convert to ASCII
      int 21h
      inc si
      loop printOriginalMatrix

      ; Transpose matrix
      mov si, offset matrix
      mov di, offset transposedMatrix
      mov cx, 3
transposeMatrix:
      mov al, [si]
      mov [di], al
      add si, 3
      inc di
      loop transposeMatrix

      ; Print transposed matrix
      lea si, transposedMatrix
      mov cx, 9
      mov dl, 0Ah ; New line character
printTransposedMatrix:
      mov ah, 02h ; Print character
      mov dl, [si]
      add dl, 30h ; Convert to ASCII
      int 21h
      inc si
      loop printTransposedMatrix

      mov ah, 4Ch ; Exit program
      int 21h
main endp

end main