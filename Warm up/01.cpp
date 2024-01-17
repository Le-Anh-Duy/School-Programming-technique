#include <iostream>

void print2ndBiggest(int a[], int n) {
    int mx = a[0], ndmx = a[1];
    if (mx < ndmx) std::swap(mx, ndmx);

    for (int i = 2; i < n; i ++) {
        if (a[i] > mx) {
            ndmx = mx;
            mx = a[i];
        } else {
            if (a[i] > ndmx && a[i] < mx)
                ndmx = a[i];
        }
    }

    if (ndmx == mx) 
        std::cout << "No second biggest element to be found"; 
    else
        std::cout << ndmx << '\n';
}

int main() {

    int n, a[100];
    std::cin >> n;
    for (int i = 0; i < n; i ++)
        std::cin >> a[i];
    print2ndBiggest(a, n);

    return 0;
}