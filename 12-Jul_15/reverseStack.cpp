//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include "stack.h"
using namespace std;

void copyStack(Stack<int>& to, Stack<int>& from) {
	while (from.empty() == false) {
		to.push(from.top());
		from.pop();
	}
}


void reverseStack(Stack<int>& S) {
	Stack<int> X, Y;

	copyStack(X, S);
	copyStack(Y, X);
	copyStack(S, Y);
}


int main() {
	Stack<int> S;
	int x;

	while (true) {
		cin >> x;
		if (x == -1) break;
		S.push(x);
	}

	reverseStack(S);

	//printing
	while (S.empty() == false) {
		cout << S.top() << endl;
		S.pop();
	}

}