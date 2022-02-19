#ifndef __PROFILER
#define __PROFILER
#define PROFILER_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __cplusplus
extern "C"{
#endif

    typedef struct 
    {
        char *name;
        size_t i;
        struct timespec T1, T2;
        Node *n;
    } Node;

    static Node *nodes;

    size_t StartMeasure(const char *name);

#ifdef __cplusplus
}
#endif

#endif

#ifdef PROFILER_IMPLEMENTATION
size_t StartMeasure(const char *name)
{

}
#endif