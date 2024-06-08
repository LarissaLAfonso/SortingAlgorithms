#ifndef _EVALSORTTIME_H_
#define _EVALSORTTIME_H_

float evalSortTime(int listSize, int seed, void (*func)(LinkedList<int>*));

float evalBfsTime(int listSize, int seed, void (*func)(TreeNode<int>*));

#endif