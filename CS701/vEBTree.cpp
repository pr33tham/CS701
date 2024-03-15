#include "vEBTree.h"

vEBTree::vEBTree(int universeSize) : u(universeSize) {
	min = NULL;
	max = NULL;
	if (u <= 2) {
		sqrtU = 0;
		summary = nullptr;
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

int vEBTree::Minimum(vEBTree tree) {
	return tree.min;
}

int vEBTree::Maximum(vEBTree tree) {
	return tree.max;
}

void vEBTree::Insert(vEBTree tree, int value) {
	if (tree.min == -1) InsertEmptyTree(tree, value);
	else if (value < tree.min) {
		std::swap(value, tree.min);
		if (tree.u > 2) {
			if (Minimum(*tree.clusters[High(value)]) == -1) {
				Insert(*tree.summary, High(value));
				InsertEmptyTree(*tree.clusters[High(value)], Low(value));
			}
			else Insert(*tree.clusters[High(value)], Low(value));
		}
		if (value > tree.max) tree.max = value;
	}
}

int vEBTree::Predecessor(vEBTree tree, int value) {
	if (tree.u == 2) {
		if (value == 1 && tree.min == 0) return 0;
		return -1;
	}
	else if (tree.max == -1 && value > tree.max) return tree.max;
	else {
		int minLow = Minimum(*tree.clusters[High(value)]);
		if (minLow != -1 && Low(value) > minLow) {
			int offset = Predecessor(*tree.clusters[High(value)], Low(value));
			return Index(High(value), offset);
		}
		else {
			int predCluster = Predecessor(*tree.summary, High(value));
			if (predCluster == -1) {
				if (tree.min != -1 && value > tree.min) return tree.min;
				return -1;
			}
			int offset = Maximum(*tree.clusters[predCluster]);
			return Index(predCluster, offset);
		}
	}
}

int vEBTree::Successor(vEBTree tree, int value) {
	if (tree.u == 2) {
		if (value == 0 && tree.max == 1) return 1;
		return -1;
	}
	else if (tree.min != -1 && value < tree.min) return tree.min;
	else {
		int maxLow = Maximum(*tree.clusters[High(value)]);
		if (maxLow != -1 && Low(value) < maxLow) {
			int offset = Successor(*tree.clusters[High(value)], Low(value));
			return Index(High(value), offset);
		}
		else {
			int succCluster = Successor(*tree.summary, High(value));
			if (succCluster == -1) {
				return -1;	
			}
			int offset = Minimum(*tree.clusters[succCluster]);
			return Index(succCluster, offset);
		}
	}
}

bool vEBTree::Member(vEBTree tree, int value) {
	if (value == tree.min || value == tree.max) return true;
	else if (tree.u == 2) return false;
	return Member(*tree.clusters[High(value)], Low(value));
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
	tree.min = value;
	tree.max = value;
}
