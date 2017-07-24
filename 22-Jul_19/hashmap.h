#ifndef _HASH_MAP_
#define _HASH_MAP_
#include <string>
using namespace std;

class Pair {
public:
	string key;
	int value;
	//ctor with no args
	Pair() {
		key = "";
		value = 0;
	}

	//ctor with 2 args
	Pair(string k, int v) {
		key = k;
		value = v;
	}

};

class Node {
public:
	Pair P;	//object of "some" class used inside
	Node* next;
	//ctor
	Node(Pair X) {
		P = X;
		next = NULL;
	}
};

class HashMap {
	Node * *table;
	int sze;
	int capacity;

	int hashFunction(string s) {
		int ans = 0;
		int mul = 1;

		//ans = s[0] * 37^0 + s[1]*37^1 + s[2]*37[2] + ...
		for (int i = 0; i < s.size(); ++i) {
			ans = (ans + (s[i] * mul) % capacity) % capacity;
			mul = (mul * 37) % capacity;
		}

		int idx = ans % capacity;
		return idx;
	}

	double load_factor(){
		return (double)sze / capacity;
	}

	template <typename T>
	void clear(T arr, int n, Node* valToSet){
		for(int i = 0; i < n; ++i){
			arr[i] = valToSet;
		}
	}

	void rehash(){
		Node** oldTable = table;
		int old_capacity = capacity;
		int sze = 0;

		capacity = 2 * capacity;
		table = new Node*[capacity];
		clear(table, capacity, NULL);

		//for every node in every linked list
		for(int i = 0; i < old_capacity; ++i){
			Node * head = oldTable[i];		//cur linked list
			while(head){
				string k = head->P.key;
				int v = head->P.value ;
				insert(k, v);
				Node * tmp = head;
				delete tmp;		//delete the current node
				head = head->next;
			}
		}
		delete oldTable;		//frees the old table that was allocated space
	}

public:
	HashMap() {
		capacity = 7;	//prime is good
		sze = 0;
		table = new Node*[capacity];	//all elements (or pointers) set to NULL
		clear(table, capacity, NULL);
	}

	void insert(string k, int v) {
		//find idx corresponding to k
		int idx = hashFunction(k);

		Pair P(k, v);
		Node* newNode = new Node(P);

		//if the list is empty, insert this element as head
		//else insert at head
		if (table[idx] == NULL) {
			//no element at that particular idx
			table[idx] = newNode;
			++sze;

		}
		else {
			//list already exists
			newNode->next = table[idx];
			table[idx] = newNode;
			++sze;
		}

		if (load_factor() >= 0.7){
			rehash();
		}
	}

	int find(string key){
		int idx = hashFunction(key);

		Node* head = table[idx];
		
		//find key/element in a linked list
		while(head != NULL){
			Pair cur = head->P;
			if (cur.key == key){		//operator overloaded in string class of STL
				return cur.value;
			}
			head = head->next;
		}

		return -1;
	}

	bool empty(){
		return sze == 0;
	}

	bool size(){
		return sze;
	}

	void remove(string key){
		int idx = hashFunction(key);

		Node * prev = NULL;
		Node * cur = table[idx];

		while(cur){
			if (cur->P.key == key){
				//node found
				if (prev == NULL){
					//head to be updated
					table[idx] = cur->next;
					cur->next = NULL;
					delete cur;
					--sze;		//size to be updated
				}

				else {
					//node deleted lies in middle/end
					prev->next = cur->next;
					cur->next = NULL;
					delete cur;
					--sze;				//size to be updated
				}
			}
			prev = cur;
			cur = cur->next;
		}
	}

	~HashMap(){
		delete [] table;		//free the memory allocated by ctor
		//scope rule doesn't follow
	}

};
#endif