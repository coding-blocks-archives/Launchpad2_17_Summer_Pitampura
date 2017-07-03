//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;

int foo(){
	static int x = 1;
	return ++x;
}


int main(){
	cout << foo() << endl;
	cout << foo() << endl;
	cout << foo() << endl;
	cout << foo() << endl;
}