#include "functions.hpp"

int findMode(int a[], int n) {

    if (n < 1) return -1;
    int mode = 0, max = 0;

    for (int i = 0; i < n; i ++) {
        int v = *(a + i);
        if (max < v) max = v;
    }

    int* cnt = new int[max + 1]();
    max = 0;

    for (int i = 0; i < n; i ++) {
        int v = *(a + i);
        int c = (*(cnt + v)) ++;

        if (c > max) {
            mode = v;
            max = c;
        }
    }

    delete[] cnt;

    return mode;
}