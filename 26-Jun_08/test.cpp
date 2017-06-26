//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	// 12;
	
	// char *ptr = "abc";
	// char arr[] = "abc";
	// // ptr[0] = 'k';
	// arr[0] = 'k';
	// // cout << ptr;
	// // cout << arr;
	// cout << ptr[0];

	// char s1[] = "abc";
	// char s2[] = s1;	

	char arr[] = "abc";	//array whose value is abc
	"abc";	//constant
	char * ptr = arr;	//ptr now POINTS to arr
	ptr[0] = 'k';
	cout << "ptr " << ptr << endl;
	cout << "arr " << arr << endl;


}