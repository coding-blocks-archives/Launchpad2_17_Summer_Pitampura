#ifndef _GENERIC_TREE_H
#define _GENERIC_TREE_H
#include <iostream>
using namespace std;
class Node {
public:
	int data;
	int nChild;	//number of children
	Node** childArr;
	Node(int d, int n) {
		data = d;
		nChild = n;
		if (nChild == 0) {
			childArr = NULL;
		}
		else {
			childArr = new Node*[nChild];
		}
	}
};


Node* createTree() {
	int d, n;
	cin >> d;

	if (d == -1) {
		return NULL;
	}

	cin >> n;
	Node * root = new Node(d, n);
	for (int i = 0; i < root->nChild; ++i) {
		root->childArr[i] = createTree();
	}
	return root;
}

void printTree(Node* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	for (int i = 0; i < root->nChild; ++i) {
		printTree(root->childArr[i]);
	}
}

#endif