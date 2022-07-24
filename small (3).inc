    
S_to_C Macro commands    ; small to capital
LOCAL loop1
LOCAL convert
LOCAL smallerletter
LOCAL exitMKMK
LOCAL RAMODE
LOCAL RAMBX
LOCAL  RAMSI
LOCAL  register
LOCAL  RAMDI
LOCAL  exit2
LOCAL  regsource
LOCAL  memory
LOCAL  DIGIT1
LOCAL  B1
LOCAL  C1
LOCAL  D1
LOCAL  E1
LOCAL  F1
LOCAL  EXITT55
LOCAL  RAMODES
LOCAL  RAMBXS
LOCAL  RAMSIS
LOCAL  RAMDIS
LOCAL  ERORSS
LOCAL  L5
LOCAL exit4 
LOCAL LETTER1
       
     lea si,commands    
     add si,2
     mov cx,16    
loop1:        
          
    mov al,[si]
    cmp al , 60h
    jnc convert  
    add si,1h
    cmp cx,0h
	jz exitMKMK
    loop loop1  
    jmp exitMKMK
    
    
     
    
 
 convert: 
  
    cmp al, 7bh
    jc smallerletter 
    dec cx 
    cmp cx,0h
    jz exitMKMK
    add si,1
    jmp loop1
 
 
 
 smallerletter: 
   
    sub al,20h  
    dec cx 
    cmp cx,0h
    jz exitMKMK
    mov [si],al
    add si,1
    jmp loop1   
  
exitMKMK:  
;//////////////////////STOP CONVERT HERE//////////////////////////////
     lea si,commands 
     mov al , [si+2]
     add al,[si+3]
     add al,[si+4] 
     mov asciisum ,al
 ;/////////////////////END COMMANDS//////////////////////////////////    
     
     mov bl, byte ptr[si+5]
     cmp bl,28h ; ;///////// MOV(BX,VALUE
     JZ RAMODE
     mov bl, byte ptr[si+6]
        
     cmp bl,5bh     ;[
     jnz register
     ;CMP [SI+7],28H   ; REGISTER ADDRESSING MODE I.E MOV(BX,AX   MOV AX,[2]  mov [2,---   ; MM DB     0 1 2 3  MOV BX,OFF MM  ADD BX,2 BX->2 MOV AX,[BX]  
     ;  JZ RAMODE 
     MOV DESTINATIONSELECTOR,0H     ; MEMORY       
     mov al,[si+7]
     mov asciidestsum,al
     jmp  exit2  
  
RAMODE: 
    MOV DESTINATIONSELECTOR,0H  ; MEAN MEMORY
    MOV AL,[SI+6]
    ADD AL,[SI+7]
    CMP AL,9AH  ; MOV(AX,--   
    JZ RAMBX 
 
    CMP AL,0A6H ; SI -> SS 
    JZ RAMSI 
  
    CMP AL,092H ; DI -> DN 
    JZ RAMDI
 
    JMP ERORSS ;///////////////////////////////////  
  
  
 RAMBX:
 
    POPF
    POPA
    PUSHA
    PUSHF                            ; 
    MOV asciidestsum,Bl 
    jmp  exit2  
 
 RAMSI:
    POPF
    POPA
    PUSHA
    PUSHF
    mov bx ,si     
    MOV asciidestsum,bl
    jmp  exit2
 
 RAMDI:
    POPF
    POPA
    PUSHA
    PUSHF
    mov bx ,di     
    MOV asciidestsum,bl    
    jmp  exit2       
      
register:     
    mov al ,[si+6]
    add al,[si+7] 
    mov asciidestsum ,al  
    MOV DESTINATIONSELECTOR,1H
  
  
exit2: 
  
    LEA SI,commands
    mov bl, byte ptr[si+9]
                    ;NEW
    cmp bl,28h
    jz regsource
    mov bl, byte ptr[si+9]
        ;mov ax , 0001
    cmp bl,5bh
    jz memory
    mov al,[si+9]
    mov  asciidigits,al
    mov al,[si+10] 
    mov  asciidigits+1,al
    mov al,[si+11] 
    mov  asciidigits+2,al
    mov al,[si+12] 
    mov  asciidigits+3,al
    MOV SOURCESELECTOR,1H
    ; mov ax,word ptr  commands+9
    ;mov asciidigits , ax 
    ; mov ax,word ptr  commands+11
    ;mov asciidigits+2,ax
    jmp exit4 
  
  
  
  
regsource:
    mov al ,[si+10]
    mov bl, byte ptr[si+11]
     
    add al,bl
    mov asciisourcesum,al
    MOV SOURCESELECTOR,2H 
    jmp exit4  
    
    
memory:
    mov bl, byte ptr[si+10]
     cmp bl,28h ;
         ;(  
    JZ RAMODES   ;///////////////////////////////////////////////////////
    mov al,[si+10]       ;mov ax,[(bx)]
    lea si,commands
    mov bl, byte ptr[si+10]
     cmp bl,28h ;
    jz EXITT55
     ; //////////////////////////////////////////////////////////////////////////////////////////////////
  
    CMP AL,3AH
    JC DIGIT1
    JMP LETTER1
      
       
DIGIT1:
       SUB AL,30H
       ;  MOV [DI],AL
      
     
       JMP EXITT55
       
       
       LETTER1:
       CMP AL,'A'
       JNZ B1
       MOV AL,0AH
       JMP EXITT55 
       
B1:
       CMP AL,'B'
       JNZ C1
       MOV AL,0BH  
       JMP EXITT55 
        
C1:
       CMP AL,'C'
       JNZ D1
       MOV AL,0CH
       JMP EXITT55 
        
D1:
       CMP AL,'D'
       JNZ E1
       MOV AL,0DH
       JMP EXITT55 
        
E1:
       CMP AL,'E'
       JNZ F1
       MOV AL,0EH 
       JMP  EXITT55 
F1:
       MOV AL,0FH
       JMP  EXITT55 
  
  
  
  
EXITT55:
   
  ;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
     mov memorysource ,al
     MOV SOURCESELECTOR,3H
     jmp exit4
  
 ;////////////////////////// 
  
RAMODES: 
    MOV SOURCESELECTOR,3H  ; MEAN MEMORY
    MOV AL,[SI+11]
    ADD AL,[SI+12]
    CMP AL,9AH  ; MOV AX,[(BX)]   
    JZ RAMBXS 
 
    CMP AL,0A6H ; SI -> SS 
    JZ RAMSIS 
  
    CMP AL,092H ; DI -> DN 
    JZ RAMDIS
 
    JMP ERORSS;///////////////////////////////////  
  
  
RAMBXS:
 
    POPF
    POPA
    PUSHA
    PUSHF     
    MOV memorysource,Bl  
    JMP exit4
 
RAMSIS:
    POPF
    POPA
    PUSHA
    PUSHF 
    mov bx ,si    
    MOV memorysource,bl
    JMP exit4
 
RAMDIS:
    POPF
    POPA
    PUSHA
    PUSHF
    mov bx ,di     
    MOV memorysource,bl
    JMP exit4   
 
 

 ERORSS:
      MOV CX,5
      MOV ERRORFLAG,1H 
    L5:  
    MOV AH,2
    MOV DL,7
    INT 21H 
    LOOP L5 
    MOV ERRORFLAG,01H
	jmp  END78  
    
  
 ;///////////////////////////// 
exit4:  
  
 
  
  
   
ENDM        ; end Small to capital
