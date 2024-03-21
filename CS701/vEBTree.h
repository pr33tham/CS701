#ifndef VEBTREE_H
#define VEBTREE_H

/*
* Test the vEB once
*/

#define NIL -1

#include <iostream>
#include <vector>
#include <math.h>

class vEBTree {
public:
	int u;												//Universe Size
	int min;											//Minimum in this current tree
	int max;											//Maximum in this current tree
	vEBTree(int universeSize);							//Constructor with universe size
	void Insert(vEBTree& tree, int value);				//Insert value into tree
	void Delete(vEBTree& tree, int value);				//Delete value from tree
	int Predecessor(vEBTree& tree, int value);			//returns index of previous value 
	int Successor(vEBTree& tree, int value);			//returns index of next value
	int Minimum(vEBTree& tree) const;					//returns min value
	int Maximum(vEBTree& tree) const;					//returns max valu
	bool Member(vEBTree& tree, int value);				//returns boolean if value is in tree
protected:
	int sqrtU;											//precomputed squrare of universesize
	vEBTree* summary;									//summary vEB structure
	std::vector<vEBTree*> clusters;						//clusters of current vEB structure
	int High(int x) const;								//computes higher bits of value
	int	Low(int x) const;								//computes lower bits of value
	int Index(int x, int y) const;						//computes index
	void InsertEmptyTree(vEBTree& tree, int value);		//Empty tree helper to insert
};

#endif // !VEBTREE_H