#include <iostream>
#include <chrono>

using std::endl;
using std::cout;
using std::cin;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

// Assinaturas
void swapValue(int&, int&);
void printArray(int[], int);
void bubbleSort(int[], int);
void optimizedBubbleSort(int[], int);

int main(){
    // Bubble sort não otimizado
    int arriNumbers_1[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraysize_1 = 10;
    cout << "Array original: ";
    printArray(arriNumbers_1, iArraysize_1); 

    // time_point<std::chrono::high_resolution_clock> timestart
    auto timeStart = high_resolution_clock::now();
    bubbleSort(arriNumbers_1, iArraysize_1);
    auto timeStop = high_resolution_clock::now();

    cout << "Array ordenado: ";
    printArray(arriNumbers_1, iArraysize_1); 

    // Tempo de execução
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanoseconds" << endl;
    cout << "==================================" << endl; 

    // Bubble sort otimizado
    int arriNumbers_2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraysize_2 = 10;
    cout << "Array original: ";
    printArray(arriNumbers_2, iArraysize_2); 

    // time_point<std::chrono::high_resolution_clock> timestart
    timeStart = high_resolution_clock::now();
    optimizedBubbleSort(arriNumbers_2, iArraysize_2);
    timeStop = high_resolution_clock::now();

    cout << "Array ordenado: ";
    printArray(arriNumbers_2, iArraysize_2); 

    // Tempo de execução
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanoseconds" << endl;
    return 0;
}

void swapValue(int& irefValue_1, int& irefValue_2){
    /*
    Receve duas variáveis e troca seus valores.
    */
    int iTemp = irefValue_1;
    irefValue_1 = irefValue_2;
    irefValue_2 = iTemp;
};

void printArray(int arriNumbers[], int iLength){
    /*
    Recebe uma array e seu tamanho e printa seus elementos no console.
    */
    for(int i = 0; i< iLength; i++) cout << arriNumbers[i] << " ";
    cout << endl;
};

void bubbleSort(int arriNumbers[], int iLength){
    /*
    Receve uma array e seu tamanho e a ordena em O(n^2)
    */

    // Para cada elemento da array
    for (int iOuterLoop = 0; iOuterLoop < iLength-1; iOuterLoop++)
        // Compare-o com cada um dos outros elementos
        for (int iInnerLoop = 0; iInnerLoop < iLength-1; iInnerLoop++ )
            // Se o elemento escolhido for menor que o elemento da vez
            if (arriNumbers[iInnerLoop]>arriNumbers[iInnerLoop+1])
                // Os trocamos de lugar
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop+1]);
};

void optimizedBubbleSort(int arriNumbers[], int iLength)
{
    /*
    Receve uma array e seu tamanho e a ordena em O(n^2).
    Não percorre a parte já ordenada da lista.
    */
    bool bUnordered = false;

    for (int iOuterLoop = 0; iOuterLoop < iLength-1; iOuterLoop++)
    {
        bUnordered = false;

        // Para cada elemento ainda não escolhido
        for (int iInnerLoop = 0; iInnerLoop < iLength-iOuterLoop-1; iInnerLoop++ )
        {
            if (arriNumbers[iInnerLoop]>arriNumbers[iInnerLoop+1])
            {
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop+1]);
                bUnordered = true;
            }    
        }

        if (bUnordered == false) 
        {
            break;
        }
    }
       
};
