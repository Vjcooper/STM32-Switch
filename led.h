#ifndef _LED_H_
#define _LED_H_

#include"types.h"


#define RCC_BASE 0x40023800

#define RCC_CR_ADDR (RCC_BASE)
#define RCC_AHB1ENR_ADDR ( RCC_BASE + 0x30 )

#define GPIO_G_BASE 0x40021800
#define GPIO_A_BASE 0x40020000

typedef struct{
	volatile 				uint32 MODER;
	volatile 				uint32 OTYPER;
	volatile				uint32 OSPEEDR;
	volatile				uint32 PUPDR;
	volatile const 	uint32 IDR;
	volatile 				uint32 ODR;
	volatile 				uint32 BSRR;
	volatile 				uint32 LCKR;
	volatile 				uint32 AFRL;
	volatile 				uint32 AFRH;
	
}_GPIO;

#define GPIO_G ((_GPIO *) GPIO_G_BASE)
#define GPIO_A ((_GPIO *) GPIO_A_BASE)

void delay(void);

void LED_init(void);
void pin_config(void);

void pin_out_set(uint8);
void pin_out_reset(uint8);
uint32 get_input(void);

extern volatile uint32 *RCC_CR;
extern volatile uint32 *RCC_AHB1ENR;

#endif /* _LED_H_ */
