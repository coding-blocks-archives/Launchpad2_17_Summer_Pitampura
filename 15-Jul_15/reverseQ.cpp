//using 2 queues
//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include "myqueue.h"
#include <iostream>
using namespace std;

void move(Queue& to, Queue& from) {
	//moves all elements from FROM to TO
	while (!from.empty()) {
		int cur = from.getFront();
		to.push(cur);
		from.pop();
	}
}


void myreverse(Queue& q) {
	Queue q1, q2;

	while (!q.empty()) {
		if (q1.empty()) {
			//push into q
			int cur = q.getFront();
			q.pop();
			q1.push(cur);
			move(q1, q2);
		}
		else {
			int cur = q.getFront();
			q.pop();
			q2.push(cur);
			move(q2, q1);
		}
	}

	if (q1.empty()) move(q, q2);
	else move(q, q1);


}


int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	myreverse(q);
	printQueue(q);
}