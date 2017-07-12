#ifndef LIST_H		//checks if BLOCK of code is already defined or not
#define LIST_H		//If not defines the below lines ending upto #endif

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

int lengthLL(Node * head) {
	int cnt = 0;
	while (head) {
		++cnt;
		head = head->next;
	}
	return cnt;
}

#endif