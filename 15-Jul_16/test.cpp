//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;
int main(){
	// int * ptr = new int[0];
	// cout << ptr << endl;
	// ptr[0] = 1;
	// cout << ptr[0];	

	int arr[5];
	for(int i = 0; i < 5; ++i){
		cin >> arr[i];
	}

	for(int i = 0; i < 5; ++i){
		cout << arr[i];
	}
}