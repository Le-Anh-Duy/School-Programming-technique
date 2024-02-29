#include <iostream>
#include "palindrome.hpp"

int main() {
    char* testStr = "abcd";
    char* testStr2 = "abcdcba";

    std::cout << isPalindrome(testStr2) << " " << isPalindrome(testStr);

}