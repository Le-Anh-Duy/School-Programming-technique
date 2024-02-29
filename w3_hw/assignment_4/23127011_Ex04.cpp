#include <iostream>
#include "functions.hpp"

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 3};
    std::cout << findMode(arr, 7);
    return 0;
}