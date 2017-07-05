//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

static int x;

int main(){
	// int n;
	// cin >> n;

	int * ptr = new int;
	*ptr = 5;
	cout << *ptr;	
	delete ptr;	//deleting integer

	int n;
	cin >> n;
	int * ptr_arr =	new int[n];

	for(int i = 0;  i < n; ++i){
		cout << ptr_arr[i] << " ";	//*(ptr_arr + 0)
	}
	delete [] ptr_arr;	//deleting arr

	// cout << x;
}