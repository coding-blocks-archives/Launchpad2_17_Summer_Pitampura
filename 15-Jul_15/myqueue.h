#ifndef MYQUEUE_H_
#define MYQUEUE_H_
#include <iostream>
using namespace std;

class Queue {
	//concept of nested class
	class Node {
	public:
		int data;
		Node* next;
		Node(int d) {
			data = d;
			next = NULL;
		}
	};

	int size;
	Node* front;
	Node* rear;
public:
	Queue() {
		front = NULL;
		rear = NULL;
		size = 0;
	}

	bool empty() {
		return front == NULL;
	}

	int getSize() {
		return size;
	}

	void push(int d) {
		Node* newNode = new Node(d);
		++size;

		if (front == NULL) {
			//was empty
			front = rear = newNode;
			return;
		}

		rear->next = newNode;
		rear = rear->next;	//rear move ahead
	}

	void pop(){
		if (empty()) return;

		Node* tmp = front->next;
		delete front;
		--size;
		if (size == 0) rear = NULL;

		front = tmp;
	}

	int getFront(){
		if (size == 0)	return -1;
		return front->data;
	}
};

void printQueue(Queue& Q){
	while(!Q.empty()){
		cout << Q.getFront() << " ";
		Q.pop();
		cout << endl;
	}
}
#endif
