#ifndef __IDT_H
#define __IDT_H 1

    #ifndef _LIMINE_H
        #include <limine.h>
    #endif

#ifdef __cplusplus
extern "C" {
#endif

// This exists in 'interrupts.S', and is used to load our IDT.
extern void load_idt();

#define INTERRUPT_GATE 0xE
#define TRAP_GATE 0xF
#define LEVEL_0 0b00
#define LEVEL_1 0b01
#define LEVEL_2 0b10
#define LEVEL_3 0b11

struct IDT_ENTRY {
    uint16_t offset1;
    uint16_t ss; // Segment selector
    int ist:3; // Interrupt stack table offset, set 0 if unused
    int reserved1:5;
    int gt:4; // Gate Type (interrupt or trap)
    int reserved2:1; // unused
    int privilege:2; // CPU privilege levels
    int present:1;
    uint16_t offset2;
    uint32_t offset3;
    uint32_t reserved3;
} __attribute__((packed));

struct IDT_PTR {
    uint16_t limit;
    void* base;
} __attribute__((packed));

#ifdef __cplusplus
}
#endif

class IDT { 
    private:
        void LoadIDT();
    public:
        void SetGate(unsigned char num, uint16_t base, uint16_t segment, int ist, int gate_type, int priv, bool present, uint16_t mid, uint16_t high);
        void SetInterruptGate(unsigned char num, uint16_t base, uint16_t ss, uint16_t mid, uint16_t high);
        void SetTrapGate(unsigned char num, uint16_t base, uint16_t ss, uint16_t mid, uint16_t high);

        void Install();
};

#endif