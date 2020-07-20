#include<stdint.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>
#define SIZE 4096
#define GPIO_BASE 0xfe200000
#define GPFSEL4 0x4
#define GPSET1 0x8
#define GPCLR1 0xb

//#define GPFSEL1 0X04
//#define GPSET0 0X1C
//#define GPCLR0 0X28

volatile uint32_t* gpio_base;

int main()
{
	int fd;
	if((fd = open("/dev/mem", O_RDWR|O_SYNC)) < 0 )
		{
			printf("/dev/mem Not Opened \n");
			return -1;
		}
	gpio_base = (uint32_t*)mmap(NULL, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);
	printf("MMAP DONE %p \n", gpio_base);
	printf("GPFSEL4: %u\n", gpio_base[GPFSEL4]);
	gpio_base[GPFSEL4] &= ~(7 << 6);
	gpio_base[GPFSEL4] |= 1 << 6 ;
	printf("MODGPFSEL4: %d\n", gpio_base[GPFSEL4]);
	//printf("SET\n");
	while(1){
		gpio_base[GPSET1] = (1 << 10);
		sleep(1);
		gpio_base[GPCLR1] = (1 << 10);
		sleep(1);
		}
	return 0;
}


