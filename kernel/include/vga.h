#define VGA 0xb8000
#define TEXT_LIM 2000
#define COLOR 0x0f

void clear_window();
void hide_cursor();
void print_hex(unsigned char hex);
void print(char * text);