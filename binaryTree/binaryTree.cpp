#include <iostream>

#include "binaryTree.h"
#include "../linkedList/linkedList.h"

using namespace std;

template<typename T>
TreeNode<T>* createTreeNode(T data)
{
    TreeNode<T>* temp = (TreeNode<T>*) malloc(sizeof(TreeNode<T>));

    temp->data = data;
    temp->ptrLeft = nullptr;
    temp->ptrRight = nullptr;

    return temp;
}

template <typename T>
TreeNode<T>* insertTreeNode(TreeNode<T>* startingNode, T data)
{
    if (startingNode == nullptr)
        return createTreeNode(data);

    if (data < (startingNode->data))
        startingNode->ptrLeft = insertTreeNode(startingNode->ptrLeft, data);
    else
        startingNode->ptrRight = insertTreeNode(startingNode->ptrRight, data);

    return startingNode;
}

template <typename T>
void deleteTree(TreeNode<T>* root)
{
    if (root == nullptr)
        return;

    deleteTree(root->ptrLeft);
    deleteTree(root->ptrRight);

    free(root);
}

TreeNode<int>* newRandomTree(int iTreeSize, int seed) {
    TreeNode<int>* temp = nullptr;

    srand(seed);

    for (int i = 0; i<iTreeSize; i++) {
        int iRandNum = rand() % 100 + 1;
        temp = insertTreeNode(temp, iRandNum);
    }

    return temp;
}


template <typename T>
void bfsTraversal(TreeNode<T>* root) 
{
    if (root == nullptr)
        return;

    // Create a linked list to store TreeNode pointers
    LinkedList<TreeNode<T>*>* list = newLinkedList<TreeNode<T>*>();

    list->ptrHead = (Node<TreeNode<T>*>*)malloc(sizeof(Node<TreeNode<T>*>*)); // front
    list->ptrTail = list->ptrHead; // rear

    list->ptrHead->data = root;

    Node<TreeNode<T>*>* currentNode = list->ptrHead;
    
    while (currentNode != nullptr) 
    {
        
        cout << currentNode->data->data << " ";

        if (currentNode->data->ptrLeft != nullptr)
        {
            list->ptrTail->ptrNext = newNode<TreeNode<T>*>(currentNode->data->ptrLeft);
            list->ptrTail = list->ptrTail->ptrNext;
        }
        
        if (currentNode->data->ptrRight != nullptr)
        {
            list->ptrTail->ptrNext = newNode<TreeNode<T>*>(currentNode->data->ptrRight);
            list->ptrTail = list->ptrTail->ptrNext;
        }

        currentNode = currentNode->ptrNext;
    }
}

template<typename T>
void dfsInOrder(TreeNode<T>* startingNode)
{
    if (startingNode != nullptr)
    {
        dfsInOrder(startingNode->ptrLeft);
        cout << " " << startingNode->data;
        dfsInOrder(startingNode->ptrRight);
    }
}

template<typename T>
void dfsPostOrder(TreeNode<T>* startingNode)
{
    if (startingNode != nullptr)
    {
        dfsPostOrder(startingNode->ptrLeft);
        dfsPostOrder(startingNode->ptrRight);
        cout << " " << startingNode->data;
    }
}

template<typename T>
void dfsPreOrder(TreeNode<T>* startingNode)
{
    if (startingNode != nullptr)
    {
        cout << " " << startingNode->data;
        dfsPreOrder(startingNode->ptrLeft);
        dfsPreOrder(startingNode->ptrRight);
    }
}


template<typename T>
TreeNode<T>* dfSearch(TreeNode<T>* startingNode, T data)
{
    if (startingNode == nullptr)
        return nullptr;

    if (startingNode->data == data)
        return startingNode;

    if (data < startingNode->data)
        return dfSearch(startingNode->ptrLeft, data);
    else
        return dfSearch(startingNode->ptrRight, data);
}

template<typename T>
TreeNode<T>* bfSearch(TreeNode<T>* root, T data) {
    if (root == nullptr)
        return nullptr;

    if (root->data == data)
        return root;

    // Create a linked list to store TreeNode pointers
    LinkedList<TreeNode<T>*>* list = newLinkedList<TreeNode<T>*>();

    list->ptrHead = (Node<TreeNode<T>*>*) malloc(sizeof(Node<TreeNode<T>*>*)); // front
    list->ptrTail = list->ptrHead; // rear

    list->ptrHead->data = root;

    Node<TreeNode<T>*>* currentNode = list->ptrHead;
    
    while (currentNode != nullptr) 
    {
        if (currentNode->data->ptrLeft != nullptr)
        {
            if (currentNode->data->ptrLeft->data == data)
                return currentNode->data->ptrLeft;
            list->ptrTail->ptrNext = newNode<TreeNode<T>*>(currentNode->data->ptrLeft);
            list->ptrTail = list->ptrTail->ptrNext;
        }
        
        if (currentNode->data->ptrRight != nullptr)
        {
            if (currentNode->data->ptrRight->data == data)
                return currentNode->data->ptrRight;
            list->ptrTail->ptrNext = newNode<TreeNode<T>*>(currentNode->data->ptrRight);
            list->ptrTail = list->ptrTail->ptrNext;
        }

        currentNode = currentNode->ptrNext;
    }

    return nullptr;
}


template TreeNode<int>* createTreeNode(int data);
template TreeNode<float>* createTreeNode(float data);

template TreeNode<int>* insertTreeNode(TreeNode<int>* startingNode, int data);
template TreeNode<float>* insertTreeNode(TreeNode<float>* startingNode, float data);

template void bfsTraversal(TreeNode<int>* root);
template void bfsTraversal(TreeNode<float>* root);

template void dfsInOrder(TreeNode<int>* startingNode);
template void dfsInOrder(TreeNode<float>* startingNode);

template TreeNode<int>* dfSearch(TreeNode<int>* startingNode, int data);

template TreeNode<int>* bfSearch(TreeNode<int>* root, int data);
template TreeNode<float>* bfSearch(TreeNode<float>* root, float data);

template void deleteTree(TreeNode<int>* root);
template void deleteTree(TreeNode<float>* root);