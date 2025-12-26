#include "core.h"
#include "ppm_writer.h"

#include <iostream>

void kindly() 
{
    PPMWriter w(256,256);
    w.write();
}

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}