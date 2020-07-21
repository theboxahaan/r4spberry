
ARMGNU ?= arm-none-eabi

COPS = -Wall -nostdlib -nostartfiles -ffreestanding -mfloat-abi=hard -mfpu=crypto-neon-fp-armv8 -march=armv8-a+crc -mcpu=cortex-a72 

all : kernel.img

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.elf
	rm -f *.list
	rm -f *.img

novectors.o : novectors.s
	$(ARMGNU)-as novectors.s -o novectors.o

blinker01.o : blinker01.c
	$(ARMGNU)-gcc $(COPS) -c blinker01.c -o blinker01.o

kernel.img : novectors.o blinker01.o 
	$(ARMGNU)-ld novectors.o blinker01.o -o blinker01.elf
	$(ARMGNU)-objdump -D blinker01.elf > blinker01.list
	$(ARMGNU)-objcopy blinker01.elf -O binary kernel.img






