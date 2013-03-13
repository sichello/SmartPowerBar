; ----------------------------------------------------
; This vector table is intended for use with code
; downloaded into Flash using the resident bootloader
; in the Dragon12 board.
; ------------------ VECTOR TABLE --------------------
        org        $EF8C
        fdb        Handler_0		;$EF8C: PWM emergency shutdown
        fdb        Handler_0		;$EF8E: PortP
        fdb        Handler_0		;$EF90: CAN4TX
        fdb        Handler_0		;$EF92: CAN4RX
        fdb        Handler_0		;$EF94: CAN4ERR
        fdb        Handler_0		;$EF96: CAN4WU
        fdb        Handler_0		;$EF98: CAN3TX
        fdb        Handler_0		;$EF9A: CAN3RX
        fdb        Handler_0		;$EF9C: CAN3ERR
        fdb        Handler_0		;$EF9E: CAN3WU
        fdb        Handler_0		;$EFA0: CAN2TX
        fdb        Handler_0		;$EFA2: CAN2RX
        fdb        Handler_0		;$EFA4: CAN2ERR
        fdb        Handler_0		;$EFA6: CAN2WU
        fdb        Handler_0		;$EFA8: CAN1TX
        fdb        Handler_0		;$EFAA: CAN1RX
        fdb        Handler_0		;$EFAC: CAN1ERR
        fdb        Handler_0		;$EFAE: CAN1WU
        fdb        Handler_0		;$EFB0: CAN0TX
        fdb        Handler_0		;$EFB2: CAN0RX
        fdb        Handler_0		;$EFB4: CAN0ERR
        fdb        Handler_0		;$EFB6: CAN0WU
        fdb        Handler_0		;$EFB8: FLASH
        fdb        Handler_0		;$EFBA: EEPROM
        fdb        Handler_0		;$EFBC: SPI2
        fdb        Handler_0		;$EFBE: SPI1
        fdb        Handler_0		;$EFC0: IIC Bus
        fdb        Handler_0		;$EFC2: BDLC
        fdb        Handler_0		;$EFC4: CRG self-clock-mode
        fdb        Handler_0		;$EFC6: CRG PLL Lock
        fdb        Handler_0		;$EFC8: Pulse Accumulator B Overflow
        fdb        Handler_0		;$EFCA: Modulus Down Counter underflow
        fdb        Handler_0		;$EFCC: PORTH
        fdb        Handler_0		;$EFCE: PORTJ
        fdb        Handler_0		;$EFD0: ATD1
        fdb        Handler_0		;$EFD2: ATD0
        fdb        Handler_0		;$EFD4: SCI1 Serial System
        fdb        Handler_0		;$EFD6: SCI0 Serial System
        fdb        Handler_0		;$EFD8: SPI0
        fdb        Handler_0		;$EFDA: Pulse Accumulator Input Edge
        fdb        Handler_0		;$EFDC: Pulse Accumulator A Overflow
        fdb        Handler_0		;$EFDE: Enhanced Capture Timer Overflow
        fdb        Handler_0		;$EFE0: Enhanced Capture Timer Channel 7
        fdb        Handler_0		;$EFE2: Enhanced Capture Timer Channel 6
        fdb        Handler_0		;$EFE4: Enhanced Capture Timer Channel 5
        fdb        Handler_0		;$EFE6: Enhanced Capture Timer Channel 4
        fdb        Handler_0		;$EFE8: Enhanced Capture Timer Channel 3
        fdb        Handler_0		;$EFEA: Enhanced Capture Timer Channel 2
        fdb        Handler_0		;$EFEC: Enhanced Capture Timer Channel 1
        fdb        Handler_0		;$EFEE: Enhanced Capture Timer Channel 0
        fdb        RTI_ISR		;$EFF0: Real Time Interrupt (RTI)
        fdb        Handler_0		;$EFF2: IRQ
        fdb        Handler_0		;$EFF4: XIRQ
        fdb        Handler_0		;$EFF6: Software Interrupt (SWI)
        fdb        Handler_0		;$EFF8: Illegal Instruction Trap
        fdb        start		;$EFFA: COP Failure Reset
        fdb        Handler_0		;$EFFC: Clock Monitor Fail Reset
        fdb        start		;$EFFE: /RESET