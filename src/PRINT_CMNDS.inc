;PRINT_CMNDS.inc
;Lee Sichello
;purpose: subroutines for printing the instantaneous voltage/current/power and average power and daily cost

print_v:        ldx     #str_voltage
                jsr     putsLCD
                jsr     print_out
print_v_back:
                brclr   pbtn_status,#$0F,print_v_back2
                rts
print_v_back2:  brclr   intFLG,#$C0,print_v_back     ;stay until print flag or no load goes high
                ldaa    #$C0
                jsr     cmd2LCD

                brset   intFLG,#$08,load_v2
                bclr    intFLG,#$40
                brset   intFLG,#$10,NoLoad_v
                ldd     v_inst1
                bra     load_v_buff
load_v2:
                bclr    intFLG,#$80
                brset   intFLG,#$20,NoLoad_v
                ldd     v_inst2
load_v_buff:
                ldy     #v_buffer
                jsr     prep_2dp_buff
                ldx     #v_buffer
                jsr     putsLCD
                ldx     #str_Volts
                jsr     putsLCD
                jmp     print_v_back
                
NoLoad_v:       jsr     print_NoLoad
                jmp     print_v_back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_i:        ldx     #str_current
                jsr     putsLCD
                jsr     print_out
print_i_back:
                brclr   pbtn_status,#$0F,print_i_back2
                rts
print_i_back2:  brclr   intFLG,#$C0,print_i_back     ;stay until print flag or no load goes high
                ldaa    #$C0
                jsr     cmd2LCD

                brset   intFLG,#$08,load_i2
                bclr    intFLG,#$40
                brset   intFLG,#$10,NoLoad_i
                ldd     i_inst1
                bra     load_i_buff
load_i2:
                bclr    intFLG,#$80
                brset   intFLG,#$20,NoLoad_i
                ldd     i_inst2
load_i_buff:
                ldy     #i_buffer
                jsr     prep_2dp_buff
                ldx     #i_buffer
                jsr     putsLCD
                ldx     #str_Amps
                jsr     putsLCD
                bclr    intFLG,#$40
                jmp     print_i_back
                
NoLoad_i:       jsr     print_NoLoad
                jmp     print_i_back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_p:        ldx     #str_power
                jsr     putsLCD
                jsr     print_out
print_p_back:
                brclr   pbtn_status,#$0F,print_p_back2
                rts
print_p_back2:  brclr   intFLG,#$C0,print_p_back     ;stay until print flag or no load goes high
                ldaa    #$C0
                jsr     cmd2LCD
                
cacl_p12:       ldd     i_inst1                     ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     p_inst1
                
                ldd     i_inst2                     ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     p_inst2
                
                brset   intFLG,#$08,load_p2
                bclr    intFLG,#$40
                brset   intFLG,#$10,NoLoad_p
                ldd     p_inst1
                bra     load_p_buff
load_p2:
                bclr    intFLG,#$80
                brset   intFLG,#$20,NoLoad_p
                ldd     p_inst2
load_p_buff:
                ldy     #p_buffer
                jsr     prep_3dp_buff
                ldx     #p_buffer
                jsr     putsLCD
                ldx     #str_kW
                jsr     putsLCD
                bclr    intFLG,#$40
                jmp     print_p_back
                
NoLoad_p:       jsr     print_NoLoad
                jmp     print_i_back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
printPave:      ldx     #str_Pave
                jsr     putsLCD
                jsr     print_out
printPav_back:
                brclr   pbtn_status,#$0F,printPav_back2
                rts
printPav_back2: brclr   intFLG,#$C0,printPav_back     ;stay until print flag or no load goes high
                ldaa    #$C0
                jsr     cmd2LCD

calc_Pav12:     ldd     Iave1                       ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     Pave1
                

                ldd     Iave2                      ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     Pave2

                brset   intFLG,#$08,loadPav2
                ;bclr    intFLG,#$40
                ;brset   intFLG,#$10,NoLoad_Pav
                ldd     Pave1
                bra     loadPave_buff
loadPav2:       ldd     Pave2
                ;bclr    intFLG,#$80
                ;brset   intFLG,#$20,NoLoad_Pav
loadPave_buff:
                ldy     #Pave_buffer
                jsr     prep_3dp_buff
                ldx     #Pave_buffer
                jsr     putsLCD
                ldx     #str_kW
                jsr     putsLCD
                bclr    intFLG,#$40
                jmp     printPav_back
                
NoLoad_Pav:    	jsr     print_NoLoad
                jmp     printPav_back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_daily:    
		ldaa	#$80
		jsr	cmd2LCD
		ldx     #str_daily
                jsr     putsLCD
                jsr     print_out
              
daily_back:
                brclr   pbtn_status,#$0F,is_cost_set
                rts
is_cost_set:
		ldx	cost
		cpx	#$0000
		bne	daily_back2
		ldaa	#$C0
		jsr	cmd2LCD
		ldx	#str_NoCost
		jsr	putsLCD
		bra	daily_back

daily_back2:    brclr   intFLG,#$C0,daily_back     ;stay until print flag or no load goes high


calc_daily:     ldd     Iave1                       ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     Pave1
                ldy     Pave1
		ldd     #24
                emul                                ;y:d contains ave power(w) * 24 hrs
                ldy     cost
                emul
                ldx     #1000
                ediv                                        ;y:d contains cost in Wh*(cents/kWh) = cents/K
        	sty     daily1

                ldd     Iave2                      ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     Pave2
                ldd     #24
                emul                                ;y:d contains ave power(w) * 24 hrs
                ldy     cost
                emul
                ldx     #1000
                ediv                                        ;y:d contains cost in Wh*(cents/kWh) = cents/K
        	sty     daily2

                ldaa    #$C1
                jsr     cmd2LCD
		brset   intFLG,#$08,load_daily2
                ldd     daily1
                bra     ld_daily_buff
load_daily2:    ldd     daily2
ld_daily_buff:
            	cpd	#10
		bge	outpt_daily
	   	ldaa	#$C0
		jsr	cmd2LCD
		ldx	#str_below0
		jsr	putsLCD
		jmp	print_daily
outpt_daily:
		
		ldy     #daily_buffer
                jsr     prep_2dp_buff
                ldx     #daily_buffer
                jsr     putsLCD
		ldx	#str_11spaces
		jsr	putsLCD
	        ldaa    #$C0
                jsr     cmd2LCD
		ldaa	#$24
		jsr	putcLCD
		bclr    intFLG,#$40
                jmp     daily_back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_totE:	ldx     #str_tot
                jsr     putsLCD
                jsr     print_out
printtot_back:
                brclr   pbtn_status,#$0F,printtot_back2
                rts
printtot_back2: brclr   intFLG,#$C0,printtot_back     ;stay until print flag or no load goes high
                ldaa    #$C0
                jsr     cmd2LCD

calc_tot12:     ldd     Iave1                       ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     Pave1
		ldd	seconds1
		emul				;d*y->y:d = energy in W*s
		ldx	#3600
		ediv				:y=total w*hrs
		sty	totE1
                

                ldd     Iave2                      ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     Pave2
		ldd	seconds2
		emul				;d*y->y:d = energy in W*s
		ldx	#3600
		ediv				:y=total w*hrs
		sty	totE2
                
                brset   intFLG,#$08,loadtot2
                ;bclr    intFLG,#$40
                ;brset   intFLG,#$10,NoLoad_tot
                ldd     totE1
                bra     loadtot_buff
loadtot2:       ldd     totE2
                ;bclr    intFLG,#$80
                ;brset   intFLG,#$20,NoLoad_tot
loadtot_buff:
                
		ldy     #totE_buffer
                jsr     prep_3dp_buff
                ldx     #totE_buffer
                jsr     putsLCD
                ldx     #str_kWh
                jsr     putsLCD
		
		bclr    intFLG,#$40
                jmp     printtot_back
                
NoLoad_tot:    	jsr     print_NoLoad
                jmp     printtot_back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_totC:	
		ldaa	#$80
		jsr	cmd2LCD
		ldx     #str_totcost
                jsr     putsLCD
                jsr     print_out
printC_back:
                brclr   pbtn_status,#$0F,is_cost_setC
                rts
is_cost_setC:
		ldx	cost
		cpx	#$0000
		bne	printC_back2
		ldaa	#$C0
		jsr	cmd2LCD
		ldx	#str_NoCost
		jsr	putsLCD
		bra	printC_back

printC_back2:   brclr   intFLG,#$C0,printC_back     ;stay until print flag or no load goes high

calc_C12:       ldd     Iave1                       ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     Pave1
		ldd	seconds1
		emul				;d*y->y:d = energy in W*s
		ldx	#3600
		ediv				:y=total w*hrs
		sty	totE1
		ldd	cost
		emul				;y*d->y:d contains total cost in thousands of dollars
		ldx	#1000
		ediv				;y contains cost in cents
		sty	totcost1			
			
                

                ldd     Iave2                      ;current in mA  in d
                ldy     #110                        ;assumed voltage
                emul                                ;d*y->y:d contains  power in mW
                ldx     #1000
                ediv                                ;d:y/x->y (y contains power in W)
                sty     Pave2
		ldd	seconds2
		emul				;d*y->y:d = energy in W*s
		ldx	#3600
		ediv				:y=total w*hrs
		sty	totE2
		ldd	cost
		emul				;y*d->y:d contains total cost in thousands of dollars
		ldx	#1000
		ediv				;y contains cost in cents
           	sty	totcost2
                
		ldaa    #$C1
                jsr     cmd2LCD
		brset   intFLG,#$08,loadC2
                ;bclr    intFLG,#$40
                ;brset   intFLG,#$10,NoLoad_C
                ldd     totcost1
                bra     loadC_buff
loadC2:       	ldd     totcost2
                ;bclr    intFLG,#$80
                ;brset   intFLG,#$20,NoLoad_C
loadC_buff:
            	cpd	#10
		bge	outpt_totC
	   	ldaa	#$C0
		jsr	cmd2LCD
		ldx	#str_below0
		jsr	putsLCD
		jmp	print_totC
outpt_totC:
                
		ldy     #totC_buffer
                jsr     prep_2dp_buff
                ldx     #totC_buffer
                jsr     putsLCD
		ldx	#str_11spaces
		jsr	putsLCD
                ldaa	#$C0
                jsr     cmd2LCD
		ldaa	#$24
		jsr	putcLCD
		bclr    intFLG,#$40
                jmp     printC_back
                
NoLoad_C:    	jsr     print_NoLoad
                jmp     printC_back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_out:
                ldaa    #$8E
                jsr     cmd2LCD
                ldaa    #$23
                jsr     putcLCD
                
                brset    intFLG,#$08,print_out2
print_out1:
                ldaa    #$31
                jsr     putcLCD
                rts
print_out2:
                ldaa    #$32
                jsr     putcLCD
                rts
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_NoLoad:   ldx     #str_NoLoad
                jsr     putsLCD
                rts