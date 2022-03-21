;/*******************************************************************************
;* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
;*
;* This software is owned and published by:
;* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
;*
;* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
;* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
;*
;* This software contains source code for use with CMS
;* components. This software is licensed by CMS to be adapted only
;* for use in systems utilizing CMS components. CMS shall not be
;* responsible for misuse or illegal use of this software for devices not
;* supported herein. CMS is providing this software "AS IS" and will
;* not be responsible for issues arising from incorrect user implementation
;* of the software.
;*
;* This software may be replicated in part or whole for the licensed use,
;* with the restriction that this Disclaimer and Copyright notice must be
;* included with each copy of this software, whether used in part or whole,
;* at all times.
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000800

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp

; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp            ; Top of Stack
                DCD     Reset_Handler           ; Reset Handler
                DCD     NMI_Handler             ; NMI Handler
                DCD     HardFault_Handler       ; Hard Fault Handler
                DCD     0                       ; Reserved
                DCD     0                       ; Reserved
                DCD     0                       ; Reserved
                DCD     0                       ; Reserved
                DCD     0                       ; Reserved
                DCD     0                       ; Reserved
                DCD     0                       ; Reserved
                DCD     SVC_Handler             ; SVCall Handler
                DCD     0                       ; Reserved
                DCD     0                       ; Reserved
                DCD     PendSV_Handler          ; PendSV Handler
                DCD     SysTick_Handler         ; SysTick Handler

                ; External Interrupts
                ; maximum of 32 External Interrupts are possible
                DCD     GPIO0_IRQHandler        ;  0: GPIO P0 interrupt
                DCD     GPIO1_IRQHandler        ;  1: GPIO P1 interrupt
                DCD     GPIO2_IRQHandler        ;  2: GPIO P2 interrupt
                DCD     GPIO3_IRQHandler        ;  3: GPIO P3 interrupt
                DCD     GPIO4_IRQHandler       	;  4: GPIO P4 interrupt
                DCD     Default_Handler         ;  5: Reserved
                DCD     CCP_IRQHandler      	;  6: Capture/PWM interrupt
                DCD     ADC0_IRQHandler       	;  7: ADC 0 interrupt
                DCD     Default_Handler         ;  8: Reserved
                DCD     WWDT_IRQHandler         ;  9: WWDT interrupt
                DCD     EPWM_IRQHandler         ; 10: EPWM interrupt	
                DCD     Default_Handler         ; 11: Reserved
                DCD     ADC1_IRQHandler         ; 12: ADC 1 interrupt	
                DCD     ACMP_IRQHandler         ; 13: ACMP interrupt	
                DCD     Default_Handler         ; 14: Reserved
                DCD     UART0_IRQHandler        ; 15: UART 0 interrupt	
                DCD     UART1_IRQHandler        ; 16: UART 1 interrupt	
                DCD     Default_Handler         ; 17: Reserved
                DCD     Default_Handler         ; 18: Reserved
                DCD     TMR0_IRQHandler     	; 19: TIMER 0 interrupt	
                DCD     TMR1_IRQHandler         ; 20: TIMER 1 interrupt	
                DCD     Default_Handler         ; 21: Reserved
                DCD     Default_Handler         ; 22: Reserved
                DCD     WDT_IRQHandler       	; 23: WDT  interrupt	
                DCD     I2C_IRQHandler       	; 24: I2C  interrupt	
                DCD     Default_Handler         ; 25: Reserved
                DCD     SPI_IRQHandler       	; 26: SPI interrupt	
                DCD     Default_Handler         ; 27: Reserved
                DCD     Default_Handler         ; 28: Reserved
                DCD     Default_Handler         ; 29: Reserved
                DCD     Default_Handler         ; 30: Reserved
                DCD     LVD_IRQHandler       	; 31: LVD interrupt	

                AREA    |.text|, CODE, READONLY

; Reset Handler

               
Reset_Handler   PROC
                EXPORT  Reset_Handler           [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler             [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler       [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler             [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler          [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler         [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  GPIO0_IRQHandler        [WEAK]
                EXPORT  GPIO1_IRQHandler        [WEAK]
                EXPORT  GPIO2_IRQHandler        [WEAK]
                EXPORT  GPIO3_IRQHandler        [WEAK]
                EXPORT  GPIO4_IRQHandler        [WEAK]
                EXPORT  CCP_IRQHandler          [WEAK]
                EXPORT  ADC0_IRQHandler       	[WEAK]
                EXPORT  WWDT_IRQHandler       	[WEAK]
                EXPORT  EPWM_IRQHandler        	[WEAK]
                EXPORT  ADC1_IRQHandler        	[WEAK]
                EXPORT  ACMP_IRQHandler         [WEAK]
                EXPORT  UART0_IRQHandler        [WEAK]
                EXPORT  UART1_IRQHandler    	[WEAK]
                EXPORT  TMR0_IRQHandler         [WEAK]
                EXPORT  TMR1_IRQHandler         [WEAK]
                EXPORT  WDT_IRQHandler         	[WEAK]
                EXPORT  I2C_IRQHandler        	[WEAK]
                EXPORT  SPI_IRQHandler        	[WEAK]
                EXPORT  LVD_IRQHandler        	[WEAK]

GPIO0_IRQHandler        
GPIO1_IRQHandler      
GPIO2_IRQHandler        
GPIO3_IRQHandler        
GPIO4_IRQHandler        
CCP_IRQHandler         
ADC0_IRQHandler       
WWDT_IRQHandler       	
EPWM_IRQHandler        
ADC1_IRQHandler        
ACMP_IRQHandler         
UART0_IRQHandler        
UART1_IRQHandler    	
TMR0_IRQHandler        
TMR1_IRQHandler         
WDT_IRQHandler         
I2C_IRQHandler        
SPI_IRQHandler        	
LVD_IRQHandler        	

                B       .
                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, = (Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF

                END
