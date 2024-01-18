#include <iostream>

struct interval {
    int l, r;
};

void input(int &n, int* &p, int* &t, interval* &ii);
int process(int n, int* p, int* t, interval* ii);
void output(int ans);
void clear();