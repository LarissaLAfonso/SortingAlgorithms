#include <iostream>
#include <ctime>
#include <chrono>

#include "linkedList.h"
#include "evalSortTime.h"
#include "bfsLinkedList.h"

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


float evalTreeTime(int listSize, int seed, void (*func)(TreeNode<int>*)) 
{
    // Calculate execution time for bfs and dfs algorithms
    LinkedList<int>* iList = newRandomList(listSize, seed);
    
    TreeNode<int>* root = nullptr;
    
    Node<int>* currentNode = iList -> ptrHead;
    while (currentNode != nullptr) 
    {
        root = insertNode(root, currentNode -> iData);
        currentNode = currentNode -> ptrNext;
    }

    // Measure the time to execute the function
    auto timeStart = high_resolution_clock::now();
    func(root);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    return timeDuration.count() * 1e-9;
}