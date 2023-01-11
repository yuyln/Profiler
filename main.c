#include <unistd.h>

#define __PROFILER_IMPLEMENTATION
#include "profiler.h"

int main(void) {
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

    DumpMeasures(stdout);

    return 0;
}
