//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include "stack.h"
#include <iostream>
using namespace std;

bool isBalanced(char arr[]){
	int i = 0;
	Stack<char> S;
	while(arr[i] != '\0'){
		if (arr[i] == '('){
			S.push(arr[i]);
		}
		else if (arr[i] == ')'){
			if (S.empty()) return false;
			S.pop();
		}
		++i;
	}
	return S.empty();
}


int main(){
	char arr[20];
	cin >> arr;

	cout << isBalanced(arr);
}