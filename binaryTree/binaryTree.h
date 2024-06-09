#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

template <typename T>
struct TreeNode {
    T iData;
    struct TreeNode* ptrLeft;
    struct TreeNode* ptrRight;
};

template <typename T>
void  bfsTraversal(TreeNode<T>* root);

template <typename T>
TreeNode<T>* createTreeNode(T iData);

template <typename T>
TreeNode<T>* insertTreeNode(TreeNode<T>* startingNode, T iData);

template <typename T>
void dfsInOrder(TreeNode<T>* startingNode);

#endif