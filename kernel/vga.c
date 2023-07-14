#include <io.h>
#include <vga.h>
#include <string.h>

volatile char *buf = (char *)VGA;
int pos;

void clear_window() {
    volatile char *buf = (char *)VGA;

    for (int i = 0; i < 2000; i += 2) {
        buf[i] = '\0';
        buf[i + 1] = COLOR;
    }

    pos = 0;
}

void hide_cursor(){
    port_byte_out(0x3D4, 0x0A);
    port_byte_out(0x3D5, 0x20);
}

char binary_2_ascii(char hex) {
    if (hex >= 10)
        hex = hex - 10 + 'a';
    else
        hex = hex + '0';
    return hex;
}

void print_hex(unsigned char hex) {

    buf[pos * 2] = '0';
    buf[(pos + 1) * 2] = 'x';
    
    unsigned char hex1 = hex >> 4; //First 4 bits
    buf[(pos + 2)*2] = binary_2_ascii(hex1);;

    unsigned char hex2 = hex << 4;
    hex2 = hex2 >> 4;
    buf[(pos + 3)*2] = binary_2_ascii(hex2);
    
    pos = pos + 8;

}

void print(char * text) {

    int x = strlen(text);
    int r = x + pos;
    if (r > 2000)
        return;
    for (int i = 0; i < x; i++) {
        buf[2 * (pos + i)] = text[i];
    }
    pos = r;
}