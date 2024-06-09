#ifndef _EVALTIME_H_
#define _EVALTIME_H_

float evalSortTime(int listSize, int seed, void (*func)(LinkedList<int>*));

float evalCreationTimeList(int iSize, int seed);
float evalCreationTimeTree(int iSize, int seed);

float evalSearchTimeList(int iSize, int seed, Node<int>* (*func)(LinkedList<int>*, int));
float evalSearchTimeTree(int iSize, int seed, TreeNode<int>* (*func)(TreeNode<int>*, int));

#endif