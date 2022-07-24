.Model Small 
.286
.Stack 64
.Data 

B_X DW 06h
B_X1 DW 06h
B_X2 DW 0h
B_X3 DW 0h
B_Y DW 40h 
B_Y2 DW 77h
B_SIZE DW 08h
time db 0h
 

photoWidth EQU 320
photoHeight EQU 200

photoFilename DB 'photo.bin', 0

photoFilehandle DW ?

photoData DB photoWidth*photoHeight dup(0)

.Code    
       
DrawB proc 
    mov cx,B_X
    mov dx,B_Y 
    
    lloopp:
    mov ah,0Ch
    mov al,02h
    mov bh,0h 
    int 10h
    inc cx
    mov ax,cx
    sub ax,B_X
    cmp ax,B_SIZE
    jc lloopp
    mov cx,B_X
    inc dx
    mov ax,dx
    sub ax,B_Y
    cmp ax,B_Size
    jc lloopp
    
    
    Ret
DrawB endp

DrawB1 proc 
    mov cx,B_X1
    mov dx,B_Y2 
    
    lloopp7:
    mov ah,0Ch
    mov al,02h
    mov bh,0h 
    int 10h
    inc cx
    mov ax,cx
    sub ax,B_X1
    cmp ax,B_SIZE
    jc lloopp7
    mov cx,B_X1
    inc dx
    mov ax,dx
    sub ax,B_Y2
    cmp ax,B_Size
    jc lloopp7
    
    
    Ret
DrawB1 endp


drawblack proc 
    mov cx,B_X2
    mov dx,B_Y 
    
    lloopp22:
    mov ah,0Ch
    mov al,00h
    mov bh,0h 
    int 10h
    inc cx
    mov ax,cx
    sub ax,B_X2
    cmp ax,B_SIZE
    jc lloopp22
    mov cx,B_X2
    inc dx
    mov ax,dx
    sub ax,B_Y
    cmp ax,B_Size
    jc lloopp22
     Ret
drawblack endp

drawblack1 proc 
    mov cx,B_X3
    mov dx,B_Y2 
    
    lloopp228:
    mov ah,0Ch
    mov al,00h
    mov bh,0h 
    int 10h
    inc cx
    mov ax,cx
    sub ax,B_X3
    cmp ax,B_SIZE
    jc lloopp228
    mov cx,B_X3
    inc dx
    mov ax,dx
    sub ax,B_Y2
    cmp ax,B_Size
    jc lloopp228
     Ret
drawblack1 endp

start proc near	
    CALL OpenFile
    CALL ReadData
	
    LEA BX , photoData ; BL contains index at the current drawn pixel
	
    MOV CX,0
    MOV DX,0
    MOV AH,0ch
	
; Drawing loop  

drawLoop:
    MOV AL,[BX]
    INT 10h 
    INC CX
    INC BX
    CMP CX,photoWidth
JNE drawLoop 
	
    MOV CX , 0
    INC DX
    CMP DX , photoHeight
JNE drawLoop

ret 
start endp

refresh proc
    mov ah,0
    mov al,13h
    int 10h   
    
    mov ah,0Bh
    mov bh,1H
    mov bl,02h
    int 10h
    ret
refresh endp
 

OpenFile PROC 


    MOV AH, 3Dh
    MOV AL, 0 
    LEA DX, photoFilename
    INT 21h
     
    MOV [photoFilehandle], AX
    
    RET

OpenFile ENDP

ReadData PROC

    MOV AH,3Fh
    MOV BX, [photoFilehandle]
    MOV CX,photoWidth*photoHeight ; number of bytes to read
    LEA DX, photoData
    INT 21h
    RET
ReadData ENDP 




CloseFile PROC
	MOV AH, 3Eh
	MOV BX, [photoFilehandle]

	INT 21h
	RET
CloseFile ENDP  

MAIN PROC FAR
    MOV AX , @DATA
    MOV DS , AX
    
    MOV AH, 0
    MOV AL, 13h
    INT 10h
	
    CALL OpenFile
    CALL ReadData
	
    LEA BX , photoData
	
    MOV CX,0
    MOV DX,0
    MOV AH,0ch
	
 

drawLoop1:
    MOV AL,[BX]
    INT 10h 
    INC CX
    INC BX
    CMP CX,photoWidth
JNE drawLoop1 
	
    MOV CX , 0
    INC DX
    CMP DX , photoHeight
JNE drawLoop1

    
    lloopp2:
    
   
    mov ah,2Ch 
    int 21h 
    
    cmp dl,time
    jz lloopp2
    
    mov time,dl
    inc B_X
    inc B_X2
    
    
    cmp B_X,79h
    
    jz ex22
     
    
     mov ah,01h
     int 16h
     cmp ah,4Dh
     jz pp
     jmp pppp
     
       pp: 
       cmp B_X1,120
       jz kkk
       add B_X1,2h
       pusha
       call DrawB1
       popa
       
       kkk:
       cmp b_X3,120
       jz kk
       add B_X3,2h
       pusha
       call drawblack1
       popa
       
       kk:
         
     
     
    pppp: 
       pusha
       call DrawB
       popa
       
       
    pusha
    call drawblack
    popa
  

    jmp lloopp2
    
    ex22: 
    mov ah,2Ch 
    int 21h 
    
    cmp dl,time
    jz ex22
    
    mov time,dl
    inc B_X2
    cmp B_X2,79h
    jz ex33
    call drawblack 
    jmp ex22
    ex33:   
       
       
    ;MOV AH,0          
;    MOV AL,03h
;    INT 10h

MAIN ENDP




END MAIN        








   