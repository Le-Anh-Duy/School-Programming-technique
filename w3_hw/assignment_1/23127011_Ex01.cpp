#include "functions.hpp"
#include <iostream>

int main() {
    int* x, y = 1;
    x = &y;
    addOne(x);

    std::cout << y;
    return 0;
}