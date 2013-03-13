;CNTRL_FNCTNS.inc
;Lee Sichello
;Purpose: A set of subroutines which alter the flow of control and user flags in the program. Makes output decisions


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DISPLAY:
                brset   pbtn_status,#$04,inc_display
                brset   pbtn_status,#$08,dec_display
                jmp     display_set
                
dec_display:    ldaa    #$01
                cmpa    disp_no
                beq     set_disp6
                dec     disp_no
                bra     display_set
set_disp6:
                ldaa    #6
                staa    disp_no
                bra     display_set
                
inc_display:    ldaa    #$06
                cmpa    disp_no
                beq     set_disp1
                inc     disp_no
                bra     display_set

set_disp1:
                ldaa    #1
                staa    disp_no
                bra     display_set

display_set:
                movb    #$00,pbtn_status
                jsr     clear_LCD

disp_1:         ldaa    #$01
                cmpa    disp_no
                bne     disp_2
                jsr     print_i
                rts
                
disp_2:         ldaa    #$02
                cmpa    disp_no
                bne     disp_3
                jsr     print_p
                rts
                
disp_3:         ldaa    #$03
                cmpa    disp_no
                bne     disp_4
                jsr     printPave
                rts
                
disp_4:         ldaa    #$04
                cmpa    disp_no
                bne     disp_5
                jsr     print_totE
                rts
                
                
disp_5:         ldaa    #$05
                cmpa    disp_no
                bne     disp_6
                jsr     print_totC
                rts

disp_6:         jsr     print_daily
                rts
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
PROGRAM:
                bclr    pbtn_status,#$01
                jsr     clear_LCD
                ldx     #str_pgm
                jsr     putsLCD
                ldaa    #$C0
                jsr     cmd2LCD
                ldd     cost
                ldy     #cost_buffer
                jsr     prep_1dp_buff
                ldx     #cost_buffer
                jsr     putsLCD
                ldx     #str_cents
                jsr     putsLCD
                movw    #$0000,pgm_count
                bclr    intFLG,#$03
pgm_back:
                brclr   intFLG,#$03,pgm_check_stat   ;check pbtns until time is up
                bclr    intFLG,#$03                  ;clear timeout flag
                rts
                
pgm_check_stat:
                brset   pbtn_status,#%00001000,pgm_L ;go to left routine if pressed
                brset   pbtn_status,#%00000100,pgm_R ;go to right routine if pressed
                jmp     pgm_back
pgm_L:
                ldd     cost
                cpd     #0
                beq     print_new_cost
                subd    #5
                std     cost
                bclr    pbtn_status,#%00001000
                bra     print_new_cost
pgm_R:
                ldd     cost
                cpd     #500
                beq     print_new_cost
                ldd     cost
                addd    #5
                std     cost
                bclr    pbtn_status,#%00000100
                jmp     print_new_cost
print_new_cost:
                ldaa    #$C0
                jsr     cmd2LCD
                ldd     cost
                ldy     #cost_buffer
                jsr     prep_1dp_buff
                ldx     #cost_buffer
                jsr     putsLCD
                ldx     #str_cents
                jsr     putsLCD
                movw    #$0000,pgm_count
                bclr    intFLG,#$02
                
                jmp     pgm_back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
OUTLET:
                movw    #$0000,hold_count
outlet_back:
                brclr   pbtn_status,#$02,toggle_outlet
                ldy     hold_count
                cpy     #2000
                bne     outlet_back
                
                brset   intFLG,#08,reset2
                movw    #$0000,Iave1
                movw    #$0000,n_Iave1
                movw    #$0000,Pave1
                movw    #$0000,daily1
                movw    #$0000,tcount1
                movw    #$0000,seconds1
                movw    #$0000,totE1
                movw        #$0000,totcost1
                bra     outpt_rst
reset2:         movw    #$0000,Iave2
                movw    #$0000,n_Iave2
                movw    #$0000,Pave2
                movw    #$0000,daily2
                movw    #$0000,tcount2
                movw    #$0000,seconds2
                movw    #$0000,totE2
                movw    #$0000,totcost2
                bra     outpt_rst
toggle_outlet:
                brset   intFLG,#$08,clear_outflg
                bset    intFLG,#$08                     ;toggles the outlet
                rts
outpt_rst:
                jsr     clear_LCD
                ldx     #str_rst
                jsr     putsLCD
                jsr     print_out
                jsr     de2s
                movb    #$0000,hold_count
                brset   pbtn_status,#$02,*
                rts
clear_outflg:
                bclr    intFLG,#$08
                rts