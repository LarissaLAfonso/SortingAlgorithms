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
void insertionSort(int[], int);

int main(){
    int arriNumbers_1[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraysize_1 = 10;
    cout << "Array original: ";
    printArray(arriNumbers_1, iArraysize_1); 

    // time_point<std::chrono::high_resolution_clock> timestart
    auto timeStart = high_resolution_clock::now();
    insertionSort(arriNumbers_1, iArraysize_1);
    auto timeStop = high_resolution_clock::now();

    cout << "Array ordenado: ";
    printArray(arriNumbers_1, iArraysize_1); 

    // Tempo de execução
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanoseconds" << endl;
    cout << "==================================" << endl; 
    
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

void insertionSort(int arriNumbers[], int iLength)
{
    int iInsertValue = 0;
    int iInnerLoop = 0;
    
    for (int iOuterLoop =1; iOuterLoop < iLength; iOuterLoop++)
    {
        int iInsertValue = arriNumbers[iOuterLoop];
        iInnerLoop = iOuterLoop - 1;
        
        while (iInsertValue < arriNumbers[iInnerLoop] && iInnerLoop >= 0)
        {
            arriNumbers[iInnerLoop + 1] = arriNumbers[iInnerLoop];
            iInnerLoop--;
        }
        
        arriNumbers[iInnerLoop + 1] = iInsertValue;
    }
}
