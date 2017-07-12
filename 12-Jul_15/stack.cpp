//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include "stack.h"
using namespace std;

int main(){
	Stack<int> S;
	S.push(2);
	S.push(3);
	S.pop();
	cout << S.top() << endl;;

	S.pop();
	cout << S.top() << endl;
	S.push(4);
	cout << S.size() << endl;		
}