#include "utils/linkedList.h"
#include "utils/sortingAlgorithms.h"

#include <iostream>
#include <cmath>

using namespace std;

void optimizedSelectionSortModulo(LinkedList* list, int iExp) {
    Node* minValueNode = newNode(0);
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    while (ptrOuter && ptrOuter->ptrNext) {
        minValueNode = ptrOuter;
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner) {
            if (minValueNode->iData / iExp % 10 > ptrInner->iData / iExp % 10){
                minValueNode = ptrInner;
            }
            ptrInner = ptrInner->ptrNext;
        }

        swapNodes(ptrOuter, minValueNode);
        ptrOuter = ptrOuter->ptrNext;
    }
}

void radixSort(LinkedList* list) 
{
    int iMaximum = getMax(list);

    for (int exp = 1; iMaximum / exp > 0; exp *= 10)
        optimizedSelectionSortModulo(list, exp);
};
