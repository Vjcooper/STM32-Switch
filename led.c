#include"types.h"
#include"led.h"

volatile uint32 *RCC_CR = (uint32 *) RCC_CR_ADDR;
volatile uint32 *RCC_AHB1ENR = (uint32 *)RCC_AHB1ENR_ADDR;



void LED_init(void){
	*RCC_CR |= ( 1 << 0 );
	*RCC_AHB1ENR |= ( 1 << 0 );
	*RCC_AHB1ENR |= ( 1 << 6 );
	pin_config();
}

void pin_config(void){
	GPIO_G->MODER |= (1 << 26);
	GPIO_G->MODER &= ~(1 << 27);
	GPIO_G->MODER |= (1 << 28);
	GPIO_G->MODER &= ~(1 << 29);
}

void pin_out_set(uint8 pin){
	GPIO_G->BSRR |= ( 1<< pin);
}

void pin_out_reset(uint8 pin){
	GPIO_G->BSRR |= ( 1<< (pin+16));
}


uint32 get_input(void){
	uint32 temp;
	temp = (GPIO_A->IDR)&(1<<0);
	return temp;
}


void delay(void){
	uint32 i;
	for( i = 0; i < 1000000; i++ );
}
