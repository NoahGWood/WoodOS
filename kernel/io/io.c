/* Input a byte from a port */
unsigned char inb(unsigned short port)
{
   unsigned char ret;
   asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
   return ret;
}


/* Output a byte to a port */
void outb(unsigned short port,unsigned char data)
{
   asm volatile ("outb %%al,%%dx": :"d" (port), "a" (data));
}