#define GPIO_BASE 0xfe200000
#define GPFSEL4 0x4
#define GPSET1 0x8
#define GPCLR1 0xb


volatile unsigned int* gpio_base = (unsigned int*)GPIO_BASE;

volatile unsigned int time;
int main(void) __attribute__((naked));
int main(void)
{
	gpio_base[GPFSEL4] &= ~(7 << 6);
	gpio_base[GPFSEL4] |= (1 << 6);
	while(1)
	{
		for(time=0; time<50000; time++);
		gpio_base[GPSET1] = (1<<10);
		
		for(time=0; time<50000; time++);
		gpio_base[GPCLR1] = (1<<10);

	}


}

