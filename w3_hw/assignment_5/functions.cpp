#include "functions.hpp"

double findMed(int a[], int n) {

    int mid = n / 2;
    double median = *(a + mid)  + *(a + mid - (n % 2 == 0));
    return median / 2;
}