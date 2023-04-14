#include <serial/serial.h>

    int Serial::serial_received(void) {
        return (inb(COM1 + 5) & 1);
    }

    int Serial::is_empty(void) {
        return (inb(COM1 + 5) & 0x20);
    }

    void Serial::serial_write_char(char chr) {
        while(is_empty() == 0) {
            ;;
        }
        outb(COM1, chr);
    }

    void Serial::serial_write_str(char* str) {
        int i=0;
        while(str[i]) {
            serial_write_char((char)str[i]);
            i++;
        }
    }


    void Serial::Write(char* str) {
        int i=0;
        while(str[i]) {
            serial_write_char((char)str[i]);
            i++;
        }
    }

    void Serial::Write(int i) {
        while(i) {
            asm volatile ("outb %%al,%%dx": :"d" (COM1), "a" ("0123456789abcdef"[i%16]));
            i=i/16;
        }
    }

    void Serial::Write(const char* str) {
        int i=0;
        while(str[i]) {
            asm volatile ("outb %%al,%%dx": :"d" (COM1), "a" (str[i]));
            i++;
        }
    }

    void Serial::newline(){
        while(is_empty() == 0) {
            ;;
        }
        asm volatile ("outb %%al,%%dx": :"d" (COM1), "a" ('\r'));
        asm volatile ("outb %%al,%%dx": :"d" (COM1), "a" ('\n'));
    }

    void Serial::WriteLine(char* str) {
        Write(str);
        newline();
    }

    void Serial::WriteLine(int str) {
        Write(str);
        newline();
    }

    void Serial::WriteLine(const char* str) {
        Write(str);
        newline();
    }
