
CONV MACRO    ; IT WILL TAKE THE SOURCE AND CONVERT TO VALUE INT MEMORY VAL (VALUE) EX MOV AX,BX  VALUE=BX OP=16BIT      
      LOCAL  A
      LOCAL   B
      LOCAL    C
      LOCAL     D
      LOCAL      E
      LOCAL       F
   CMP SOURCESELECTOR,1H
       JZ VALUE
       
                                     ;1-> VALUE     2-> REGISTER SOURCE  3-> MEMORYSOURCE
       
       CMP SOURCESELECTOR,2H
       JZ REGISTSOURCE999
                                   
       
                                       ; VAR8BIT DB ?
                                        ;VAR16BIT DW ?
       CMP SOURCESELECTOR,3H
       JZ MEMORYSOURCE1999
       
VALUE:
          LEA DI,asciidigits         ; 1A45 -> "1,41,4,5  MOV AL,VAR8BIT  A->41
          MOV CX,4 
LOOP4:      
       MOV AL,[DI]
       CMP AL,3AH
       JC DIGIT
       JMP LETTER
BACK:
       INC DI
       LOOP LOOP4
       JMP EXIT44
       
DIGIT:
       SUB AL,30H
       MOV [DI],AL
       INC DI 
       DEC CX
       JNZ LOOP4
       JMP EXIT44
       
                                  
LETTER:
       CMP BYTE PTR [DI],'A'
       JNZ B
       MOV BYTE PTR [DI],0AH
       JMP BACK 
       
B:
       CMP BYTE PTR [DI],'B'
       JNZ C
       MOV BYTE PTR [DI],0BH  
       JMP BACK 
        
C:
       CMP BYTE PTR [DI],'C'
       JNZ D
       MOV BYTE PTR [DI],0CH
       JMP BACK 
        
D:
       CMP BYTE PTR [DI],'D'
       JNZ E
       MOV BYTE PTR [DI],0DH
       JMP BACK 
        
E:
       CMP BYTE PTR [DI],'E'
       JNZ F
       MOV BYTE PTR [DI],0EH 
       JMP BACK 
F:
       MOV BYTE PTR [DI],0FH
       JMP BACK 
REGISTSOURCE999:
JMP REGISTSOURCE
MEMORYSOURCE1999:
JMP MEMORYSOURCE1
       
EXIT44:
       LEA DI,asciidigits   
       MOV AX,[DI]
       MOV BX ,1000H
       MUL BX
       MOV CX,AX
       
       MOV AX,0000H  
       MOV AX,[DI+1]
       MOV AH,0H
       MOV BX,100H
      
       MUL BX
       ADD CX,AX     
          
       MOV AX,0000H   
       MOV AX,[DI+2]
       MOV AH,0H
       MOV BX,10H
       MUL BX
       ADD CX,AX  
            
       MOV AX,0000H 
       MOV AX,[DI+3] 
       MOV AH,0H
       ADD CX,AX       
       MOV FINALSOURCE,CX        ;VALUE IN FINAL SOURCE 
       CMP CX,0FFH
       JNC  GREATER
      
       
SMALLER:
       MOV SOURCEHIN,8H      ; SOURCE IN 8H IF 8H BIT OPERATION 
       jmp EX
       
       
       
GREATER:
       cmp cx,0ffh
       jz SMALLER
       MOV SOURCEHIN,16H      ; SOURCE IN 16 H  IF 16H BIT OPERATION 
       jmp EX  
        
       
REGISTSOURCE: 
      ; POPA      ; TO GET THE ACTUAL VALUES FROM REGISTERS 
       ;PUSHA
     POPF
     POPA
     PUSHA
     PUSHF     
       LEA DI ,asciisourcesum
      ; MOV BL,BYTE PTR [DI]
       CMP BYTE PTR [DI],99H 
       JZ RAX
       
       CMP BYTE PTR [DI],9AH
       JZ RBX999 
       
       CMP BYTE PTR [DI],9BH
       JZ RCX999
       
       CMP BYTE PTR [DI],9CH
       JZ RDX999 
        
       CMP BYTE PTR [DI],0A3H
       JZ RSP999 
        
       CMP BYTE PTR [DI],84H
       JZ RBB999
       
       CMP BYTE PTR [DI],0A6H
       JZ RSI999 
       
       CMP BYTE PTR [DI],92H
       JZ RDI999  
       
       CMP BYTE PTR [DI],8DH
       JZ RAL999
       
       CMP BYTE PTR [DI],89H
       JZ RAH999
       
       CMP BYTE PTR [DI],8EH
       JZ RBL999   
       
       CMP BYTE PTR [DI],8AH
       JZ RBH999  
       
       CMP BYTE PTR [DI],8FH ; CL:
       JZ RCLL999
       
       CMP BYTE PTR [DI],8BH
       JZ RCH999
       
       CMP BYTE PTR [DI],90H
       JZ RDL999
       
       CMP BYTE PTR [DI],8CH
       JZ  RDH999                                        ;      MACRO FINALSOURCE asciidestsum   asciisum  CHECK 8BIT OPERATION CHECK ->SOURCEHIN 
       
                                                     ;
       JMP ERRORSO                                        ; DEST-> AX    SOURCEIN ->17
RDX999:
JMP RDX                                                     ;
RCX999:
JMP RCX
RBX999:
JMP RBX
        
RAX:
       MOV FINALSOURCE , AX 
       MOV SOURCEHIN,16H
       JMP EX
       
RBX:
       MOV FINALSOURCE , BX 
       MOV SOURCEHIN,16H
       JMP EX
RDH999:
JMP RDH998       
RSI999:
JMP RSI
RDI999:
JMP RDI
RSP999:
JMP RSP
RBB999:
JMP RBB
RAH999:
JMP RAH998
RBL999:
JMP RBL998
RBH999:
JMP RBH998
RCLL999:
JMP RCLL998
RCH999:
JMP RCH998       
RDL999:
JMP RDL998       
RAL999:
JMP RAL998       
RCX:
       MOV FINALSOURCE ,CX 
       MOV SOURCEHIN,16H
       JMP EX
       
RDX:
       MOV FINALSOURCE ,DX 
       MOV SOURCEHIN,16H
       JMP EX
       
RSI:
       MOV FINALSOURCE ,SI 
       MOV SOURCEHIN,16H
       JMP EX
       
RDI:
;POPA
;PUSHA
       MOV FINALSOURCE,DI 
       MOV SOURCEHIN,16H
       JMP EX
       
RSP:    
       MOV AX,stackpointerreg 
       MOV FINALSOURCE , AX 
       MOV SOURCEHIN,16H
       JMP EX 
       
RBB:   
       MOV AX,BASEpointerreg
       MOV FINALSOURCE ,AX 
       MOV SOURCEHIN,16H
       JMP EX

RDH998:
JMP RDH 
RDL998:
JMP RDL       
RAL998:
JMP RAL
RAH998:
JMP RAH
RBL998:
JMP RBL
RBH998:
JMP RBH
RCLL998:
JMP RCLL
RCH998:
JMP RCH

  
     
RAL:  
       mov Ah,0h
       MOV FINALSOURCE ,AX 
       MOV SOURCEHIN,17H 
       JMP EX 
       
RAH:   
       mov Al,Ah
       mov Ah,0h
       MOV FINALSOURCE ,AX 
       MOV SOURCEHIN,17H 
       JMP EX 
       
RBL:   
       mov bh,0h
       MOV FINALSOURCE ,Bx 
       MOV SOURCEHIN,17H 
       JMP EX 
       
RBH:   
       mov bl,bh
       mov bh,0h
       MOV FINALSOURCE ,Bx 
       MOV SOURCEHIN,17H 
       JMP EX 
       
RCLL:   
       mov ch,0h
       MOV FINALSOURCE ,Cx 
       MOV SOURCEHIN,17H 
       JMP EX 
       
RCH:  
       mov cl,ch
       mov ch,0h
       MOV FINALSOURCE ,Cx 
       MOV SOURCEHIN,17H 
       JMP EX 
RDH:
       mov dl,dh
       mov dh,0h
       MOV FINALSOURCE ,Dx 
       MOV SOURCEHIN,17H 
       JMP EX 
       
RDL:   
       mov dh,0h
       MOV FINALSOURCE ,Dx
        
       MOV SOURCEHIN,17H 
       JMP EX 
       
       
MEMORYSOURCE1:
       LEA dI,commands
       mov bl, byte ptr[di+7]
       CMP bl,04ch   ;  MOV AL,[2]
       JZ BITREG8
       mov bl, byte ptr[di+7]
     
       CMP bl,'H'
       JZ BITREG8
       
       LEA DI, MEMORYPLAYER    ; MOV AX,[2]
       MOV Al,memorysource
       ADD DI,AX
       MOV Ah,[DI+1]
       MOV Al,[DI]
       MOV FINALSOURCE,AX
       JMP EX
       
       
BITREG8:
       LEA DI, MEMORYPLAYER  ; 
       MOV Al,memorysource
       ADD DI,AX
       MOV AL,[DI] 
       mov ah,0h
       MOV FINALSOURCE,Ax
       JMP EX
       ;////////////////////////////////////////////////////////
       ;///////////////////////////////////////////////////////
       ;//////////////////////////////////////////////////////                          
ERRORSO: 

      MOV CX,5
      
    L44SH:  
    MOV AH,2
    MOV DL,7
    INT 21H 
    LOOP L44SH  
    MOV ERRORFLAG,1H                  





EX:
     
ENDM CONV