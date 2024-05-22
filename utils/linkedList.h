#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

template <typename T>
struct Node {
    T iData;
    struct Node* ptrNext;
    struct Node* ptrPrev;
};

template <typename T>
struct LinkedList {
    Node<T>* ptrHead;
    Node<T>* ptrTail;
};

template <typename T> 
Node<T>* newNode(T);

template <typename T> 
LinkedList<T>* newLinkedList();

template <typename T> LinkedList<T>* 
listFromArray(int *arriValues, int iArraySize);

LinkedList<int>* newRandomList(int, int);

template <typename T> 
int getMax(LinkedList<T>* const list);

template <typename T> 
void addElement(LinkedList<T>* list, T iValue);

template <typename T> 
void showElements(LinkedList<T>* list);

template <typename T> 
void swapNodes(Node<T>* ptrNode1, Node<T>* ptrNode2);

template <typename T> 
void freeList(LinkedList<T>* list);

#endif