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
      mov cx, 9
      mov si, offset matrix
      mov ah, 02h
printMatrix:
      mov dl, [si]
      add dl, 30h ; Convert to ASCII
      int 21h
      inc si
      loop printMatrix

      ; Perform transpose
      mov cx, 3
      mov si, offset matrix
      mov di, offset transposedMatrix
transposeMatrix:
      mov al, [si]
      mov [di], al
      add si, 3
      inc di
      loop transposeMatrix

      ; Print transposed matrix
      mov cx, 9
      mov si, offset transposedMatrix
      mov ah, 02h
printTransposedMatrix:
      mov dl, [si]
      add dl, 30h ; Convert to ASCII
      int 21h
      inc si
      loop printTransposedMatrix

      mov ah, 4Ch
      int 21h
main endp

end main