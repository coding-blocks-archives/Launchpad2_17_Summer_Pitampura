//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void funct(int a[]){
	cout << "Inside funct\n";
	cout << a << endl;
	cout << "size of a " << sizeof(a) << endl;
}


int main(){
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	cout << "Value OF arr " << arr << endl;
	cout << "Address of arr[0] " << &(arr[0]) << endl;	
	cout << "Sizeof arr " << sizeof(arr) << endl;

	int * ptr = arr;
	cout << "Value of ptr_ARR " << ptr << endl;
	cout << "Sizeof of ptr_ARR " << sizeof(ptr) << endl;
	funct(arr);


	//Ptr arithmetic'
	cout << arr[0] << endl;
	cout << *(ptr + 4) << endl;
	cout << ptr[4] << endl;	//same as above
	cout << *(&arr[4]) << endl; 

	int * ptr1 = &arr[0];
	int * ptr2 = &arr[5];
	cout << "(ptr2 - ptr1)" << (ptr2 - ptr1) << endl;
	//No of elements and not the difference

	char x;
	char *ptr3 = &x;
	// cout << "(ptr3 - ptr1)" << (ptr3 - ptr1) << endl;
}