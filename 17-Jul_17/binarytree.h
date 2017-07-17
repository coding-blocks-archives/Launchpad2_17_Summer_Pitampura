#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* createTree(){
	int d;
	cin >> d;

	if (d == -1){
		return NULL;
	}

	Node * root = new Node(d);
	root->left = createTree();
	root->right = createTree();
	return root;

}

void preOrder(Node* root){
	//root left right

	if (root == NULL){
		return;
	}

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);

}

int height(Node* root){
	if (root == NULL){
		return 0;
	}

	return max(
		height(root->left),
		height(root->right)
		) + 1;
}


#endif