;buff_prep.inc
;Lee Sichello
;prepares buffers with various amounts of decimal places in ASCII for LCD output


prep_1dp_buff:  pshx                    ;expects value to convert in d , beginning of 6 bit buffer address in y
                pshy
                pshd

                ldx     #100           ;
                idiv                    ;d/x->x , rem->d
                pshd
                cpx     #$0000
                beq     div_10
                xgdx
                addb    #$30          ;convert d to ascii
                stab    0,Y
                iny
div_10:
                puld
                ldx     #10            ;
                idiv                    ;d/x->x , rem->d
                pshd
                xgdx
                addb    #$30          ;convert d to ascii
                stab    0,Y

                ldaa    #46                    ;decimal point
                staa    1,Y

                puld
                addb    #$30
                stab    2,Y

                ldaa    #$20                    ;space character
                staa    3,Y

                ldaa    #$00                    ;null character
                staa    4,Y

                puld
                puly
                pulx
                rts

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
prep_2dp_buff:  pshx                    ;expects value to convert in d , beginning of 6 bit buffer address in y
                pshy
                pshd

                ldx     #10000           ;
                idiv                    ;d/x->x , rem->d
                pshd
                cpx     #$0000
                beq     div_1000
                xgdx
                addb    #$30          ;convert d to ascii
                stab    0,Y
                iny
div_1000:
                puld
                ldx     #1000            ;
                idiv                    ;d/x->x , rem->d
                pshd
                xgdx
                addb    #$30          ;convert d to ascii
                stab    0,Y

                ldaa    #46                    ;decimal point
                staa    1,Y

                puld
                ldx     #100
                idiv                  ;(10xrem)/51->x (first didgit of fraction), rem->d
                pshd
                xgdx
                addb    #$30
                stab    2,Y

                puld
                ldx     #10
                idiv
                xgdx
                addb    #$30
                stab    3,Y

                ldaa    #$20                    ;space character
                staa    4,Y

                ldaa    #$00                    ;null character
                staa    5,Y

                puld
                puly
                pulx
                rts
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
prep_3dp_buff:  pshx                    ;expects value to convert in d , beginning of 6 bit buffer address in y
                pshy
                pshd

                ldx     #1000            ;
                idiv                    ;d/x->x , rem->d
                pshd
                xgdx
                addb    #$30          ;convert d to ascii
                stab    0,Y

                ldaa    #46                    ;decimal point
                staa    1,Y

                puld
                ldx     #100
                idiv                  ;(10xrem)/51->x (first didgit of fraction), rem->d
                pshd
                xgdx
                addb    #$30
                stab    2,Y

                puld
                ldx     #10
                idiv
                pshd
                xgdx
                addb    #$30
                stab    3,Y
                
                puld
                addb    #$30
                stab    4,Y

                ldaa    #$20                    ;space character
                staa    5,Y

                ldaa    #$00                    ;null character
                staa    6,Y

                puld
                puly
                pulx
                rts