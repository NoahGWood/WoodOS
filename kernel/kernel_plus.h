#ifndef __KPP_H
#define __KPP_H 1
    #ifndef _LIMINE_H
        #include <limine.h>
    #endif

#ifdef __cplusplus
extern "C" {
#endif

extern void setup_idt();

extern void setup_memory(struct limine_memmap_response * mmap);

#ifdef __cplusplus
}
#endif


#endif