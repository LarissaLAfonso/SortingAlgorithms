#include "../linkedList/linkedList.h"
#include "sortAlgs.h"

// Bubble sort algorithm for sorting the linked list
template <typename T>
void bubbleSort(LinkedList<T>* list) {
    Node<T>* ptrOuter = list->ptrHead;

    // Loop through the list
    while (ptrOuter && ptrOuter->ptrNext) {
        Node<T>* ptrInner = list->ptrHead;

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
template <typename T>
void optimizedBubbleSort(LinkedList<T>* list) {

    bool bUnordered = false; // Check if the list is already ordered
    Node<T>* ptrOuter = list->ptrHead;
    Node<T>* ptrLast = list->ptrTail;

    while (ptrOuter && ptrOuter->ptrNext) {
        Node<T>* ptrInner = list->ptrHead;
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


template void bubbleSort<int>(LinkedList<int>*);
template void bubbleSort<float>(LinkedList<float>*);

template void optimizedBubbleSort<int>(LinkedList<int>*);
template void optimizedBubbleSort<float>(LinkedList<float>*);