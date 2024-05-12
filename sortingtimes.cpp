#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using std::cout;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

// Node structure to represent elements in the linked list
typedef struct Node {
    int iData;          // Data stored in the node
    struct Node* ptrNext;  // Pointer to the next node in the list
    struct Node* ptrPrev;  // Pointer to the previous node in the list
} Node;

// Linked list structure to hold the head and tail pointers
typedef struct LinkedList {
    Node* ptrHead;      // Pointer to the first node in the list
    Node* ptrTail;      // Pointer to the last node in the list
} LinkedList;

// Function prototypes
LinkedList* newLinkedList();
LinkedList* newRandomList(int iListSize, int seed = 0);
Node* newNode(int iValue);
Node* searchElement(LinkedList* const list, int iValue);

void addElement(LinkedList* list, int iValue);
void showElements(LinkedList* list);
void removeElement(LinkedList* list, int iValue);
void swapNodes(Node* ptrNode1, Node* ptrNode2);
void freeList(LinkedList* list);
void invertList(LinkedList* list);

// Sorting algorithms
void insertionSort(int arriNumbers[], int iLength);
void bubbleSort(LinkedList* list);
void optimizedBubbleSort(LinkedList* list);
void selectionSort(LinkedList* list);
void optimizedSelectionSort(LinkedList* list);

void evalSortingEfficiency(int listSize, void (*func)(LinkedList*));

// Bubble sort algorithm for sorting the linked list
void bubbleSort(LinkedList* list) {
    Node* ptrOuter = list->ptrHead;

    // Loop through the list
    while (ptrOuter && ptrOuter->ptrNext) {
        Node* ptrInner = list->ptrHead;

        // Loop through the list again
        while (ptrInner && ptrInner->ptrNext) {
            // Swap values if the current pointer has a bigger value than the next one
            if ((ptrInner->iData) > (ptrInner->ptrNext->iData)) {
                swapNodes(ptrInner, ptrInner->ptrNext);
            }
            ptrInner = ptrInner->ptrNext;
        }
        ptrOuter = ptrOuter->ptrNext;
    }
};

// Optimized bubble sort algorithm for sorting the linked list
void optimizedBubbleSort(LinkedList* list) {

    bool bUnordered = false; // Check if the list is already ordered
    Node* ptrOuter = list->ptrHead;
    Node* ptrLast = list->ptrTail;

    while (ptrOuter && ptrOuter->ptrNext) {
        Node* ptrInner = list->ptrHead;
        bUnordered = false;

        while (ptrInner != ptrLast && ptrInner->ptrNext) {
            // Swap values if the current pointer has a bigger value than the next one
            if ((ptrInner->iData) > (ptrInner->ptrNext->iData)) {
                swapNodes(ptrInner, ptrInner->ptrNext);
                bUnordered = true;
            }
            ptrInner = ptrInner->ptrNext;
        }
        // If the list is not unordered, then we don't need to continue
        if (bUnordered == false) {
            break;
        }

        ptrLast = ptrLast->ptrPrev;
        ptrOuter = ptrOuter->ptrNext;
    }  
};

// Selection sort algorithm for sorting the linked list
void selectionSort(LinkedList* list) {
    Node* minValueNode = newNode(0);
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    while (ptrOuter && ptrOuter->ptrNext) {
        minValueNode = ptrOuter;
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner) {
            if (minValueNode->iData > ptrInner->iData) {
                minValueNode = ptrInner;
                swapNodes(ptrOuter, minValueNode);
            }
            ptrInner = ptrInner->ptrNext;
        }

        ptrOuter = ptrOuter->ptrNext;
    }
}

// Optimized selection sort algorithm for sorting the linked list
void optimizedSelectionSort(LinkedList* list)
{
    Node* minValueNode = newNode(0);
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    while (ptrOuter && ptrOuter->ptrNext) {
        minValueNode = ptrOuter;
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner) {
            if (minValueNode->iData > ptrInner->iData) {
                minValueNode = ptrInner;
            }
            ptrInner = ptrInner->ptrNext;
        }

        swapNodes(ptrOuter, minValueNode);
        ptrOuter = ptrOuter->ptrNext;
    }
}

// Insertion sort algorithm for sorting the linked list
void insertionSort(LinkedList* list)
{
    Node* ptrOuter = list->ptrHead;
    Node* ptrInner = list->ptrHead;

    while (ptrOuter && ptrOuter->ptrNext) {
        ptrInner = ptrOuter->ptrNext;

        while (ptrInner) {
            if (ptrOuter->iData > ptrInner->iData) {
                swapNodes(ptrOuter, ptrInner);
            }
            ptrInner = ptrInner->ptrNext;
        }

        ptrOuter = ptrOuter->ptrNext;
    }
}

// Main function
int main() {

    int iTestSize = 50000;

    cout << "Bubble Sort: " << endl;
    evalSortingEfficiency(iTestSize, &bubbleSort);
    cout << "======================\n" << endl;

    cout << "Bubble Sort Otimizado: " << endl;
    evalSortingEfficiency(iTestSize, &optimizedBubbleSort);
    cout << "======================\n" << endl;

    cout << "Selection Sort: " << endl;
    evalSortingEfficiency(iTestSize, &selectionSort);
    cout << "======================\n" << endl;

    // can be worse than the unoptimized
    cout << "Selection Sort Otimizado: " << endl;
    evalSortingEfficiency(iTestSize, &optimizedSelectionSort);
    cout << "======================\n" << endl;

    cout << "Insertion Sort: " << endl;
    evalSortingEfficiency(iTestSize, &insertionSort);
    cout << "======================\n" << endl;

    return 0;
}

// Function to evaluate sorting efficiency
void evalSortingEfficiency(int listSize, void (*func)(LinkedList*)) {
    LinkedList* list = newRandomList(listSize);

    // Measure the time to execute the function
    auto timeStart = high_resolution_clock::now();
    func(list);
    auto timeStop = high_resolution_clock::now();

    // Calculate execution time
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() * 1e-9 << " segundos" << endl;
}

// Function to create a new linked list
LinkedList* newLinkedList() {
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrHead  = nullptr;
    temp->ptrTail  = nullptr;
    return temp;
}

// Function to create a new linked list with random values
LinkedList* newRandomList(int iListSize, int seed) {
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));

    srand(seed);

    for (int i=0; i<iListSize; i++) {
        int iRandNum = rand() % 1000;
        addElement(temp, iRandNum);
    }

    return temp;
}

// Function to create a new node with given value
Node* newNode(int iValue) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

// Function to add an element to the linked list
void addElement(LinkedList* const list, int iValue) {
    
    Node* temp = newNode(iValue);

    if (list->ptrHead == nullptr) {
        list->ptrHead = temp;
        list->ptrTail = temp;
    }
    else {
        temp->ptrPrev = list-> ptrTail;
        list->ptrTail->ptrNext = temp;
        list->ptrTail = temp;
    }

    return;
}

// Function to display elements of the linked list
void showElements(LinkedList* const list) {
    
    Node* temp = list->ptrHead;

    while (temp != nullptr) {
        cout << temp->iData << " ";
        temp = temp->ptrNext;
    }

    cout << endl;

    return;
}

// Function to search for an element in the linked list
Node* searchElement(LinkedList* const list, int iValue) {
    Node* temp = nullptr;
    
    for (temp = list->ptrHead; temp != nullptr; temp = temp->ptrNext) {
        if (temp->iData == iValue) {
            return temp;
        }
    }
    return NULL;
}

// Function to remove an element from the linked list
void removeElement(LinkedList* const list, int iValue) {

    Node* temp = searchElement(list, iValue);;
    Node* garbage = nullptr;

    if (temp->ptrPrev == nullptr) {
        list->ptrHead = temp->ptrNext;
        temp->ptrNext->ptrPrev = nullptr;
    } 
    else if (temp->ptrNext == nullptr) {
        list->ptrTail = temp->ptrPrev;
        temp->ptrPrev->ptrNext = nullptr;
    } 
    else {
        temp->ptrPrev->ptrNext = temp->ptrNext;
        temp->ptrNext->ptrPrev = temp->ptrPrev;
    }

    free(temp);

    return;
}

// Function to free memory allocated for the linked list
void freeList(LinkedList* list) {
    Node* current = list->ptrHead;
    Node* previous = nullptr;

    while (current) {
        previous = current;
        current = current->ptrNext;

        free(previous);
    }

    list->ptrHead = nullptr;
    list->ptrTail = nullptr;
}

// Function to swap the data of two nodes
void swapNodes(Node* ptrNode1, Node* ptrNode2) {

    int iTemp = ptrNode1->iData;

    ptrNode1->iData = ptrNode2->iData;
    ptrNode2->iData = iTemp;
}
