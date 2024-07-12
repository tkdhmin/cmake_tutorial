#include "factorial.h"
#include <iostream>


int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Factorial of " << number << " is " << factorial(number) << std::endl;
    return 0;
}