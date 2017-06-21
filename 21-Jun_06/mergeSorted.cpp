//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;


void input(int a[], int n){
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
}

void print(int a[], int n){
	for(int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
}

void myMerge(int a1[], int m, int a2[], int n){
	//copy m elements into a temp arr
	int temp[100];
	for(int i = 0; i < m; ++i){
		temp[i] = a1[i]; 
	}

	int i = 0;	//corresponding to m
	int j = 0;	//corresponding to n
	int k = 0;	//corresponding to orig arr

	while(i < m && j < n){
		//do some stuff
		//copy elements accordingly
		if (temp[i] < a2[j]){
			a1[k] = temp[i];
			++i;
			++k;
		}
		else {
			a1[k] = a2[j];
			++j;
			++k;
		}
	}

	while(i < m){
		//copy elements from temp to a1
		a1[k] = temp[i];
		++i;
		++k;
	}

	while(j < n){
		//copy elements from a2 to a1
		a1[k] = a2[j];
		++j;
		++k;
	}

}


int main(){
	int arr1[10];
	int arr2[5];

	int m, n;
	cout << "Enter m and n : ";
	cin >> m >> n;

	//input m elements inside arr1
	cout << "Enter elements for 1st arr\n";
	input(arr1, m);

	//input n elements inside arr2
	cout << "Enter elements for 2nd arr\n";
	input(arr2, n);

	myMerge(arr1, m, arr2, n);

	//print arr
	print(arr1, m + n);

}