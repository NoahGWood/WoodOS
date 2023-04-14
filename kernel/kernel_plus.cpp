#include "kernel_plus.h"
#include <serial/serial.h>
#include <interrupts/idt.h>

void setup_idt() {
    Serial serial = Serial();
    IDT idt = IDT();
    serial.WriteLine("Setting Up IDT..");
    idt.Install();
    serial.WriteLine("IDT Setup Completed.");
}

void setup_memory(struct limine_memmap_response* mmap) {
    Serial serial = Serial();
    serial.Write("THIS IS A TEST!");
    serial.Write("Count: ");
    serial.WriteLine(mmap->entry_count);
    for(uint64_t i=0; i<mmap->entry_count; i++) {
        struct limine_memmap_entry* entry = mmap->entries[i];
        switch(entry->type) {
            case LIMINE_MEMMAP_USABLE:
                serial.newline();
                serial.Write(entry->base);
                break;
            case LIMINE_MEMMAP_RESERVED:
                break;
            case LIMINE_MEMMAP_ACPI_RECLAIMABLE:
                break;
            case LIMINE_MEMMAP_ACPI_NVS:
                break;
            case LIMINE_MEMMAP_BAD_MEMORY:
                break;
            case LIMINE_MEMMAP_BOOTLOADER_RECLAIMABLE:
                break;
            case LIMINE_MEMMAP_KERNEL_AND_MODULES:
                break;
            case LIMINE_MEMMAP_FRAMEBUFFER:
                break;
            default:
                break;
        }
    }
}