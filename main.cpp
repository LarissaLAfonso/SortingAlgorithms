#include <iostream>

#include "binaryTree/binaryTree.h"
#include "linkedList/linkedList.h"
#include "sortAlgs/sortAlgs.h"
#include "utils/evalTime.h"

using namespace std;


int main() {


    radixExplainer(newRandomList(10, 1));

    int iNumberTests = 100;
    int iListSize = 10000;

    evalSearchTimes(iNumberTests, iListSize);
    evalCreationTimes(iNumberTests, iListSize);
    evalSortingTimes(iNumberTests, iListSize);

    return 0;
}