
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );

#define GPFSEL4 0xFE200010
#define GPSET1 0xFE200020
#define GPCLR1 0XFE20002C
//-------------------------------------------------------------------------
int notmain ( void )
{
    unsigned int ra;

    ra=GET32(GPFSEL4);
    ra&=~(7<<6);
    ra|=1<<6;
    PUT32(GPFSEL4,ra);

    while(1)
    {
        PUT32(GPSET1,1<<10);
        for(ra=0;ra<0x100000;ra++) dummy(ra);
        PUT32(GPCLR1,1<<10);
        for(ra=0;ra<0x100000;ra++) dummy(ra);
    }
    return(0);
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
