//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include "myio.h"
using namespace std;

int sumArr(int arr[], int n){
	//this function computes the sum of N elements of an Integer array
	if (n <= 0){
		return 0;
	}


	/*copy first n - 1 elements into smallArr since recursion can't add N elements but
	can add n - 1 elemets*/
	int smallArr[10];
	for(int i = 0; i < n - 1; ++i){
		smallArr[i] = arr[i];
	}
	//the above copying can be avoided IFF we can logically create a smaller array

	int smallSum = sumArr(smallArr, n - 1);
	int curSum = smallSum + arr[n - 1];
	return curSum;
}

int sumArr2(int arr[], int n){
	if (n <= 0) return 0;

	int smallerSum = sumArr2(arr, n - 1);	//sum of first n-1 elements got through recursion
	int curSum = smallerSum + arr[n - 1];	//adding the Nth element @ index n - 1
	return curSum;
}



int main(){
	int arr[10];
	int n;
	cin >> n;
	inputArr(arr, n);

	int sum = sumArr2(arr, n);
	cout << sum << " ";
	
}