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

	//insertion sort
	for(int i = 1; i < n; ++i){
		int j = i;
		//shifting required no of elements
		while(j - 1 >= 0 && arr[j] < arr[j - 1]){
			int tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			--j;
		}
	}
	
	//output the array
	for(int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
}