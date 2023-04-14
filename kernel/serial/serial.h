#ifndef __SERIAL_H
#define __SERIAL_H 1

    #ifndef __STDDEF_H
        #include <stddef.h>
    #endif

    #ifndef __STD_INT_H
        #include <stdint.h>
    #endif

    #ifndef __STDBOOL_H
        #include <stdbool.h>
    #endif

    #ifdef __cplusplus

    extern "C" {
    #endif
    #include <io/io.h>
        #define COM1 0x3F8
        #define COM2 0x2F8
        #define COM3 0x3E8
        #define COM4 0x2E8
        
        #define BASH_RED "\033[31m"
        #define BASH_CYAN "\033[36m"
        #define BASH_GREEN "\033[32m"
        #define BASH_WHITE "\033[97m"
        #define BASH_GRAY "\033[37m"
        #define BASH_PURPLE "\033[35m"
        #define BASH_YELLOW "\033[93m"
        #define BASH_DEFAULT "\033[39m"


    #ifdef __cplusplus
    }
    #endif


class Serial
{
private:
    static int serial_received(void);
    int is_empty(void);
    void serial_write_char(char);
    void serial_write_str(char*);
    /* data */
public:
    Serial(/* args */){};
    ~Serial(){};
    void Write(char*);
    void Write(int);
    void Write(const char*);
    void newline();
    void WriteLine(char*);
    void WriteLine(const char* str);
    void WriteLine(int);

};
#endif