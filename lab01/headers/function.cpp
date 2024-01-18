#include <iostream>
#include "function.hpp"

void clear(int* p, int* t, interval* ii) {
    delete[] p;
    delete[] t;
    delete[] ii;
}

void input(int &n, int* &p, int* &t, interval* &ii) {
    std::cin >> n;
    
    for (int i = 0; i < 3; i ++) 
        std::cin >> p[i];
    
    for (int i = 0; i < 2; i ++)
        std::cin >> t[i];

    t[2] = (1ll << 31) - 1;

    ii = new interval[n];
    for (int i = 0; i < n; i ++)
        std::cin >> ii[i].l >> ii[i].r;
}

int process(int n, int* p, int* t, interval* ii) {
    
    int ans = 0, st = 0;
    
    for (int i = 0; i < n; i ++) {
        int l = (ii + i)->l, r = (ii + i)->r;

        if (st == 0) st = l;
        int tOut = l - st;
        
        ans += (r - l) * p[0];
        
        for (int j = 0; j < 3; j ++) {
            if (tOut <= t[j]) {
                ans += p[j] * tOut;
                tOut = 0;
                break;
            }

            tOut -= t[j];
            ans += p[j] * t[j];
        }
        
        st = r;
    }   

    return ans;
}

void output(int ans) {
    std::cout << ans << '\n';
}

