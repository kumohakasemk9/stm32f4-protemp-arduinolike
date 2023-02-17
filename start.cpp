/*
	STM32F4XX Arduino-like Project Template
	Startup script and vector table
	(C) 2023 Kumohakase
	You are free to destribute, modify without modifying this section.
	Please consider support me on kofi.com https://ko-fi.com/kumohakase
*/

#include <stm32f4xx.h>

const extern char *__stack; //Stack top
void Reset_Handler();
//Weak definition for interrupt handlers
__attribute((interrupt,weak)) void NonMaskableInt_Handler();    /*!< 2 Non Maskable Interrupt                                          */
__attribute((interrupt,weak)) void HardFault_Handler();
__attribute((interrupt,weak)) void MemoryManagement_Handler();    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
__attribute((interrupt,weak)) void BusFault_Handler();    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
__attribute((interrupt,weak)) void UsageFault_Handler();   /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
__attribute((interrupt,weak)) void SVCall_Handler();     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
__attribute((interrupt,weak)) void DebugMonitor_Handler();     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
__attribute((interrupt,weak)) void PendSV_Handler();     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
__attribute((interrupt,weak)) void SysTick_Handler();     /*!< 15 Cortex-M4 System Tick Interrupt                                */
/******  STM32 specific Interrupt Numbers **********************************************************************/
__attribute((interrupt,weak)) void WWDG_Handler();      /*!< Window WatchDog Interrupt                                         */
__attribute((interrupt,weak)) void PVD_Handler();      /*!< PVD through EXTI Line detection Interrupt                         */
__attribute((interrupt,weak)) void TAMP_STAMP_Handler();      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
__attribute((interrupt,weak)) void RTC_WKUP_Handler();      /*!< RTC Wakeup interrupt through the EXTI line                        */
__attribute((interrupt,weak)) void FLASH_Handler();      /*!< FLASH global Interrupt                                            */
__attribute((interrupt,weak)) void RCC_Handler();      /*!< RCC global Interrupt                                              */
__attribute((interrupt,weak)) void EXTI0_Handler();      /*!< EXTI Line0 Interrupt                                              */
__attribute((interrupt,weak)) void EXTI1_Handler();      /*!< EXTI Line1 Interrupt                                              */
__attribute((interrupt,weak)) void EXTI2_Handler();      /*!< EXTI Line2 Interrupt                                              */
__attribute((interrupt,weak)) void EXTI3_Handler();      /*!< EXTI Line3 Interrupt                                              */
__attribute((interrupt,weak)) void EXTI4_Handler();     /*!< EXTI Line4 Interrupt                                              */
__attribute((interrupt,weak)) void DMA1_Stream0_Handler();     /*!< DMA1 Stream 0 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA1_Stream1_Handler();     /*!< DMA1 Stream 1 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA1_Stream2_Handler();     /*!< DMA1 Stream 2 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA1_Stream3_Handler();     /*!< DMA1 Stream 3 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA1_Stream4_Handler();     /*!< DMA1 Stream 4 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA1_Stream5_Handler();     /*!< DMA1 Stream 5 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA1_Stream6_Handler();     /*!< DMA1 Stream 6 global Interrupt                                    */
__attribute((interrupt,weak)) void ADC_Handler();     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
__attribute((interrupt,weak)) void CAN1_TX_Handler();     /*!< CAN1 TX Interrupt                                                 */
__attribute((interrupt,weak)) void CAN1_RX0_Handler();     /*!< CAN1 RX0 Interrupt                                                */
__attribute((interrupt,weak)) void CAN1_RX1_Handler();     /*!< CAN1 RX1 Interrupt                                                */
__attribute((interrupt,weak)) void CAN1_SCE_Handler();     /*!< CAN1 SCE Interrupt                                                */
__attribute((interrupt,weak)) void EXTI9_5_Handler();     /*!< External Line[9:5] Interrupts                                     */
__attribute((interrupt,weak)) void TIM1_BRK_TIM9_Handler();     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
__attribute((interrupt,weak)) void TIM1_UP_TIM10_Handler();     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
__attribute((interrupt,weak)) void TIM1_TRG_COM_TIM11_Handler();     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
__attribute((interrupt,weak)) void TIM1_CC_Handler();     /*!< TIM1 Capture Compare Interrupt                                    */
__attribute((interrupt,weak)) void TIM2_Handler();     /*!< TIM2 global Interrupt                                             */
__attribute((interrupt,weak)) void TIM3_Handler();     /*!< TIM3 global Interrupt                                             */
__attribute((interrupt,weak)) void TIM4_Handler();     /*!< TIM4 global Interrupt                                             */
__attribute((interrupt,weak)) void I2C1_EV_Handler();     /*!< I2C1 Event Interrupt                                              */
__attribute((interrupt,weak)) void I2C1_ER_Handler();     /*!< I2C1 Error Interrupt                                              */
__attribute((interrupt,weak)) void I2C2_EV_Handler();     /*!< I2C2 Event Interrupt                                              */
__attribute((interrupt,weak)) void I2C2_ER_Handler();     /*!< I2C2 Error Interrupt                                              */  
__attribute((interrupt,weak)) void SPI1_Handler();     /*!< SPI1 global Interrupt                                             */
__attribute((interrupt,weak)) void SPI2_Handler();     /*!< SPI2 global Interrupt                                             */
__attribute((interrupt,weak)) void USART1_Handler();     /*!< USART1 global Interrupt                                           */
__attribute((interrupt,weak)) void USART2_Handler();     /*!< USART2 global Interrupt                                           */
__attribute((interrupt,weak)) void USART3_Handler();     /*!< USART3 global Interrupt                                           */
__attribute((interrupt,weak)) void EXTI15_10_Handler();     /*!< External Line[15:10] Interrupts                                   */
__attribute((interrupt,weak)) void RTC_Alarm_Handler();     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
__attribute((interrupt,weak)) void OTG_FS_WKUP_Handler();     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */    
__attribute((interrupt,weak)) void TIM8_BRK_TIM12_Handler();     /*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
__attribute((interrupt,weak)) void TIM8_UP_TIM13_Handler();     /*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
__attribute((interrupt,weak)) void TIM8_TRG_COM_TIM14_Handler();     /*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
__attribute((interrupt,weak)) void TIM8_CC_Handler();     /*!< TIM8 Capture Compare Interrupt                                    */
__attribute((interrupt,weak)) void DMA1_Stream7_Handler();     /*!< DMA1 Stream7 Interrupt                                            */
__attribute((interrupt,weak)) void FSMC_Handler();     /*!< FSMC global Interrupt                                             */
__attribute((interrupt,weak)) void SDIO_Handler();     /*!< SDIO global Interrupt                                             */
__attribute((interrupt,weak)) void TIM5_Handler();     /*!< TIM5 global Interrupt                                             */
__attribute((interrupt,weak)) void SPI3_Handler();     /*!< SPI3 global Interrupt                                             */
__attribute((interrupt,weak)) void UART4_Handler();     /*!< UART4 global Interrupt                                            */
__attribute((interrupt,weak)) void UART5_Handler();     /*!< UART5 global Interrupt                                            */
__attribute((interrupt,weak)) void TIM6_DAC_Handler();     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
__attribute((interrupt,weak)) void TIM7_Handler();     /*!< TIM7 global interrupt                                             */
__attribute((interrupt,weak)) void DMA2_Stream0_Handler();     /*!< DMA2 Stream 0 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA2_Stream1_Handler();     /*!< DMA2 Stream 1 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA2_Stream2_Handler();     /*!< DMA2 Stream 2 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA2_Stream3_Handler();     /*!< DMA2 Stream 3 global Interrupt                                    */
__attribute((interrupt,weak)) void DMA2_Stream4_Handler();     /*!< DMA2 Stream 4 global Interrupt                                    */
__attribute((interrupt,weak)) void ETH_Handler();     /*!< Ethernet global Interrupt                                         */
__attribute((interrupt,weak)) void ETH_WKUP_Handler();     /*!< Ethernet Wakeup through EXTI line Interrupt                       */
__attribute((interrupt,weak)) void CAN2_TX_Handler();     /*!< CAN2 TX Interrupt                                                 */
__attribute((interrupt,weak)) void CAN2_RX0_Handler();     /*!< CAN2 RX0 Interrupt                                                */
__attribute((interrupt,weak)) void CAN2_RX1_Handler();     /*!< CAN2 RX1 Interrupt                                                */
__attribute((interrupt,weak)) void CAN2_SCE_Handler();     /*!< CAN2 SCE Interrupt                                                */
__attribute((interrupt,weak)) void OTG_FS_Handler();     /*!< USB OTG FS global Interrupt                                       */
__attribute((interrupt,weak)) void DMA2_Stream5_Handler();     /*!< DMA2 Stream 5 global interrupt                                    */
__attribute((interrupt,weak)) void DMA2_Stream6_Handler();     /*!< DMA2 Stream 6 global interrupt                                    */
__attribute((interrupt,weak)) void DMA2_Stream7_Handler();     /*!< DMA2 Stream 7 global interrupt                                    */
__attribute((interrupt,weak)) void USART6_Handler();     /*!< USART6 global interrupt                                           */ 
__attribute((interrupt,weak)) void I2C3_EV_Handler();     /*!< I2C3 event interrupt                                              */
__attribute((interrupt,weak)) void I2C3_ER_Handler();     /*!< I2C3 error interrupt                                              */
__attribute((interrupt,weak)) void OTG_HS_EP1_OUT_Handler();     /*!< USB OTG HS End Point 1 Out global interrupt                       */
__attribute((interrupt,weak)) void OTG_HS_EP1_IN_Handler();     /*!< USB OTG HS End Point 1 In global interrupt                        */
__attribute((interrupt,weak)) void OTG_HS_WKUP_Handler();     /*!< USB OTG HS Wakeup through EXTI interrupt                          */
__attribute((interrupt,weak)) void OTG_HS_Handler();     /*!< USB OTG HS global interrupt                                       */
__attribute((interrupt,weak)) void DCMI_Handler();     /*!< DCMI global interrupt                                             */
__attribute((interrupt,weak)) void CRYP_Handler();     /*!< CRYP crypto global interrupt                                      */
__attribute((interrupt,weak)) void HASH_RNG_Handler();      /*!< Hash and Rng global interrupt                                     */
__attribute((interrupt,weak)) void FPU_Handler();     /*!< FPU global interrupt                                              */

//Vector table

__attribute((section(".vects"))) void (*VectorTable[])() = {
  (void (*)())__stack, //Initial stack pointer value comes first.
  Reset_Handler,
  NonMaskableInt_Handler,    
  HardFault_Handler,
  MemoryManagement_Handler,    
  BusFault_Handler,    
  UsageFault_Handler,0,0,0,0,    
  SVCall_Handler,     
  DebugMonitor_Handler,0,     
  PendSV_Handler,     
  SysTick_Handler,     
  WWDG_Handler,      
  PVD_Handler,      
  TAMP_STAMP_Handler,      
  RTC_WKUP_Handler,      
  FLASH_Handler,      
  RCC_Handler,      
  EXTI0_Handler,      
  EXTI1_Handler,      
  EXTI2_Handler,      
  EXTI3_Handler,      
  EXTI4_Handler,     
  DMA1_Stream0_Handler,     
  DMA1_Stream1_Handler,     
  DMA1_Stream2_Handler,     
  DMA1_Stream3_Handler,     
  DMA1_Stream4_Handler,     
  DMA1_Stream5_Handler,     
  DMA1_Stream6_Handler,     
  ADC_Handler,     
  CAN1_TX_Handler,     
  CAN1_RX0_Handler,     
  CAN1_RX1_Handler,     
  CAN1_SCE_Handler,     
  EXTI9_5_Handler,     
  TIM1_BRK_TIM9_Handler,     
  TIM1_UP_TIM10_Handler,     
  TIM1_TRG_COM_TIM11_Handler,     
  TIM1_CC_Handler,     
  TIM2_Handler,     
  TIM3_Handler,     
  TIM4_Handler,     
  I2C1_EV_Handler,     
  I2C1_ER_Handler,     
  I2C2_EV_Handler,     
  I2C2_ER_Handler,       
  SPI1_Handler,     
  SPI2_Handler,     
  USART1_Handler,     
  USART2_Handler,     
  USART3_Handler,     
  EXTI15_10_Handler,     
  RTC_Alarm_Handler,     
  OTG_FS_WKUP_Handler,         
  TIM8_BRK_TIM12_Handler,     
  TIM8_UP_TIM13_Handler,     
  TIM8_TRG_COM_TIM14_Handler,     
  TIM8_CC_Handler,     
  DMA1_Stream7_Handler,     
  FSMC_Handler,     
  SDIO_Handler,     
  TIM5_Handler,     
  SPI3_Handler,     
  UART4_Handler,     
  UART5_Handler,     
  TIM6_DAC_Handler,     
  TIM7_Handler,     
  DMA2_Stream0_Handler,     
  DMA2_Stream1_Handler,     
  DMA2_Stream2_Handler,     
  DMA2_Stream3_Handler,     
  DMA2_Stream4_Handler,     
  ETH_Handler,     
  ETH_WKUP_Handler,     
  CAN2_TX_Handler,     
  CAN2_RX0_Handler,     
  CAN2_RX1_Handler,     
  CAN2_SCE_Handler,     
  OTG_FS_Handler,     
  DMA2_Stream5_Handler,     
  DMA2_Stream6_Handler,     
  DMA2_Stream7_Handler,     
  USART6_Handler,      
  I2C3_EV_Handler,     
  I2C3_ER_Handler,     
  OTG_HS_EP1_OUT_Handler,     
  OTG_HS_EP1_IN_Handler,     
  OTG_HS_WKUP_Handler,     
  OTG_HS_Handler,     
  DCMI_Handler,     
  CRYP_Handler,     
  HASH_RNG_Handler,      
  FPU_Handler      
};

void Reset_Handler() {
  //SCB->VTOR = &VectorTable;
  extern char *__sbss;
  extern char *__ebss;
  extern char *__sidata;
  extern char *__sdata;
  extern char *__edata;
  extern void setup();
  extern void loop();
  char *p = __sbss; //Bss start
  char *e = __ebss; //Bss end
  char *i = __sidata; //Data start (ROM)
  /* Zero fill BSS section. */
  while(p < e) {
    *p = 0;
    p++;
  }
  p = __sdata; //Data start
  e = __edata; //Data end
  /* Copy ROM data section into RAM */
  while(p < e) {
    *p = *i;
    p++;
    i++;
  }
  setup(); //Exec once
  while(1) {loop();} //Forever
}
