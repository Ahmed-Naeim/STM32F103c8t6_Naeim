/*
		@file	startup_stm32f10x.c
		@Author	Ahmed Naeim
        @Date 12/10/2023
		@brief	startup code for STM32F10x
*/


#define NULL 0

typedef unsigned long uint32_t;

extern uint32_t _estack, _etext, _sdata, _edata, _sbss, _ebss, _sidata;

extern int main(void);

void Reset_Handler                     (void);
void NMI_Handler                       (void) __attribute__ ((alias ("Default_Handler")));
void HardFault_Handler                 (void) __attribute__ ((alias ("Default_Handler")));
void MemManage_Handler                 (void) __attribute__ ((alias ("Default_Handler")));
void BusFault_Handler                  (void) __attribute__ ((alias ("Default_Handler")));
void UsageFault_Handler                (void) __attribute__ ((alias ("Default_Handler")));
void SVC_Handler                       (void) __attribute__ ((alias ("Default_Handler")));
void DebugMon_Handler                  (void) __attribute__ ((alias ("Default_Handler")));
void PendSV_Handler                    (void) __attribute__ ((alias ("Default_Handler")));
void SysTick_Handler                   (void) __attribute__ ((alias ("Default_Handler")));
void WWDG_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));                                        
void PVD_IRQHandler                    (void) __attribute__ ((alias ("Default_Handler")));
void TAMP_STAMP_IRQHandler             (void) __attribute__ ((alias ("Default_Handler")));
void RTC_WKUP_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void FLASH_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler"))); 
void RCC_IRQHandler                    (void) __attribute__ ((alias ("Default_Handler")));   
void EXTI0_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void EXTI1_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void EXTI2_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void EXTI3_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void EXTI4_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Stream0_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Stream1_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Stream2_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Stream3_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Stream4_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Stream5_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Stream6_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void ADC_IRQHandler                    (void) __attribute__ ((alias ("Default_Handler")));
void CAN1_TX_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void CAN1_RX0_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void CAN1_RX1_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void CAN1_SCE_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void EXTI9_5_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler     (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_CC_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM2_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM3_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM4_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void I2C1_EV_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C1_ER_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C2_EV_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C2_ER_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void SPI1_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void SPI2_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void USART1_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));
void USART2_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));
void USART3_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));
void EXTI15_10_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));
void RTC_Alarm_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));
void OTG_FS_WKUP_IRQHandler            (void) __attribute__ ((alias ("Default_Handler")));



uint32_t * const MSP_Value = (uint32_t *)&_estack;

uint32_t *Vector_Table[] __attribute__ ((section (".isr_vector"))) = {
    (uint32_t *)MSP_Value,
    (uint32_t *)&Reset_Handler,
    (uint32_t *)Reset_Handler,                     /* Reset */
    (uint32_t *)NMI_Handler,                       /* Non maskable interrupt */
    (uint32_t *)HardFault_Handler,                 /* All class of fault */
    (uint32_t *)MemManage_Handler,                 /* Memory management */
    (uint32_t *)BusFault_Handler,                  /* Pre-fetch fault, memory access fault */ 
    (uint32_t *)UsageFault_Handler,                /* Undefined instruction or illegal state */
    0,
    0,
    0,
    0,
    (uint32_t *)SVC_Handler,                       /* System service call via SWI instruction */
    (uint32_t *)DebugMon_Handler,                  /* Debug Monitor */
    0,
    (uint32_t *)PendSV_Handler,                    /* Pendable request for system service */ 
    (uint32_t *)SysTick_Handler,
    (uint32_t *)WWDG_IRQHandler,                   /* Window WatchDog              */                                        
    (uint32_t *)PVD_IRQHandler,                    /* PVD through EXTI Line detection */                        
    (uint32_t *)TAMP_STAMP_IRQHandler,             /* Tamper and TimeStamps through the EXTI line */            
    (uint32_t *)RTC_WKUP_IRQHandler,               /* RTC Wakeup through the EXTI line */                      
    (uint32_t *)FLASH_IRQHandler,                  /* FLASH                        */                                          
    (uint32_t *)RCC_IRQHandler,                    /* RCC                          */                                            
    (uint32_t *)EXTI0_IRQHandler,                  /* EXTI Line0                   */                        
    (uint32_t *)EXTI1_IRQHandler,                  /* EXTI Line1                   */                          
    (uint32_t *)EXTI2_IRQHandler,                  /* EXTI Line2                   */                          
    (uint32_t *)EXTI3_IRQHandler,                  /* EXTI Line3                   */                          
    (uint32_t *)EXTI4_IRQHandler,                  /* EXTI Line4                   */                          
    (uint32_t *)DMA1_Stream0_IRQHandler,           /* DMA1 Stream 0                */                  
    (uint32_t *)DMA1_Stream1_IRQHandler,           /* DMA1 Stream 1                */                   
    (uint32_t *)DMA1_Stream2_IRQHandler,           /* DMA1 Stream 2                */                   
    (uint32_t *)DMA1_Stream3_IRQHandler,           /* DMA1 Stream 3                */                   
    (uint32_t *)DMA1_Stream4_IRQHandler,           /* DMA1 Stream 4                */                   
    (uint32_t *)DMA1_Stream5_IRQHandler,           /* DMA1 Stream 5                */                   
    (uint32_t *)DMA1_Stream6_IRQHandler,           /* DMA1 Stream 6                */                   
    (uint32_t *)ADC_IRQHandler,                    /* ADC1, ADC2 and ADC3s         */                   
    (uint32_t *)CAN1_TX_IRQHandler,                /* CAN1 TX                      */                         
    (uint32_t *)CAN1_RX0_IRQHandler,               /* CAN1 RX0                     */                          
    (uint32_t *)CAN1_RX1_IRQHandler,               /* CAN1 RX1                     */                          
    (uint32_t *)CAN1_SCE_IRQHandler,               /* CAN1 SCE                     */                          
    (uint32_t *)EXTI9_5_IRQHandler,                /* External Line[9:5]s          */                          
    (uint32_t *)TIM1_BRK_TIM9_IRQHandler,          /* TIM1 Break and TIM9          */         
    (uint32_t *)TIM1_UP_TIM10_IRQHandler,          /* TIM1 Update and TIM10        */         
    (uint32_t *)TIM1_TRG_COM_TIM11_IRQHandler,     /* TIM1 Trigger and Commutation and TIM11 */
    (uint32_t *)TIM1_CC_IRQHandler,                /* TIM1 Capture Compare         */                          
    (uint32_t *)TIM2_IRQHandler,                   /* TIM2                         */                   
    (uint32_t *)TIM3_IRQHandler,                   /* TIM3                         */                   
    (uint32_t *)TIM4_IRQHandler,                   /* TIM4                         */                   
    (uint32_t *)I2C1_EV_IRQHandler,                /* I2C1 Event                   */                          
    (uint32_t *)I2C1_ER_IRQHandler,                /* I2C1 Error                   */                          
    (uint32_t *)I2C2_EV_IRQHandler,                /* I2C2 Event                   */                          
    (uint32_t *)I2C2_ER_IRQHandler,                /* I2C2 Error                   */                            
    (uint32_t *)SPI1_IRQHandler,                   /* SPI1                         */                   
    (uint32_t *)SPI2_IRQHandler,                   /* SPI2                         */                   
    (uint32_t *)USART1_IRQHandler,                 /* USART1                       */                   
    (uint32_t *)USART2_IRQHandler,                 /* USART2                       */                   
    (uint32_t *)USART3_IRQHandler,                 /* USART3                       */                   
    (uint32_t *)EXTI15_10_IRQHandler,              /* External Line[15:10]s        */                          
    (uint32_t *)RTC_Alarm_IRQHandler,              /* RTC Alarm (A and B) through EXTI Line */                 
    (uint32_t *)OTG_FS_WKUP_IRQHandler,            /* USB OTG FS Wakeup through EXTI line */    
};

static void System_Initialization(void)
{
    /*Clock initialization*/
}

void Reset_Handler(void){

    uint32_t Section_Size =0;
    uint32_t *MemSourceAddr = NULL;
    uint32_t *MemDestAddr = NULL;
        /* 1) Copy the data segment initializers from flash to SRAM */
    Section_Size = &_edata - &_sdata;               /* Length of .data segment */
    MemSourceAddr = (uint32_t *) &_sidata;          /* Start address of .data sengement (LMA) -> Load Memory Address */
    MemDestAddr = (uint32_t *) &_sdata;             /* Start address of .data sengement (VMA) -> Virtual Memory Address */

    	/* 2) Initialize the .bss segment with zero */
    for(uint32_t MemCounter= 0; MemCounter < Section_Size; MemCounter++)
    {
        *MemDestAddr++ = *MemSourceAddr++;
    }

    Section_Size = &_ebss - &_sbss;             /* Length of .bss segment */
    MemDestAddr = (uint32_t *) &_sbss;          /* Start address of .bss sengement */

    for(uint32_t MemCounter= 0; MemCounter < Section_Size; MemCounter++)
    {
        *MemDestAddr++ = 0;
    }
    
        /* 3) Call the system initialization function */
    System_Initialization();

        /* 4) Call the main function */
    main();





}

void Default_Handler(void){

}