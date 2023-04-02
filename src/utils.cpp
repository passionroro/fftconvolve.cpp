#include "../inc/fftconvolve.hpp"

int p(const char *s) {
    std::cout << s;
    return 1;
}

bool isseparator(char c) {
    return (c == ' ' || c == ',');
}