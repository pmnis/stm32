# SPDX-License-Identifier: BSD 2-Clause 

CROSS_COMPILE = arm-linux-

CC	= $(CROSS_COMPILE)gcc
LD	= $(CROSS_COMPILE)ld
OBJCOPY	= $(CROSS_COMPILE)objcopy
 
CFLAGS	= -c -g -fno-common -Os -mcpu=cortex-m3 -mthumb
LFLAGS	= -nostartfiles -Tscript.ld

main.bin: main.elf
	$(OBJCOPY) -O binary main.elf main.bin
 
main.elf: main.o
	$(LD) $(LFLAGS) -o main.elf main.o
 
main.o: main.c
	$(CC) $(CFLAGS) -o main.o main.c
 
clean:
	rm -rf *.o *.elf *.bin
 
