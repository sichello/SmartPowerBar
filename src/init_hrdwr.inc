;hardware initialization for adc and pushbuttons

init_hrdwr:
                movb    #$00,INITRG          ;configure registers(lab 6 handout)
                movb    #$11,INITRM
                
                bclr    CLKSEL,#$80          ;configure clock (lab 6 handout)
                bset    PLLCTL,#$40
                movb    #$2,SYNR
                movb    #$0,REFDV
                nop
                nop
                bclr    CRGFLG,#$08,*
                bset    CLKSEL,#$80
                
                ldx     #REGBLK
                ldaa    #$ff
                staa    ddrj,x               ; make port J an output port
                staa    ddrb,x               ; make port B an output port
                staa    ddrp,x               ; make port P an output port
                staa    ptp,x                ; turn off 7-segment LED display
                
                movb    #$FF,ptp                ; turn off 7-segment LED display
                jsr     openLCD                 ; turn on/enable LCD screen
                movb    #$00,DDRH
		ldaa	#$0C
		jsr	cmd2LCD
                
                movb    #$C0,atd0ctl2           ;configure adc registers
                movb    #$08,atd0ctl3
                movb    #$05,atd0ctl4