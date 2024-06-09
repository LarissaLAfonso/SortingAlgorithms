#ifndef _BFS_LINKED_LIST_H_
#define _BFS_LINKED_LIST_H_

template <typename T>
struct TreeNode {
    T iData;
    struct TreeNode* ptrLeft;
    struct TreeNode* ptrRight;
};

template <typename T>
void  bfsTraversal(TreeNode<T>* root);

template <typename T>
TreeNode<T>* createNode(T iData);

template <typename T>
TreeNode<T>* insertNode(TreeNode<T>* startingNode, T iData);

template <typename T>
void dfsInOrder(TreeNode<T>* startingNode);

#endif // BFS_LINKED_LIST_H