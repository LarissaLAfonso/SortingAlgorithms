#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

template <typename T>
struct TreeNode {
    T data;
    struct TreeNode* ptrLeft;
    struct TreeNode* ptrRight;
};

template <typename T>
void  bfsTraversal(TreeNode<T>* root);

template <typename T>
TreeNode<T>* createTreeNode(T data);

template <typename T>
TreeNode<T>* insertTreeNode(TreeNode<T>* startingNode, T data);

template <typename T>
void dfsInOrder(TreeNode<T>* startingNode);

TreeNode<int>* newRandomTree(int iTreeSize, int seed);

template <typename T>
TreeNode<T>* dfSearch(TreeNode<T>* startingNode, T data);

template<typename T>
TreeNode<T>* bfSearch(TreeNode<T>* root, T data);

#endif