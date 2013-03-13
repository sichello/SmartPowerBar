;Lee Sichello
;interrupt service routine that samples pushbuttons and current

RTI_ISR:        bset    CRGFLG,#$80
;---------------------------------------
TIMING_STUFF:
		ldx	tcount1
		inx
		stx	tcount1
		cpx	#1000
		bne	TIMING2
		movw	#$0000,tcount1
		ldx	seconds1
		inx
		stx	seconds1
				
TIMING2:	
		ldx	tcount2
		inx
		stx	tcount2
		cpx	#1000
		bne	PGM_STUFF
		movw	#$0000,tcount2
		ldx	seconds2
		inx
		stx	seconds2				
;---------------------------------------
PGM_STUFF:
                ldx     pgm_count
                cpx     #5000
                bne     inc_pgm_count
                movw    #$0000,pgm_count
                bset    intFLG,#$03           ;set the timeout bit
                jmp     CHECK_RST_HOLD
inc_pgm_count:
                inx
                stx     pgm_count
                jmp     CHECK_RST_HOLD
;---------------------------------------
CHECK_RST_HOLD:
                ldy     hold_count
                iny
                sty     hold_count

		ldaa    pth                   ;retrieve pushbttn status in bits 0-3 (0=pressed)
                coma                          ;1 = pressed
                anda    #$0F                  ;clear upper bits
                staa    pbtn_sample
                brclr   pbtn_sample,#$02,PBTN_STUFF
                movb    #$02,pbtn_status
done_RST:       rti
                
;---------------------------------------
PBTN_STUFF:
                cmpa    #$00
                beq     nothing_pressed      ;if no button is down, go to nonthing pressed

                ldx     #750
                cpx     pbtn_count
                bne     low_pbtn_count     ;if pbtn_cout != 500, go to nothing pressed
                bra     pbtn_pressed
nothing_pressed:
                movb    #$00,pbtn_status
                ldx     #750
                stx     pbtn_count
                bra     ADC_STUFF
low_pbtn_count:
                ldx     pbtn_count
                inx
                stx     pbtn_count
                bra     ADC_STUFF
pbtn_pressed:
                staa    pbtn_status
                movw    #$00,pbtn_count
                jmp     ADC_STUFF
;--------------------------------------
ADC_STUFF:
;========
adc_out1:
                movb    #$86,atd0ctl5           ;tells adc to take reading on an6
                brclr   atd0stat0,#$80,*         ;wait until reading is finished
                ldaa    atd0dr0h                 ;retrieve sample from data register
                ldab    atd0dr0l                ;get upper half of sample into D

                cpd     #5
                bge     keep_sample1             ;if sample is greater than or = #$01

null_sample1:   ldx     n_nullsamp1
                inx
                stx     n_nullsamp1
                ldx     #1000
                cpx     n_nullsamp1
                ble     no_load1                ;if 40 of 50 samples are null, there is no load
                jmp     adc_out2
                                              ;set v_inst = 0
no_load1:       movw    #$0000,v_inst1
                movw    #$0000,i_inst1
                movw    #$0000,n_nullsamp1
                bset    intFLG,#$10
                bset    intFLG,#$40           ;set print flag
                jmp     calc_Iave1
                
keep_sample1:   addd    sum_samp1                 ;add to sum of samples
                std     sum_samp1                ;store new sum
                
                ldx     n_samp1                  ;increment sample count
                inx
                stx     n_samp1

                ldx     #50
                cpx     n_samp1
                ble     get_ave1                  ;if n_samples > 50 return get_ave
                jmp     adc_out2
                
get_ave1:       ldd     sum_samp1                ;if n_samples >= 50 take sum/count=average
                idiv                            ;d/x->x where x = average for 50 samples
                xgdx                            ;put average into d
                addd    sum_ave1               ;add 50cycle ave to sum
                std     sum_ave1
                
                ldx     n_ave1                   ;increment sample count
                inx
                stx     n_ave1

                movw    #$0000,n_samp1             ;reset the cycle count
                movw    #$0000,sum_samp1
                movw    #$0000,n_nullsamp1
                bclr    intFLG,#$10
                
                ldx     #10
                cpx     n_ave1
                ble     get_v_inst1              ;if n_samples > 50 return get_ave
                jmp     adc_out2
                
get_v_inst1:    ldd     sum_ave1                ;if n_samples >= 40 take sum/count=average
                idiv                            ;d/x->x where x = average for 2000 samples
                xgdx                            ;put average into d
                ldy     #1000
                emul                            ;d*1000 into y:d
                ldx     #205
                ediv                            ;y:d/x into Y, remainder into D (y=voltage in mV)
                sty     v_inst1
                
                ldd     #357                   ;conversion factor times 100
                emul                           ;v_inst*395 into y:d  (result fits in d though)
                ldx     #100
                ediv                            ;v_vinst*395/100 into y  gives current (in mA)
                sty     i_inst1


                movw    #$0000,n_ave1             ;reset the cycle count
                movw    #$0000,sum_ave1
                bset    intFLG,#$40             ;set the intFLG

calc_Iave1:
                ldd     Iave1
                ldy     n_Iave1
                emul                            ;Iave*n_Iave->y:d  (weighting)
                addd    i_inst1                 ;add new entry to product
                bcc     no_carry1               ;incremement y if needed
                iny
no_carry1:      ldx     n_Iave1
                inx
                stx     n_Iave1
                ediv                            ;[(old ave)*entries + new instantaneous]/entries+1 -> y
                sty     Iave1

;=========
adc_out2:
                movb    #$00,atd0dr0h
                movb    #$00,atd0dr0h
                movb    #$82,atd0ctl5           ;tells adc to take reading on an5
                brclr   atd0stat0,#$80,*         ;wait until reading is finished
                ldaa    atd0dr0h                 ;retrieve sample from data register
                ldab    atd0dr0l                ;get upper half of sample into D

                cpd     #5
                bge     keep_sample2             ;if sample is greater than or = #$01

null_sample2:   ldx     n_nullsamp2
                inx
                stx     n_nullsamp2
                ldx     #1000
                cpx     n_nullsamp2
                ble     no_load2                ;if 40 of 50 samples are null, there is no load
                jmp     done_adc
                                              ;set v_inst = 0
no_load2:       movw    #$0000,v_inst2
                movw    #$0000,i_inst2
                movw    #$0000,n_nullsamp2
                bset    intFLG,#$20
                bset    intFLG,#$80           ;set print flag
                jmp     calc_Iave2

keep_sample2:   addd    sum_samp2                 ;add to sum of samples
                std     sum_samp2                ;store new sum

                ldx     n_samp2                  ;increment sample count
                inx
                stx     n_samp2

                ldx     #50
                cpx     n_samp2
                ble     get_ave2                  ;if n_samples > 50 return get_ave
                jmp     done_adc

get_ave2:       ldd     sum_samp2                ;if n_samples >= 50 take sum/count=average
                idiv                            ;d/x->x where x = average for 50 samples
                xgdx                            ;put average into d
                addd    sum_ave2               ;add 50cycle ave to sum
                std     sum_ave2

                ldx     n_ave2                   ;increment sample count
                inx
                stx     n_ave2

                movw    #$0000,n_samp2             ;reset the cycle count
                movw    #$0000,sum_samp2
                movw    #$0000,n_nullsamp2
                bclr    intFLG,#$20

                ldx     #10
                cpx     n_ave2
                ble     get_v_inst2              ;if n_samples > 50 return get_ave
                jmp     done_adc

get_v_inst2:    ldd     sum_ave2                ;if n_samples >= 40 take sum/count=average
                idiv                            ;d/x->x where x = average for 2000 samples
                xgdx                            ;put average into d
                ldy     #1000
                emul                            ;d*1000 into y:d
                ldx     #205
                ediv                            ;y:d/x into Y, remainder into D (y=voltage in mV)
                sty     v_inst2

                ldd     #379                   ;conversion factor times 100
                emul                           ;v_inst*395 into y:d  (result fits in d though)
                ldx     #100
                ediv                            ;v_vinst*395/100 into y  gives current (in mA)
                sty     i_inst2
                
                movw    #$0000,n_ave2             ;reset the cycle count
                movw    #$0000,sum_ave2
                bset    intFLG,#$80             ;set the intFLG

calc_Iave2:
                ldd     Iave2
                ldy     n_Iave2
                emul                            ;Iave*n_Iave->y:d  (weighting)
                addd    i_inst2                 ;add new entry to product
                bcc     no_carry2               ;incremement y if needed
                iny
no_carry2:      ldx     n_Iave2
                inx
                stx     n_Iave2
                ediv                            ;[(old ave)*entries + new instantaneous]/entries+1 -> y
                sty     Iave2

done_adc:       rti