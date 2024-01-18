#include <iostream>
#include "headers/function.hpp"

int main() {

    int n, *p, *t;
    interval *ii;
    p = new int[3];
    t = new int[3];

    input(n, p, t, ii);
    output(process(n, p, t, ii));
    return 0;
}