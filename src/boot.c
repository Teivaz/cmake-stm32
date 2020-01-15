/*
Boot file for the STM32L011F4
Created by Teivaz
14.01.2020
*/

int main(void);

void __attribute__ ((weak, naked)) reset_handler(void) {
		main();
}
void blocking_handler(void) { while (1); }
void null_handler(void) {}
extern unsigned int _stack;

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
	.initial_sp_value = &_stack,
	.reset = reset_handler,
	.nmi = null_handler,
	.hard_fault = blocking_handler,
	.sv_call = null_handler,
	.pend_sv = null_handler,
	.systick = null_handler,
	.irq = {
		null_handler, //Window WatchDog
		null_handler, //PVD through EXTI Line detection
		null_handler, //RTC through the EXTI line
		null_handler, //FLASH
		null_handler, //RCC
		null_handler, //EXTI Line 0 and 1
		null_handler, //EXTI Line 2 and 3
		null_handler, //EXTI Line 4 to 15
		null_handler, //Reserved
		null_handler, //DMA1 Channel 1
		null_handler, //DMA1 Channel 2 and Channel 3
		null_handler, //DMA1 Channel 4 and Channel 5
		null_handler, //ADC1, COMP1 and COMP2
		null_handler, //LPTIM1
		null_handler, //Reserved
		null_handler, //TIM2
		null_handler, //Reserved
		null_handler, //Reserved
		null_handler, //Reserved
		null_handler, //Reserved
		null_handler, //TIM21
		null_handler, //Reserved
		null_handler, //Reserved
		null_handler, //I2C1
		null_handler, //Reserved
		null_handler, //SPI1
		null_handler, //Reserved
		null_handler, //Reserved
		null_handler, //USART2
		null_handler, //LPUART1
		null_handler, //Reserved
		null_handler, //Reserved
	}
};
