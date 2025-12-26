#include "core.h"

#include <iostream>

void kindly() 
{
    std::cout << "Hello there" << std::endl;
}

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}