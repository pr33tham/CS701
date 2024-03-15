#include "vEBTree.h"

vEBTree::vEBTree(int universeSize) : u(universeSize) {
	min = NIL;
	max = NIL;
	if (u == 2) {
		sqrtU = 0;
		summary = nullptr;
		clusters = std::vector<vEBTree*>(0, nullptr);
	}
	else {
		sqrtU = ceil(sqrt(u));
		summary = new vEBTree(sqrtU);
		clusters = std::vector<vEBTree*>(sqrtU, nullptr);
		
		for (int i = 0; i < sqrtU; i++) {
			clusters[i] = new vEBTree(sqrtU);
		}
	}
}

vEBTree::~vEBTree() {
	if (u != 2) {
		delete summary;
		for (int i = 0; i < sqrtU; i++) {
			clusters[i]->~vEBTree();
			delete clusters[i];
		}
	}
}

void vEBTree::Insert(vEBTree tree, int value) {
	if (min == NIL) InsertEmptyTree(tree, value);
	else if (value < min) {
		std::swap(value, min);
		if (u == 2) {
			if (Minimum(*clusters[High(value)]) == NIL) {
				Insert(*summary, High(value));
				InsertEmptyTree(*clusters[High(value)], Low(value));
			}
			else Insert(*clusters[High(value)], Low(value));
		}
		if (value > max) max = value;
	}
}

void vEBTree::Delete(vEBTree tree, int value) {
	if (min == max) {
		min = NIL;
		max = NIL;
	}
	else if (u == 2) {
		if (value == 0) min = 1;
		else min = 0;
	}
	else if (value == min) {
		int firstCluster = Minimum(*summary);
		value = Index(firstCluster, Minimum(*clusters[firstCluster]));
		min = value;
		Delete(*clusters[High(value)], Low(value));
		if (Minimum(*clusters[High(value)]) == NIL) {
			Delete(*summary, High(value));
			if (value == max) {
				int summaryMax = Maximum(*summary);
				if (summaryMax == NIL) max = min;
				else {
					max = Index(summaryMax, Maximum(*clusters[summaryMax]));
				}
			}
			else if (value == max) {
				max = Index(High(value), Maximum(*clusters[High(value)]));
			}
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

void vEBTree::InsertEmptyTree(vEBTree tree, int value) {
	min = value;
	max = value;
}

int vEBTree::Predecessor(vEBTree tree, int value) {
	if (u == 2) {
		if (value == 1 && min == 0) return 0;
		return NIL;
	}
	else if (max != NIL && value > max) return max;
	else {
		int minLow = Minimum(*clusters[High(value)]);
		if (minLow != NIL && Low(value) > minLow) {
			int offset = Predecessor(*clusters[High(value)], Low(value));
			return Index(High(value), offset);
		}
		else {
			int predCluster = Predecessor(*summary, High(value));
			if (predCluster == NIL) {
				if (min != NIL && value > min) return min;
				return min;
			}
			else {
				int offset = Maximum(*clusters[predCluster]);
				return Index(predCluster, offset);
			}
		}
	}
}

int vEBTree::Successor(vEBTree tree, int value) {
	if (u == 2) {
		if (value == 0 && max == 1) return 1;
		return NIL;
	}
	else if (min != NIL && value < min) return min;
	else {
		int maxLow = Maximum(*clusters[High(value)]);
		if (maxLow != NIL && Low(value) < maxLow) {
			int offset = Successor(*clusters[High(value)], Low(value));
			return Index(High(value), offset);
		}
		else {
			int succCluster = Successor(*summary, High(value));
			if (succCluster == NIL) return NIL;
			int offset = Minimum(*clusters[succCluster]);
			return Index(succCluster, offset);
		}
	}
}

int vEBTree::Minimum(vEBTree tree) const{
	return min;
}

int vEBTree::Maximum(vEBTree tree) const {
	return max;
}

bool vEBTree::Member(vEBTree tree, int value) {
	if (value == min || value == max) return true;
	else if (u == 2) return false;
	return Member(*clusters[High(value)], Low(value));
}
