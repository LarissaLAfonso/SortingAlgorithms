#include <iostream>
#include "progressBar.h"

using namespace std;

void progressBar(int iProgress, int iTotal) {
    int iBarWidth = 50;
    float fPercentage = (float) iProgress / iTotal;
    int iPosition = iBarWidth * fPercentage;

    cout << " [";
    for (int i = 0; i < iBarWidth; ++i) {
        if (i <= iPosition)
            cout << "=";
        else
            cout << ".";
    }
    cout << "] " << int(fPercentage * 100.0 + 1) << "%\r" ;
    cout.flush();
}