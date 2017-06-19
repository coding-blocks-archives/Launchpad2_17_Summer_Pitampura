//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int arr[100];	
	
	int n;
	cin >> n;

	//input
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	//selection sort
	//for every pos i, I have to find corresponding smallest element
	for(int i = 0; i < n; ++i){
		//finding the smallest ele
		int smallest = arr[i];	//HW : Smallest is not required
		int pos = i;			//because I have position
		for(int j = i; j < n; ++j){
			if (arr[j] < smallest){
				smallest = arr[j];
				pos = j;
			}
		}
		//smallest VARIABLE contains the smallest ele within arr [i to n-1]	
		//swap
		int tmp = arr[i];
		arr[i] = smallest;
		arr[pos] = tmp;
	}


	//output the array
	for(int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
}