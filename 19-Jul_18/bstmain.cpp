//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include <cmath>		//for abs()
#include "bst.h"
#include "binarytree.h"
using namespace std;

void printkk(BSTNode* root, int k1, int k2) {
	if (root == NULL) {
		return;
	}

	//if root lies within the range
	if (root->data >= k1 && root->data <= k2) {
		cout << root->data << " ";
	}

	if (k1 < root->data) {
		printkk(root->left, k1, k2);
	}

	if (k2 > root->data) {
		printkk(root->right, k1, k2);
	}
}


typedef pair<BSTNode*, BSTNode*> pbb;

pbb convertToLL(BSTNode* root) {
	if (root == NULL) {
		pbb P(NULL, NULL);
		return P;
	}

	pbb leftPair = convertToLL(root->left);
	pbb rightPair = convertToLL(root->right);

	//pair.first --> head
	//pair.second --> tail
	pbb ans(NULL, NULL);

	//if leftPair/left LL exists
	if (leftPair.second) {
		leftPair.second->right = root;
		ans.first = leftPair.first;
	}
	else {
		ans.first = root;
	}

	//if rightPair/right LL exists
	if (rightPair.first) {
		root->right = rightPair.first;
		ans.second = rightPair.second;
	}
	else {
		ans.second = root;
	}
	return ans;
}

BSTNode* findBST(BSTNode* root, int x) {
	if (root == NULL) return NULL;

	if (root->data == x) return root;

	if (x < root->data) return findBST(root->left, x);

	else return findBST(root->right, x);
}


bool isBST(Node* root, int myMin, int myMax) {
	if (root == NULL) {
		return true;
	}

	// bool leftAns = isBST(root->left, myMin, root->data);
	// bool rightAns = isBST(root->right, root->data, myMax);
	// return leftAns && rightAns && (root->data >= myMin && root->data <= myMax);

	//short circuit evaluation
	return (root->data >= myMin && root->data <= myMax) &&
	       isBST(root->left, myMin, root->data) && isBST(root->right, root->data, myMax);
}

typedef pair<bool, int> pbi;
pbi isBalanced(Node* root){
	if (root == NULL){
		pbi P(true, 0);
		return P;
	}

	pbi leftAns = isBalanced(root->left);
	pbi rightAns = isBalanced(root->right);

	pbi ans(false, 0);
	int curHtDiff = abs(leftAns.second - rightAns.second);
	
	if (curHtDiff <= 1){
		//curNode is Balanced
		//But the tree is Bal??
		ans.first = leftAns.first && rightAns.first;
	}

	int curHt = 1 + max(leftAns.second, rightAns.second);
	ans.second = curHt;
	return ans;
}

BSTNode* arrToBST(int arr[], int be, int en){
	if (be > en){
		return NULL;
	}

	int mid = (be + en) / 2;
	BSTNode* root = new BSTNode(arr[mid]);

	root->left = arrToBST(arr, be, mid - 1);
	root->right = arrToBST(arr, mid + 1, en);
	return root;
}



int main() {
	// BSTNode* root = createBST();
	// levelOrder(root);
	// cout << endl;
	// inorder(root);

	// int k1, k2; cin >> k1 >> k2;
	// printkk(root, k1, k2);

	// int n; cin >> n;
	// BSTNode* ans = findBST(root, n);
	// cout << ans << " " << ans->data;

	// pbb ans = convertToLL(root);
	// BSTNode* head = ans.first;
	// while(head){
	// 	cout << head->data << "-->";
	// 	head = head->right;
	// }

	// Node * root = createTree();
	// const int inf = (int)1e8;
	// cout << isBST(root, -inf, inf);

	// Node* root = createTree();
	// pbi ans = isBalanced(root);
	// cout << ans.first << " " << ans.second << endl;

	int arr[10];
	int n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	BSTNode* root = arrToBST(arr, 0, n - 1);
	inorder(root);
	cout << endl;
	levelOrder(root);

}