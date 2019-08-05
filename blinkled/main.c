// SPDX-License-Identifier: BSD 2-Clause
/*
 * blink/main.c
 *
 * Copyright (C) 2019 Pierre Morel
 *
 * Test program for STM32F103RB
 * - blinking green LED
 */

#define SRAM_BASE	0x20000000
#define SRAM_SIZE	20 * 1024
#define STACK		(SRAM_BASE + SRAM_SIZE)

#define PERIPH_BASE	0x40000000

#define RCC_BASE	(PERIPH_BASE + 0x21000)
#define RCC_APB2ENR	(*(volatile unsigned long *)(RCC_BASE + 0x18))

#define GPIOA_BASE	(PERIPH_BASE + 0x10800)
#define GPIOA_CRL	(*(volatile unsigned long *)(GPIOA_BASE + 0x00))
#define GPIOA_BSRR	(*(volatile unsigned long *)(GPIOA_BASE + 0x10))

/* Green LED is connected to GPIO A pin 5 */
#define LED_PIN		5

void delay(unsigned long ms)
{
	for (unsigned long j = 0; j < 1000UL * ms; j++) {
		__asm__("nop");
	};
}

int main()
{
	/* Activate GPIO A */
	RCC_APB2ENR |= 0x04;
	/* Set GPIO A PIN to output push-pull */
	GPIOA_CRL = (0x0|0x3) << ((LED_PIN) << 2);

	while (1) {
		/* Turn GPIO PIN ON */
		GPIOA_BSRR = 1 << LED_PIN;
		delay(500);
		/* Turn GPIO PIN OFF */
		GPIOA_BSRR = (1 << LED_PIN) << 16;
		delay(500);
	}
}

unsigned long *vector_table[] __attribute__((section(".vector_table"))) =
{
	(unsigned long *)STACK,
	(unsigned long *)main
};

