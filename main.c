#include <stdio.h>
#define PROFILER_IMPLEMENTATION
#include <stdlib.h>
#include "profiler.h"
#include <time.h>
#include <unistd.h>

int main(void)
{
    StartMeasure("aa");
    usleep(3000000);
    EndMeasure("aa");

    StartMeasure("bb");
    usleep(2000000);
    EndMeasure("bb");

    StartMeasure("cc");
    usleep(1000000);
    EndMeasure("cc");

    StartMeasure("aa");
    usleep(3400000);
    EndMeasure("aa");

    StartMeasure("cc1");
    usleep(1000000);
    EndMeasure("cc1");

    PrintAll(stdout);
    return 0;
}