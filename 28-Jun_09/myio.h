//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void inputArr(int arr[], int n){
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}