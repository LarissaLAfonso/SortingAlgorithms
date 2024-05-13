#include "utils/linkedList.h"
#include "utils/sortingAlgorithms.h"

void insertionSort(LinkedList* list) {
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    while (ptrOuter && ptrOuter->ptrNext) {
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner && ptrInner->ptrPrev && (ptrInner->iData < ptrInner->ptrPrev->iData)) {
            swapNodes(ptrInner, ptrInner->ptrPrev);
            ptrInner = ptrInner->ptrPrev;
        }
        ptrOuter = ptrOuter->ptrNext;
    }
}