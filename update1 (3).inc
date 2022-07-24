WINNERMACRO MACRO
LOCAL lloopp2WIN
LOCAL ex22WIN     
    
    
       MOV AH,0H
    MOV AL,13H              
    INT 10H 
    MOV BH,0
    MOV DL,0bH
    MOV DH,0bH
    MOV AH,2H
    INT 10H
    MOV AH,9H
    LEA DX,MESWIN
    INT 21H
    mov SI,0h
    lloopp2WIN:
    mov ah,2Ch 
    int 21h 
    cmp dh,time
    jz lloopp2WIN
    mov time,dh
    inc SI
    cmp SI,04h
    jz ex22WIN 
    jmp lloopp2WIN
    ex22WIN:
    MOV AH,0H
    MOV AL,13H              
    INT 10H 
    HLT
    
ENDM WINNERMACRO

 
    

FROMDIGITTOASCILL MACRO BYTTOASC  
    LOCAL G9
    LOCAL G91
    lOCAL FFFFF
    LOCAL F111
    LOCAL F1111
    LOCAL A111
    LOCAL A1111
    LOCAL B111
    LOCAL B1111
    LOCAL C111
    LOCAL C1111
    LOCAL D111
    LOCAL D1111
    LOCAL E111
    LOCAL E1111
    LOCAL FLL2
    

    LEA DI,TWOBYTE
     MOV AL,BYTTOASC
     MOV AH,0H
     MOV BL,10H
     
     DIV BL
     
     CMP AL,10
     JNC G9
     ADD AL,30H
     MOV BYTE PTR [DI],AL
      JMP FLL2
     
     
      G9:
     CMP AL,0AH 
        JZ A111
     CMP AL,0BH
         JZ  B111
     CMP AL,0CH
        JZ C111
     
     CMP AL,0DH
        JZ D111
     
     CMP AL,0EH
        JZ E111
     
     CMP AL,0FH
        JZ F111
        
       
     
     A111:
     MOV BYTE PTR [DI],'A'
     JMP FLL2
     
     B111: 
     MOV BYTE PTR [DI],'B'
     JMP FLL2
     
     C111:
     MOV BYTE PTR [DI],'C'
     JMP FLL2
     D111:
     MOV BYTE PTR [DI],'D'
     JMP FLL2                 
                      
     E111:
     MOV BYTE PTR [DI],'E'
     JMP FLL2
     F111:
     MOV BYTE PTR [DI],'F' 
     JMP FLL2  
      
        FLL2:
      
     CMP AH,10
     JNC G91
     ADD AH,30H
     MOV BYTE PTR [DI+1],AH   
     JMP  FFFFF 
     
     
      G91:
     CMP AH,0AH 
        JZ A1111
        
     CMP AH,0BH
         JZ  B1111
     CMP AH,0CH
        JZ C1111
     
     CMP AH,0DH
        JZ D1111
     
     CMP AH,0EH
        JZ E1111
     
     CMP AH,0FH
        JZ F1111
     
      A1111:
      MOV BYTE PTR [DI+1],'A'
      JMP  FFFFF
     
      B1111: 
      MOV BYTE PTR [DI+1],'B'
      JMP  FFFFF
     
      C1111:
      MOV BYTE PTR [DI+1],'C'
      JMP  FFFFF 
      
      D1111:
      MOV BYTE PTR [DI+1],'D'
      JMP  FFFFF
     
      E1111:
      MOV BYTE PTR [DI+1],'E'
      JMP  FFFFF
      F1111:
      MOV BYTE PTR [DI+1],'F'
      JMP  FFFFF 
      
      
      
      FFFFF:
    
    
    
    
ENDM FROMDIGITTOASCILL
    

update macro
LOCAL CONTINUEINUPDATE1
LOCAL CONTINUEINUPDATE2
LOCAL CONTINUEINUPDATE3
LOCAL CONTINUEINUPDATE4
LOCAL CONTINUEINUPDATE5
LOCAL CONTINUEINUPDATE6
LOCAL CONTINUEINUPDATE7
LOCAL CONTINUEINUPDATE8
LOCAL WINNERMACROCALL 
LOCAL EXITUPDATE
    pusha
    mov  dl, 3h   ;Column
    mov  dh, 3h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    popa
    mov temp3,al
    mov temp4,ah
    pusha
    FROMDIGITTOASCILL temp3
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+3],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+2],BL
    FROMDIGITTOASCILL temp4
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+0],BL
    popa
    pusha
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    CMP AX,TARGETVALUE
    JNZ CONTINUEINUPDATE1
    JMP WINNERMACROCALL
    
CONTINUEINUPDATE1:    
    pusha
    mov  dl, 3h   ;Column
    mov  dh, 4h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    popa
    mov temp3,bl
    mov temp4,bh
    pusha
    FROMDIGITTOASCILL temp3
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+3],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+2],BL
    FROMDIGITTOASCILL temp4
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+0],BL
    popa
    pusha
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
     CMP BX,TARGETVALUE
    JNZ CONTINUEINUPDATE2
    JMP WINNERMACROCALL
    
CONTINUEINUPDATE2:
    pusha
    mov  dl, 3h   ;Column
    mov  dh, 5h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    popa
    mov temp3,cl
    mov temp4,ch
    pusha
    FROMDIGITTOASCILL temp3
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+3],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+2],BL
    FROMDIGITTOASCILL temp4
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+0],BL
    popa
    pusha
    mov ah,09h
    mov dx, offset temp
    int 21h 
    popa
     CMP CX,TARGETVALUE
    JNZ CONTINUEINUPDATE3
    JMP WINNERMACROCALL
    
CONTINUEINUPDATE3:
    
    pusha
    mov  dl, 3h   ;Column
    mov  dh, 7h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    popa
    mov temp3,dl
    mov temp4,dh
    pusha
    FROMDIGITTOASCILL temp3
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+3],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+2],BL
    FROMDIGITTOASCILL temp4
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+0],BL
    popa
    pusha
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    CMP DX,TARGETVALUE
    JNZ CONTINUEINUPDATE4
    JMP WINNERMACROCALL
    
CONTINUEINUPDATE4:
    
    pusha
    mov  dl, 0Bh   ;Column
    mov  dh, 3h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    popa
    mov tempp,si
    pusha
    mov ax,tempp
    mov temp3,al
    mov temp4,ah
    FROMDIGITTOASCILL temp3
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+3],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+2],BL
    FROMDIGITTOASCILL temp4
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+0],BL
    popa
    pusha
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
     CMP SI,TARGETVALUE
    JNZ CONTINUEINUPDATE5
    JMP WINNERMACROCALL
    
CONTINUEINUPDATE5:
    pusha
    mov  dl, 0Bh   ;Column
    mov  dh, 4h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    popa
    mov tempp,di
    pusha
    mov ax,tempp
    mov temp3,al
    mov temp4,ah
    FROMDIGITTOASCILL temp3
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+3],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+2],BL
    FROMDIGITTOASCILL temp4
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+0],BL
    popa
    pusha
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
     CMP DI,TARGETVALUE
    JNZ CONTINUEINUPDATE6
    JMP WINNERMACROCALL
    
CONTINUEINUPDATE6:
    
    pusha
    mov  dl, 0Bh   ;Column
    mov  dh, 5h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    popa
    pusha
    mov ax,word ptr stackpointerreg
    mov temp3,al
    mov temp4,ah
    FROMDIGITTOASCILL temp3
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+3],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+2],BL
    FROMDIGITTOASCILL temp4
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+0],BL
    popa
    pusha
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
     MOV TEMPUPDATE,AX
     MOV AX,stackpointerreg
     CMP AX,TARGETVALUE 
     MOV AX,TEMPUPDATE
    JNZ CONTINUEINUPDATE7
    JMP WINNERMACROCALL
    
CONTINUEINUPDATE7:
    pusha
    mov  dl, 0Bh   ;Column
    mov  dh, 7h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    popa
    pusha
    mov ax,word ptr BASEpointerreg
    mov temp3,al
    mov temp4,ah
    FROMDIGITTOASCILL temp3
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+3],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+2],BL
    FROMDIGITTOASCILL temp4
    LEA di,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [di+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [di+0],BL
    popa
    pusha
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
   
    MOV TEMPUPDATE,AX
     MOV AX,BASEpointerreg
     CMP AX,TARGETVALUE 
     MOV AX,TEMPUPDATE
    JNZ CONTINUEINUPDATE8
    JMP WINNERMACROCALL
    
CONTINUEINUPDATE8:
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 0h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+0]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 1h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+1]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 3h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+2]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 4h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+3]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 5h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+4]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 7h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+5]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 8h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+6]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 9h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+7]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 0Ah   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+8]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 0Bh   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+9]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 0Dh   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+10]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 0Eh   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+11]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa  
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 0Fh   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+12]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa   
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 11h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+13]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 12h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+14]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa
    
    pusha
    mov  dl, 11h   ;Column
    mov  dh, 13h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,memoryplayer
    mov al,byte ptr [di+15]
    mov temp3,al
    FROMDIGITTOASCILL temp3
    LEA si,temp
    mov bl,byte ptr TWOBYTE+1
    mov byte ptr [si+1],BL
    mov bl,byte ptr TWOBYTE
    mov byte ptr [si+0],BL
    mov byte ptr [si+2],'$'
    mov byte ptr [si+3],'$'
    mov ah,09h
    mov dx, offset temp
    int 21h
    popa 
    JMP EXITUPDATE
    
WINNERMACROCALL:
WINNERMACRO 
EXITUPDATE:
   
Endm update 
    
    
    
    
    