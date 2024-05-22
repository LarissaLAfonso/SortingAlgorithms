#include <iostream>
#include "linkedList.h"

using namespace std;

template <typename T>
int getMax(LinkedList<T>* const list) {
    Node<T>* temp = list->ptrHead;
    int max = temp->iData;

    while (temp != nullptr) {
        if (temp->iData > max) {
            max = temp->iData;
        }
        temp = temp->ptrNext;
    }

    return max;
}

template <typename T>
LinkedList<T>* listFromArray(int *arrValues, int iArraySize) {
    LinkedList<T>* temp = newLinkedList<T>();

    for (int i=0; i<iArraySize; i++) {
        addElement(temp, arrValues[i]);
    }

    return temp;
}

template <typename T>
LinkedList<T>* newLinkedList() {
    LinkedList<T>* temp = (LinkedList<T>*) malloc(sizeof(LinkedList<T>));
    temp->ptrHead  = nullptr;
    temp->ptrTail  = nullptr;
    return temp;
}

// Function to create a new linked list with random values
LinkedList<int>* newRandomList(int iListSize, int seed) {
    LinkedList<int>* temp = (LinkedList<int>*) malloc(sizeof(LinkedList<int>));

    srand(seed);

    for (int i=0; i<iListSize; i++) {
        int iRandNum = rand() % 100 + 1;
        addElement<int>(temp, iRandNum);
    }

    return temp;
}

// Function to create a new node with given value
template <typename T>
Node<T>* newNode(T iValue) {
    Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));
    temp->iData = iValue;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

// Function to add an element to the linked list
template <typename T>
void addElement(LinkedList<T>* const list, T iValue) {
    
    Node<T>* temp = newNode<T>(iValue);

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
template <typename T>
void showElements(LinkedList<T>* const list) {
    
    Node<T>* temp = list->ptrHead;

    while (temp != nullptr) {
        cout << temp->iData << " ";
        temp = temp->ptrNext;
    }

    cout << endl;

    return;
}

// Function to search for an element in the linked list
template <typename T>
Node<T>* searchElement(LinkedList<T>* const list, int iValue) {
    Node<T>* temp = nullptr;
    
    for (temp = list->ptrHead; temp != nullptr; temp = temp->ptrNext) {
        if (temp->iData == iValue) {
            return temp;
        }
    }
    return NULL;
}

// Function to remove an element from the linked list
template <typename T>
void removeElement(LinkedList<T>* const list, int iValue) {

    Node<T>* temp = searchElement(list, iValue);;
    Node<T>* garbage = nullptr;

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
template <typename T>
void freeList(LinkedList<T>* list) {
    Node<T>* current = list->ptrHead;
    Node<T>* previous = nullptr;

    while (current) {
        previous = current;
        current = current->ptrNext;

        free(previous);
    }

    list->ptrHead = nullptr;
    list->ptrTail = nullptr;
}

// Function to swap the data of two nodes
template <typename T>
void swapNodes(Node<T>* ptrNode1, Node<T>* ptrNode2) {

    int iTemp = ptrNode1->iData;

    ptrNode1->iData = ptrNode2->iData;
    ptrNode2->iData = iTemp;
}

template LinkedList<int>* newLinkedList<int>();
template LinkedList<float>* newLinkedList<float>();

template int getMax<int>(LinkedList<int>*);
template int getMax<float>(LinkedList<float>*);

template Node<int>* newNode<int>(int);
template Node<float>* newNode<float>(float);

template void showElements<int>(LinkedList<int>*);
template void showElements<float>(LinkedList<float>*);

template void addElement<int>(LinkedList<int>*, int);
template void addElement<float>(LinkedList<float>*, float);

template void swapNodes<int>(Node<int>*, Node<int>*);
template void swapNodes<float>(Node<float>*, Node<float>*);

template LinkedList<int>* listFromArray(int *arrValues, int iArraySize);