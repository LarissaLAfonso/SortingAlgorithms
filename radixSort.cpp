#include "utils/linkedList.h"
#include "utils/sortingAlgorithms.h"

#include <iostream>
#include <cmath>

using namespace std;

void optimizedSelectionSortModulo(LinkedList<int>* list, int iExp) {
    Node<int>* minValueNode = newNode(0);
    Node<int>* ptrOuter = list->ptrHead;
    Node<int>* ptrInner = list->ptrHead;

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

void radixSort(LinkedList<int>* list) 
{
    int iMaximum = getMax(list);

    for (int exp = 1; iMaximum / exp > 0; exp *= 10)
        optimizedSelectionSortModulo(list, exp);
};

void radixExplainer(int iArray[], int size) 
{
    LinkedList<int> list;
    for (int i = 0; i < size; ++i) 
    {
        addElement(&list, iArray[i]);
    }

    cout << " -- Radix Sort -- " << endl;

    cout << "O radix sort consiste de escolher um algotimo de ordenação qualquer\n (usualmente counting sort, mas aqui você uma implementação com selection sort) e,\n a cada passo, ordena uma ordem de grandeza de acordo com esse algoritmo. " << endl;

    
    cout << "A lista que vamos ordenar agora é" << endl;
    showElements(&list);

    cout << "Primeiro, determinamos o maior elemento da lista." << endl;

    int iMaximum = getMax(&list);

    cout << "Nesse caso, será " << iMaximum << "." << endl;

    cout << "A quantidade de dígitos que ele tem é um número n natural tal que " << iMaximum << "/10^n >= 1, mas " << iMaximum << "/10^(n+1) < 1." << endl;

    cout << "Fazemos então um loop for de 1 até n, ordenando os números da lista por cada uma das n ordens de grandeza." << endl;

    for (int exp = 1; iMaximum / exp > 0; exp *= 10) 
    {
        cout << "Expoente atual = " << exp << endl;
        cout << "Lista antes do passo: ";
        showElements(&list);

        cout << "Ordenando a lista por seu " << log10(exp) << "-ésimo algarismo...";
        optimizedSelectionSortModulo(&list, exp);

        cout << "Lista após o passo: ";
        showElements(&list);
        cout << "----------------------------------\n";
    }

    
    cout << "TERMINAMOS!!!" << endl;
    cout << "Olha o resultado final:" << endl;
    showElements(&list);
}
