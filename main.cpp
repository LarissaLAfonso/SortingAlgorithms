#include <iostream>

#include "utils/linkedList.h"
#include "utils/evalSortTime.h"
#include "utils/sortingAlgorithms.h"

using namespace std;

int main() {

    int iArray[10] = {40, 3, 23, 41, 6, 73, 9, 69, 4, 100};
    LinkedList<int>* list = listFromArray<int>(iArray, 10);

    radixExplainer(list);

    cout << endl;
    cout << "=============== Sorting Times" << endl;
    cout << endl;

    int iNumberTests = 100;
    int iListSize = 10000;

    cout << "Bubble Sort, Optimized Bubble Sort, Selection Sort, Optimized Selection Sort, Insertion Sort, Radix Sort" << endl;

    for (int i=0; i<iNumberTests; i++) 
    {
        cout << evalSortTime(iListSize, i+1, &bubbleSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &optimizedBubbleSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &selectionSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &optimizedSelectionSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &insertionSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &radixSort);
        cout << endl;        
    }

    return 0;
}
