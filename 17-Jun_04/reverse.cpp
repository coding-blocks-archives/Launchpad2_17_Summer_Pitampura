//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main() {
	int arr[10];

	//input val
	for (int i  = 0; i < 10; ++i) {
		cin >> arr[i];	//[0, 9]
	}

	//reverse printing
	for (int i = 9; i >= 0; --i){
		cout << arr[i];
		cout << " ";
		// cout << arr[i] << " "; 
	}
}