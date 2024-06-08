#include "bfsLinkedList.h"
#include "linkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
TreeNode<T>* createNode(T iData)
{
    TreeNode<T>* tmp = (TreeNode<T>*) malloc(sizeof(TreeNode<T>));

    tmp->iData = iData;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;

    return tmp;
}

template <typename T>
TreeNode<T>* insertNode(TreeNode<T>* startingNode, T iData)
{
    if (startingNode == nullptr)
        return createNode(iData);

    if (iData < (startingNode->iData))
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    else
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);

    return startingNode;
}

template <typename T>
void bfsTraversal(TreeNode<T>* root) 
{
    if (root == nullptr)
        return;

    // Criando lista de valores
    LinkedList<T>* list = new LinkedList<T>();
    list -> ptrHead = (Node<T>*)malloc(sizeof(Node<T>*)); // front
    list -> ptrTail = list -> ptrHead; // rear

    // Os valores que queremos colocar na lista, mas de tipo TreeNode
    //TreeNode<T>* treeRearNode = nullptr;
    //TreeNode<T>* treeFrontNode = root;

    //Node<T>* treeHead = newNode(treeFrontNode->iData);

    // Os valores que queremos colocar na lista, mas transformados para tipo Node
    //Node<T>* rearNode = treeHead -> ptrNext;
    //Node<T>* frontNode = treeHead;

    list -> ptrHead -> iData = root;

    Node<T>* currentNode = list -> ptrHead;
    
    while (currentNode != (list -> ptrTail))
    {
        
        cout << currentNode -> iData -> iData << " ";

        if (currentNode -> iData -> ptrLeft != nullptr)
        {
            list -> ptrTail -> ptrNext = newNode(currentNode->ptrLeft->iData);
            list -> ptrTail = list -> ptrTail -> ptrNext;
        }
        
        if (currentNode -> iData -> ptrRight != nullptr)
        {
            list -> ptrTail -> ptrNext = newNode(currentNode->ptrRight->iData);
            list -> ptrTail = list -> ptrTail -> ptrNext;
        }
    }
}