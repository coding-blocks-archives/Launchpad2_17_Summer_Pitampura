//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int a = 10;
	cout << "Address of a is " << &a << endl;

	int * ptr_a;	//declaration
	ptr_a = &a;
	cout << "Value OF ptr_a " << ptr_a << endl;	

	//accessing value via ptr
	cout << (*ptr_a);

	// int* ptr1, *ptr2;	//2 pointers
	// int* ptr1, ptr2;	//1 pointer
	// (int*) ptr1, ptr2;	//Invalid syntax

	double b = 22.22;
	int i = 20;
	int * ptr_i = (int*)&b;	//forcing compiler:::Explicit Typecasting
	//SHOULD NEVER be used

	int mul = * ptr * 10;	//dereference has higher precedence

}
