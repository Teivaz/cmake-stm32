/*
Boot file for the STM32L011F4
Created by Teivaz
14.01.2020
*/

int main(void);

extern unsigned int __stack;

void __reset_handler(void) {
	main();
}
void __blocking_handler(void) { while (1); }
static void null_handler(void) {}

void Reset_Handler() __attribute__ ((weak, alias ("__reset_handler")));
void NMI_Handler() __attribute__ ((weak, alias ("null_handler")));
void HardFault_Handler() __attribute__ ((weak, alias ("__blocking_handler")));
void SVC_Handler() __attribute__ ((weak, alias ("null_handler")));
void PendSV_Handler() __attribute__ ((weak, alias ("null_handler")));
void SysTick_Handler() __attribute__ ((weak, alias ("null_handler")));
void WWDG_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void PVD_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void RTC_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void FLASH_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void RCC_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void EXTI0_1_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void EXTI2_3_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void EXTI4_15_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void DMA1_Channel1_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void DMA1_Channel2_3_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void DMA1_Channel4_5_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void ADC1_COMP_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void LPTIM1_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void TIM2_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void TIM21_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void I2C1_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void SPI1_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void USART2_IRQHandler() __attribute__ ((weak, alias ("null_handler")));
void LPUART1_IRQHandler() __attribute__ ((weak, alias ("null_handler")));

// The following section is taken from the datasheet of the MCU
__attribute__ ((section(".vectors")))
struct {
	unsigned int* initial_sp_value; // 0x00
	void (*reset)(void); // 0x04
	void (*nmi)(void); // 0x08
	void (*hard_fault)(void); // 0x0C
	void (*reserved_0x0010[7])(void); // 0x10
	void (*sv_call)(void); // 0x2C
	void (*reserved_0x0030[2])(void); // 0x30
	void (*pend_sv)(void); // 0x38
	void (*systick)(void); // 0x3C
	void (*irq[32])(void); // 0x40
} vector_table = {
	.initial_sp_value = &__stack,
	.reset = Reset_Handler,
	.nmi = NMI_Handler,
	.hard_fault = HardFault_Handler,
	.sv_call = SVC_Handler,
	.pend_sv = PendSV_Handler,
	.systick = SysTick_Handler,
	.irq = {
		[0] = WWDG_IRQHandler, // Window WatchDog
		[1] = PVD_IRQHandler, // PVD through EXTI Line detection
		[2] = RTC_IRQHandler, // RTC through the EXTI line
		[3] = FLASH_IRQHandler, // FLASH
		[4] = RCC_IRQHandler, // RCC
		[5] = EXTI0_1_IRQHandler, // EXTI Line 0 and 1
		[6] = EXTI2_3_IRQHandler, // EXTI Line 2 and 3
		[7] = EXTI4_15_IRQHandler, // EXTI Line 4 to 15
		[8] = 0, // Reserved
		[9] = DMA1_Channel1_IRQHandler, // DMA1 Channel 1
		[10] = DMA1_Channel2_3_IRQHandler, // DMA1 Channel 2 and Channel 3
		[11] = DMA1_Channel4_5_IRQHandler, // DMA1 Channel 4 and Channel 5
		[12] = ADC1_COMP_IRQHandler, // ADC1, COMP1 and COMP2
		[13] = LPTIM1_IRQHandler, // LPTIM1
		[14] = 0, // Reserved
		[15] = TIM2_IRQHandler, // TIM2
		[16] = 0, // Reserved
		[17] = 0, // Reserved
		[18] = 0, // Reserved
		[19] = 0, // Reserved
		[20] = TIM21_IRQHandler, // TIM21
		[21] = 0, // Reserved
		[22] = 0, // Reserved
		[23] = I2C1_IRQHandler, // I2C1
		[24] = 0, // Reserved
		[25] = SPI1_IRQHandler, // SPI1
		[26] = 0, // Reserved
		[27] = 0, // Reserved
		[28] = USART2_IRQHandler, // USART2
		[29] = LPUART1_IRQHandler, // LPUART1
		[30] = 0, // Reserved
		[31] = 0, // Reserved
	}
};
