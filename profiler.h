#ifndef __PROFILER
#define __PROFILER
#if _POSIX_C_SOURCE < 199309L
#define _POSIX_C_SOURCE 199310L
#endif

#define PROFILER_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

    typedef struct Node
    {
        char *name;
        size_t i;
        struct timespec T1, T2;
        double dt;
        struct Node *n;
    } Node;

    static Node *nodes = NULL;
    static size_t i = 0;

    size_t StartMeasure(const char *name);
    double EndMeasure(const char *name);
    void PrintAll();

#ifdef __cplusplus
}
#endif

#endif

#ifdef PROFILER_IMPLEMENTATION
size_t StartMeasure(const char *name)
{
    if (i == 0)
    {
        nodes = (Node*)malloc(sizeof(Node));
        nodes->i = 0;
        nodes->name = (char*)name;
        clock_gettime(CLOCK_REALTIME, &nodes->T1);
        nodes->n = NULL;
        nodes->dt = 0.0;
        return i++;
    }


    Node *p = (Node*)malloc(sizeof(Node));
    p->name = (char*) name;
    p->i = i;
    p->n = NULL;
    p->dt = 0.0;
    clock_gettime(CLOCK_REALTIME, &p->T1);

    Node *p1 = nodes;

    while (p1->n != NULL)
    {
        p1 = p1->n;
    }
    p1->n = p;
    return i++;
}

double EndMeasure(const char *name)
{
    Node *p = nodes;
    while (p != NULL)
    {
        int r = strcmp(p->name, name);
        if (r != 0)
        {
            p = p->n;
            continue;
        }
        clock_gettime(CLOCK_REALTIME, &p->T2);
        break;
    }
    int dts = p->T2.tv_sec - p->T1.tv_sec;
    int dtns = p->T2.tv_nsec - p->T1.tv_nsec;
    p->dt = (double)dts + (double)dtns / 1.0e9;
    return p->dt;
}

void PrintAll()
{
    Node *p = nodes;
    while (p != NULL)
    {
        printf("[ %s ] -> [ %.9f ] seg\n", p->name, p->dt);
        p = p->n;
    }
}

#endif