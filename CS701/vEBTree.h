#ifndef VEBTREE_H
#define VEBTREE_H

/*************************************************************************
 *
 *  Pace University
 *  Spring 2024
 *  Advanced Algorithms
 *
 *  Course: CS 701-801
 *  Name: RUTHWIK PREETHAM, SURAPARAJU
 *  Collaborators: NONE
 *  References: NONE
 *
 *  Assignment: #1
 *  Problem: Write two generic classes: BinaryHeapPriorityQueue<T> and vEBTree<T>, with methods ExtractMax(), Insert(value,priority),
 *	IncreaseKey(value,priority), and a constructor to create the data structure and populate it with a parametric collection of n items. (You may
 *	include other methods if you want, but these are the required.) Your methods must implement the pseudocode included in our textbook (3rd edition,
 *	Chapters 6 and 20). No points for code implementing other algorithms. Description: PUT A BRIEF DESCRIPTION HERE
 *  
 *	Input:
 *  Output:
 *
 *  Visible data fields:
 *
 *
 *  Visible methods:
 *
 *
 *   Remarks
 *   -------
 *
 *   PUT ALL NON-CODING ANSWERS HERE
 *
 *
 *
 *************************************************************************/


/*
* Test the vEB once
*/

#define NIL std::numeric_limits<int>::min()

#include <iostream>
#include <vector>
#include <math.h>

class vEBTree {
public:
	int u;
	vEBTree(int universeSize);
	~vEBTree();
	void Insert(vEBTree tree, int value);
	void Delete(vEBTree tree, int value);
	int Predecessor(vEBTree tree, int value);
	int Successor(vEBTree tree, int value);
	int Minimum(vEBTree tree) const;
	int Maximum(vEBTree tree) const;
	bool Member(vEBTree tree, int value);
	void showData();
protected:
	int min;
	int max;
	int sqrtU;
	vEBTree* summary;
	std::vector<vEBTree*> clusters;
	int High(int x) const;
	int	Low(int x) const;
	int Index(int x, int y) const;
	void InsertEmptyTree(vEBTree tree, int value);
};

#endif // !VEBTREE_H