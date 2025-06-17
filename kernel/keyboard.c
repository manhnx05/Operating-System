#include "keyboard.h"
#include "screen.h"

char get_char_input() {
    char c = 0;
    while (c == 0) {
        asm volatile("in al, 0x60" : "=a"(c));
    }
    return c;
}

float get_float_input(const char* prompt) {
    print_string(prompt);
    
    char buffer[20];
    int index = 0;
    char c;
    
    while ((c = get_char_input()) != '\n') {
        if (c >= '0' && c <= '9' || c == '.' || c == '-') {
            print_char(c);
            buffer[index++] = c;
        }
    }
    buffer[index] = '\0';
    
    // Chuyển chuỗi thành số float
    float result = 0.0f;
    float fraction = 0.1f;
    int is_negative = 0;
    int has_decimal = 0;
    
    for (int i = 0; i < index; i++) {
        if (buffer[i] == '-') {
            is_negative = 1;
        } else if (buffer[i] == '.') {
            has_decimal = 1;
        } else {
            if (has_decimal) {
                result += (buffer[i] - '0') * fraction;
                fraction *= 0.1f;
            } else {
                result = result * 10.0f + (buffer[i] - '0');
            }
        }
    }
    
    if (is_negative) {
        result = -result;
    }
    
    return result;
}