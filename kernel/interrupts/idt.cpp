#include <interrupts/idt.h>

// Declare an IDT with 256 entires
struct IDT_ENTRY IDT_ARR[256];
// Declare an IDT pointer
struct IDT_PTR IDTP;

void IDT::SetGate(unsigned char num, uint16_t base, uint16_t segment,
        int ist, int gate_type, int priv, bool present,
        uint16_t mid, uint16_t high) {
            IDT_ARR[num].offset1 = base;
            IDT_ARR[num].ss = segment;
            IDT_ARR[num].ist = ist;
            IDT_ARR[num].gt=gate_type;
            IDT_ARR[num].offset2 = mid;
            IDT_ARR[num].offset3 = high;
            IDT_ARR[num].privilege=priv;
            if(present) {
                IDT_ARR[num].present=1;
            } else {
                IDT_ARR[num].present=0;
            }
}

void IDT::SetInterruptGate(unsigned char num, uint16_t base, uint16_t ss, uint16_t mid, uint16_t high){
    this->SetGate(num, base, ss, 0b000, INTERRUPT_GATE, LEVEL_0, true, mid, high);
}

void IDT::SetTrapGate(unsigned char num, uint16_t base, uint16_t ss, uint16_t mid, uint16_t high) {
    this->SetGate(num, base, ss, 0b000, TRAP_GATE, LEVEL_3, true, mid, high);
}

// void IDT::SetGate(unsigned char num, uint16_t base, uint16_t segment, uint16_t mid, uint16_t high)

void IDT::Install() {
    // Set up IDT pointer
    IDTP.limit = (sizeof(struct IDT_ENTRY)*256) - 1;
    IDTP.base = &IDT_ARR; // Point to address of our IDT array
    // Clear the entire IDT and initialize it with zeros
    //memset(&IDT, 0, sizeof(struct IDT_ENTRY)*256);

    // Add any new ISR to the IDT using IDT::SetGate();

    // Point the processor's internal register to the new IDT
    IDT::LoadIDT();
}

void IDT::LoadIDT() {
    load_idt();
}