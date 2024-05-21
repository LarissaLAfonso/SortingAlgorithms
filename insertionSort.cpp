#include "utils/linkedList.h"
#include "utils/sortingAlgorithms.h"

void insertionSort(LinkedList* list) {
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    int iInsertValue = 0;

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