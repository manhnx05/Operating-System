#ifndef SCREEN_H
#define SCREEN_H

void clear_screen();
void print_char(char c);
void print_string(const char* str);
void print_float(float f);
void print_int(int n);
void set_cursor_position(int x, int y);

#endif