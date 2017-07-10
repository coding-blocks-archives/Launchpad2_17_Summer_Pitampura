#include <iostream>
using namespace std;

class Node {
public:
	int data;	//public because they need to accessed in multiple functions outside the class
	Node * next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};


void printLL(Node* head) {
	Node * cur = head;
	while (cur != NULL) {
		cout << cur->data << "-->";
		cur = cur->next;	//take cur to the next element
	}
	cout << endl;
}

Node* insert(Node* head, int d) {
	Node* tmp = new Node(d);

	if (head == NULL) {
		//empty list
		return tmp;
	}

	// (*tmp).next = head;
	tmp->next = head;
	return tmp;
}


Node* createList(int n) {
	Node * head = NULL;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		head = insert(head, x);
	}
	return head;
}

Node* createList() {
	Node * head = NULL;
	int x;

	while (true) {
		cin >> x;
		if (x == - 1) break;
		head = insert(head, x);
	}
	return head;
}

Node* deleteNode(Node* head, int d) {
	Node* prev = NULL;
	Node* cur = head;

	while (cur != NULL) {
		if (cur->data == d) {
			//deletion mode
			if (prev == NULL) {
				// head to be deleted
				Node *tmp = cur->next;
				delete cur;
				return tmp;
			}
			else {
				prev->next = cur->next;
				delete cur;
			}
		}
		prev = cur;
		cur = cur->next;
	}
	return head;
}

int lengthLL(Node * head) {
	int cnt = 0;
	while (head) {
		++cnt;
		head = head->next;
	}
	return cnt;
}


Node* searchLL(Node* head, int x) {
	if (head == NULL) {
		return NULL;	//empty Node
	}

	if (head->data == x) {
		return head;
	}

	return searchLL(head->next, x);
}


Node* midPoint(Node* head) {
	Node * slow = head;	//ready
	Node * fast = head;	//ready
	//GO!!!
	while (slow && fast && fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


void bubbleSort(Node* &head) {
	int len = lengthLL(head);

	for (int i = 0; i < len; ++i) {
		Node * cur = head;
		Node * prev = NULL;

		// Node * ahead = cur->next;	it is not guaranteed that cur is NOT null
		while (cur && cur->next) {
			Node* ahead = cur->next;	//cur is guranteed NOT to be NULL

			if (cur->data > ahead->data) {
				// swap the nodes
				if (prev == NULL) {
					head = ahead;	//to keep track of head

					cur->next = ahead->next;
					ahead->next = cur;
					prev = ahead;
					ahead = cur->next;
				}
				else {
					//when prev is NOT null
					prev->next = ahead;
					cur->next = ahead->next;
					ahead->next = cur;
					prev = ahead;
					ahead = cur->next;

				}
			}
			else {
				prev = cur;
				cur = ahead;
				ahead = cur->next;	//ahead will be destroyed so can be avoided! But improves logic
			}
		}
	}

}

Node* last5th(Node* head) {
	Node* ahead = head;	
	Node* cur = head;	//ready


	int i = 1;			//ready
	while (i < 5 && ahead) {
		ahead = ahead->next;
		++i;
	}

	//go!
	while (ahead && ahead->next) {
		ahead = ahead->next;
		cur = cur->next;
	}

	return cur == head ? NULL : cur;
}


Node* mergeList(Node* A, Node* B){
	if (A == NULL){
		return B;
	}

	if (B == NULL){
		return A;
	}

	Node * ans = NULL;

	if (A->data < B->data){
		ans = A;
		ans->next = mergeList(A->next, B);	//recursion always works
	}
	else {
		ans = B;
		ans->next = mergeList(A, B->next);
	}
	return ans;
}


Node* mergeSort(Node* head){
	if (head == NULL || head->next == NULL){
		return head;
	}

	Node* mid = midPoint(head);
	Node* left = head;
	Node* right = mid->next;
	mid->next = NULL;

	left = mergeSort(left);
	right = mergeSort(right);
	return mergeList(left, right);	//left and right are merged inside mergeList
}


int main() {
	Node * head = NULL;

	int n;
	// cin >> n;
	// head = createList();
	// printLL(head);

	// cin >> n;
	// head = deleteNode(head, n);
	// printLL(head);

	// int len = lengthLL(head);
	// cout << len << endl;

	// cin >> n;
	// Node * res = searchLL(head, n);
	// cout << res << " ";
	// if (res != NULL) cout << res->data << endl;

	// cout << res << " " << res->data << endl;		//SEG Fault if res is NULL

	// Node* mid = midPoint(head);
	// cout << mid << " " << (mid ? mid->data : -1) << endl;

	// bubbleSort(head);
	// printLL(head);

	// Node * lastFifth = last5th(head);
	// cout << lastFifth << " ";
	// if (lastFifth) cout << lastFifth->data << endl;

	// Node* X = createList();
	// Node* Y = createList();
	// printLL(X);
	// printLL(Y);
	// Node* res = mergeList(X, Y);
	// printLL(res);

	// head = createList();
	// printLL(head);
	// head = mergeSort(head);
	// printLL(head);
}