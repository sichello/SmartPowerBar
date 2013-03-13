;rti interrupts initialized here

init_intrpt:
                movb    #%01000000,RTICTL       ;set RTICLOCK to 2^13osclks , or 1ms
                bset    CRGINT,#$80            ;enable RTI locally
                cli                         ;enable interrupt globally