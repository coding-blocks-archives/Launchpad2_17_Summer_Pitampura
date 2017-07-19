//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

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

int findLargest(Node * root) {
	static const int inf = 10000;
	if (root == NULL) {
		return -inf;
	}

	int res = root->data;	//root is not Null; NULL-->data
	for (int i = 0; i < root->nChild; ++i) {
		int childAns = findLargest(root->childArr[i]);
		res = max(res, childAns);
	}
	return res;
}

void printKthLevel(Node* root, int k) {
	//k shows level
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root->data << " ";
	}

	for (int i = 0; i < root->nChild; ++i) {
		printKthLevel(root->childArr[i], k - 1);
	}
}

void postOrder(Node* root) {
	if (root == NULL) {
		return;
	}

	//print children legt->right
	for (int i = 0; i < root->nChild; ++i) {
		postOrder(root->childArr[i]);
	}
	cout << root->data <<  " ";
}


int cntGreaterNodes(Node* root, int x) {
	if (root == NULL) {
		return 0;
	}

	int res = 0;
	if (root->data > x) res = res + 1;
	//check for EVERY SUBTREE
	for (int i = 0; i < root->nChild; ++i) {
		int subtreeAns = cntGreaterNodes(root->childArr[i], x);
		res += subtreeAns;
	}
	return res;
}

int familySum(Node* root){
	//calculating sum for current family	
	if (root == NULL){
		return 0;
	}

	int curSum = root->data;
	for (int i = 0; i < root->nChild; ++i) {
		curSum += root->childArr[i]->data;
	}
	return curSum;
}

Node* maxSumNode(Node* root) {
	if (root == NULL) {
		return NULL;
	}

	Node * ans = root;
	int curFamilySum = familySum(root);
	
	//for every subtree
	for(int i = 0; i < root->nChild; ++i){
		Node* childNode = maxSumNode(root->childArr[i]);	//best family in the subtree
		int childSum = familySum(childNode);

		if (curFamilySum < childSum){
			ans = childNode;
			curFamilySum = childSum; 
		}
	}

	return ans;
}



int main() {
	Node * root = NULL;
	root = createTree();
	// printTree(root);

	// int ans = findLargest(root);
	// cout << ans << endl;

	// printKthLevel(root, 2);

	// postOrder(root);

	// int res = cntGreaterNodes(root, 100);
	// cout << res;

	Node * ans = maxSumNode(root);
	if (ans) cout << ans->data;

}
