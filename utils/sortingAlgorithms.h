#ifndef _SORTINGALGORITHMS_H_
#define _SORTINGALGORITHMS_H_
#include "linkedList.h"

template <typename T> void bubbleSort(LinkedList<T>*);
template <typename T> void optimizedBubbleSort(LinkedList<T>*);


template <typename T> void selectionSort(LinkedList<T>*);
template <typename T> void optimizedSelectionSort(LinkedList<T>*);


template <typename T> void insertionSort(LinkedList<T>*);
template <typename T> void optimizedInsertionSort(LinkedList<T>*);


template <typename T> void optimizedSelectionSortModulo(LinkedList<T>*, int);
template <typename T> void radixSort(LinkedList<T>*);

void radixSort(LinkedList<int>* list);
#endif