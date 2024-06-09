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

    // Create a linked list to store TreeNode pointers
    LinkedList<TreeNode<T>*>* list = new LinkedList<TreeNode<T>*>();
    list -> ptrHead = (Node<TreeNode<T>*>*)malloc(sizeof(Node<TreeNode<T>*>*)); // front
    list -> ptrTail = list -> ptrHead; // rear

    list -> ptrHead -> iData = root;

    Node<TreeNode<T>*>* currentNode = list -> ptrHead;
    
    while (currentNode != nullptr) 
    {
        
        cout << currentNode -> iData -> iData << " ";

        if (currentNode -> iData -> ptrLeft != nullptr)
        {
            list -> ptrTail -> ptrNext = newNode<TreeNode<T>*>(currentNode->iData->ptrLeft);
            list -> ptrTail = list -> ptrTail -> ptrNext;
        }
        
        if (currentNode -> iData -> ptrRight != nullptr)
        {
            list -> ptrTail -> ptrNext = newNode<TreeNode<T>*>(currentNode->iData->ptrRight);
            list -> ptrTail = list -> ptrTail -> ptrNext;
        }

        currentNode = currentNode -> ptrNext;
    }
}

template<typename T>
void dfsInOrder(TreeNode<T>* startingNode)
{
    if (startingNode != nullptr)
    {
        traversePreOrder(startingNode -> ptrLeft);
        cout << " " << startingNode -> iData;
        traversePreOrder(startingNode -> ptrRight);
    }
}

template TreeNode<int>* createNode(int iData);
template TreeNode<float>* createNode(float iData);

template TreeNode<int>* insertNode(TreeNode<int>* startingNode, int iData);
template TreeNode<float>* insertNode(TreeNode<float>* startingNode, float iData);

template void bfsTraversal(TreeNode<int>* root);
template void bfsTraversal(TreeNode<float>* root);

template void dfsInOrder(TreeNode<int>* startingNode);
template void dfsInOrder(TreeNode<float>* startingNode);

