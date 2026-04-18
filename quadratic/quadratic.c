#include "quadratic.h"
#include "screen.h"
#include "math.h"

void solve_quadratic(float a, float b, float c) {
    // Validate input
    if (a != a || b != b || c != c) { // Check for NaN
        print_string("Error: Invalid input (NaN detected)\n");
        return;
    }
    
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                print_string("Infinite solutions (all x satisfy the equation)\n");
            } else {
                print_string("No solution (contradiction)\n");
            }
        } else {
            float root = -c / b;
            print_string("Linear equation solution: x = ");
            print_float(root);
            print_string("\n");
        }
        return;
    }

    float discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        float root1 = (-b + sqrt(discriminant)) / (2*a);
        float root2 = (-b - sqrt(discriminant)) / (2*a);
        print_string("Two real roots: x1 = ");
        print_float(root1);
        print_string(", x2 = ");
        print_float(root2);
        print_string("\n");
    } else if (discriminant == 0) {
        float root = -b / (2*a);
        print_string("One real root: x = ");
        print_float(root);
        print_string("\n");
    } else {
        float real_part = -b / (2*a);
        float imag_part = sqrt(-discriminant) / (2*a);
        print_string("Complex roots: x1 = ");
        print_float(real_part);
        print_string(" + ");
        print_float(imag_part);
        print_string("i, x2 = ");
        print_float(real_part);
        print_string(" - ");
        print_float(imag_part);
        print_string("i\n");
    }
}