#include "utils/linkedList.h"
#include "utils/sortingAlgorithms.h"

template <typename T>
void selectionSort(LinkedList<T>* list) {
    Node<T>* minValueNode = newNode<T>(0);
    Node<T>* ptrOuter = list->ptrHead;
    Node<T>* ptrInner = list->ptrHead;

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
template <typename T>
void optimizedSelectionSort(LinkedList<T>* list) {
    Node<T>* minValueNode = newNode<T>(0);
    Node<T>* ptrOuter = list->ptrHead;
    Node<T>* ptrInner = list->ptrHead;

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

template void selectionSort<int>(LinkedList<int>*);
template void selectionSort<float>(LinkedList<float>*);

template void optimizedSelectionSort<int>(LinkedList<int>*);
template void optimizedSelectionSort<float>(LinkedList<float>*);