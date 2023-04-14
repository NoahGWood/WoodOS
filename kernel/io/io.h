#ifndef __IO_H
#define __IO_H 1

#ifdef __cplusplus
extern "C" {
#endif


unsigned char inb(unsigned short);
void outb(unsigned short, unsigned char);

#ifdef __cplusplus
}
#endif


#endif