//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include "mylist.h"
#include <iostream>
using namespace std;

//iterative Reverse
Node* reverseList(Node* head){
	Node* prev = NULL;
	Node* cur = head;

	while(cur){
		Node* ahead = cur->next;
		cur->next = prev;
		prev = cur;
		cur = ahead;
	}

	return prev;
}

Node* reverseRec(Node* head){
	if (head == NULL || head->next == NULL){
		return head;
	}

	Node* smallhead = reverseRec(head->next);
	head->next->next = head;		//smart!!
	head->next = NULL;
	return smallhead;
}

int main(){
	Node* head = createList();
	printLL(head);

	// Node* reverseHead = reverseList(head);
	Node* reverseHead = reverseRec(head);
	printLL(reverseHead);

	return 0;	
}
