#include <iostream>
#include <fstream>

#include "binaryTree/binaryTree.h"
#include "linkedList/linkedList.h"
#include "sortAlgs/sortAlgs.h"
#include "utils/progressBar.h"

#include "utils/evalTime.h"


using namespace std;
void evalSortingTimes(int iNumberTests, int iListSize);
void evalSearchTimes(int iNumberTests, int iListSize);
void evalCreationTimes(int iNumberTests, int iListSize);

int main() {
    int iNumberTests = 100;
    int iListSize = 10000;

    evalSearchTimes(iNumberTests, iListSize);
    evalCreationTimes(iNumberTests, iListSize);
    evalSortingTimes(iNumberTests, iListSize);

    return 0;
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