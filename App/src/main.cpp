#include "main.h"

#include <core/ppm_writer.h>

int main(int argc, char* argv[]) 
{
    PPMWriter w(256,256);
    w.write();
    return 0;
}