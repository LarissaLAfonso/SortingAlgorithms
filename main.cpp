#include <iostream>

#include "utils/linkedList.h"
#include "utils/evalSortTime.h"
#include "utils/sortingAlgorithms.h"
#include "utils/bfsLinkedList.h"

using namespace std;

int main() {
    TreeNode<int>* root = nullptr;
    
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 28);
    root = insertNode(root, 51);
    root = insertNode(root, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal<int>(root);
    cout << endl;

    cout << "DFS Pre-Order Traversal: ";
    dfsPreOrder<int>(root);
    cout << endl;

    int iArray[10] = {40, 3, 23, 41, 6, 73, 9, 69, 4, 100};
    LinkedList<int>* list = listFromArray<int>(iArray, 10);

    radixExplainer(list);

    cout << endl;
    cout << "=============== Sorting Times" << endl;
    cout << endl;

    int iNumberTests = 100;
    int iListSize = 10000;

    cout << "Bubble Sort, Optimized Bubble Sort, Selection Sort, Optimized Selection Sort, Insertion Sort, Radix Sort" << endl;

    for (int i=0; i<iNumberTests; i++) 
    {
        cout << evalSortTime(iListSize, i+1, &bubbleSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &optimizedBubbleSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &selectionSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &optimizedSelectionSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &insertionSort);
        cout << ", ";

        cout << evalSortTime(iListSize, i+1, &radixSort);
        cout << endl;  

        cout << evalTreeTime(iListSize, i+1, &bfsTraversal); 
        cout << endl;

        cout << evalTreeTime(iListSize, i+1, &dfsPreOrder);
        cout << endl;     

    }

    return 0;
}
