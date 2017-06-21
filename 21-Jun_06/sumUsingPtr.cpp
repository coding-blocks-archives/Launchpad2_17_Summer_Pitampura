//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void input(int a[], int n){
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
}


int printArr(int arr[], int n){
	int i = 0;
	while((arr + i) != (arr + n)){
		cout << arr[i] << " " ;
		++i;
	}

}

int printArr2(int * arrBegin, int * arrEnd){
	int i = 0;
	// while((arr + i) != (arr + n)){
	while(arrBegin != arrEnd){
		// cout << arr[i] << " " ;
		cout << *arrBegin << " ";
		++arrBegin;	//arrBegin = arrBegin + 1
	}

}


int main(){
	int arr[10];
	int n;
	cout << "Enter size ";
	cin >> n;

	input(arr, n);
	// printArr(arr, n);
	// printArr(arr + 2, n);
	printArr2(arr + 2, arr + 6);
}