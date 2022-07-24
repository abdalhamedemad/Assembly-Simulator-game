CMOVMACRO MACRO
CMP DESTINATIONSELECTOR,1H
        JZ REGISTERDEST100
        
  CMP DESTINATIONSELECTOR,0H ; MOV [2],(AX)
  JMP  MEMORYDEST      
           
   
  MEMORYDEST:
  
   
  CMP SOURCESELECTOR,3H
  JZ CEROR500            ;memory to memory
   
   ;//////////////////////////  mov(bx,0005
   lea di,commands
   mov al,asciidestsum
  ; MOV BL,[di+5]
   cmp BYTE PTR [DI+5],28h ; register addressing mode  mean we don't need to convert from ascii to degitss
   jz EXITT555  
   CMP AL,3AH
       JC DIGIT11
       JMP LETTER13
      
       
       DIGIT11:
       SUB AL,30H
     ;  MOV [DI],AL
      
     
       JMP EXITT555
       
       
       LETTER13:
       CMP AL,'A'
       JNZ B11
       MOV AL,0AH
       JMP EXITT555 
       
       B11:
       CMP AL,'B'
       JNZ C11
       MOV AL,0BH  
       JMP EXITT555 
        
        C11:
       CMP AL,'C'
       JNZ D11
       MOV AL,0CH
       JMP EXITT555 
        
         D11:
       CMP AL,'D'
       JNZ E11
       MOV AL,0DH
       JMP EXITT555 
        
         E11:
       CMP AL,'E'
       JNZ F11
       MOV AL,0EH 
         JMP  EXITT555 
          F11:
       MOV AL,0FH
       JMP  EXITT555 


REGISTERDEST100:
JMP REGISTERDEST  
CEROR500:
JMP CEROR  
  
  
EXITT555:
    mov asciidestsum,al
      ;//////////////////////////////
  
  ; LEA SI,asciisum
   ;CMP [SI],0EEH
    ; JZ MULFMM8
  ;CMP [SI],0E3H
  ;   JZ DIVFMM8
 ;CMP [SI],0CCH
   ;  JZ DECFMM8
     
    ;  CMP [SI],0DAH
     ;JZ INCFMM8
  
  
  
  
  CMP SOURCEHIN,8H    ; 8-> VALUE 8 BIT  16-> VLAUE 16 REG OR 16 BIT VALUE  17-> 8 BIT REG
  JZ BITMEMORY8100  
  
  
  CMP SOURCEHIN,17H 
  JZ BITMEMORY8100  
  
     LEA DI, MEMORYPLAYER
	 MOV AH,0H
	 
     MOV  AL, asciidestsum
	mov ah,00h
   ;////////////////////////////////////////////
   
   
   ;/////////////////////////////////////////////  
     ADD DI,AX
     MOV BX,FINALSOURCE

;//////////////////////////////////////////////////
  LEA SI,asciisum
      ;MOV BL ,[SI]
     cmp  BYTE PTR [SI],0C9H
     JZ ADDfMM
     
     CMP  BYTE PTR [SI],0C8H
     JZ ADCfMM   
     
      CMP  BYTE PTR [SI],0EAH
     JZ SUBfMM
     
      CMP  BYTE PTR [SI],0D7H
     JZ SUBBfMM
	  CMP  BYTE PTR [SI],0F2H
     JZ MOVfMM
   CMP  BYTE PTR [SI],0F9H
     JZ XORFMM
     
      CMP  BYTE PTR [SI],0D3H
     JZ ANDFMM
 CMP BYTE PTR [SI],0D3H
     JZ ORRFMM

 ;CMP [SI],0EEH
  ;   JZ MULFMM
  ;CMP [SI],0E3H
   ;  JZ DIVFMM
  ;CMP [SI],0CCH
   ;  JZ DECFMM
     
    ;  CMP [SI],0DAH
    ; JZ INCFMM  
    JMP CEROR
BITMEMORY8100:
JMP BITMEMORY8    	
MOVfMM:
	; POPA
        
     MOV [DI+1],BH
     MOV [DI],BL 
         ;PUSHA
         JMP CEX
;MULFMM:
;	 POPA
;	 popf
 ;        MUL AX
;	 pushf         
;	 PUSHA
 ;        JMP CEX
;DIVFMM:
;	 POPA
;	 popf
 ;        DIV AX
;	 pushf         
;	 PUSHA
 ;        JMP CEX
;DECFMM:
;	 POPA
;	 popf
 ;        DEC AX
;	 pushf         
;	 PUSHA
 ;        JMP CEX
;INCFMM:
;	 POPA
;	 popf
 ;        INC AX
;	 pushf         
;	 PUSHA
 ;        JMP CEX

ADDfMM:
	 POPF
;	 popA
      ADD [DI],BL ;you need a buff   
     ADD [DI+1],BH
    
;	 pushA         
	 PUSHF
         JMP CEX
ADCfMM:
	
	 POPF
	 ;popA
      ADC [DI],BL  
     ADC [DI+1],BH
    
	; PUSHA 
         PUSHF
         JMP CEX
SUBfMM:
	
	 POPF
;	 popA
       SUB [DI],BL  
     SUB [DI+1],BH
    
 	; PUSHA 
         PUSHF
         JMP CEX

SUBBfMM:
	
	 POPF
;	 popA
      SBB [DI],BL   
     SBB [DI+1],BH
     
 ;	 PUSHA 
         PUSHF
         JMP CEX
XORFMM:
 	 POPF
;	 popA
      XOR [DI],BL    
     XOR [DI+1],BH
    
 ;	 PUSHA 
         PUSHF
         JMP CEX
ANDFMM:
         POPF
;	 popA
       AND [DI],BL  
     AND [DI+1],BH
    
 ;	 PUSHA 
        PUSHF
         JMP CEX
ORRFMM:
         POPF
;	 popA
      OR [DI],BL    
     OR [DI+1],BH
    
 ;	 PUSHA 
         PUSHF
         JMP CEX

;     MOV [DI],BH
;     MOV [DI+1],BL

	JMP CEX 


     
   
  
BITMEMORY8:
     MOV AH,0H
     MOV  AL, asciidestsum
     LEA DI ,MEMORYPLAYER 
  
     ADD DI,AX
     MOV AX,FINALSOURCE
;//////////////////////////////////////////////////////
  LEA SI,asciisum
     MOV BL ,[SI]
     cmp BL,0C9H
     JZ ADDfMM8
     
     CMP BL,0C8H
     JZ ADCfMM8   
     
      CMP BL,0EAH
     JZ SUBfMM8
     
      CMP BL,0D7H
     JZ SUBBfMM8
	  CMP BL,0F2H
     JZ MOVfMM8
   CMP BL,0F9H
     JZ XORFMM8
     
      CMP BL,0D3H
     JZ ANDFMM8
 CMP BL,0D3H
     JZ ORRFMM8

 CMP BYTE PTR [SI],0EEH
     JZ MULFMM8
  CMP BYTE PTR [SI],0E3H
     JZ DIVFMM8
 CMP BYTE PTR [SI],0CCH
     JZ DECFMM8
     
      CMP BYTE PTR [SI],0DAH
     JZ INCFMM8
    	
MOVfMM8:
	; POPA
        
     MOV [DI],AX
         ;PUSHA
         JMP CEX
MULFMM8:
	 POPf
	 ;popa
         MUL byte Ptr [di]
	 ;pusha         
	 PUSHf
         JMP CEX
DIVFMM8:
	 POPF
	 ;popA
         DIV BYTE PTR [DI]
	 ;pushA         
	 PUSHF
        JMP CEX
DECFMM8:
	 POPF
	 ;popA
         DEC  BYTE PTR [DI] 
	 ;pushA         
	 PUSHF
         JMP CEX
INCFMM8:
	 POPF
	 ;popA
         INC  BYTE PTR [DI]
	 ;pushA         
	 PUSHF
         JMP CEX

ADDfMM8:
	 POPF
;	 popA
       
     ADD [DI],AX
;	 pushA        
	 PUSHF
         JMP CEX
ADCfMM8:
	
	 POPF
;	 popA
       
    ADC [DI],AX
;	 PUSHA 
         PUSHF
         JMP CEX
SUBfMM8:
	
	 POPF
;	 popA
        
     SUB [DI],AX
; 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfMM8:
	
	 POPF
;	 popA
         
    SBB [DI],AX
 ;	 PUSHA 
         PUSHF
         JMP CEX
XORFMM8:
 	 POPF
;	 popA
         
      XOR [DI],AX
 ;	 PUSHA 
         PUSHF
         JMP CEX
ANDFMM8:
         POPF
;	 popA
        
     OR [DI],AX
 ;	 PUSHA 
         PUSHF
         JMP CEX
ORRFMM8:
         POPF
;	 popA
         
      OR [DI],AX
    
 ;	 PUSHA 
         PUSHF
         JMP CEX




     ;MOV [DI],AX
	;JMP CEX 
  
;///////////////////
   
   
    
REGISTERDEST:  
   POPA
   PUSHA
   LEA DI ,asciidestsum
        MOV BL ,[DI]
       CMP BL,99H 
       JZ RAXD
       
       CMP BL,9AH
       JZ RBXD84 
       
       CMP BL,9BH
       JZ RCXD84
       
       CMP BL,9CH
       JZ RDXD84 
        
       CMP BL,0A3H
       JZ RSPD84 
        
       CMP BL,84H
       JZ RBBD84
       
       CMP BL,0A6H
       JZ RSID84 
       
       CMP BL,92H
       JZ RDID84  
       
       CMP BL,8DH
       JZ RALD84
       
       CMP BL,89H
       JZ RAHD84
       
       CMP BL,8EH
       JZ RBLD84   
       
       CMP BL,8AH
       JZ RBHD84  
       
       CMP BL,8FH
       JZ RCLLD84
       
       CMP BL,8BH
       JZ RCHD84
       
       CMP BL,90H
       JZ RDLD84
       
       CMP BL,8CH
       JZ RDHD84 
   
       
       JMP CEROR
       
       
    
       
                                                
RBXD84:
JMP RBXD
RCXD84:
JMP RCXD83
RDXD84:
JMP RDXD83
RSPD84:
JMP RSPD83
RBBD84:
JMP RBBD83
RSID84:
JMP RSID83
RDID84:
JMP RDID83
RALD84:
JMP RALD83
RAHD84:
JMP RAHD83
RBLD84:
JMP RBLD83
RBHD84:
JMP RBHD83
RCLLD84:
JMP RCLLD83
RCHD84:
JMP RCHD83
RDLD84:
JMP RDLD83
RDHD84:
JMP RDHD83 
        
RAXD:
         LEA DI,asciisum
         MOV BL ,[DI]
	CMP BL,0EEH
     JZ MULFAX
  CMP BL,0E3H
     JZ DIVFAX
  CMP BL,0CCH
     JZ DECFAX
     
      CMP BL,0DAH
     JZ INCFAX


         CMP SOURCEHIN,17H  ;TO MAKE SURE TAHT NOT AH OR BH I.E SIZE MISMATCH
         JZ  CEROR85              ; NOT EQUAL  ; YOU MUST MAKE MESSAGE SHOW ERROR SIZE MISHMATCH
         
 

	  LEA DI,asciisum
      MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfAX
     
     CMP BL,0C8H
     JZ ADCfAX   
     
      CMP BL,0EAH
     JZ SUBfAX
     
      CMP BL,0D7H
     JZ SUBBfAX
	  CMP BL,0F2H
     JZ MOVfAX
   CMP BL,0F9H
     JZ XORFAX
     
      CMP BL,0D3H
     JZ ANDFAX
 CMP BL,0D3H
     JZ ORRFAX


    	
MOVfAX:
	 POPF
	 POPA
         MOV AX,FINALSOURCE 
         PUSHA
	 PUSHF
         JMP CEX
MULFAX:
	 POPF
	 popA
         MUL AX
	 pushA         
	 PUSHF
         JMP CEX
DIVFAX:
	 POPF
	 popA
         DIV AX
	 pushA         
	 PUSHF
         JMP CEX
DECFAX:
	 POPF
	 popA
         DEC AX
	 pushA         
	 PUSHF
         JMP CEX
INCFAX:
	 POPF
	 popA
         INC AX
	 pushA         
	 PUSHF
         JMP CEX
CEROR85:
JMP CEROR
ADDfAX:
	 POPF
	 popA
         ADD AX,FINALSOURCE 
	 pushA         
	 PUSHF
         JMP CEX
        
ADCfAX:
	
	 POPF
	 popA
         ADC AX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfAX:
	
	 POPF
	 popA
         SUB AX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfAX:
	
	 POPF
	 popA
         SBB AX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
XORFAX:
 	 POPF
	 popA
         XOR AX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFAX:
         POPF
	 popA
         AND AX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFAX:
         POPF
	 popA
         OR AX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

RCXD83:
JMP RCXD
RDXD83:
JMP RDXD82
RSPD83:
JMP RSPD82
RBBD83:
JMP RBBD82
RSID83:
JMP RSID82
RDID83:
JMP RDID82
RALD83:
JMP RALD82
RAHD83:
JMP RAHD82
RBLD83:
JMP RBLD82
RBHD83:
JMP RBHD82
RCLLD83:
JMP RCLLD82
RCHD83:
JMP RCHD82
RDLD83:
JMP RDLD82
RDHD83:
JMP RDHD82
        
RBXD: ;///////// BX 
	LEA DI,asciisum
	MOV BL ,[DI]
 CMP BL,0EEH
     JZ MULFBX
  CMP BL,0E3H
     JZ DIVFBX
  CMP BL,0CCH
     JZ DECFBX
     
      CMP BL,0DAH
     JZ INCFBX

         CMP SOURCEHIN,17H
         JZ  CEROR86 
          LEA DI,asciisum
            MOV BL ,[DI]
     cmp  BL,0C9H
     JZ ADDfBX
     
     CMP  BL,0C8H
     JZ ADCfBX   
     
      CMP  BL,0EAH
     JZ SUBfBX
     
      CMP  BL,0D7H
     JZ SUBBfBX
	  CMP  BL,0F2H
     JZ MOVfBX
   CMP  BL,0F9H
     JZ XORFBX
     
      CMP  BL,0D3H
     JZ ANDFBX
 CMP BL,0D3H
     JZ ORRFBX


    	
MOVfBX:
	 POPF
	 POPA
         MOV BX,FINALSOURCE 
         PUSHA
	 PUSHF
         JMP CEX
MULFBX:
	 POPF
	 popA
         MUL BX
	 pushA         
	 PUSHF
         JMP CEX
DIVFBX:
	 POPF
	 popA
         DIV BX
	 pushA         
	 PUSHF
         JMP CEX
DECFBX:
	 POPF
	 popA
         DEC BX
	 pushA         
	 PUSHF
         JMP CEX
INCFBX:
	 POPF
	 popA
         INC BX
	 pushA         
	 PUSHF
         JMP CEX




CEROR86:
JMP CEROR
ADDfBX:
	 POPF
	 popA
         ADD BX,FINALSOURCE 
	 pushA         
	 PUSHF
         JMP CEX
ADCfBX:
	
	 POPF
	 popA
         ADC BX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfBX:
	
	 POPF
	 popA
         SUB BX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfBX:
	
	 POPF
	 popA
         SBB BX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
XORFBX:
 	 POPF
	 popA
         XOR BX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFBX:
         POPF
	 popA
         AND BX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFBX:
         POPF
	 popA
         OR BX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

       
       
RDXD82:
JMP RDXD
RSPD82:
JMP RSPD81
RBBD82:
JMP RBBD81
RSID82:
JMP RSID81
RDID82:
JMP RDID81
RALD82:
JMP RALD81
RAHD82:
JMP RAHD81
RBLD82:
JMP RBLD81
RBHD82:
JMP RBHD81
RCLLD82:
JMP RCLLD81
RCHD82:
JMP RCHD81
RDLD82:
JMP RDLD81
RDHD82:
JMP RDHD81
       
RCXD:
 LEA DI,asciisum
 
 MOV BL ,[DI]
CMP BL,0EEH
     JZ MULFCX
  CMP BL,0E3H
     JZ DIVFCX
  CMP BL,0CCH
     JZ DECFCX
     
      CMP BL,0DAH
     JZ INCFCX

         CMP SOURCEHIN,17H
         JZ  CEROR87
        LEA DI,asciisum
        MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfCX
     
     CMP BL,0C8H
     JZ ADCfCX   
     
      CMP BL,0EAH
     JZ SUBfCX
     
      CMP BL,0D7H
     JZ SUBBfCX
	  CMP BL,0F2H
     JZ MOVfCX
   CMP BL,0F9H
     JZ XORFCX
     
      CMP BL,0D3H
     JZ ANDFCX
 CMP BL,0D3H
     JZ ORRFCX

 
    	
MOVfCX:
	 POPF
	 POPA
         MOV CX,FINALSOURCE 
         PUSHA
	 PUSHF
         JMP CEX

MULFCX:
	 POPF
	 popA
         MUL CX
	 pushA         
	 PUSHF
         JMP CEX
DIVFCX:
	 POPF
	 popA
         DIV CX
	 pushA         
	 PUSHF
         JMP CEX
DECFCX:
	 POPF
	 popA
         DEC CX
	 pushA         
	 PUSHF
         JMP CEX
INCFCX:
	 POPF
	 popA
         INC CX
	 pushA         
	 PUSHF
         JMP CEX

CEROR87:
JMP CEROR
ADDfCX:
	 POPF
	 popA
         ADD CX,FINALSOURCE 
	 pushA         
	 PUSHF
         JMP CEX
ADCfCX:
	
	 POPF
	 popA
         ADC CX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfCX:
	
	 POPF
	 popA
         SUB CX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfCX:
	
	 POPF
	 popA
         SBB CX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
XORFCX:
 	 POPF
	 popA
         XOR CX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFCX:
         POPF
	 popA
         AND CX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFCX:
         POPF
	 popA
         OR CX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX


RSID81:
JMP RSID
RDID81:
JMP RDID80
RSPD81:
JMP RSPD80
RBBD81:
JMP RBBD80
RALD81:
JMP RALD80
RAHD81:
JMP RAHD80
RBLD81:
JMP RBLD80
RBHD81:
JMP RBHD80
RCLLD81:
JMP RCLLD80
RCHD81:
JMP RCHD80
RDHD81:
JMP RDHD80
RDLD81:
JMP RDLD80

       
RDXD:
LEA DI,asciisum
MOV BL ,[DI]
CMP BL,0EEH
     JZ MULFDX
  CMP BL,0E3H
     JZ DIVFDX
  CMP BL,0CCH
     JZ DECFDX
     
      CMP BL,0DAH
     JZ INCFDX
         CMP SOURCEHIN,17H
         JZ  CEROR88
  LEA DI,asciisum
     MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfDX
     
     CMP BL,0C8H
     JZ ADCfDX   
     
      CMP BL,0EAH
     JZ SUBfDX
     
      CMP BL,0D7H
     JZ SUBBfDX
	  CMP BL,0F2H
     JZ MOVfDX
   CMP BL,0F9H
     JZ XORFDX
     
      CMP BL,0D3H
     JZ ANDFDX
 CMP BL,0D3H
     JZ ORRFDX

 
    	
MOVfDX:
	 POPF
	 POPA
         MOV DX,FINALSOURCE 
         PUSHA
	 PUSHF
         JMP CEX

MULFDX:
	 POPF
	 popA
         MUL DX
	 pushA         
	 PUSHF
         JMP CEX
DIVFDX:
	 POPF
	 popA
         DIV DX
	 pushA         
	 PUSHF
         JMP CEX
DECFDX:
	 POPF
	 popA
         DEC DX
	 pushA         
	 PUSHF
         JMP CEX
INCFDX:
	 POPF
	 popA
         INC DX
	 pushA         
	 PUSHF
         JMP CEX

CEROR88:
JMP CEROR
ADDfDX:
	 POPF
	 popA
         ADD DX,FINALSOURCE 
	 pushA         
	 PUSHF
         JMP CEX
ADCfDX:
	
	 POPF
	 popA
         ADC DX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfDX:
	
	 POPF
	 popA
         SUB DX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfDX:
	
	 POPF
	 popA
         SBB DX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
XORFDX:
 	 POPF
	 popA
         XOR DX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFDX:
         POPF
	 popA
         AND DX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFDX:
         POPF
	 popA
         OR DX,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

RDID80:
JMP RDID
RSPD80:
JMP RSPD79
RBBD80:
JMP RBBD79
RALD80:
JMP RALD79
RAHD80:
JMP RAHD79
RBLD80:
JMP RBLD79
RBHD80:
JMP RBHD79
RCLLD80:
JMP RCLLD79
RCHD80:
JMP RCHD79
RDHD80:
JMP RDHD79
RDLD80:
JMP RDLD79

RSID:
LEA DI,asciisum
MOV BL ,[DI]
 CMP BL,0EEH
     JZ MULFSI
  CMP BL,0E3H
     JZ DIVFSI
  CMP BL,0CCH
     JZ DECFSI
     
      CMP BL,0DAH
     JZ INCFSI

         CMP SOURCEHIN,17H
         JZ  CEROR89
           LEA DI,asciisum
     MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfSI
     
     CMP BL,0C8H
     JZ ADCfSI   
     
      CMP BL,0EAH
     JZ SUBfSI
     
      CMP BL,0D7H
     JZ SUBBfSI
	  CMP BL,0F2H
     JZ MOVfSI
   CMP BL,0F9H
     JZ XORFSI
     
      CMP BL,0D3H
     JZ ANDFSI
 CMP BL,0D3H
     JZ ORRFSI


    	
MOVfSI:
	 POPF
	 POPA
         MOV SI,FINALSOURCE 
         PUSHA
	 PUSHF
         JMP CEX
MULFSI:
	 POPF
	 popA
         MUL SI
	 pushA         
	 PUSHF
         JMP CEX
DIVFSI:
	 POPF
	 popA
         DIV SI
	 pushA         
	 PUSHF
         JMP CEX
DECFSI:
	 POPF
	 popA
         DEC SI
	 pushA         
	 PUSHF
         JMP CEX
INCFSI:
	 POPF
	 popA
         INC SI
	 pushA         
	 PUSHF
         JMP CEX

CEROR89:
JMP CEROR
ADDfSI:
	 POPF
	 popA
         ADD SI,FINALSOURCE 
	 pushA         
	 PUSHF
         JMP CEX
ADCfSI:
	
	 POPF
	 popA
         ADC SI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfSI:
	
	 POPF
	 popA
         SUB SI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfSI:
	
	 POPF
	 popA
         SBB SI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
XORFSI:
 	 POPF
	 popA
         XOR SI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFSI:
         POPF
	 popA
         AND SI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFSI:
         POPF
	 popA
         OR SI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

RSPD79:
JMP RSPD
RBBD79:
JMP RBBD78
RALD79:
JMP RALD78
RAHD79:
JMP RAHD78
RBLD79:
JMP RBLD78
RBHD79:
JMP RBHD78
RCLLD79:
JMP RCLLD78
RCHD79:
JMP RCHD78
RDHD79:
JMP RDHD78
RDLD79:
JMP RDLD78

RDID:
;         CMP SOURCEHIN,17H ; MOV AX,AH     MOV AX,88H     
 ;        JZ  CEROR
;         POPA
 ;        MOV DI,FINALSOURCE
  ;       PUSHA 
   ;      JMP CEX
LEA SI,asciisum
MOV BL ,[SI]
CMP BL,0EEH
     JZ MULFDI
  CMP BL,0E3H
     JZ DIVFDI
  CMP BL,0CCH
     JZ DECFDI
     
      CMP BL,0DAH
     JZ INCFDI
         CMP SOURCEHIN,17H
         JZ  CEROR90
  LEA SI,asciisum
      MOV BL ,[SI]
     cmp  BL,0C9H
     JZ ADDfDI
     
     CMP  BL,0C8H
     JZ ADCfDI   
     
      CMP  BL,0EAH
     JZ SUBfDI
     
      CMP  BL,0D7H
     JZ SUBBfDI
	  CMP  BL,0F2H
     JZ MOVfDI
   CMP  BL,0F9H
     JZ XORFDI
     
      CMP  BL,0D3H
     JZ ANDFDI
 CMP BL,0D3H
     JZ ORRFDI

 
    	
MOVfDI:
	 POPF
	 POPA
         MOV DI,FINALSOURCE 
         PUSHA
	 PUSHF
         JMP CEX

MULFDI:
	 POPF
	 popA
         MUL DI
	 pushA         
	 PUSHF
         JMP CEX
DIVFDI:
	 POPF
	 popA
         DIV DI
	 pushA         
	 PUSHF
         JMP CEX
DECFDI:
	 POPF
	 popA
         DEC DI
	 pushA         
	 PUSHF
         JMP CEX
INCFDI:
	 POPF
	 popA
         INC DI
	 pushA         
	 PUSHF
         JMP CEX


ADDfDI:
	 POPF
	 popA
         ADD DI,FINALSOURCE 
	 pushA         
	 PUSHF
         JMP CEX
CEROR90:
JMP CEROR         
ADCfDI:
	
	 POPF
	 popA
         ADC DI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfDI:
	
	 POPF
	 popA
         SUB DI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfDI:
	
	 POPF
	 popA
         SBB DI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
XORFDI:
 	 POPF
	 popA
         XOR DI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFDI:
         POPF
	 popA
         AND DI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFDI:
         POPF
	 popA
         OR DI,FINALSOURCE
 	 PUSHA 
         PUSHF
         JMP CEX



RBBD78:
JMP RBBD
RALD78:
JMP RALD77
RAHD78:
JMP RAHD77
RBLD78:
JMP RBLD77
RBHD78:
JMP RBHD77
RCLLD78:
JMP RCLLD77
RCHD78:
JMP RCHD77
RDHD78:
JMP RDHD77
RDLD78:
JMP RDLD77
      
RSPD:
LEA DI,asciisum
MOV BL ,[DI]
CMP BL,0EEH
     JZ MULFSP
  CMP BL,0E3H
     JZ DIVFSP
  CMP BL,0CCH
     JZ DECFSP
     
      CMP BL,0DAH
     JZ INCFSP
         CMP SOURCEHIN,17H
         JZ  CEROR91
  LEA DI,asciisum
     MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfSP
     
     CMP BL,0C8H
     JZ ADCfSP99K   
     
      CMP BL,0EAH
     JZ SUBfSP99K
     
      CMP BL,0D7H
     JZ SUBBfSP99K
	  CMP BL,0F2H
     JZ MOVfSP
   CMP BL,0F9H
     JZ XORFSP99K
     
      CMP BL,0D3H
     JZ ANDFSP99K
 CMP BL,0D3H
     JZ ORRFSP99K

 
    	
MOVfSP:
	 POPF
	 POPA
	 MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     MOV stackpointerreg,AX
     MOV AX,TEMPSPANDBP
          
         PUSHA
	 PUSHF
         JMP CEX

MULFSP:
	 POPF
	 popA
         MUL stackpointerreg
	 pushA         
	 PUSHF
         JMP CEX
DIVFSP:
	 POPF
	 popA
         DIV stackpointerreg
	 pushA         
	 PUSHF
         JMP CEX
DECFSP:
	 POPF
	 popA
         DEC stackpointerreg
	 pushA         
	 PUSHF
         JMP CEX
INCFSP:
	 POPF
	 popA
         INC stackpointerreg
	 pushA         
	 PUSHF
         JMP CEX
SUBfSP99K:
JMP SUBfSP
SUBBfSP99K:
JMP SUBBfSP
XORFSP99K:
JMP XORFSP
ANDFSP99K:
JMP ANDFSP
ORRFSP99K:
JMP ORRFSP
ADCfSP99K:
JMP ADCfSP
CEROR91:
JMP CEROR
ADDfSP:
	 POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     ADD stackpointerreg,AX
     MOV AX,TEMPSPANDBP 
	 pushA         
	 PUSHF
         JMP CEX
ADCfSP:
	
	 POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     ADC stackpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF

         JMP CEX
        
SUBfSP:
	
	 POPF
	 popA
        MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     SUB stackpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfSP:
	
	 POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     SBB stackpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX
XORFSP:
 	 POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     XOR stackpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFSP:
         POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     AND stackpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFSP:
         POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     OR stackpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX


RALD77:
JMP RALD
RAHD77:
JMP RAHD76
RBLD77:
JMP RBLD76
RBHD77:
JMP RBHD76
RCLLD77:
JMP RCLLD76
RCHD77:
JMP RCHD76
RDHD77:
JMP RDHD76
RDLD77:
JMP RDLD76
       
RBBD:
LEA DI,asciisum
MOV BL ,[DI]
 CMP BL,0EEH
     JZ MULFBP
  CMP BL,0E3H
     JZ DIVFBP
  CMP BL,0CCH
     JZ DECFBP
     
      CMP BL,0DAH
     JZ INCFBP


         CMP SOURCEHIN,17H
         JZ  CEROR92
          LEA DI,asciisum
          MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfBP
     
     CMP BL,0C8H
     JZ ADCfBP99K   
     
      CMP BL,0EAH
     JZ SUBfBP99K
     
      CMP BL,0D7H
     JZ SUBBfBP99K
	  CMP BL,0F2H
     JZ MOVfBP
   CMP BL,0F9H
     JZ XORFBP99K
     
      CMP BL,0D3H
     JZ ANDFBP99K
 CMP BL,0D3H
     JZ ORRFBP99K

    	
MOVfBP:
	 POPF
	 POPA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     MOV BASEpointerreg,AX
     MOV AX,TEMPSPANDBP 
         PUSHA
	 PUSHF
         JMP CEX
MULFBP:
	 POPF
	 popA
         MUL BASEpointerreg
	 pushA         
	 PUSHF
         JMP CEX 
ADCfBP99K:
JMP ADCfBP         
DIVFBP:
	 POPF
	 popA
         DIV BASEpointerreg
	 pushA         
	 PUSHF
         JMP CEX
DECFBP:
	 POPF
	 popA
         DEC BASEpointerreg
	 pushA         
	 PUSHF
         JMP CEX
INCFBP:
	 POPF
	 popA
         INC BASEpointerreg
	 pushA         
	 PUSHF
         JMP CEX

CEROR92:
JMP CEROR
ANDFBP99K:
JMP ANDFBP
SUBfBP99K:
JMP SUBfBP
SUBBfBP99K:
JMP SUBBfBP
XORFBP99K:
JMP XORFBP
ORRFBP99K:
JMP ORRFBP
ADDfBP:
	 POPF
	 popA
        MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     ADD BASEpointerreg,AX
     MOV AX,TEMPSPANDBP 
	 pushA         
	 PUSHF
         JMP CEX
ADCfBP:
	
	 POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     ADC BASEpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX 
         
SUBfBP:
	
	 POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     SUB BASEpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfBP:
	
	 POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     SBB BASEpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX
XORFBP:
 	 POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     XOR BASEpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFBP:
         POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     AND BASEpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFBP:
         POPF
	 popA
         MOV TEMPSPANDBP,AX
	 MOV AX , FINALSOURCE 
     OR BASEpointerreg,AX
     MOV AX,TEMPSPANDBP
 	 PUSHA 
         PUSHF
         JMP CEX



RAHD76:
JMP RAHD
RBLD76:
JMP RBLD75
RBHD76:
JMP RBHD75
RCLLD76:
JMP RCLLD75
RCHD76:
JMP RCHD75
RDHD76:
JMP RDHD75
RDLD76:
JMP RDLD75
       
RALD: 
          LEA DI,asciisum
          MOV BL ,[DI]
 CMP BL,0EEH
     JZ MULFAL
  CMP BL,0E3H
     JZ DIVFAL
  CMP BL,0CCH
     JZ DECFAL
     
      CMP BL,0DAH
     JZ INCFAL

         CMP SOURCEHIN,16H
         JZ  CEROR93
          LEA DI,asciisum
            MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfAL
     
     CMP BL,0C8H
     JZ ADCfAL  
     
      CMP BL,0EAH
     JZ SUBfAL
     
      CMP BL,0D7H
     JZ SUBBfAL93
	  CMP BL,0F2H
     JZ MOVfAL
   CMP BL,0F9H
     JZ XORFAL93
     
      CMP BL,0D3H
     JZ ANDFAL93
 CMP BL,0D3H
     JZ ORRFAL93

    	
MOVfAL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 POPA
         MOV AL,BUFF 
         PUSHA
	 PUSHF
         JMP CEX
MULFAL:
	 POPF
	 popA
         MUL AL
	 pushA         
	 PUSHF
         JMP CEX
DIVFAL:
	 POPF
	 popA
         DIV AL
	 pushA         
	 PUSHF
         JMP CEX
DECFAL:
	 POPF
	 popA
         DEC AL
	 pushA         
	 PUSHF
         JMP CEX
INCFAL:
	 POPF
	 popA
         INC AL
	 pushA         
	 PUSHF
         JMP CEX

CEROR93:
JMP CEROR
SUBBfAL93:
JMP SUBBfAL
XORFAL93:
JMP XORFAL
ANDFAL93:
JMP ANDFAL
ORRFAL93:
JMP ORRFAL

ADDfAL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADD AL,BUFF 
	 pushA         
	 PUSHF
         JMP CEX
ADCfAL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	
	 POPF
	 popA
         ADC AL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfAL:
        MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	
	 POPF
	 popA
         SUB AL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfAL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SBB AL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
XORFAL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
 	 POPF
	 popA
         XOR AL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFAL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         AND AL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFAL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         OR AL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

RBLD75:
JMP RBLD
RBHD75:
JMP RBHD74
RCLLD75:
JMP RCLLD74
RCHD75:
JMP RCHD74
RDHD75:
JMP RDHD74
RDLD75:
JMP RDLD74

       
RAHD: 
 LEA DI,asciisum
 MOV BL ,[DI]
CMP BL,0EEH
     JZ MULFAH
  CMP BL,0E3H
     JZ DIVFAH
  CMP BL,0CCH
     JZ DECFAH
     
      CMP BL,0DAH
     JZ INCFAH

         CMP SOURCEHIN,16H
         JZ  CEROR94
         LEA DI,asciisum
         MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfAH
     
     CMP BL,0C8H
     JZ ADCfAH   
     
      CMP BL,0EAH
     JZ SUBfAH
     
      CMP BL,0D7H
     JZ SUBBfAH94
	  CMP BL,0F2H
     JZ MOVfAH
   CMP BL,0F9H
     JZ XORFAH94
     
      CMP BL,0D3H
     JZ ANDFAH94
 CMP BL,0D3H
     JZ ORRFAH94

 
    	
MOVfAH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 POPA
         MOV AH,BUFF 
         PUSHA
	 PUSHF
         JMP CEX
MULFAH:
	 POPF
	 popA
         MUL AH
	 pushA         
	 PUSHF
         JMP CEX
DIVFAH:
	 POPF
	 popA
         DIV AH
	 pushA         
	 PUSHF
         JMP CEX
DECFAH:
	 POPF
	 popA
         DEC AH
	 pushA         
	 PUSHF
         JMP CEX
INCFAH:
	 POPF
	 popA
         INC AH
	 pushA         
	 PUSHF
         JMP CEX

CEROR94:
JMP CEROR
SUBBfAH94:
JMP SUBBfAH
XORFAH94:
JMP XORFAH
ANDFAH94:
JMP ANDFAH
ORRFAH94:
JMP ORRFAH

ADDfAH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADD AH,BUFF 
	 pushA         
	 PUSHF
         JMP CEX
ADCfAH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADC AH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfAH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SUB AH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfAH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SBB AH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
XORFAH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
 	 POPF
	 popA
         XOR AH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFAH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         AND AH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFAH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         OR AH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

RBHD74:
JMP RBHD
RCLLD74:
JMP RCLLD73
RCHD74:
JMP RCHD73
RDHD74:
JMP RDHD73
RDLD74:
JMP RDLD73
       
RBLD:
LEA DI,asciisum
MOV BL ,[DI]
 CMP  BL,0EEH
     JZ MULFBL
  CMP  BL,0E3H
     JZ DIVFBL
  CMP  BL,0CCH
     JZ DECFBL
     
      CMP BL,0DAH
     JZ INCFBL

         CMP SOURCEHIN,16H
         JZ  CEROR95
  LEA DI,asciisum
      MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfBL
     
     CMP BL,0C8H
     JZ ADCfBL   
     
      CMP BL,0EAH
     JZ SUBfBL
     
      CMP BL,0D7H
     JZ SUBBfBL95
	  CMP BL,0F2H
     JZ MOVfBL
   CMP BL,0F9H
     JZ XORFBL95
     
      CMP BL,0D3H
     JZ ANDFBL95
 CMP BL,0D3H
     JZ ORRFBL95


    	
MOVfBL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 POPA
         MOV BL,BUFF 
         PUSHA
	 PUSHF
         JMP CEX
MULFBL:
	 POPF
	 popA
         MUL BL
	 pushA         
	 PUSHF
         JMP CEX
DIVFBL:
	 POPF
	 popA
         DIV BL
	 pushA         
	 PUSHF
         JMP CEX
DECFBL:
	 POPF
	 popA
         DEC BL
	 pushA         
	 PUSHF
         JMP CEX
INCFBL:
	 POPF
	 popA
         INC BL
	 pushA         
	 PUSHF
         JMP CEX

CEROR95:
JMP CEROR
SUBBfBL95:
JMP SUBBfBL
XORFBL95:
JMP XORFBL
ANDFBL95:
JMP ANDFBL
ORRFBL95:
JMP ORRFBL

ADDfBL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADD BL,BUFF
	 pushA         
	 PUSHF
         JMP CEX
ADCfBL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADC BL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfBL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SUB BL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfBL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SBB BL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
XORFBL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
 	 POPF
	 popA
         XOR BL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFBL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         AND BL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFBL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         OR BL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
RCLLD73:
JMP RCLLD
RCHD73:
JMP RCHD72
RDHD73:
JMP RDHD72
RDLD73:
JMP RDLD72

       
RBHD:
 LEA DI,asciisum
 MOV BL ,[DI]
CMP BL,0EEH
     JZ MULFBH
  CMP BL,0E3H
     JZ DIVFBH
  CMP BL,0CCH
     JZ DECFBH
     
      CMP BL,0DAH
     JZ INCFBH

         CMP SOURCEHIN,16H
         JZ  CEROR96
  LEA DI,asciisum
      MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfBH
     
     CMP BL,0C8H
     JZ ADCfBH   
     
      CMP BL,0EAH
     JZ SUBfBH
     
      CMP BL,0D7H
     JZ SUBBfBH96
	  CMP BL,0F2H
     JZ MOVfBH
   CMP BL,0F9H
     JZ XORFBH96
     
      CMP BL,0D3H
     JZ ANDFBH96
 CMP BL,0D3H
     JZ ORRFBH96

 
    	
MOVfBH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 POPA
         MOV BH,BUFF 
         PUSHA
	 PUSHF
         JMP CEX
MULFBH:
	 POPF
	 popA
         MUL BH
	 pushA         
	 PUSHF
         JMP CEX
DIVFBH:
	 POPF
	 popA
         DIV BH
	 pushA         
	 PUSHF
         JMP CEX
DECFBH:
	 POPF
	 popA
         DEC BH
	 pushA         
	 PUSHF
         JMP CEX
INCFBH:
	 POPF
	 popA
         INC BH
	 pushA         
	 PUSHF
         JMP CEX

CEROR96:
JMP CEROR
SUBBfBH96:
JMP SUBBfBH
XORFBH96:
JMP XORFBH
ANDFBH96:
JMP ANDFBH
ORRFBH96:
JMP ORRFBH

ADDfBH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADD BH,BUFF 
	 pushA         
	 PUSHF
         JMP CEX
ADCfBH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADC BH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfBH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SUB BH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfBH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SBB BH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
XORFBH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
 	 POPF
	 popA
         XOR BH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFBH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         AND BH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFBH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         OR BH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
RCHD72:
JMP RCHD
RDHD72:
JMP RDHD71
RDLD72:
JMP RDLD71

       
RCLLD:
LEA DI,asciisum
MOV BL ,[DI]
 CMP BL,0EEH
     JZ MULFCL
  CMP BL,0E3H
     JZ DIVFCL
  CMP BL,0CCH
     JZ DECFCL
     
      CMP BL,0DAH
     JZ INCFCL

         CMP SOURCEHIN,16H
         JZ  CEROR97
       LEA DI,asciisum
       MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfCL
     
     CMP BL,0C8H
     JZ ADCfCL   
     
      CMP BL,0EAH
     JZ SUBfCL
     
      CMP BL,0D7H
     JZ SUBBfCL97
	  CMP BL,0F2H
     JZ MOVfCL
   CMP BL,0F9H
     JZ XORFCL97
     
      CMP BL,0D3H
     JZ ANDFCL97
 CMP BL,0D3H
     JZ ORRFCL97


    	
MOVfCL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 POPA
         MOV CL,BUFF 
         PUSHA
	 PUSHF
         JMP CEX
MULFCL:
	 POPF
	 popA
         MUL CL
	 pushA         
	 PUSHF
         JMP CEX
DIVFCL:
	 POPF
	 popA
         DIV CL
	 pushA         
	 PUSHF
         JMP CEX
DECFCL:
	 POPF
	 popA
         DEC CL
	 pushA         
	 PUSHF
         JMP CEX
INCFCL:
	 POPF
	 popA
         INC CL
	 pushA         
	 PUSHF
         JMP CEX

CEROR97:
JMP CEROR
XORFCL97:
JMP XORFCL
ANDFCL97:
JMP ANDFCL
ORRFCL97:
JMP ORRFCL
SUBBfCL97:
JMP SUBBfCL
ADDfCL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADD CL,BUFF
	 pushA         
	 PUSHF
         JMP CEX
ADCfCL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADC CL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfCL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SUB CL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfCL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SBB CL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
XORFCL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
 	 POPF
	 popA
         XOR CL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFCL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         AND CL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFCL:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         OR CL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
RDHD71:
JMP RDHD
RDLD71:
JMP RDLD70

RCHD:
LEA DI,asciisum
MOV BL ,[DI]
 CMP BL,0EEH
     JZ MULFCH
  CMP BL,0E3H
     JZ DIVFCH
  CMP BL,0CCH
     JZ DECFCH
     
      CMP BL,0DAH
     JZ INCFCH

         CMP SOURCEHIN,16H
         JZ  CEROR98
          LEA DI,asciisum
          MOV BL ,[DI]
     cmp BL,0C9H
     JZ ADDfCH
     
     CMP BL,0C8H
     JZ ADCfCH   
     
      CMP BL,0EAH
     JZ SUBfCH
     
      CMP BL,0D7H
     JZ SUBBfCH98
	  CMP BL,0F2H
     JZ MOVfCH
   CMP BL,0F9H
     JZ XORFCH98
     
      CMP BL,0D3H
     JZ ANDFCH98
 CMP BL,0D3H
     JZ ORRFCH98


    	
MOVfCH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 POPA
         MOV CH,BUFF
         PUSHA
	 PUSHF
         JMP CEX
MULFCH:
	 POPF
	 popA
         MUL CH
	 pushA         
	 PUSHF
         JMP CEX
DIVFCH:
	 POPF
	 popA
         DIV CH
	 pushA         
	 PUSHF
         JMP CEX
DECFCH:
	 POPF
	 popA
         DEC CH
	 pushA         
	 PUSHF
         JMP CEX
INCFCH:
	 POPF
	 popA
         INC CH
	 pushA         
	 PUSHF
         JMP CEX

CEROR98:
JMP CEROR
SUBBfCH98:
JMP SUBBfCH
XORFCH98:
JMP XORFCH
ANDFCH98:
JMP ANDFCH
ORRFCH98:
JMP ORRFCH

ADDfCH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADD CH,BUFF
	 pushA         
	 PUSHF
         JMP CEX
ADCfCH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADC CH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfCH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SUB CH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfCH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SBB CH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
XORFCH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
 	 POPF
	 popA
         XOR CH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFCH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         AND CH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFCH:
	 MOV AL,BYTE PTR FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         OR CH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

RDLD70:
JMP RDLD

RDHD:
LEA DI,asciisum 
MOV BL ,[DI]
CMP BL,0EEH
     JZ MULFDH
  CMP BL,0E3H
     JZ DIVFDH
  CMP BL,0CCH
     JZ DECFDH
     
      CMP BL,0DAH
     JZ INCFDH

       CMP SOURCEHIN,16H
       JZ  CEROR99
  LEA DI,asciisum
  MOV BL ,[DI]   
     cmp BL,0C9H
     JZ ADDfDH
     
     CMP BL,0C8H
     JZ ADCfDH   
     
      CMP BL,0EAH
     JZ SUBfDH
     
      CMP BL,0D7H
     JZ SUBBfDH99
	  CMP BL,0F2H
     JZ MOVfDH
   CMP BL,0F9H
     JZ XORFDH99
     
      CMP BL,0D3H
     JZ ANDFDH99
 CMP BL,0D3H
     JZ ORRFDH99
   
 
 	
MOVfDH:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 POPA
         MOV DH,BUFF 
         PUSHA
	 PUSHF
         JMP CEX
MULFDH:
	 POPF
	 popA
         MUL DH
	 pushA         
	 PUSHF
         JMP CEX
DIVFDH:
	 POPF
	 popA
         DIV DH
	 pushA         
	 PUSHF
         JMP CEX
DECFDH:
	 POPF
	 popA
         DEC DH
	 pushA         
	 PUSHF
         JMP CEX
INCFDH:
	 POPF
	 popA
         INC DH
	 pushA         
	 PUSHF
         JMP CEX

CEROR99:
JMP CEROR
XORFDH99:
JMP XORFDH
ANDFDH99:
JMP ANDFDH
ORRFDH99:
JMP ORRFDH
SUBBfDH99:
JMP SUBBfDH

ADDfDH:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADD DH,BUFF
	 pushA         
	 PUSHF
         JMP CEX
ADCfDH:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADC DH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfDH:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SUB DH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfDH:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SBB DH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
XORFDH:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
 	 POPF
	 popA
         XOR DH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFDH:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         AND DH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ORRFDH:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         OR DH,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
       
RDLD:
LEA DI,asciisum
MOV BL,[DI]
 CMP  BL,0EEH
     JZ MULFDL
  CMP  BL,0E3H
     JZ DIVFDL
  CMP  BL,0CCH
     JZ DECFDL
     
      CMP  BL,0DAH
     JZ INCFDL

       CMP SOURCEHIN,16H
       JZ CEROR100;;;;;;;;;;;;;
      LEA DI,asciisum
     MOV BL,[DI]
     cmp BL,0C9H
     JZ ADDfDL
     
     CMP BL,0C8H
     JZ ADCfDL   
     
      CMP BL,0EAH
     JZ SUBfDL
     
      CMP BL,0D7H
     JZ SUBBfDL100;;;;;;;;;;;
	  CMP BL,0F2H
     JZ MOVfDL
   CMP BL,0F9H
     JZ  XORFDL100;;;;;;;;;;;;;
     
      CMP BL,0D3H
     JZ ANDFDL100;;;;;;;;;;;;;;;
 CMP BL,0D3H
     JZ ORRFDL100;;;;;;;;;;;


    	
     MOVfDL:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 POPA
         MOV DL,BUFF 
         PUSHA
	 PUSHF
         JMP CEX
MULFDL:
	 POPF
	 popA
         MUL DL
	 pushA         
	 PUSHF
         JMP CEX
DIVFDL:
	 POPF
	 popA
         DIV DL
	 pushA         
	 PUSHF
         JMP CEX
ceror100:
JMP CEROR
XORFDL100:
JMP XORFDL
ANDFDL100:
JMP ANDFDL
ORRFDL100:
JMP ORRFDL
SUBBfDL100:
JMP SUBBfDL         
DECFDL:
	 POPF
	 popA
         DEC DL
	 pushA         
	 PUSHF
         JMP CEX
INCFDL:
	 POPF
	 popA
         INC DL
	 pushA         
	 PUSHF
         JMP CEX


ADDfDL:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADD DL,BUFF
	 pushA         
	 PUSHF
         JMP CEX
ADCfDL:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         ADC DL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
SUBfDL:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SUB DL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

SUBBfDL:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
	 POPF
	 popA
         SBB DL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
XORFDL:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
 	 POPF
	 popA
         XOR DL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
ANDFDL:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         AND DL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX
         
ORRFDL:
	 MOV AL,byte ptr FINALSOURCE 
   	 MOV BUFF,AL 
         POPF
	 popA
         OR DL,BUFF
 	 PUSHA 
         PUSHF
         JMP CEX

     
    
    CEROR:
    MOV ERRORFLAG,1H 
      MOV CX,5
      
    L44:  
    MOV AH,2
    MOV DL,7
    INT 21H 
    LOOP L44
    
    CEX: 
 
    
ENDM CMOVMACRO    
