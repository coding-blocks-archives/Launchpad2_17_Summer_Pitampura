//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int x = 5;	//global variable throughout program
// int x; this is wrong
int main(){
	int var;	//definition
	int var2 = 10;	//initialisation
	var = 3;	//assignment
	cout << x;	//global variables
	cout << var2 <<endl;


	int x = 15;
	// cout << "x is " << x << endl;
	cout << "x is " << ::x  << endl;	//global x

	//scope 1
	{
		cout << var2 << endl;
		int var2 = 11;	//local variable--local to block
		cout << var2 << endl;
	}

	cout << var2 << endl;
}
