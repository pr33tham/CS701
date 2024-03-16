#include "vEBTree.h"

vEBTree::vEBTree(int universeSize) : u(universeSize), min(NIL), max(NIL), sqrtU(ceil(sqrt(u))) {
	if (u == 2) {
		summary = nullptr;
		clusters = std::vector<vEBTree*>(0, nullptr);
	}
	else {
		summary = new vEBTree(sqrtU);
		clusters.resize(sqrtU, nullptr);
		
		for (int i = 0; i < sqrtU; i++) {
			clusters[i] = new vEBTree(sqrtU);
		}
	}
}

void vEBTree::Insert(vEBTree& tree, int value) {
	if (tree.min == NIL) InsertEmptyTree(tree, value);
	else {
		if (value < tree.min) {
			std::swap(value, tree.min);
		}
		if (tree.u > 2) {
			if (Minimum(*tree.clusters[High(value)]) == NIL) {
				Insert(*tree.summary, High(value));
				InsertEmptyTree(*tree.clusters[High(value)], Low(value));
			}
			else Insert(*tree.clusters[High(value)], Low(value));
		}
		if (value > tree.max) tree.max = value;
	}
}

void vEBTree::Delete(vEBTree& tree, int value) {
	if (tree.min == tree.max) {
		tree.min = NIL;
		tree.max = NIL;
	}
	else if (tree.u == 2) {
		if (value == 0) tree.min = 1;
		else tree.min = 0;
	}
	else {
		if (value == tree.min) {
			int firstCluster = Minimum(*tree.summary);
			value = Index(firstCluster, Minimum(*tree.clusters[firstCluster]));
			tree.min = value;
		}
		Delete(*tree.clusters[High(value)], Low(value));
		if (Minimum(*tree.clusters[High(value)]) == NIL) {
			Delete(*tree.summary, High(value));
			if (value == tree.max) {
				int summaryMax = Maximum(*tree.summary);
				if (summaryMax == NIL) tree.max = tree.min;
				else {
					tree.max = Index(summaryMax, Maximum(*tree.clusters[summaryMax]));
				}
			}
		}
		else if (value == tree.max) {
			tree.max = Index(High(value), Maximum(*tree.clusters[High(value)]));
		}
	}
}

int vEBTree::High(int x) const {
	return x / sqrtU;
}

int vEBTree::Low(int x) const {
	return x % sqrtU;
}

int vEBTree::Index(int x, int y) const {
	return x * sqrtU + y;
}

void vEBTree::InsertEmptyTree(vEBTree& tree, int value) {
	tree.min = value;
	tree.max = value;
}

int vEBTree::Predecessor(vEBTree& tree, int value) {
	if (tree.u == 2) {
		if (value == 1 && min == 0) return 0;
		return NIL;
	}
	else if (tree.max != NIL && value > tree.max) return tree.max;
	else {
		int minLow = Minimum(*tree.clusters[High(value)]);
		if (minLow != NIL && Low(value) > minLow) {
			int offset = Predecessor(*clusters[High(value)], Low(value));
			return Index(High(value), offset);
		}
		else {
			int predCluster = Predecessor(*tree.summary, High(value));
			if (predCluster == NIL) {
				if (min != NIL && value > min) return min;
				return min;
			}
			else {
				int offset = Maximum(*tree.clusters[predCluster]);
				return Index(predCluster, offset);
			}
		}
	}
}

int vEBTree::Successor(vEBTree& tree, int value) {
	if (tree.u == 2) {
		if (value == 0 && tree.max == 1) return 1;
		return NIL;
	}
	else if (tree.min != NIL && value < tree.min) return tree.min;
	else {
		int maxLow = Maximum(*tree.clusters[High(value)]);
		if (maxLow != NIL && Low(value) < maxLow) {
			int offset = Successor(*tree.clusters[High(value)], Low(value));
			return Index(High(value), offset);
		}
		else {
			int succCluster = Successor(*tree.summary, High(value));
			if (succCluster == NIL) return NIL;
			int offset = Minimum(*tree.clusters[succCluster]);
			return Index(succCluster, offset);
		}
	}
}

int vEBTree::Minimum(vEBTree& tree) const{
	return tree.min;
}

int vEBTree::Maximum(vEBTree& tree) const {
	return tree.max;
}

bool vEBTree::Member(vEBTree& tree, int value) {
	if (value == tree.min || value == tree.max) return true;
	else if (tree.u == 2) return false;
	return Member(*tree.clusters[High(value)], Low(value));
}
