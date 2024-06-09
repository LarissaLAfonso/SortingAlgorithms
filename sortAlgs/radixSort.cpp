#include "../linkedList/linkedList.h"
#include "sortAlgs.h"

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
            if (minValueNode->data / iExp % 10 > ptrInner->data / iExp % 10){
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

void radixExplainer(LinkedList<int>* list) 
{

    cout << " -- Radix Sort -- " << endl;

    cout << "O radix sort consiste em um algoritmo de ordenação não comparativo\n(implementações desse algoritmo geralmente usam counting sort, mas\n aqui faremos a implementação com selection sort, o que tornará o \ndesempenho do algoritmo não tão bom) e, a cada passo, processa\n individualmente os digitos dos elementos, agrupando-os. Ao final\n de cada passo, teremos uma ordenação conforme a posição do\n respectivo digito que estamos olhando. No final do processo tudo\n é ordenado." << endl;

    cout << endl;
    cout << "A lista que vamos ordenar agora é" << endl;
    showElements(list);

    cout << endl;
    cout << "Primeiro, procuramos o maior elemento da lista." << endl;

    int iMaximum = getMax(list);

    cout << "Nesse caso, será " << iMaximum << "." << endl;

    cout << endl;
    cout << "A quantidade de dígitos que ele tem é um número n natural tal que " << iMaximum << "/10^n >= 1, mas " << iMaximum << "/10^(n+1) < 1." << endl;
    cout << "Fazemos então um loop for de 1 até n, ordenando os números da lista por cada uma das n ordens de grandeza." << endl;

    for (int exp = 1; iMaximum / exp > 0; exp *= 10) 
    {
        cout << endl;
        cout << "Expoente atual = " << exp << endl;
        cout << "Lista antes do passo: ";
        showElements(list);

        cout << "Ordenando a lista por seu " << log10(exp) + 1 << " algarismo..." << endl;
        optimizedSelectionSortModulo(list, exp);

        cout << "Lista após o passo: ";
        showElements(list);
        cout << "----------------------------------\n";
    }

    
    cout << "TERMINAMOS!!!" << endl;
    cout << "Olha o resultado final:" << endl;
    showElements(list);
}
