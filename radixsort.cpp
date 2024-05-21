#include "utils/linkedList.h"

#include <iostream>
#include <cmath>

using namespace std;

void optimizedSelectionSortModulo(LinkedList* list, int iExp) {
    // Ordena a lista módulo 10** iExp

    Node* minValueNode = newNode(0);
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    while (ptrOuter && ptrOuter->ptrNext) {
        minValueNode = ptrOuter;
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner) {

            int minNodeModulo = (minValueNode->iData) % static_cast<int>(pow(10, iExp));
            int innerNodeModulo = (ptrInner->iData) % static_cast<int>(pow(10, iExp));

            int iCurrentExp = iExp - 1;

            while (iCurrentExp > 0)
            {
                minNodeModulo -= (minNodeModulo) % static_cast<int>(pow(10, iCurrentExp));
                innerNodeModulo -= (innerNodeModulo) % static_cast<int>(pow(10, iCurrentExp));
                iCurrentExp -= 1;
            }

            if (minNodeModulo > innerNodeModulo) {
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
        optimizedSelectionSortModulo(list, exp)
};
