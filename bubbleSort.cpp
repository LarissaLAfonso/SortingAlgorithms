#include "utils/linkedList.h"
#include "utils/sortingAlgorithms.h"

// Bubble sort algorithm for sorting the linked list
void bubbleSort(LinkedList* list) {
    Node* ptrOuter = list->ptrHead;

    // Loop through the list
    while (ptrOuter && ptrOuter->ptrNext) {
        Node* ptrInner = list->ptrHead;

        // Loop through the list again
        while (ptrInner && ptrInner->ptrNext) {
            // Swap values if the current pointer has a bigger value than the next one
            if ((ptrInner->iData) > (ptrInner->ptrNext->iData)) {
                swapNodes(ptrInner, ptrInner->ptrNext);
            }
            ptrInner = ptrInner->ptrNext;
        }
        ptrOuter = ptrOuter->ptrNext;
    }
};

// Optimized bubble sort algorithm for sorting the linked list
void optimizedBubbleSort(LinkedList* list) {

    bool bUnordered = false; // Check if the list is already ordered
    Node* ptrOuter = list->ptrHead;
    Node* ptrLast = list->ptrTail;

    while (ptrOuter && ptrOuter->ptrNext) {
        Node* ptrInner = list->ptrHead;
        bUnordered = false;

        while (ptrInner != ptrLast && ptrInner->ptrNext) {
            // Swap values if the current pointer has a bigger value than the next one
            if ((ptrInner->iData) > (ptrInner->ptrNext->iData)) {
                swapNodes(ptrInner, ptrInner->ptrNext);
                bUnordered = true;
            }
            ptrInner = ptrInner->ptrNext;
        }
        // If the list is not unordered, then we don't need to continue
        if (bUnordered == false) {
            break;
        }

        ptrLast = ptrLast->ptrPrev;
        ptrOuter = ptrOuter->ptrNext;
    }  
};

