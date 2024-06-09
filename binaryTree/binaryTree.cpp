#include "binaryTree.h"
#include "../linkedList/linkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
TreeNode<T>* createTreeNode(T iData)
{
    TreeNode<T>* temp = (TreeNode<T>*) malloc(sizeof(TreeNode<T>));

    temp->iData = iData;
    temp->ptrLeft = nullptr;
    temp->ptrRight = nullptr;

    return temp;
}

template <typename T>
TreeNode<T>* insertTreeNode(TreeNode<T>* startingNode, T iData)
{
    if (startingNode == nullptr)
        return createTreeNode(iData);

    if (iData < (startingNode->iData))
        startingNode->ptrLeft = insertTreeNode(startingNode->ptrLeft, iData);
    else
        startingNode->ptrRight = insertTreeNode(startingNode->ptrRight, iData);

    return startingNode;
}

template <typename T>
void bfsTraversal(TreeNode<T>* root) 
{
    if (root == nullptr)
        return;

    // Create a linked list to store TreeNode pointers
    LinkedList<TreeNode<T>*>* list = newLinkedList<TreeNode<T>*>();

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
        dfsInOrder(startingNode -> ptrLeft);
        cout << " " << startingNode -> iData;
        dfsInOrder(startingNode -> ptrRight);
    }
}

template TreeNode<int>* createTreeNode(int iData);
template TreeNode<float>* createTreeNode(float iData);

template TreeNode<int>* insertTreeNode(TreeNode<int>* startingNode, int iData);
template TreeNode<float>* insertTreeNode(TreeNode<float>* startingNode, float iData);

template void bfsTraversal(TreeNode<int>* root);
template void bfsTraversal(TreeNode<float>* root);

template void dfsInOrder(TreeNode<int>* startingNode);
template void dfsInOrder(TreeNode<float>* startingNode);

