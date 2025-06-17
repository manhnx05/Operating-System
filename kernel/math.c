#include "math.h"

float abs(float x) {
    return x < 0 ? -x : x;
}

float pow(float x, int n) {
    float result = 1.0f;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

float sqrt(float x) {
    if (x < 0) return 0;
    
    float guess = x / 2.0f;
    for (int i = 0; i < 10; i++) {
        guess = (guess + x / guess) / 2.0f;
    }
    return guess;
}