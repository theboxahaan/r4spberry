ARMGNU ?= arm-none-eabi

COPS = -nostartfiles -mfloat-abi=hard -mfpu=crypto-neon-fp-armv8 \
       -march=armv8-a+crc -mcpu=cortex-a72

all : kernel.img

clean:
	rm -f *.o
	rm -f *.bin
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.s

blinker.o : blinker.c
	$(ARMGNU)-gcc $(COPS) -c blinker.c -o blinker.o

kernel.img: blinker.o
	$(ARMGNU)-ld blinker.o -o blinker.elf
	$(ARMGNU)-objcopy blinker.elf -O binary kernel.img

blinker.s: blinker.c
	$(ARMGNU)-gcc -S  blinker.c -o blinker.s

