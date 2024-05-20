#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

extern "C" {

    typedef struct Node {
        int iData;
        struct Node* ptrNext;
        struct Node* ptrPrev;
    } Node;

    typedef struct LinkedList {
        Node* ptrHead;
        Node* ptrTail;
    } LinkedList;

    int getMax(LinkedList* const list);

    LinkedList* newLinkedList();
    LinkedList* listFromArray(int *arriValues, int iArraySize);
    LinkedList* newRandomList(int iListSize, int seed=0);
    Node* newNode(int iValue);
    Node* searchElement(LinkedList* const list, int iValue);

    void addElement(LinkedList* list, int iValue);
    void showElements(LinkedList* list);
    void removeElement(LinkedList* list, int iValue);
    void swapNodes(Node* ptrNode1, Node* ptrNode2);
    void freeList(LinkedList* list);
    void invertList(LinkedList* list);
}

#endif