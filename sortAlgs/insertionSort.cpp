#include "../linkedList/linkedList.h"
#include "sortAlgs.h"

template <typename T>
void insertionSort(LinkedList<T>* list) {
    Node<T>* ptrOuter = list->ptrHead;
    Node<T>* ptrInner = list->ptrHead;

    T iInsertValue = 0;

    while (ptrOuter) {
        ptrInner = ptrOuter->ptrPrev;
        iInsertValue = ptrOuter->iData;

        while (ptrInner && (ptrInner->iData > iInsertValue)) {
            swapNodes(ptrInner->ptrNext, ptrInner);
            ptrInner = ptrInner->ptrPrev;
        }
        ptrOuter = ptrOuter->ptrNext;
    }
}

template void insertionSort<int>(LinkedList<int>*);
template void insertionSort<float>(LinkedList<float>*);