#include <iostream>
#include <ctime>
#include <chrono>

#include "linkedList.h"
#include "evalSortTime.h"

using namespace std;

using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::nanoseconds;  

float evalSortTime(int listSize, int seed, void (*func)(LinkedList*)) {
    LinkedList* list = newRandomList(listSize, seed);

    // Measure the time to execute the function
    auto timeStart = high_resolution_clock::now();
    func(list);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    return timeDuration.count() * 1e-9;
}