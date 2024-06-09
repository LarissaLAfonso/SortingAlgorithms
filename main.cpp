#include <iostream>
#include <fstream>

#include "linkedList/linkedList.h"
#include "utils/evalSortTime.h"

#include "sortAlgs/sortAlgs.h"

#include "utils/progressBar.h"

#include "binaryTree/binaryTree.h"

// #include "utils/bfsLinkedList.h"

using namespace std;

int main() {
    TreeNode<int>* root = nullptr;
    
    root = insertTreeNode(root, 42);
    root = insertTreeNode(root, 13);
    root = insertTreeNode(root, 11);
    root = insertTreeNode(root, 10);
    root = insertTreeNode(root, 28);
    root = insertTreeNode(root, 51);
    root = insertTreeNode(root, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal<int>(root);
    cout << endl;

    // cout << "DFS Pre-Order Traversal: ";
    // dfsPreOrder<int>(root);
    // cout << endl;

    int iArray[10] = {40, 3, 23, 41, 6, 73, 9, 69, 4, 100};
    LinkedList<int>* list = listFromArray<int>(iArray, 10);

    radixExplainer(list);

    // cout << endl;
    // cout << "=============== Sorting Times" << endl;
    // cout << endl;

    ofstream sortingTimes("sortingTimes.csv");

    int iNumberTests = 100;
    int iListSize = 10000;

    cout << "Calculando tempos - Sorting" << endl;
    sortingTimes << "Bubble Sort, Optimized Bubble Sort, Selection Sort, Optimized Selection Sort, Insertion Sort, Radix Sort\n";
    for (int i=0; i<iNumberTests; i++) 
    {
        progressBar(i, iNumberTests);

        sortingTimes << evalSortTime(iListSize, i+1, &bubbleSort) << "\n";
        sortingTimes << ", ";

        sortingTimes << evalSortTime(iListSize, i+1, &optimizedBubbleSort);
        sortingTimes << ", ";

        sortingTimes << evalSortTime(iListSize, i+1, &selectionSort);
        sortingTimes << ", ";

        sortingTimes << evalSortTime(iListSize, i+1, &optimizedSelectionSort);
        sortingTimes << ", ";

        sortingTimes << evalSortTime(iListSize, i+1, &insertionSort);
        sortingTimes << ", ";

        sortingTimes << evalSortTime(iListSize, i+1, &radixSort);
        sortingTimes << "\n";
    }

    sortingTimes.close();

    return 0;
}

