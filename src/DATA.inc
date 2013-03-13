;DATA.inc
;Lee Sichello
;A set of strings for LCD output
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
str_pgm:        fcc     'SET LOCAL COST '
                fcb     $00

str_cents:      fcc     'cents/kWh   '
                fcb     $00
                
str_voltage:    fcc     'VOLTAGE '
                fcb     $00
                
str_current:    fcc     'CURRENT '
                fcb     $00

str_power:      fcc     'POWER '
                fcb     $00

str_Pave:       fcc     'AVERAGE POWER '
                fcb     $00
                
str_daily:      fcc     'DAILY COST '
                fcb     $00

str_$:          fcc     '$'
                fcb     $00
                
str_Amps:       fcc     'Amps            '
                fcb     $00
                
str_Volts:      fcc     'Volts           '
                fcb     $00
                
str_kWh         fcc     'kWh             '
                fcb     $00
                
str_kW:         fcc     'kW              '
                fcb     #$00
                
str_NoLoad:     fcc     '**NO LOAD**'
                fcb     $00
                
str_rst:        fcc     'RESET OUTLET '
                fcb     $00

str_NoCost:	fcc	'Must Set $/kWh  '
		fcb	$00

str_below0:	fcc	'Under 1 cent '
		fcb	$00

str_tot:	fcc	'TOTAL ENERGY'
		fcb	$00

str_11spaces:	fcc	'           '
		fcb	$00

str_totcost:	fcc	'TOTAL COST'
		fcb	$00