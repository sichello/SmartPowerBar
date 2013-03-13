lcd_dat:        equ     PORTK
lcd_dir:        equ     DDRK
lcd_E           equ     $02
lcd_RS          equ     $01

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
clear_LCD:      psha
                ldaa    #$01
                jsr     cmd2LCD
                pula
                rts
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
cmd2LCD:        pshy
                psha
                psha
                bclr    lcd_dat,lcd_RS
                bset    lcd_dat,lcd_E
                anda    #$F0
                lsra
                lsra
                oraa    #lcd_E
                staa    lcd_dat
                nop
                nop
                nop
                bclr    lcd_dat,lcd_E
                pula
                anda    #$0F
                lsla
                lsla
                bset    lcd_dat,lcd_E
                oraa    #lcd_E
                staa    lcd_dat
                nop
                nop
                nop
                bclr    lcd_dat,lcd_E
                ldy     #1
                jsr     de50us
                pula
                puly
                rts

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
openLCD:        pshy
                psha
                movb    #$FF,lcd_dir
                ldy     #10
                jsr     de10ms
                ldaa    #$28
                jsr     cmd2lcd
                ldaa    #$0F
                jsr     cmd2lcd
                ldaa    #$06
                jsr     cmd2lcd
                ldaa    #$01
                jsr     cmd2lcd
                ldy     #2
                jsr     de10ms
                pula
                puly
                rts

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
putcLCD:        pshy
                psha
                psha
                bset    lcd_dat,lcd_RS
                bset    lcd_dat,lcd_E
                anda    #$F0
                lsra
                lsra
                oraa    #$03
                staa    lcd_dat
                nop
                nop
                nop
                bclr    lcd_dat,lcd_E
                pula
                anda    #$0F
                lsla
                lsla
                bset    lcd_dat,lcd_E
                oraa    #$03
                staa    lcd_dat
                nop
                nop
                nop
                bclr    lcd_dat,lcd_E
                ldy     #1
                jsr     de50us
                pula
                puly
                rts

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
putsLCD:        
		ldaa    1,x+
                beq     donePS
                jsr     putcLCD
                bra     putsLCD
donePS:         rts
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
de10ms:         ldaa    #10                 ; delay 10 ms
                staa    counter
de10ms1:        ldy     #6000                ; 6000 x 4 = 24,000 cycles = 1ms
de10ms2:        dey                          ; this instruction  takes 1 cycle
                bne     de10ms2               ; this instruction  takes 3 cycles
                dec     counter
                bne     de10ms1               ; not 250ms yet, delay again
                rts

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
de50us:         ldaa    #250                  ; delay 250 us
                staa    counter
de50us1:        ldy     #6                   ; 6 x 4 = 24 cycles = 1us
de50us2:        dey                          ; this instruction  takes 1 cycle
                bne     de50us2                ; this instruction  takes 3 cycles
                dec     counter
                bne     de50us1               ; not 250ms yet, delay again
                rts
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
de2s:         	ldaa    #50                  ; delay 250 us
                staa    counter
de2s1:        	ldy     #60000                ; 60000 x 4 = 240000 cycles = 0.1s
de2s2:        	dey                          ; this instruction  takes 1 cycle
                bne     de2s2                ; this instruction  takes 3 cycles
                dec     counter
                bne     de2s1               ; not 250ms yet, delay again
                rts