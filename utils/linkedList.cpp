#include <iostream>
#include "linkedList.h"

using std::cout;
using std::endl;

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