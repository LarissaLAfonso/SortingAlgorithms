#include "utils/linkedList.h"
#include "utils/sortingAlgorithms.h"

void selectionSort(LinkedList* list) {
    Node* minValueNode = newNode(0);
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    while (ptrOuter && ptrOuter->ptrNext) {
        minValueNode = ptrOuter;
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner) {
            if (minValueNode->iData > ptrInner->iData) {
                minValueNode = ptrInner;
                swapNodes(ptrOuter, minValueNode);
            }
            ptrInner = ptrInner->ptrNext;
        }

        ptrOuter = ptrOuter->ptrNext;
    }
}

// Optimized selection sort algorithm for sorting the linked list
void optimizedSelectionSort(LinkedList* list) {
    Node* minValueNode = newNode(0);
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    while (ptrOuter && ptrOuter->ptrNext) {
        minValueNode = ptrOuter;
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner) {
            if (minValueNode->iData > ptrInner->iData) {
                minValueNode = ptrInner;
            }
            ptrInner = ptrInner->ptrNext;
        }

        swapNodes(ptrOuter, minValueNode);
        ptrOuter = ptrOuter->ptrNext;
    }
}