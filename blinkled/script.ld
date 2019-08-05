/* SPDX-License-Identifier: BSD 2-Clause
 * 
 * blink/script.ld
 *
 * Copyright (C) 2019 Pierre Morel
 *
 * Test program for STM32F103RB
 * - script for blinking green LED
 */

MEMORY
{
	FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
	SRAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 20K
}
 
SECTIONS
{
	.text :
	{
		*(.vector_table)
		*(.text)
	} >FLASH
 
	.data :
	{
		*(.data)            
	} >SRAM
}

