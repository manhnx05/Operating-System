#include "screen.h"
#include "keyboard.h"
#include "quadratic.h"

void kernel_main() {
    clear_screen();
    print_string("=== Quadratic OS - Giai Phuong Trinh Bac 2 ===\n\n");
    
    print_string("Vi du: x^2 - 3x + 2 = 0\n");
    solve_quadratic(1.0f, -3.0f, 2.0f);
    
    // Vòng lặp cho phép tính nhiều lần
    while (1) {
        print_string("\n\n--- Nhap phuong trinh moi (ax^2 + bx + c = 0) ---\n");
        
        float a = get_float_input("a: ");
        float b = get_float_input("b: ");
        float c = get_float_input("c: ");
        
        print_string("\nGiai: ");
        print_float(a);
        print_string("x^2 + ");
        print_float(b);
        print_string("x + ");
        print_float(c);
        print_string(" = 0\n");
        
        solve_quadratic(a, b, c);
        
        // Hỏi có muốn tiếp tục không
        print_string("\n\nTiep tuc? (y/n): ");
        char choice = get_char_input();
        print_char(choice);
        print_char('\n');
        
        if (choice != 'y' && choice != 'Y') {
            print_string("\nCam on ban da su dung Quadratic OS!\n");
            print_string("He thong se dung lai...\n");
            break;
        }
    }
    
    // Dừng hệ thống
    for(;;);
}