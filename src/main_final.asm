;Project:         Smart Power Bar
;Creator:         Lee Sichello
;Date:          Jan-Mar, 2011
;Class:         ENEL 387
;Description:   The following is the assembly code written to control the
                ;'smart power bar' module. IT is written for the HC9S12
                ;and implemented on a Dragon12 board from WYTEC along with a
                ;custom designed current sampling circuit. The program makes use
                ;of the LCD screen for output and uses the pushbuttons for user
                ;control. Two ADC channels are the only external interfaces.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include        D_variant_registers.inc


REGBLK:         equ     $0000
STACK:          equ     $2000
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                org     $1000
counter:        rmb     1
pbtn_status:    rmb     1
pbtn_sample:    rmb     1
pbtn_count:     rmb     2
disp_no:        rmb     1
hold_count:     rmb     2
pgm_count:      rmb     2
intFLG:         rmb     1                     ;used to enter into main loop
cost:           rmb     2

daily_buffer:   rmb     7
cost_buffer:    rmb     7
v_buffer:       rmb     6
i_buffer:       rmb     6
p_buffer:       rmb     7
Pave_buffer:    rmb     7
totE_buffer:    rmb     7
totC_buffer:    rmb     7

n_nullsamp1:    rmb     2
sum_samp1:      rmb     2                     ;sum of 1ms voltage samples
n_samp1:        rmb     2                     ;number of 1ms samples
sum_ave1:       rmb     2                     ;sum of average reading for 60 cycles
n_ave1:         rmb     2                     ;number of 60 cycle averages
v_inst1:        rmb     2                     ;'instantaneous' voltage = sum_ave50cyc/n_ave50cyc(taken every 2000 samples or 2s)
i_inst1:        rmb     2                     ;instantneous current
p_inst1:        rmb     2
n_nullsamp2:    rmb     2
sum_samp2:      rmb     2                     ;sum of 1ms voltage samples
n_samp2:        rmb     2                     ;number of 1ms samples
sum_ave2:       rmb     2                     ;sum of average reading for 60 cycles
n_ave2:         rmb     2                     ;number of 60 cycle averages
v_inst2:        rmb     2                     ;'instantaneous' voltage = sum_ave50cyc/n_ave50cyc(taken every 2000 samples or 2s)
i_inst2:        rmb     2                     ;instantneous current
p_inst2:        rmb     2
Pave1:          rmb     2
Pave2:          rmb     2
Iave1:          rmb     2
n_Iave1:        rmb     2
Iave2:          rmb     2
n_Iave2:        rmb     2
daily1:         rmb     2
daily2:         rmb     2
tcount1:        rmb     2
tcount2:        rmb     2
seconds1:       rmb     2
seconds2:       rmb     2
totE1:          rmb     2
totE2:          rmb     2
totcost1:       rmb     2
totcost2:       rmb     2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                org     $4000                        ;begin program code
handler_0:      rti
start:          lds     #STACK
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include        init_hrdwr.inc                  ;initialize the hardware
#include        init_intrpt.inc                 ;initialize the RTI
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
main:
                movw    #$0000,v_inst1          ;initialize variables
                movw    #$0000,v_inst2
                movw    #$0000,i_inst1
                movw    #$0000,i_inst2
                movw    #$0000,p_inst1
                movw    #$0000,p_inst2
                movw    #$0000,n_nullsamp1
                movw    #$0000,sum_ave1
                movw    #$0000,n_samp1
                movw    #$0000,sum_samp1
                movw    #$0000,n_ave1
                movw    #$0000,sum_ave1
                movw    #$0000,n_nullsamp2
                movw    #$0000,sum_ave2
                movw    #$0000,n_samp2
                movw    #$0000,sum_samp2
                movw    #$0000,n_ave2
                movw    #$0000,sum_ave2
                movb    #$00,intFLG
                movw    #$0000,cost
                movb    #$00,pbtn_status
                movb    #$01,disp_no
                movw    #$0000,Iave1
                movw    #$0000,n_Iave1
                movw    #$0000,Iave2
                movw    #$0000,n_Iave2
                movw    #$0000,Pave1
                movw    #$0000,Pave2
                movw    #$0000,daily1
                movw    #$0000,daily2
                movw    #$0000,hold_count
                movw    #$0000,tcount1
                movw    #$0000,tcount2
                movw    #$0000,seconds1
                movw    #$0000,seconds2
                movw    #$0000,totE1
                movw    #$0000,totE2
                movw    #$0000,totcost1
                movw    #$0000,totcost2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
back:
                jsr     DISPLAY                         ;display proper output
check_pgm:
                brclr   pbtn_status,#$01,check_out      ;program cost if needed
                jsr     PROGRAM
check_out:
                brclr   pbtn_status,#$02,check_done     ;change/reset outlet
                jsr     OUTLET                          ;if needed
check_done:
                jmp     back                            ;repeat
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include        CNTRL_FNCTNS.inc        ;functions for flow control
#inclde         PRINT_CMNDS.inc         ;various output commands
#include        BUFF_PREP.inc           ;ascii buffer preparation
#include        LCD_cmnds.inc           ;basic LCD commands
#include        RTI_ISR.inc             ;Real Time Interrupt
#include        DATA.inc                ;output strings
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
#include        vector_table.inc
                end