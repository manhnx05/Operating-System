#include "quadratic.h"
#include "screen.h"
#include "math.h"

void solve_quadratic(float a, float b, float c) {
    // Validate input
    if (a != a || b != b || c != c) { // Check for NaN
        set_color(COLOR_LIGHT_RED, COLOR_BLACK);
        print_string("Error: Invalid input (NaN detected)\n");
        set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
        return;
    }
    
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
                print_string("Infinite solutions (all x satisfy the equation)\n");
                set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
            } else {
                set_color(COLOR_LIGHT_RED, COLOR_BLACK);
                print_string("No solution (contradiction)\n");
                set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
            }
        } else {
            float root = -c / b;
            set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
            print_string("Linear equation solution: ");
            set_color(COLOR_WHITE, COLOR_BLACK);
            print_string("x = ");
            print_float(root);
            print_string("\n");
            set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
        }
        return;
    }

    float discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        float root1 = (-b + sqrt(discriminant)) / (2*a);
        float root2 = (-b - sqrt(discriminant)) / (2*a);
        set_color(COLOR_LIGHT_GREEN, COLOR_BLACK);
        print_string("Two real roots: ");
        set_color(COLOR_WHITE, COLOR_BLACK);
        print_string("x1 = ");
        print_float(root1);
        print_string(", x2 = ");
        print_float(root2);
        print_string("\n");
        set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    } else if (discriminant == 0) {
        float root = -b / (2*a);
        set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
        print_string("One real root: ");
        set_color(COLOR_WHITE, COLOR_BLACK);
        print_string("x = ");
        print_float(root);
        print_string("\n");
        set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    } else {
        float real_part = -b / (2*a);
        float imag_part = sqrt(-discriminant) / (2*a);
        set_color(COLOR_LIGHT_MAGENTA, COLOR_BLACK);
        print_string("Complex roots: ");
        set_color(COLOR_WHITE, COLOR_BLACK);
        print_string("x1 = ");
        print_float(real_part);
        print_string(" + ");
        print_float(imag_part);
        print_string("i, x2 = ");
        print_float(real_part);
        print_string(" - ");
        print_float(imag_part);
        print_string("i\n");
        set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    }
}