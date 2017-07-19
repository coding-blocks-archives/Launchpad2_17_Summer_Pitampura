#ifndef _BST_H
#define _BST_H
#include <iostream>
#include <queue>
using namespace std;

class BSTNode {	//struct by default public
public:
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
//BST Node exactly same as Node since it is a constrained BT
};

BSTNode* insertInBST(BSTNode* root, int d) {
	if (root == NULL) {
		//insertion in empty tree
		BSTNode * newNode = new BSTNode(d);
		return newNode;
	}

	//i have atleast one node in bst
	if (d < root->data) {
		BSTNode *updatedTree = insertInBST(root->left, d);
		root->left = updatedTree;
	}

	else {
		root->right = insertInBST(root->right, d );
	}

	return root;
}

BSTNode* createBST() {
	int d;
	BSTNode* root = NULL;

	while (cin >> d && d != -1) {
		root = insertInBST(root, d);
	}
	return root;
}


void inorder(BSTNode* root){
	if (root == NULL){
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void levelOrder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	queue<BSTNode*> q;
	q.push(root);
	q.push(NULL);
	
	while (q.empty() == false) {
		BSTNode* cur = q.front();
		q.pop();

		if (cur == NULL){
			cout << endl;
			if (!q.empty()) q.push(NULL);
			continue;
		}

		cout << cur->data << " ";
		if (cur->left) {
			q.push(cur->left);
		}

		if (cur->right) {
			q.push(cur->right);
		}
	}

}

#endif