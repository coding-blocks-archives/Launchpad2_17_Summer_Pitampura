//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include "myio.h"
using namespace std;

void myMerge(int arr[], int be, int mid, int en){
	int A[100];
	int B[100];

	//copying be to mid elements into A
	for(int i = be; i <= mid; ++i){
		A[i - be] = arr[i];
	}

	//copying [mid + 1, en] elements into B
	for(int i = mid + 1; i <= en; ++i){
		B[i - (mid + 1)] = arr[i];
	}

	//merging
	int k = be;
	int i = 0;
	int j = 0;
	int sizeA = mid - be + 1;
	int sizeB = en - mid;
	while(i < sizeA && j < sizeB){
		if (A[i] < B[j]){
			arr[k] = A[i];
			++k;
			++i;
		}
		else{
			arr[k++] = B[j++];
		}
	}

	while(i < sizeA) arr[k++] = A[i++];
	while(j < sizeB) arr[k++] = B[j++];

}



void mergeSort(int arr[], int be, int en){
	if (be >= en){
		return;
	}

	int mid = (be + en) / 2;
	mergeSort(arr, be , mid);
	mergeSort(arr, mid + 1, en);
	myMerge(arr, be, mid, en);
}



int main(){
	int arr[100];
	int n;
	cin >> n;
	inputArr(arr, n);

	mergeSort(arr, 0, n  - 1);

	printArr(arr, n);
}