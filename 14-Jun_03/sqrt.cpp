//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	int root = 0;		//root contains  the root of my number

	while(root * root <= num){
		// root = root + 1;
		++root;		//preincrement operator--adds 1 to root
	}
	root = root - 1;	//value of root is one extra as per logic

	cout << root;	
}
