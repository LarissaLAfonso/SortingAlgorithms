#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

#include "../linkedList/linkedList.h"
#include "../binaryTree/binaryTree.h"
#include "../sortAlgs/sortAlgs.h"
#include "../utils/progressBar.h"
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
    newRandomList(iSize, seed);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    return timeDuration.count() * 1e-9;
}

float evalCreationTimeTree(int iSize, int seed) {
    // Measure the time to create the tree
    auto timeStart = high_resolution_clock::now();
    newRandomTree(iSize, seed);
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


void evalSortingTimes(int iNumberTests, int iListSize) {
    cout << "Calculando tempos - List Sorting" << endl;

    ofstream sortingTimes("sortingTimes.csv");
    sortingTimes << "Bubble Sort, Optimized Bubble Sort, Selection Sort, Optimized Selection Sort, Insertion Sort, Radix Sort\n";
    for (int i=0; i<iNumberTests; i++) {
        progressBar(i, iNumberTests);

        sortingTimes << evalSortTime(iListSize, i+1, &bubbleSort) << ", ";
        sortingTimes << evalSortTime(iListSize, i+1, &optimizedBubbleSort) << ", ";
        sortingTimes << evalSortTime(iListSize, i+1, &selectionSort) << ", ";
        sortingTimes << evalSortTime(iListSize, i+1, &optimizedSelectionSort) << ", ";
        sortingTimes << evalSortTime(iListSize, i+1, &insertionSort) << ", ";
        sortingTimes << evalSortTime(iListSize, i+1, &radixSort) << "\n";
    }

    cout << "\v" << endl;

    sortingTimes.close();
}

void evalSearchTimes(int iNumberTests, int iListSize) {
    cout << "Calculando tempos - Searching" << endl;

    ofstream searchTimes("searchTimes.csv");
    searchTimes << "List Search, Breadth-first Search, Depth-first Search\n";
    for (int i=0; i<iNumberTests; i++) {
        progressBar(i, iNumberTests);

        searchTimes << evalSearchTimeList(iListSize, i+1, &searchElement) << ", ";
        searchTimes << evalSearchTimeTree(iListSize, i+1, &bfSearch) << ", ";
        searchTimes << evalSearchTimeTree(iListSize, i+1, &dfSearch) << "\n ";
    }

    cout << "\v" << endl;

    searchTimes.close();
}

void evalCreationTimes(int iNumberTests, int iListSize) {
    cout << "Calculando tempos - Creation" << endl;

    ofstream creationTimes("creationTimes.csv");
    creationTimes << "List, Tree\n";
    for (int i=0; i<iNumberTests; i++) {
        progressBar(i, iNumberTests);

        creationTimes << evalCreationTimeList(iListSize, i+1) << ", ";
        creationTimes << evalCreationTimeTree(iListSize, i+1) << "\n";
    }

    cout << "\v" << endl;

    creationTimes.close();
}