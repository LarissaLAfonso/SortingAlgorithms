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
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃                     ━=━ Radix Sort Explained ━=━                    ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ O radix sort consiste em um algoritmo de ordenação não comparativo  ┃" << endl;
    cout << "┃ que processa individualmente cada digito dos elementos. Ao final de ┃" << endl;
    cout << "┃ cada passo, teremos uma ordenação conforme a posição do respectivo  ┃" << endl;
    cout << "┃ digito que estamos olhando. No final do processo tudo é ordenado.   ┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃ OBS: implementações desse algoritmo geralmente usam counting sort,  ┃" << endl;
    cout << "┃ mas aqui faremos a implementação com selection sort, o que tornará  ┃" << endl;
    cout << "┃ o desempenho do algoritmo não tão bom                               ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << endl;
    cout << "┃ A lista que vamos ordenar agora é" << endl;
    cout << "┃ ";

    showElements(list);

    cout << endl;
    cout << "┃ Primeiro, procuramos o maior elemento da lista." << endl;

    int iMaximum = getMax(list);

    cout << "┃ Nesse caso, é " << iMaximum << "." << endl;

    cout << endl;
    cout << "┃ A quantidade de dígitos que ele tem é um N natural tal que: " << endl;
    cout << "┃ " << iMaximum << "/10^N >= 1, mas " << iMaximum << "/10^(N+1) < 1." << endl;
    cout << "┃ Fazemos então um loop de 1 até N, agrupando os números da lista" << endl;
    cout << "┃ conferme cada uma de suas N ordens de grandeza." << endl;

    cout << endl;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃                        ━=━ Vamos começar! ━=━                       ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;


    for (int exp = 1; iMaximum / exp > 0; exp *= 10) 
    {
        cout << endl;
        cout << "┃ Expoente atual = " << exp << endl;
        cout << "┃ Ordenando a lista pelo " << log10(exp) + 1 << " algarismo" << endl;
        cout << "┃" << endl;
        cout << "┃ Lista antes do passo: " << endl;
        cout << "┃ \t";
        showElements(list);
        optimizedSelectionSortModulo(list, exp);
        cout << "┃" << endl;
        cout << "┃ Lista após o passo: " << endl;
        cout << "┃ \t";
        showElements(list);
    }

    cout << endl;
    cout << "┃ Confira o resultado final:" << endl;
    cout << "┃ \t";
    showElements(list);
    cout << endl;

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃                             ━=━ FIM! ━=━                            ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    cout << endl;
}
