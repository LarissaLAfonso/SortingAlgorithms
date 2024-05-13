#ifndef _EVALSORTTIME_H_
#define _EVALSORTTIME_H_

extern "C" {
    float evalSortTime(int listSize, int seed, void (*func)(LinkedList*));
}

#endif