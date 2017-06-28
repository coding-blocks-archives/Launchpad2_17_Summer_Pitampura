//Deepak Aggarwal, Coding Blocks
#include <iostream>
#include "myio.h"
using namespace std;

void selection(int arr[], int n){
	if (n <= 0){
		return;
	}


	//setting the smallest no in arr with n elements at 0th position
	int pos = 0;
	for(int i = 0; i < n; ++i){
		if(arr[i] < arr[pos]){
			pos = i;
		}
	}
	//pos contains the idx of the smallest element
	swap(arr[0], arr[pos]);

	int tmp[10];
	for(int i = 1; i < n; ++i){
		tmp[i - 1] = arr[i];
	}

	selection(tmp, n - 1);

	//copying tmp back to arr
	for(int i = 0; i < n - 1; ++i){
		arr[i + 1] = tmp[i];
	}
}

void selection2(int arr[], int be, int en){
	if (be >= en){
		return;
	}

	//setting the element for be position
	int pos = be;
	for(int i = be; i <= en; ++i){
		if (arr[i] < arr[pos]){
			pos = i;
		}
	}
	swap(arr[be], arr[pos]);

	selection2(arr, be + 1, en);
}


int main(){
	int arr[10];
	int n;
	cin >> n;
	inputArr(arr, n);

	selection2(arr, 0, n-1);

	printArr(arr, n);
}