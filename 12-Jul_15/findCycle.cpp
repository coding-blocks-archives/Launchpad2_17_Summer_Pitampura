//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "mylist.h"
using namespace std;

void setRandom(Node* head) {
	int len = lengthLL(head);

	srand(time(NULL));
	int randNo = rand() % len;

	int i = 0;
	Node* cur = head;
	Node* randNode = NULL;

	cout << randNo << endl;

	while (cur->next) {
		if (i == randNo) {
			randNode = cur;
		}
		++i;
		cur = cur->next;
	}

	// cout << randNo << " " << randNode->data << " " << cur->data;
	cur->next = randNode;
}

bool containCycle(Node* head) {
	Node *slow = head;		//ready
	Node *fast = head;		//set

	//GO
	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	// if (slow == fast) return true;
	// else return false;

	return slow == fast;
}




int main() {
	Node* head = createList();
	// printLL(head);

	setRandom(head);
	printLL(head);

	// Node* head = createList();
	// head->next->next->next->next->next  = head->next->next;
	// printLL(head);
	// cout << containCycle(head);

}