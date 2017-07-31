//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
	bool isterminal;
	Node* characters[26];

	Node(){
		isterminal = false;
		fill(characters, characters + 26, (Node*)NULL);
	}
};

class Trie{
	Node * root;
public:
	Trie(){
		root = new Node();
	}

	int charToInt(char c){
		return c - 'a';
	}

	void addWord(char word[]){
		Node * cur = root;

		for(int i = 0; word[i] != '\0'; ++i){
			int idx = charToInt(word[i]);

			if (cur->characters[idx] == NULL){
				//furthur levels do NOT exist
				cur->characters[idx] = new Node();
			}
			cur = cur->characters[idx];
		}

		cur->isterminal = true;
	}

	bool searchWord(char word[]){
		Node * cur = root;

		for(int i = 0; word[i] != '\0'; ++i){
			int idx = charToInt(word[i]);
			if (!cur->characters[idx]) return false;
			cur = cur->characters[idx];
		}
		return cur->isterminal;
	}
};

int main(){

	Trie T;
	// cout << "Hi";
	T.addWord("tree");
	T.addWord("trie");
	T.addWord("algo");
	T.addWord("assoc");
	T.addWord("all");

	cout << T.searchWord("asso");

	
}