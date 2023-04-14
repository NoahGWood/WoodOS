#ifndef __ISR_H
#define __ISR_H 1

    #ifndef _LIMINE_H
        #include <limine.h>
    #endif

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((noreturn))
void exception_handler(void);

#ifdef __cplusplus
}
#endif


#endif