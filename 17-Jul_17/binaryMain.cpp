//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include "binarytree.h"
#include <iostream>
#include <utility>	//for pair
#include <queue>
using namespace std;

int cntNodes(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftCnt = cntNodes(root->left);
	int rgtCnt = cntNodes(root->right);
	int curCnt = leftCnt + 1 + rgtCnt;
	return curCnt;
}

int diameter(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int lftDia = diameter(root->left);
	int rgtDia = diameter(root->right);

	int curDia = height(root->left) + 1 + height(root->right);

	return max(curDia, max(lftDia, rgtDia));
}

pair<int, int> diameterFast(Node* root) {
	if (root == NULL) {
		pair<int, int> P(0, 0);
		return P;
	}

	pair<int, int> lftAns = diameterFast(root->left);
	pair<int, int> rgtAns = diameterFast(root->right);

	pair<int, int> curAns;
	// curAns.first  diameter
	// curAns.second height

	//compute current height
	curAns.second = max(lftAns.second, rgtAns.second) + 1;

	//compute current diameter
	// int curDia = height(root->left) + 1 + height(root->right);
	int curDia = lftAns.second + 1 + rgtAns.second;
	curAns.first = max(curDia, max(lftAns.first, rgtAns.first));

	return curAns;
}

Node* findNode(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == x) {
		return root;
	}

	Node* lftAns = findNode(root->left, x);
	if (lftAns) return lftAns;

	return findNode(root->right, x);
}

Node* mirror(Node* root) {
	if (root == NULL) {
		return NULL;
	}

	Node * lft = mirror(root->left);
	Node * rgt = mirror(root->right);
	root->left = rgt;
	root->right = lft;
	return root;
}


Node* levelOrderInput() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}

	Node* root = new Node(d);
	queue<Node *> q;	//queue of Node*
	q.push(root);
	while (q.empty() == false) {
		Node * cur = q.front();
		q.pop();

		cin >> d;
		if (d != -1) {
			cur->left = new Node(d);
			q.push(cur->left);
		}

		cin >> d;
		if (d != -1) {
			cur->right = new Node(d);
			q.push(cur->right);
		}
	}

	return root;
}

void printLevel(Node* root) {
	if (root == NULL) {
		return;
	}

	queue<Node*> q;
	q.push(root);
	while (q.empty() == false) {
		Node* cur = q.front();
		q.pop();
		cout << cur->data << " ";

		if (cur->left) {
			q.push(cur->left);
		}

		if (cur->right) {
			q.push(cur->right);
		}
	}

}


void printLevelAdv(Node* root) {
	if (root == NULL) return ;

	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while (q.empty() == false) {
		Node * cur = q.front();
		q.pop();
		if (cur == NULL) {
			cout << endl;

			if (q.empty() == false) q.push(NULL);
			continue;
		}

		cout << cur->data << " ";
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);
	}
}

int search(int arr[], int be, int en, int x) {
	//searches x into logical arr [be, en]
	while (be <= en) {
		if (arr[be] == x) {
			return be;
		}
		be++;
	}
}

Node* seqToTree(int inorder[], int in_be, int in_en, int preOrder_arr[], int& preIndex) {
	// static int preIndex = 0;
	if (in_be > in_en) {
		return NULL;
	}

	int curEle = preOrder_arr[preIndex];
	++preIndex;
	Node * root = new Node(curEle);

	int idx = search(inorder, in_be, in_en, curEle);

	root->left = seqToTree(inorder, in_be, idx - 1, preOrder_arr, preIndex);
	root->right = seqToTree(inorder, idx + 1, in_en, preOrder_arr, preIndex);
	return root;
}



int main() {
	// Node * root = createTree();
	// Node * root =  levelOrderInput();
	// preOrder(root);

	// int ans = cntNodes(root);
	// cout << ans << endl;

	// int ht = height(root);
	// cout << ht << endl;

	// int dia = diameter(root);
	// cout << dia << endl;

	// pair<int, int> p = diameterFast(root);
	// cout << p.first << " " << p.second << " ";

	// int n; cin >> n;
	// Node* ans = findNode(root, n);
	// cout << ans->data;

	// root = mirror(root);
	// preOrder(root);

	// printLevelAdv(root);

	int in[] = {1, 2, 3, 4, 5, 6, 7};
	int pre[] = {4, 2, 1, 3, 6, 5, 7};
	// int pre[] = {1, 2, 3, 4, 5, 6, 7};

	int preIndex = 0;
	Node * root = seqToTree(in, 0, 6, pre, preIndex);
	printLevelAdv(root);
}