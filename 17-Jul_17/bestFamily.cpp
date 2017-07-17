//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include "genericTree.h"
#include <iostream>
using namespace std;

class Pair {
public:
	Node* node;	//note capital N
	int sum;
};

Pair getMaxSum(Node* root) {
	if (root == NULL) {
		//base case
		Pair P;
		P.node = NULL;
		P.sum = 0;
		return P;
	}

	Pair curAns;
	curAns.node = root;
	curAns.sum = root->data;
	//calculating family
	for (int i  = 0; i < root->nChild; ++i) {
		curAns.sum += root->childArr[i]->data;
	}

	//for every subtree
	for (int i = 0; i < root->nChild; ++i) {
		Pair X = getMaxSum(root->childArr[i]);
		if (curAns.sum < X.sum) {
			curAns.sum = X.sum;
			curAns.node = X.node;
		}
	}
	return curAns;
}



int main() {
	Node * root = createTree();

	Pair solPair = getMaxSum(root);

	cout << solPair.node << " " << solPair.node->data << " " << solPair.sum;



}