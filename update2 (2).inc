;temp3 db 1,?,1 dup('$')
;tempppp db 6,?,6 dup('$')
;tempppp2 db 4,?,4 dup('$')
update3 macro
    
    POPF
    POPA
    
    MOV temppp1,Al
    MOV temppp2,Ah
                       
    PUSHA                  
    PUSHF
    LEA si,arrtemp1 
            
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+3],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+2],bl   
   ; MOV CX,2
  ;  LOOP550:
  ;  mov dx,3fdh
;    again8: in al,dx   
;    and al,00100000b
;    jz again8
;    mov dx,3f8h  
;    mov al,BYTE PTR [DI]
;    INC DI
;    out dx,al  
;    LOOP LOOP550  
          
   ; LEA DI,temppp2
    FROMDIGITTOASCILL temppp2
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+1],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+0],bl   
   ; MOV CX,4
;    lea si,arrtemp
;    LOOP551:
;    mov dx,3fdh
;    again9: in al,dx   
;    and al,00100000b
;    jz again9
;    mov dx,3f8h  
;    mov al,BYTE PTR [DI]
;    INC DI
;    out dx,al  
    ;LOOP LOOP551
    POPF
    POPA
    
    MOV temppp1,bl
    MOV temppp2,bh 
    PUSHA                  
    PUSHF
    LEA si,arrtemp1 
           
    ;LEA DI,temppp1
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+7],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+6],bl   
    ;MOV CX,2
    ;LOOP552:
    ;mov dx,3fdh
    ;again10: in al,dx   
    ;and al,00100000b
    ;jz again10
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP552  
          
    ;LEA DI,temppp2
    FROMDIGITTOASCILL temppp2
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+5],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+4],bl   
    ;MOV CX,2
    ;LOOP553:
    ;mov dx,3fdh
    ;again11: in al,dx   
    ;and al,00100000b
    ;jz again11
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP553
    POPF
    POPA 
    
    MOV temppp1,cl
    MOV temppp2,ch 
    PUSHA                  
    PUSHF
    LEA si,arrtemp1 
           
    ;LEA DI,temppp1
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+11],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+10],bl   
    ;MOV CX,2
    ;LOOP554:
    ;mov dx,3fdh
    ;again12: in al,dx   
    ;and al,00100000b
    ;jz again12
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP554  
          
    ;LEA DI,temppp2
    FROMDIGITTOASCILL temppp2
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+9],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+8],bl   
    ;MOV CX,2
    ;LOOP555:
    ;mov dx,3fdh
    ;again13: in al,dx   
    ;and al,00100000b
    ;jz again13
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP555
    POPF
    POPA  
    
    MOV temppp1,dl
    MOV temppp2,dh
    PUSHA                  ;12
    PUSHF
    LEA si,arrtemp1 
            
    ;LEA DI,temppp1
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+15],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+14],bl   
    ;MOV CX,2
    ;LOOP556:
    ;mov dx,3fdh
    ;again14: in al,dx   
    ;and al,00100000b
    ;jz again14
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP556  
          
    ;LEA DI,temppp2
    FROMDIGITTOASCILL temppp2
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+13],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+12],bl   
    ;MOV CX,2
    ;LOOP557:
    ;mov dx,3fdh
    ;again15: in al,dx   
    ;and al,00100000b
    ;jz again15
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP557
    POPF
    POPA
         
    mov var,si     
    
    pusha
    pushf
    LEA si,arrtemp1
    mov ax,var 
    MOV temppp1,Al
    MOV temppp2,Ah        
    ;LEA DI,temppp1
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+19],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+18],bl   
    ;MOV CX,2
    ;LOOP558:
    ;mov dx,3fdh
    ;again16: in al,dx   
    ;and al,00100000b
    ;jz again16
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP558  
          
    ;LEA DI,temppp2
    FROMDIGITTOASCILL temppp2
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+17],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+16],bl   
    ;MOV CX,2
    ;LOOP559:
    ;mov dx,3fdh
    ;again17: in al,dx   
    ;and al,00100000b
    ;jz again17
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP559
    POPF
    POPA  
          
    mov var,di      
    
    pusha
    pushf
    LEA si,arrtemp1
    mov ax,var 
    MOV temppp1,Al
    MOV temppp2,Ah        
    ;LEA DI,temppp1
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+23],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+22],bl   
    ;MOV CX,2
    ;LOOP560:
    ;mov dx,3fdh
    ;again18: in al,dx   
    ;and al,00100000b
    ;jz again18
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP560  
          
    ;LEA DI,temppp2
    FROMDIGITTOASCILL temppp2
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+21],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+20],bl   
    ;MOV CX,2
    ;LOOP561:
    ;mov dx,3fdh
    ;again19: in al,dx   
    ;and al,00100000b
    ;jz again19
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP561
    POPF
    POPA
    
    
    
    pusha
    pushf
    LEA si,arrtemp1
    mov ax,stackpointerreg 
    MOV temppp1,Al
    MOV temppp2,Ah        
    ;LEA DI,temppp1
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+27],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+26],bl   
    ;MOV CX,2
    ;LOOP562:
    ;mov dx,3fdh
    ;again20: in al,dx   
    ;and al,00100000b
    ;jz again20
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP562  
          
    ;LEA DI,temppp2
    FROMDIGITTOASCILL temppp2
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+25],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+24],bl   
    ;MOV CX,2
    ;LOOP563:
    ;mov dx,3fdh
    ;again21: in al,dx   
    ;and al,00100000b
    ;jz again21
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP563
    POPF
    POPA
         
         
    
    pusha
    pushf
    LEA si,arrtemp1
    mov ax,BASEpointerreg 
    MOV temppp1,Al
    MOV temppp2,Ah        
    ;LEA DI,temppp1
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+31],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+30],bl   
    ;MOV CX,2
    ;LOOP564:
    ;mov dx,3fdh
    ;again22: in al,dx   
    ;and al,00100000b
    ;jz again22
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP564  
          
    ;LEA DI,temppp2
    FROMDIGITTOASCILL temppp2
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+29],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+28],bl   
    ;MOV CX,2
    ;LOOP565:
    ;mov dx,3fdh
    ;again23: in al,dx   
    ;and al,00100000b
    ;jz again23
    ;mov dx,3f8h  
    ;mov al,BYTE PTR [DI]
    ;INC DI
    ;out dx,al  
    ;LOOP LOOP565
    
    
   ; MOV VAR,DI
    
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+0]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+33],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+32],bl  
    
    
    
    
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+1]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+35],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+34],bl  
    
    
    
    
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+2]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+37],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+36],bl  
    
    
    
    
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+3]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+39],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+38],bl  
    
    
    
              
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+4]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+41],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+40],bl  
    
    
    
              
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+5]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+43],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+42],bl  
    
    
    
     
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+6]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+45],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+44],bl  
    
    
    
              
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+7]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+47],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+46],bl  
    
    
    
             
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+8]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+49],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+48],bl  
    
    
    
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+9]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+51],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+50],bl  
   
    
    
            
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+10]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+53],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+52],bl  
   
    
             
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+11]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+55],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+54],bl  
    
    
     
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+12]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+57],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+56],bl  
    
    
    
            
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+13]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+59],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+58],bl  
   
    
    
             
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+14]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+61],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+60],bl  
    
    
    
     
    LEA si,arrtemp1
    LEA DI,MEMORYPLAYER   
    mov al,byte ptr [di+15]
    mov temppp1,al
    FROMDIGITTOASCILL temppp1
    mov bl,byte ptr twobyte+1
    mov byte ptr[si+63],bl
    mov bl,byte ptr twobyte
    mov byte ptr[si+62],bl   
    
        ; pointsss 
    
    ; LEA si,arrtemp1
;    LEA DI,mypoint1   
;    mov al,byte ptr [di+2]
;    mov byte ptr[si+64],al
;    mov bl,byte ptr twobyte
;    mov al,byte ptr [di+3]
;    mov byte ptr[si+65],bl 
    
     
    
Endm update3
    
    
    
    
    
    
    
    
update2 macro
    
    pusha
    mov  dl, 17h   ;Column
    mov  dh, 3h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp
    mov al,byte ptr[di+0]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+1]
    mov byte ptr[si+1],al
    mov al,byte ptr[di+2]
    mov byte ptr[si+2],al
    mov al,byte ptr[di+3]
    mov byte ptr[si+3],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp
    int 21h
    popa
    
    
    pusha
    mov  dl, 17h   ;Column
    mov  dh, 4h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp
    mov al,byte ptr[di+4]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+5]
    mov byte ptr[si+1],al
    mov al,byte ptr[di+6]
    mov byte ptr[si+2],al
    mov al,byte ptr[di+7]
    mov byte ptr[si+3],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp
    int 21h
    popa
    
    
    pusha
    mov  dl, 17h   ;Column
    mov  dh, 5h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp
    mov al,byte ptr[di+8]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+9]
    mov byte ptr[si+1],al
    mov al,byte ptr[di+10]
    mov byte ptr[si+2],al
    mov al,byte ptr[di+11]
    mov byte ptr[si+3],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp
    int 21h
    popa
    
    
    
    pusha
    mov  dl, 17h   ;Column
    mov  dh, 7h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp
    mov al,byte ptr[di+12]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+13]
    mov byte ptr[si+1],al
    mov al,byte ptr[di+14]
    mov byte ptr[si+2],al
    mov al,byte ptr[di+15]
    mov byte ptr[si+3],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp
    int 21h
    popa
    
    
    
    pusha
    mov  dl, 1Fh   ;Column
    mov  dh, 3h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp
    mov al,byte ptr[di+16]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+17]
    mov byte ptr[si+1],al
    mov al,byte ptr[di+18]
    mov byte ptr[si+2],al
    mov al,byte ptr[di+19]
    mov byte ptr[si+3],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp
    int 21h
    popa
    
    
    
    pusha
    mov  dl, 1Fh   ;Column
    mov  dh, 4h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp
    mov al,byte ptr[di+20]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+21]
    mov byte ptr[si+1],al
    mov al,byte ptr[di+22]
    mov byte ptr[si+2],al
    mov al,byte ptr[di+23]
    mov byte ptr[si+3],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp
    int 21h
    popa
    
    
    
    pusha
    mov  dl, 1Fh   ;Column
    mov  dh, 5h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp
    mov al,byte ptr[di+24]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+25]
    mov byte ptr[si+1],al
    mov al,byte ptr[di+26]
    mov byte ptr[si+2],al
    mov al,byte ptr[di+27]
    mov byte ptr[si+3],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp
    int 21h
    popa
          
          
    pusha
    mov  dl, 1Fh   ;Column
    mov  dh, 7h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp
    mov al,byte ptr[di+28]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+29]
    mov byte ptr[si+1],al
    mov al,byte ptr[di+30]
    mov byte ptr[si+2],al
    mov al,byte ptr[di+31]
    mov byte ptr[si+3],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp
    int 21h
    popa
         
         
         
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 0h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+32]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+33]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
    
    
    
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 1h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+34]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+35]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
    
    
    
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 3h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+36]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+37]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
    
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 4h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+38]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+39]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
                       
                       
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 5h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+40]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+41]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
         
         
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 7h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+42]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+43]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
    
    
    
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 8h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+44]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+45]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
                
                
                
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 9h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+46]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+47]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
              
              
              
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 0Ah   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+48]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+49]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
              
              
              
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 0Bh   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+50]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+51]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
                        
                        
                        
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 0Dh   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+52]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+53]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
    
    

    pusha
    mov  dl, 25h   ;Column
    mov  dh, 0Eh   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+54]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+55]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
    
               
               
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 0Fh   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+56]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+57]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
               
               
               
               
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 11h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+58]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+59]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
         
         
         
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 12h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+60]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+61]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa
         
         
         
    pusha
    mov  dl, 25h   ;Column
    mov  dh, 13h   ;Row
    mov  bh, 0    ;Display page
    mov  ah, 02h  ;SetCursorPosition
    int  10h
    LEA di,arrtemp
    LEA si,tempppp2
    mov al,byte ptr[di+62]
    mov byte ptr[si+0],al
    mov al,byte ptr[di+63]
    mov byte ptr[si+1],al
    ;mov temp3,al
    mov ah,09h
    mov dx, offset tempppp2
    int 21h
    popa 
    
    
    
    ;mypoint1 
    ;pusha
;    mov  dl, 9h   ;Column
;    mov  dh, 16h   ;Row
;    mov  bh, 0    ;Display page
;    mov  ah, 02h  ;SetCursorPosition
;    int  10h
;    LEA di,arrtemp
;    LEA si,tempppp2
;    mov al,byte ptr[di+64]
;    mov byte ptr[si+0],al
;    mov al,byte ptr[di+65]
;    mov byte ptr[si+1],al
;    ;mov temp3,al
;    mov ah,09h
;    mov dx, offset tempppp2
;    int 21h
;    popa 
    
    
    
Endm update2   
                         
                         
                         
    
     