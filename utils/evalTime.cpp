#include <iostream>
#include <ctime>
#include <chrono>

#include "../linkedList/linkedList.h"
#include "../binaryTree/binaryTree.h"
#include "evalTime.h"

using namespace std;

using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::nanoseconds;  


float evalSortTime(int listSize, int seed, void (*func)(LinkedList<int>*)) {
    LinkedList<int>* list = newRandomList(listSize, seed);
    
    // Measure the time to execute the function
    auto timeStart = high_resolution_clock::now();
    func(list);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    return timeDuration.count() * 1e-9;
}


float evalCreationTimeList(int iSize, int seed) {
    // Measure the time to create the list
    auto timeStart = high_resolution_clock::now();
    LinkedList<int>* list = newRandomList(iSize, seed);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    return timeDuration.count() * 1e-9;
}

float evalCreationTimeTree(int iSize, int seed) {
    // Measure the time to create the tree
    auto timeStart = high_resolution_clock::now();
    TreeNode<int>* root = newRandomTree(iSize, seed);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    return timeDuration.count() * 1e-9;
}

float evalSearchTimeList(int iSize, int seed, Node<int>* (*func)(LinkedList<int>*, int)) {
    LinkedList<int>* list = newRandomList(iSize, seed);
    
    // Measure the time to execute the function
    auto timeStart = high_resolution_clock::now();
    func(list, 50);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    return timeDuration.count() * 1e-9;
}

float evalSearchTimeTree(int iSize, int seed, TreeNode<int>* (*func)(TreeNode<int>*, int)) {
    TreeNode<int>* root = newRandomTree(iSize, seed);
    
    // Measure the time to execute the function
    auto timeStart = high_resolution_clock::now();
    func(root, 50);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    return timeDuration.count() * 1e-9;
}
