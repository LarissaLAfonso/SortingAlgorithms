#ifndef _SORTINGALGORITHMS_H_
#define _SORTINGALGORITHMS_H_

extern "C" {
    void bubbleSort(LinkedList*);
    void optimizedBubbleSort(LinkedList*);
    
    void selectionSort(LinkedList*);
    void optimizedSelectionSort(LinkedList*);

    void insertionSort(LinkedList*);
    void optimizedInsertionSort(LinkedList*);
}

#endif