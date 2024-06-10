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

    cout << endl;
    cout << "|=====================================================================|" << endl;
    cout << "|                     === Radix Sort Explained ===                    |" << endl;
    cout << "|=====================================================================|" << endl;
    cout << "|=====================================================================|" << endl;
    cout << "| O radix sort consiste em um algoritmo de ordenacao nao comparativo  |" << endl;
    cout << "| que processa individualmente cada digito dos elementos. Ao final de |" << endl;
    cout << "| cada passo, teremos uma ordenacao conforme a posicao do respectivo  |" << endl;
    cout << "| digito que estamos olhando. No final do processo tudo e ordenado.   |" << endl;
    cout << "|=====================================================================|" << endl;
    cout << "| OBS: implementacoes desse algoritmo geralmente usam counting sort,  |" << endl;
    cout << "| mas aqui faremos a implementacao com selection sort, o que tornara  |" << endl;
    cout << "| o desempenho do algoritmo nao tao bom                               |" << endl;
    cout << "|=====================================================================|" << endl;

    cout << endl;
    cout << "| A lista que vamos ordenar agora e" << endl;
    cout << "| ";

    showElements(list);

    cout << endl;
    cout << "| Primeiro, procuramos o maior elemento da lista." << endl;

    int iMaximum = getMax(list);

    cout << "| Nesse caso, e " << iMaximum << "." << endl;

    cout << endl;
    cout << "| A quantidade de digitos que ele tem e um N natural tal que: " << endl;
    cout << "| " << iMaximum << "/10^N >= 1, mas " << iMaximum << "/10^(N+1) < 1." << endl;
    cout << "| Fazemos entao um loop de 1 ate N, agrupando os numeros da lista" << endl;
    cout << "| conferme cada uma de suas N ordens de grandeza." << endl;

    cout << endl;
    cout << "|=====================================================================|" << endl;
    cout << "|                        === Vamos comecar! ===                       |" << endl;
    cout << "|=====================================================================|" << endl;


    for (int exp = 1; iMaximum / exp > 0; exp *= 10) 
    {
        cout << endl;
        cout << "| Expoente atual = " << exp << endl;
        cout << "| Ordenando a lista pelo " << log10(exp) + 1 << " algarismo" << endl;
        cout << "|" << endl;
        cout << "| Lista antes do passo: " << endl;
        cout << "| \t";
        showElements(list);
        optimizedSelectionSortModulo(list, exp);
        cout << "|" << endl;
        cout << "| Lista apos o passo: " << endl;
        cout << "| \t";
        showElements(list);
    }

    cout << endl;
    cout << "| Confira o resultado final:" << endl;
    cout << "| \t";
    showElements(list);
    cout << endl;

    cout << "|=====================================================================|" << endl;
    cout << "|                             === FIM! ===                            |" << endl;
    cout << "|=====================================================================|" << endl;
    cout << endl;
}
