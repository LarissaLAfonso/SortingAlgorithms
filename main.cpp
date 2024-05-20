#include <iostream>

#include "utils/linkedList.h"
#include "utils/evalSortTime.h"
#include "utils/sortingAlgorithms.h"

using namespace std;

int main() {

    int iNumberTests = 100;
    int iListSize = 10000;

    cout << "Bubble Sort, Optimized Bubble Sort, Selection Sort, Optimized Selection Sort, Insertion Sort" << endl;

    for (int i=0; i<iNumberTests; i++) {
        cout << evalSortTime(iListSize, i+1, &bubbleSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &optimizedBubbleSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &selectionSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &optimizedSelectionSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &insertionSort);
        cout << endl;
    }

    return 0;
}