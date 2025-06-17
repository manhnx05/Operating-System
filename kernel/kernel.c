#include "screen.h"
#include "keyboard.h"
#include "quadratic.h"

void kernel_main() {
    clear_screen();
    print_string("Quadratic OS Kernel Loaded!\n\n");
    
    print_string("Example equation: x^2 - 3x + 2 = 0\n");
    solve_quadratic(1.0f, -3.0f, 2.0f);
    
    print_string("\n\nEnter your own equation (ax^2 + bx + c = 0):\n");
    float a = get_float_input("a: ");
    float b = get_float_input("b: ");
    float c = get_float_input("c: ");
    
    print_string("\nSolving: ");
    print_float(a);
    print_string("x^2 + ");
    print_float(b);
    print_string("x + ");
    print_float(c);
    print_string(" = 0\n");
    
    solve_quadratic(a, b, c);
    
    // Dừng hệ thống
    for(;;);
}