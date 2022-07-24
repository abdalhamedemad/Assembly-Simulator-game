.286
include source.inc
;include updateMacro.inc
include update1.inc
include update2.inc
;include ADDMR.inc
include AYA.inc
include small.inc 
INCLUDE commall.inc
.Model SMALL
.Stack 64
.Data
MESSAGS DB  24, ?, 24 dup('$') 
MESSAGR DB  24, ?, 24 dup('$')
mmk db 0ch  
x db 0h    
  
MESWIN DB 'WINNER $'
MESLOS DB 'LOSER $'
TEMPUPDATE DW ?
TIME DB 0H
mmks db 1h  
xs db 0h  
CHOOSEPROCESSORMESSAGE db "CHOOSE PROCESSOR:$"   
eups db "Pups:$"
ccc db "comma:$"
cccL2 db "PROCE:$"
errorr db "Error$"
right db "right$"
TEMPSPANDBP DW 0H
;stackpointerreg dw 0h
BASEpointerreg dw 0h 
onboth22 db 1h
arrtemp db 66 dup('0')
arrtemp1 db 66 dup('0') 
var dw ?
tempp dw ?
temp db 6,?,6 dup('$')
temp2 db 1,?,1 dup('$')
temp3 db ?
temp4 db ?
temppp db 6,?,6 dup('$')
temppp1 db ?
temppp2 db ?
tempppp db 6,?,6 dup('$')
tempppp2 db 4,?,4 dup('$')
READING DB 15 dup('$')
points DB ?
commands DB  15, ?, 15 dup('$')
asciisum db ? 
asciidestsum db ?
asciisourcesum  db ?
asciidigits db 4 dup(?)
SOURCESELECTOR DB ?
DESTINATIONSELECTOR DB ?
BUFF DB 0H
MEMORYPLAYER DB 16 DUP(0)
MEMORYPLAYER2 DB 16 DUP(0)
stackpointerreg dw 0h
SOURCEHIN DB ?
FINALSOURCE DW ? 
FINALDEST  DW ?
memorysource db ? 
VAR8BIT DB ?
VAR16BIT DW ?
;N2 DB  15, ?, 15 dup('$')
;point1 DB 4,?,4 dup('$')
;point2 DB 4,?,4 dup('$')   
STRING1 DB "ENTER your name : $"
STRING2 DB "ENTER intial points : $"
STRING3 DB "Press Enter Key to continue $"
STRING4 DB "Press F2 To Start The Game $"
STRING5 DB "Press ESC Key to End the program $"
ppp db "Points $"
NAME DB 15,?,15 DUP('$')
NEWLINE DB 10,13,'$' 
TEMPSHIFTROT DB ?
TEMPSHIFTROT2 DW ? 
ERRORFLAG DB 0H 
OPPONENTDATA DB 33 DUP('$') 
OPPOK DB 0H
OPPONENTCOMMAND DB  15, ?, 15 dup('$')
CMOK DB 0H 
N2 DB  15, ?, 15 dup('$')
N1 DB  15, ?, 15 dup('$') 
point1 DB 4,?,4 dup('$')
point2 DB 4,?,4 dup('$')
initialpts DB ? 
FK DB ? 
FKOPPONENT DB ?
STRING6 DB "Choose Any Level (1 or 2) $"
STRING10 DB "THE LEVEL OF THE GAME IS $" 
STRING7 DB "Choose Any FORBIDEN KEY(CHAR,NUMVER) $"
STRING8 DB "YOUR OPPONENT CHOSE THIS FORBIDDEN KEY : $"
STRINGCHAT DB "TO START CHATTING PRESS F1 $"
STRING9 DB "CHOOSE REGISTERS' VALUES (AX-BX-CX-DX-SI-DI-SP-BP) : $"
TWOBYTE DB 0,0
FINALPOINTS DB ?
FKUSEDFLAG DB 0H
GAMELEVEL DB ?
MINECHECKFK DB 0H


photoWidth EQU 320
photoHeight EQU 200

photoFilename DB 'photo.bin', 0

photoFilehandle DW ?

photoData DB photoWidth*photoHeight dup(0) 
POWERUPS1 DB ?
POWERUPS2 DB ?
TURNFLAG DB 0H
ONLYONEFK DB 0H

AXL2 DW ?
BXL2 DW ?
CXL2 DW ?
DXL2 DW ?
SPL2 DW ?
BPL2 DW ?
DIL2 DW ?
SIL2 DW ?
FORTHDIGIT DW ?
THIRDDIGIT DW ?    ;NOTWORKING IF DB
SECONDDIGIT DW ?
FIRSTDIGIT DW ? 
PROCESSOR DB ? ; O-->OPPONENT M-->MINE
TARGETVALUE DW 105EH
ONLYONCETARGETVALUE DB 0H
TEMPTARGETVALUE DW ?

.Code



MAIN PROC FAR
    MOV AX , @DATA
    MOV DS , AX
   BEGINNN:
     MOV AH,0
    MOV AL,3H              
    INT 10H                
    DISPLAY STRING1
    READ2 N1       
    DISPLAY NEWLINE
    DISPLAY STRING2
    READ2 POINT1
    DISPLAY NEWLINE
    DISPLAY STRING3         
    CALL intial 
    CHECK:
    MOV AH,0  ;CHECK ENTER KEY 
    INT 16H
    MOV AH,1
    INT 16H
    CMP AL,13
    JNZ CHECK 
    MOV AH,0
    MOV AL,3H
    INT 10H
    
   DISPLAY STRING4
    DISPLAY NEWLINE
    DISPLAY STRINGCHAT 
    DISPLAY NEWLINE
    DISPLAY STRING5 
    
    CLICK:
    MOV AH,0
    INT 16H
    CMP AH,3BH
    JZ CHATTING
    CMP AL,27
    JZ EXITFF2
    CMP AH,3CH  ;CHECK MODE
    JZ LEVELCHOOSE2 
    JMP CLICK
    
EXITFF2:
JMP EXITFF
LEVELCHOOSE2:
JMP LEVELCHOOSE    
CHATTING:
CALL intial 


    MOV AH,0
    MOV AL,3H              
    INT 10H  
    
    
      mov ah,2
    mov bh,0
    mov dx,0A00h
    int 10h 

    mov cx,0
loop2f:
    mov ah,02h
    mov dl,'_'
    int 21h
    inc cx
    cmp cx,80
jnz loop2f          

    mov ah,2
    mov bh,0
    mov dx,0000h
    int 10h  
    Display n1
                     
                     
    mov ah,2
    mov bh,0
    mov dx,0b00h
    int 10h  
    Display n2
                     
    

  


               
    lea si,MESSAGS
    LEA DI,MESSAGR   
    
SEND:
    
    
    MOV AH,01h
    INT 16H
    JZ REC  ; GET KEY PRESSED IF NOT KEY PRESSED JZ TO RECIEVE  
  

    MOV AH,0h
    INT 16H
    
      mov  dl, xs   ;Column
      mov  dh,mmks   ;Row            
      mov  bh, 0    ;Display page
      mov  ah, 02h  ;SetCursorPosition
      int  10h
      add xs,1h
    
    
    
     
    MOV AH,2
    MOV DL,AL     
    INT 21H
    
    CMP AL,1BH
    JE EXITCHAT
     
    mov byte ptr [si+2],al
    inc si
    CMP AL,0dh
    jz go
    jmp send
    
    
    go:
         add mmks,1h 
      mov xs,0h   
     call sendCHAT
     lea si,MESSAGS 
     mov cx,24
     hnhn:
     mov byte ptr [si+2],'$'
     inc si
     loop hnhn
     
     
      lea si,MESSAGS   
     jmp send
                                                             

    
REC:   LEA DI,MESSAGR 
   
 reg:   mov dx,3fdh
    in al,dx
    and al,1
    JZ SEND 
    mov dx,03f8h
    in al,dx
    cmp al,0dh  ;mean enter key 
    jz newlineCH
    cmp al,'$'
    jz send 
    
      mov  dl, x   ;Column
      mov  dh,mmk   ;Row            
      mov  bh, 0    ;Display page
      mov  ah, 02h  ;SetCursorPosition
      int  10h
      add x,1h
    
    MOV AH,2
    MOV DL,AL     
    INT 21H
    ;mov BYTE PTR [DI+2] ,al
    ; Display  MESSAGR+2 
   ; INC DI
    jmp reg 
    
   
   
   newlineCH:
     ; mov  dl, 0h   ;Column
     ; mov  dh,mmk   ;Row            
     ; mov  bh, 0    ;Display page
     ; mov  ah, 02h  ;SetCursorPosition
     ; int  10h
      add mmk,1h 
      mov x,0h
    ; Display  MESSAGR+2 
     ;LEA DI,MESSAGR 
     jmp rec 
       
   
    
    
   EXITCHAT: 
      JMP BEGINNN
 

    
    LEVELCHOOSE:
  
    DISPLAY NEWLINE
    DISPLAY NEWLINE
    DISPLAY STRING10
    
    
     LEVEL:
    CALL RESGAMELEVEL
    CMP GAMELEVEL,31H
    JZ LEVEL1
    JNZ LEVEL2KK

LEVEL2KK:
JMP LEVEL2
    
LEVEL1:
    MOV AH,2
    MOV DL,'1'     ;DISPLAY LEVEL
    INT 21H            
    
    
    
    DISPLAY NEWLINE
    DISPLAY STRING7
    MOV AH,0
    INT 16H
    MOV FK,AL   ;FORBIDEN KEY
     
    
    MOV AH,2H
    MOV DL,AL    ; DISPLAY FK CHOSEN BY CURRENT USER
    INT 21H 
   CALL RECIEVEFK
   CALL SENDFORBIDDEN
   
    
    DISPLAY NEWLINE
    DISPLAY STRING8
    
    MOV AH,2H
    MOV DL,FKOPPONENT ; DISPLAY FK CHOSEN BY OPPONENT USER ; IT WILL COME AS ASCII , SO IT CAN BE DISPLAYED DIRECTLY
    INT 21H
    
    DISPLAY NEWLINE
    DISPLAY STRING3
    
             
    
    CHECKENTER2:
    MOV AH,0  ;CHECK ENTER KEY 
    INT 16H
    MOV AH,1
    INT 16H
    CMP AL,13
    JNZ CHECKENTER2 
    JZ EXITFF3
EXITFF3:
JMP EXITFF

LEVEL2:
     
    MOV AH,2
    MOV DL,'2'     ;DISPLAY LEVEL
    INT 21H
    MOV GAMELEVEL,32H
    
     
    DISPLAY NEWLINE
    DISPLAY STRING7
    MOV AH,0
    INT 16H
    MOV FK,AL 
    
    MOV AH,2H
    MOV DL,AL    ; DISPLAY FK CHOSEN BY CURRENT USER
    INT 21H 
    
    CALL SENDFORBIDDEN
    CALL RECIEVEFK ;NOT DISPLAYED AS IT IS LEVEL2 (DEDUCED)
     
    DISPLAY NEWLINE
    DISPLAY STRING9
    DISPLAY NEWLINE
     
    LEVEL2INITIALIZATION 
    
    DISPLAY NEWLINE
    DISPLAY STRING3         
    
    CHECKENTER:
    MOV AH,0  ;CHECK ENTER KEY 
    INT 16H
    MOV AH,1
    INT 16H
    CMP AL,13
    JNZ CHECKENTER 
    JZ EXITFF
 EXITFF:
    
    MOV AH, 0
    MOV AL, 13h
    mov bh,0
    INT 10h
	
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
;///////finish gui/////////

;lea di,MEMORYPLAYER
 ;   mov BYTE PTR [DI],12H
  ;  MOV BYTE PTR [DI+1],34H 
    
LEA si,commands
mov  dl, 4h   ;Column
mov  dh, 13h   ;Row
mov  bh, 0    ;Display page
mov  ah, 02h  ;SetCursorPosition
int  10h   
DISPLAY N1+2

LEA si,commands
mov  dl, 1h   ;Column
mov  dh, 16h   ;Row
mov  bh, 0    ;Display page
mov  ah, 02h  ;SetCursorPosition
int  10h   
DISPLAY ppp

LEA si,commands
mov  dl, 9h   ;Column
mov  dh, 16h   ;Row
mov  bh, 0    ;Display page
mov  ah, 02h  ;SetCursorPosition
int  10h   
DISPLAY point1+2


;LEA si,commands
;mov  dl, 4h   ;Column
;mov  dh, 13h   ;Row
;mov  bh, 0    ;Display page
;mov  ah, 02h  ;SetCursorPosition
;int  10h   
;DISPLAY N2+2

   call intial
   CMP GAMELEVEL,31H
    JZ NORMALINITIALIZE
    JNZ INITIALIZELEVEL2 
NORMALINITIALIZE:    
CALL  INTIALIZE
JMP    CONTTTTTT
INITIALIZELEVEL2:;
CALL INITIALIZEL2 
;CALL resREGST
;CALL sendREGIST
JMP CONTTTTTT
CONTTTTTT:
   update
   update2 
 repee:
 PUSHA 
 PUSHF 
 ;call intial
 ;\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
     
      CMP TURNFLAG,1H     
        JZ myturn
        jmp OPPONENTTURN
        
        
                ; i will send first 
  myturn:       
        
  ; first turn 
 
 ;A||B||C   
  ;//////////////////////////pups: 
mov dl, 0h   ;Column
mov dh, 11h   ;Row
mov bh, 0    ;Display page
mov ah, 02h  ;SetCursorPosition
int 10h  
mov ah,09h
mov dx,offset eups
int 21h  
MOV AH,0
 INT 16H
 MOV POWERUPS1,AL  ; read power ups  
 CALL  SENDpowerups ; send power ups to opponent 
  
 ;
 CMP POWERUPS1,'A' ;
 
 ;
 ;  points > 5 
 ;
 JZ ONMYPROCESSORTG 
 
 
 CMP POWERUPS1,'B'
 ;    points > 3 
 ;
 JZ ONBOTHKKK
 CMP POWERUPS1,'C'
 JZ CHANGEFKKKK
 CMP POWERUPS1,'E'
 JZ CLEARALLREGISTERSKKK 
     jmp NORMAL 

ONBOTHKKK:
JMP ONBOTH
CHANGEFKKKK:
JMP CHANGEFK
CLEARALLREGISTERSKKK:
JMP CLEARALLREGISTERS


ONMYPROCESSORTG:
CMP GAMELEVEL,31H
JZ  ONMYPROCESSOR
JMP TG
 
ONMYPROCESSOR:
READ3 COMMANDS
MOV TURNFLAG,0H
MOV MINECHECKFK,1H
 JMP EEX  
TG:
CHANGEGAMETARGET
CALL SENDNEWTARGETVALUE 
JMP END78 

ONBOTH:
READ3 COMMANDS
MOV CX,15 
LEA DI , COMMANDS
LEA SI, OPPONENTCOMMAND
LABELONBOTH:
mov al,BYTE PTR [DI]
MOV BYTE PTR [SI],al
INC DI
INC SI
LOOP  LABELONBOTH
CALL sendCOMMAND
mov onboth22,0h
MOV TURNFLAG,0H
MOV MINECHECKFK,1H
JMP EEX  


CHANGEFK:
CMP ONLYONEFK ,0H
JZ CHANGEFORBBIDENKEY
JMP DONOTCHANGEFK
CHANGEFORBBIDENKEY:
MOV ONLYONEFK ,1H
MOV AH,0
INT 16H
MOV FK,AL
CALL SENDFORBIDDEN
JMP END78
DONOTCHANGEFK:
CALL SENDFORBIDDEN 
JMP END78


CLEARALLREGISTERS:
mov cx,65
lea si, arrtemp1
llltoz:

mov BYTE PTR[si],0h
inc si
loop llltoz
update2

POPF
POPA
CALL INTIALIZE

MOV TURNFLAG,0H
PUSHA
PUSHF 
;update
JMP FINALEXIT
              
NORMAL:
CMP GAMELEVEL,31H
JZ LEVEL1NORMAL
JMP  LEVEL2NORMAL
LEVEL1NORMAL: 
    mov dl, 0h   ;Column
    mov dh, 11h   ;Row
    mov bh, 0    ;Display page
    mov ah, 02h  ;SetCursorPosition
    int 10h  
    mov ah,09h
    mov dx,offset CCC
    int 21h   ; run in normal way                     
     
     Read3  OPPONENTCOMMAND
     CALL sendCOMMAND
     call resREGST
     update2
     MOV TURNFLAG,0H  ; SEND                                             ;   CALL sendREGIST 
     JMP FINALEXIT
     
LEVEL2NORMAL:          
mov dl, 0h   ;Column
    mov dh, 11h   ;Row
    mov bh, 0    ;Display page
    mov ah, 02h  ;SetCursorPosition
    int 10h  
    mov ah,09h
    mov dx,offset CCCL2
    int 21h
    
    MOV AH,0H
    INT 16H
    MOV PROCESSOR,AL 
   TURNTOASCIIFK PROCESSOR
CALL SENDPROCESSORSELECTOR    
mov dh, 11h   ;Row
    mov bh, 0    ;Display page
    mov ah, 02h  ;SetCursorPosition
    int 10h  
    mov ah,09h
    mov dx,offset CCC
    int 21h 
CMP PROCESSOR,'O'
JZ OPPSPROC
JMP MINEEE
                
OPPSPROC:          
 Read3  OPPONENTCOMMAND
     CALL sendCOMMAND
     call resREGST
     update2
     MOV TURNFLAG,0H  ; SEND                                             ;   CALL sendREGIST 
     JMP FINALEXIT
     
MINEEE:
READ3 COMMANDS
MOV TURNFLAG,0H
MOV MINECHECKFK,1H
 JMP EEX
     
      
OPPONENTTURN: 
CALL RECIEVEPOWERUPS

 CMP POWERUPS2,'A'
 JZ ONMYPROCESSOR2TG
 CMP POWERUPS2,'B'
 JZ ONBOTH55
 CMP POWERUPS2,'C'
 JZ chang223
 CMP POWERUPS2,'E'
 JZ clear223
 JMP NOPWUPS
 onboth55:
 jmp onboth2  
 
 chang223:
 jmp CHANGEFK2
 
 clear223:
 jmp CLEARALLREGISTERS2

ONMYPROCESSOR2TG:

CMP GAMELEVEL,31H
JZ ONMYPROCESSOR2
JMP TGRES
 
ONMYPROCESSOR2:
call resREGST
update2
MOV TURNFLAG,1H
JMP FINALEXIT

TGRES:
CALL RESNEWTARGETVALUE
MOV TURNFLAG,1H
JMP END78

ONBOTH2:
CALL resCOMMAND
call resREGST
update2
MOV TURNFLAG,1H
JMP EEX

CHANGEFK2:
CALL RECIEVEFK
MOV TURNFLAG,1H
JMP END78;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;////////////

CLEARALLREGISTERS2:
mov cx,65
lea si, arrtemp1
llltozMM:

mov BYTE PTR [si],0h
inc si
loop llltozMM
update2

POPF
POPA
CALL INTIALIZE

MOV TURNFLAG,1H
PUSHA
PUSHF
;update
JMP FINALEXIT 

NOPWUPS:
CMP GAMELEVEL,31H
JZ LEVEL1NORMALREC
JMP  LEVEL2NORMALREC

LEVEL1NORMALREC:
CALL resCOMMAND
MOV TURNFLAG,1H
JMP EEX   ; EXECUTE COMMAND 
LEVEL2NORMALREC:
CALL RESPROCESSORSELECTOR
CMP PROCESSOR,'O'
JNZ OPPSPROCREC
JMP MINEEEREC 

OPPSPROCREC:
call resREGST
update2
MOV TURNFLAG,1H
JMP FINALEXIT 
MINEEEREC: 
CALL resCOMMAND
MOV TURNFLAG,1H
JMP EEX   ; EXECUTE COMMAND 

 
 
 



   
     ; Read3  OPPONENTCOMMAND    ; READ COMMAND FROM USER                     ;  CMP CMOK,1H 
                                                                          ;  JNZ ERORINRESCOM
                                                                          ;    ; DO YOUR OPERATION + UPDATE HIS INTERFACE
     ;CALL sendCOMMAND  ; SEND                                             ;   CALL sendREGIST 
     
                                                                          ;   CALL sendCOMMAND
     ;CALL resREGST   ; WAIT UNTIL THE OPPENENT SEND THE CHANGES           ;    CALL resREGST
     ;CMP OPPOK,1H                                                         ;    CMP OPPOK,1H
     ;JNZ ERORINRES                                                        ;    JNZ ERORINRES 
                                                                          ;    UPDATE INTERFACE
     ; UPDATE OPPONENT INTERFACE   -> OPPONENTDATA  
     
     
     ;CALL resCOMMAND
     ;CMP CMOK,1H 
     ;JNZ ERORINRESCOM
     ;CALL sendREGIST  

     ;jmp END78
     
          ; A - EXCUTE COMMAND ON YOUR PC            ;   CALL resREGST   ; WAIT UNTIL THE OPPENENT SEND THE CHANGES   
          ; Read commands                            ;
          ; EXECUTE IT                               ;
          ;  CALL sendREGIST                         ;
          ;                                          ;
          ;                                          ;
          ;
          ;
          ;
          ;
          ;
          ;
          ;
   ;////////////////////////////////////////////////////////////////////////////////////////////////////
   ;//////////read commands//////////

    ;read commands   

eex:
;mov  dl, 3h   ;Column
;mov  dh, 3h   ;Row
;mov  bh, 0    ;Display page
;mov  ah, 02h  ;SetCursorPosition
;int  10h
;mov ah,09h
;mov dx,offset commands
;int 21h

   CMP GAMELEVEL,31H
    JZ NORMALINITIALIZE2
    JNZ INITIALIZELEVEL22
     
NORMALINITIALIZE2:    
CALL  INTIALIZE 
JMP CONTINGAME
INITIALIZELEVEL22:;
CALL INITIALIZEL2
JMP CONTINGAME 
 
; PUSHA
CONTINGAME:     
    S_to_C commands
    
CMP MINECHECKFK,1H
    JZ CHECKMYYFK
    JMP NOTBOTHNOTMINE
    
CHECKMYYFK:
TURNTOASCIIFK FKOPPONENT
    FKUSEDONBOTH
    MOV MINECHECKFK,0H
    
    CMP FKUSEDFLAG,1H
    JZ FORBIDDENUSED
    JMP CONTINUEINGAME



NOTBOTHNOTMINE:
TURNTOASCIIFK FK
    FKUSED        
 CMP FKUSEDFLAG,1H
    JZ FORBIDDENUSED
    JMP CONTINUEINGAME



    
FORBIDDENUSED:
MOV FKUSEDFLAG,0H
JMP END78

CONTINUEINGAME:    
    
    
       ; small to capital
;////////////////////////////////////////////////////////////////////////
    LEA DI,asciisum
     CMP BYTE PTR [DI],0D2h
     JZ  CCLC  
     CMP BYTE PTR [DI],0DFH
     JZ CNOB  
     jmp convert1999
      CCLC:     
     CLC
     JMP END78
     CNOB:
     NOP 
     JMP END78
     
;////////////////////////////////////////////////////////////////////    
    convert1999:
     CONV 
   ;/////////////////////////////////////////
                           
     
  ;/////////////////////// determine the command //////////////
     LEA DI,asciisum
     
     
     
     
     CMP BYTE PTR [DI],0EDH
     JZ CSHR
     
     CMP BYTE PTR [DI],0E7H
     JZ CSHR
     
     
     
    
     
     CMP BYTE PTR [DI],0EFH
     JZ CSHR
     
     CMP BYTE PTR [DI],0F0H
     JZ CSHR   
     
     
     
     
     
     CMP BYTE PTR [DI],0E5h
     JZ CSHR
     
     CMP BYTE PTR [DI],0E1h
     Jz CSHR
     
     CMP BYTE PTR [DI],0E6h
     JZ CSHR
     
     JMP OTHER
     
  ; //////// EX MOV  
       
     
  
      
     CSHR:
     CSHIFTROTMACRO 
     JMP END78
     other:
     
     
     
     cmp BYTE PTR [DI],0C9H
     JZ CMOV
     
     CMP BYTE PTR [DI],0C8H
     JZ CMOV   
     
     CMP BYTE PTR [DI],0EAH
     JZ CMOV
     
     CMP BYTE PTR [DI],0D7H
     JZ CMOV
     
     CMP BYTE PTR [DI],0E3H  ; DIV
     JZ  CMOV
     
     CMP BYTE PTR [DI],0EEH ; MUL
     JZ  CMOV
     
     CMP BYTE PTR [DI],0F2H
     JZ CMOV
     
     CMP BYTE PTR [DI],0F9H
     JZ CMOV
     
     CMP BYTE PTR [DI],0D3H
     JZ CMOV
      CMP BYTE PTR [DI],0DAH
     JZ CMOV
     CMP BYTE PTR [DI],6Ch
     JZ CMOV
     CMP BYTE PTR [DI],0CCH
     JZ CMOV
     CMOV:
   
    
    CMOVMACRO 

     JMP END78
     
      
    
         
  ;/////////////   
     
         
     END78:
     
    
     
      POPF 
     POPA
      MMMMMM:
     update
     pusha
     pushf  
     update3
     call sendREGIST
     
     
     

     ;pusha
     ;pushf
     cmp ERRORFLAG,1h
     jz dddd
     jmp rightlabel

     dddd:
    mov  dl, 0h   ;Column
    mov  dh, 0h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h 
    ;mov  bl, 0ch  ;Color is red
   ;mov  bh, 0    ;Display page
   ;mov ah, 0Eh  ;Teletype
   ;int  10h
     mov ah,09h
     mov dx,offset errorr
     int 21h
     mov ERRORFLAG,0h
     jmp finalexit


     rightlabel:
      mov  dl, 0h   ;Column
    mov  dh, 0h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h 
    ;mov  bl, 0ch  ;Color is red
   ;mov  bh, 0    ;Display page
   ;mov ah, 0Eh  ;Teletype
   ;int  10h
     mov ah,09h
     mov dx,offset right
     int 21h
    
              
     cmp onboth22,0h
     jz onboth33   
      jmp FINALEXIT
     
     
     onboth33: 
     call resREGST
     update2
     mov onboth22,1h          
              
     FINALEXIT:

     POPF 
     POPA
     
 JMP repee    
     
 ; ///////////////////////////////////////  
    
   ; MOVE asciisourcesum asciidestsum
               
  ; jmp repee
  
  
  ;hlt 
  
  
   INTIALIZE proc near 
   MOV AX,0
   MOV BX,0
   MOV CX,0
   MOV DX,0
   MOV SI,0
   MOV DI,0   
   
   
   MOV asciisum ,'?'
   MOV asciidestsum,'?' 
   MOV asciisourcesum,'?'
   MOV SOURCESELECTOR,'?'
   MOV DESTINATIONSELECTOR,'?'
   MOV SOURCEHIN,'?'
   MOV FINALDEST,'?'
   MOV memorysource,'?'
        
   ret
   
    


INTIALIZE ENDp

INITIALIZEL2 proc near 
    
    MOV BX,BXL2
    MOV CX,CXL2
    MOV DX,DXL2
    MOV SI,SIL2
    MOV DI,DIL2
    MOV AX, SPL2
    MOV stackpointerreg,AX
    MOV AX, BPL2
    MOV BASEpointerreg,AX   
    MOV AX,AXL2
   
   MOV asciisum ,'?'
   MOV asciidestsum,'?' 
   MOV asciisourcesum,'?'
   MOV SOURCESELECTOR,'?'
   MOV DESTINATIONSELECTOR,'?'
   MOV SOURCEHIN,'?'
   MOV FINALDEST,'?'
   MOV memorysource,'?'
        
   ret
   
    


INITIALIZEL2 ENDp 

  intial proc
    Mov dx,3fbh
    mov al,10000000b
    out dx,al

    mov dx,3f8h
    mov al,0ch
    out dx,al

    mov dx,3f9h
    mov al,00H
    out dx,al

    mov dx,3fbh
    mov al,00011011b
    out dx,al

    ret

intial ENDP
   
   sendCOMMAND  proc
   LEA DI,OPPONENTCOMMAND 
    
    
    MOV BYTE PTR [DI+14],'Q' ;  
    MOV CX,15
    LOOP55:
    mov dx,3fdh
    again7: in al,dx   
    and al,00100000b
    jz again7
    mov dx,3f8h  
    mov al,BYTE PTR [DI]
    INC DI
    out dx,al  
    LOOP LOOP55 
    
    RET

sendCOMMAND ENDP
   
  sendREGIST  proc 
    
      
    LEA DI,arrtemp1 
      
    MOV CX,66
    LOOP77:
    mov dx,3fdh
    again55: in al,dx   
    and al,00100000b
    jz again55
    mov dx,3f8h  
    mov al,BYTE PTR [DI]
    INC DI
    out dx,al  
    LOOP LOOP77 
    
    
    
    
     
    
    RET

sendREGIST ENDP
  
resCOMMAND  proc
    LEA DI,commands
     
    MOV CX,15
    LOOP660:
    mov dx,3fdh
    check3: in al,dx
    and al,1
    jz check3
    mov dx,03f8h
    in al,dx
    mov BYTE PTR [DI] ,al
    INC DI
    LOOP LOOP660
    
    CMP COMMANDS+15,'Q'
    JZ SUCESS ; :)
    
    MOV CMOK,0 ; :(
    JMP EXRR 
     
    SUCESS:
    MOV CMOK,1 
     
    EXRR: 
     
    ret

resCOMMAND ENDP  


resREGST  proc
    LEA DI,arrtemp
     
    MOV CX,66
    LOOP669:
    mov dx,3fdh
    check4: in al,dx
    and al,1
    jz check4
    mov dx,03f8h
    in al,dx
    mov BYTE PTR [DI] ,al
    INC DI
    LOOP LOOP669
    
    ;CMP COMMANDS+33,'Q'
;    JZ SUCESS45 ; :)
;    
;    MOV OPPOK,0 ; :(
;    JMP EXRR77 
;     
;    SUCESS45:
;    MOV OPPOK,1 
;     
;    EXRR77: 
     
    ret

resREGST ENDP


SENDPOINT PROC 
     
     LEA DI,POINT1
     
     MOV CX,2
     LLL44:
     MOV DX,3FDH
     AGIN55: IN AL,DX
     AND AL,00100000B
     JZ AGIN55
     
     MOV DX,3F8H
     MOV AL,BYTE PTR [DI+2]
     
     OUT DX,AL 
     INC DI  
     LOOP LLL44
     RET 
SENDPOINT ENDP 

SENDNAMES PROC 
     
     LEA DI,N1
     
     MOV CX,15
     LLL4411:
     MOV DX,3FDH
     AGIN556: IN AL,DX
     AND AL,00100000B
     JZ AGIN556
     
     MOV DX,3F8H
     MOV AL,BYTE PTR [DI]
     
     OUT DX,AL 
     INC DI  
     LOOP LLL4411
     RET 
SENDNAMES ENDP

SENDFORBIDDEN PROC 
     
     LEA DI,FK
     
    ; MOV CX,10
     ;LLL4411:
     MOV DX,3FDH
     AGIN5561: IN AL,DX
     AND AL,00100000B
     JZ AGIN5561
          
     MOV DX,3F8H
     MOV AL,BYTE PTR [DI]
     
     OUT DX,AL 
    ;INC DI  
     ;LOOP LLL4411
     RET 
SENDFORBIDDEN ENDP 
SENDpowerups PROC 
     
     LEA DI,POWERUPS1
     
    ; MOV CX,10
     ;LLL4411:
     MOV DX,3FDH
     AGIN5561PW: IN AL,DX
     AND AL,00100000B
     JZ AGIN5561PW
          
     MOV DX,3F8H
     MOV AL,BYTE PTR [DI]
     
     OUT DX,AL 
    ;INC DI  
     ;LOOP LLL4411
     RET 
SENDpowerups ENDP

 SENDNEWTARGETVALUE PROC
    LEA DI,TARGETVALUE
     
    ; MOV CX,10
     ;LLL4411:
     MOV DX,3FDH
     AGIN5561TG: IN AL,DX
     AND AL,00100000B
     JZ AGIN5561TG
          
     MOV DX,3F8H
     MOV AL,BYTE PTR [DI]
     
     OUT DX,AL 
    ;INC DI  
     ;LOOP LLL4411
     RET 
SENDNEWTARGETVALUE ENDP
 RESNEWTARGETVALUE PROC
   LEA DI, TARGETVALUE
 ; MOV CX,15 
  ;LDH:
  MOV DX,3FDH
  CHK7891TG: IN AL,DX
  AND AL,1
  JZ CHK7891TG

  MOV DX,03F8H
  IN AL,DX
  MOV BYTE PTR [DI],AL
  RET  
    
    
RESNEWTARGETVALUE ENDP


RECIEVEPOINT PROC
   LEA DI, POINT2
  MOV CX,2 
  LDH:
  MOV DX,3FDH
  CHK789: IN AL,DX
  AND AL,1
  JZ CHK789

  MOV DX,03F8H
  IN AL,DX
  MOV BYTE PTR [DI+2],AL
  INC DI
  LOOP LDH 
 
     
RECIEVEPOINT ENDP 

sendCHAT  proc
   LEA bx,MESSAGS 
    
    
   
    MOV CX,24
    LOOP55kCHAT:
    mov dx,3fdh
    again7CHAT: in al,dx   
    and al,00100000b
    jz again7CHAT
    mov dx,3f8h  
    mov al,BYTE PTR [bx+2]
    INC bx
    out dx,al  
    LOOP LOOP55kCHAT 
    
    RET

sendCHAT ENDP

RECIEVENAMES PROC
   LEA DI, N2
  MOV CX,15 
  LDH1:
  MOV DX,3FDH
  CHK7892: IN AL,DX
  AND AL,1
  JZ CHK7892

  MOV DX,03F8H
  IN AL,DX
  MOV BYTE PTR [DI],AL
  INC DI
  LOOP LDH1 
 
     
RECIEVENAMES ENDP

SENDPROCESSORSELECTOR  PROC
       LEA DI,PROCESSOR
     
    ; MOV CX,10
     ;LLL4411:
     MOV DX,3FDH
     AGIN5561CHOOSEPROC: IN AL,DX
     AND AL,00100000B
     JZ AGIN5561CHOOSEPROC
          
     MOV DX,3F8H
     MOV AL,BYTE PTR [DI]
     
     OUT DX,AL 
    ;INC DI  
     ;LOOP LLL4411
     RET   
    
SENDPROCESSORSELECTOR  ENDP

RESPROCESSORSELECTOR PROC  
    
  LEA DI, PROCESSOR
 ; MOV CX,15 
  ;LDH:
  MOV DX,3FDH
  CHK7891PROC: IN AL,DX
  AND AL,1
  JZ CHK7891PROC

  MOV DX,03F8H
  IN AL,DX
  MOV BYTE PTR [DI],AL
        RET
RESPROCESSORSELECTOR ENDP

RECIEVEFK PROC
  LEA DI, FKOPPONENT
 ; MOV CX,15 
  ;LDH:
  MOV DX,3FDH
  CHK7891: IN AL,DX
  AND AL,1
  JZ CHK7891

  MOV DX,03F8H
  IN AL,DX
  MOV BYTE PTR [DI],AL
  ;INC DI
  ;LOOP LDH 
 
      ret
RECIEVEFK ENDP
 
RESGAMELEVEL PROC
     LEA DI, GAMELEVEL
 ; MOV CX,15 
  ;LDH:
  MOV DX,3FDH
  CHK7891GL: IN AL,DX
  AND AL,1
  JZ CHK7891GL

  MOV DX,03F8H
  IN AL,DX
  MOV BYTE PTR [DI],AL
     RET
RESGAMELEVEL ENDP

RECIEVEPOWERUPS PROC
  LEA DI, POWERUPS2
 ; MOV CX,15 
  ;LDH:
  MOV DX,3FDH
  CHK7891PW: IN AL,DX
  AND AL,1
  JZ CHK7891PW

  MOV DX,03F8H
  IN AL,DX
  MOV BYTE PTR [DI],AL
  ;INC DI
  ;LOOP LDH
  ret 
 
     
RECIEVEPOWERUPS ENDP 


    ; Press any key to exit
    MOV AH , 0
    INT 16h
    
    call CloseFile
    
    ;Change to Text MODE
    MOV AH,0          
    MOV AL,11h
    INT 10h 
    ;mov bh,0
    ;int 10h
    ;mov ah,2h
    ;mov dx,0303h
    ;int 10h
	;mov ah, 9
	;mov dx, offset msg
	;int 21h
    

    ; return control to operating system
    MOV AH , 4ch
    INT 21H   
    
   
     RET
 
    
    
    
MAIN ENDP 





OpenFile PROC 

    ; Open file

    MOV AH, 3Dh
    MOV AL, 0 ; read only
    LEA DX, photoFilename
    INT 21h
    
    ; you should check carry flag to make sure it worked correctly
    ; carry = 0 -> successful , file handle -> AX
    ; carry = 1 -> failed , AX -> error code
     
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

END MAIN
END MAIN